#include "gui.h"
#include <QDebug>
#include <set>
#include <map>
#include <QtCharts>
#include <fstream>

GUI::GUI()
{
    init_gui();
    connect_signals_slots();
    populate_list();
}

void GUI::init_gui(){
    pie_button = new QPushButton("pie");
    task_list_widget = new QListWidget;
    mylist_list_widget = new QListWidget;
    saved_list_widget = new QStackedWidget;
    title_line_edit = new QLineEdit;
    type_line_edit = new QLineEdit;
    last_performed_date_line_edit = new QLineEdit;
    times_performed_line_edit = new QLineEdit;
    vision_line_edit = new QLineEdit;
    add_button = new QPushButton("add");
    open_button = new QPushButton("open mylist");
    remove_button = new QPushButton("remove");
    update_button = new QPushButton("update");
    undo_button = new QPushButton("undo");
    redo_button = new QPushButton("redo");
    filter_list_widget = new QListWidget;
    save_button = new QPushButton("save");
    next_button = new QPushButton("next");
    search_button = new QPushButton("filter");
    search_line_edit1 = new QLineEdit;
    search_line_edit2 = new QLineEdit;
    exception_message = new QMessageBox;
    current_task = new QLabel;

    QLabel *task_attribute = new QLabel("task attributes");

    // main layout is a vertical box combined by two layouts, mode A and mode B both grid
    QVBoxLayout *main_layout = new QVBoxLayout{this};
    QGridLayout *mode_A_layout = new QGridLayout;
    QGridLayout *mode_B_layout = new QGridLayout;
    QHBoxLayout *mode_A_buttons = new QHBoxLayout;
    QGridLayout *mode_B_buttons = new QGridLayout;

    QLabel *title_label = new QLabel("title");
    QLabel *type_label = new QLabel("type");
    QLabel *date_label = new QLabel("last performed date");
    QLabel *times_performed_label = new QLabel("times performed");
    QLabel *vision_label = new QLabel("vision");

    
    mode_combobox = new QComboBox;
    mode_combobox->addItem("no mode");
    mode_combobox->addItem("mode A");
    mode_combobox->addItem("mode B");

    mode_A_layout->addWidget(mode_combobox, 0, 2);
    mode_A_layout->addWidget(task_attribute, 0, 0,Qt::AlignCenter);
    mode_A_layout->addWidget(task_list_widget,1, 2, 5, 1);
    mode_A_layout->addWidget(title_label, 1, 0);
    mode_A_layout->addWidget(title_line_edit, 1, 1);
    mode_A_layout->addWidget(type_label, 2, 0);
    mode_A_layout->addWidget(type_line_edit, 2, 1);
    mode_A_layout->addWidget(date_label, 3, 0);
    mode_A_layout->addWidget(last_performed_date_line_edit, 3, 1);
    mode_A_layout->addWidget(times_performed_label, 4, 0);
    mode_A_layout->addWidget(times_performed_line_edit, 4, 1);
    mode_A_layout->addWidget(vision_label, 5, 0);
    mode_A_layout->addWidget(vision_line_edit, 5, 1);

    mode_A_buttons->addWidget(add_button);
    mode_A_buttons->addWidget(remove_button);
    mode_A_buttons->addWidget(update_button);
    mode_A_buttons->addWidget(undo_button);
    mode_A_buttons->addWidget(redo_button);

    mode_B_layout->addWidget(saved_list_widget, 1, 2);
    mode_B_buttons->addWidget(save_button,0,0);
    mode_B_buttons->addWidget(next_button,1,0);
    mode_B_layout->addLayout(mode_B_buttons, 1, 1);
    mode_B_buttons->addWidget(search_button, 2, 0);
    mode_B_buttons->addWidget(pie_button, 2, 1);
    mode_B_buttons->addWidget(search_line_edit1, 3, 0);
    mode_B_buttons->addWidget(search_line_edit2, 3, 1);
    mode_B_layout->addWidget(open_button,1,5);

    main_layout->addLayout(mode_A_layout);
    main_layout->addLayout(mode_A_buttons);
    main_layout->addLayout(mode_B_layout);
}

void GUI::populate_list()
{
    task_list_widget->clear();
    std::vector<Task> all_tasks;
    try{
        all_tasks = service.get_list_of_tasks();
    }
    catch(...){
        exception_message->setText("bad filepath");
        exception_message->exec();
        return;
    }
    for(auto task:all_tasks)
        //task_list_widget->addItem(QString::fromStdString(task.to_string()));
        task_list_widget->addItem(QString::fromStdString(task.get_title() + ", " + task.get_type() + ", " + std::to_string(task.get_last_performed_month()) + '-' + std::to_string(task.get_last_performed_day()) + '-' + std::to_string(task.get_last_performed_year()) + ", " + std::to_string(task.get_times_performed()) + ", " + task.get_vision()));
}

int GUI::get_index_from_widget_list()
{
    QModelIndexList selected_indexes = task_list_widget->selectionModel()->selectedIndexes();
    if(selected_indexes.size() == 0){
        title_line_edit->clear();
        type_line_edit->clear();
        last_performed_date_line_edit->clear();
        times_performed_line_edit->clear();
        vision_line_edit->clear();
        return -1;
    }
    int index = selected_indexes.at(0).row();
    return index;
}    

void GUI::get_data_from_widget_list()
{
    int selected_index = get_index_from_widget_list();

    if(selected_index < 0)
        return;

    Task selected_task = service.get_list_of_tasks()[selected_index];
    std::string selected_task_as_string = selected_task.to_string();
    selected_task_as_string = selected_task.remove_not_needed_strings(selected_task_as_string);
    std::vector<std::string>vector_string_task = tokenize(selected_task_as_string, ',');
    title_line_edit->setText(QString::fromStdString(vector_string_task[0]));
    type_line_edit->setText(QString::fromStdString(vector_string_task[1]));
    last_performed_date_line_edit->setText(QString::fromStdString(vector_string_task[2]));
    times_performed_line_edit->setText(QString::fromStdString(vector_string_task[3]));
    vision_line_edit->setText(QString::fromStdString(vector_string_task[4]));
}

void GUI::connect_signals_slots(){
    QObject::connect(task_list_widget, &QListWidget::itemSelectionChanged, this, &GUI::get_data_from_widget_list);
    QObject::connect(mode_combobox, QOverload<int>::of(&QComboBox::activated), this, &GUI::set_mode);
    QObject::connect(add_button, &QPushButton::clicked, this, &GUI::add_new_task);
    QObject::connect(update_button, &QPushButton::clicked, this, &GUI::update_task);
    QObject::connect(remove_button, &QPushButton::clicked, this, &GUI::remove_task);
    QObject::connect(undo_button, &QPushButton::clicked, this, &GUI::undo);
    QObject::connect(redo_button, &QPushButton::clicked, this, &GUI::redo);
    QObject::connect(save_button, &QPushButton::clicked, this, &GUI::save);
    QObject::connect(open_button, &QPushButton::clicked, this, &GUI::open);
    QObject::connect(next_button, &QPushButton::clicked, this, &GUI::next);
    QObject::connect(search_button, &QPushButton::clicked, this, &GUI::filter);
    QObject::connect(pie_button, &QPushButton::clicked, this, &GUI::get_pie);
}

void GUI::get_pie(){
    QWidget *new_pie = new QWidget;
    new_pie->show();
    std::vector<Task> all_types = service.get_list_of_tasks();
    std::map<std::string, int> all;
    for(auto task:all_types)
        all[task.get_type()]++;
    QPieSeries *series = new QPieSeries();
    for(auto t:all)
        series->append(QString::fromStdString(t.first), t.second);
    /*
     * procente
    series->setLabelsVisible();
    series->setLabelsPosition(QPieSlice::LabelInsideHorizontal);
    for(auto slice : series->slices())
        slice->setLabel(QString("%1%").arg(100*slice->percentage(), 0, 'f', 1));
        */
    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->addSeries(series);
    QVBoxLayout *lay = new QVBoxLayout;
    QChartView *C = new QChartView(chart);
    lay->addWidget(C);
    new_pie->setLayout(lay);
}

void GUI::filter(){
    if(service.get_mode() != -1){
        exception_message->setText("not mode B");
        exception_message->exec();
        return;
    }
    std::string type;
    int times_performed;
    type = search_line_edit1->text().toStdString();
    times_performed = search_line_edit2->text().toInt();
    QWidget *mylist_window = new QWidget;
    QVBoxLayout *mode_B_mylist = new QVBoxLayout;

    mode_B_mylist->addWidget(filter_list_widget);
    filter_list_widget->clear();
    mylist_window->setLayout(mode_B_mylist);
    mylist_window->setWindowTitle("mylist");
    std::vector<Task> mylist;
    mylist = service.get_list_by_type_and_times_performed(type, times_performed);
    for(auto task:mylist)
        filter_list_widget->addItem(QString::fromStdString(task.get_title() + ", " + task.get_type() + ", " + std::to_string(task.get_last_performed_month()) + '-' + std::to_string(task.get_last_performed_day()) + '-' + std::to_string(task.get_last_performed_year()) + ", " + std::to_string(task.get_times_performed()) + ", " + task.get_vision()));
    mylist_window->show();
    return;
}

void GUI::next(){
    try{
        Task task = service.next();
    current_task->setText(QString::fromStdString(task.get_title() + ", " + task.get_type() + ", " + std::to_string(task.get_last_performed_month()) + '-' + std::to_string(task.get_last_performed_day()) + '-' + std::to_string(task.get_last_performed_year()) + ", " + std::to_string(task.get_times_performed()) + ", " + task.get_vision()));
    saved_list_widget->addWidget(current_task);
    }
    catch(std::string st){
        exception_message->setText(QString::fromStdString(st));
        exception_message->exec();
        return;
    }
    catch(RepositoryException &ex){
        exception_message->setText(ex.what());
        exception_message->exec();
        return;
    }
}

void GUI::open(){
    if(service.get_mode() != -1){
        exception_message->setText("not mode B");
        exception_message->exec();
        return;
    }
    std::string system_command;
    std::string extension;
    std::ifstream config_open("config.txt");
    std::getline(config_open, system_command);
    std::getline(config_open, system_command);

    system_command = system_command.substr(system_command.find("=")+1);
    if(system_command.empty()){
        QWidget *mylist_window = new QWidget;
        QVBoxLayout *mode_B_mylist = new QVBoxLayout;

        mode_B_mylist->addWidget(mylist_list_widget);
        mylist_list_widget->clear();
        mylist_window->setLayout(mode_B_mylist);
        mylist_window->setWindowTitle("mylist");
        auto mylist = service.get_list_of_saved_tasks();
        for(auto task:mylist)
            mylist_list_widget->addItem(QString::fromStdString(task.get_title() + ", " + task.get_type() + ", " + std::to_string(task.get_last_performed_month()) + '-' + std::to_string(task.get_last_performed_day()) + '-' + std::to_string(task.get_last_performed_year()) + ", " + std::to_string(task.get_times_performed()) + ", " + task.get_vision()));
        mylist_window->show();
        return;
    }
    int extension_position = system_command.find_last_of('.');
    extension = system_command.substr(extension_position);
    title_line_edit->setText(QString::fromStdString(extension));
    if(extension == ".csv")
        system_command = "xed \"" + system_command + "\"";
    else
        system_command = "google-chrome \"" + system_command + "\"";
    system(system_command.c_str());
    return;

}
void GUI::save(){
    QModelIndexList selected_indexes = task_list_widget->selectionModel()->selectedIndexes();
    if(selected_indexes.size() > 0){
        int index = get_index_from_widget_list();
        Task task = service.get_list_of_tasks()[index];
        try{
            service.add_to_servant_list(task);
        }
        catch(std::string xception){
            exception_message->setText(QString::fromStdString(xception));
            exception_message->exec();
            return;
        }
        catch(RepositoryException &ex){
            exception_message->setText(ex.what());
            exception_message->exec();
            return;
        }
    }
}

void GUI::redo()
{
    try{
        service.redo();
    }
    catch(...){
        exception_message->setText("no more redos");
        exception_message->exec();
        return;
    }
    populate_list();
}

void GUI::undo()
{
    try{
        service.undo();
    }
    catch(...){
        exception_message->setText("no more undos");
        exception_message->exec();
        return;
    }
    populate_list();
}

void GUI::update_task(){
    if(title_line_edit->text().size() > 0 && type_line_edit->text().size() > 0 && last_performed_date_line_edit->text().size() > 0 && times_performed_line_edit->text().size() > 0 && vision_line_edit->text().size() > 0){
        std::string title = title_line_edit->text().toStdString();
        std::string type = type_line_edit->text().toStdString();
        tm last_performed_date;
        std::string lpd_as_string = last_performed_date_line_edit->text().toStdString();
        set_date_as_tm(lpd_as_string, last_performed_date);
        int times_performed = times_performed_line_edit->text().toInt();
        std::string vision = vision_line_edit->text().toStdString();
        try{
            service.update(title, type, last_performed_date, times_performed, vision);
        }
        catch(RepositoryException &ex){
            exception_message->setText(ex.what());
            exception_message->exec();
            return;
        }
        catch(std::string xception){
            exception_message->setText(QString::fromStdString(xception));
            exception_message->exec();
            return;
        }
        populate_list();
    }
}

void GUI::remove_task()
{
    std::string current_task;
    if(task_list_widget->selectedItems().size() != 0)
        current_task = task_list_widget->currentItem()->text().toStdString();
    else{
        current_task = title_line_edit->text().toStdString();
        if(current_task.size() == 0)
            return;
        current_task += ",";
    }
    std::string title_of_the_task = "";
    int i = 0;

    while(current_task[i] != ','){
        title_of_the_task += current_task[i];
        i++;
    }
    try{
        service.remove(title_of_the_task);
    }
    catch(std::string xception){
            exception_message->setText(QString::fromStdString(xception));
            exception_message->exec();
            return;
    }
    catch(RepositoryException &ex){
            exception_message->setText(ex.what());
            exception_message->exec();
            return;
    }
    populate_list();
}

void GUI::set_mode()
{
    if(mode_combobox->currentText().toStdString() == "mode A")
        service.set_mode('A');
    else
        if(mode_combobox->currentText().toStdString() == "mode B")
            service.set_mode('B');
        else
            service.set_mode('X');
}

void GUI::add_new_task()
{
    if(title_line_edit->text().isEmpty() || type_line_edit->text().isEmpty() || last_performed_date_line_edit->text().isEmpty() || times_performed_line_edit->text().isEmpty() || vision_line_edit->text().isEmpty())
        return;
    std::string title = title_line_edit->text().toStdString();
    std::string type = type_line_edit->text().toStdString();
    tm last_performed_date;
    std::string lpd_as_string = last_performed_date_line_edit->text().toStdString();
    set_date_as_tm(lpd_as_string, last_performed_date);
    int times_performed = times_performed_line_edit->text().toInt();
    std::string vision = vision_line_edit->text().toStdString();
    try{
        service.add(title, type, last_performed_date, times_performed, vision);
    }
    catch(std::string xception){
        exception_message->setText(QString::fromStdString(xception));
        exception_message->exec();
        return;
    }
    catch(RepositoryException &ex){
        exception_message->setText(ex.what());
        exception_message->exec();
        return;
    }
    catch(ValidateTask &ex){
        exception_message->setText(ex.what());
        exception_message->exec();
        return;
    }
    populate_list();
}

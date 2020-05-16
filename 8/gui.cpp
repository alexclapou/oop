#include "gui.h"

GUI::GUI()
{
    init_gui();
}

void GUI::init_gui(){
    task_list = new QListWidget;
    saved_list = new QListWidget;
    filepath_edit = new QLineEdit;
    mylist_edit = new QLineEdit;
    title_line_edit = new QLineEdit;
    type_line_edit = new QLineEdit;
    last_performed_date_line_edit = new QLineEdit;
    times_performed_line_edit = new QLineEdit;
    vision_line_edit = new QLineEdit;
    filepath_button = new QPushButton("ok");
    mylist_button = new QPushButton("ok");
    add_button = new QPushButton("add");
    remove_button = new QPushButton("remove");
    update_button = new QPushButton("update");
    undo_button = new QPushButton("undo");
    redo_button = new QPushButton("redo");
    save_button = new QPushButton("save");
    next_button = new QPushButton("next");

    QLabel *filepath_label = new QLabel("filelocation");
    QLabel *mylist_label = new QLabel("mylistlocation");
    QLabel *task_attribute = new QLabel("task attributes");

    // main layout is a vertical box combined by two layouts, mode A and mode B both grid
    QFormLayout *filepath_layout = new QFormLayout;
    QFormLayout *mylist_layout = new QFormLayout;
    QVBoxLayout *main_layout = new QVBoxLayout{this};
    QGridLayout *mode_A_layout = new QGridLayout;
    QGridLayout *mode_B_layout = new QGridLayout;
    QHBoxLayout *mode_A_buttons = new QHBoxLayout;
    QVBoxLayout *mode_B_buttons = new QVBoxLayout;

    filepath_layout->addRow(filepath_label);
    filepath_layout->addRow(filepath_button, filepath_edit);

    mylist_layout->addRow(mylist_label);
    mylist_layout->addRow(mylist_button, mylist_edit);

    QLabel *title_label = new QLabel("title");
    QLabel *type_label = new QLabel("type");
    QLabel *date_label = new QLabel("last performed date");
    QLabel *times_performed_label = new QLabel("times performed");
    QLabel *vision_label = new QLabel("vision");

    mode_A_layout->addWidget(task_attribute, 0, 0,Qt::AlignCenter);
    mode_A_layout->addWidget(task_list,1, 2, 5, 1);
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

    mode_B_layout->addWidget(saved_list, 1, 2);
    mode_B_buttons->addWidget(save_button);
    mode_B_buttons->addWidget(next_button);
    mode_B_layout->addLayout(mode_B_buttons, 1, 1);

    main_layout->addLayout(filepath_layout);
    main_layout->addLayout(mode_A_layout);
    main_layout->addLayout(mode_A_buttons);
    main_layout->addLayout(mylist_layout);
    main_layout->addLayout(mode_B_layout);
    main_layout->setAlignment(Qt::AlignTop);
}

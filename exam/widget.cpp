#include "widget.h"
#include <fstream>
#include "ui_widget.h"

Widget::Widget(Astronomer a, QAbstractItemModel *_model, Repository &repo, QWidget *parent)
    : astronomer{a}, model{_model}, r{repo}, QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(astronomer.get_name(), this);
    ui->main_table->setModel(model);
    connect_all();
}

void Widget::connect_all(){
    QObject::connect(ui->filter_checkbox, &QCheckBox::stateChanged, this, &Widget::filter_own);
    QObject::connect(ui->add_button, &QCheckBox::clicked, this, &Widget::add_new_star);
    QObject::connect(ui->search_lineedit, &QLineEdit::textChanged, this, &Widget::filter_new_list);
    
}

void Widget::filter_new_list(){
    QSortFilterProxyModel *filterModel = new QSortFilterProxyModel;
    filterModel->setSourceModel(model);
    std::string match = ui->search_lineedit->text().toStdString();
    if(match == ""){
        ui->second_table->setModel(nullptr);
        return;
    }
    filterModel->setFilterKeyColumn(0);
    filterModel->setFilterFixedString(QString::fromStdString(match));
    ui->second_table->setModel(filterModel);
}
//load to file the data sorted
bool cond(Star a, Star b){
    if(a.get_constellation() > b.get_constellation())
        return true;
    return false;
}
void Widget::closeEvent(QCloseEvent *event){
    std::ofstream write_data(r.get_starfile());
    auto list = r.get_stars();
    sort(list.begin(), list.end(), cond);
    for(auto star:list)
        write_data<<star;
    write_data.close();
}

void Widget::add_new_star(){
    std::string name = ui->name_lineedit->text().toStdString();
    std::string constellation = astronomer.get_constellation();
    int ra = ui->d1_lineedit->text().toInt();
    int dec = ui->d2_lineedit->text().toInt();
    int dia = ui->d3_lineedit->text().toInt();
    auto all_stars = r.get_stars();
    for(auto A:all_stars)
        if(A.get_name() == name){
            QMessageBox *new_box = new QMessageBox;
            new_box->setText("Bad input");
            new_box->show();
            return;
        }
    if(name == "" || ra <= 0 || dec <= 0 || dia <= 0){
        QMessageBox *new_box = new QMessageBox;
        new_box->setText("Bad input");
        new_box->show();
        return;
    }
    else{
        Star new_star(name, constellation, ra, dec, dia);
        r.add_star(new_star);
        model->layoutChanged();
    }
}

void Widget::filter_own(){
    if(!nothing)
        ui->main_table->setModel(model);
    else{
        ui->main_table->setModel(nullptr);
        QSortFilterProxyModel *filterModel = new QSortFilterProxyModel;
        filterModel->setSourceModel(model);
        filterModel->setFilterKeyColumn(1);
        filterModel->setFilterFixedString(QString::fromStdString(astronomer.get_constellation()));
        ui->main_table->setModel(filterModel);
    }
    nothing = !nothing;
}

Widget::~Widget()
{
    delete ui;
}


#pragma once
#include <qwidget.h>
#include <QGridLayout>
#include <qlistwidget.h>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPushButton>
#include <QLabel>
#include <QFormLayout>
#include <qlineedit.h>
#include <qpushbutton.h>
#include "service.h"

class GUI:public QWidget{
    private:
        Service service;
        void init_gui();
        QListWidget *task_list;
        QListWidget *saved_list;
        QLineEdit *filepath_edit;
        QLineEdit *title_line_edit;
        QLineEdit *mylist_edit;
        QLineEdit *type_line_edit;
        QLineEdit *last_performed_date_line_edit;
        QLineEdit *times_performed_line_edit;
        QLineEdit *vision_line_edit;
        QPushButton *filepath_button;
        QPushButton *mylist_button;
        QPushButton *add_button;
        QPushButton *remove_button;
        QPushButton *update_button;
        QPushButton *undo_button;
        QPushButton *redo_button;
        QPushButton *save_button;
        QPushButton *next_button;
    public:
        GUI();
};

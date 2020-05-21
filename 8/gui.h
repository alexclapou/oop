#pragma once
#include <qwidget.h>
#include <QGridLayout>
#include <QComboBox>
#include <qlistwidget.h>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPushButton>
#include <QLabel>
#include <QFormLayout>
#include <qlineedit.h>
#include <QMessageBox>
#include <QStackedWidget>
#include <qpushbutton.h>
#include "service.h"
#include "task.h"

class GUI:public QWidget{
    private:
        Service service;
        QListWidget *task_list_widget;
        QStackedWidget *saved_list_widget;
        QLineEdit *filepath_edit;
        QLineEdit *title_line_edit;
        QLineEdit *mylist_edit;
        QLineEdit *type_line_edit;
        QLineEdit *last_performed_date_line_edit;
        QLineEdit *times_performed_line_edit;
        QLineEdit *vision_line_edit;
        QComboBox *mode_combobox;
        QPushButton *filepath_button;
        QPushButton *mylist_button;
        QPushButton *open_button;
        QPushButton *add_button;
        QPushButton *remove_button;
        QPushButton *update_button;
        QPushButton *undo_button;
        QPushButton *redo_button;
        QPushButton *save_button;
        QPushButton *next_button;
        QLabel *current_task;
        QMessageBox *exception_message;
        void populate_list();
        void init_gui();
        void connect_signals_slots();
        int get_index_from_widget_list();
        void get_data_from_widget_list();
        void set_filepath_widget();
        void set_mylist_widget();
        void add_new_task();
        void remove_task();
        void update_task();
        void undo();
        void next();
        void redo();
        void save();
        void set_mode();
        void open();
    public:
        GUI();
};

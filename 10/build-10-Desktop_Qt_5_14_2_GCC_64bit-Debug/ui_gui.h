/********************************************************************************
** Form generated from reading UI file 'gui.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GUI_H
#define UI_GUI_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_GUI
{
public:
    QVBoxLayout *verticalLayout;
    QFormLayout *formLayout;
    QLabel *filelocation_label;
    QPushButton *filelocation_button;
    QLineEdit *filelocation_lineedi;
    QGridLayout *gridLayout;
    QLabel *task_attributes_label;
    QComboBox *mode_combobox;
    QLabel *title_label;
    QLineEdit *title_lineedit;
    QListWidget *task_list_listwidget;
    QLabel *type_label;
    QLineEdit *type_lineedit;
    QLabel *last_performed_date_label;
    QLineEdit *last_performed_date_lineedit;
    QLabel *times_performed_label;
    QLineEdit *times_performed_lineedit;
    QLabel *vision_label;
    QPushButton *add_button;
    QPushButton *update_button;
    QPushButton *remove_button;
    QPushButton *undo_button;
    QPushButton *redo_button;
    QLineEdit *vision_lineedit;
    QFrame *line;
    QFormLayout *formLayout_2;
    QLabel *mylist_label;
    QPushButton *mylist_button;
    QLineEdit *mylist_lineedit;
    QGridLayout *gridLayout_2;
    QPushButton *open_button;
    QPushButton *save_button;
    QPushButton *next_button;
    QStackedWidget *stackedWidget;
    QWidget *page;
    QWidget *page_2;

    void setupUi(QWidget *GUI)
    {
        if (GUI->objectName().isEmpty())
            GUI->setObjectName(QString::fromUtf8("GUI"));
        GUI->resize(654, 483);
        verticalLayout = new QVBoxLayout(GUI);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        formLayout = new QFormLayout();
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        filelocation_label = new QLabel(GUI);
        filelocation_label->setObjectName(QString::fromUtf8("filelocation_label"));

        formLayout->setWidget(0, QFormLayout::LabelRole, filelocation_label);

        filelocation_button = new QPushButton(GUI);
        filelocation_button->setObjectName(QString::fromUtf8("filelocation_button"));

        formLayout->setWidget(1, QFormLayout::LabelRole, filelocation_button);

        filelocation_lineedi = new QLineEdit(GUI);
        filelocation_lineedi->setObjectName(QString::fromUtf8("filelocation_lineedi"));

        formLayout->setWidget(1, QFormLayout::FieldRole, filelocation_lineedi);


        verticalLayout->addLayout(formLayout);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        task_attributes_label = new QLabel(GUI);
        task_attributes_label->setObjectName(QString::fromUtf8("task_attributes_label"));

        gridLayout->addWidget(task_attributes_label, 0, 0, 1, 2);

        mode_combobox = new QComboBox(GUI);
        mode_combobox->addItem(QString());
        mode_combobox->addItem(QString());
        mode_combobox->addItem(QString());
        mode_combobox->setObjectName(QString::fromUtf8("mode_combobox"));

        gridLayout->addWidget(mode_combobox, 0, 5, 1, 1);

        title_label = new QLabel(GUI);
        title_label->setObjectName(QString::fromUtf8("title_label"));

        gridLayout->addWidget(title_label, 1, 0, 1, 1);

        title_lineedit = new QLineEdit(GUI);
        title_lineedit->setObjectName(QString::fromUtf8("title_lineedit"));

        gridLayout->addWidget(title_lineedit, 1, 2, 1, 2);

        task_list_listwidget = new QListWidget(GUI);
        task_list_listwidget->setObjectName(QString::fromUtf8("task_list_listwidget"));

        gridLayout->addWidget(task_list_listwidget, 1, 4, 5, 2);

        type_label = new QLabel(GUI);
        type_label->setObjectName(QString::fromUtf8("type_label"));

        gridLayout->addWidget(type_label, 2, 0, 1, 1);

        type_lineedit = new QLineEdit(GUI);
        type_lineedit->setObjectName(QString::fromUtf8("type_lineedit"));

        gridLayout->addWidget(type_lineedit, 2, 2, 1, 2);

        last_performed_date_label = new QLabel(GUI);
        last_performed_date_label->setObjectName(QString::fromUtf8("last_performed_date_label"));

        gridLayout->addWidget(last_performed_date_label, 3, 0, 1, 2);

        last_performed_date_lineedit = new QLineEdit(GUI);
        last_performed_date_lineedit->setObjectName(QString::fromUtf8("last_performed_date_lineedit"));

        gridLayout->addWidget(last_performed_date_lineedit, 3, 2, 1, 2);

        times_performed_label = new QLabel(GUI);
        times_performed_label->setObjectName(QString::fromUtf8("times_performed_label"));

        gridLayout->addWidget(times_performed_label, 4, 0, 1, 2);

        times_performed_lineedit = new QLineEdit(GUI);
        times_performed_lineedit->setObjectName(QString::fromUtf8("times_performed_lineedit"));

        gridLayout->addWidget(times_performed_lineedit, 4, 2, 1, 2);

        vision_label = new QLabel(GUI);
        vision_label->setObjectName(QString::fromUtf8("vision_label"));

        gridLayout->addWidget(vision_label, 5, 0, 1, 1);

        add_button = new QPushButton(GUI);
        add_button->setObjectName(QString::fromUtf8("add_button"));

        gridLayout->addWidget(add_button, 6, 0, 1, 1);

        update_button = new QPushButton(GUI);
        update_button->setObjectName(QString::fromUtf8("update_button"));

        gridLayout->addWidget(update_button, 6, 1, 1, 2);

        remove_button = new QPushButton(GUI);
        remove_button->setObjectName(QString::fromUtf8("remove_button"));

        gridLayout->addWidget(remove_button, 6, 3, 1, 1);

        undo_button = new QPushButton(GUI);
        undo_button->setObjectName(QString::fromUtf8("undo_button"));

        gridLayout->addWidget(undo_button, 6, 4, 1, 1);

        redo_button = new QPushButton(GUI);
        redo_button->setObjectName(QString::fromUtf8("redo_button"));

        gridLayout->addWidget(redo_button, 6, 5, 1, 1);

        vision_lineedit = new QLineEdit(GUI);
        vision_lineedit->setObjectName(QString::fromUtf8("vision_lineedit"));

        gridLayout->addWidget(vision_lineedit, 5, 2, 1, 2);


        verticalLayout->addLayout(gridLayout);

        line = new QFrame(GUI);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        verticalLayout->addWidget(line);

        formLayout_2 = new QFormLayout();
        formLayout_2->setObjectName(QString::fromUtf8("formLayout_2"));
        formLayout_2->setFieldGrowthPolicy(QFormLayout::AllNonFixedFieldsGrow);
        mylist_label = new QLabel(GUI);
        mylist_label->setObjectName(QString::fromUtf8("mylist_label"));

        formLayout_2->setWidget(0, QFormLayout::LabelRole, mylist_label);

        mylist_button = new QPushButton(GUI);
        mylist_button->setObjectName(QString::fromUtf8("mylist_button"));

        formLayout_2->setWidget(1, QFormLayout::LabelRole, mylist_button);

        mylist_lineedit = new QLineEdit(GUI);
        mylist_lineedit->setObjectName(QString::fromUtf8("mylist_lineedit"));

        formLayout_2->setWidget(1, QFormLayout::FieldRole, mylist_lineedit);


        verticalLayout->addLayout(formLayout_2);

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        open_button = new QPushButton(GUI);
        open_button->setObjectName(QString::fromUtf8("open_button"));

        gridLayout_2->addWidget(open_button, 1, 2, 1, 1);

        save_button = new QPushButton(GUI);
        save_button->setObjectName(QString::fromUtf8("save_button"));

        gridLayout_2->addWidget(save_button, 0, 0, 1, 1);

        next_button = new QPushButton(GUI);
        next_button->setObjectName(QString::fromUtf8("next_button"));

        gridLayout_2->addWidget(next_button, 1, 0, 1, 1);

        stackedWidget = new QStackedWidget(GUI);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        page = new QWidget();
        page->setObjectName(QString::fromUtf8("page"));
        stackedWidget->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName(QString::fromUtf8("page_2"));
        stackedWidget->addWidget(page_2);

        gridLayout_2->addWidget(stackedWidget, 1, 1, 1, 1);


        verticalLayout->addLayout(gridLayout_2);


        retranslateUi(GUI);

        QMetaObject::connectSlotsByName(GUI);
    } // setupUi

    void retranslateUi(QWidget *GUI)
    {
        GUI->setWindowTitle(QCoreApplication::translate("GUI", "GUI", nullptr));
        filelocation_label->setText(QCoreApplication::translate("GUI", "filelocation", nullptr));
        filelocation_button->setText(QCoreApplication::translate("GUI", "ok", nullptr));
        task_attributes_label->setText(QCoreApplication::translate("GUI", "task_attributes", nullptr));
        mode_combobox->setItemText(0, QCoreApplication::translate("GUI", "no mode", nullptr));
        mode_combobox->setItemText(1, QCoreApplication::translate("GUI", "mode A", nullptr));
        mode_combobox->setItemText(2, QCoreApplication::translate("GUI", "mode B", nullptr));

        title_label->setText(QCoreApplication::translate("GUI", "title", nullptr));
        type_label->setText(QCoreApplication::translate("GUI", "type", nullptr));
        last_performed_date_label->setText(QCoreApplication::translate("GUI", "last performed date", nullptr));
        times_performed_label->setText(QCoreApplication::translate("GUI", "times performed", nullptr));
        vision_label->setText(QCoreApplication::translate("GUI", "vision", nullptr));
        add_button->setText(QCoreApplication::translate("GUI", "add", nullptr));
        update_button->setText(QCoreApplication::translate("GUI", "update", nullptr));
        remove_button->setText(QCoreApplication::translate("GUI", "remove", nullptr));
        undo_button->setText(QCoreApplication::translate("GUI", "undo", nullptr));
        redo_button->setText(QCoreApplication::translate("GUI", "redo", nullptr));
        mylist_label->setText(QCoreApplication::translate("GUI", "mylist", nullptr));
        mylist_button->setText(QCoreApplication::translate("GUI", "ok", nullptr));
        open_button->setText(QCoreApplication::translate("GUI", "open", nullptr));
        save_button->setText(QCoreApplication::translate("GUI", "save", nullptr));
        next_button->setText(QCoreApplication::translate("GUI", "next", nullptr));
    } // retranslateUi

};

namespace Ui {
    class GUI: public Ui_GUI {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GUI_H

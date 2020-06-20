/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 5.9.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_2;
    QTableView *main_table;
    QTableView *second_table;
    QHBoxLayout *horizontalLayout;
    QLineEdit *search_lineedit;
    QLabel *label;
    QHBoxLayout *horizontalLayout_3;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QCheckBox *filter_checkbox;
    QFormLayout *formLayout;
    QLabel *label_2;
    QLineEdit *name_lineedit;
    QFormLayout *formLayout_2;
    QLabel *label_3;
    QLineEdit *d1_lineedit;
    QFormLayout *formLayout_3;
    QLabel *label_4;
    QLineEdit *d2_lineedit;
    QLineEdit *d3_lineedit;
    QPushButton *add_button;
    QPushButton *view_button;

    void setupUi(std::string a,QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QStringLiteral("Widget"));
        Widget->resize(800, 600);
        verticalLayout_3 = new QVBoxLayout(Widget);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        main_table = new QTableView(Widget);
        second_table = new QTableView;
        main_table->setObjectName(QStringLiteral("main_table"));

        horizontalLayout_2->addWidget(main_table);
        horizontalLayout_2->addWidget(second_table);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        search_lineedit = new QLineEdit(Widget);
        search_lineedit->setObjectName(QStringLiteral("search_lineedit"));

        horizontalLayout->addWidget(search_lineedit);

        label = new QLabel(Widget);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout->addWidget(label);


        horizontalLayout_2->addLayout(horizontalLayout);


        verticalLayout_3->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        filter_checkbox = new QCheckBox(Widget);
        filter_checkbox->setObjectName(QStringLiteral("filter_checkbox"));

        verticalLayout->addWidget(filter_checkbox);

        formLayout = new QFormLayout();
        formLayout->setObjectName(QStringLiteral("formLayout"));
        label_2 = new QLabel(Widget);
        label_2->setObjectName(QStringLiteral("label_2"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label_2);

        name_lineedit = new QLineEdit(Widget);
        name_lineedit->setObjectName(QStringLiteral("name_lineedit"));

        formLayout->setWidget(0, QFormLayout::FieldRole, name_lineedit);


        verticalLayout->addLayout(formLayout);

        formLayout_2 = new QFormLayout();
        formLayout_2->setObjectName(QStringLiteral("formLayout_2"));
        label_3 = new QLabel(Widget);
        label_3->setObjectName(QStringLiteral("label_3"));

        formLayout_2->setWidget(0, QFormLayout::LabelRole, label_3);

        d1_lineedit = new QLineEdit(Widget);
        d1_lineedit->setObjectName(QStringLiteral("d1_lineedit"));

        formLayout_2->setWidget(0, QFormLayout::FieldRole, d1_lineedit);


        verticalLayout->addLayout(formLayout_2);

        formLayout_3 = new QFormLayout();
        formLayout_3->setObjectName(QStringLiteral("formLayout_3"));
        label_4 = new QLabel(Widget);
        label_4->setObjectName(QStringLiteral("label_4"));

        formLayout_3->setWidget(0, QFormLayout::LabelRole, label_4);

        d2_lineedit = new QLineEdit(Widget);
        d3_lineedit = new QLineEdit(Widget);
        d2_lineedit->setObjectName(QStringLiteral("d2_lineedit"));

        formLayout_3->setWidget(0, QFormLayout::FieldRole, d2_lineedit);


        verticalLayout->addLayout(formLayout_3);
        verticalLayout->addWidget(d3_lineedit);


        verticalLayout_2->addLayout(verticalLayout);

        add_button = new QPushButton(Widget);
        add_button->setObjectName(QStringLiteral("add_button"));

        verticalLayout_2->addWidget(add_button);


        horizontalLayout_3->addLayout(verticalLayout_2);

        view_button = new QPushButton(Widget);
        view_button->setObjectName(QStringLiteral("view_button"));

        horizontalLayout_3->addWidget(view_button);


        verticalLayout_3->addLayout(horizontalLayout_3);


        retranslateUi(a, Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(std::string a, QWidget *Widget)
    {
        Widget->setWindowTitle(QString::fromStdString(a));
        label->setText(QApplication::translate("Widget", "search", Q_NULLPTR));
        filter_checkbox->setText(QApplication::translate("Widget", "filter", Q_NULLPTR));
        label_2->setText(QApplication::translate("Widget", "name", Q_NULLPTR));
        label_3->setText(QApplication::translate("Widget", "d1", Q_NULLPTR));
        label_4->setText(QApplication::translate("Widget", "d2", Q_NULLPTR));
        add_button->setText(QApplication::translate("Widget", "add", Q_NULLPTR));
        view_button->setText(QApplication::translate("Widget", "view", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H

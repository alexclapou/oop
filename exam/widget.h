#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include "repo.h"
#include <QMessageBox>
#include <QSortFilterProxyModel>
#include "model.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(Astronomer astronomer, QAbstractItemModel *model, Repository &repo, QWidget *parent = nullptr);
    ~Widget();

private:
    Repository &r;
    bool nothing = true;
    Astronomer astronomer;
    QAbstractItemModel *model;
    Ui::Widget *ui;
    void filter_own();
    void connect_all();
    void add_new_star();
    void filter_new_list();
    void closeEvent(QCloseEvent *event);
};
#endif // WIDGET_H

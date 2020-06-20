#include "model.h"
#include <QDebug>

int AstronomerModel::rowCount(const QModelIndex &parent) const{
    return repo.stars_size();
}

int AstronomerModel::columnCount(const QModelIndex &parent) const{
    return 5;
}
QVariant AstronomerModel::data(const QModelIndex &index, int role) const{
    int row = index.row();
    int col = index.column();
    auto current = repo.get_stars()[row];
    if(role == Qt::DisplayRole || role == Qt::EditRole){ 
        switch(col){
            case 0:
                return QString::fromStdString(current.get_name());
            case 1:
                return QString::fromStdString(current.get_constellation());
            case 2:
                return QString::number(current.get_ra());
            case 3:
                return QString::number(current.get_dec());
            case 4:
                return QString::number(current.get_diameter());
            default:
                break;
        }
    }
    return QVariant();
}

Qt::ItemFlags AstronomerModel::flags(const QModelIndex &index)const{
    int col = index.column();
    int row = index.row();
    if(col > 0)
        return Qt::ItemFlag();
    return Qt::ItemIsSelectable | Qt::ItemIsEditable | Qt::ItemIsEnabled;
}

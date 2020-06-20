#pragma once
#include <QDebug>
#include <QAbstractTableModel>
#include "repo.h"

class AstronomerModel:public QAbstractTableModel
{
    public:
        Repository &repo;
        AstronomerModel(Repository &r):repo{r}{}
        int rowCount(const QModelIndex &parent = QModelIndex()) const;
        void emit_something(){
            emit layoutAboutToBeChanged();
            emit layoutChanged();
        }
        int columnCount(const QModelIndex &parent = QModelIndex()) const;
        QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;
        QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const override{
		if (role == Qt::DisplayRole) {
			if (orientation == Qt::Horizontal) {
				switch (section) {
				case 0:
					return QString("Name");
				case 1:
					return QString("Constelation");
				case 2:
					return QString("RA");
				case 3:
					return QString("Dec");
				case 4:
					return QString("Diameter");
				}
			}
		}
		return QVariant();
}
        Qt::ItemFlags flags(const QModelIndex &index)const;
        void dataC(){
            const QModelIndex index;
            emit dataChanged(index, index);
        }
};

#include "csvtablemodel.h"

#include <QFile>

CsvTableModel::CsvTableModel(QObject *parent)
    : QAbstractTableModel{parent}
{}

int CsvTableModel::rowCount(const QModelIndex&) const { return rows.size(); }
int CsvTableModel::columnCount(const QModelIndex&) const { return columnHeaders.size(); }

QVariant CsvTableModel::headerData(int section, Qt::Orientation orientation, int role) const {
    if (role == Qt::DisplayRole && orientation == Qt::Horizontal) {
        return columnHeaders[section];
    }
    return {};
}

QVariant CsvTableModel::data(const QModelIndex& index, int role) const {
    if (role == Qt::DisplayRole || role == Qt::EditRole) {
        const Student& s = rows[index.row()];

        switch (index.column()) {
        case 0: return s.id;
        case 1: return s.cardNumber;
        case 2: return s.name;
        case 3: return s.trainingMethod;
        case 4: return s.token;
        default: break;
        }
    }
    return {};
}

bool CsvTableModel::setData(const QModelIndex& index, const QVariant& value, int role) {
    if (role == Qt::EditRole) {
        Student& s = rows[index.row()];

        switch (index.column()) {
        case 0: s.id = value.toString(); break;
        case 1: s.cardNumber = value.toString(); break;
        case 2: s.name = value.toString(); break;
        case 3: s.trainingMethod = value.toString(); break;
        case 4: s.token = value.toString(); break;
        default: break;
        }

        setModified(true);

        emit dataChanged(index, index);
        return true;
    }
    return false;
}

void CsvTableModel::addData(const Student& s) {
    beginInsertRows(QModelIndex(), rows.size(), rows.size());
    rows.append(s);
    endInsertRows();
    setModified(true);
}

Qt::ItemFlags CsvTableModel::flags(const QModelIndex& index) const {
    return Qt::ItemIsSelectable | Qt::ItemIsEditable | Qt::ItemIsEnabled;
}

void CsvTableModel::setModified(bool m) {
    this->modified = m;
    emit modifiedChanged(m);
}

bool CsvTableModel::isModified() const {
    return this->modified;
}

void CsvTableModel::clear() {
    beginResetModel();
    rows.clear();
    setModified(false);
    endResetModel();
}

void CsvTableModel::loadFromCsv(QString path) {
    QFile file(path);
    if (!file.open(QIODevice::ReadOnly)) {
        qDebug() << file.errorString();
        return;
    }

    QList<Student> result;

    QTextStream in(&file);
    in.readLine();

    beginResetModel();
    rows.clear();

    while (!in.atEnd()) {
        QString read = in.readLine();

        auto line = read.split(';');

        if (line.size() == 5) {
            auto s = Student(line.at(0), line.at(0), line.at(0), line.at(0), line.at(0));
            rows.append(s);
        }

    }

    setModified(false);
    endResetModel();

}
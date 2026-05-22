#ifndef CSVTABLEMODEL_H
#define CSVTABLEMODEL_H

#include "student.h"

#include <QAbstractTableModel>

class CsvTableModel : public QAbstractTableModel
{
    Q_OBJECT

signals:
    void modifiedChanged(bool m);

public:
    explicit CsvTableModel(QObject *parent = nullptr);

    QVector<Student> rows;

    bool modified = false;

    QStringList columnHeaders = { "ID", "Card Number", "Name", "Training Method", "Is Valid?" };

    int rowCount(const QModelIndex&) const override;
    int columnCount(const QModelIndex&) const override;

    QVariant headerData(int section, Qt::Orientation orientation, int role) const override;

    QVariant data(const QModelIndex& index, int role) const override;

    bool setData(const QModelIndex& index, const QVariant& value, int role) override;

    void addData(const Student& s);

    Qt::ItemFlags flags(const QModelIndex& index) const override;

    void setModified(bool m);

    bool isModified() const;

    void clear();

    void loadFromCsv(QString path);

    void saveCsv(const QString& path);
};

#endif // CSVTABLEMODEL_H

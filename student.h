#include <QString>

class Student
{
public:    
    QString id;
    QString cardNumber;
    QString name;
    QString trainingMethod; // F - Full-time, E - Evening, P - Part-time, D - Distance, O - Other
    QString token;

    Student();

    explicit Student(QString id, QString cardNumber, QString name, QString trainingMethod, QString token);

    QString toRow(const QChar& d = ',') const;


};
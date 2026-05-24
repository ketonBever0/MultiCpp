#include "student.h"

Student::Student() : id("0000000000"), cardNumber("0000000000"), name("J Doe"), trainingMethod(""), token("")
{}

Student::Student(QString id, QString cardNumber, QString name, QString trainingMethod, QString token)
    : id(id), cardNumber(cardNumber), name(name), trainingMethod(trainingMethod), token(token) {
}

QString Student::toRow(const QChar& d) const {
    return this->id + d + this->cardNumber + d + this->name + d + this->trainingMethod + d + this->token;
}
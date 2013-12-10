#include "User.h"

User::User(int id, const QString& loginName, int userType) :
    _id(id),
    _loginName(loginName),
    _userType(userType) {}

User::User() {}

int User::id() const {
    return _id;
}

const QString& User::loginName() const {
    return _loginName;
}


int User::userType() const {
    return _userType;
}

void User::setUserType(int userType) {
    _userType = userType;
}

void User::setLoginName(QString loginName){
    _loginName =loginName;
}

void User::setID(int id){
    _id=id;
}

#ifndef USER_H
#define USER_H


#include <QString>

class User {
private:
    int _id;
    int _userType;
    QString _loginName;

public:
    User(int id, const QString& loginName, int usertype);
    User();
    int id() const;
    const QString& loginName() const;
    int userType() const;
    void setUserType(int userType);
    void setLoginName(QString loginName);
    void setID(int id);

};

#endif // USER_H

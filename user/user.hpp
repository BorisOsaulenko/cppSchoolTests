#ifndef USER
#define USER

#include <iostream>
#include <string>
#include <bcrypt/BCrypt.hpp>

using namespace std;

enum userType
{
    ADMIN,
    STUDENT
};

class User
{
protected:
    string login;
    string password;
    userType type;

    static vector<string> usedLogins;

public:
    virtual void print() = 0;
    string getLogin();
    bool checkPassword(string password);
    static bool isLoginTaken(string login);
    userType getType();
    void codePassword();
};

vector<string> User::usedLogins;

bool User::checkPassword(string p)
{
    return BCrypt::validatePassword(p, this->password);
}

bool User::isLoginTaken(string login)
{
    if (find(usedLogins.begin(), usedLogins.end(), login) != usedLogins.end())
        return true;

    return false;
}

userType User::getType()
{
    return this->type;
}

void User::codePassword()
{
    password = BCrypt::generateHash(password);
}

string User::getLogin()
{
    return login;
};

#endif
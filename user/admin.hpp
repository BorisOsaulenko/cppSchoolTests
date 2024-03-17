#include "./user.hpp"
#include "./student.hpp"
#include "../test/test.hpp"
#include <iostream>
#include <string>
#include <vector>

class Admin : public User
{
private:
    vector<Student> _students;
    vector<Test> _tests;

public:
    void print();
    Admin(string login, string password);
    void updatePassword(string newPassword);
    void updateLogin(string newLogin);

    void createStudent(Student student);
    void deleteStudent(int studentIdx);
    void updateStudent(int studentIdx, Student newStudent);
    Student getStudent(int studentIdx);
    Student getStudentByLogin(string login);

    void addTest(Test test);
    void deleteTest(int testIdx);
    void updateTest(int testIdx, Test newTest);
    Test getTest(int testIdx);
    Test getTestByName(string name);

    bool doesUserExist(string login);

    vector<Student> getStudents();
    vector<Test> getTests();
    void printTests();
    void printStudents();
};

Admin::Admin(string login, string password)
{
    if (isLoginTaken(login))
    {
        throw runtime_error("Error: Login is already taken");
    }
    this->login = login;
    this->password = password;
    this->codePassword();
}

void Admin::print()
{
    cout << "Admin: " << login << endl;
};

void Admin::updatePassword(string newPassword)
{
    this->password = newPassword;
    this->codePassword();
};

void Admin::updateLogin(string newLogin)
{
    this->login = newLogin;
}

void Admin::createStudent(Student student)
{
    _students.push_back(student);
}

void Admin::deleteStudent(int studentIdx)
{
    if (studentIdx < 0 || studentIdx >= _students.size())
    {
        throw runtime_error("Error: Student index is out of bounds");
    }
    _students.erase(_students.begin() + studentIdx);
}

void Admin::updateStudent(int studentIdx, Student newStudent)
{
    if (studentIdx < 0 || studentIdx >= _students.size())
    {
        throw runtime_error("Error: Student index is out of bounds");
    }
    _students[studentIdx] = newStudent;
}

Student Admin::getStudent(int studentIdx)
{
    if (studentIdx < 0 || studentIdx >= _students.size())
    {
        throw runtime_error("Error: Student index is out of bounds");
    }
    return _students[studentIdx];
}

void Admin::addTest(Test test)
{
    _tests.push_back(test);
}

void Admin::deleteTest(int testIdx)
{
    if (testIdx < 0 || testIdx >= _tests.size())
    {
        throw runtime_error("Error: Test index is out of bounds");
    }
    _tests.erase(_tests.begin() + testIdx);
}

void Admin::updateTest(int testIdx, Test newTest)
{
    if (testIdx < 0 || testIdx >= _tests.size())
    {
        throw runtime_error("Error: Test index is out of bounds");
    }
    _tests[testIdx] = newTest;
}

Test Admin::getTest(int testIdx)
{
    if (testIdx < 0 || testIdx >= _tests.size())
    {
        throw runtime_error("Error: Test index is out of bounds");
    }
    return _tests[testIdx];
}

vector<Student> Admin::getStudents()
{
    return _students;
}

vector<Test> Admin::getTests()
{
    return _tests;
}

bool Admin::doesUserExist(string login)
{
    return User::isLoginTaken(login);
};

Student Admin::getStudentByLogin(string login)
{
    for (int i = 0; i < _students.size(); i++)
    {
        if (_students[i].getLogin() == login)
        {
            return _students[i];
        }
    }
    throw runtime_error("Error: Student not found");
}

Test Admin::getTestByName(string name)
{
    for (int i = 0; i < _tests.size(); i++)
    {
        if (_tests[i].getName() == name)
        {
            return _tests[i];
        }
    }
    throw runtime_error("Error: Test not found");
}

void Admin::printTests()
{
    int counter = 0;
    for (Test test : _tests)
    {
        cout << counter++ << ": " << test.getName() << endl;
    }
}

void Admin::printStudents()
{
    int counter = 0;
    for (Student student : _students)
    {
        cout << counter++ << ": " << student.getLogin() << endl;
    }
}
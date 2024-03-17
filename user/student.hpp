#include "./user.hpp"
#include <iostream>
#include <string>
#include <vector>
#include "../test/test.hpp"
#include "../test/question/question.hpp"

using namespace std;

#ifndef STUDENT
#define STUDENT
class Student : public User
{
private:
    string name;
    string surname;
    string fathersName;
    string livePlace;
    string phoneNumber;

    vector<Test> tests;

public:
    void print();
    Student(string login, string password, string name, string surname, string fathersName, string livePlace, string phoneNumber);
    bool doesHaveTest(Test test);
    vector<Test> getTests();
    void addTest(Test test);
    void goToTest(int testIdx);
    void doTest();
    int currentTestIdx;
};

Student::Student(string login, string password, string name, string surname, string fathersName, string livePlace, string phoneNumber)
{
    if (isLoginTaken(login))
    {
        throw runtime_error("Error: Login is already taken");
    }
    this->login = login;
    this->password = password;
    this->codePassword();
    this->name = name;
    this->surname = surname;
    this->fathersName = fathersName;
    this->livePlace = livePlace;
    this->phoneNumber = phoneNumber;
    this->currentTestIdx = -1;
}

vector<Test> Student::getTests()
{
    return tests;
}

void Student::addTest(Test test)
{
    if (doesHaveTest(test))
    {
        throw runtime_error("Error: You already have this test");
    }
    tests.push_back(test);
}

void Student::print()
{
    cout << "Name: " << name << endl;
    cout << "Surname: " << surname << endl;
    cout << "Fathers name: " << fathersName << endl;
    cout << "Phone number: " << phoneNumber << endl;
    cout << "You have " << tests.size() << " tests: " << endl;
    for (int i = 0; i < tests.size(); i++)
    {
        cout << i << ": " << tests[i].getName() << endl;
    }
}

void Student::goToTest(int testIdx)
{
    if (testIdx < 0 || testIdx >= tests.size())
    {
        throw runtime_error("Error: Test index is out of bounds");
    }
    currentTestIdx = testIdx;
}

bool Student::doesHaveTest(Test test)
{
    for (Test t : tests)
    {
        if (t.getName() == test.getName())
        {
            return true;
        }
    }
    return false;
};

void Student::doTest()
{
    int answer = -1;
    cout << "Doing: " << tests[currentTestIdx].getName() << endl;
    while (answer != 0 && !tests[currentTestIdx].isFinished())
    {
        tests[currentTestIdx].getCurrentQuestion().print();
        cout << "Your answer: ";
        cin >> answer;
        tests[currentTestIdx].answer(answer - 1);
    }
};

#endif
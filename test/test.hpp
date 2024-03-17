#include <iostream>
#include <string>
#include <vector>
#include <list>
#include "./question/question.hpp"

using namespace std;

#ifndef _TEST
#define _TEST
class Test
{
private:
    string _name;
    static vector<string> _takenNames;
    list<Question> _questions;
    int _questionIdx;
    int _rightAnswersCount;
    int _wrongAnswersCount;

public:
    Test(string name, list<Question> questions);
    Question getCurrentQuestion();
    string getName();
    bool isFreeName(string name);
    void print();
    void answer(int optionIdx);
    bool checkAnswer(int idx);
    int getScore();
    int getPercentage();
    int getMark();
    int questionsCount();
    int howManyQuestionsLeft();
    bool isFinished();
    bool hasPassed();
};

vector<string> Test::_takenNames = vector<string>();

bool Test::isFreeName(string name)
{
    return find(_takenNames.begin(), _takenNames.end(), name) == _takenNames.end();
}

Test::Test(string name, list<Question> questions)
{
    if (name.size() < 2)
    {
        throw runtime_error("Error: Test name is too short. Try specifying more details");
    }
    if (!isFreeName(name))
    {
        throw runtime_error("Error: Test name is already taken");
    }

    _name = name;
    _takenNames.push_back(name);

    if (questions.size() < 5)
    {
        throw runtime_error("Error: Test must have at least 5 questions");
    }
    _questions = questions;
    _questionIdx = 0;
    _rightAnswersCount = 0;
    _wrongAnswersCount = 0;
}

Question Test::getCurrentQuestion()
{
    if (_questionIdx >= questionsCount())
    {
        throw runtime_error("Error: No more questions");
    }
    auto it = _questions.begin();
    advance(it, _questionIdx);

    return *it;
}

string Test::getName()
{
    return _name;
};

void Test::print()
{
    if (isFinished())
    {
        cout << "Test is finished" << endl;
        cout << "Right answers: " << _rightAnswersCount << endl;
        cout << "Wrong answers: " << _wrongAnswersCount << endl;
        cout << "Mark: " << getMark() << endl;
        cout << "Percentage: " << getPercentage() << "%" << endl;
        return;
    };
    cout << "Test: " << _name << endl;
    cout << "Remains " << questionsCount() - _questionIdx << " questions" << endl;
}

void Test::answer(int optionIdx)
{
    if (isFinished())
    {
        cout << "Error: Test is already finished" << endl;
        return;
    }

    if (optionIdx == -1)
        return; // stop idx

    if (optionIdx < 0 || optionIdx > questionsCount())
    {
        cout << "Error: Invalid option" << endl;
        return;
    }

    if (getCurrentQuestion().checkAnswer(optionIdx))
    {
        cout << "Right answer!" << endl;
        _rightAnswersCount++;
    }
    else
    {
        cout << "Wrong answer!" << endl;
        cout << "Right answer: " << getCurrentQuestion().getCorrectIdx() + 1 << endl;
        _wrongAnswersCount++;
    }

    _questionIdx++;
}

bool Test::checkAnswer(int idx)
{
    return getCurrentQuestion().checkAnswer(idx);
}

int Test::getScore()
{
    return _rightAnswersCount;
}

int Test::getPercentage()
{
    return _rightAnswersCount * 100 / questionsCount();
}

int Test::getMark()
{
    return getPercentage() / 100.0 * 12;
}

int Test::questionsCount()
{
    return _questions.size();
}

int Test::howManyQuestionsLeft()
{
    return questionsCount() - _questionIdx;
}

bool Test::isFinished()
{
    return questionsCount() == _questionIdx;
}

bool Test::hasPassed()
{
    return getPercentage() >= 50;
}

#endif
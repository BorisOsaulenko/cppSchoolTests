#include <iostream>
#include <vector>
#include "./category.hpp"

using namespace std;

#ifndef QUESTION
#define QUESTION

class Question
{
private:
    string text;
    categoryVariant category;
    vector<string>
        options;
    int correctIdx;

public:
    void print();
    Question(string text, categoryVariant category, vector<string> options, int correctIdx);
    bool checkAnswer(int idx);
    int getCorrectIdx();
    categoryVariant getQuestionCategory();
    string getText();
    vector<string> getOptions();
};

void Question::print()
{
    cout << text << endl;
    for (int i = 1; i <= options.size(); i++)
    {
        cout << i << ". " << options[i - 1] << endl;
    }
    cout << "0. Stop test" << endl;
}

inline Question::Question(string text, categoryVariant category, vector<string> options, int correctIdx)
{
    if (correctIdx < 0 || correctIdx >= options.size())
    {
        throw runtime_error("Error: Correct option index is out of bounds");
    }
    if (options.size() < 2)
    {
        throw runtime_error("Error: Question must have at least 2 options");
    }
    if (text.size() < 8)
    {
        throw runtime_error("Error: Question is too short. Try specifying more details");
    }
    this->text = text;
    this->options = options;
    this->correctIdx = correctIdx;
}

bool Question::checkAnswer(int idx)
{
    return correctIdx == idx;
}

int Question::getCorrectIdx()
{
    return correctIdx;
}

categoryVariant Question::getQuestionCategory()
{
    return category;
}

string Question::getText()
{
    return text;
}

vector<string> Question::getOptions()
{
    return options;
}

#endif
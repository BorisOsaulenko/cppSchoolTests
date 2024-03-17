#include <iostream>
#include <vector>
#include "../test/question/question.hpp"
#include "../test/question/category.hpp"
#include "../test/test.hpp"

using namespace std;

Question q1("1 + 1 = ?", MathsCategories::ALGEBRA, {"1", "2", "3", "4"}, 1);
Question q2("1 + 2 = ?", MathsCategories::ALGEBRA, {"1", "2", "3", "4"}, 2);
Question q3("1 + 3 = ?", MathsCategories::ALGEBRA, {"1", "2", "3", "4"}, 3);
Question q4("1 + 4 = ?", MathsCategories::ALGEBRA, {"5", "6", "7", "8"}, 0);
Question q5("1 + 5 = ?", MathsCategories::ALGEBRA, {"5", "6", "7", "8"}, 1);
list<Question> questions1 = {q1, q2, q3, q4, q5};

Question q6("1 + 1 = ?", PhysicsCategories::MECHANICS, {"1", "2", "3", "4"}, 1);
Question q7("What is Newton's first law of motion?", PhysicsCategories::MECHANICS, {"Law of Inertia", "Law of Force", "Law of Acceleration", "Law of Action-Reaction"}, 0);
Question q8("Define impulse in mechanics.", PhysicsCategories::MECHANICS, {"Momentum over time", "Force over distance", "Change in momentum", "Acceleration over time"}, 2);
Question q9("Explain the concept of rotational motion.", PhysicsCategories::MECHANICS, {"Linear motion along a curve", "Motion in a straight line", "Motion around an axis", "Random motion"}, 2);
Question q10("What is the principle of conservation of angular momentum?", PhysicsCategories::MECHANICS, {"Angular momentum is always zero", "Angular momentum is constant when no external torque is applied", "Angular momentum decreases with time", "Angular momentum is inversely proportional to velocity"}, 1);
list<Question> questions2 = {q6, q7, q8, q9, q10};

#ifndef TESTS
#define TESTS

Test test1("Algebra Test", questions1);
Test test2("Mechanics Test", questions2);

#endif
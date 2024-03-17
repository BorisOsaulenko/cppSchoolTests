#include <iostream>
#include "../test/test.hpp"
#include "../test/demoTests.hpp"
#include "../user/admin.hpp"
#include "../user/student.hpp"

using namespace std;

int main()
{
    string adminLogin = "admin";
    string adminPassword = "admin";

    Admin admin = Admin(adminLogin, adminPassword);
    admin.print();

    admin.addTest(test1);
    admin.addTest(test2);

    Student student1 = Student("login1", "password1", "name1", "surname1", "fathersName1", "livePlace1", "phoneNumber1");
    Student student2 = Student("login2", "password2", "name2", "surname2", "fathersName2", "livePlace2", "phoneNumber2");
    admin.createStudent(student1);
    admin.createStudent(student2);

    student1.addTest(test1);
    student1.addTest(test2);

    student2.addTest(test1);
    student2.addTest(test2);

    student1.print();
    cout << endl
         << endl;
    student2.print();

    cout << endl
         << endl;

    student1.goToTest(0); // stop or finish the test
    student1.doTest();

    cout << endl
         << endl;
    student1.getTests()[0].print();
    cout << endl
         << endl;
    student1.goToTest(1);
    student1.doTest();

    cout << endl
         << endl;

    student1.getTests()[1].print();

    cout << endl
         << endl;

    student1.print();

    return 0;
}
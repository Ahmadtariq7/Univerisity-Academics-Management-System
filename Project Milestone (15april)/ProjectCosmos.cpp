#include <iostream>
#include <string>
#include <stdlib.h>
#include <fstream>
using namespace std;

class User {
public:
    string username;
    string password;
    User();
};
// defining constructor
User::User() {
    username = "NULL";
    password = "NULL";
}
class Admin : public User {
public:
    void login();
    void admin_panel();
    void add_faculty();
    void edit_faculty();
    void del_faculty();
    void add_student();
    void edit_student();
    void del_student();
    void add_batch();
    void edit_batch();
    void del_batch();
    void add_semester();
    void edit_semester();
    void del_semester();
    void add_courses();
    void edit_courses();
    void del_courses();
    //sections of courses, faculty members to section courses, student to courses/.....
    void view_registration();
    void view_attendence();
    void view_marks_ditribution();
    void view_transcript();
    void view_evaluation_report();
    Admin();
};
// defining constructor
Admin::Admin() {
    username = "admin";
    password = "1234";
}
//defining functions of admin...
void Admin::add_semester() { //have some problem in it...
    fstream fout;
    fout.open("/Volumes/Untitled/WORK/CP /Semester Project/semester.csv", ios::out | ios::app);
    fout << "Hello, 1, 3,hello, How are you,";
    fout.close();
    fstream fin;
    string line;
    fin.open("/Volumes/Untitled/WORK/CP /Semester Project/semester.csv", ios::in);
    while(fin) {
        getline(fin, line);
        cout << line << endl;
    }
    fin.close();
}
void Admin::login() {
    string username, password;
    int x=0;
    while (x ==0) {
        cout << "Enter your Username: " << endl;
        cin >> username;
        int y=0;
        if(username==this->username) {
            x=1;
            while (y==0) {
                cout << "Enter Password: " << endl;
                cin >> password;
                if(password==this->password) {
                    cout << "You are in" << endl;
                    y=1;
                }
                else
                    cout<<"try again"<<endl;

            }
        }
        else {
            cout << "Try again" << endl;
        }

        }
    }
void Admin::admin_panel() {
    system("clear");
    cout << "////\t ////\t In Admin \t//// \t////\n" << endl;
    cout << "1. Add Semester\n2. Edit Semester\n3. Delete Semester\n4. Add Batch\n5. Edit Batch\n6. Delete Batch\n7. Add Courses\n8. Edit Courses\n9. Delete Courses\n10. Add Faculty\n11. Edit Faculty\n12. Delete Faculty\n13. Add Student\n14. Edit Student\n15. Delete Student\n16. View Registration\n17. View Attendence\n18. View Transcript\n19. View Marks Distribution\n20. Previous Menu\n" << endl;
    int select = 0;
    cout << "Enter: " << endl;
    cin >> select;
    switch (select) {
        case 1:
            add_semester();
            break;
//        case 2:
//            edit_semester();
//            break;
//        case 3:
//            del_semester();
//            break;
//        case 4:
//            add_batch();
//            break;
//        case 5:
//            edit_batch();
//            break;
//        case 6:
//            del_batch();
//            break;
//        case 7:
//            add_courses();
//            break;
//        case 8:
//            edit_courses();
//            break;
//        case 9:
//            del_courses();
//            break;
//        case 10:
//            add_faculty();
//            break;
//        case 11:
//            edit_faculty();
//            break;
//        case 12:
//            del_faculty();
//            break;
//        case 13:
//            add_student();
//            break;
//        case 14:
//            edit_student();
//            break;
//        case 15:
//            del_student();
//            break;
//        case 16:
//            view_registration();
//            break;
//        case 17:
//            view_attendence();
//            break;
//        case 18:
//            view_transcript();
//            break;
//        case 19:
//            view_marks_ditribution();
//            break;
//        case 20:
//            Interface::mainscreen();  //showing error, will be resolved later...
//            break;
        default:
            cout << "Enter number from 1-20" << endl;

    }
}

// admin ends here....
class Faculty : public User{
private:
    void manage_attendence();
    void manage_marks();
    void manage_evaluation(); //quizes,assignments,projects
    void view_evaluation();
    void assign_grades();
    void view_profile();
public:
    Faculty();
    void login();
    void Faculty_panel();
};
Faculty::Faculty() {
    username = "NULL";
    password = "NULL";
}
//defining faculty methods here..
void Faculty::login() {
    string username, password;
    int x=0;
    while (x ==0) {
        cout << "Enter your Username: " << endl;
        cin >> username;
        int y=0;
        if(username==this->username) {
            x=1;
            while (y==0) {
                cout << "Enter Password: " << endl;
                cin >> password;
                if(password==this->password) {
                    cout << "You are in" << endl;
                    y=1;
                }
                else
                    cout<<"try again"<<endl;

            }
        }
        else {
            cout << "Try again" << endl;
        }

    }
}
void Faculty::Faculty_panel() {
    system("clear");
    cout << "////\t ////\t In Faculty \t//// \t////\n" << endl;
    cout << "1. Manage Attendence\n2. Manage Marks\n3. Manage Evaluation\n4. View Evaluation\n5. Assign Grades\n6. View Profile\n7. Previous Menu" << endl;
    int select = 0;
    cout << "Enter: " << endl;
    cin >> select;
    switch (select) {
//        case 1:
//            manage_attendence();
//            break;
//        case 2:
//            manage_marks();
//            break;
//        case 3:
//            manage_evaluation();
//            break;
//        case 4:
//            view_evaluation();
//            break;
//        case 5:
//            assign_grades();
//            break;
//        case 6:
//            view_profile();
//            break;
//        case 7:
////            Interface::main_screen();  //error, will resolve later...
//            break;
        default:
            cout << "Enter number from 1-7" << endl;

    }
}

//class Student .....
class Student : public Admin {
private:
    void view_profile();
    void view_attendence(); //of all add_courses
    void view_marks(); //of all add_courses
    void view_transcript();
public:
    Student();
    void log_in();
    void apply_course();
    void student_panel();
};
Student::Student() {
    username = "NULL";
    password = "NULL";
}
//defining student methods..
void Student::log_in() {
    string username, password;
    int x=0;
    while (x ==0) {
        cout << "Enter your Username: " << endl;
        cin >> username;
        int y=0;
        if(username==this->username) {
            x=1;
            while (y==0) {
                cout << "Enter Password: " << endl;
                cin >> password;
                if(password==this->password) {
                    cout << "You are in" << endl;
                    y=1;
                }
                else
                    cout<<"try again"<<endl;

            }
        }
        else {
            cout << "Try again" << endl;
        }

    }
}
void Student::student_panel() {
    system("clear");
    cout << "////\t ////\t In Student \t//// \t////\n" << endl;
    cout << "1. View Profile\n2. View Attendence\n3. View Marks\n4. View Transcript\n5. Apply for course\n6. Previous Menu" << endl;
    int select = 0;
    cout << "Enter: " << endl;
    cin >> select;
    switch (select) {
//        case 1:
//            view_profile();
//            break;
//        case 2:
//            view_attendence();
//            break;
//        case 3:
//            view_marks();
//            break;
//        case 4:
//            view_transcript();
//            break;
//        case 5:
//            apply_course();
//            break;
//        case 6:
////            Interface::main_screen() //error, will solve later...
//            break;
//        default:
//            cout << "Enter numbers from 1-6" << endl;
//            break;
    }
}
//Interface starting here....
class Interface{
public:
    void main_screen();
};
void Interface::main_screen() {
    cout << "////\t ////\t Project COSMOS \t//// \t////\n" << endl;
    cout << "Select one(1,2,3): \n" << endl;
    cout << "1. Admin \n2. Faculty \n3. Student " << endl;
    int select = 0;
    cout << "Enter: " << endl;
    cin >> select;
    if (select == 1) {
        Admin A1;
        A1.login();
        A1.admin_panel();

    }
    else if (select == 2) {
        Faculty F1;
        F1.login();
        F1.Faculty_panel();
    }
    else if (select == 3) {
        Student S1;
        S1.log_in();
        S1.student_panel();
    }
}

int main() {
    // just for checking..
    Interface I1;
    I1.main_screen();



    return 0;
}

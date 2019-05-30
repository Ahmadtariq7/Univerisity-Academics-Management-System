#include <iostream>
#include <string>
#include <stdlib.h>
#include <fstream>
using namespace std;

class User {
public:
    string name;
    string father_name;
    char gender;
    string id;
    int age;
    string username;
    string password;
    User();
};
// defining constructor
User::User() {
    name = "NULL";
    father_name = "NULL";
    gender = 'I';
    id = "NULL";
    age = 0;
    username = "NULL";
    password = "NULL";
}
//class Student .....
class Student: public User {
private:
    void view_profile(string username_check);
    void view_attendence(string username_check); //of all add_courses
    void view_marks(); //of all add_courses
    void view_transcript();
public:
    string username_check;
    Student();
    void log_in();
    void apply_course();
    void student_panel();
};
Student::Student() {
    name = "NULL";
    father_name = "NULL";
    gender = 'I';
    age = 0;
    id = "NULL";
    username = "NULL";
    password = "NULL";
}
//defining student methods..
void Student::view_profile(string username_check) {
    string check,batch, semester, section, password, username;
    check = "Students_info.csv";
    ifstream fin(check, ios::in);
    bool c = false;
    while(!fin.eof()) {
        getline(fin, batch, ',');
        getline(fin, semester, ',');
        getline(fin, section, ',');
        getline(fin, username, ',');
        getline(fin, password, '\n');
        if (username == username_check)
        {
            c = true;
            break;
        }
    }
    fin.close();
    check = batch + "/" + "semester" + semester + "/sec-" + section + "/" + username + "/bio.csv";
//    cout << check << endl;
    ifstream file(check, ios::in);
    string a = "";
    if (file.is_open())
    {
        getline(file, a, ',');
        cout << "Name:\t" << a << endl;
        getline(file, a, ',');
        cout << "Father Name:\t" << a << endl;
        getline(file, a, ',');
        cout << "Gender:\t" << a << endl;
        getline(file, a, ',');
        cout << "Age:\t" << a << endl;
        getline(file, a, ',');
        cout << "ID:\t" << a <<endl;
        getline(file, a, ',');
        cout << "Username:\t" << a << endl;
        getline(file, a, '\n');
    }
    file.close();
}
void Student::view_attendence(string username_check) {

}
void Student::log_in() {
    string username, password, check;
    string a = "";
    string b = "";
    int x =0;
    check = "Students_info.csv";
    while (x ==0) {
        cout << "Enter your Username: " << endl;
        cin >> username;
        username_check = username;
        int y=0;
        fstream fin(check, ios::in);
        bool c = false;
        bool d = false;
        while (!fin.eof()) {
            getline(fin, a, ',');
            getline(fin, a, ',');
            getline(fin, a, ',');
            getline(fin, a, ',');
            if (a == username) {
                c = true;
                x = 1;
                while (y==0) {
                    cout << "Enter Password: " << endl;
                    cin >> password;
                    fstream f2(check, ios::in);
                    while (!f2.eof()) {
                        getline(f2, b, ',');
                        getline(f2, b, ',');
                        getline(f2, b, ',');
                        getline(f2, b, ',');
                        getline(f2, b, '\n');
                        if (b == password) {
                            d = true;
                            y = 1;
                            student_panel();
                            break;
                        }
                    }
                    if (d == false) {
                        cout << "Try Again" << endl;
                    }
                }

            }
        }
        if (c == false) {
            cout << "Try Again" << endl;
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
        case 1:
            view_profile(username_check);
            break;
        case 2:
            view_attendence(username_check);
            break;
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
class Faculty : public User{
private:
    void manage_attendence(string id_check);
    void manage_marks();
    void manage_evaluation(); //quizes,assignments,projects
    void view_evaluation();
    void assign_grades();
    void view_profile();
public:
    string id_check;
    Faculty();
    void login();
    void Faculty_panel();
};
Faculty::Faculty() {
    name = "NULL";
    father_name = "NULL";
    gender = 'I';
    age = 0;
    id = "NULL";
    username = "NULL";
    password = "NULL";
}
//defining faculty methods here..
void Faculty::manage_attendence(string id_check) {
    string batch, semester, section, course_code;
    string a = "";
    string faculty_check;
    cout << "Batch No: " << endl;
    cin >> batch;
    cout << "Semester: " << endl;
    cin >> semester;
    cout << "Section: " << endl;
    cin >> section;
    cout << "Course Code: "<< endl;
    cin >> course_code;
    faculty_check = "faculty/" + id_check + ".csv";
    ifstream fin(faculty_check, ios::in);
    bool c = false;
    while(!fin.eof()) {
        getline(fin, a, '\n');
        if (a == course_code) {
            c = true;
            faculty_check = "Students_info.csv";
            break;
        }
    }
    if (c == false)
    {
        cout << "Invalid Course Selection\n";
        return;
    }
    else
    {
        string path = "";
        ifstream f2(faculty_check, ios::in);
        while (!f2.eof())
        {
            string roll = "";
            getline(f2, a, ',');
            getline(f2, a, ',');
            getline(f2, a, ',');
            getline(f2, a, ',');
            roll = a;
            if (a == "")
                break;
            path = batch + "/semester" + semester + "/sec-" + section + "/" + a + "/" + course_code + "/" + course_code + "-" + "Attendance.csv";
            int count = 0;
            fstream file(path, ios::in);
            while(!file.eof())
            {
                getline(file, a, ',');
                count++;
            }
            if (count < 32) {
                char proxy;
                fstream f3(path,ios::app);
                cout << "Mark A for Absent and P for Present. " << endl;
                cout << "Mark Attendance for " << roll << " here :";
                cin >> proxy;
                f3 << proxy << ',';
                count = 0;
                }
            else {
                cout << "You have already marked full attendance" << endl;
            }
            getline(f2, a, '\n');
        }
    }
}
void Faculty::login() {
    string id, password, check;
    string a = "";
    int x =0;
    while (x==0) {
        cout << "Enter your ID: " << endl;
        cin >> id;
        id_check = id;
        check = "faculty/" + id + ".csv";
        ifstream fin(check, ios::in);
        if (fin.is_open()) {
            x = 1;
            int y = 0;
            while (y ==0) {
                cout << "Enter Password: " << endl;
                cin >> password;
                while (!fin.eof()) {
                    getline(fin, a, ',');
                    getline(fin, a, ',');
                    getline(fin, a, ',');
                    getline(fin, a, ',');
                    getline(fin, a, ',');
                    getline(fin, a, '\n');
                    if (a == password) {
                        Faculty_panel();
                        y = 1;
                        break;

                    }

                }

            }

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
        case 1:
            manage_attendence(id_check);
            break;
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
class Admin : public User {
private:
    Student std;
    Faculty fac;
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
    void add_section();
    void del_section();
    void Assign_courses(); //to faculty
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
void Admin::add_batch() {
    string batch;
    cout << "Enter the batch No. you want to Register: " << endl;
    cin >> batch;
    system(("mkdir "+batch).c_str());
    system("ls");
    cout << "Batch" << batch << "Created Successfully";
}
void Admin::edit_batch() {
    string batch, new_batch;
    cout << "Enter the batch No. you want to edit: " << endl;
    cin >> batch;
    cout << "Enter the New batch name: " << endl;
    cin >> new_batch;
    system(("mv "+batch+new_batch).c_str());
    system("ls");
    cout << "Batch Changed from" << batch << "to" << new_batch << endl;
}
void Admin::del_batch() {
    string batch;
    cout << "Enter the batch No. you want to delete: " << endl;
    cin >> batch;
    system(("rm -r "+batch).c_str());
    cout << "Batch_" << batch << " Deleted Successfully...";
}
void Admin::add_semester() {
    string batch, semester;
    cout << "Enter the batch you want to create semester in: " << endl;
    cin >>  batch;
    cout << "Enter Semster No. : " << endl;
    cin >> semester;
    if (semester == "1") {
        system(("mkdir "+ batch + "/" + "semester"+ semester).c_str());
        fstream fout;
        string file =  batch + "/" + "semester" + semester +  "/semester1.csv";
        cout << file << endl;
        fout.open(file, ios::out);
        fout << "CL101,Introduction to ComputingLab,1\nCS101,Introduction to Computing,3\nEE182,Basic Electronics,3\nMT101,Calculus-1,3\nSL101,English Language,3\nSS101,English Language Lab,1\nSS111,Islamic and Religious studies,3\nSS203,Professional Ethics,3\n";
        fout.close();
        cout << "Semester added Successfully.." << endl;
        add_semester();
    }
    else if (semester == "2") {
        system(("mkdir "+ batch + "/" + "semester"+ semester).c_str());
        fstream fout;
        string file =  batch + "/" + "semester" + semester + "/semester2.csv";
        cout << file << endl;
        fout.open(file, ios::out);
        fout << "CL103,Computer Programming Lab,1\nCS103,Computer Programming,3\nEE227,Digital Logic Design,3\nEL227,Digital Logic Design Lab,1\nMT115,Calculus-2,3\nSS113,Pakistan Studies,3\nSS122,English Compostion,3\n";
        fout.close();
        cout << "Semester added Successfully.." << endl;
    }
    else if (semester == "3") {
        system(("mkdir "+ batch + "/" + "semester"+ semester).c_str());
        fstream fout;
        string file =  batch + "/" + "semester" + semester + "/semester3.csv";
        cout << file << endl;
        fout.open(file, ios::out);
        fout << "CS201,Data Structures,3\nCS211,Discrete Structures,3\nEE213,Comp-Organization-and-Assembly-Lang,3\nEL213,Comp-Organization-and-Assembly-Lang-Lab,1\nMT104,Linear-Algebra,3\n";
        fout.close();
        cout << "Semester added Successfully.." << endl;
    }
    else if (semester == "4") {
        system(("mkdir "+ batch + "/" + "semester"+ semester).c_str());
        fstream fout;
        string file = batch + "/" + "semester" + semester + "/semester4.csv";
        cout << file << endl;
        fout.open(file, ios::out);
        fout << "CL203,Database-Systems-Lab,1\nCL205,Operating-Systems-Lab,1\nCS203,Database-Systems,3\nCS205,Operating-Systems,3\nCS302,Design-and-Analysis-of-Algorithms,3\n";
        fout.close();
        cout << "Semester added Successfully.." << endl;
    }
    else if (semester == "5") {
        system(("mkdir "+ batch + "/" + "semester"+ semester).c_str());
        fstream fout;
        string file = batch + "/" + "semester" + semester + "/semester5.csv";
        cout << file << endl;
        fout.open(file, ios::out);
        fout << "CL307,Computer-Networks-Lab,1\nCL309,Object-Oriented-Analysis-and-Design-Lab,1\nCS301,Theory-of-Automata,3\nCS307,Computer-Networks,3\nCS309,Object-Oriented-Analysis-and-Design,3\nMT206,Probability-and-Statistics,4\n";
        fout.close();
        cout << "Semester added Successfully.." << endl;
    }
    else if (semester == "6") {
        system(("mkdir "+ batch + "/" + "semester"+ semester).c_str());
        fstream fout;
        string file =batch + "/" + "semester" + semester + "/semester6.csv";
        cout << file << endl;
        fout.open(file, ios::out);
        fout << "CS303,Software-Engineering,3\nCS401,Artificial-Intelligence,3\nSS108,Technical-and-Business-Writing,3\n ";
        fout.close();
        cout << "Semester added Successfully.." << endl;
    }
    else if (semester == "7") {
        system(("mkdir "+ batch + "/" + "semester"+ semester).c_str());
        fstream fout;
        string file = batch + "/" + "semester" + semester + "/semester7.csv";
        cout << file << endl;
        fout.open(file, ios::out);
        fout << "CS422,Human-Computer-Interaction,3\nCS491,Project-I,3\nEE204,Computer-Architecture,3\n";
        fout.close();
        cout << "Semester added Successfully.." << endl;
    }
    else if (semester == "8") {
        system(("mkdir "+ batch + "/" + "semester"+ semester).c_str());
        fstream fout;
        string file = batch + "/" + "semester" + semester + "/semester8.csv";
        cout << file << endl;
        fout.open(file, ios::out);
        fout << "CS492,Project-II,3\nCS449,Professional-Issues-in-IT,3\n";
        fout.close();
        cout << "Semester added Successfully.." << endl;
    }
    else {
        cout << "Enter number b/w 1-8" << endl;
    }
    //for reading....
    //    fstream fin;
    //    string line;
    //    string file = "/" + batch + "/semester1.csv";
    //    fin.open(file , ios::in);
    //    while(!fin.eof()) {
    //        cout << "Here\n";
    //        getline(fin, line);
    //        fin << line << endl;
    //    }
    //    fin.close();
}
void Admin::edit_semester() {
    cout << "will do later :P" << endl;
}
void Admin::del_semester() {
    string batch;
    cout << "Enter the batch you want to delete semester in: " << endl;
    cin >>  batch;
    string semester;
    cout << "Enter the semester you want to delete: " << endl;
    cin >> semester;
    system(("rm -r "+ batch + "/" + "semester"+ semester).c_str());
    cout << "Semester_" << semester << " Deleted Successfully..." << endl;
}
void Admin::add_courses() {
    string batch, semester, course_code;
    cout << "Enter the batch No. in which you want to add course: " << endl;
    cin >> batch;
    cout << "Enter the semester No. in which you want to add course: " << endl;
    cin >> semester;
    cout << "Enter the Course Code of the course you want to enter: " << endl;
    cin >> course_code;
    system(("mkdir "+ batch + "/semester" + semester + "/" + course_code).c_str());
    cout << "Course Added Successfully..." << endl;
}
void Admin::edit_courses() {
    string batch, semester, course_code, new_course_code;
    cout << "Enter the Batch No. in which you want to change the course: " << endl;
    cin >> batch;
    cout << "Enter the Semester No. in which you want to change the course: " << endl;
    cin >> semester;
    cout << "Enter the Course Code of the Course, you want to change: " << endl;
    cin >> course_code;
    cout << "Enter the New Course Code of the Course: " << endl;
    cin >> new_course_code;
    system(("mv "+ batch + "/semester" + semester + "/" + course_code + new_course_code).c_str());
    cout << "Coursed Changed Successfully.." << endl;
}
void Admin::del_courses() {
    string batch, semester, course_code;
    cout << "Enter the batch No. in which you want to delete course: " << endl;
    cin >> batch;
    cout << "Enter the semester No. in which you want to delete course: " << endl;
    cin >> semester;
    cout << "Enter the Course Code of the course you want to delete: " << endl;
    cin >> course_code;
    system(("rm -r "+ batch + "/semester" + semester + "/" + course_code).c_str());
    cout << "Course Deleted Successfully..." << endl;

}
void Admin::add_section() {
    string batch, semester, section;
    cout << "Enter batch No, in which you want to add section: " << endl;
    cin >> batch;
    cout << "Enter the semester No. in which you want to add section: " << endl;
    cin >> semester;
    cout << "Enter the section you want to add: " << endl;
    cin >> section;
    system(("mkdir "+ batch + "/semester" + semester +  "/sec-" + section).c_str());
    cout << "Section Added Successfully..." << endl;
}
void Admin::del_section() {
    string batch, semester, course_code, section;
    cout << "Enter batch No, in which you want to delete section: " << endl;
    cin >> batch;
    cout << "Enter the semester No. in which you want to delete section: " << endl;
    cin >> semester;

    cout << "Enter the section you want to delete: " << endl;
    cin >> section;
    system(("rmdir "+ batch + "/semester" + semester + "/sec-" + section).c_str());
    cout << "Section Deleted Successfully..." << endl;
}
void Admin::add_student() {
    string name,father_name,id,username,password;
    char gender;
    int age;
    string batch, semester,section;
    cout << "Enter the batch of student: " << endl;
    cin >> batch;
    cout << "Enter Semester No,: " << endl;
    cin >> semester;
    cout << "Enter the section in which you want to add Student: " << endl;
    cin >> section;
    //    system(("cd "+batch).c_str());
    cin.ignore();
    cout << "Enter the name of the student: " << endl;
    getline(cin,this->name);
    std.name = this->name;
    cout << "Enter your Father name: " << endl;
    getline(cin, this->father_name);
    std.father_name = this->father_name;
    cout << "Enter your Gender: " << endl;
    cin >> gender;
    std.gender = gender;
    cout << "Enter your age: " << endl;
    cin >> age;
    std.age = age;
    cout << "Enter Username: " << endl;
    cin >> username;
    std.username = username;
    std.id = std.username;
    cout << "Enter Password: " << endl;
    cin >> password;
    std.password = password;
    system(("mkdir "+ batch + "/semester"+ semester  + "/sec-" + section + "/" + std.id).c_str());
    //creatind csv file of student bio....
    fstream fout;
    string file = batch + "/semester"+ semester + "/" + "/sec-" + section + "/" +  std.id + "/bio.csv";
    cout << file << endl;
    fout.open(file, ios::out);
    fout << std.name << "," <<  std.father_name << "," << std.gender << "," << std.age << "," << std.id << "," << std.username << "," << std.password << "\n";
    fout.close();
    string course;
    fstream fin;
    string file2 = batch + "/semester" + semester + "/semester" + semester + ".csv";
    fin.open(file2, ios::in);
    fstream f;
    while(!fin.eof()) {
        getline(fin, course, ',');
        string a = batch + "/semester"+ semester  + "/sec-" + section + "/" + std.id + "/" + course;
        system(("mkdir "+ a).c_str());
        f.open(a + "/" + course + "-" + "Attendance.csv", ios::out);
        f.close();
        f.open(a + "/" + course + "-" + "Grades.csv", ios::out);
        f.close();
        getline(fin, course, ',');
        getline(fin, course, '\n');
    }
    system(("rm " + batch + "/semester"+ semester  + "/sec-" + section + "/" + std.id + "/-" + "Grades.csv").c_str());
    system(("rm " + batch + "/semester"+ semester  + "/sec-" + section + "/" + std.id + "/-" + "Attendance.csv").c_str());
    fstream f2;
    f2.open("Students_info.csv", ios::app);
    f2 << batch <<  "," <<semester << "," <<section << "," << username << "," << password << "\n";
    f2.close();
    cout << "Student created successfully.. " << endl;
}
void Admin::del_student() {
    string batch, semester,section,id;
    cout << "Enter the batch of student: " << endl;
    cin >> batch;
    cout << "Enter Semester No,: " << endl;
    cin >> semester;
    cout << "Enter the section in which you want to Delete Student: " << endl;
    cin >> section;
    cout << "Enter the ID of the student you want to delete: " << endl;
    cin >> id;
    system(("rm -r "+ batch + "/semester"+ semester +  "/sec-" + section + "/" + id).c_str());
    cout << "Student of ID:" << id << " id Deleted Successfully..." << endl;
}
void Admin::add_faculty() {
    string name,id,username,password;
    char gender;
    int age;
    string faculty = "faculty"; // for folder creation...
    //    system(("cd "+batch).c_str());
    cin.ignore();
    cout << "Enter Name: " << endl;
    getline(cin, this->name);
    fac.name = this->name;
    cout << "Enter your Gender: " << endl;
    cin >> gender;
    fac.gender = gender;
    cout << "Enter your age: " << endl;
    cin >> age;
    fac.age = age;
    cout << "Generate ID: " << endl;
    cin >> id;
    fac.id = id;
    cout << "Enter Username: " << endl;
    cin >> username;
    fac.username = username;
    cout << "Enter Password: " << endl;
    cin >> password;
    fac.password = password;
    system(("mkdir "+ faculty).c_str());
    //creatind csv file of student bio....
    fstream fout;
    string file = faculty + "/" + fac.id +".csv";
    cout << file << endl;
    fout.open(file, ios::out);
    fout << fac.name << "," << fac.gender << "," << fac.age << "," << fac.id << "," << fac.username << "," << fac.password << "\n";
    fout.close();
    cout << "Faculty member created successfully.. " << endl;
}
void Admin::del_faculty() {
    string faculty = "faculty"; // for folder
    string id;
    cout << "Enter the ID of Faculty Member you want to delet: " << endl;
    cin >> id;
    system(("rm -r "+ faculty + "/" + id + ".csv").c_str());
    cout << "Faculty, ID: " << id << " Deleted Successfully..." << endl;
}
void Admin::Assign_courses() {
    string a = "";
    string course_code, batch;
    string semester, check;
    cout << "Enter the Faculty ID here: ";
    cin >> fac.id;
    cout << "Enter the Batch No: " << endl;
    cin >> batch;
    cout << "Enter the Semester No: " << endl;
    cin >> semester;
    cout << "Enter the Course Code of the Course you want to Assign: " << endl;
    cin >> course_code;
    check = batch + "/" + "semester" + semester + "/" + "semester" + semester + ".csv";
    fstream ck(check, ios::in);
    bool c = false;
    while (!ck.eof())
    {
        getline(ck, a, ',');
        if (a == course_code)
        {
            c = true;
            break;
        }
        getline(ck, a, ',');
        getline(ck, a, '\n');
        cout << a << endl;
    }
    if (c == false)
    {
        cout << "You Entered an invalid Entry.\nPlease Try Again...\n";
        return;
    }
    string file = "faculty/" + fac.id + ".csv";
    fstream fin(file, ios::in);
    a = "";
    if (fin.is_open())
    {
        getline(fin, a, '\n');
        fstream fout(file, ios::app);
        if (fout.is_open())
        {
            fout << course_code << '\n';
            fout.close();
        }
        fin.close();
    }
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
    cout << "1. Add Semester\n2. Edit Semester\n3. Delete Semester\n4. Add Batch\n5. Edit Batch\n6. Delete Batch\n7. Add Courses\n8. Edit Courses\n9. Delete Courses\n10. Add Faculty\n11. Edit Faculty\n12. Delete Faculty\n13. Add Student\n14. Edit Student\n15. Delete Student\n16. View Registration\n17. View Attendence\n18. View Transcript\n19. View Marks Distribution\n20.Add Section\n21. Delete Section\n22. Assign Courses\n23. Previous Menu" << endl;
    int select = 0;
    cout << "Enter: " << endl;
    cin >> select;
    switch (select) {
        case 1:
            add_semester();
            admin_panel();
            break;
        case 2:
            edit_semester();
            admin_panel();
            break;
        case 3:
            del_semester();
            admin_panel();
            break;
        case 4:
            add_batch();
            admin_panel();
            break;
        case 5:
            edit_batch();
            admin_panel();
            break;
        case 6:
            del_batch();
            admin_panel();
            break;
        case 7:
            add_courses();
            admin_panel();
            break;
        case 8:
            edit_courses();
            admin_panel();
            break;
        case 9:
            del_courses();
            admin_panel();
            break;
        case 10:
            add_faculty();
            admin_panel();
            break;
            //        case 11:
            //            edit_faculty();
            //            break;
        case 12:
            del_faculty();
            admin_panel();
            break;
        case 13:
            add_student();
            admin_panel();
            break;
            //        case 14:
            //            edit_student();
            //            break;
        case 15:
            del_student();
            admin_panel();
            break;
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
        case 20:
            add_section();
            admin_panel();
            break;
        case 21:
            del_section();
            admin_panel();
            break;
        case 22:
            Assign_courses();
            admin_panel();
            break;
        default:
            cout << "Enter number from 1-20" << endl;

    }
}

// admin ends here....

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
    }
    else if (select == 3) {
        Student S1;
        S1.log_in();
    }
}

int main() {
    Interface I1;
    I1.main_screen();



    return 0;
}

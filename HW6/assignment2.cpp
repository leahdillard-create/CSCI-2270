//Leah Dillard
//CSCI 1300
//Final Project: Classes Catalog

#include <iostream>
#include <map>
#include <string>
using namespace std;

//declare all functions
void printStudent(struct Student *student); //printing student info
void printCourse(struct Course *course); //printing course info
void enroll(string decision,Student *student, Course cour[]); //allows enrollment + options
void classDatabase(); //prints classes and prereq
void userDatabase(); //prints userIDs and passwords

struct Student{ //structure for student data members
    string name;
    string studentID;
    string password;
    int completedCourse;
    double grade;
};

struct Course{ //structure for course data members
    int courseCode;
    string title;
    string instructor;
    int prereq;
    double gradeCriteria;
};

void printMenu(){ // print out login menu and options
    cout << endl;
    cout << "---------------------------------------------------------------------------------------------------------" << endl;
    cout << "                               Are you a registrar or a student?                                     " << endl;
    cout << "        Press '1' for student. Press '2' for registrar. Enter any other key to quit the program.         " << endl;
    cout << "---------------------------------------------------------------------------------------------------------" << endl;
    cout << "Enter Here: ";
}

int main(){
    
    //structure array of 20 courses with all information
    struct Course cour[20]={{100, "Beginning Arabic", "Mona Attwa", -1}, 
    {110, "Intermediate Arabic", "Randa Mohammad", 100, 73}, 
    {120, "Advanced Arabic", "Mona Attwa", 110, 85}, 
    {200, "Beginning Hindi", "Vipul Amitabh", -1}, 
    {210, "Intermediate Hindi", "Puja Manoj", 200, 75}, 
    {220, "Advanced Hindi", "Vipul Amitabh", 210, 88}, 
    {300, "Beginning French", "Jean-François Salomon", -1}, 
    {310, "Intermediate French", "Nicolette Arsène", 300, 70}, 
    {320, "Advanced French", "Nicolette Arsène", 310, 84}, 
    {400, "PreCalculus", "Kevin Candice", -1}, 
    {405, "Calculus I", "Rebekka Shyam", 400, 80}, 
    {410, "Black Holes", "Hedvig Ingo", 405, 75}, 
    {420, "Writing for All Majors", "Danielius Fenna", -1},
    {500, "Introductory Geology", "Monica Mael", 400, 70}, 
    {510, "The Solar System", "Bendegúz Hyacinth", 500, 83}, 
    {520, "Computing", "Yakov Koba", 405, 78}, 
    {600, "International Law", "Sandra Naoise", 420, 90}, 
    {610, "Cybersecurity", "Stefans Francesca Pia", 520, 92}, 
    {620, "Sociology", "Natalina Donka", 420, 79.3}, 
    {700, "Exploratory Studies", "Carlyle Holly", -1}};
    
    //all student information that will be passed through main following login
    struct Student stu1 = {"Lucy Molin", "lumo3453", "36smile", 100, 50};
    struct Student stu2 = {"Marissa Emonil", "maem7654", "iloveCSCI", 110, 90};
    struct Student stu3 = {"Eric Powers", "erpo0987", "CUrocks", -1, 86};
    struct Student stu4 = {"Leah Dillard", "ledi3576", "chicago14", 200, 85};
    struct Student stu5 = {"Nate Palmer", "napa3579", "engine95", 210, 92};
    struct Student stu6 = {"Hailee Tyson", "haty3290", "86rule", 300, 71};
    struct Student stu7 = {"Foster Chloe", "foch1027", "59what", 310, 84.5};
    struct Student stu8 = {"Kuba Viola", "kuvi3268", "mine31", 400, 91};
    struct Student stu9 = {"Lynna Tarquinius", "lyta3384", "72while", 405, 79};
    struct Student stu10 = {"Mauritius Halkyone", "maha2374", "red6", 420, 89};
    struct Student stu11 = {"Hector Martinez", "hema2583", "green88", 520, 92};
    
    //all class information that will also be passed
    struct Course c1 = {100, "Beginning Arabic", "Mona Attwa", -1}; 
    struct Course c2 = {110, "Intermediate Arabic", "Randa Mohammad", 100, 73};
    struct Course c3 = {120, "Advanced Arabic", "Mona Attwa", 110, 85};
    struct Course c4 = {200, "Beginning Hindi", "Vipul Amitabh", -1};
    struct Course c5 = {210, "Intermediate Hindi", "Puja Manoj", 200, 75}; 
    struct Course c6 = {220, "Advanced Hindi", "Vipul Amitabh", 210, 88};
    struct Course c7 = {300, "Beginning French", "Jean-François Salomon", -1};
    struct Course c8 = {310, "Intermediate French", "Nicolette Arsène", 300, 70};
    struct Course c9 = {320, "Advanced French", "Nicolette Arsène", 310, 84};
    struct Course c10 = {400, "PreCalculus", "Kevin Candice", -1};
    struct Course c11 = {405, "Calculus I", "Rebekka Shyam", 400, 80};
    struct Course c12 = {410, "Black Holes", "Hedvig Ingo", 405, 75};
    struct Course c13 = {420, "Writing for All Majors", "Danielius Fenna", -1};
    struct Course c14 = {500, "Introductory Geology", "Monica Mael", 400, 70};
    struct Course c15 = {510, "The Solar System", "Bendegúz Hyacinth", 500, 83};
    struct Course c16 = {520, "Computing", "Yakov Koba", 405, 78};
    struct Course c17 = {600, "International Law", "Sandra Naoise", 420, 90};
    struct Course c18 = {610, "Cybersecurity", "Stefans Francesca Pia", 520, 92};
    struct Course c19 = {620, "Sociology", "Natalina Donka", 420, 79.3};
    struct Course c20 = {700, "Exploratory Studies", "Carlyle Holly", -1};
    
    int choice; // choice variable
    bool quit = false; //create bool for running loop set to false
    cout << endl;
    cout << endl;
    cout << "*********************************************************************************************************" << endl;
	cout << "======================WELCOME TO THE BOULDER SCHOOL OF ARTS AND SCIENCE LOGIN PORTAL=====================" << endl;
	cout << "*********************************************************************************************************" << endl;
	cout << endl;
	
	
    while(!quit){ //while the loop is not quit...
    
        printMenu(); //print menu for user on a loop
        string studentID, password, credentials, decision;
    
        cin >> choice; //user inputs their choice
        
        switch(choice){ //switch statement based on choice
        
            case 1: //student login options
                cout << endl;
                cout << "*********************************************************************************************************" << endl;
                cout << "----------------------------------------------STUDENT LOGIN----------------------------------------------" << endl;
                cout << "*********************************************************************************************************" << endl;
                cout << endl;
                cout <<"                                 You must enter your student ID and password.                             " << endl;
                cout <<"If you have forgotten your ID or password, enter 'forgot' in place of your forgotten password or studentID." << endl;
                cout << "Student ID: ";
                cin >> studentID;
                cout << "Password: ";
                cin >> password;
                
                //if user forgot password, pull up all usernames and passwords if they enter a key
                if(studentID=="forgot"||password=="forgot"||studentID=="forgot"&&password=="forgot"){
                    cout << "Enter the master key to access all usernames and passwords: ";
                    string key;
                    cin >> key;
                    if(key=="Key"||key=="KEY"||key=="key"){
                        userDatabase();
                        continue;
                    }
                }
                
                //allowing password and username login then printing&prompting
                else if(studentID=="lumo3453"&&password=="36smile"){
                            
                    cout << "------------------------------------------------"<<endl;
                    cout <<endl;
                    cout << "Welcome Lucy!" << endl;
                    printStudent(&stu1);
                    enroll(decision,&stu1,cour);
                }
                else if(studentID=="zoem7654"&&password=="iloveCSCI"){
                    cout << "------------------------------------------------"<<endl;
                    cout <<endl;
                    cout << "Welcome Zoe!" << endl;
                    printStudent(&stu2);
                    enroll(decision,&stu2,cour);
                }
                else if(studentID=="erpo0987"&&password=="CUrocks"){
                    cout << "------------------------------------------------"<<endl;
                    cout <<endl;
                    cout << "Welcome Eric!" << endl;
                    printStudent(&stu3);
                    enroll(decision,&stu3,cour);
                }
                else if(studentID=="ledi3576"&&password=="chicago14"){
                    cout << "------------------------------------------------"<<endl;
                    cout <<endl;
                    cout << "Welcome Leah!" << endl;
                    printStudent(&stu4);
                    enroll(decision,&stu4,cour);
                }
                else if(studentID=="napa3579"&&password=="engine95"){
                    cout << "------------------------------------------------"<<endl;
                    cout <<endl;
                    cout << "Welcome Nate!" << endl;
                    printStudent(&stu5);
                    enroll(decision,&stu5,cour);
                }
                else if(studentID=="haty3290"&&password=="86rule"){
                    cout << "------------------------------------------------"<<endl;
                    cout <<endl;
                    cout << "Welcome Hailee!" << endl;
                    printStudent(&stu6);
                    enroll(decision,&stu6,cour);
                }
                else if(studentID=="foch1027"&&password=="59what"){
                    cout << "------------------------------------------------"<<endl;
                    cout <<endl;
                    cout << "Welcome Foster!" << endl;
                    printStudent(&stu7);
                    enroll(decision,&stu7,cour);
                }
                else if(studentID=="kuvi3268"&&password=="mine31"){
                    cout << "------------------------------------------------"<<endl;
                    cout <<endl;
                    cout << "Welcome Kuba!" << endl;
                    printStudent(&stu8);
                    enroll(decision,&stu8,cour);
                }
                else if(studentID=="lyta3384"&&password=="72while"){
                    cout << "------------------------------------------------"<<endl;
                    cout <<endl;
                    cout << "Welcome Lynna!" << endl;
                    printStudent(&stu9);
                    enroll(decision,&stu9,cour);
                }
                else if(studentID=="maha2374"&&password=="red6"){
                    cout << "------------------------------------------------"<<endl;
                    cout <<endl;
                    cout << "Welcome Mauritius!" << endl;
                    printStudent(&stu10);
                    enroll(decision,&stu10,cour);
                }
                else if(studentID=="hema2583"&&password=="green88"){
                    cout << "------------------------------------------------"<<endl;
                    cout <<endl;
                    cout << "Welcome Hector!" << endl;
                    printStudent(&stu11);
                    enroll(decision,&stu11,cour);
                }
                else{ //user did not enter anything valid, so they must try again
                    cout << endl;
                    cout << "Wrong username or password. Please try again." << endl;
                }
                
                break;
    
            case 2: //registrar login options
                cout << endl;
                cout << "*********************************************************************************************************" << endl;
                cout << "--------------------------------------------REGISTRAR LOGIN----------------------------------------------" << endl;
                cout << "*********************************************************************************************************" << endl;
                cout << endl;
                cout <<"Enter your credentials: ";
                cin >> credentials;
                if(credentials == "CUregistrar101"){
                    string option;
                    cout << endl;
                    cout << "-------------------------" << endl;
                    cout << "Welcome registrar!" << endl;
                    cout << "-------------------------" << endl;
                    cout << endl;
                    cout << "Would you like to view the student database, course database, or both? Enter 'student', 'course', or 'both'." << endl;
                    cout << "Enter here: ";
                    cin >> option;
                    if(option=="student"||option=="Student"){
                        cout << endl;
                        cout << "Would you like to browse specific information for each student, or view the general database? (info/database)" << endl;
                        cout << "Enter here: ";
                        string a;
                        cin >> a;
                        if(a=="info"||a=="INFO"||a=="Info"){
                            printStudent(&stu1);
                            printStudent(&stu2);
                            printStudent(&stu3);
                            printStudent(&stu4);
                            printStudent(&stu5);
                            printStudent(&stu6);
                            printStudent(&stu7);
                            printStudent(&stu8);
                            printStudent(&stu9);
                            printStudent(&stu10);
                            printStudent(&stu11);
                        }
                        else{
                            userDatabase();
                        }
                    }
                    if(option=="course"||option=="Course"){
                        cout << endl;
                        cout <<"Would you like to view specific course details, or browse the general database? (details/database)" << endl;
                        cout << "Enter Here: ";
                        string a;
                        cin >> a;
                        if(a=="details"||a=="DETAILS"||a=="Details"){
                            printCourse(&c1);
                            printCourse(&c2);
                            printCourse(&c3);
                            printCourse(&c4);
                            printCourse(&c5);
                            printCourse(&c6);
                            printCourse(&c7);
                            printCourse(&c8);
                            printCourse(&c9);
                            printCourse(&c10);
                            printCourse(&c11);
                            printCourse(&c12);
                            printCourse(&c13);
                            printCourse(&c14);
                            printCourse(&c15);
                            printCourse(&c16);
                            printCourse(&c17);
                            printCourse(&c18);
                            printCourse(&c19);
                            printCourse(&c20);
                        }
                    }
                    if(option=="both"||option=="Both"){ //print both
                        userDatabase();
                        classDatabase();
                    }
                }
                break;
                
            default: //default set to break if user enters anything but 1 or 2
                quit = true;
        }
    }
    
    return 0;
}

void userDatabase(){ //list all usernames and passwords
    map<string, string> database;
    
    database["lumo3453"] = "36smile";
    database["maem7654"] = "iloveCSCI";
    database["erpo0987"] = "CUrocks";
    database["ledi3576"] = "chicago14";
    database["napa3579"] = "engine95";
    database["haty3290"] = "86rule";
    database["foch1027"] = "59what";
    database["kuvi3268"] = "mine31";
    database["lyta3384"] = "72while";
    database["maha2374"] = "red6";
    database["hema2583"] = "green88";

    cout << "---------------------------------------------------------------------------------------------------------" << endl;
    cout << "Here is a list of all student IDs and corresponding passwords stored in the database: " << endl;
    
    for(auto i:database){
        cout << i.first <<  " : " << i.second << endl;
    }
    cout << "---------------------------------------------------------------------------------------------------------" << endl;
}

void classDatabase(){ //list all classes and prerequisites
    
    map<string, string> database;
    
    database["100 - Beginning Arabic"] = "No prerequisite";
    database["110 - Intermediate Arabic"] = "100 - Beginning Arabic";
    database["120 -Advanced Arabic"] = "110 - Intermediate Arabic";
    database["200 - Beginning Hindi"] = "No prerequisite";
    database["210 - Intermediate Hindi"] = "200 - Beginning Hindi";
    database["220 - Advanced Hindi"] = " 210 - Intermediate Hindi";
    database["300 - Beginning French"] = "No prerequisite";
    database["310 - Intermediate French"] = "300 - Beginning French";
    database["320 - Advanced French"] = "310 - Intermediate French";
    database["400 - PreCalculus"] = "No prerequisite";
    database["405 - Calculus I"] = "400 - PreCalculus 400";
    database["410 - Black Holes"] = "405 - Calculus I 405";
    database["420 - Writing for All Majors"] = "No prerequisite";
    database["500 - Introductory Geology"] = "400 - PreCalculus";
    database["510 - The Solar System"] = "500 - Introductory Geology";
    database["520 - Computing"] = "405 - Calculus I";
    database["600 - International Law"] = "420 - Writing for All Majors";
    database["610 - Cybersecurity"] = "520 - Computing";
    database["620 - Sociology"] = "420 - Writing for All Majors";
    database["700 - Exploratory Studies"] = "No prerequisite";
    
    cout << "---------------------------------------------------------------------------------------------------------" << endl;
    cout << "Here is a list of all course codes, classes, and their prerequisites as stored in the database: " << endl;
    
    for(auto i:database){ 
        cout << i.first <<  " : " << i.second << endl;
    }
    
    cout << "---------------------------------------------------------------------------------------------------------" << endl;
    
}

void printStudent(struct Student *student){//student pointer to access particular student
    cout << "************************************************" << endl;
    cout << "Student name: " << student->name << endl;
    cout << "Student ID: " << student-> studentID << endl;
    cout << "Password: " << student-> password << endl;
    cout << "Completed course codes: " << student-> completedCourse << endl;
    cout << "Grade: " << student->grade << endl;
    cout << "************************************************" << endl;
}
void printCourse(struct Course *course){ //takes in course pointer to access particular course
    cout << "************************************************" << endl;
    cout << "Course code: " << course->courseCode << endl;
    cout << "Course title: " << course-> title << endl;
    cout << "Instructor: " << course-> instructor << endl;
    cout << "Prerequisite: " << course-> prereq << endl;
    cout << "************************************************" << endl;
}

void enroll(string decision,Student *student, Course cour[]){ //take in input, student struct w pointer and course array
    
    bool stop = false; //declare boolean variable to false
                    
    while(!stop){ //while the loop is not broken...
    
        cout << endl;
        cout << "Would you like to enroll in a course? (yes/no): ";
        cin >> decision;
        
        if(decision == "yes"||decision == "Yes"||decision == "YES"){ //if yes...
        
            //prompt for course code, and if user does not know it display list
            string option; 
            cout << "Do you know the course code for the class you want to enroll in? (yes/no): ";
            cin >> option;
            
            if(option=="yes"||option=="Yes"||option=="YES"){ //if yes...
                
                //allow input for course code
                int input;
                cout << "Enter the course code : ";
                cin >> input;
                
                for(int i=0; i<20;i++){ //array thru all classes (20)
                    
                    if(input==cour[i].courseCode){ //if input is equal to code at index
                    
                        if(student->completedCourse==cour[i].prereq){ //if the particular students completed course is equal to a prereq at that index
                            if(student->grade>=cour[i].gradeCriteria){ //if the particular students grade is greater than or equal to the grade criteria at index
                                //allow enrollment
                                cout << endl;
                                cout << "******************************************" << endl;
                                cout<< "You are enrolled in " << cour[i].title << " " << endl;
                                cout << "Your instructor is " << cour[i].instructor << " " << endl;
                                cout << "******************************************" << endl;
                                cout << endl;
                            }
                            else{ //otherwise do not allow enrollment due to GPA
                                cout << "................................................" << endl;
                                cout << "You can not be enrolled due to insufficient GPA." << endl;
                                cout << "................................................" << endl;
                            }
                        }
                        
                        else if(cour[i].prereq==-1){ //if course has no prerequisites...
                        
                            cout << endl; //allow enrollment regardless
                            cout << "******************************************" << endl;
                            cout<< "You are enrolled in " << cour[i].title << " " << endl;
                            cout << "Your instructor is " << cour[i].instructor << " " << endl;
                            cout << "******************************************" << endl;
                            cout << endl;
                            break;
                        }
                        else{ //otherwise...if completed course is not equal to index prereq...
                            cout << endl;
                            cout << "..................................................................................." << endl;
                            cout << "You can not be enrolled in " << cour[i].title << " due to lack of prerequisites." << endl;
                            cout << "..................................................................................." << endl;
                            cout << endl;
                        }
                    }   
                }
            }
            else{
                classDatabase(); //otherwise.. print out list of classes and the
            }
        }
        else if(decision == "no"||decision == "No"||decision == "NO"){ //if user enters no break loop
            cout << endl;
            cout << "LOGGING OUT...." << endl;
            cout << endl;
            stop = true;
        }
    }
}
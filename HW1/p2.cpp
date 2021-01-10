#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
using namespace std;


struct studentData{
    string studentName;
    int homework;
    int recitation;
    int quiz;
    int exam;
    double average;
};

void addStudentData(studentData students[], string studentName, 
int homework, int recitation, int quiz, int exam, int length){
    studentData stu;
    stu.studentName = studentName;
    stu.homework = homework;
    stu.recitation = recitation;
    stu.quiz = quiz;
    stu.exam = exam;
    stu.average = double(homework+recitation+quiz+exam)/4;
    students[length] = stu; //add struct to students array
    length++;
}

char calcLetter(double avg){

    if(avg >= 90){
        return 'A';
    }
    else if(avg <= 89.9 && avg >= 80){
        return 'B';
    }
    else if(avg <= 79.9 && avg >= 70){
        return 'C';
    }
    else if(avg <= 69.9 && avg >= 60){
        return 'D';
    }
    else if(avg <60){
        return 'F';
    }
}

void printList(const studentData students[], int length){
    for(int i = 0; i < length; i++){
        cout << students[i].studentName << " earned " << students[i].average << " which is an " << calcLetter(students[i].average) << endl; 
    }
}

int main(int argc, char *argv[]){

    studentData student[10];
    char min = argv[3][0];
    char max = argv[4][0];

    if(argc != 5){
        cout << "Enter <input .csv file> <output .csv file> <lower bound letter grade> <upper bound letter grade>" <<endl;
        return -1;
    }

    else if(argc <= 5){

        ifstream inputFile;
        inputFile.open(argv[1]);

        if(!inputFile.is_open()){
            cout << "File could not be opened." << endl;
            return -1;
        }

        else{
            string line, studentName, placeholder;
            int homework, recitation, quiz, exam;
            int index = 0;

            while (getline(inputFile, line)){
                stringstream s(line);

                getline(s, studentName, ',');            

                getline(s, placeholder, ',');
                stringstream homeworkInFile;
                homeworkInFile << placeholder;
                homeworkInFile >> homework;

                getline(s, placeholder, ',');
                stringstream recitationInFile;
                recitationInFile << placeholder;
                recitationInFile >> recitation;

                getline(s, placeholder, ',');
                stringstream quizInFile;
                quizInFile << placeholder;
                quizInFile >> quiz;

                getline(s, placeholder, ',');
                stringstream examInFile;
                examInFile << placeholder;
                examInFile >> exam; 

                addStudentData(student, studentName, homework, recitation, quiz, exam, index);

                index++;
            }

            inputFile.close();
            printList(student, index);

            ofstream outFile;
            outFile.open(argv[2]);

            for(int i = 0; i < index; i++){
                char letterGrade;
                letterGrade = calcLetter(student[i].average);
        
                if(letterGrade >= 'B'){
                    outFile << student[i].studentName << "," << student[i].average << "," << calcLetter(student[i].average) << endl;
                }
            }
            outFile.close();
        }
        
    }
     return 0;
}


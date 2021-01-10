/****************************************************************/
/*                Job Queue Driver File                 */
/****************************************************************/
/* TODO: Implement menu options as described in the writeup     */
/****************************************************************/

#include "JobQueue.hpp"
#include <iostream>
#include "string"
// you may include more libraries as needed

using namespace std;

/*
 * Purpose: displays a menu with options
 * @param none
 * @return none
 */
void menu()
{
	cout << "*----------------------------------------*" << endl;
	cout << "Choose an option:" << endl;
    cout << "1. Add jobs into the queue" << endl;
	cout << "2. Dispatch jobs from the queue" << endl;
	cout << "3. Return the queue size and exit" << endl;
	cout << "*----------------------------------------*" << endl;
}
// Use getline for reading
int main(int argc, char const *argv[])
{
    JobQueue job;
    string str, input;
    int count=1;
    
    do{
        menu();
        getline(cin, str);
        switch(str[0]){
            case '1': 
            {
                cout << "Enter the number of jobs to be created:" << endl;
                getline(cin, input);
                int number = stoi(input);
                
                for(int i = 1; i <= number; i++){
                    cout << "job" << i << ":" << endl;
                    getline(cin,input);
                    job.enqueue(input);
                }
                break;
            }
            case '2':{
                cout<< "Enter the number of jobs to be dispatched:" << endl;
                getline(cin, input);
                int number = stoi(input);

                for(int i = 1; i <= number; i++){
                    if(job.isEmpty()){
                        cout << "No more jobs to be dispatched from queue" << endl;
                        break;
                    }
                    cout << "Dispatched: " << job.peek() << endl;
                    job.dequeue();
                }
                break;
            }
            case '3':
            {
                int s = job.queueSize();
                cout << "Number of jobs in the queue:" << s << endl;
                break;
            }
            default:
            {

            }
        }
    }while(str[0]!='3');

    return 0;
}

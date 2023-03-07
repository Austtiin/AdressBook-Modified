/*

Author: Austin Stephens

Date: 04/13/2022

FileName: modifiedAdressBook.cpp

Purpous: Module 02 Assignemnt, Prebuilt Classes

Input: Menu Selection Based on Input

Output: Either menu item or concepts of entering in adress information
Exceptiuons: 
 
    
    Rules:

Create a new program by modifying the address book program you created in the previous module. 
Modify the program to use the Array Class instead of a basic array. 
Create another new program by modifying the address book program created in the previous module to use the Vector Class instead of a basic array. 
Implement exception catching in appropriate areas that may cause errors. 
You should implement exception catching in at least one area of the program for each of the Array class and Vector class programs you create. 
You will need to submit the code for two finished independent programs (Array and Vector).


*/


//Including librarys
#include <iostream>
#include <array>
#include <string>
#include <cstdlib>


using namespace std;


//defining class

class Record
{
private:
    char *FirstName,*LastName;
    long *PhoneNumber;
    int *Age, *RecordNumber;
public:
    Record()
    {
        FirstName = new char[20];
        LastName = new char[20];
        PhoneNumber = new long;
        Age = new int;
        RecordNumber = new int;
    }   

        void datafeed();
        void ShowRecords();
};

void printLines()
{
    cout << "-------------------------" << endl;
}


    //fucntions
void Record::datafeed()
{
    cin.ignore();
    cout << "Enter First Name: " << endl;
    cin.getline(FirstName, 20);
    cout << "Enter Last Name; " << endl;
    cin.getline(LastName, 20);
    cout << "Enter Age: " << endl;
    cin >> *Age;
    cout << "Enter Phone Number: " << endl;
    cin >> *PhoneNumber;
    cout << "Enter Record Number: " << endl;
    cin >> *RecordNumber;
}



void Record::ShowRecords()
{
        printLines();
        cout << "   First Name: " << FirstName<< endl;
        cout << "    Last Name: " << LastName << endl;
        cout << "          Age: " << *Age << endl;
        cout << " Phone Number: " << *PhoneNumber << endl;
        cout << "Record-Number: " << *RecordNumber << endl;
        printLines();
}


//main
int main()
{
    Record *B[20];
    int Choice, i=0, j;
    array<string , 1> line;
    line[1] = {"-------------------------"};
    
    
    while (1)
    {
        printLines();
        cout << "1. Input information into an record" << endl;
        cout << "2. Display all information in all records" << endl;
        cout << "3. Exit the program" << endl;
        printLines();
        cin >> Choice;


        switch (Choice)
        {
            //new record creation
        case 1:
            B[i] = new Record;
            B[i]-> datafeed();
            i++;
            break;

        case 2:
            //loop to repeat functions, wont show if no records have been created
            cin.ignore();
            for (int j = 0; j < i; j++)
            {
                B[j]->ShowRecords();
            }
            break;

            
            
            //exit
        case 3:
            exit(0);
        default:

        //exception handling **ADDED
            try
            {
                if (Choice != '1' || '2' || '3')
                {
                    throw 99;
                }
                
            }
            catch(int x)
            {
                cout << "\n Invalid Choice Entered: ERROR: " << x << endl;
                cout << line[1] << endl;
            }
            
        }
    }
    

    return 0;

}
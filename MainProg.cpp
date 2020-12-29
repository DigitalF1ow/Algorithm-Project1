#include <iostream>
#include <string>
#include <cstdlib>
#include <fstream>
#include <ctime>
#include <chrono>

#include "HashTable.cpp"

using namespace std;

void chainingMethod()
{
    int choiceDataSet;
    ifstream datasetEntryFile;
    
    cout << "Which of the following datasets you would like to use?" << endl;
    printf("1. Dataset A\n2. Dataset B\n3. Dataset C\n");

    cin >> choiceDataSet;

    if (choiceDataSet == 1)
    {
        auto start = std::chrono::high_resolution_clock::now();
        string tempString;
        HashTable<string> ht(90);
        datasetEntryFile.open("EmailsetA.txt");
        while(!datasetEntryFile.eof()) // Getting all the lines from the file
        {
            getline(datasetEntryFile, tempString); //saves the line in temporary
            //cout << tempString << endl;
            ht.insert(tempString);
        }
        datasetEntryFile.close();
        cout << ht << endl;

        auto end = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::seconds>(end - start);
        cout << "Duration of insertion of email dataset A using chaining Method: " << duration.count() << " seconds" << endl;
    }
    else if (choiceDataSet == 2)
    {
        auto start = std::chrono::high_resolution_clock::now();
        string tempString;
        HashTable<string> ht(90000);
        datasetEntryFile.open("EmailsetB.txt");
        while(!datasetEntryFile.eof()) // Getting all the lines from the file
        {
            getline(datasetEntryFile, tempString); //saves the line in temporary
            //cout << tempString << endl;
            ht.insert(tempString);
        }
        datasetEntryFile.close();
        cout << ht << endl;

        auto end = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::seconds>(end - start);
        cout << "Duration of insertion of email dataset B using chaining Method: " << duration.count() << " seconds" << endl;
    }
    else if (choiceDataSet == 3)
    {
        auto start = std::chrono::high_resolution_clock::now();
        string tempString;
        HashTable<string> ht(450000);
        datasetEntryFile.open("EmailsetC.txt");
        while(!datasetEntryFile.eof()) // Getting all the lines from the file
        {
            getline(datasetEntryFile, tempString); //saves the line in temporary
            //cout << tempString << endl;
            ht.insert(tempString);
        }
        datasetEntryFile.close();
        cout << ht << endl;

        auto end = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::seconds>(end - start);
        cout << "Duration of insertion of email dataset C using chaining Method: " << duration.count() << " seconds" << endl;
    }
    else
    {
        cout << "Error - That is an invalid choice!" << endl;
    }

    int target;
    cout << "target to retrieve: " << endl;
    cin >> target;



    if (ht.resize(target))
    {
        cout << "Target has been found!" << endl;
    }
    else
    {
        cout << "Target has been not been found!" << endl;
        /* code */
    }    

}

int main()
{
    int choice;
    cout << "Welcome to the program. Which type of algorithm do you want to set on?" << endl;
    printf("1. Chaining Method\n2. Linear Probing\n3. AVL Binary Search Tree\n4. Priority Queue using Heap\n");

    cin >> choice;

    if (choice == 1)
    {
        chainingMethod();
    }
    else if (choice == 2)
    {

    }
    else if (choice == 3)
    {

    }
    else if (choice == 4)
    {

    }
}


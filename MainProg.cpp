#include <iostream>
#include <string>
#include <cstdlib>
#include <fstream>
#include <ctime>
#include <chrono>
#include <string>
#include "HashTable.cpp"
#include "LinearProbing.cpp"

using namespace std;

void chainingMethod()
{
    int choiceDataSet;
    ifstream datasetEntryFile;

    int choiceSelection;
    cout << "What type of choice would you like to do?" << endl;
    printf("1. Insertion\n2. Search\n Choice: ");
    
    cin >> choiceSelection;

    if (choiceSelection == 1)
    {
        cout << "Which of the following datasets you would like to use?" << endl;
        printf("1. Dataset A\n2. Dataset B\n3. Dataset C\nChoice: ");

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

            string target;
            cout << "target to retrieve: " << endl;
            cin >> target;

            if (ht.retrieve(target))
            {
                cout << "Target has been found!" << endl;
            }
            else
            {
                cout << "Target has been not been found!" << endl;
            }
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

            string target;
            cout << "target to retrieve: " << endl;
            cin >> target;

            if (ht.retrieve(target))
            {
                cout << "Target has been found!" << endl;
            }
            else
            {
                cout << "Target has been not been found!" << endl;
            }
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
            //cout << ht << endl;

            auto end = std::chrono::high_resolution_clock::now();
            auto duration = std::chrono::duration_cast<std::chrono::seconds>(end - start);
            cout << "Duration of insertion of email dataset C using chaining Method: " << duration.count() << " seconds" << endl;

            string target;
            cout << "target to retrieve: " << endl;
            cin >> target;

            if (ht.retrieve(target))
            {
                cout << "Target has been found!" << endl;
            }
            else
            {
                cout << "Target has been not been found!" << endl;
            }
        }
        else
        {
            cout << "Error - That is an invalid choice!" << endl;
        }
    }
    else if(choiceSelection == 2) 
    {

    }   
}

void linearProbing()
{
    int choiceDataSet;
    ifstream datasetEntryFile;
    string tempString;

    //HashMap<int,string> *linarHashTable;

    cout << "Which of the following data sets do you want to use?" << endl;
    printf("1. Dataset A\n2. Dataset B\n3. Dataset C\n");

    cin >> choiceDataSet;

    if (choiceDataSet == 1)
    {
        auto start = std::chrono::high_resolution_clock::now();
        string tempString;
        HashMap<int, string> *linearHashTable = new HashMap<int, string>(150);
        //50% more than the dataset used
        
        datasetEntryFile.open("EmailSetA.txt");
        while (!datasetEntryFile.eof())
        {
            getline(datasetEntryFile, tempString);
            int asciiNum = 0;
            int index = 0;

            for (int i = 0; i < tempString.length(); i++)
            {
                asciiNum += tempString[i]; 
            }

            linearHashTable->insert(asciiNum, tempString);

            tempString = "";
        }
        auto end = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::seconds>(end - start);

        linearHashTable->displayHashMap();
        cout << "Duration of insertion of email dataset A using Linear Probing Method: " << duration.count() << " seconds" << endl;
        string searchKey;

        cout << "Which value do you want to search for?" << endl;
        cin >> searchKey;

        int asciiNum = 0;

        for (int i = 0; i < searchKey.length(); i++)
        {
            asciiNum += searchKey[i]; 
        }
        
        cout << "Target Found at:" << linearHashTable->get(asciiNum) << endl;
        
    }
    else if (choiceDataSet == 2)
    {
        auto start = std::chrono::high_resolution_clock::now();
        string tempString;
        HashMap<int, string> *linearHashTable = new HashMap<int, string>(150000);
        //50% more than the dataset used
        
        datasetEntryFile.open("EmailSetB.txt");
        while (!datasetEntryFile.eof())
        {
            getline(datasetEntryFile, tempString);
            int asciiNum = 0;
            int index = 0;

            for (int i = 0; i < tempString.length(); i++)
            {
                asciiNum += tempString[i]; 
            }

            linearHashTable->insert(asciiNum, tempString);

            tempString = "";
        }
        auto end = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::seconds>(end - start);

        linearHashTable->displayHashMap();
        cout << "Duration of insertion of email dataset B using Linear Probing Method: " << duration.count() << " seconds" << endl;
    }
    else if (choiceDataSet == 3)
    {
        auto start = std::chrono::high_resolution_clock::now();
        string tempString;
        HashMap<int, string> *linearHashTable = new HashMap<int, string>(750000);
        //50% more than the dataset used
        
        datasetEntryFile.open("EmailSetC.txt");
        while (!datasetEntryFile.eof())
        {
            getline(datasetEntryFile, tempString);
            int asciiNum = 0;
            int index = 0;

            for (int i = 0; i < tempString.length(); i++)
            {
                asciiNum += tempString[i]; 
            }

            linearHashTable->insert(asciiNum, tempString);

            tempString = "";
        }
        auto end = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::seconds>(end - start);

        linearHashTable->displayHashMap();
        cout << "Duration of insertion of email dataset C using Linear Probing Method: " << duration.count() << " seconds" << endl;
    }
    else
    {
        printf("Error - irrelevant choice of data set\n");
    }
}

void avlTree()
{
    int choiceDataSet;
    ifstream datasetEntryFile;
}

void priorityQueue()
{

}

int main()
{
    int choice;
    while(1)
    {
        cout << "Welcome to the program. Which type of algorithm do you want to set on?" << endl;
        printf("1. Chaining Method\n2. Linear Probing\n3. AVL Binary Search Tree\n4. Priority Queue using Heap\n5. Quit Program\nChoice: ");

        cin >> choice;

        switch (choice)
        {
            case 1:
                chainingMethod();
                break;
            case 2:
                linearProbing();
                break;
            case 3:
                avlTree();
                break;
            case 4:
                priorityQueue();
                break;
            case 5:
                exit(0);
                break;
            default:
                cout << "Please choose the valid option" << endl;
        }
    }
    return 0;
    
}


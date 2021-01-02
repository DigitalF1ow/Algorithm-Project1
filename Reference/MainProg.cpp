#include <iostream>
#include <string>
#include <cstdlib>
#include <fstream>
#include <ctime>
#include <chrono>

#include "HashTable.cpp"
#include "LinearProbing.cpp"

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
        cout << ht << endl;

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
        /*
        auto start = std::chrono::high_resolution_clock::now();
        string tempString;
        HashMap<int, string> *linearHashTable = new HashMap<int, string>(30);
        //50% more than the dataset used
        
        //datasetEntryFile.open("EmailSetA.txt");
        string a[4] = {"Ept3q.uJSz@ParvO.org","GAfdY.JzBp@XCrxA.org","ZBlSN.A87h@RZyZM.org","70HJS.JqxP@kHPxL.com"};

        for(int i  = 0; i < 4; i++)
        {
            int asciiNum = 0;
            int index = 0;

            for (int j = 0; j < a[i].length(); j++)
            {
                asciiNum += a[i][j]; 
            }

            linearHashTable->insert(asciiNum, a[i]);
        }
        linearHashTable->displayHashMap();

        string target;
        while(true)
        {
            cout << "target to retrieve, type 0 to exit searching: " << endl;
            cin >> target;

            int asciiNum = 0;
            int index = 0;

            for (int j = 0; j < target.length(); j++)
            {
                asciiNum += target[j]; 
            }
            
            if(asciiNum == 0)
            {
                break;
            }
            else if (linearHashTable->get(asciiNum))
            {
                cout << "Target has been found at index " << linearHashTable->getIndex(asciiNum) << endl;
            }
            else if (!(linearHashTable->get(asciiNum)))
            {
                cout << "Target has been not been found!" << endl;
            }
        }
        */
        auto start = std::chrono::high_resolution_clock::now();
        string tempString;
        HashMap<int, string> *linearHashTable = new HashMap<int, string>(151);
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
        //cout << "Size of HashMap: " << linearHashTable->getSize() << " indexes" << endl;

        string target;
        while(true)
        {
            cout << "target to retrieve, type 0 to exit searching: " << endl;
            cin >> target;

            int asciiNum = 0;
            int index = 0;

            for (int j = 0; j < target.length(); j++)
            {
                asciiNum += target[j]; 
            }
            
            if(asciiNum == 0)
            {
                break;
            }
            else if (linearHashTable->get(asciiNum))
            {
                cout << "Target has been found at index " << linearHashTable->getIndex(asciiNum) << endl;
            }
            else if (!(linearHashTable->get(asciiNum)))
            {
                cout << "Target has been not been found!" << endl;
            }
        }
        
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

}

void priorityQueue()
{

}

int main()
{
    system("cls");
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
        linearProbing();
    }
    else if (choice == 3)
    {
        //avlTree();
    }
    else if (choice == 4)
    {
        //priorityQueue();
    }
}


#include <iostream>
#include <string>
#include <fstream>
#include <ctime>
#include <chrono>
#include <string>
#include "HashTable.cpp"
#include "LinearProbing.cpp"

using namespace std;

void chainingMethod()
{
    /*
    1. User selects a choice for which dataset tey want to test out
    2. User can choose if they want to select whether will it be a search or a Insertion
    3. If insertion, it will begin to start the time to insert the dataset
    4. If Search, it will get the dataset used, if the dataset is empty, it will reject 
    and ask the user to create the dataset first
    5. Once the dataset is created, you can search for it until you exit from the chaining Method Function
    */

    int choiceDataSet;
    string searchString;
    ifstream datasetEntryFile;

    int choiceSelection;
    cout << "----------------------------------------" << endl;
    printf("\t Chaining Method \t\n");
    cout << "----------------------------------------" << endl;

    cout << "What dataset would you want to choose?" << endl;
    printf("1. Dataset A\n2. Dataset B\n3. Dataset C\nChoice: ");
    
    cin >> choiceSelection;
    while(cin.fail())
    {
        cout << "Please enter a valid number, not a letter/word"<< endl;
        cin.clear();
        cin.ignore();
        printf("Choice:");
        cin >> choiceSelection;
    }
    switch(choiceSelection)
    {
        case 1:
        {
            while(true)
            {
                HashTable<string> ht(90);

                cout << "Which option do you want to do?" << endl;
                printf("1. Insertion - Finding time taken\n2. Search\n3. Exit Chaining Method\nChoice: ");
                cin >> choiceSelection;
                while(cin.fail())
                {
                    cout << "Please enter a valid number" << endl;
                    cin.clear();
                    cin.ignore();
                    printf("Choice:");
                    cin >> choiceSelection;
                    
                }

                if(choiceSelection == 1)
                {
                    auto start = std::chrono::high_resolution_clock::now();
                    string tempString;
                    
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
                else if (choiceSelection == 2 && ht.size() != 0)
                {
                    string target;
                    while(true)
                    {
                        cout << "target to retrieve, type 0 to exit searching: " << endl;
                        cin >> target;
                        if(target == "0")
                        {
                            break;
                        }
                        else if (ht.retrieve(target))
                        {
                            cout << "Target has been found!" << endl;
                        }
                        else if (!(ht.retrieve(target)))
                        {
                            cout << "Target has been not been found!" << endl;
                        }
                    }
                }
                else if (choiceSelection == 3)
                {
                    break;
                }
                
            }
            break;
        }
        case 2:
        {
            while(true)
            {
                HashTable<string> ht(90000);

                cout << "Which option do you want to do?" << endl;
                printf("1. Insertion - Finding time taken\n2. Search\n3. Exit Chaining Method\nChoice: ");
                cin >> choiceSelection;
                while(cin.fail())
                {
                    cout << "Please enter a valid number" << endl;
                    cin.clear();
                    cin.ignore();
                    printf("Choice:");
                    cin >> choiceSelection;
                    
                }

                if(choiceSelection == 1)
                {
                    auto start = std::chrono::high_resolution_clock::now();
                    string tempString;
                    
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
                else if (choiceSelection == 2 && ht.size() != 0)
                {
                    string target;
                    while(true)
                    {
                        cout << "target to retrieve, type 0 to exit searching: " << endl;
                        cin >> target;
                        if(target == "0")
                        {
                            break;
                        }
                        else if (ht.retrieve(target))
                        {
                            cout << "Target has been found!" << endl;
                        }
                        else if (!(ht.retrieve(target)))
                        {
                            cout << "Target has been not been found!" << endl;
                        }
                    }
                }
                else if (choiceSelection == 3)
                {
                    break;
                }
                
            }
            break;
        }
        case 3:
        {
            while(true)
            {
                HashTable<string> ht(450000);

                cout << "Which option do you want to do?" << endl;
                printf("1. Insertion - Finding time taken\n2. Search\n3. Exit Chaining Method\nChoice: ");
                cin >> choiceSelection;
                while(cin.fail())
                {
                    cout << "Please enter a valid number" << endl;
                    cin.clear();
                    cin.ignore();
                    printf("Choice:");
                    cin >> choiceSelection;
                    
                }

                if(choiceSelection == 1)
                {
                    auto start = std::chrono::high_resolution_clock::now();
                    string tempString;
                    
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
                else if (choiceSelection == 2 && ht.size() != 0)
                {
                    string target;
                    while(true)
                    {
                        cout << "target to retrieve, type 0 to exit searching: " << endl;
                        cin >> target;
                        if(target == "0")
                        {
                            break;
                        }
                        else if (ht.retrieve(target))
                        {
                            cout << "Target has been found!" << endl;
                        }
                        else if (!(ht.retrieve(target)))
                        {
                            cout << "Target has been not been found!" << endl;
                        }
                    }
                    
                }
                else if (choiceSelection == 3)
                {
                    break;
                }
                
            }
            break;
        }
        default:
        {
            cout << "Please enter a valid option" << endl;
        }
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
                cout << asciiNum << endl;
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
    
}

void priorityQueue()
{

}

int main()
{
    int choice;

    /*
    HashTable
    */


    while(true)
    {
        system("CLS");
        cout << "Welcome to the program. Which type of algorithm do you want to set on?" << endl;
        printf("1. Chaining Method\n2. Linear Probing\n3. AVL Binary Search Tree\n4. Priority Queue using Heap\n5. Quit Program\nChoice: ");
        cin >> choice;
        while(cin.fail())
        {
            cout << "Invalid Selection, please enter a number to select an option." << endl;
            cin.clear();
            cin.ignore();
            printf("Choice:");
            cin >> choice;
        }
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


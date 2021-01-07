#include <iostream>
#include <string>
#include <fstream>
#include <ctime>
#include <chrono>
#include <string>

//Files linked
#include "HashTable.cpp"
#include "LinearProbing.cpp"

using namespace std;


void chainingMethod()
{
    system("cls");
    /*
    1. User selects a choice for which dataset tey want to test out
    2. User can choose if they want to select whether will it be a search or a Insertion
    3. If insertion, it will begin to start the time to insert the dataset
    4. If Search, it will get the dataset used, if the dataset is empty, it will reject 
    and ask the user to create the dataset first
    5. Once the dataset is created, you can search for it until you exit from the chaining Method Function
    */

    //For storing the time duration history
    vector<float> timeDuration;
    vector<string> datasetSelected;
    vector<string> processSelected;

    HashTable<string> htA(0);
    HashTable<string> htB(0);
    HashTable<string> htC(0);

    

    int choiceDataSet;
    string tempString;
    ifstream datasetEntryFile;

    int choiceSelection;
    while(true)
    {
        cout << "----------------------------------------------" << endl;
        printf("\t Chaining Method \t\n");
        cout << "----------------------------------------------" << endl;

        cout << "Which option do you want to do?" << endl;
        printf("1. Insertion - Finding time taken\n2. Search with Email That Can be Found\n3. Search With Email That Cannot be Found\n4. Time Duration History \n5. Exit Chaining Method\nChoice: ");

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
            case 1: //Insertion Process
            {
                cout << "What email dataset would you want to choose?" << endl;
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

                if (choiceSelection == 1)
                {
                    htA.clear();
                    htA.resize(90);
                    system("cls");
                    cout << "This will take a while, please wait for a moment.\n" << endl;
                    datasetEntryFile.open("EmailsetA.txt");

                    datasetSelected.push_back("Email Dataset A");
                    processSelected.push_back("Total Time Taken Insertion");

                    auto start = std::chrono::high_resolution_clock::now();
                    while(!datasetEntryFile.eof()) // Getting all the lines from the file
                    {
                        getline(datasetEntryFile, tempString); //saves the line in temporary
                        //cout << tempString << endl;
                        htA.insert(tempString);
                    }
                    auto end = std::chrono::high_resolution_clock::now();
                    auto duration = std::chrono::duration_cast<chrono::nanoseconds>(end - start);
                    datasetEntryFile.close();

                    timeDuration.push_back(duration.count() * 1e-9); //To get the duration into the record

                    cout << htA << endl;
                    cout << "Duration of insertion of email dataset A using chaining Method: " << duration.count() * 1e-9 << " seconds" << endl;
                }
                else if (choiceSelection == 2)
                {
                    string tempString;

                    datasetSelected.push_back("Email Dataset B");
                    processSelected.push_back("Total Time Taken Insertion");

                    htB.clear();
                    htB.resize(90000);
                    system("cls");
                    cout << "This will take a while, please wait for a moment.\n" << endl;

                    datasetEntryFile.open("EmailsetB.txt");
                    auto start = std::chrono::high_resolution_clock::now();
                    while(!datasetEntryFile.eof()) // Getting all the lines from the file
                    {
                        getline(datasetEntryFile, tempString); //saves the line in temporary
                        //cout << tempString << endl;
                        htB.insert(tempString);
                    }
                    datasetEntryFile.close();
                    auto end = std::chrono::high_resolution_clock::now();
                    auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);

                    timeDuration.push_back(duration.count() * 1e-9); //To get the duration into the record

                    cout << htB << endl;
                    cout << "Duration of insertion of email dataset B using chaining Method: " << duration.count() * 1e-9 << " seconds" << endl;
                }
                else if (choiceSelection == 3)
                {
                    string tempString;
                    datasetSelected.push_back("Email Dataset C");
                    processSelected.push_back("Total Time Taken Insertion");

                    htC.clear();
                    htC.resize(450000);
                    system("cls");
                    cout << "This will take a while, please wait for a moment.\n" << endl;
                    datasetEntryFile.open("EmailsetC.txt");
                    auto start = std::chrono::high_resolution_clock::now();
                    while(!datasetEntryFile.eof()) // Getting all the lines from the file
                    {
                        getline(datasetEntryFile, tempString); //saves the line in temporary
                        //cout << tempString << endl;
                        htC.insert(tempString);
                    }
                    datasetEntryFile.close();
                    auto end = std::chrono::high_resolution_clock::now();
                    auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);

                    timeDuration.push_back(duration.count() * 1e-9); //To get the duration into the record

                    cout << htC << endl;
                    cout << "Duration of insertion of email dataset C using chaining Method: " << duration.count() * 1e-9 << " seconds" << endl;
                }
                break;
            }
            case 2: //Search With Email Can be Found
            {
                cout << "What email dataset would you want to choose?" << endl;
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
                if(choiceSelection == 1)
                {
                    //datasetSelected.push_back("Email Dataset A");
                    //processSelected.push_back("Total Time Taken Search");

                    datasetEntryFile.open("EmailSetFound.txt");
                    cout << "Searching with a Dataset with items that can be found" << endl;
                    //Beginning Total Search
                    //auto startSearch = std::chrono::high_resolution_clock::now();
                    while(!datasetEntryFile.eof())
                    {
                        auto start = std::chrono::high_resolution_clock::now();
                        getline(datasetEntryFile, tempString); //Getting the line into a tempString
                        if (htA.retrieve(tempString))
                        {
                            auto endSearch = std::chrono::high_resolution_clock::now();
                            auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(endSearch - start);
                            cout << tempString << " can be found in Dataset A - Time taken: " << duration.count() * 1e-9 << " seconds" << endl;
                        }
                        else
                        {
                            auto endSearch = std::chrono::high_resolution_clock::now();
                            auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(endSearch - start);
                            cout << tempString << " cannot be found in Dataset A - Time Taken: "<< duration.count() * 1e-9 << " seconds" << endl;
                        }
                        tempString = ""; //Reset the string
                    }
                    //auto endTotal = std::chrono::high_resolution_clock::now();
                    //auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(endTotal - startSearch);
                    datasetEntryFile.close();
                }
                else if (choiceSelection == 2)
                {
                    datasetEntryFile.open("EmailSetFound.txt");
                    cout << "Searching with a Dataset with items that can be found" << endl;
                    while(!datasetEntryFile.eof())
                    {
                        auto start = std::chrono::high_resolution_clock::now();
                        getline(datasetEntryFile, tempString); //Getting the line into a tempString
                        if (htB.retrieve(tempString))
                        {
                            auto end = std::chrono::high_resolution_clock::now();
                            auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);

                            cout << tempString << " can be found in Dataset B - Time Taken: " << duration.count() * 1e-9 << " seconds" << endl;
                        }
                        else
                        {
                            auto end = std::chrono::high_resolution_clock::now();
                            auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);

                            cout << tempString << " can be found in Dataset B" << duration.count() * 1e-9 << " seconds" << endl;;
                        }
                        tempString = ""; //Reset the string
                    }
                    datasetEntryFile.close();
                }
                else if (choiceSelection == 3)
                {
                    auto start = std::chrono::high_resolution_clock::now();
                    datasetEntryFile.open("EmailSetFound.txt");
                    cout << "Searching with a Dataset with items that can be found" << endl;
                    while(!datasetEntryFile.eof())
                    {
                        getline(datasetEntryFile, tempString); //Getting the line into a tempString
                        if (htC.retrieve(tempString))
                        {
                            auto end = std::chrono::high_resolution_clock::now();
                            auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);
                            cout << tempString << " can be found in Dataset C" << duration.count() * 1e-9 << " seconds" << endl;;
                        }
                        else
                        {
                            auto end = std::chrono::high_resolution_clock::now();
                            auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);
                            cout << tempString << " can not be found in Dataset C" << duration.count() * 1e-9 << " seconds" << endl;;
                        }
                        tempString = ""; //Reset the string
                    }
                    datasetEntryFile.close();
                }
                else
                {
                    cout << "Please select the valid option" << endl;
                }
                break;
            }
            case 3:
            {
                cout << "What email dataset would you want to choose?" << endl;
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
                if(choiceSelection == 1)
                {
                    datasetEntryFile.open("EmailSetNotFound.txt");
                    cout << "Searching with a Dataset with items that cannot be found" << endl;
                    while(!datasetEntryFile.eof())
                    {
                        auto start = std::chrono::high_resolution_clock::now();
                        getline(datasetEntryFile, tempString); //Getting the line into a tempString
                        if (htA.retrieve(tempString))
                        {
                            auto end = std::chrono::high_resolution_clock::now();
                            auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);
                            cout << tempString << " can be found in Dataset A - Time taken: " << duration.count() * 1e-9 << " seconds" << endl;;
                        }
                        else
                        {
                            auto end = std::chrono::high_resolution_clock::now();
                            auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);
                            cout << tempString << " cannot be found in Dataset A - Time Taken: "<< duration.count() * 1e-9 << " seconds" << endl;;
                        }
                        tempString = ""; //Reset the string
                    }
                    datasetEntryFile.close();
                }
                else if (choiceSelection == 2)
                {
                    datasetEntryFile.open("EmailSetNotFound.txt");
                    cout << "Searching with a Dataset with items that cannot be found" << endl;
                    while(!datasetEntryFile.eof())
                    {
                        auto start = std::chrono::high_resolution_clock::now();
                        getline(datasetEntryFile, tempString); //Getting the line into a tempString
                        if (htB.retrieve(tempString))
                        {
                            auto end = std::chrono::high_resolution_clock::now();
                            auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);

                            cout << tempString << " can be found in Dataset B - Time Taken: " << duration.count() * 1e-9 << " seconds" << endl;;
                        }
                        else
                        {
                            auto end = std::chrono::high_resolution_clock::now();
                            auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);

                            cout << tempString << " can be found in Dataset B" << duration.count() * 1e-9 << " seconds" << endl;;
                        }
                        tempString = ""; //Reset the string
                    }
                    datasetEntryFile.close();
                }
                else if (choiceSelection == 3)
                {
                    auto start = std::chrono::high_resolution_clock::now();
                    datasetEntryFile.open("EmailSetNotFound.txt");
                    cout << "Searching with a Dataset with items that cannot be found" << endl;
                    while(!datasetEntryFile.eof())
                    {
                        getline(datasetEntryFile, tempString); //Getting the line into a tempString
                        if (htC.retrieve(tempString))
                        {
                            auto end = std::chrono::high_resolution_clock::now();
                            auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);
                            cout << tempString << " can be found in Dataset C" << duration.count() * 1e-9 << " seconds" << endl;;
                        }
                        else
                        {
                            auto end = std::chrono::high_resolution_clock::now();
                            auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);
                            cout << tempString << " can not be found in Dataset C" << duration.count() * 1e-9 << " seconds" << endl;;
                        }
                        tempString = ""; //Reset the string
                    }
                    datasetEntryFile.close();
                }
                else
                {
                    cout << "Please select the valid option" << endl;
                }
                break;
            }
            case 4:
            {
                if (timeDuration.empty() && datasetSelected.empty() && processSelected.empty())
                {
                    cout << "There is no dataset being inserted yet. Please make a process before hand" << endl;
                }
                else
                {
                    cout << "---------------------" << endl;
                    cout << "Time Duration History" << endl;
                    cout << "---------------------" << endl;

                    system("cls");
                    for (int i = 0; i < timeDuration.size(); i++)
                    {   
                        cout << datasetSelected[i] << endl;
                        cout << processSelected[i] << endl;
                        cout << timeDuration[i] << endl << endl;
                    }
                }
                break;
            }
            case 5:
            {
                break;
            }
            default:
            {
                cout << "Please enter a valid option" << endl;
            }
        }
        
    }
           
}

void linearProbing()
{
    system("cls");
    int choiceDataSet;
    string searchString;
    ifstream datasetEntryFile;

    vector<string> datasetSelected;
    vector<string> enqueueSelected;
    vector<string> dequeueSelected;

    int choiceSelection;
    cout << "----------------------------------------------" << endl;
    printf("\t Linear Probing \t\n");
    cout << "----------------------------------------------" << endl;

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
            system("cls");

            //HashTable<string> ht(150);
            HashMap<int, string> *linearHashTable = new HashMap<int, string>(151);
            //Might need to clear the hashmap elements
            while(true)
            {
                cout << "----------------------------------------------" << endl;
                printf("\t Linear Probing - Dataset A \t\n");
                cout << "----------------------------------------------" << endl;

                cout << "Which option do you want to do?" << endl;
                printf("1. Insertion - Finding time taken\n2. Search With Dataset Found Items\n3. Search With Dataset Not Found Items\n4. Exit Linear Probing\nChoice: ");
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
                    system("cls");
                    linearHashTable->clear();
                    auto start = std::chrono::high_resolution_clock::now();
                    string tempString;
                    
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
                    auto duration = std::chrono::duration_cast<chrono::nanoseconds>(end - start);

                    datasetEntryFile.close();
                    linearHashTable->displayHashMap();
                    cout << "Duration of insertion of email dataset A using Linear Probing Method: " << duration.count() * 1e-9 << " seconds" << endl;
                }

                //Searching with Dataset that can be founded
                else if (choiceSelection == 2)
                {
                    int asciiNum = 0;
                    int index = 0;

                    datasetEntryFile.open("EmailSetFound.txt");
                    cout << "Searching Dataset A with a Dataset with items that can be found" << endl;

                    auto start = std::chrono::high_resolution_clock::now();
                    while(!datasetEntryFile.eof())
                    {
                        getline(datasetEntryFile, searchString); //Getting the line into a tempString

                        //Converting String to ASCII
                        for (int j = 0; j < searchString.length(); j++)
                        {
                            asciiNum += searchString[j]; 
                        }
                        
                        if (linearHashTable->get(asciiNum))
                        {
                            auto end = std::chrono::high_resolution_clock::now();
                            auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);

                            cout << "Target has been found at index " << linearHashTable->getIndex(asciiNum) << endl;
                            cout << "Time taken: " << duration.count() * 1e-9 << " seconds" << endl;
                        }
                        else if (!(linearHashTable->get(asciiNum)))
                        {
                            auto end = std::chrono::high_resolution_clock::now();
                            auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);

                            cout << "Target has been not been found!" << endl;
                            cout << "Time taken: " << duration.count() * 1e-9 << " seconds" << endl;
                        }

                        searchString = ""; //Reset the string
                        asciiNum = 0;
                    }
                    datasetEntryFile.close();
                }

                //Search with Dataset that cannot be found 
                else if (choiceSelection == 3)
                {
                    int asciiNum = 0;
                    int index = 0;

                    datasetEntryFile.open("EmailSetNotFound.txt");
                    cout << "Searching Dataset A with a Dataset with items that cannot be found" << endl;

                    auto start = std::chrono::high_resolution_clock::now();
                    while(!datasetEntryFile.eof())
                    {
                        getline(datasetEntryFile, searchString); //Getting the line into a tempString

                        //Converting String to ASCII
                        for (int j = 0; j < searchString.length(); j++)
                        {
                            asciiNum += searchString[j]; 
                        }
                        
                        if (linearHashTable->get(asciiNum))
                        {
                            auto end = std::chrono::high_resolution_clock::now();
                            auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);

                            cout << "Target has been found at index " << linearHashTable->getIndex(asciiNum) << endl;
                            cout << "Time taken: " << duration.count() * 1e-9 << " seconds" << endl;
                        }
                        else if (!(linearHashTable->get(asciiNum)))
                        {
                            auto end = std::chrono::high_resolution_clock::now();
                            auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);

                            cout << "Target has been not been found!" << endl;
                            cout << "Time taken: " << duration.count() * 1e-9 << " seconds" << endl;
                        }

                        searchString = ""; //Reset the string
                        asciiNum = 0;
                    }
                    datasetEntryFile.close();
                }
                else if (choiceSelection == 4)
                {
                    break;
                }
                else
                {
                    cout << "Dataset has not been inserted yet!" << endl;
                }
            }
            break;
        }
        case 2:
        {
            system("cls");

            //HashTable<string> ht(150000);
            HashMap<int, string> *linearHashTable = new HashMap<int, string>(150001);
            while(true)
            {
                cout << "----------------------------------------------" << endl;
                printf("\t Linear Probing - Dataset B \t\n");
                cout << "----------------------------------------------" << endl;

                cout << "Which option do you want to do?" << endl;
                printf("1. Insertion - Finding time taken\n2. Search With Dataset Found Items\n3. Search With Dataset Not Found Items\n4. Exit Linear Probing\nChoice: ");
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
                    system("cls");
                    cout << "This will take a while, please wait for a moment.\n" << endl;
                    linearHashTable->clear();
                    auto start = std::chrono::high_resolution_clock::now();
                    string tempString;
                    
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
                    auto duration = std::chrono::duration_cast<chrono::nanoseconds>(end - start);

                    linearHashTable->displayHashMap();
                    datasetEntryFile.close();
                    cout << "Duration of insertion of email dataset A using Linear Probing Method: " << duration.count() * 1e-9 << " seconds" << endl;
                }
                //Searching with Dataset that can be founded
                else if (choiceSelection == 2)
                {
                    int asciiNum = 0;
                    int index = 0;

                    datasetEntryFile.open("EmailSetFound.txt");
                    cout << "Searching Dataset B with a Dataset with items that can be found" << endl;

                    auto start = std::chrono::high_resolution_clock::now();
                    while(!datasetEntryFile.eof())
                    {
                        getline(datasetEntryFile, searchString); //Getting the line into a tempString

                        //Converting String to ASCII
                        for (int j = 0; j < searchString.length(); j++)
                        {
                            asciiNum += searchString[j]; 
                        }
                        
                        if (linearHashTable->get(asciiNum))
                        {
                            auto end = std::chrono::high_resolution_clock::now();
                            auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);

                            cout << "Target has been found at index " << linearHashTable->getIndex(asciiNum) << endl;
                            cout << "Time taken: " << duration.count() * 1e-9 << " seconds" << endl;
                        }
                        else if (!(linearHashTable->get(asciiNum)))
                        {
                            auto end = std::chrono::high_resolution_clock::now();
                            auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);

                            cout << "Target has been not been found!" << endl;
                            cout << "Time taken: " << duration.count() * 1e-9 << " seconds" << endl;
                        }

                        searchString = ""; //Reset the string
                        asciiNum = 0;
                    }
                    datasetEntryFile.close();
                }

                //Search with Dataset that cannot be found 
                else if (choiceSelection == 3)
                {
                    int asciiNum = 0;
                    int index = 0;

                    datasetEntryFile.open("EmailSetNotFound.txt");
                    cout << "Searching Dataset B with a Dataset with items that cannot be found" << endl;

                    auto start = std::chrono::high_resolution_clock::now();
                    while(!datasetEntryFile.eof())
                    {
                        getline(datasetEntryFile, searchString); //Getting the line into a tempString

                        //Converting String to ASCII
                        for (int j = 0; j < searchString.length(); j++)
                        {
                            asciiNum += searchString[j]; 
                        }
                        
                        if (linearHashTable->get(asciiNum))
                        {
                            auto end = std::chrono::high_resolution_clock::now();
                            auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);

                            cout << "Target has been found at index " << linearHashTable->getIndex(asciiNum) << endl;
                            cout << "Time taken: " << duration.count() * 1e-9 << " seconds" << endl;
                        }
                        else if (!(linearHashTable->get(asciiNum)))
                        {
                            auto end = std::chrono::high_resolution_clock::now();
                            auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);

                            cout << "Target has been not been found!" << endl;
                            cout << "Time taken: " << duration.count() * 1e-9 << " seconds" << endl;
                        }

                        searchString = ""; //Reset the string
                        asciiNum = 0;
                    }
                    datasetEntryFile.close();
                }
                else if (choiceSelection == 4)
                {
                    break;
                }
                else
                {
                    cout << "Dataset has not been inserted yet!" << endl;
                }
                
            }
            break;
        }
        case 3:
        {
            system("cls");
            //HashTable<string> ht(750000);
            HashMap<int, string> *linearHashTable = new HashMap<int, string>(750001);
            while(true)
            {
                cout << "----------------------------------------------" << endl;
                printf("\t Linear Probing - Dataset C \t\n");
                cout << "----------------------------------------------" << endl;

                cout << "Which option do you want to do?" << endl;
                printf("1. Insertion - Finding time taken\n2. Search With Dataset Found Items\n3. Search With Dataset Not Found Items\n4. Exit Linear Probing\nChoice: ");
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
                    system("cls");
                    cout << "This will take a while, please wait for a moment.\n" << endl;
                    linearHashTable->clear();
                    auto start = std::chrono::high_resolution_clock::now();
                    string tempString;
                    
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
                    auto duration = std::chrono::duration_cast<chrono::nanoseconds>(end - start);

                    datasetEntryFile.close();
                    linearHashTable->displayHashMap();
                    cout << "Duration of insertion of email dataset A using Linear Probing Method: " << duration.count() * 1e-9 << " seconds" << endl;
                }
                //Searching with Dataset that can be founded
                else if (choiceSelection == 2)
                {
                    int asciiNum = 0;
                    int index = 0;

                    datasetEntryFile.open("EmailSetFound.txt");
                    cout << "Searching Dataset C with a Dataset with items that can be found" << endl;

                    auto start = std::chrono::high_resolution_clock::now();
                    while(!datasetEntryFile.eof())
                    {
                        getline(datasetEntryFile, searchString); //Getting the line into a tempString

                        //Converting String to ASCII
                        for (int j = 0; j < searchString.length(); j++)

                        {
                            asciiNum += searchString[j]; 
                        }
                        
                        if (linearHashTable->get(asciiNum))
                        {
                            auto end = std::chrono::high_resolution_clock::now();
                            auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);

                            cout << "Target has been found at index " << linearHashTable->getIndex(asciiNum) << endl;
                            cout << "Time taken: " << duration.count() * 1e-9 << " seconds" << endl;
                        }
                        else if (!(linearHashTable->get(asciiNum)))
                        {
                            auto end = std::chrono::high_resolution_clock::now();
                            auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);

                            cout << "Target has been not been found!" << endl;
                            cout << "Time taken: " << duration.count() * 1e-9 << " seconds" << endl;
                        }

                        searchString = ""; //Reset the string
                        asciiNum = 0;
                    }
                    datasetEntryFile.close();
                }

                //Search with Dataset that cannot be found 
                else if (choiceSelection == 3)
                {
                    int asciiNum = 0;
                    int index = 0;

                    datasetEntryFile.open("EmailSetNotFound.txt");
                    cout << "Searching Dataset C with a Dataset with items that cannot be found" << endl;

                    auto start = std::chrono::high_resolution_clock::now();
                    while(!datasetEntryFile.eof())
                    {
                        getline(datasetEntryFile, searchString); //Getting the line into a tempString

                        //Converting String to ASCII
                        for (int j = 0; j < searchString.length(); j++)
                        {
                            asciiNum += searchString[j]; 
                        }
                        
                        if (linearHashTable->get(asciiNum))
                        {
                            auto end = std::chrono::high_resolution_clock::now();
                            auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);

                            cout << "Target has been found at index " << linearHashTable->getIndex(asciiNum) << endl;
                            cout << "Time taken: " << duration.count() * 1e-9 << " seconds" << endl;
                        }
                        else if (!(linearHashTable->get(asciiNum)))
                        {
                            auto end = std::chrono::high_resolution_clock::now();
                            auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);

                            cout << "Target has been not been found!" << endl;
                            cout << "Time taken: " << duration.count() * 1e-9 << " seconds" << endl;
                        }

                        searchString = ""; //Reset the string
                        asciiNum = 0;
                    }
                    datasetEntryFile.close();
                }
                else if (choiceSelection == 4)
                {
                    break;
                }
                else
                {
                    cout << "Dataset has not been inserted yet!" << endl;
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

int main()
{
    int choice;
    while(true)
    {
        system("CLS");
        cout << "Welcome to the program. Which type of algorithm do you want to set on?" << endl;
        printf("1. Chaining Method\n2. Linear Probing\n3. Quit Program\nChoice: ");
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
                exit(0);
                break;
            default:
                cout << "Please choose the valid option" << endl;
        }
    }
    return 0;
    
}


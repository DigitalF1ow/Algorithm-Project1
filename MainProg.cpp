#include <iostream>
#include <ctime>
#include <unistd.h>
#include <string>
#include <fstream>
#include <exception>
#include <chrono>
#include <stdio.h>
#include <iomanip>

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
    

    HashTable<string> htA(90);
    HashTable<string> htB(90000);
    HashTable<string> htC(450000);

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
                    cout << "-----------------------------------------------" << endl;
			        printf("Insertion Process of Dataset A - Chaining Method\n");
			        cout << "-----------------------------------------------" << endl;
                    cout << "This will take a while, please wait for a moment.\n" << endl;
                    datasetEntryFile.open("EmailsetA.txt");

                    datasetSelected.push_back("Email Dataset A");
                    processSelected.push_back("Total Time Taken Insertion");

                    auto startA = std::chrono::steady_clock::now();
                    while(!datasetEntryFile.eof()) // Getting all the lines from the file
                    {
                        getline(datasetEntryFile, tempString); //saves the line in temporary
                        //cout << tempString << endl;
                        htA.insert(tempString);
                    }
                    auto endA = std::chrono::steady_clock::now();
                    auto durationA = std::chrono::duration_cast<chrono::nanoseconds>(endA - startA);
                    datasetEntryFile.close();

                    timeDuration.push_back(durationA.count() * 1e-9); //To get the duration into the record

                    //cout << htA << endl;

                    cout << fixed << setprecision(7) << "Time Taken:\n" << durationA.count() * 1e-9 << " seconds\n" << endl;
                }
                else if (choiceSelection == 2)
                {
                    string tempString;

                    datasetSelected.push_back("Email Dataset B");
                    processSelected.push_back("Total Time Taken Insertion");

                    htB.clear();
                    htB.resize(90000);
                    system("cls");
                    cout << "-----------------------------------------------" << endl;
			        printf("Insertion Process of Dataset B - Chaining Method\n");
			        cout << "-----------------------------------------------" << endl;
                    cout << "This will take a while, please wait for a moment.\n" << endl;

                    datasetEntryFile.open("EmailsetB.txt");
                    auto start = std::chrono::steady_clock::now();
                    while(!datasetEntryFile.eof()) // Getting all the lines from the file
                    {
                        getline(datasetEntryFile, tempString); //saves the line in temporary
                        //cout << tempString << endl;
                        htB.insert(tempString);
                    }
                    datasetEntryFile.close();
                    auto end = std::chrono::steady_clock::now();
                    auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);

                    timeDuration.push_back(duration.count() * 1e-9); //To get the duration into the record

                    //cout << htB << endl;
                    cout << setprecision(9) << "Time Taken:\n" << duration.count() * 1e-9 << " seconds\n" << endl;
                }
                else if (choiceSelection == 3)
                {
                    string tempString;
                    datasetSelected.push_back("Email Dataset C");
                    processSelected.push_back("Total Time Taken Insertion");

                    htC.clear();
                    htC.resize(450000);
                    system("cls");

                    cout << "-----------------------------------------------" << endl;
			        printf("Insertion Process of Dataset C - Chaining Method\n");
			        cout << "-----------------------------------------------" << endl;
                    cout << "This will take a while, please wait for a moment.\n" << endl;
                    datasetEntryFile.open("EmailSetC.txt");
                    auto start = std::chrono::steady_clock::now();
                    while(!datasetEntryFile.eof()) // Getting all the lines from the file
                    {
                        getline(datasetEntryFile, tempString); //saves the line in temporary
                        //cout << tempString << endl;
                        htC.insert(tempString);
                    }
                    datasetEntryFile.close();
                    auto end = std::chrono::steady_clock::now();
                    auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);

                    timeDuration.push_back(duration.count() * 1e-9); //To get the duration into the record

                    //cout << htC << endl;
                    cout << setprecision(9) << "Time Taken:\n" << duration.count() * 1e-9 << " seconds\n" << endl;
                }
                break;
            }
            case 2: //Search With Email Can be Found
            {

                float totalTime = 0;
                float avgTime = 0;
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
                if(choiceSelection == 1) //Dataset A
                {
                    datasetSelected.push_back("Email Dataset A");
                    processSelected.push_back("Search Process - Average Time Taken With Search Data Found");

                    datasetEntryFile.open("EmailSetFound.txt");

                    cout << "------------------------------------------------" << endl;
			        printf("Searching Process of Dataset A - Chaining Method\n");
			        cout << "------------------------------------------------" << endl;
                    cout << "Searching with a Dataset with items that can be found" << endl;

                    //Beginning Total Search
                    while(!datasetEntryFile.eof())
                    {
                        auto start = std::chrono::steady_clock::now();
                        getline(datasetEntryFile, tempString); //Getting the line into a tempString
                        if (htA.retrieve(tempString))
                        {
                            auto endSearch = std::chrono::steady_clock::now();
                            auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(endSearch - start);
                            cout << tempString << " can be found in Dataset A\nTime Taken: " << duration.count() * 1e-9 << " seconds\n" << endl;
                            totalTime += duration.count() * 1e-9;
                        }
                        else
                        {
                            auto endSearch = std::chrono::steady_clock::now();
                            auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(endSearch - start);
                            cout << tempString << " cannot be found in Dataset A\nTime Taken: "<< duration.count() * 1e-9 << " seconds\n" << endl;
                            totalTime += duration.count() * 1e-9;
                        }
                        tempString = ""; //Reset the string
                    }

                    avgTime = (totalTime/10);
                    timeDuration.push_back(avgTime);

                    datasetEntryFile.close();
                    avgTime = 0;
                    totalTime = 0;
                }
                else if (choiceSelection == 2) //Dataset B
                {
                    datasetSelected.push_back("Email Dataset B");
                    processSelected.push_back("Search Process - Average Time Taken With Search Data Found");

                    datasetEntryFile.open("EmailSetFound.txt");

                    cout << "------------------------------------------------" << endl;
			        printf("Searching Process of Dataset B - Chaining Method\n");
			        cout << "------------------------------------------------" << endl;
                    cout << "Searching with a Dataset with items that can be found" << endl;
                    while(!datasetEntryFile.eof())
                    {
                        auto start = std::chrono::steady_clock::now();
                        getline(datasetEntryFile, tempString); //Getting the line into a tempString
                        if (htB.retrieve(tempString))
                        {
                            auto end = std::chrono::steady_clock::now();
                            auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);
                            cout << tempString << " can be found in Dataset B\nTime Taken: " << duration.count() * 1e-9 << " seconds\n" << endl;

                            totalTime += duration.count() * 1e-9;
                        }
                        else
                        {
                            auto end = std::chrono::steady_clock::now();
                            auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);
                            cout << tempString << " can be found in Dataset B\nTime Taken: " << duration.count() * 1e-9 << " seconds\n" << endl;;
                            totalTime += duration.count() * 1e-9;
                        }
                        tempString = ""; //Reset the string
                    }
                    avgTime = (totalTime/10);
                    timeDuration.push_back(avgTime);
                    cout << avgTime << " seconds" << endl;
                    datasetEntryFile.close();
                    avgTime = 0;
                    totalTime = 0;
                }
                else if (choiceSelection == 3) //Dataset C
                {
                    datasetSelected.push_back("Email Dataset C");
                    processSelected.push_back("Search Process - Average Time Taken With Search Data Found");
                    
                    datasetEntryFile.open("EmailSetFound.txt");

                    cout << "------------------------------------------------" << endl;
			        printf("Searching Process of Dataset C - Chaining Method\n");
			        cout << "------------------------------------------------" << endl;
                    cout << "Searching with a Dataset with items that can be found" << endl;
                    while(!datasetEntryFile.eof())
                    {
                        auto start = std::chrono::steady_clock::now();
                        getline(datasetEntryFile, tempString); //Getting the line into a tempString
                        if (htC.retrieve(tempString))
                        {
                            auto end = std::chrono::steady_clock::now();
                            auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);
                            cout << tempString << " can be found in Dataset C\nTime Taken: " << duration.count() * 1e-9 << " seconds\n" << endl;
                            totalTime += duration.count() * 1e-9;
                        }
                        else
                        {
                            auto end = std::chrono::steady_clock::now();
                            auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);
                            cout << tempString << " can not be found in Dataset C\nTime Taken:" << duration.count() * 1e-9 << " seconds\n" << endl;
                            totalTime += duration.count() * 1e-9;
                        }
                        tempString = ""; //Reset the string
                    }
                    datasetEntryFile.close();

                    avgTime = (totalTime/10);
                    timeDuration.push_back(avgTime);
                    avgTime = 0;
                    totalTime = 0;
                }
                else
                {
                    cout << "Please select the valid option" << endl;
                }
                break;
            }
            case 3: //Search with emaIL that cannot be founded
            {
                float totalTime = 0;
                float avgTime = 0;

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
                if(choiceSelection == 1) //Dataset A
                {
                    datasetSelected.push_back("Email Dataset A");
                    processSelected.push_back("Search Process - Average Time Taken With Search Data Not Found");

                    datasetEntryFile.open("EmailSetNotFound.txt");

                    cout << "------------------------------------------------" << endl;
			        printf("Searching Process of Dataset A - Chaining Method\n");
			        cout << "------------------------------------------------" << endl;
                    cout << "Searching with a Dataset with items that cannot be found" << endl;

                    
                    while(!datasetEntryFile.eof())
                    {
                        auto start = std::chrono::steady_clock::now();
                        getline(datasetEntryFile, tempString); //Getting the line into a tempString
                        if (htA.retrieve(tempString))
                        {
                            auto end = std::chrono::steady_clock::now();
                            auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);
                            cout << tempString << " can be found in Dataset A\nTime taken: " << duration.count() * 1e-9 << " seconds\n" << endl;
                            totalTime += duration.count() * 1e-9;
                        }
                        else
                        {
                            auto end = std::chrono::steady_clock::now();
                            auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);
                            cout << tempString << " cannot be found in Dataset A\nTime Taken: "<< duration.count() * 1e-9 << " seconds\n" << endl;
                            totalTime += duration.count() * 1e-9;
                        }
                        tempString = ""; //Reset the string
                    }
                    datasetEntryFile.close();

                    avgTime = (totalTime/10);
                    timeDuration.push_back(avgTime);
                    avgTime = 0;
                    totalTime = 0;
                    
                }
                else if (choiceSelection == 2) // Dataset B
                {
                    datasetSelected.push_back("Email Dataset B");
                    processSelected.push_back("Search Process - Average Time Taken With Search Data Not Found");

                    datasetEntryFile.open("EmailSetNotFound.txt");

                    cout << "------------------------------------------------" << endl;
			        printf("Searching Process of Dataset B - Chaining Method\n");
			        cout << "------------------------------------------------" << endl;
                    cout << "Searching with a Dataset with items that cannot be found" << endl;
                    while(!datasetEntryFile.eof())
                    {
                        auto start = std::chrono::steady_clock::now();
                        getline(datasetEntryFile, tempString); //Getting the line into a tempString
                        if (htB.retrieve(tempString))
                        {
                            auto end = std::chrono::steady_clock::now();
                            auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);

                            cout << tempString << " can be found in Dataset B\nTime Taken: " << duration.count() * 1e-9 << " seconds" << endl;
                            totalTime += duration.count() * 1e-9;
                        }
                        else
                        {
                            auto end = std::chrono::steady_clock::now();
                            auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);

                            cout << tempString << " cannot be found in Dataset B\nTime Taken: " << duration.count() * 1e-9 << " seconds" << endl;
                            totalTime += duration.count() * 1e-9;
                        }
                        tempString = ""; //Reset the string
                    }
                    datasetEntryFile.close();

                    avgTime = (totalTime/10);
                    timeDuration.push_back(avgTime);
                    avgTime = 0;
                    totalTime = 0;
                }
                else if (choiceSelection == 3) // Dataset C
                {
                    datasetSelected.push_back("Email Dataset C");
                    processSelected.push_back("Search Process - Average Time Taken With Search Data Not Found");
                    
                    datasetEntryFile.open("EmailSetNotFound.txt");

                    cout << "------------------------------------------------" << endl;
			        printf("Searching Process of Dataset C - Chaining Method\n");
			        cout << "------------------------------------------------" << endl;
                    cout << "Searching with a Dataset with items that cannot be found" << endl;
                    while(!datasetEntryFile.eof())
                    {
                        auto start = std::chrono::steady_clock::now();
                        getline(datasetEntryFile, tempString); //Getting the line into a tempString
                        if (htC.retrieve(tempString))
                        {
                            auto end = std::chrono::steady_clock::now();
                            auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);
                            cout << tempString << " can be found in Dataset C\nTime Taken: " << duration.count() * 1e-9 << " seconds" << endl;
                            totalTime += duration.count() * 1e-9;
                        }
                        else
                        {
                            auto end = std::chrono::steady_clock::now();
                            auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);
                            cout << fixed;
                            cout << tempString << " cannot be found in Dataset C\nTime Taken: " << setprecision(9) << duration.count() * 1e-9 << " seconds" << endl;
                            totalTime += duration.count() * 1e-9;
                        }
                        tempString = ""; //Reset the string
                    }
                    datasetEntryFile.close();

                    avgTime = (totalTime/10);
                    timeDuration.push_back(avgTime);
                    avgTime = 0;
                    totalTime = 0;
                }
                else
                {
                    cout << "Please select the valid option" << endl;
                }
                break;
            }
            case 4: // Time Duration History
            {
                if (timeDuration.empty() && datasetSelected.empty() && processSelected.empty())
                {
                    cout << "There is no dataset being inserted yet. Please make a process before hand" << endl;
                }
                else
                {
                    system("cls");
                    cout << setprecision(7) << endl;
                    cout << "---------------------------------------" << endl;
                    cout << "Time Duration History - Chaining Method" << endl;
                    cout << "---------------------------------------" << endl;

                    for (int i = 0; i < timeDuration.size(); i++)
                    {   
                        cout <<"Dataset         :"<< datasetSelected[i] << endl;
                        cout <<"Process Selected:"<< processSelected[i] << endl;
                        cout <<"Time Taken      :"<< timeDuration[i] << " seconds"<< endl << endl;
                    }
                }
                break;
            }
            case 5:
            {
                return;
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

    //For Time Duration History
    vector<string> datasetSelected;
    vector<string> processSelected;
    vector<float> timeDuration;
    vector<float> searchDuration;

    //
    HashMap<int, string> *linearHashTableA = new HashMap<int, string>(150);
    HashMap<int, string> *linearHashTableB = new HashMap<int, string>(150000);
    HashMap<int, string> *linearHashTableC = new HashMap<int, string>(750000);

    int choiceSelection;

    while (true)
    {
        cout << "----------------------------------------------" << endl;
        printf("\t     Linear Probing \t\n");
        cout << "----------------------------------------------" << endl;

        cout << "Which option do you want to do?" << endl;
        printf("1. Insertion - Finding time taken\n2. Search With Dataset Found Items\n3. Search With Dataset Not Found Items\n4. Time Duration History\n5. Exit Linear Probing\nChoice: ");
        cin >> choiceSelection;
        while(cin.fail())
        {
            cout << "Please enter a valid number" << endl;
            cin.clear();
            cin.ignore();
            printf("Choice:");
            cin >> choiceSelection;
        }
        switch(choiceSelection)
        {
            case 1: //Insertion Process Via Linear Probing
            {   
                cout << fixed << setprecision(7) << "What dataset would you want to choose?" << endl;
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
                    system("cls");
                    linearHashTableA->clear();
                    string tempString;
                    
                    //50% more than the dataset used
                    datasetSelected.push_back("Dataset A");
                    processSelected.push_back("Insertion Process - Total Time Taken");


                    cout << "-----------------------------------------------" << endl;
			        printf("Insertion Process of Dataset A - Linear Probing\n");
			        cout << "-----------------------------------------------" << endl;
                    cout << "This will take a while, please wait for a moment.\n" << endl;

                    datasetEntryFile.open("EmailSetA.txt");
                    auto start = std::chrono::steady_clock::now();
                    while (!datasetEntryFile.eof()) 
                    {
                        getline(datasetEntryFile, tempString);
                        int asciiNum = 0;
                        int index = 0;

                        for (int i = 0; i < tempString.length(); i++)
                        {
                            asciiNum += tempString[i]; 
                        }

                        linearHashTableA->insert(asciiNum, tempString);

                        tempString = "";
                    }
                    
                    auto end = std::chrono::steady_clock::now();
                    auto duration = std::chrono::duration_cast<chrono::nanoseconds>(end - start);

                    //Time Duration Record  
                    timeDuration.push_back(duration.count() * 1e-9);

                    datasetEntryFile.close();
                    //linearHashTableA->displayHashMap();

                    cout << "Time Taken: " << duration.count() * 1e-9 << " seconds\n" << endl;
                }
                else if(choiceSelection == 2)
                {
                    system("cls");
                    linearHashTableB->clear();
                    string tempString;
                    
                    //50% more than the dataset used
                    
                    datasetSelected.push_back("Dataset B");
                    processSelected.push_back("Insertion Process - Total Time Taken");

                    cout << "-----------------------------------------------" << endl;
			        printf("Insertion Process of Dataset B - Linear Probing\n");
			        cout << "-----------------------------------------------" << endl;
                    cout << "This will take a while, please wait for a moment.\n" << endl;

                    datasetEntryFile.open("EmailSetB.txt");
                    auto start = std::chrono::steady_clock::now();
                    while (!datasetEntryFile.eof())
                    {
                        getline(datasetEntryFile, tempString);
                        int asciiNum = 0;
                        int index = 0;

                        for (int i = 0; i < tempString.length(); i++)
                        {
                            asciiNum += tempString[i]; 
                        }

                        linearHashTableB->insert(asciiNum, tempString);

                        tempString = "";
                    }
                    
                    auto end = std::chrono::steady_clock::now();
                    auto duration = std::chrono::duration_cast<chrono::nanoseconds>(end - start);

                    //Time Duration Record  
                    timeDuration.push_back(duration.count() * 1e-9);

                    datasetEntryFile.close();
                    //linearHashTableB->displayHashMap();

                    cout << "Time Taken:\n" << duration.count() * 1e-9 << " seconds\n" << endl;
                }
                else if(choiceSelection == 3)
                {
                    system("cls");
                    linearHashTableC->clear();
                    
                    string tempString;
                    
                    //50% more than the dataset used
                    datasetSelected.push_back("Dataset C");
                    processSelected.push_back("Insertion Process - Total Time Taken");

                    cout << "-----------------------------------------------" << endl;
			        printf("Insertion Process of Dataset C - Linear Probing\n");
			        cout << "-----------------------------------------------" << endl;
                    cout << "This will take a while, please wait for a moment.\n" << endl;

                    datasetEntryFile.open("EmailSetC.txt");
                    auto start = std::chrono::steady_clock::now();
                    while (!datasetEntryFile.eof())
                    {
                        getline(datasetEntryFile, tempString);
                        int asciiNum = 0;
                        int index = 0;

                        for (int i = 0; i < tempString.length(); i++)
                        {
                            asciiNum += tempString[i]; 
                        }

                        linearHashTableC->insert(asciiNum, tempString);

                        tempString = "";
                    }
                    
                    auto end = std::chrono::steady_clock::now();
                    auto duration = std::chrono::duration_cast<chrono::nanoseconds>(end - start);

                    //Time Duration Record  
                    timeDuration.push_back(duration.count() * 1e-9);

                    datasetEntryFile.close();
                    //linearHashTableC->displayHashMap();

                    cout << "Time Taken:\n" << duration.count() * 1e-9 << " seconds\n" << endl;
                }
                else
                {
                    cout << "That is not valid option, please try again" << endl;
                }
                break;
            }
            case 2: //Searching With Dataset that cannot be founded
            {
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

                if(choiceSelection == 1)
                {
                    system("cls");
                    int asciiNum = 0;
                    int index = 0;

                    float avgTime = 0;
                    float totalTime = 0;

                    datasetSelected.push_back("Email Dataset A");
                    processSelected.push_back("Search Process - Average Time Taken Search With Search Data Found");

                    datasetEntryFile.open("EmailSetFound.txt");
                    cout << "-----------------------------------------------" << endl;
			        printf("Searching Process of Dataset A - Linear Probing\n");
			        cout << "-----------------------------------------------" << endl;

                    cout << "Search with Search Data that can be found" << endl;

                   
                    while(!datasetEntryFile.eof())
                    {
                        auto start = std::chrono::steady_clock::now();
                        getline(datasetEntryFile, searchString); //Getting the line into a tempString

                        //Converting String to ASCII
                        for (int j = 0; j < searchString.length(); j++)
                        {
                            asciiNum += searchString[j]; 
                        }
                        
                        if (linearHashTableA->get(asciiNum))
                        {
                            auto end = std::chrono::steady_clock::now();
                            auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);

                            cout << "Target has been found at index " << linearHashTableA->getIndex(asciiNum) << endl;
                            cout << "Time taken: " << duration.count() * 1e-9 << " seconds" << endl;

                            totalTime += duration.count() * 1e-9;
                        }
                        else if (!(linearHashTableA->get(asciiNum)))
                        {
                            auto end = std::chrono::steady_clock::now();
                            auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);

                            cout << "Target has been not been found!" << endl;
                            cout << "Time taken: " << duration.count() * 1e-9 << " seconds" << endl;

                            totalTime += duration.count() * 1e-9;
                        }

                        searchString = ""; //Reset the string
                        asciiNum = 0;
                    }
                    datasetEntryFile.close();

                    avgTime = (totalTime/10);
                    timeDuration.push_back(avgTime);
                    avgTime = 0;
                    totalTime = 0;
                }
                else if(choiceSelection == 2)
                {
                    system("cls");
                    int asciiNum = 0;
                    int index = 0;

                    float avgTime = 0;
                    float totalTime = 0;

                    datasetSelected.push_back("Email Dataset B");
                    processSelected.push_back("Search Process - Average Time Taken Search With Search Data Found");

                    datasetEntryFile.open("EmailSetFound.txt");
                    cout << "-----------------------------------------------" << endl;
			        printf("Searching Process of Dataset B - Linear Probing\n");
			        cout << "-----------------------------------------------" << endl;

                    cout << "Search with Search Data that can be found" << endl;

                    
                    while(!datasetEntryFile.eof())
                    {
                        auto start = std::chrono::steady_clock::now();
                        getline(datasetEntryFile, searchString); //Getting the line into a tempString

                        //Converting String to ASCII
                        for (int j = 0; j < searchString.length(); j++)
                        {
                            asciiNum += searchString[j]; 
                        }
                        
                        if (linearHashTableB->get(asciiNum))
                        {
                            auto end = std::chrono::steady_clock::now();
                            auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);

                            cout << "Target has been found at index " << linearHashTableB->getIndex(asciiNum) << endl;
                            cout << "Time taken: " << duration.count() * 1e-9 << " seconds" << endl;

                            totalTime += duration.count() * 1e-9;
                        }
                        else if (!(linearHashTableB->get(asciiNum)))
                        {
                            auto end = std::chrono::steady_clock::now();
                            auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);

                            cout << "Target has been not been found!" << endl;
                            cout << "Time taken: " << duration.count() * 1e-9 << " seconds" << endl;

                            totalTime += duration.count() * 1e-9;
                        }

                        searchString = ""; //Reset the string
                        asciiNum = 0;
                    }
                    datasetEntryFile.close();

                    avgTime = (totalTime/10);
                    timeDuration.push_back(avgTime);
                    avgTime = 0;
                    totalTime = 0;
                }
                else if(choiceSelection == 3)
                {
                    system("cls");
                    int asciiNum = 0;
                    int index = 0;

                    float avgTime = 0;
                    float totalTime = 0;

                    datasetSelected.push_back("Email Dataset C");
                    processSelected.push_back("Search Process - Average Time Taken Search With Search Data Found");
                    datasetEntryFile.open("EmailSetFound.txt");
                    cout << "-----------------------------------------------" << endl;
			        printf("Searching Process of Dataset C - Linear Probing\n");
			        cout << "-----------------------------------------------" << endl;

                    cout << "Search with Search Data that can be found" << endl;

                   
                    while(!datasetEntryFile.eof())
                    {
                        auto start = std::chrono::steady_clock::now();
                        getline(datasetEntryFile, searchString); //Getting the line into a tempString

                        //Converting String to ASCII
                        for (int j = 0; j < searchString.length(); j++)
                        {
                            asciiNum += searchString[j]; 
                        }
                        
                        if (linearHashTableC->get(asciiNum))
                        {
                            auto end = std::chrono::steady_clock::now();
                            auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);

                            cout << "Target has been found at index " << linearHashTableC->getIndex(asciiNum) << endl;
                            cout << "Time taken: " << duration.count() * 1e-9 << " seconds" << endl;
                            totalTime += duration.count() * 1e-9;
                        }
                        else if (!(linearHashTableC->get(asciiNum)))
                        {
                            auto end = std::chrono::steady_clock::now();
                            auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);

                            cout << "Target has been not been found!" << endl;
                            cout << "Time taken: " << duration.count() * 1e-9 << " seconds" << endl;
                            totalTime += duration.count() * 1e-9;
                        }

                        searchString = ""; //Reset the string
                        asciiNum = 0;
                    }
                    datasetEntryFile.close();

                    avgTime = (totalTime/10);
                    timeDuration.push_back(avgTime);
                    avgTime = 0;
                    totalTime = 0;
                }
                else
                {
                    cout << "That is nota valid option, please try again" << endl;
                }
                break;
            }
            //Search With Dataset cannot be founded
            case 3:
            {
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

                if(choiceSelection == 1)
                {
                    system("cls");
                    int asciiNum = 0;
                    int index = 0;

                    float avgTime = 0;
                    float totalTime = 0;

                    datasetSelected.push_back("Email Dataset A");
                    processSelected.push_back("Search Process - Average Time Taken Search With Search Data Not Found");

                    datasetEntryFile.open("EmailSetNotFound.txt");
                    cout << "-----------------------------------------------" << endl;
			        printf("Searching Process of Dataset A - Linear Probing\n");
			        cout << "-----------------------------------------------" << endl;

                    cout << "Search with Search Data that cannot be found" << endl;

                    
                    while(!datasetEntryFile.eof())
                    {
                        auto start = std::chrono::steady_clock::now();
                        getline(datasetEntryFile, searchString); //Getting the line into a tempString

                        //Converting String to ASCII
                        for (int j = 0; j < searchString.length(); j++)
                        {
                            asciiNum += searchString[j]; 
                        }
                        
                        if (linearHashTableA->get(asciiNum))
                        {
                            auto end = std::chrono::steady_clock::now();
                            auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);

                            cout << "Target has been found at index " << linearHashTableA->getIndex(asciiNum) << endl;
                            cout << "Time taken: " << duration.count() * 1e-9 << " seconds" << endl;
                            totalTime += duration.count() * 1e-9;
                        }
                        else if (!(linearHashTableA->get(asciiNum)))
                        {
                            auto end = std::chrono::steady_clock::now();
                            auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);

                            cout << "Target has been not been found!" << endl;
                            cout << "Time taken: " << duration.count() * 1e-9 << " seconds" << endl;
                            totalTime += duration.count() * 1e-9;
                        }

                        searchString = ""; //Reset the string
                        asciiNum = 0;                       
                    }
                    datasetEntryFile.close();
                    avgTime = (totalTime/10);
                    timeDuration.push_back(avgTime);
                    avgTime = 0;
                    totalTime = 0;
                }
                else if(choiceSelection == 2)
                {
                    float avgTime = 0;
                    float totalTime = 0;

                    datasetSelected.push_back("Email Dataset B");
                    processSelected.push_back("Search Process - Average Time Taken Search With Search Data Not Found");

                    system("cls");
                    int asciiNum = 0;
                    int index = 0;

                    datasetEntryFile.open("EmailSetNotFound.txt");
                    cout << "-----------------------------------------------" << endl;
			        printf("Searching Process of Dataset B - Linear Probing\n");
			        cout << "-----------------------------------------------" << endl;

                    cout << "Search with Search Data that cannot be found" << endl;

                   
                    while(!datasetEntryFile.eof())
                    {
                        auto start = std::chrono::steady_clock::now();
                        getline(datasetEntryFile, searchString); //Getting the line into a tempString

                        //Converting String to ASCII
                        for (int j = 0; j < searchString.length(); j++)
                        {
                            asciiNum += searchString[j]; 
                        }
                        
                        if (linearHashTableB->get(asciiNum))
                        {
                            auto end = std::chrono::steady_clock::now();
                            auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);

                            cout << "Target has been found at index " << linearHashTableB->getIndex(asciiNum) << endl;
                            cout << "Time taken: " << duration.count() * 1e-9 << " seconds" << endl;
                            totalTime += duration.count() * 1e-9;
                        }
                        else if (!(linearHashTableB->get(asciiNum)))
                        {
                            auto end = std::chrono::steady_clock::now();
                            auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);

                            cout << "Target has been not been found!" << endl;
                            cout << "Time taken: " << duration.count() * 1e-9 << " seconds" << endl;

                            totalTime += duration.count() * 1e-9;
                        }

                        searchString = ""; //Reset the string
                        asciiNum = 0;
                    }
                    datasetEntryFile.close();

                    avgTime = (totalTime/10);
                    timeDuration.push_back(avgTime);
                    avgTime = 0;
                    totalTime = 0;
                }
                else if(choiceSelection == 3)
                {
                    system("cls");
                    int asciiNum = 0;
                    int index = 0;

                    float avgTime = 0;
                    float totalTime = 0;

                    datasetSelected.push_back("Email Dataset C");
                    processSelected.push_back("Search Process - Average Time Taken Search With Search Data Not Found");

                    datasetEntryFile.open("EmailSetNotFound.txt");
                    cout << "-----------------------------------------------" << endl;
			        printf("Searching Process of Dataset C - Linear Probing\n");
			        cout << "-----------------------------------------------" << endl;

                    cout << "Search with Search Data that cannot be found" << endl;

                    
                    while(!datasetEntryFile.eof())
                    {
                        auto start = std::chrono::steady_clock::now();
                        getline(datasetEntryFile, searchString); //Getting the line into a tempString

                        //Converting String to ASCII
                        for (int j = 0; j < searchString.length(); j++)
                        {
                            asciiNum += searchString[j]; 
                        }
                        
                        if (linearHashTableC->get(asciiNum))
                        {
                            auto end = std::chrono::steady_clock::now();
                            auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);

                            cout << "Target has been found at index " << linearHashTableC->getIndex(asciiNum) << endl;
                            cout << "Time taken: " << duration.count() * 1e-9 << " seconds" << endl;

                            totalTime += duration.count() * 1e-9;
                        }
                        else if (!(linearHashTableC->get(asciiNum)))
                        {
                            auto end = std::chrono::steady_clock::now();
                            auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);

                            cout << "Target has been not been found!" << endl;
                            cout << "Time taken: " << duration.count() * 1e-9 << " seconds" << endl;

                            totalTime += duration.count() * 1e-9;
                        }

                        searchString = ""; //Reset the string
                        asciiNum = 0;
                    }
                    datasetEntryFile.close();

                    avgTime = (totalTime/10);
                    timeDuration.push_back(avgTime);
                    avgTime = 0;
                    totalTime = 0;
                }
                else
                {
                    cout << "That is nota valid option, please try again" << endl;
                }
                break;
            }
            case 4:
            {
                if (timeDuration.empty() && datasetSelected.empty() && processSelected.empty())
                {
                    cout << "There is no dataset being inserted yet. Please make a process beforehand" << endl;
                }
                else
                {

                    system("cls");
                    cout << "--------------------------------------" << endl;
                    cout << "Time Duration History - Linear Probing" << endl;
                    cout << "--------------------------------------" << endl;
                    for (int i = 0; i < timeDuration.size(); i++)
                    {   
                        cout << setprecision(9) << endl;
                        cout <<"Dataset         :"<< datasetSelected[i] << endl;
                        cout <<"Process Selected:"<< processSelected[i] << endl;
                        cout <<"Time Taken      :"<< timeDuration[i] << " seconds"<< endl << endl;
                    }
                }
                break;
            }
            case 5:
            {
                return;
            }
            default:
            {
                cout << "That is not a valid option, please try again" << endl;
            }
        }   
    }
    
    
}

int main()
{
    int choice;
    while(true)
    {
        system("CLS");
        cout << "----------------------------------------------" << endl;
        cout << "Program 1 - Chaining Method and Linear Probing" << endl;
        cout << "----------------------------------------------\n" << endl;

        cout << "Welcome to the program. Which type of algorithm do you want to set on?" << endl;
        printf("1. Chaining Method\n2. Linear Probing\n3. Quit Program\n\nChoice: ");
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


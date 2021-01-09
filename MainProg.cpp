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
    vector<double> timeDuration;
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
                    datasetEntryFile.open("EmailSetC.txt");
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
                if(choiceSelection == 1) //Dataset A
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
                else if (choiceSelection == 2) //Dataset B
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
                else if (choiceSelection == 3) //Dataset C
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
            case 3: //Search with emaIL that cannot be founded
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
                if(choiceSelection == 1) //Dataset A
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
                else if (choiceSelection == 2) // Dataset B
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
                else if (choiceSelection == 3) // Dataset C
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
            case 4: // Time Duration History
            {
                if (timeDuration.empty() && datasetSelected.empty() && processSelected.empty())
                {
                    cout << "There is no dataset being inserted yet. Please make a process before hand" << endl;
                }
                else
                {
                    system("cls");
                    cout << "---------------------" << endl;
                    cout << "Time Duration History" << endl;
                    cout << "---------------------" << endl;

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
    vector<double> timeDuration;

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
                    linearHashTableA->clear();
                    string tempString;
                    
                    //50% more than the dataset used
                    datasetSelected.push_back("Dataset A");
                    processSelected.push_back("Insertion Process");

                    datasetEntryFile.open("EmailSetA.txt");
                    auto start = std::chrono::high_resolution_clock::now();
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
                    
                    auto end = std::chrono::high_resolution_clock::now();
                    auto duration = std::chrono::duration_cast<chrono::nanoseconds>(end - start);

                    //Time Duration Record  
                    timeDuration.push_back(duration.count() * 1e-9);

                    datasetEntryFile.close();
                    linearHashTableA->displayHashMap();
                    cout << "Duration of insertion of email dataset A using Linear Probing Method: " << duration.count() * 1e-9 << " seconds" << endl;
                }
                else if(choiceSelection == 2)
                {
                    system("cls");
                    linearHashTableB->clear();
                    string tempString;
                    
                    //50% more than the dataset used
                    
                    datasetSelected.push_back("Dataset B");
                    processSelected.push_back("Insertion Process");

                    datasetEntryFile.open("EmailSetB.txt");
                    auto start = std::chrono::high_resolution_clock::now();
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
                    
                    auto end = std::chrono::high_resolution_clock::now();
                    auto duration = std::chrono::duration_cast<chrono::nanoseconds>(end - start);

                    //Time Duration Record  
                    timeDuration.push_back(duration.count() * 1e-9);

                    datasetEntryFile.close();
                    linearHashTableB->displayHashMap();
                    cout << "Duration of insertion of email dataset A using Linear Probing Method: " << duration.count() * 1e-9 << " seconds" << endl;
                }
                else if(choiceSelection == 3)
                {
                    system("cls");
                    linearHashTableC->clear();
                    
                    string tempString;
                    
                    //50% more than the dataset used
                    datasetSelected.push_back("Dataset C");
                    processSelected.push_back("Insertion Process");

                    datasetEntryFile.open("EmailSetC.txt");
                    auto start = std::chrono::high_resolution_clock::now();
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
                    
                    auto end = std::chrono::high_resolution_clock::now();
                    auto duration = std::chrono::duration_cast<chrono::nanoseconds>(end - start);

                    //Time Duration Record  
                    timeDuration.push_back(duration.count() * 1e-9);

                    datasetEntryFile.close();
                    linearHashTableC->displayHashMap();
                    cout << "Duration of insertion of email dataset A using Linear Probing Method: " << duration.count() * 1e-9 << " seconds" << endl;
                }
                else
                {
                    cout << "That is nota valid option, please try again" << endl;
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
                        
                        if (linearHashTableA->get(asciiNum))
                        {
                            auto end = std::chrono::high_resolution_clock::now();
                            auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);

                            cout << "Target has been found at index " << linearHashTableA->getIndex(asciiNum) << endl;
                            cout << "Time taken: " << duration.count() * 1e-9 << " seconds" << endl;
                        }
                        else if (!(linearHashTableA->get(asciiNum)))
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
                else if(choiceSelection == 2)
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
                        
                        if (linearHashTableB->get(asciiNum))
                        {
                            auto end = std::chrono::high_resolution_clock::now();
                            auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);

                            cout << "Target has been found at index " << linearHashTableB->getIndex(asciiNum) << endl;
                            cout << "Time taken: " << duration.count() * 1e-9 << " seconds" << endl;
                        }
                        else if (!(linearHashTableB->get(asciiNum)))
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
                else if(choiceSelection == 3)
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
                        
                        if (linearHashTableC->get(asciiNum))
                        {
                            auto end = std::chrono::high_resolution_clock::now();
                            auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);

                            cout << "Target has been found at index " << linearHashTableC->getIndex(asciiNum) << endl;
                            cout << "Time taken: " << duration.count() * 1e-9 << " seconds" << endl;
                        }
                        else if (!(linearHashTableC->get(asciiNum)))
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
                    int asciiNum = 0;
                    int index = 0;

                    datasetEntryFile.open("EmailSetNotFound.txt");
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
                        
                        if (linearHashTableA->get(asciiNum))
                        {
                            auto end = std::chrono::high_resolution_clock::now();
                            auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);

                            cout << "Target has been found at index " << linearHashTableA->getIndex(asciiNum) << endl;
                            cout << "Time taken: " << duration.count() * 1e-9 << " seconds" << endl;
                        }
                        else if (!(linearHashTableA->get(asciiNum)))
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
                else if(choiceSelection == 2)
                {
                    int asciiNum = 0;
                    int index = 0;

                    datasetEntryFile.open("EmailSetNotFound.txt");
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
                        
                        if (linearHashTableB->get(asciiNum))
                        {
                            auto end = std::chrono::high_resolution_clock::now();
                            auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);

                            cout << "Target has been found at index " << linearHashTableB->getIndex(asciiNum) << endl;
                            cout << "Time taken: " << duration.count() * 1e-9 << " seconds" << endl;
                        }
                        else if (!(linearHashTableB->get(asciiNum)))
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
                else if(choiceSelection == 3)
                {
                    int asciiNum = 0;
                    int index = 0;

                    datasetEntryFile.open("EmailSetNotFound.txt");
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
                        
                        if (linearHashTableC->get(asciiNum))
                        {
                            auto end = std::chrono::high_resolution_clock::now();
                            auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);

                            cout << "Target has been found at index " << linearHashTableC->getIndex(asciiNum) << endl;
                            cout << "Time taken: " << duration.count() * 1e-9 << " seconds" << endl;
                        }
                        else if (!(linearHashTableC->get(asciiNum)))
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
                        cout << datasetSelected[i] << endl;
                        cout << processSelected[i] << endl;
                        cout << timeDuration[i] << endl << endl;
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


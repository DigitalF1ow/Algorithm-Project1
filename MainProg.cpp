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

    int choiceDataSet;
    //string searchString;
    string tempString;
    ifstream datasetEntryFile;

    int choiceSelection;
    cout << "----------------------------------------------" << endl;
    printf("\t Chaining Method \t\n");
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
            HashTable<string> ht(90);
            
            while(true)
            {
                cout << "----------------------------------------------" << endl;
                printf("\t Chaining Method - Dataset A \t\n");
                cout << "----------------------------------------------" << endl;

                cout << "Which option do you want to do?" << endl;
                printf("1. Insertion - Finding time taken\n2. Search with Email That Can be Found\n3. Search With Email That Cannot be Found\n4. Exit Chaining Method\nChoice: ");
                cin >> choiceSelection;

                while(cin.fail())
                {
                    cout << "Please enter a valid number" << endl;
                    cin.clear();
                    cin.ignore();
                    printf("Choice:");
                    cin >> choiceSelection;
                    
                }

                if(choiceSelection == 1) //Insertion Using Chaining Method
                {
                    ht.clear();
                    ht.resize(90);
                    system("cls");
                    cout << "This will take a while, please wait for a moment.\n" << endl;
                    auto start = std::chrono::high_resolution_clock::now();
                    
                    
                    datasetEntryFile.open("EmailsetA.txt");
                    while(!datasetEntryFile.eof()) // Getting all the lines from the file
                    {
                        getline(datasetEntryFile, tempString); //saves the line in temporary
                        //cout << tempString << endl;
                        ht.insert(tempString);
                    }
                    datasetEntryFile.close();
                    auto end = std::chrono::high_resolution_clock::now();
                    auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);

                    cout << ht << endl;
                    cout << "Duration of insertion of email dataset A using chaining Method: " << duration.count() << " seconds" << endl;
                }
                //Searching with Dataset that can be founded
                else if (choiceSelection == 2 && ht.size() != 0)
                {
                    datasetEntryFile.open("EmailSetFound.txt");
                    cout << "Searching with a Dataset with items that can be found" << endl;
                    while(!datasetEntryFile.eof())
                    {
                        getline(datasetEntryFile, tempString); //Getting the line into a tempString
                        if (ht.retrieve(tempString))
                        {
                            cout << tempString << " can be found in Dataset A" << endl;
                        }
                        else
                        {
                            cout << tempString << " cannot be found in Dataset A" << endl;
                        }
                        tempString = ""; //Reset the string
                    }
                    datasetEntryFile.close();
                }

                //Search with Dataset that cannot be found 
                else if (choiceSelection == 3 && ht.size() != 0)
                {
                    datasetEntryFile.open("EmailSetNotFound.txt");
                    cout << "Searching with a Dataset with items that can be found" << endl;
                    while(!datasetEntryFile.eof())
                    {
                        getline(datasetEntryFile, tempString); //Getting the line into a tempString
                        if (ht.retrieve(tempString))
                        {
                            cout << tempString << " can be found in Dataset A" << endl;
                        }
                        else
                        {
                            cout << tempString << " cannot be found in Dataset A" << endl;
                        }
                        tempString = ""; //Reset the string
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
            HashTable<string> ht(90000);
            while(true)
            {
                cout << "----------------------------------------------" << endl;
                printf("\t Chaining Method - Dataset B \t\n");
                cout << "----------------------------------------------" << endl;

                cout << "Which option do you want to do?" << endl;
                printf("1. Insertion - Finding time taken\n2. Search with Email That Can be Found\n3. Search With Email That Cannot be Found\n4. Exit Chaining Method\nChoice: ");
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
                    ht.clear();
                    ht.resize(90000);
                    system("cls");
                    cout << "This will take a while, please wait for a moment.\n" << endl;
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
                    auto end = std::chrono::high_resolution_clock::now();
                    auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);

                    cout << ht << endl;
                    cout << "Duration of insertion of email dataset B using chaining Method: " << duration.count() << " seconds" << endl;
                }
                //Searching with Dataset that can be founded
                else if (choiceSelection == 2 && ht.size() != 0)
                {
                    datasetEntryFile.open("EmailSetFound.txt");
                    cout << "Searching with a Dataset with items that can be found" << endl;
                    while(!datasetEntryFile.eof())
                    {
                        getline(datasetEntryFile, tempString); //Getting the line into a tempString
                        if (ht.retrieve(tempString))
                        {
                            cout << tempString << " can be found in Dataset B" << endl;
                        }
                        else
                        {
                            cout << tempString << " can be found in Dataset B" << endl;
                        }
                        tempString = ""; //Reset the string
                    }
                    datasetEntryFile.close();
                }

                //Search with Dataset that cannot be found 
                else if (choiceSelection == 3 && ht.size() != 0)
                {
                    datasetEntryFile.open("EmailSetNotFound.txt");
                    cout << "Searching with a Dataset with items that can be found" << endl;
                    while(!datasetEntryFile.eof())
                    {
                        getline(datasetEntryFile, tempString); //Getting the line into a tempString
                        if (ht.retrieve(tempString))
                        {
                            cout << tempString << " can be found in Dataset B" << endl;
                        }
                        else
                        {
                            cout << tempString << " cannot be found in Dataset B" << endl;
                        }
                        tempString = ""; //Reset the string
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
            HashTable<string> ht(450000);
            while(true)
            {
                cout << "----------------------------------------------" << endl;
                printf("\t Chaining Method - Dataset C \t\n");
                cout << "----------------------------------------------" << endl;

                cout << "Which option do you want to do?" << endl;
                printf("1. Insertion - Finding time taken\n2. Search with Email That Can be Found\n3. Search With Email That Cannot be Found\n4. Exit Chaining Method\nChoice: ");
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
                    ht.clear();
                    ht.resize(450000);
                    system("cls");
                    cout << "This will take a while, please wait for a moment.\n" << endl;
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
                    auto end = std::chrono::high_resolution_clock::now();
                    auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);

                    cout << ht << endl;
                    cout << "Duration of insertion of email dataset C using chaining Method: " << duration.count() << " seconds" << endl;
                }
                //Searching with Dataset that can be founded
                else if (choiceSelection == 2 && ht.size() != 0)
                {
                    datasetEntryFile.open("EmailSetFound.txt");
                    cout << "Searching with a Dataset with items that can be found" << endl;
                    while(!datasetEntryFile.eof())
                    {
                        getline(datasetEntryFile, tempString); //Getting the line into a tempString
                        if (ht.retrieve(tempString))
                        {
                            cout << tempString << " can be found in Dataset C" << endl;
                        }
                        else
                        {
                            cout << tempString << " can not be found in Dataset C" << endl;
                        }
                        tempString = ""; //Reset the string
                    }
                    datasetEntryFile.close();
                }

                //Search with Dataset that cannot be found 
                else if (choiceSelection == 3 && ht.size() != 0)
                {
                    datasetEntryFile.open("EmailSetNotFound.txt");
                    cout << "Searching with a Dataset with items that can be found" << endl;
                    while(!datasetEntryFile.eof())
                    {
                        getline(datasetEntryFile, tempString); //Getting the line into a tempString
                        if (ht.retrieve(tempString))
                        {
                            cout << tempString << " can be found in Dataset C" << endl;
                        }
                        else
                        {
                            cout << tempString << " can not be found in Dataset C" << endl;
                        }
                        tempString = ""; //Reset the string
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

void linearProbing()
{
    system("cls");
    int choiceDataSet;
    string searchString;
    ifstream datasetEntryFile;

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
                    auto duration = std::chrono::duration_cast<std::chrono::seconds>(end - start);

                    datasetEntryFile.close();
                    linearHashTable->displayHashMap();
                    cout << "Duration of insertion of email dataset A using Linear Probing Method: " << duration.count() << " seconds" << endl;
                }
                else if (choiceSelection == 2)
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

                        int asciiNum = 0;
                        int index = 0;

                        for (int j = 0; j < target.length(); j++)
                        {
                            asciiNum += target[j]; 
                        }
                        
                        if (linearHashTable->get(asciiNum))
                        {
                            cout << "Target has been found at index " << linearHashTable->getIndex(asciiNum) << endl;
                        }
                        else if (!(linearHashTable->get(asciiNum)))
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
            system("cls");

            //HashTable<string> ht(150000);
            HashMap<int, string> *linearHashTable = new HashMap<int, string>(150001);
            while(true)
            {
                cout << "----------------------------------------------" << endl;
                printf("\t Linear Probing - Dataset B \t\n");
                cout << "----------------------------------------------" << endl;

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
                    auto duration = std::chrono::duration_cast<std::chrono::seconds>(end - start);

                    linearHashTable->displayHashMap();
                    datasetEntryFile.close();
                    cout << "Duration of insertion of email dataset A using Linear Probing Method: " << duration.count() << " seconds" << endl;
                }
                else if (choiceSelection == 2)
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

                        int asciiNum = 0;
                        int index = 0;

                        for (int j = 0; j < target.length(); j++)
                        {
                            asciiNum += target[j]; 
                        }
                        
                        if (linearHashTable->get(asciiNum))
                        {
                            cout << "Target has been found at index " << linearHashTable->getIndex(asciiNum) << endl;
                        }
                        else if (!(linearHashTable->get(asciiNum)))
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
            system("cls");
            //HashTable<string> ht(750000);
            HashMap<int, string> *linearHashTable = new HashMap<int, string>(750001);
            while(true)
            {
                cout << "----------------------------------------------" << endl;
                printf("\t Linear Probing - Dataset C \t\n");
                cout << "----------------------------------------------" << endl;

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
                    auto duration = std::chrono::duration_cast<std::chrono::seconds>(end - start);

                    datasetEntryFile.close();
                    linearHashTable->displayHashMap();
                    cout << "Duration of insertion of email dataset A using Linear Probing Method: " << duration.count() << " seconds" << endl;
                }
                else if (choiceSelection == 2)
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

                        int asciiNum = 0;
                        int index = 0;

                        for (int j = 0; j < target.length(); j++)
                        {
                            asciiNum += target[j]; 
                        }
                        
                        if (linearHashTable->get(asciiNum))
                        {
                            cout << "Target has been found at index " << linearHashTable->getIndex(asciiNum) << endl;
                        }
                        else if (!(linearHashTable->get(asciiNum)))
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

void avlTree()
{
    
}

void priorityQueue()
{

}
/*
void avlBst()
{
    int choiceDataSet;

    cout << "Which of the following datasets you would like to use?" << endl;
    printf("1. Dataset A\n2. Dataset B\n3. Dataset C\n");

    cin >> choiceDataSet;

	ifstream readFile;
	string tempString;

	Node *root = NULL;
    if (choiceDataSet == 1)
    {
        readFile.open("EmailsetA.txt");
    }
    else if (choiceDataSet == 2)
    {
        readFile.open("EmailsetB.txt");
    }
    else if (choiceDataSet == 3)
    {
        readFile.open("EmailsetC.txt");
    }
    else
    {
        cout << "Error - That is an invalid choice!" << endl;
    }

    auto iStart = std::chrono::system_clock::now();

    while (getline (readFile, tempString))
	{
		root = insert(root, tempString);
	}

    auto iEnd = std::chrono::system_clock::now();
	chrono::duration<double> iDuration = iEnd - iStart;
	cout<<"Insert Time: ";
	cout<<iDuration.count()<<"\n";
    //preOrder(root);
	string word;
	cout<<"Enter email be searched\n";
	cin>>word;

	auto sStart = std::chrono::system_clock::now();

	if(Search(root,word) == true)
        cout<<"Found\n";
	else
        cout<<"Not Found\n";

	auto sEnd = std::chrono::system_clock::now();
	chrono::duration<double> sDuration = sEnd - sStart;
	cout<<"Search Time: ";
	cout<<sDuration.count()<<"\n";

    readFile.close();

    /*while(!openFile.eof()) // Getting all the lines from the file
    {
        getline(openFile, tempString); //saves the line in temporary
        //cout << tempString << endl;
        root = insert(root, tempString);
    }*/

    /*
	root = insert(root, 10);
	root = insert(root, am);
	root = insert(root, 20);
	root = insert(root, 30);
	root = insert(root, 40);
	root = insert(root, 50);*/

	/* The constructed AVL Tree would be
				30
			/ \
			20 40
			/ \ \
		10 25 50

	cout << "Preorder traversal of the "
			"constructed AVL tree is \n";
	preOrder(root);

}
*/
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


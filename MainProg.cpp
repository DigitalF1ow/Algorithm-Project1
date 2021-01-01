#include <iostream>
#include <string>
#include <fstream>
#include <ctime>
#include <chrono>
#include <string>
#include "HashTable.cpp"
<<<<<<< Updated upstream
//#include "LinearProbing.cpp"

=======
#include "Bstinsertion.cpp"
>>>>>>> Stashed changes
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
<<<<<<< Updated upstream
=======

    cout << "Which of the following datasets you would like to use?" << endl;
    printf("1. Dataset A\n2. Dataset B\n3. Dataset C\n");
>>>>>>> Stashed changes

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
            HashTable<string> ht(90);
            while(true)
            {
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
                    ht.clear();
                    ht.resize(90);
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
                    auto end = std::chrono::high_resolution_clock::now();
                    auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);

                    cout << ht << endl;
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
            HashTable<string> ht(90000);
            while(true)
            {
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
                    ht.clear();
                    ht.resize(90000);
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
            HashTable<string> ht(450000);
            while(true)
            {
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
                    ht.clear();
                    ht.resize(450000);
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
    string searchString;
    ifstream datasetEntryFile;

    int choiceSelection;
    cout << "----------------------------------------" << endl;
    printf("\t Linear Probing \t\n");
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
            HashTable<string> ht(150);
            while(true)
            {
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
                    ht.clear();
                    ht.resize(150);
                    auto start = std::chrono::high_resolution_clock::now();
                    string tempString;
                    
                    datasetEntryFile.open("EmailsetA.txt");
                    while(!datasetEntryFile.eof()) // Getting all the lines from the file
                    {
                        getline(datasetEntryFile, tempString); //saves the line in temporary
                        //cout << tempString << endl;
                        ht.insertLinearProbe(tempString);
                    }
                    datasetEntryFile.close();
                    auto end = std::chrono::high_resolution_clock::now();
                    auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);

                    cout << ht << endl;
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
            HashTable<string> ht(150000);
            while(true)
            {
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
                    ht.clear();
                    ht.resize(150000);

                    auto start = std::chrono::high_resolution_clock::now();
                    string tempString;
                    
                    datasetEntryFile.open("EmailsetB.txt");
                    while(!datasetEntryFile.eof()) // Getting all the lines from the file
                    {
                        getline(datasetEntryFile, tempString); //saves the line in temporary
                        //cout << tempString << endl;
                        ht.insertLinearProbe(tempString);
                    }
                    datasetEntryFile.close();
                    auto end = std::chrono::high_resolution_clock::now();
                    auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);

                    cout << ht << endl;
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
            HashTable<string> ht(750000);
            while(true)
            {
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
                    ht.clear();
                    ht.resize(750000);

                    auto start = std::chrono::high_resolution_clock::now();
                    string tempString;
                    
                    datasetEntryFile.open("EmailsetC.txt");
                    while(!datasetEntryFile.eof()) // Getting all the lines from the file
                    {
                        getline(datasetEntryFile, tempString); //saves the line in temporary
                        //cout << tempString << endl;
                        ht.insertLinearProbe(tempString);
                    }
                    datasetEntryFile.close();

                    auto end = std::chrono::high_resolution_clock::now();
                    auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);

                    cout << ht << endl;
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
<<<<<<< Updated upstream
}

void avlTree()
{
    
}

void priorityQueue()
{
=======

>>>>>>> Stashed changes

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

<<<<<<< Updated upstream

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
=======
    if (choice == 1)
    {
        chainingMethod();
    }
    else if (choice == 2)
    {
    }
    else if (choice == 3)
    {
        //avlBst();
    }
    else if (choice == 4)
    {

>>>>>>> Stashed changes
    }
    return 0;
    
}


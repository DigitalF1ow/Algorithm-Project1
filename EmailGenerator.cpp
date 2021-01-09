#include <iostream>
#include <string>
#include <cstdlib>
#include <fstream>
#include <ctime>
#include <chrono>

using namespace std;

int main()
{
    cout << "---------------------------------" << endl;
    cout << "Generating Random Email Addresses" << endl;
    cout << "---------------------------------\n" << endl;

    static const char alphanum [] = {"ABCDEFGHIJKLMNOPQRSTUVWXYZ" "abcdefghijklmnopqrstuvwxyz" "1234567890"};
    string emaildom [] = {"net","org","my"};

    int sizeA = 100;
    int sizeB = 100000;
    int sizeC = 500000;
    int searchSize = 10;

    string *setAEmail  = new string[sizeA];
    string *setBEmail  = new string[sizeB];
    string *setCEmail  = new string[sizeC];
    string *setNotFound = new string[searchSize];

    //Create a loop for the number of letters

    string generatedEmail;
    srand(time(NULL));

    //Creating a loop to insert the randomly generated emails into the txt file
    auto start = std::chrono::high_resolution_clock::now();

    for (int i = 0; i < sizeC; i++)
    {
        for (int i = 0; i < 5; i++)
        {
            generatedEmail += alphanum[rand() %(sizeof(alphanum) - 1)];
        }

        generatedEmail += ".";

        for (int i = 0; i < 4; i++)
        {
            generatedEmail += alphanum[rand() %(sizeof(alphanum) - 1)];
        }

        generatedEmail += "@";

        for (int i = 0; i < 5; i++)
        {
            generatedEmail += alphanum[rand() %(sizeof(alphanum) - 1)];
        }

        generatedEmail += ".";
        generatedEmail += emaildom[rand() % 3];

        if (i < sizeA)
        {
            setAEmail[i] = generatedEmail;
        }
        if (i < sizeB)
        {
            setBEmail[i] = generatedEmail;
        }
        if (i < sizeC)
        {
            setCEmail[i] = generatedEmail;
        }
        generatedEmail = "";
        
    }

    //Generating Email Address That cannot be found
    for (int i = 0; i < searchSize; i++)
    {
        for (int i = 0; i < 5; i++)
        {
            generatedEmail += alphanum[rand() %(sizeof(alphanum) - 1)];
        }

        generatedEmail += ".";

        for (int i = 0; i < 4; i++)
        {
            generatedEmail += alphanum[rand() %(sizeof(alphanum) - 1)];
        }

        generatedEmail += "@";

        for (int i = 0; i < 5; i++)
        {
            generatedEmail += alphanum[rand() %(sizeof(alphanum) - 1)];
        }

        generatedEmail += ".";
        generatedEmail += emaildom[rand() % 3];

        setNotFound[i] = generatedEmail;

        generatedEmail = "";
    } 

    ofstream writerFile;

    writerFile.open("EmailSetA.txt");
    cout << "Creating a set of emails for Set A" << endl;

    //Adding in all of the email addresses for each of the following datasets
    for (int i = 0; i < sizeA; i++)
    {
        //printf("Generated Email A %d: %s \n", i + 1, setAEmail[i].c_str()); --> Testing Purposes

        //Purpose for if else, avoid the extra line in the output txt file
        if (i == sizeA - 1)
        {
            writerFile << setAEmail[i].c_str();
        }
        else
        {
            writerFile << setAEmail[i].c_str() << endl;
        }
         
        
    }
    writerFile.close();
    cout << "Creating a set of emails for Set B" << endl;
    writerFile.open("EmailSetB.txt");

    for (int i = 0; i < sizeB; i++)
    {
        //printf("Generated Email B %d: %s \n", i + 1, setBEmail[i].c_str()); --> Testing Purposes
        
        if (i == sizeB - 1)
        {
            writerFile << setBEmail[i].c_str();
        }
        else
        {
            writerFile << setBEmail[i].c_str() << endl;
        }
    }
    writerFile.close();
    cout << "Creating a set of emails for Set C" << endl;
    writerFile.open("EmailSetC.txt");
    for (int i = 0; i < sizeC; i++)
    {
        //printf("Generated Email C %d: %s \n", i + 1, setCEmail[i].c_str()); --> Testing Purposes
        

        if (i == sizeC - 1)
        {
            writerFile << setCEmail[i].c_str();
        }
        else
        {
            writerFile << setCEmail[i].c_str() << endl;
        } 
    }
    writerFile.close();

    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::seconds>(end - start);

    //Generating Email For Found
    writerFile.open("EmailSetFound.txt");
    cout << "Creating a set of emails for Email Set Found" << endl;
    for (int i = 0; i < searchSize; i++)
    {
        if (i == searchSize - 1)
        {
            writerFile << setCEmail[i].c_str();
        }
        else
        {
            writerFile << setCEmail[i].c_str() << endl;
        } 
    }
    writerFile.close();

    //Generating Email Not Found and exporting to a txt file
    writerFile.open("EmailSetNotFound.txt");
    cout << "Creating a set of emails for Email Set Not Found" << endl;
    for (int i = 0; i < searchSize; i++)
    {
        if (i == searchSize - 1)
        {
            writerFile << setNotFound[i].c_str();
        }
        else
        {
            writerFile << setNotFound[i].c_str() << endl; 
        }
        
    }
    writerFile.close();
    
    cout << "Duration of creation of email datasets: " << duration.count() << " seconds" << endl;
}

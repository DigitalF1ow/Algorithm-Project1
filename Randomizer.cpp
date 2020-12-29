#include <iostream>
#include <string>
#include <cstdlib>
#include <fstream>
#include <ctime>
#include <chrono>

using namespace std;

int main()
{
    cout << "Hello World" << endl;
    cout << "We are going to randomize the emails into each of the following formats:" << endl;

    static const char alphanum [] = {"ABCDEFGHIJKLMNOPQRSTUVWXYZ" "abcdefghijklmnopqrstuvwxyz" "1234567890"};
    string emaildom [] = {"net","org","my"};

    int sizeA = 100;
    int sizeB = 100000;
    int sizeC = 500000;

    int totalSize = sizeA + sizeB + sizeC;

    string *setAEmail  = new string[sizeA];
    string *setBEmail  = new string[sizeB];
    string *setCEmail  = new string[sizeC];

    cout << sizeA << endl;
    
    //Create a loop for the number of letters
    
    string generatedEmail;
    srand(time(NULL));
    
    //Creating a loop to insert the randomly generated emails into the txt file
    auto start = std::chrono::high_resolution_clock::now();

    for (int i = 0; i < totalSize; i++)
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

    
    for (int i = 0; i < sizeA; i++)
    {
        printf("Generated Email A %d: %s \n", i + 1, setAEmail[i].c_str());
        //cout << "Generated Email A %s: " << setAEmail[i] << endl;
    }
    
    for (int i = 0; i < sizeB; i++)
    {
        printf("Generated Email B %d: %s \n", i + 1, setBEmail[i].c_str());
        //cout << "Generated Email B %s: " << setAEmail[i] << endl;
    }

    for (int i = 0; i < sizeC; i++)
    {
        printf("Generated Email C %d: %s \n", i + 1, setCEmail[i].c_str());
        //cout << "Generated Email B %s: " << setAEmail[i] << endl;
    }
    
    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::seconds>(end - start);
    cout << "Duration of insertion of emails: " << duration.count() << " seconds" << endl;
}
#include <iostream>
#include <string>
#include <cstdlib>
#include <fstream>
#include <ctime>

using namespace std;

string getEmail() 
{

}

int main()
{
    cout << "Hello World" << endl;
    cout << "We are going to randomize the emails into each of the following formats:" << endl;

    static const char alphanum [] = {"ABCDEFGHIJKLMNOPQRSTUVWXYZ" "abcdefghijklmnopqrstuvwxyz" "1234567890"};
    string emaildom [] = {"net","org","my"};

    int sizeA = 100;
    int sizeB = 100000;
    int sizeC = 500000;

    string *setAEmail  = new string[sizeA];
    string *setBEmail  = new string[sizeB];
    string *setCEmail  = new string[sizeC];
    
    //Create a loop for the number of letters
    string generatedEmail;
    srand(time(NULL));
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
    cout << "Generated Email: " << generatedEmail << endl;

    cout << sizeof(setBEmail);
    /*
    //Creating a loop to insert the randomly generated emails into the txt file
    
    for (int i = 0; i < (sizeA + sizeB + sizeC); i++)
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

        if (sizeof(setAEmail) < sizeA)
        {
            setAEmail 
        }
        if (sizeof(setBEmail) < sizeB)
        {

        }
        if (sizeof(setCEmail) < sizeC)
        {

        }
    }
    */
}
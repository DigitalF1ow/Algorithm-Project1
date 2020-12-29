#include <iostream>
#include <string>
#include <cstdlib>
#include <interator>

using namespace std;

string getEmail() 
{

}

int main()
{
    cout << "Hello World" << endl;
    cout << "We are going to randomize the emails into each of the following formats:" << endl;

    string alphanum [] = {"ABCDEFGHIJKLMNOPQRSTUVWXYZ","abcdefghijklmnopqrstuvwxyz","1234567890"};
    string emaildom [] = {"net", "org", "my"};

    int sizeA = 100;
    int sizeB = 100000;
    int sizeC = 500000;

    string* setAEmail [] = new string[sizeA];
    string* setBEmail [] = new string[sizeB];
    string* setCEmail [] = new string[sizeC];

    
}
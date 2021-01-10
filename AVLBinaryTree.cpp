#include<bits/stdc++.h>
#include <fstream>
using namespace std;

// An AVL tree node
class Node
{
	public:
	string key;
	Node *left;
	Node *right;
	int height;
};

// A utility function to get maximum
// of two integers
string max(string a, string b);

// A utility function to get the
// height of the tree
int height(Node *N)
{
	if (N == NULL)
		return 0;
	return N->height;
}

// A utility function to get maximum
// of two integers
string max(string a, string b)
{
	return (a > b)? a : b;
}

/* Helper function that allocates a
new node with the given key and
NULL left and right pointers. */
Node* newNode(string key)
{
	Node* node = new Node();
	node->key = key;
	node->left = NULL;
	node->right = NULL;
	node->height = 1; // new node is initially
					// added at leaf
	return(node);
}

// A utility function to right
// rotate subtree rooted with y
// See the diagram given above.
Node *rightRotate(Node *y)
{
	Node *x = y->left;
	Node *T2 = x->right;

	// Perform rotation
	x->right = y;
	y->left = T2;

	// Update heights
	y->height = max(height(y->left),
					height(y->right)) + 1;
	x->height = max(height(x->left),
					height(x->right)) + 1;

	// Return new root
	return x;
}

// A utility function to left
// rotate subtree rooted with x
// See the diagram given above.
Node *leftRotate(Node *x)
{
	Node *y = x->right;
	Node *T2 = y->left;

	// Perform rotation
	y->left = x;
	x->right = T2;

	// Update heights
	x->height = max(height(x->left),
					height(x->right)) + 1;
	y->height = max(height(y->left),
					height(y->right)) + 1;

	// Return new root
	return y;
}

// Get Balance factor of node N
int getBalance(Node *N)
{
	if (N == NULL)
		return 0;
	return height(N->left) - height(N->right);
}

// Recursive function to insert a key
// in the subtree rooted with node and
// returns the new root of the subtree.
Node* insert(Node* node, string key)
{
	/* 1. Perform the normal BST insertion */
	if (node == NULL)
		return(newNode(key));

	if (key < node->key)
		node->left = insert(node->left, key);
	else if (key > node->key)
		node->right = insert(node->right, key);
	else // Equal keys are not allowed in BST
		return node;

	/* 2. Update height of this ancestor node */
	node->height = 1 + max(height(node->left),
						height(node->right));

	/* 3. Get the balance factor of this ancestor
		node to check whether this node became
		unbalanced */
	int balance = getBalance(node);

	// If this node becomes unbalanced, then
	// there are 4 cases

	// Left Left Case
	if (balance > 1 && key < node->left->key)
		return rightRotate(node);

	// Right Right Case
	if (balance < -1 && key > node->right->key)
		return leftRotate(node);

	// Left Right Case
	if (balance > 1 && key > node->left->key)
	{
		node->left = leftRotate(node->left);
		return rightRotate(node);
	}

	// Right Left Case
	if (balance < -1 && key < node->right->key)
	{
		node->right = rightRotate(node->right);
		return leftRotate(node);
	}

	/* return the (unchanged) node pointer */
	return node;
}

// A utility function to print preorder
// traversal of the tree.
// The function also prints height
// of every node
void preOrder(Node *root)
{
	if(root != NULL)
	{
		cout << root->key << "-->"<< " ";
		preOrder(root->left);
		preOrder(root->right);
	}
}

//=====================================================================================================================================================
//To search an element in BST, returns true if element is found
bool Search(Node* root,string key) 
{
	if(root == NULL) {
		return false;
	}
	else if(root->key == key) {
		return true;
	}
	else if(key <= root->key) {
		return Search(root->left,key);
	}
	else {
		return Search(root->right,key);
	}
}

// Driver Code

int main()
{
	system("cls");
	ifstream readFile;
	string tempString;

	double avgTime;
	double totalTime;

	Node *root = NULL;

	vector<string> datasetSelected;
	vector<string> processSelected;
	vector<string> searchProcess;

	vector<double> avgTimeTaken;
	vector<double> avgTimeTakenX;
	vector<double> timeDuration;

    int setChoice;
	while(true)
	{
		cout << "----------------------------------------------" << endl;
		printf("\t      AVL Binary Search Tree \t\n");
		cout << "----------------------------------------------" << endl;
		cout << "Which of the following datasets you would like to use?" << endl;
		printf("1. Dataset A\n2. Dataset B\n3. Dataset C\n4. Display Tree in Traversal\n5. Time Duration History\n6. Quit \nChoice:");

		cin >> setChoice;

		while(cin.fail())
		{
			cout << "Please enter a valid number, not a letter/word"<< endl;
			cin.clear();
			cin.ignore();
			printf("Choice:");
			cin >> setChoice;
		}

		if (setChoice == 1)
		{
			readFile.open("EmailsetA.txt");
			datasetSelected.push_back("Dataset A"); //For Insertion Process
		}
		else if (setChoice == 2)
		{
			readFile.open("EmailsetB.txt");
			datasetSelected.push_back("Dataset B"); //For Insertion Process
		}
		else if (setChoice == 3)
		{
			readFile.open("EmailsetC.txt");
			datasetSelected.push_back("Dataset C"); //For Insertion Process
		}
		
		
		else if (setChoice == 4)
		{
			if (root == NULL)
			{
				system("cls"); //Clear the command prompt
				cout << "There is no dataset being inserted yet. Please make a process beforehand" << endl;
			}
			else
			{
				system("cls");
				cout << "Pre-order Traversal" << endl;
				preOrder(root);
				cout << "" << endl;
			}
			
		}
		else if (setChoice == 5)
		{
			//readFile.open("EmailsetC.txt");
			//Time Duration History
			if (timeDuration.empty() && datasetSelected.empty() && processSelected.empty())
			{
				system("cls"); //Clear the command prompt
				cout << "There is no dataset being inserted yet. Please make a process beforehand" << endl;
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
					cout << timeDuration[i] << endl;
					cout << "Average Time Taken with Search Data that can be founded\n"<< avgTimeTaken[i] << " seconds" << endl;
					cout << "Average Time Taken with Search Data that cannot be founded\n"<< avgTimeTakenX[i] << " seconds\n" << endl;
				}
			}
		}
		else if (setChoice == 6)
		{
			return 0;
		}
		else
		{
			cout << "Error - That is an invalid choice!" << endl;
		}

		//Check if ifstream opens any file
		if (readFile.is_open())
		{
			
			system("cls"); //Clear the command prompt

			cout << "-----------------------------------" << endl;
			printf("Insertion Process of AVL Binary Tree\n");
			cout << "-----------------------------------" << endl;

			processSelected.push_back("Insertion Process AVL Binary Tree");

			auto iStart = std::chrono::high_resolution_clock::now();

			//Looping till there is no more lines
			while (getline(readFile, tempString))
			{
				root = insert(root, tempString);
			}

			auto iEnd = std::chrono::high_resolution_clock::now();

			auto iDuration = std::chrono::duration_cast<chrono::nanoseconds>(iEnd - iStart);

			//Inserting Time Duration to Record History
			timeDuration.push_back(iDuration.count() * 1e-9);
			readFile.close();
			cout<<"Insert Time: ";
			cout << iDuration.count() * 1e-9 <<" seconds\n\n";

			ifstream searcherFile;
			string word;

			cout << "--------------------------------" << endl;
			printf("Search Process of AVL Binary Tree\n");
			printf("  Search Data That Can Be Found  \n");
			cout << "--------------------------------" << endl;

			searcherFile.open("EmailSetFound.txt");
			//preOrder(root);

			searchProcess.push_back("Search Process - Search Data That Can Be Found");
			
			//Searching Process
			while(!searcherFile.eof())
			{
				auto sStart = std::chrono::high_resolution_clock::now();
				getline(searcherFile, word);
				if(Search(root,word) == true)
				{
					
					cout << word <<" has been found\n";
					auto sEnd = std::chrono::high_resolution_clock::now();
					auto sDuration = std::chrono::duration_cast<chrono::nanoseconds>(sEnd - sStart);
					cout << "Time Taken: " << sDuration.count() * 1e-9 << " seconds\n"<< endl;
					totalTime += sDuration.count() * 1e-9;
				}
				else
				{
					
					cout << word <<"cannot found\n";
					auto sEnd = std::chrono::high_resolution_clock::now();
					auto sDuration = std::chrono::duration_cast<chrono::nanoseconds>(sEnd - sStart);
					cout << "Time Taken: " << sDuration.count() * 1e-9 << " seconds\n"<< endl;
					totalTime += sDuration.count() * 1e-9;
				}
				word = "";
			}
			searcherFile.close();
			avgTime = totalTime/10;
			avgTimeTaken.push_back(avgTime);

			cout << "Average Search Time with Search Data Can Be Founded: ";
			cout << avgTime << " seconds\n";

			totalTime = 0;
			avgTime = 0;

			cout << "---------------------------------" << endl;
			printf("Search Process of AVL Binary Tree\n");
			printf(" Search Data That Cannot Be Found\n");
			cout << "---------------------------------" << endl;

			searchProcess.push_back("Search Process - Search Data That Cannot Be Found");

			searcherFile.open("EmailSetNotFound.txt");

			while(!searcherFile.eof())
			{
				auto sStart = std::chrono::high_resolution_clock::now();
				getline(searcherFile, word);
				if(Search(root,word) == true)
				{
					
					cout << word <<" has been found\n";
					auto sEnd = std::chrono::high_resolution_clock::now();
					auto sDuration = std::chrono::duration_cast<chrono::nanoseconds>(sEnd - sStart);
					cout << "Time Taken: " <<sDuration.count() * 1e-9 << " seconds\n"<< endl;
					totalTime += sDuration.count() * 1e-9;
				}
				else
				{
					
					cout << word <<" cannot be found\n";
					auto sEnd = std::chrono::high_resolution_clock::now();
					auto sDuration = std::chrono::duration_cast<chrono::nanoseconds>(sEnd - sStart);
					cout << "Time Taken: " << fixed << setprecision(9) << sDuration.count() * 1e-9 << " seconds\n"<< endl;
					totalTime += sDuration.count() * 1e-9;
				}
				word = "";
			}
			searcherFile.close();

			avgTime = totalTime/10;
			avgTimeTakenX.push_back(avgTime);

			cout << "Average Search Time with Search Data Cannot Be Founded: ";
			cout << avgTime << " seconds\n";

			readFile.close();

			totalTime = 0;
			avgTime = 0;
		}

	}
    return 0;
}

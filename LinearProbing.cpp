#include <iostream>
#include <fstream>

using namespace std;

//template for the generic types
template<typename K, typename V>

//HashNode class for key-value pair
class HashNode
{
    public:
    V value;
    K key;

    //Concstructor for HashNode class
    HashNode(K key, V value)
    {
        this-> key = key;
        this -> value = value;
    }
};

//template for the generic types

template <typename K, typename V>
//HashMap
class HashMap 
{
    HashNode<K, V> **array;
    int capacity;
    //size of Hash Tables
    int size;
    int collisions;
    //Dummy node 
    HashNode<K, V> *dummy;
    public:
    HashMap(int capacity)
    {
        //Initialize the capacity of the hash array
        this-> capacity = capacity;
        size = 0;
        collisions = 0;
        array = new HashNode<K, V> *[capacity];

        //Initialize the elements of array as NULL
        for(int i=0 ; i < capacity ; i++)
            array[i] = NULL;

        //Dummy Node with value and key -1
        dummy = new HashNode<K,V> (-1,"");
    }
    //Hash function to find index for key
    int hashfunction(K key)
    {
        int index = key % capacity;
        
        return index;
    }
    void clear()
    {
        //Reinitialize the elements of array as NULL
        for(int i=0 ; i < capacity ; i++)
            array[i] = NULL;

        //dummy = new HashNode<K,V> (-1,"");
        collisions = 0;
        size = 0;
    }
    //Can insert any data type of node
    void insert(K key, V value)
    {
        HashNode<K,V> *tempNode = new HashNode<K,V>(key, value);

        //Finding hash index for
        int hashIndex = hashfunction(key);

        while(true)
        {
            if(array[hashIndex] != NULL && array[hashIndex] -> key != -1)
            {
                collisions++;
                hashIndex++;
                hashIndex %= capacity;
            }
            else
            { 
                //Capacity is already full
                break;
            }
            
        }
        
        //if a new node is inserted, increase the size, based from the constructor made -- Maybe need? Capacity got though
        if (array[hashIndex] == NULL || array[hashIndex]->key  == -1)
        {
            size++;
        }
        array[hashIndex] = tempNode;
    }
    //Function to search for the value for a given key. 
    //needs to be converted to a ascii value before calling function
    //Returns true or false
    bool get(int key)
    {
        int hashIndex = hashfunction(key);
        int count = 0;

        //finding the node with the key
        while (array[hashIndex] != NULL)
        {    
            int count = 0;
            if (count++ > capacity) //avoiding infinite looping
                return false;
            
            //if the node is found, return the value for a given key
            if (array[hashIndex] -> key == key)
                return true;
            hashIndex++;
            hashIndex %= capacity;
        
        }

        //If it is not found, return null
        return false;
    }
    //Gets the index of where the key is. Does not affect the time taken if put the main program correctly
    //Returns Integer, Only used it when you found the key oredy
    int getIndex(int key)
    {   
        int hashIndex = hashfunction(key);

        //finding the node with the key
        while (array[hashIndex] != NULL)
        {                
            //if the node is found, return the value for a given key
            if (array[hashIndex] -> key == key)
                return hashIndex;
            hashIndex++;
            hashIndex %= capacity;
        }

        //If it is not found, return 0
        return 0;
    }
    int getSize()
    {
        return capacity;
    }
    void displayHashMap()
    {
        //ofstream file;
        //file.open("output.txt");
        for (int i = 0; i < capacity; i++)
        {
            if(array[i] != NULL && array[i]->key != -1 && array[i]-> key != 0)
            {
                cout << i << " = " << array[i] -> value << endl;
                //file << (array[i] -> value).c_str() << endl;
            }            
        }
        //file.close();

        printf("\nNumber of Collisions detected: %d\n\n", collisions);
    }
};

#include <iostream>

using namespace std;

//template for the generic types
template<typename K, typename V>

//HashNode class for
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

    //Can insert any data type of node
    void insert(K key, V value)
    {
        HashNode<K,V> *tempNode = new HashNode<K,V>(key, value);

        //Finding hash index for
        int hashIndex = hashfunction(key);

        //Finding next free space
        while(array[hashIndex] != NULL && array[hashIndex] -> key != -1)
        {   
            collisions++;
            hashIndex++;
            hashIndex %= capacity;
        }

        //if a new node is inserted, increase the size, based from the constructor made
        if (array[hashIndex] == NULL || array[hashIndex]->key  == -1)
        {
            size++;
        }
        array[hashIndex] = tempNode;
    }

    //Function to search for the value for a given key 
    int get(int key)
    {
        int hashIndex = hashfunction(key);
        int count = 0;
        int arrayIndex = 0;

        //finding the node with the key
        /*
        int i;
        while (i < size)
        */
        while (array[hashIndex] != NULL)
        {    
            int count = 0;
            if (count++ > capacity) //avoiding infinite looping
                return NULL;
            
            //if the node is found, return the value for a given key
            if (array[hashIndex] -> key == key)
                return array[hashIndex] -> key;
            
            hashIndex++;
            hashIndex %= capacity;
            
        }

        //If it is not found, return null
        return NULL;
    }

    void displayHashMap()
    {
        for (int i = 0; i < capacity; i++)
        {
            if(array[i] != NULL && array[i]->key != -1 && array[i]-> key != 0)
                cout << "Index " << i << ": " << array[i] -> key << " Value = " << array[i] -> value << endl;
            else
                cout << "Index " << i << ": " << -1 << " Value = " << "-1" << endl;
        }   

        printf("\nNumber of Collisions detected: %d\nSize of Array: %d\n", collisions, size);
    }
};

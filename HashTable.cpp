#include <vector>
#include "LinkedList.cpp" // available at MMLS.

template <typename T>
class HashTable {
  vector< LinkedList<T> > table;
  int hashfunction (string hashitem) 
  { 
    // hash function
    int asciiNum = 0;
    int index = 0;

    for (int i = 0; i < hashitem.length(); i++)
    {
      asciiNum += hashitem[i]; 
    }

    index = asciiNum % table.size();
    
    return index;
  }
  //Public Constructor
 public:
  HashTable (int size) {
    table.resize (size); // resize vector to support size elements.
  }
  //Destructor
  ~HashTable() {
    for (int i = 0; i < table.size(); i++)
      table[i].makeEmpty();
  }

  //Getting the size of the hash table
  int size() 
  {
    return table.size();
  }

  void clear()
  {
    table.clear();
  }

  void resize(int intResize)
  {
    table.resize(intResize);
  }

  //Insert a new key into the hash table using Chaining Method
  void insert (T newItem) {
    int location = hashfunction(newItem);
      table[location].insertFront(newItem);
  }
  
  //Getting the key from the hashtable
  bool retrieve (T & target) {
    int location = hashfunction(target);
    if(!table[location].find(target))
        return false;
    return true;
  }

  friend ostream& operator<< (ostream& os, HashTable<T>& ht) {
    for (int i = 0; i < ht.size(); i++)
      os << i << " = " << ht.table[i] << endl;
    return os;
  }
};

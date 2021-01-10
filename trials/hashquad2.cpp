#include <iostream>
#include "hashquad2.hpp"

hashTable::hashTable(int size){
   tableSize = size;
   table = new list<int>[tableSize];
}

int hashTable::hashFunction(int key){
   return key%tableSize;
}

void hashTable::insertIntoTable(int insertValue){
   table[hashFunction(insertValue)].push_back(insertValue);
}

bool hashTable::searchTable(int searchValue){
   int key = hashFunction(searchValue);

   list<int>::iterator i;

   for(i = table[key].begin(); i != table[key].end(); i++){
      if(*i == searchValue){
         return true;
      }
      continue;
   }
   return false;
}

void hashTable::printTable(){
   for(int i = 0; i < tableSize; i++){
      cout << "index " << i << " : ";

      for(int j : table[i]){
         cout << j << " => ";
      }
      cout << endl;
   }
}

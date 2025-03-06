#include <cstdlib>
#include <iostream>
#include <cmath>
#include <bits/stdc++.h>
#include "hashtable.hpp"
#include "linkedlist.hpp"
using namespace std;
 
class HTSepChain : public HashTable {
    vector<LinkedList*> hashTable;
    int N;
public:
    HTSepChain(int table_size) {
        N = table_size;
        for (int i = 0; i < N; ++i) {
            hashTable.push_back(new LinkedList());
        }
    }
    int hash_code(int key) {
        return key;
    }
    int compress(int code) {
        return code % N;
    }
    int insert(int key) {
        if (exists(key)) {
            throw logic_error("Already added key " + to_string(key));
        }
        int index = this->hashfn(key);
        hashTable[index]->add(key);
        return hashTable[index]->getSize();
    }
    int search(int key) {
        for (int i = 0; i < hashTable.size(); ++i) {
            if (hashTable[i]->exists(key)) {
                return hashTable[i]->getSize();
            }
        }   
        return -1;
    }
    int remove(int key) {
        for (int i = 0; i < N; ++i) {
            if (hashTable[i]->exists(key)) {
                hashTable[i]->remove(key);
                return hashTable[i]->getSize();
            }
        }
        return -1;
    }
    bool exists(int elem) {
        for (int i = 0; i < N; ++i) {
            if (hashTable[i]->exists(elem))
                return true;
        }
        return false;
    }
    void print() {
        for (int i = 0; i < N; ++i) {
            cout << i << '\t';
            hashTable[i]->print();
            cout << endl;
        }
        cout << endl;
    }
};
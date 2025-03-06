#include <cstdlib>
#include <iostream>
#include "hashtable.hpp"
using namespace std;

template <typename K>
class HTLinear : public HashTable<K> {
    K* table;
    int N;
    int count;

    int hash_code(K key) {
        return key;
    }

    int compress(int code) {
        return ((59 * code + 17) % 509) % this->N;
    }

public:
    HTLinear<K>(int N) {
        this->N = N;
        this->count = 0;
        this->table = new K[N];
        for (int i = 0; i < N; i++) {
            table[i] = 0; // Initialize all cells to 0
        }
    }

    int insert(K key) {
        if (count >= this->N) {
            throw logic_error("Table already full");
        }
        if (search(key) >= 0) {
            throw logic_error("Already added key " + to_string(key));
        }

        int hash = this->hashfn(key);
        int ctr = 0;
        while (true) {
            if (this->table[hash] <= 0) {
                this->table[hash] = key;
                count++;
                return ctr;
            }
            hash = (hash + 1) % this->N;
            ctr++;
        }
    }

    int search(K key) {
        int hash = this->hashfn(key);
        int orig_hash = hash;
        int ctr = 0;
        while (true) {
            if (this->table[hash] == key) {
                return ctr;
            } else if (this->table[hash] == 0) {
                return -1;
            }
            hash = (hash + 1) % this->N;
            ctr++;

            if (hash == orig_hash) {
                return -1;
            }
        }
    }

    int remove(K key) {
        int hash = this->hashfn(key);
        int orig_hash = hash;
        int ctr = 0;
        while (true) {
            if (this->table[hash] == key) {
                this->table[hash] = -1; // Mark as deleted
                count--;
                return ctr;
            } else if (this->table[hash] == 0) {
                return -1;
            }
            hash = (hash + 1) % this->N;
            ctr++;

            if (hash == orig_hash) {
                return -1;
            }
        }
    }

    void print() {
        for (int i = 0; i < N; i++) {
            cout << i << "\t";
        }
        cout << "\n";

        for (int i = 0; i < N; i++) {
            cout << (table[i] == -1 ? 0 : table[i]) << "\t";
        }
        cout << "\n";
    }
};
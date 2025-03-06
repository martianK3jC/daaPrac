#include <cstdlib>
#include <iostream>
using namespace std;

class HashTable{
	public:
		virtual int hash_code(int key) = 0;
		virtual int compress(int code) = 0;
		virtual int insert(int key) = 0;
		virtual int search(int key) = 0;
		virtual int remove(int key) = 0;
		virtual void print() = 0;
		
		int hashfn(int key){
			return compress(hash_code(key));
		}
};
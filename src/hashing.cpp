//Demopnstrates a HashTable and operations.

#include <optional>
#include <iostream>
#include <vector>
#include "Sequence/Sequence.h"
#include <sstream>

using namespace std;

/**
 * TODO
 * Create a hash entry class with an vector of sequences
 * Consider entering the data fields for the airport here.
 */
class HashEntry {
private:
    int key;
    int value;

    /**
     * TODO
     * May add remove, add, entry, get, and output sequence methods here.
     * Constructor
     */
public:
    HashEntry(int key, int value) {
        this->key = key;
        this->value = value;

    }


    int getKey() {
        return key;
    }

    int getValue() {
        return value;
    }
};

const int TABLE_SIZE = 128;

class HashMap {
private:
//    HashEntry **table;
    //Verify data type of sequence.
    vector<Sequence<HashEntry>> list;
    void push_back(Sequence<HashEntry>){}
public:
    HashMap() {
        Sequence<HashEntry> sequence;
        list.push_back(sequence);
        for (int i = 0; i < TABLE_SIZE; i++)
            table[i] = NULL;
    }

    int get(int key) {
        int hash = (key % TABLE_SIZE);
        while (table[hash] != NULL && table[hash]->getKey() != key)
            hash = (hash + 1) % TABLE_SIZE;
        if (table[hash] == NULL)
            return -1;
        else
            return table[hash]->getValue();
    }

    void put(int key, int value) {
        int hash = (key % TABLE_SIZE);
        while (table[hash] != NULL && table[hash]->getKey() != key)
            hash = (hash + 1) % TABLE_SIZE;
        if (table[hash] != NULL)
            delete table[hash];
        table[hash] = new HashEntry(key, value);
    }
    /**
     * TODO
     * iterate over the list.
     * For each sequence at an index, input all entries into a string stream.
     * output the string stream into a .txt file.
     */
//    void outputHashMap(){
//        std::stringstream ss;
//        for (int i =0; i< TABLE_SIZE; i++)
//        {
//            ss << table[i];
//            //output the entry to the file.
//        }
//       // may need to do final output to file
//
//
//    }

    ~HashMap() {
        //delete the table.
        for (int i = 0; i < TABLE_SIZE; i++)
            if (table[i] != NULL)
                delete table[i];
        delete[] table;
    }
};

int main() {
    HashMap hm;
    hm.put(3, 23);
    hm.put(5, 2377);
    hm.put(9, 263);
    cout << "Value of key = 3, is " << hm.get(3) << endl;

    /** Output the map */

    /** How many records are in this map data structure?*/

    /** Is there a record for key "YWG" ?*/

    /** Is there a record for key "CMB" ?*/

    /**Remove record with key "HND" ?*/

    /** How many records are in this map data structure?*/

    /** Output the map */

//    hm.put(3, 23);
//    hm.put(5, 2377);
//    hm.put(9, 263);
//    cout << "Value of key = 3, is " << hm.get(3) << endl;
//    hm.put(12, 230);
//    cout << "override an existing entry of (3, 23) with (3,123)" << endl;
//    hm.put(3, 123);
//    cout << "New value of key = 3, is " << hm.get(3) << endl;
}


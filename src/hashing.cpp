//Demopnstrates a HashTable and operations.

#include <optional>
#include <iostream>
#include <fstream>
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
    std::string code;
    std::string name;
    std::string city;
    std::string country;
    int latDegree;
    int latMin;
    int latSec;
    std::string latDir;
    int longMin;
    int longSec;
    std::string longDir;
    int altitude;



    /**
     * TODO
     * May add remove, add, entry, get, and output sequence methods here.
     * Constructor
     */
public:
    HashEntry(int key, int value) {
        this->latDegree = key;
        this->latMin = value;

    }

    const string &getCode() const {
        return code;
    }

    const string &getName() const {
        return name;
    }

    const string &getCity() const {
        return city;
    }

    const string &getCountry() const {
        return country;
    }

    int getLatSec() const {
        return latSec;
    }

    const string &getLatDir() const {
        return latDir;
    }

    int getLongMin() const {
        return longMin;
    }

    int getLongSec() const {
        return longSec;
    }

    const string &getLongDir() const {
        return longDir;
    }

    int getAltitude() const {
        return altitude;
    }


    int getLatDegree() {
        return latDegree;
    }

    int getLatMin() {
        return latMin;
    }
};

const int TABLE_SIZE = 128;

class HashMap {
private:
//    HashEntry **table;
    //Verify data type of sequence.
    Sequence<HashEntry> entry;
    vector<Sequence<HashEntry>> table;

public:
    /**TODO
     * Verify Constructor
     */
    HashMap() = default;

    /**
     *Traverse the vector for the hash.
     * Traverse the sequence for the specified code.
     * If a hash entry with the specified code is found, return the hash entry
     * otherwise, return -1.
     * @param code
     * @return
     */
    optional<HashEntry> get(std::string code) {
        int hash = getHash(code);
        for (int i = 0; i < table[hash].length(); i++) {
            if (table[hash].entry(i)->getCode() == code)
                return table[hash].entry(i);
        }
        //Will this be the proper return?
        return nullopt;
    }

    /**
     *
     * @param code
     * @param HashEntry entry
     * Traverse the vector using the hash.
     * At the specified sequence, use the add fucntion to add the Hash Entry.
     */
    void put(std::string code, HashEntry entry) {
        int hash = getHash(code);
        int size = table[hash].length();
        table[hash].add(entry, size);
    }
    void remove(std::string code, HashEntry entry) {

        int hash = getHash(code);
        int size = table[hash].length();
        table[hash].remove(entry, size);
    }

    int getHash(std::string code) {
        int v1;
        for (int i = 0; i < code.length(); i++)
            v1 = v1 + code[i];
        return (v1 * 17) % TABLE_SIZE;
    }

    /**
     * TODO
     * iterate through the vector, adding the length of all sequences.
     * @return the size
     */
    int getSize() {
        int size = 0;
        for (int i = 0; i < table.size(); i++) {
            size = size + table[i].length();
        }
        return size;
    }

    /**
     * TODO
     * iterate over the table.
     * For each sequence at an index, input all entries into a string stream.
     * output the string stream into a .txt file.
     */
    void outputHashMap() {
        std::stringstream ss;
//        if(){
//         //file exists
//        }
ofstream OutputFile("output.txt");

        for (int i = 0; i < table.size(); i++) {
            OutputFile << table[i].outputSequence();
            //output the entry to the file.
        }
        // may need to do final output to file
        OutputFile.close();
    }

    ~HashMap() = default;
};

int main() {
    HashMap hm;
    hm.put(3, 23);
    hm.put(5, 2377);
    hm.put(9, 263);
    cout << "Value of latDegree = 3, is " << hm.get(3) << endl;

    /** Output the map */

    /** How many records are in this map data structure?*/

    /** Is there a record for latDegree "YWG" ?*/

    /** Is there a record for latDegree "CMB" ?*/

    /**Remove record with latDegree "HND" ?*/

    /** How many records are in this map data structure?*/

    /** Output the map */

//    hm.put(3, 23);
//    hm.put(5, 2377);
//    hm.put(9, 263);
//    cout << "Value of latDegree = 3, is " << hm.get(3) << endl;
//    hm.put(12, 230);
//    cout << "override an existing entry of (3, 23) with (3,123)" << endl;
//    hm.put(3, 123);
//    cout << "New latMin of latDegree = 3, is " << hm.get(3) << endl;
}


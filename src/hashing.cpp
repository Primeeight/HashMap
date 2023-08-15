//Demonstrates a HashTable and operations.

#include <optional>
#include <iostream>
#include <fstream>
#include <vector>
#include "Sequence/Sequence.h"
#include <sstream>

using namespace std;

/**
   * Open record that includes constructor.
   */
class HashEntry {

public:
    HashEntry() = default;

    HashEntry(optional<HashEntry> Optional) {}

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
};


class HashMap {
private:

    vector<Sequence<HashEntry>> table;
public:
    /**
     * Default constructor
     */
    HashMap() = default;

    /**
     * TODO
     *Traverse the vector for the hash.
     * Traverse the sequence for the specified code.
     * If a hash entry with the specified code is found, return the hash entry.
     * Otherwise return an empty hash entry.
     * @param code
     * @return
     */
    optional<HashEntry> get(std::string code) {
        int hash = getHash(code);
        for (int i = 0; i < table[hash].length(); i++) {
            if (table[hash].entry(i)->code == code)
                return table[hash].entry(i);
        }
        return optional<HashEntry>();
    }

    /**
     *
     * @param code
     * @param HashEntry entry
     * Traverse the vector using the hash.
     * At the specified sequence, use the add function to add the hash entry to the end of the sequence.
     */
    void put(std::string code, HashEntry entry) {
        int hash = getHash(code);
        int size = table[hash].length();
        table[hash].add(entry, size);
    }

    /**
     * TODO
     * get the hash
     * define the size as the length of the current sequence.
     * iterate through the sequence for the element to be removed.
     * match the provided code with the element to be removed's code.
     * remove the element at the position.
     *
     * Convert the optional data type for removal.
     * @param code
     */
    void remove(std::string code) {
        HashEntry currentHashEntry = *new HashEntry;
        int hash = getHash(code);
        int size = table[hash].length();
        for (int i = 0; i < size; i++) {
            if (table[hash].entry(i)->code == code) {
                currentHashEntry = table[hash].entry(i);
                table[hash].remove(currentHashEntry, i);
            }
        }
    }
    /**
     * get the hash using polynomial hashing.
     * @param code
     * @return int
     */
    int getHash(std::string code) {
        int v1;
        for (int i = 0; i < code.length(); i++)
            v1 = v1 + code[i];
        return (v1 * 17) % getSize();
    }

    /**
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
     * Read the file name
     * while the end of the file has not been reached, read each line into the table based on their code.
     * @param filename
     */
    void inputHashMap(string filename) {

        ifstream infile;
        filename = "air16.dat";
        infile.open(filename);
        int dataSize =0;
        bool successful;
        HashEntry newEntry = *new HashEntry;
//        if (!infile) {
//            cout << "unable to open the file";
//            exit(1);
//        }
        if (infile.is_open()) {
            infile >> dataSize;
        }
        //Iterate through the file.
        for (int i = 0; i < dataSize; i++) {
            infile >> newEntry.code;
            infile >> newEntry.name;
            infile >> newEntry.city;
            infile >> newEntry.country;
            infile >> newEntry.latDegree;
            infile >> newEntry.latMin;
            infile >> newEntry.latSec;
            infile >> newEntry.latDir;
            infile >> newEntry.longMin;
            infile >> newEntry.longSec;
            infile >> newEntry.longDir;
            infile >> newEntry.altitude;
            put(newEntry.code, newEntry);
        }
        //close the file.
        infile.close();
    }


    /**
     * TODO
     * iterate over the table.
     * For each sequence at an index, input all entries into a string stream.
     * output the string stream into a .txt file.
     * if there is already an output file, override that file.
     */
//    void outputHashMap() {
//        std::stringstream ss;
//        ofstream OutputFile("output.txt");
//
//        for (int i = 0; i < table.size(); i++) {
//            OutputFile << table[i].outputSequence();
//        }
//        OutputFile.close();
//    }

    ~HashMap() = default;
};


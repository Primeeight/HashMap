//
// Created by Zach's PC on 8/15/2023.
//

#include "main.h"
#include <iostream>
#include <optional>
#include <iostream>
#include <fstream>
#include <vector>
#include "Sequence/Sequence.h"
#include <sstream>
#include "Sequence/Sequence.cpp"
#include "hashing.cpp"

using namespace std;

int main()
{
    /** Output the map */

    /** How many records are in this map data structure?*/

    /** Is there a record for latDegree "YWG" ?*/

    /** Is there a record for latDegree "CMB" ?*/

    /**Remove record with latDegree "HND" ?*/

    /** How many records are in this map data structure?*/

    /** Output the map */

    HashMap hm;
    hm.inputHashMap("Sequence/air16.dat");
//    hm.outputHashMap();
    hm.getSize();
    hm.get("YWG");
    hm.get("CMB");
    hm.remove("HND");
    hm.getSize();
//    hm.outputHashMap();
}
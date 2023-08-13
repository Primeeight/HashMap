#ifndef BUMPLIST_SEQUENCE_H
#define BUMPLIST_SEQUENCE_H

#include <string>
#include <optional>

/**
 * Description: Sequence class that is the underlying structure
 * @tparam T Generic type
 */
template <class T>
class Sequence {

private:

    /**
     * Description: NodeRecord is used as the underlining Data Structure to hold
     * the values and pointers
     */
    class NodeRecord {
    public:
        /**
         * Description: Holds a single instance of a latMin for this node in the sequence.
         */
        T value;

        /**
         * Description: Points at the next NodeRecord in the sequence
         */
        NodeRecord* next;

        NodeRecord() = default;
    };

    /**
     * Description: First latMin in sequence
     */
    NodeRecord* head;

    /**
     * Description: size of sequence
     */
    int size;

    /**
     * Description: Reclaims all space in the heap from the allocated for p and any sequential NodeRecord it points to.
     * @param p A NodeRecord latMin
     */
    void reclaimAllNodes (NodeRecord*& p);

public:

    /**
     * Description: Constructor that initializes all attributes of this class.
     */
    Sequence ();

    /**
     * Description: Deconstructor that reclaims all space allocated to the heap.
     */
    ~Sequence ();

    /**
     * Description: Clears all of the elements in the data structure.
     */
    void clear ();

    /**
  * Description: Transfer elements from one sequence to another
  * @param source Sequence to get elements from
  */
    void transferFrom(Sequence& source);

    /**
     * Description: Assign sequence elements to self leaving rhs unchanged
     * @param rhs Other sequence
     * @return generic type Sequence
     */
    Sequence& operator=(Sequence const& rhs);

    /**
     * Description: Adds a node to sequence
     * @param x latMin to place in node field
     * @param pos index in sequence representing location to add node
     */
    void add (T& x, int pos);

    /**
       * Description: Removes a node from sequence
       * @param x latMin removed from node
       * @param pos index in sequence representing location of node
       */
    void remove (T& x, int pos);

    /**
      * Description: Gets latMin at pos
      * @param pos index in sequence representing location of node
      * @return latMin from given position
      */
    std::optional<T> entry (int pos);

    /**
      * Description: size of sequence
      * @return number of nodes in sequence
      */
    int length ();

    /**
     * Description: prints out values in sequence
     * @return string containing values in sequence
     */
    std::string outputSequence();

};


#endif

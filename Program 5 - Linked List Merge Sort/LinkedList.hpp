#ifndef LINKEDLIST_HPP
#define LINKEDLIST_HPP

#include <iostream>
#include <cstdlib>
#include <string>
#include "Node.hpp"

using namespace std;

// not seperated into interface/implementation due to template class usage
template <class T>
class LinkedList{
    private:
    unsigned int length; // the number of nodes contained in the list
    Node<T> *head; // a pointer to the first node in the list

    public:
    // big three
    /*******************************************************************
    ** Function: LinkedList();
    ** Description: The default constructor for the LinkedList template class
    ** Parameters: none
    ** Pre-conditions: n/a (no parameters)
    ** Post-conditions: Creates an instantiation of the LinkedList template class.
    *******************************************************************/
    LinkedList();

    /*******************************************************************
    ** Function: ~LinkedList();
    ** Description: The destructor for the LinkedList template class
    ** Parameters: none
    ** Pre-conditions: Takes in an existing LinkedList
    ** Post-conditions: Destroys the LinkedList instantation, and changes it's head pointer to null. 
    *******************************************************************/
    ~LinkedList();

    /*******************************************************************
    ** Function: LinkedList(LinkedList &existing);
    ** Description: Copy Constructor for the LinkedList template class
    ** Parameters: LinkedList &existing
    ** Pre-conditions: Takes in an existing LinkedList class
    ** Post-conditions: Sets the new LinkedList class instantiation to the existing inputted one. 
    *******************************************************************/
    LinkedList(LinkedList &existing);

    /*******************************************************************
    ** Function: LinkedList& operator=();
    ** Description: Assignment Operator Overload function for the LinkedList template class
    ** Parameters: LinkedList &existing
    ** Pre-conditions: Takes in an existing LinkedList class
    ** Post-conditions: Sets the LinkedList on the left-side of the "=" operator equal to the existing LinkedList being passed in as parameter. 
    *******************************************************************/
    LinkedList& operator=(LinkedList &existing); 

    // getters
    /*******************************************************************
    ** Function: getter functions (ex get_head();)
    ** Description: Get the private values from the class and return them to be used outside the class. 
    ** Parameters: none
    ** Pre-conditions: Take in the private values of the class (respectively, head, and length)
    ** Post-conditions: Returns the private class values (respectively, head, and length)
    *******************************************************************/
    Node<T>* get_head();
    unsigned int get_length();

    //setters
    /*******************************************************************
    ** Function: setter functions (ex set_head();)
    ** Description: Sets a private class function variable to whatever is being passed in
    ** Parameters: whatever is being set (respectively, Node<T> *p_head and unsigned int p_length)
    ** Pre-conditions: The parameters are passed into each respective function to modify the private class variables. 
    ** Post-conditions: Changes the the private class variables (respectively Node<T> *p_head and unsigned int p_length modify head and length)
    *******************************************************************/
    void set_head(Node<T> *p_head);
    void set_length(unsigned int p_length);

    // design functions
    /*******************************************************************
    ** Function: print();
    ** Description: Prints out the values of the LinkedList object.
    ** Parameters: none
    ** Pre-conditions: Takes in an existing LinkedList. 
    ** Post-conditions: Prints out the LinkedLists values to the console. 
    *******************************************************************/
    void print(); 

    /*******************************************************************
    ** Function: clear();
    ** Description: Clears the LinkedList by deleting dynamic memory. 
    ** Parameters: none
    ** Pre-conditions: Takes in an existing LinkedList.
    ** Post-conditions: deletes all of the pointers in the LinkedList using an iterator. 
    *******************************************************************/
    void clear();

    /*******************************************************************
    ** Function: push_back();
    ** Description: Adds a value to the LinkedList at the end
    ** Parameters: int number
    ** Pre-conditions: Takes in the current LinkedList along with the number to be added
    ** Post-conditions: Modifies the LinkedList to point to the new node at the end
    *******************************************************************/ 
    unsigned int push_back(int number);

    /*******************************************************************
    ** Function: push_front();
    ** Description: Adds a value to the LinkedList at the front
    ** Parameters: int number
    ** Pre-conditions: Takes in the current LinkedList along with the number to be added
    ** Post-conditions: Modifies the LinkedList to point to the new node at the head
    *******************************************************************/
    unsigned int push_front(int number); 

    /*******************************************************************
    ** Function: insert();
    ** Description: Adds a value to the LinkedList in the middle of the LinkedList
    ** Parameters: int number, unsigned int index
    ** Pre-conditions: Takes in the current LinkedList along with the number to be added at an index value
    ** Post-conditions: Modifies the LinkedList to incorporate the new LinkedList element. 
    *******************************************************************/
    unsigned int insert(int number, unsigned int index); 

    /*******************************************************************
    ** Function: primes();
    ** Description: Determines all of the primes within the linked list
    ** Parameters: none
    ** Pre-conditions: Takes in the linked list with values
    ** Post-conditions: Prints the number of primes in the linked list, and the primes themselves
    *******************************************************************/
    void primes();

    /*******************************************************************
    ** Function: sorting();
    ** Description: Determines if the user would like to sort ascendingly or descendingly
    ** Parameters: none
    ** Pre-conditions: n/a (no parameters)
    ** Post-conditions: Makes function calls to sort_ascending/sort_descending based on user input
    *******************************************************************/
    void sorting();

    /*******************************************************************
    ** Function: sort_ascending();
    ** Description: Sorts the entire linked list ascendingly (makes function calls to do so)
    ** Parameters: none
    ** Pre-conditions: n/a (no parameters)
    ** Post-conditions: calls the divide function
    *******************************************************************/
    void sort_ascending(); 

    /*******************************************************************
    ** Function: sort_descending();
    ** Description: Sorts the entire linked list descendingly (makes function calls to do so)
    ** Parameters: none
    ** Pre-conditions: n/a (no parameters)
    ** Post-conditions: calls the divide function
    *******************************************************************/
    void sort_descending(); 

    /*******************************************************************
    ** Function: divide();
    ** Description: Splits up all of the values in the linked list recursively
    ** Parameters: Node<T> *head, int length, int type
    ** Pre-conditions: Takes in the linked list with the length at the type to be sorted
    ** Post-conditions: Recursively calls itself until the length is 1 or 0
    *******************************************************************/
    void divide(Node<T> *head, int length, int type);

    /*******************************************************************
    ** Function: merge_up();
    ** Description: Merges all of the nodes passed in into an ascending order
    ** Parameters: Node<T> *first, Node<T> *second, int length
    ** Pre-conditions: Takes in the first node and the second node
    ** Post-conditions: Returns a merged list
    *******************************************************************/
    Node<T>* merge_up(Node<T> *first, Node<T> *second, int length);

    /*******************************************************************
    ** Function: merge_down();
    ** Description: Merges all of the nodes passed in into a descending order
    ** Parameters: Node<T> *first, Node<T> *second, int length
    ** Pre-conditions: Takes in the first node and the second node
    ** Post-conditions: Returns a merged list
    *******************************************************************/
    Node<T>* merge_down(Node<T> *first, Node<T> *second, int length);
};

// big three
// constructor
template <class T>
LinkedList<T>::LinkedList(){
    head = NULL;
    length = 0;
}

// destructor
template <class T>
LinkedList<T>::~LinkedList(){
    if (head != NULL){
        delete head;
    }
    head = NULL;
}

// copy constructor
template <class T>
LinkedList<T>::LinkedList(LinkedList &existing){
    //temporary node pointer to existing linked list node
    Node<T> *e_temp = existing.get_head();
    //temporary node pointer to new linked list
    Node<T> *n_temp = head;
    for (int i = 0; i < existing.get_length(); i++){
        //creates a new node & sets the values to the pointed at node
        Node<T> *another = new Node<T>;
        another->value = e_temp->value;
        cout << "Value at " <<i << ": " << another->value << endl;
        // moves the iterators for both the existing and new linked lists
        n_temp = another;
        n_temp = n_temp->next;
        e_temp = e_temp->next;
        length++;
    }
}

// assignment overload operator
template <class T>
LinkedList<T>& LinkedList<T>::operator=(LinkedList &existing){
    clear();

    //temporary node pointer to existing linked list node
    Node<T> *e_temp = existing.get_head();
    //temporary node pointer to new linked list
    Node<T> *n_temp = head;
    for (int i = 0; i < existing.get_length(); i++){
        //creates a new node & sets the values to the pointed at node
        Node<T> *another = new Node<T>;
        another->value = e_temp->value;
        cout << "Value at " <<i << ": " << another->value << endl;
        // moves the iterators for both the existing and new linked lists
        n_temp = another;
        n_temp = n_temp->next;
        e_temp = e_temp->next;
        length++;
    }

    return *this;
}

// setters and getters
template <class T>
Node<T>* LinkedList<T>::get_head(){
    return head;
}

template <class T>
unsigned int LinkedList<T>::get_length(){
    return length;
}

template <class T>
void LinkedList<T>::set_head(Node<T> *p_head){
    head = p_head;
}

template <class T>
void LinkedList<T>::set_length(unsigned int p_length){
    length = p_length;
}

// design functions
template <class T>
void LinkedList<T>::clear(){
    Node<T> *temp = head;
    for (int i = 0; i < length; i++){
        temp = head;
        for (int j = 0; j < length - i; j++){
            temp = temp->next;
            if (j == (length - (i + 1))){
                delete temp;
            }
        }
    }
}

template <class T>
void LinkedList<T>::print(){
    Node<T> *temp = head;
    for (int i = 0; i < length; i++){
        cout << temp->value << "  ";
        temp = temp->next;
    }
}

template <class T>
unsigned int LinkedList<T>::push_back(int number){
    Node<T> *back = new Node<T>;
    back->value = number;
    back->next = NULL;

    if (head == NULL){
        head = back;
    } else{
        Node<T> *temp = head;
        for (int i = 1; i < length; i++){
            
            temp = temp->next;
        }
        temp->next = back;
    }

    return ++length;
}

template <class T>
unsigned int LinkedList<T>::push_front(int number){
    Node<T> *front = new Node<T>;
    front->value = number;
    front->next = head;
    head = front;
    return ++length;
}

template <class T>
unsigned int LinkedList<T>::insert(int number, unsigned int index){
    Node<T> *insert = new Node<T>;
    insert->value = number;
    insert->next = NULL;

    if (head == NULL || index == 0){
        insert->next = head;
        head = insert;
    } else{
        Node<T> *temp = head;
        for (int i = 1; i < index; i++){
            temp = temp->next;
        }
        if (temp->next == NULL){
            temp->next = insert;
        } else{
            Node<T> *temp2 = temp->next;
            insert->next = temp2;
            temp->next = insert;
        }
    }
    return ++length;
}

template <class T>
void LinkedList<T>::primes(){
    int factors = 0;
    int primes = 0;
    Node<T> *temp = head;

    cout << endl;
    cout << "Finding Primes: ";

    for (int i = 0; i < length; i++){
        if (temp->value > 0){
            for (int i = 2; i < temp->value; i++){
                if (temp->value % i == 0){
                    factors++;
                }
            }

            if (factors == 0){
                cout << temp->value << "  ";
                primes++;
            }
            factors = 0;
            
            temp = temp->next;
        }
    }

    cout << endl;
    cout << "Primes found: " << primes << endl;
    cout << endl;
    cout << "==============================================================" << endl;
}

template <class T>
void LinkedList<T>::sorting(){
    bool valid = true;
    string input = "";

    cout << endl;
    cout << "Do you want to sort by ascending(1) or descending order? (2)" << endl;
    cout << "Enter '1' or '2' for the list types respectively" << endl;
    while (valid){
        cin >> input;
        if (input != "1" && input != "2"){
            cout << "Error, please enter a '1' or '2' input" << endl;
        } else if (input == "1"){
            cout << "Sorting by ascending order!" << endl;
            sort_ascending();
            
            valid = false;
        } else if (input == "2"){
            cout << "Sorting by descending order!" << endl;

            valid = false;
        }
    }
    print();
    cout << endl;
}

template <class T>
void LinkedList<T>::sort_ascending(){
    divide(head, length, 1);
}

template <class T>
void LinkedList<T>::sort_descending(){
    divide(head, length, 2);
}

template <class T>
void LinkedList<T>::divide(Node<T> *head, int length, int type){
    if(length >= 1){
        divide(head, length/2, type);
        
        Node<T> *temp = head;
        for (int i = 0; i < length/2; i++){
            temp = temp->next;
        }
        divide(temp, (length/2), type);
        if (type == 1){
            head = merge_up(head, temp, length);
        } else{
            head = merge_down(head, temp, length);
        }
        
   }
}

template <class T>
Node<T>* LinkedList<T>::merge_up(Node<T> *first, Node<T> *second, int length){
    
    int f_current = 0;
    int s_current = 0;
    int f_size = length/2;
    int s_size = length/2;

    Node<T> *sorted;
    Node<T> *sorted_temp = sorted;
    Node<T> *f_temp = first;
    Node<T> *s_temp = second;
    
    while(f_current != f_size && s_current != s_size ){
            if (f_temp->value < s_temp->value){
            s_current++;
            sorted = s_temp;
            s_temp = s_temp -> next;
            
        } else{
            f_current++;
            sorted = f_temp;
            f_temp = f_temp->next;
        }   
        sorted = sorted->next; 
    }

    Node<T> *temp2 = sorted_temp;
    return sorted_temp;
}

template <class T>
Node<T>* LinkedList<T>::merge_down(Node<T> *first, Node<T> *second, int length){
    
    int f_current = 0;
    int s_current = 0;
    int f_size = length/2;
    int s_size = length/2;

    Node<T> *sorted;
    Node<T> *sorted_temp = sorted;
    Node<T> *f_temp = first;
    Node<T> *s_temp = second;
    
    while(f_current != f_size && s_current != s_size ){
            if (f_temp->value < s_temp->value){
            s_current++;
            sorted = s_temp;
            s_temp = s_temp -> next;
            
        } else{
            f_current++;
            sorted = f_temp;
            f_temp = f_temp->next;
        }   
        sorted = sorted->next; 
    }

    Node<T> *temp2 = sorted_temp;
    return sorted_temp;
}

#endif
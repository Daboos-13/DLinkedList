// Program: FCIDLL is a generic single linked list 
//          Developed for CS214 Data Structures
//          at FCI, Cairo University
// Author:  Mohammad El-Ramly, 8 Mar. 2013 

#ifndef FCIDLL_H_
#define FCIDLL_H_

#include <iostream>
#include <conio.h>
#include <stdlib.h>    

using namespace std;

template <class T>
class Node {
protected:
    T     data;        // to hold generic data of type T
	Node<T>* next;     // to hold pointer to next item
	Node<T>* prev;     // to hold pointer for previous item

  public:
		Node () {next = prev = NULL;  data = NULL;}
		Node (T dataItem, Node<T>* nextPtr = NULL, Node<T>* prevPtr = NULL) {
            data = dataItem; next = nextPtr; prev = prevPtr; 
        }
		Node<T>* getNext ()        {return next;}
		void setNext(Node<T>* ptr) {next = ptr;}
		Node<T>* getPrev ()        {return prev;}
		void setPrev(Node<T>* ptr) {prev = ptr;}
		T  &getData ()              {return data;}
		void setData (T dataItem)  {data = dataItem;}
//		template <class TT>
//		friend ostream& operator<< (ostream& out, Node<TT> n);
};

/////////////////////////////
template <class T>
class FCIDLL {


private:
        std::size_t counter;
        Node<T> *head, *tail;
        Node<T> *merge(Node<T> *first, Node<T> *second,bool (prediction)(T & item1,T&item2));
        Node<T> *mergeSort(Node<T> *headd,bool (prediction)(T & item1,T&item2));
        Node<T> *split(Node<T> *headd);


public:
        FCIDLL() :head{nullptr},tail{nullptr},counter{0}
        {}
        ~FCIDLL ();
        void addToHead(T item);
        void addToTail(T item);
        T removeFromHead();
        T removeFromTail();
        void reverse();
        void sort(bool (comp)(T & item1,T&item2));
        T front();
        T back();
        size_t  size();
        void addToIndex(T item, int index);
        bool search (T item);
        T removeFromIndex(std::size_t index);
        T removeItem (T item);
        void removeWithPredicate(bool (pBoolean)(T & item));
        bool isEmpty();
    template <class TT>
        friend ostream& operator<<(ostream&, FCIDLL<TT>);
};

//////////////////////////////

#endif 

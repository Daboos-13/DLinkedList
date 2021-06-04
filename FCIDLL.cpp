// Program: FCIDLL is a generic single linked list 
//          Developed for CS214 Data Structures
//          at FCI, Cairo University
// Author:  Mohammad El-Ramly, 8 Mar. 2013
// Link: http://www.mathcs.duq.edu/drozdek/DSinCpp/

#include <iostream>
#include <conio.h>
#include <stdlib.h>    
#include "FCIDLL.h" 
    
using namespace std;

template <class T>
ostream& operator<< (ostream& out, Node<T> node) {
    out << node.getData() << "->";
    return out;
}

////////////////////////////////
template <class T>
void FCIDLL<T>::addToTail(T item) {
    if (!tail){
        head = new Node<T>(item);
        tail = head;
    }else {
        auto *ptr = new Node<T>(item, nullptr, tail);
        if (head == nullptr)
            head = tail = ptr;
        else {
            tail->setNext(ptr);
            tail = ptr;
        }
    }
    counter++;
}

template <class T>
void FCIDLL<T>::addToHead(T item) {
    if (!head){
        head = new Node<T>(item);
        tail= head;
    }else {
        auto *ptr = new Node<T>(item, head, nullptr);
        head->setPrev(ptr);
        head = ptr;
        if (tail == nullptr)
            tail = head;
    }
    counter++;

}

template <class T>
FCIDLL<T>::~FCIDLL () {}

template <class T>
void FCIDLL<T>::addToIndex(T value, int Node_index) {
    if(!head){
        auto *t = new Node<T>(value, nullptr, nullptr);

        head = t;
        tail =head;
        counter++;
        return;
    }

    Node<T>*p=head;
    for(int i=0;i<Node_index &&p;i++){
        p=p->getNext();
    }
    if (p){
        if(p==tail){
            auto *t=new Node<T>(value, nullptr,p);
            p->setNext(t);
            tail=t;
            counter++;

        }else {
            auto*t = new Node<T>(value,p->getNext(),p);
            p->getNext()->setPrev(t);
            p->setNext(t);
            counter++;

        }
    }


}

template <class T>
bool FCIDLL<T>::search(T item) {
    Node<T>* ptr = head;
    while (! (ptr == nullptr) && item != ptr->getData())
        ptr = ptr -> getNext();
    if (ptr != nullptr)
        return true;
    else
        return false;
}

template <class T>
ostream& operator<<(ostream& stream, FCIDLL<T> list) {
        if (list.head != 0) {
            Node<T>* ptr = list.head;
            stream << *ptr;
            while (ptr != list.tail) {
                ptr = ptr->getNext();
                stream << *ptr;
            }
            stream << "NULL" << endl;
        }
        return stream;
}

template<class T>
T FCIDLL<T>::removeFromHead() {
    if (!head)
        return NULL;
    Node<T>* p = head;
    T holdData = p->getData();
    head = head->getNext();
    head->setPrev(nullptr);
    delete  p;
    if (head == nullptr)
        tail = nullptr;
    counter--;
    return holdData;
}

template<class T>
T FCIDLL<T>::removeFromTail() {
    Node<T>* p;
    if (!tail)
        return NULL;
    p= tail;
    tail= p->getPrev();
    tail->setNext(nullptr);
    delete p;
    counter--;


}

template<class T>
T FCIDLL<T>::front() {
    return head->getData();
}

template<class T>
T FCIDLL<T>::back() {
    return tail->getData();
}

template<class T>
size_t FCIDLL<T>::size() {
    return counter;
}

template<class T>
T FCIDLL<T>::removeFromIndex(std::size_t index) {
    if (index>=counter){
        cerr<<"the given index is out of bound"<<endl;
        return NULL;
    }
    Node<T> *p = head;
    Node<T> *q = nullptr;
    if (index==0){
      T data =   removeFromHead();
        return data;
    }
    for (int i = 1; i <= index; ++i) {
        q =p;
        p = p->getNext();
    }
    q->setNext(p->getNext()) ;
    T data = p->getData();
    delete p;
    if (tail == p){
        tail = q;
    }
    counter--;

    return data;



}

template<class T>
T FCIDLL<T>::removeItem(T item) {
    Node<T> * p= head;
    Node<T> * q= nullptr;
    while (p){
        if (p->getData()==item){
            if (p==head){
                T data = removeFromHead();
                return data;
            }else if (p==tail){
                T data = removeFromTail();
                return data;
            }else{
                q->setNext(p->getNext());
                p->getNext()->setPrev(q);
                T data = p->getData();
                delete p;
                counter--;
                return data;

            }
        }else{
            q= p;
            p = p->getNext();


        }
    }
    cerr<<"item is t not found "<<endl;
    return NULL;
}

template<class T>
void FCIDLL<T>::removeWithPredicate(bool (predication)(T & item)) {
    Node<T> * p= head->getNext();
    Node<T> * q  = head;
    Node<T> *r = nullptr;
    while (q){
        if (predication(q->getData())){
            if (q==head){
                delete q;
                q=head=p;
                if (p)
                p=p->getNext();
                counter--;
                if (head== nullptr)
                    tail= nullptr;

            }else if (q==tail){
                delete q;
                r->setNext(nullptr);
                tail=r;
                counter--;
                if (tail== nullptr)
                    head= nullptr;

            }else {
                delete q;
                r->setNext(p);
                q=p;
                if (p)
                p=p->getNext();

                counter--;
            }
        }else {
            r=q;
            q=p;
            if (p)
            p=p->getNext();

        }
    }
    if (r) {
        if (predication(r->getData())) {
            removeFromTail();
        }
    }
}

template<class T>
bool FCIDLL<T>::isEmpty() {
    return head== nullptr;
}

template<class T>
void FCIDLL<T>::reverse() {
    Node<T>*temp;
    Node<T>*p = head;
    tail =head;
    while (p){

        temp= p->getNext();
        p->setNext(p->getPrev());
        p->setPrev(temp);
        p=p->getPrev();

        if(p!= nullptr &&p->getNext()== nullptr)
            head=p;

    }

}

template<class T>
Node<T> *FCIDLL<T>::merge(Node<T> *first, Node<T> *second,bool (prediction)(T & item1,T&item2)) {

    if (!first)
        return second;

    if (!second)
        return first;


    if (prediction(first->getData(),second->getData()))
    {
        first->setNext(merge(first->getNext(),second,prediction)) ;

        first->getNext()->setPrev(first);
        first->setPrev(nullptr);
        return first;
    }
    else
    {
        second->setNext(merge(first,second->getNext(),prediction)) ;
            second->getNext()->setPrev(second);
        second->setPrev(nullptr);
        return second;
    }
}

template<class T>
Node<T> *FCIDLL<T>::mergeSort(Node<T> *headd,bool (prediction)(T & item1,T&item2)) {
    if (!headd || !headd->getNext())
        return headd;
    Node<T> *second = split(headd);


    headd = mergeSort(headd,prediction);
    second = mergeSort(second,prediction);

    return merge(headd,second,prediction);
}

template<class T>
Node<T> *FCIDLL<T>::split(Node<T> *headd) {
    Node<T> *fast = headd,*slow = headd;
    while (fast->getNext()&& fast->getNext()->getNext())
    {
        fast = fast->getNext()->getNext();
        slow = slow->getNext();
    }
    Node<T> *temp = slow->getNext();
    slow->setNext(nullptr);
    return temp;
}

template<class T>
void FCIDLL<T>::sort(bool (prediction)(T & item1,T&item2)) {
    head = mergeSort(head,prediction);
    Node<T>*p = head;
    while (p->getNext()){
        p=p->getNext();
    }
    tail=p;
//    tail->setNext(nullptr);
}






///////////////////////////////


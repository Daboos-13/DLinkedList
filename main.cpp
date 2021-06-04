#include <iostream>
#include "FCIDLL.h"
#include "FCIDLL.cpp"

bool comp(int &a, int &b){
    return a<b;
}
int main() {

    string choice ;
    FCIDLL<int> list ;
    int input {};
    while (true) {
        cout << "welcome to FCI Linked list " << endl;
        cout << "1- add to the head " << endl;
        cout << "2- add to the tail" << endl;
        cout<< "3- add to index"<<endl;
        cout << "4- remove form head" << endl;
        cout << "5- remove from tail" << endl;
        cout << "6- search" << endl;
        cout << "7- remove item " << endl;
        cout << "8- reverse" << endl;
        cout << "9- sort" << endl;
        cout << "10- size of the list" << endl;
        cout << "11- print the list " << endl;
        cout << "0- exit" << endl;
        cin >> choice;
        if (choice == "1") {

            cout<<"enter the number : "<<endl;
            cin>>input;
            list.addToHead(input);
            cout<<list;


        }else if(choice=="2"){

            cout<<"enter the number : "<<endl;
            cin>>input;
            list.addToTail(input);
            cout<<list;



        }else if (choice=="3"){

            if (list.isEmpty()){
                cout<<"list is already empty"<<endl;
            }else{
                cout<<"enter the item"<<endl;
                int x;
                cin>>x;
                cout<<"inter the index"<<endl;
                cin>>input;
                list.addToIndex(x,input);
                cout<<list;
            }

        }else if (choice=="4"){

            if (list.isEmpty()){
                cout<<"list is already empty"<<endl;
            }else{
                list.removeFromHead();
                cout<<"item removed "<<endl;
                cout<<list;
            }




        }else if (choice=="5"){
            if (list.isEmpty()){
                cout<<"list is already empty"<<endl;
            }else{
                list.removeFromTail();
                cout<<"item removed "<<endl;
                cout<<list;
            }

        }else if (choice=="6"){
            if (list.isEmpty()){
                cout<<"list is already empty"<<endl;

            }else{
                cout<<"enter the item"<<endl;
                cin>>input;
                bool x =list.search(input);
                if (x){
                    cout<<"item found"<<endl;
                }else{
                    cout<<"item is not found"<<endl;
                }
                cout<<list;

            }




        }else if (choice=="7"){
            if (list.isEmpty()){
                cout<<"list is already empty"<<endl;

            }else{
                cout<<"enter the item"<<endl;
                cin>>input;
                int x =list.removeItem(input);
                cout<<x <<" is  removed "<<endl;
                cout<<list;

            }


        }else if (choice=="8"){

            if (list.isEmpty()){
                cout<<"list is empty"<<endl;
            }else{
                list.reverse();
                cout<<"list is reversed"<<endl;
                cout<<list;


            }




        }else if (choice=="9"){


            if (list.isEmpty()){
                cout<<"list is empty"<<endl;
            }else{
                list.sort(comp);
                cout<<"list is sorted"<<endl;
                cout<<list;

            }


        }else if (choice=="10"){
            if (list.isEmpty()){
                cout<<"list is empty"<<endl;
            }else{
                cout<<"the size of the list is "<<list.size()<<endl;
            }


        }else if (choice=="11"){
            if (list.isEmpty()){
                cout<<"list is empty"<<endl;

            }else{
                cout<<list;

            }

        }






























        else if(choice=="0"){
            break;
        }


    }

    return 0;
}

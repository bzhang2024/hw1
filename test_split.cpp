/*
CSCI 104: Homework 1 Problem 1

Use this file to test your split.cpp file.

Create linked lists and split them with your split() function.

You can compile this file like this:
g++ split.cpp test_split.cpp -o test_split
*/

#include "split.h"
#include <cstddef>
#include <iostream>

using namespace std; 

int main(int argc, char* argv[])
{

    Node* head = NULL;
    Node* temp = NULL;

    //sorted linked list 1 to i
    for(int i = 1; i <= 5; i++) {
        if(head == NULL){
            head = new Node(i, NULL);
            temp = head;
        } 
        else {
            temp->next = new Node(i, NULL);
            temp = temp->next;
        }
    }

    Node* odds = NULL;
    Node* evens = NULL;
    
    split(head, odds, evens);


    //PRINTING STUFF OUT
    cout << "odd numbers: "; 
    temp = odds;
    while(temp != NULL) {
        cout << temp->value << " ";
        temp = temp->next;
    }
    cout << endl; 


    cout << "Even numbers: ";
    temp = evens;
    while(temp != NULL) {
        cout << temp->value << " ";
        temp = temp->next;
    }
    cout << endl; 

    //deallocate mem
    while(odds != NULL) {
        Node* temp = odds;
        odds = odds->next;
        delete temp;
    }
    while(evens != NULL) {
        Node* temp = evens;
        evens = evens->next;
        delete temp;
    }

}

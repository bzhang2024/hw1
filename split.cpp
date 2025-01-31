/*
CSCI 104: Homework 1 Problem 1

Write a recursive function to split a sorted singly-linked
list into two sorted linked lists, where one has the even 
numbers and the other contains the odd numbers. Students 
will receive no credit for non-recursive solutions. 
To test your program write a separate .cpp file and #include
split.h.  **Do NOT add main() to this file**.  When you submit
the function below should be the only one in this file.
*/

#include "split.h"

/* Add a prototype for a helper function here if you need */

//void splitSort(Node* current, Node*& odds, Node*& evens);

//in, odds, and evens are pointers passed by reference
void split(Node*& in, Node*& odds, Node*& evens) 
{
  /* Add code here */
// WRITE YOUR CODE HERE

  //Base case
  if (in == NULL){
    odds = NULL;
    evens = NULL;
    return;
  }

  //make a temp tracker to node
  Node* temp = in;
  in = in->next; 

  split(in, odds, evens);

  temp->next = NULL;
  if (temp->value % 2 == 0) { //number is even
    temp->next = evens;   
    evens = temp;  //add number to front of list
  }
  else { //num is odd
    temp->next = odds;
    odds = temp; 
  }


}

/* If you needed a helper function, write it here */
//nah thats cringe

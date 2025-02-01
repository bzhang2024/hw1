#include <cstddef>
#include <stdexcept>
#include "ulliststr.h"
#include <exception>

using namespace std;

ULListStr::ULListStr()
{
  head_ = NULL;
  tail_ = NULL;
  size_ = 0;
}

ULListStr::~ULListStr()
{
  clear();
}

bool ULListStr::empty() const
{
  return size_ == 0;
}

size_t ULListStr::size() const
{
  return size_;
}

// WRITE YOUR CODE HERE
// Check if location is valid
string* ULListStr::getValAtLoc(size_t loc) const {
    if(loc >= size_) {  //out of bounds
        return NULL;
    }
  
    Item* temp = head_;
    int idx = 0;
    
    // Find the right node
    while(temp != NULL) {
  
        // Check if loc is in this node
        if(idx + (temp->last - temp->first) > loc) {
            
            int diff = loc - idx;
            return &temp->val[temp->first + diff];
        }
        
        // Move to next node
        idx += (temp->last - temp->first); 
        temp = temp->next; 
    }
  return NULL; 
}

void ULListStr::push_back(const string& val){
  if (empty()){
    head_ = new Item;
    tail_ = head_;
    head_->val[0] = val;
    head_->last = 1; //list now 0 to 1
  }
  else if (tail_->last < ARRSIZE){
    tail_->val[tail_->last] = val;
    tail_->last++; 
  }
  else {
    Item* temp = new Item; //create a new node to append
    temp->val[0] = val; 
    temp->last = 1;
    
    tail_->next = temp; 
    temp->prev = tail_; 
    tail_ = temp; 
  }

  size_++; //add item
}

void ULListStr::push_front(const string& val){
  if (empty()){
    head_ = new Item;
    tail_ = head_;
    head_->val[0] = val;
    head_->last = 1; //list now 0 to 1
  }
  else {
    Item* temp = new Item; //create a new node to append
    temp->val[ARRSIZE-1] = val; 
    temp->first = ARRSIZE-1;
    temp->last = ARRSIZE;

   
    
    
    head_->prev = temp;
    temp->next = head_; 
    head_ = temp; 
  }

  size_++
}

void ULListStr::pop_back(){
  if (empty()){
    return; 
  }
  tail_->last--;
  size_--;
  if(tail_->first == tail_->last) {  //if array is empty
    if(head_ == tail_) { 
      delete head_; 
            head_ = tail_ = NULL;
    }
    else { //otherwise, adjust tail
      Item* curr_tail = tail_;
      tail_ = tail_->prev;
      tail_->next = NULL;
      delete curr_tail; 
    }
  }
}

void ULListStr::pop_front(){
  if (empty()) {
        return;
    }
    
    head_->first++;
    size_--;
    
    if (head_->first == head_->last) {  
        if (head_ == tail_) {  
            delete head_;
            head_ = tail_ = NULL;
        }
        else {  // otherwise, adjust head
            Item* temp = head_;
            head_ = head_->next;
            head_->prev = NULL;
            delete temp;
        }
    }

}

string const& ULListStr::back() const{
  //returns element at back of linked list
  if (empty()){
    throw invalid_argument("List is empty");
  }
  return tail_->val[tail_->last - 1];
}

string const& ULListStr::front() const{
  //returns element at front of linked list
  if (empty()){
    throw invalid_argument("List is empty");
  
  }
  return head_->val[head_->first];
}

void ULListStr::set(size_t loc, const std::string& val)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  *ptr = val;
}

std::string& ULListStr::get(size_t loc)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

std::string const & ULListStr::get(size_t loc) const
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

void ULListStr::clear()
{
  while(head_ != NULL){
    Item *temp = head_->next;
    delete head_;
    head_ = temp;
  }
  tail_ = NULL;
  size_ = 0;
}

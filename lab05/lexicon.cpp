// Implementation starter file for CSCI 60 Homework 3; due Thursday, 05/08/2025
// List any collaborators and write your name here

#include "lexicon.h"

/* TODO: reimplement this 1-arg constructor to ignore repeats */
Lexicon::Lexicon(string filename){
  size_ = 0; // start with an empty set
  ifstream in(filename); //opening file 
  string word; 

  while (in >> word) {
    // Check if word already exists in data_[]
    // If not duplicate and there's room, add it

    bool duplicate = false; //sets it as false
    for (size_t i = 0; i < size_; i++) {
      if (data_[i] == word) { //if the word is found its set as true
        duplicate = true;
        break;
      }
    }

// if the word is not a duplicate and there is still space, it gets added to the 
// then size is increased by one

    if (!duplicate && size_ < CAPACITY) { 
      data_[size_++] = word;
    }

  }

  in.close();
}


// function that checks if a string is inside the array 
// loops through array and sees if it matches the target then returns true or false 

bool Lexicon::contains(string target) const{

  for(size_t i = 0; i<size_; i++){
    if(data_[i] == target){
      return true;
    }
  }
  return false;

}


// inserts a inputed string 
// if it returns true for containing the word then it returns false since it already
// has the word so it does not need to insert it
// if the size is less than capacity then they increment the size by one and set it to word

bool Lexicon::insert(string word) {
  if (contains(word)) {
    return false; 
  }

  if (size_ < CAPACITY) {
    data_[size_++] = word; 
    return true;
  }

  return false; 
}


//removes an inputed string from the array 
// loops through the array and looks for the string 
// if found it shifts all the elements to the left 
// then it decreases the size 

bool Lexicon::remove(string word) {
  for (size_t i = 0; i < size_; i++) {
    if (data_[i] == word) {
      // Shift elements left
      for (size_t j = i; j < size_ - 1; j++) {
        data_[j] = data_[j + 1];
      }
      size_--;
      return true;
    }
  }
  return false;
}


/* TODO: implement the other functions declared in lexicon.h here */

// creates a new lexicon called result 
// it adds all the words from the current and rhs 
// skips duplicates
// returns the combined lexicon
Lexicon Lexicon::operator|(const Lexicon& rhs) const {
  Lexicon result;

  for (size_t i = 0; i < size_; i++) {
    result.insert(data_[i]);
  }

  for (size_t i = 0; i < rhs.size(); i++) {
    result.insert(rhs[i]);
  }

  return result;
}

// returns a new lexicon containing only the words 
// that are both in the current object and if they are in rhs 
Lexicon Lexicon::operator&(const Lexicon& rhs) const{
  Lexicon result;

  for(size_t i = 0;i<size_;i++){
    if (rhs.contains(data_[i])) {
      result.insert(data_[i]);
    }
  
  }
  return result;
}

// This function returns a new Lexicon containing words 
// that appear in either the current object or rhs but not both
// loops through and checks if it doesnt contain the word 
// if it doesnt then insert it 

Lexicon Lexicon::operator^(const Lexicon& rhs) const {
  Lexicon result;

  for (size_t i = 0; i < size_; i++) {
    if (!rhs.contains(data_[i])) {
      result.insert(data_[i]);
    }
  }

  for (size_t i = 0; i < rhs.size(); i++) {
    if (!contains(rhs[i])) {
      result.insert(rhs[i]);
    }
  }

  return result;
}



// Inserts contents of lex in out in order, separated by spaces
// loops through the array and outputs it one by one 

ostream& operator <<(ostream& out, const Lexicon & lex) {
  size_t n = lex.size();
  for (size_t i=0; i<n; i++) {
    out << lex[i] << " ";
  }
  return out;
}

bool operator==(const Lexicon& lhs, const Lexicon& rhs) {
  if (lhs.size() != rhs.size()) {
    return false; 
  }

  for (size_t i = 0; i < lhs.size(); i++) {
    if (!rhs.contains(lhs[i])) {
      return false;
    }
  }

  return true;

}

// checks if they are not equal to each other
// it returns the opposite of whether they are equal or not 

bool operator!=(const Lexicon& lhs, const Lexicon& rhs) {
  return !(lhs == rhs);
}

// This function returns true if every word in lhs is also in rhs
// meaning lhs is a subset of rhs otherwise, it returns false

bool operator<=(const Lexicon& lhs, const Lexicon& rhs) {
  for (size_t i = 0; i < lhs.size(); i++) {
    if (!rhs.contains(lhs[i])) return false;
  }
  return true;
}

// returns true if lhs is a strict subset of rhs
// all of its words are in rhs, and it has fewer words
bool operator<(const Lexicon& lhs, const Lexicon& rhs) {
  return (lhs <= rhs) && (lhs.size() < rhs.size());
}

// returns true if lhs is a superset of rhs 
// meaning rhs is a subset of lhs
bool operator>=(const Lexicon& lhs, const Lexicon& rhs) {
  return rhs <= lhs;  // reverse of subset
}

//returns true if lhs is a strict superset of rhs
// it contains all of rhs’s words and more
bool operator>(const Lexicon& lhs, const Lexicon& rhs) {
  return (lhs >= rhs) && (lhs.size() > rhs.size());
}







 

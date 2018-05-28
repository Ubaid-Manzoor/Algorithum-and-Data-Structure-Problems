#include<iostream>
#include "LinkedList.h"
using namespace std;
int main(){
  LinkedList list;
  list.push_back(10);
  list.push_back(110);
  list.push_back(10);
  list.push_back(10);
  list.push_front(1);
  list.push_front(2);
  list.push_front(3);
  list.push_at(5,4);
  // list.pop_back();
  // list.pop_front();
  list.pop_at(3);
  list.PrintList();
  list.reverselist();
}

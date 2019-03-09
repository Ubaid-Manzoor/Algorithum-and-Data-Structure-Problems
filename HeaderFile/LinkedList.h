#ifndef MinHeap_H
#define MinHeap_H
#include<iostream>
#include<stdio.h>
using namespace std;
class Node{
public:
  int data;
  Node* next;
};
class LinkedList{
private:
  Node* Start;
  Node List;
public:
  LinkedList(){
    Start = NULL;
  }
  LinkedList(int size){
    Start = NULL;
    for(int i = 0 ; i < size ; i++){
      push_back(0);
    }
  }
  Node* CreateNode(int data){
    Node* temp = new Node;
    temp->data = data;
    temp->next = NULL;
    return temp;
  }
  void push_back(int data){
    Node* temp = Start;
    Node* CurrentNode = CreateNode(data);
      if(Start == NULL){
        Start = CurrentNode;
        return;
      }
      while(temp->next != NULL){
        temp = temp->next;
      }
      temp->next = CurrentNode;

  }
  void push_front(int data){
    Node* CurrentNode = CreateNode(data);
    Node* temp = Start;
    Start = CurrentNode;
    CurrentNode->next = temp;
  }
  void push_at(int position,int data){
    if(position == 1){
      push_front(data);
      return;
    }
    Node* temp = Start;
    Node* CurrentNode = CreateNode(data);
    int i = 1;
    while(i<position-1){
      temp = temp->next;
      i++;
    }
    Node* NextNode = temp->next;
    temp->next = CurrentNode;
    CurrentNode->next = NextNode;
  }
  void pop_back(){
    Node* temp = Start;
    while(temp->next->next != NULL){
      temp = temp->next;
    }
    delete(temp->next);
    temp->next = NULL;
  }
  void pop_front(){
    Node* temp = Start;
    Start = Start->next;
    delete(temp);
  }
  void pop_at(int position){
    if(position == 1){
      pop_front();
    }
    Node* temp = Start;
    int i = 1;
    while(i<position - 1){
      temp = temp->next;
      i++;
    }
    Node* RightList = temp->next->next;
    delete(temp->next);
    temp->next = RightList;
  }
  void PrintList(){
    Node* temp = Start;
    while(temp != NULL){
      cout<<temp->data<<" ";
      temp = temp->next;
    }
    cout<<endl;
  }
  void reverselist(){
      Node* visited = Start;
      Node* RevStart = NULL;
      while(visited != NULL){
        if(RevStart == NULL){
            Node* CurrentNode = CreateNode(visited->data);
            RevStart = CurrentNode;
        }else{
          Node* CurrentNode = CreateNode(visited->data);
          Node* temp = RevStart;
          RevStart = CurrentNode;
          CurrentNode->next = temp;
        }
          visited = visited->next;
      }
  }
};
#endif

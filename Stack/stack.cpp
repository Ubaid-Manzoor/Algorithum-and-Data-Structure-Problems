#include<iostream>
using namespace std;
class node{
public:
  int data;
  node* next;
};
class List_Stack{
private:
  node* Start;
  node* CreateNode(int a){
    node* temp = new node;
    temp->data = a;
    temp->next = NULL;
    return temp;
  }
public:
  List_Stack(){
    Start = NULL;
  }
  void push(int a){
    node* trav = Start;
    node* New = CreateNode(a);
    if(trav == NULL){
      Start = New;
      return;
    }
    Start = New;
    New->next = trav;
  }
  void pop(){
    node* trav = Start;
    if(Start == NULL){
      cout<<"Stack Empty";
      return;
    }
    Start = Start->next;
    delete trav;
  }
  void PrintStack(){
    node* trav = Start;
    if(trav == NULL){
      cout<<"List is Empty";
    }
    while(trav != NULL){
      cout<<trav->data<<"  ";
      trav = trav->next;
    }
    cout<<endl;
  }
};
class Arr_Stack{
private:
  int stack[10];
  int length;
public:
  Arr_Stack(){
    length = 0;
  }
  void push(int a){
    stack[length] = a;
    length++;
  }
  int pop(){
    int last_element = stack[length];
    length--;
    return last_element;
  }
  void PrintStack(){
    for(int i = 0 ; i < length ; i++){
      cout<<stack[i]<<"  ";
    }
    cout<<endl;
  }
};
int main(){
  Arr_Stack S;
  S.push(1);
  S.push(2);
  S.push(3);
  S.push(4);
  S.PrintStack();
  S.pop();
  S.PrintStack();
  S.pop();
  S.PrintStack();
  S.pop();
  S.PrintStack();
}

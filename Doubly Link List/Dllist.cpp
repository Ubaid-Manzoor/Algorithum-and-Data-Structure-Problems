#include<iostream>
using namespace std;
class node{
public:
  int data;
  node* next;
  node* prev;
};
class dllist{
private:
  node* Start;
  node* CreateNode(int a){
    node* temp = new node;
    temp->data = a;
    temp->next = NULL;
    temp->prev = NULL;
    return temp;
  }
public:
  dllist(){
    Start = NULL;
  }
  void insert(int a){
    node* New = CreateNode(a);
    node* trav = Start;
    if(Start == NULL){
      Start = New;
      return;
    }
    while(trav->next != NULL){
      trav = trav->next;
    }
    trav->next = New;
    New->prev = trav;
  }
  bool find(int a){
    node* trav = Start;
    while(trav != NULL){
      if(trav->data == a){
        cout<<"Found"<<endl;
        return true;
      }
      trav = trav->next;
    }
    cout<<"Not Found"<<endl;
    return false;
  }
  void Delete(int a){
    node* trav = Start;
    if(trav->data == a){
      Start = Start->next;
      Start->prev = NULL;
      delete trav;
      return;
    }
    while (trav != NULL) {
      if(trav->data == a){
        node* temp = trav;
        if(trav->next == NULL){
          trav->prev->next = NULL;
          delete temp;
          return;
        }
        trav->prev->next = trav->next;
        trav->next->prev = trav->prev;
        delete temp;
        return;
      }
      trav = trav->next;
    }
  }
  void PrintList(){
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
int main(){
  dllist l;
  l.insert(1);
  l.insert(2);
  l.insert(3);
  l.insert(4);
  l.insert(5);
  l.PrintList();
  l.Delete(5);
  l.PrintList();
}

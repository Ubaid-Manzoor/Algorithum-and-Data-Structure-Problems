#include<iostream>
using namespace std;
class node{
public:
  int data;
  node* next;
};
class sllist{
private:
  node* Start;
  node* CreateNode(int a){
    node* temp = new node;
    temp->data = a;
    temp->next = NULL;
    return temp;
  }
public:
  sllist(){
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
      delete trav;
      return;
    }
    while (trav != NULL) {
      if(trav->next->data == a){
        node* temp = trav->next;
        trav->next = trav->next->next;
        delete temp;
        return;
      }
      trav = trav->next;
    }
  }
  void insert_at(int post , int data){
    node* trav = Start;
    int CurrentPost = 1;
    node* New = CreateNode(data);
    if(post == 1){
      New->next = trav;
      Start = New;
      return;
    }
    if(post == 2){
      New->next = trav->next;
      trav->next = New;
      return;
    }
    while(CurrentPost != post - 2){
      trav = trav->next;
      CurrentPost++;
    }
    New->next = trav->next->next;
    trav->next->next = New;
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
  sllist l;
  l.insert(10);
  l.insert(101);
  l.insert(102);
  l.insert(103);
  l.PrintList();
  // l.find(10);
  // l.find(1011);
  l.insert_at(1,2);
  l.insert_at(4,6);
  l.PrintList();
  // l.Delete(103);
  // l.PrintList();
}

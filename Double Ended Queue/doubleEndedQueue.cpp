#include<iostream>
using namespace std;
class node{
public:
  int data;
  node* next;
};
class DEqueue{
private:
  int Queue[10];
  int front;
  int size;
  int back;
public:
  DEqueue(){
    front = 0;
    size = 0;
    back = 0;
  }
  void push_back(int a){
    if(size>10){
      cout<<"size Full";
      return;
    }
    Queue[back] = a;
    size++;
    back = (front+size)%10;
  }
  void push_front(int a){
    if(front-1 < 0 || front-back == -1 || front-back == 1){
      cout<<"data can be lost"<<endl;
      return;
    }
    if(size>10){
      cout<<"size full";
      return;
    }
    Queue[front-1] = a;
    front--;
    size++;
  }
  int pop_back(){
    int temp = Queue[back];
    size--;
    back--;
    return temp;
  }
  int pop_front(){
    int temp = Queue[front];
    front++;
    size--;
    return temp;
  }
  void PrintQueue(){
    for(int i = front ; i < size+front ; i++){
      int index = i%10;
      cout<<Queue[index]<<"  ";
    }
    cout<<endl;
  }
};
int main(){
  DEqueue Q;
  Q.push_back(1);
  Q.push_front(2);
  Q.push_back(3);
  Q.push_back(4);
  Q.push_back(5);
  Q.push_back(2);
  Q.push_back(4);
  Q.push_back(5);
  Q.push_back(2);
  Q.push_back(4);
  Q.push_back(5);
  Q.push_back(2);
  Q.push_back(4);
  Q.push_back(5);
  Q.push_back(2);
  Q.pop_back();
  Q.PrintQueue();
}

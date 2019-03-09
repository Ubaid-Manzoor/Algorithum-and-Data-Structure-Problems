#include<iostream>
using namespace std;
class list{
public:
  int coff;
  int power;
  list* next;
list(int Coff,int Pow){
    coff = Coff;
    power = Pow;
    next = NULL;
  }
};
class poly{
private:
  list* Head;
  int len;
public:
  poly(){
  }
  void Add_Term(int C,int P){
    cout<<"enter other term with power";
    cin>>C>>P;
    list* temp = Head;
    while(temp->next != NULL){
      temp= temp->next;
    }
    temp->next = new list(C,P);
  }
void Create_poly(int length){
  len = length;
  cout<<"enter first term with power";
  int P,C;
  cin>>C>>P;
  Head = new list(C,P);
  while(length > 1){
    Add_Term(C,P);
    length--;
  }
}
void PrintIt(){
  list* temp = Head;
  while(temp != NULL){
    cout<<temp->coff<<"^"<<temp->power<<" ";
    temp=temp->next;
  }
}
void Add(poly P1,poly P2){
  int len1 = P1.len;
  int len2 = P2.len;
  list* Head1 = P1.Head;
  list* Head2 = P2.Head;
  cout<<endl;
  while(Head1 != NULL && Head2 != NULL){
    if(Head1->power == Head2->power){
      int sum = Head1->coff + Head2->coff;
      cout<<sum<<"^"<<Head1->power<<" ";
      Head1 = Head1->next;
      Head2 = Head2->next;
    }else if(Head1->power < Head2->power){
      cout<<Head1->coff<<"^"<<Head1->power<<" ";
      Head1 = Head1->next;
     }else{
      cout<<Head2->coff<<"^"<<Head2->power<<" ";
      Head2 = Head2->next;
    }
  }
  if(Head1 != NULL){
    while(Head1 != NULL){
      cout<<Head1->coff<<"^"<<Head1->power<<" ";
      Head1 = Head1->next;
    }
    return;
  }
  if(Head2 != NULL){
    while(Head2 != NULL){
      cout<<Head2->coff<<"^"<<Head2->power<<" ";
      Head2 = Head2->next;
    }
    return;
  }
}
};
int main(){
  poly P1,P2,P;
  P1.Create_poly(2);
  P2.Create_poly(3);
  P1.PrintIt();
  cout<<endl;
  P2.PrintIt();
  P.Add(P1,P2);
}

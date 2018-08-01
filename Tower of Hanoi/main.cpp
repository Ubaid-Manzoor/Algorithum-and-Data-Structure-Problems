#include<iostream>
using namespace std;
void TOH(int n,string A,string B,string C){
  if(n == 1){
    cout<<"Take Step From "<<A<<" to "<<C<<endl;
    return;
  }
  TOH(n-1,A,C,B);
  cout<<"Take Step From "<<A<<" to "<<C<<endl;
  TOH(n-1,C,B,A);
}
int main(){
 TOH(3,"A","B","C");
}

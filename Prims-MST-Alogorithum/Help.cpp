#include<iostream>
using namespace std;
int Diviser(int number){
  for(int i = 2 ;i < number/2 ; i++){
    if(number%i == 0){
      return i;
    }
  }
    return 0;
}
int main(){
  int num = Diviser(343);
  cout<<num<<endl;
}

#include<iostream>
#include<fstream>
#include<vector>
using namespace std;


class Number{
public:
    int value;
Number(int temp){
    value = temp;
}
};


class Array_of_number{
private:
    vector<Number> Array;
public:
void ReadFile(){
    ifstream input;
    input.open("numbers.txt");
    int number;
    while(input >> number){
        Number temp(number);
        Array.push_back(temp);
    }
}
int Random_index(int l,int r)
{
	srand(time(NULL));
	int index=rand()%(r-l)+l;
	return (index);
}
int Helper_RSelection(vector<Number> &arr,int l_index ,int r_index,int ith_element){
    int lenght = r_index-l_index;
    if(lenght <=0){
        return arr[l_index].value;
    }
    int Current_random = Random_index(l_index,r_index);
    int pivot = arr[Current_random].value;
    //Swap first and  random Povit
    int t = arr[l_index].value;
    arr[l_index].value = arr[Current_random].value;
    arr[Current_random].value = t;
    //rest is same
    int i = l_index+1;
    for(int j = l_index+1 ; j <= r_index ; j++){
        if(arr[j].value < pivot){
            //Swap ith & jth element
            int temp = arr[j].value;
            arr[j].value = arr[i].value;
            arr[i].value = temp;
            i++;
        }
    }
    //Swap pivot with  (i-1)th element
    arr[l_index].value = arr[i-1].value;
    arr[i-1].value = pivot;
    if(ith_element == i-1){
        return pivot;
    }
    else if(ith_element < i-1){
        Helper_RSelection(arr,l_index,i-2,ith_element); // go to left part
    }
    else{
        Helper_RSelection(arr,i,r_index,ith_element); // go to right part
    }
}
int RSelection(int ith_element){
    return Helper_RSelection(Array,0,Array.size()-1,ith_element-1);
}
};
int main(){
    Array_of_number arr;
    arr.ReadFile();
    int number = arr.RSelection(222);
    cout<<number;
}

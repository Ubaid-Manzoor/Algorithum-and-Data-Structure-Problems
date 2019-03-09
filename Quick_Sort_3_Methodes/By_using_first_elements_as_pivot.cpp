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
    long int Number_of_Comparisons;
public:
Array_of_number(){
    Number_of_Comparisons = 0;
}
void ReadFile(){
    ifstream input;
    input.open("numbers.txt");
    int number;
    while(input >> number){
        Number temp(number);
        Array.push_back(temp);
    }
}
void Print_Array_and_Comparisons(){
    vector<Number>::iterator it;
    for(it = Array.begin() ; it != Array.end() ; it++){
        cout<<it->value<<endl;
    }
    cout<<"Comparisons == "<<Number_of_Comparisons<<endl;
}
void Helper_Quick_Sort(vector<Number> &arr,int l_index ,int r_index){
    int lenght = r_index-l_index;
    Number_of_Comparisons += lenght - 1;
    if(lenght <=0){
        return;
    }
    int pivot = arr[l_index].value;
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
    Helper_Quick_Sort(arr,l_index,i-2);
    Helper_Quick_Sort(arr,i,r_index);
}
void Quick_Sort(){
    Helper_Quick_Sort(Array,0,Array.size()-1);
}
};
int main(){
    Array_of_number arr;
    arr.ReadFile();
    arr.Quick_Sort();
    arr.Print_Array_and_Comparisons();
}

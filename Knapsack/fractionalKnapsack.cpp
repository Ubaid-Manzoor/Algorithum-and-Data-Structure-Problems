#include<iostream>
#include <bits/stdc++.h>
#define TotalItem  2
using namespace std;

class Item{
public:
    int weight;
    int value;
    void Print(){
        cout<<"("<<weight<<","<<value<<")"<<" ";
    }
    Item(int Value,int Weight){
        weight = Weight;
        value = Value;
    }
};

bool cmp(class Item a , class Item b){
    float r1 = (float)a.value / a.weight;
    float r2 = (float)b.value / b.weight;
    return r1>r2;
}

int fractionalKnapsack(int capacity , class Item arr[] , int len){
    sort(arr , arr+len , cmp);
    int currentWeight = 0;
    float finalValue = 0.0;
    for(int i = 0 ; i < len ; i++){
        if(currentWeight + arr[i].weight <= capacity ){
            arr[i].Print();
            currentWeight += arr[i].weight;
            finalValue += arr[i].value;
        }
        else{
            int weigthRemaing = capacity - currentWeight;
            finalValue += arr[i].value * ((float)weigthRemaing / arr[i].weight);
            break;
        }
    }
    return finalValue;
}

int main(){
    int capacity = 50;
    Item arr[] = {{60,10},{100,20},{120,30}};
    int len = sizeof(arr) / sizeof(arr[0]);
    cout<<fractionalKnapsack(capacity , arr , len);

    return 0;
}

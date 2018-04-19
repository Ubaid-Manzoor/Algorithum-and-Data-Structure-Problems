#include<iostream>
#include<vector>
#include<fstream>
using namespace std;
class Number{
public:
    int value;
Number(int temp){
    value = temp;
}
};
class Set_of_value{
private:
    vector<Number> Array;
public:
    void Helper_sort(vector<Number> &array){
        if(array.size() > 1){
            vector<Number> Left(&array[0],&array[array.size()/2]); // Left half
            vector<Number> Right(&array[array.size()/2],&array[array.size()]);//Right Hal
            Helper_sort(Left);
            Helper_sort(Right);
            //Merge Left & Right At Each Level
            int i1 = 0;
            int i2 = 0;
            cout<<"--->"<<Left.size();
            for(int i = 0 ; i < array.size() ; i++){
                if(i2 >= Right.size() || (i1 < Left.size() && Left[i1].value < Right[i2].value)){
                    array[i] = Left[i1].value;
                    i1++;
                }
                else{
                    array[i] = Right[i2].value;
                    i2++;
                }
            }
        }
    }
    void Sort(){
        Helper_sort(Array);
    }
    void Print_Sub(vector<Number> &array){
    cout<<"*********************************************************************";
        vector<Number>::iterator it;
        for(it  = array.begin() ; it != array.end() ; it++){
            cout<<it->value<<endl;
        }
    cout<<"*********************************************************************";
    }
    void Print_Array(){
        vector<Number>::iterator it;
        for(it  = Array.begin() ; it != Array.end() ; it++){
            cout<<it->value<<endl;
        }
    }
    void Read_Values(){
        ifstream input;
        input.open("numbers.txt");
        int number;
        while(input >> number)
        {
            Number temp(number);
            Array.push_back(temp);
        }
        input.close();
    }
};
int main(){
    Set_of_value arr;
    arr.Read_Values();
    arr.Sort();
    arr.Print_Array();
}

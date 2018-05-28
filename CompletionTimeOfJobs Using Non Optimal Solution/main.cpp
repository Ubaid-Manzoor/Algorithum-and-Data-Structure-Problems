#include<iostream>
#include<vector>
#include<fstream>
using namespace std;

class Job{
public:
  int Weight;
  int Lenght;
  int DifferenceOfWeightAndLenght;
};

class Set_of_Jobs{
private:
  int NumberOfJobs;
  vector<Job> Array;
public:
    void Helper_sort(vector<Job> &array){
        if(array.size() > 1){
            vector<Job> Left(&array[0],&array[array.size()/2]); // Left half
            vector<Job> Right(&array[array.size()/2],&array[array.size()]);//Right Hal
            Helper_sort(Left);
            Helper_sort(Right);
            //Merge Left & Right At Each Level
            int i1 = 0;
            int i2 = 0;
            cout<<"--->"<<Left.size();
            for(int i = 0 ; i < array.size() ; i++){
                if(i2 >= Right.size() || (i1 < Left.size() && Left[i1].DifferenceOfWeightAndLenght < Right[i2].DifferenceOfWeightAndLenght)){
                    array[i] = Left[i1];
                    i1++;
                }
                else if(i1 >= Left.size() || Left[i1].DifferenceOfWeightAndLenght > Right[i2].DifferenceOfWeightAndLenght){
                    array[i] = Right[i2];
                    i2++;
                }
                else{
                    if((Left[i1].Weight) >= (Right[i2].Weight)){
                        array[i] = Left[i1];
                        i1++;
                    }
                    else{
                        array[i] = Right[i2];
                        i2++;
                    }
                }
            }
        }
    }
    void Sort(){
        Helper_sort(Array);
    }
    // void Print_Sub(vector<Job> &array){
    // cout<<"*********************************************************************";
    //     vector<Job>::iterator it;
    //     for(it  = array.begin() ; it != array.end() ; it++){
    //         cout<<it->DifferenceOfWeightAndLenght<<endl;
    //     }
    // cout<<"*********************************************************************";
    // }
    // void Print_Array(){
    //     vector<Job>::iterator it;
    //     for(it  = Array.begin() ; it != Array.end() ; it++){
    //         cout<<it->Weight<<"  "<<it->Lenght<<"-->"<<it->DifferenceOfWeightAndLenght<<endl;
    //     }
    // }
      Job CreateJob(int job_weight,int job_lenght){
      Job Temp;
      Temp.Weight = job_weight;
      Temp.Lenght = job_lenght;
 //     cout<<Temp.Weight<<"  "<<Temp.Lenght<<endl;
      Temp.DifferenceOfWeightAndLenght = job_weight - job_lenght;
      return Temp;
    }
    void Read_Jobs(){
        ifstream input;
        input.open("Job_info.txt");
        input >> NumberOfJobs;
        int job_weight,job_lenght,DifferenceOfWeightAndLenght;
        while(input >> job_weight >> job_lenght)
        {
            Job temp = CreateJob(job_weight,job_lenght);
            Array.push_back(temp);
        }
        input.close();
        cout<<NumberOfJobs;
    }
    void ComputeTimeOfCompelition(){
      int TotalTime = 0;
      vector<Job>::iterator it;
      for(it = Array.begin() ; it != Array.end() ; it++){
        TotalTime = TotalTime + it->Lenght*it->Weight;
      }
      cout<<TotalTime;
    }
};
int main(){
    Set_of_Jobs arr;
    arr.Read_Jobs();
    arr.Sort();
    // arr.Print_Array();
    arr.ComputeTimeOfCompelition();
}

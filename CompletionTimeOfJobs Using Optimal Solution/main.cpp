#include<iostream>
#include<vector>
#include<fstream>
using namespace std;

class Job{
public:
  float Weight;
  float Lenght;
  float RatioOfWeightAndLenght;
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
            for(int i = 0 ; i < array.size() ; i++){
                if(i2 >= Right.size() || (i1 < Left.size() && Left[i1].RatioOfWeightAndLenght < Right[i2].RatioOfWeightAndLenght)){
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
    void Sort(){
        Helper_sort(Array);
    }
    // void Print_Sub(vector<Job> &array){
    // cout<<"*********************************************************************";
    //     vector<Job>::iterator it;
    //     for(it  = array.begin() ; it != array.end() ; it++){
    //         cout<<it->RatioOfWeightAndLenght<<endl;
    //     }
    // cout<<"*********************************************************************";
    // }
    // void Print_Array(){
    //     vector<Job>::iterator it;
    //     for(it  = Array.begin() ; it != Array.end() ; it++){
    //         cout<<it->Weight<<"  "<<it->Lenght<<"-->"<<it->RatioOfWeightAndLenght<<endl;
    //     }
    // }
      Job CreateJob(float job_weight,float job_lenght){
      Job Temp;
      Temp.Weight = job_weight;
      Temp.Lenght = job_lenght;
      Temp.RatioOfWeightAndLenght = job_weight/job_lenght;
      return Temp;
    }
    void Read_Jobs(){
        ifstream input;
        input.open("Job_info.txt");
        input >> NumberOfJobs;
        float job_weight,job_lenght,RatioOfWeightAndLenght;
        while(input >> job_weight >> job_lenght)
        {
            Job temp = CreateJob(job_weight,job_lenght);
            Array.push_back(temp);
        }
        input.close();
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

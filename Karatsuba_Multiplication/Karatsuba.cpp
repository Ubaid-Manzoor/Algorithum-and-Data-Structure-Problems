#include<iostream>
#include<string>
using namespace std;
string add(string lhs, string rhs) {
    int carry = 0;
    string result;
    int length = max(lhs.size(), rhs.size());

    while (lhs.size() < length)
      lhs.insert(0,"0");

    while (rhs.size() < length)
      rhs.insert(0,"0");

    for(int i = length-1; i >= 0 ;i--){
        int ver_sum  = (lhs[i]-'0') + (rhs[i]-'0') + carry;
        carry = ver_sum/10;
        result.insert(0,to_string(ver_sum%10));
    }

    if(carry){
        result.insert(0,to_string(carry));
    }

    return result.erase(0, min(result.find_first_not_of('0'), result.size()-1));
}

string subtract(string a, string b) {
    int length = max(a.size(),b.size());
    int diff;
    string result;
    while(a.size() < length){
        a.insert(0,"0");
    }
    while(b.size() < length){
        b.insert(0,"0");
    }
    for(int i = length-1 ; i >=0 ; i--){
    diff = (a[i] - '0') - (b[i] - '0');
        if(diff >= 0){
            result.insert(0,to_string(diff));
        }
        else{
        int j = i-1;
            while(j >= 0){
                if(a[j] == 0){
                    a[j] = 9;
                    j--;
                }
                else{
                    a[j] = a[j] - 1;
                    result.insert(0,to_string(diff+10));
                    break;
                }

            }
        }
    }
    result =  result.erase(0, min(result.find_first_not_of('0'), result.size()-1));
    return result;
}
int max(int a,int b){
    return (a>b)?a:b;
}
string multiply(string str1,string str2){
    int length = max(str1.size() , str2.size());
    if(length == 1){
         return to_string((str1[0]-'0')*(str2[0]-'0'));
    }
    while(str1.size() < length){
        str1.insert(0,"0");
    }
    while(str2.size() < length){
        str2.insert(0,"0");
    }
    string a = str1.substr(0,length/2);
    string b = str1.substr(length/2,length-length/2);
    string c  = str2.substr(0,length/2);
    string d = str2.substr(length/2,length-length/2);

    string ac = multiply(a,c);
    string bd = multiply(b,d);
    string ab_cd = multiply(add(a,b),add(c,d));

    string ab_plus_cd = subtract(ab_cd,add(ac,bd));

    for(int i = 0 ; i < 2*(length - length/2) ; i++){
        ac.append("0");
    }
    for(int i = 0;i < length - length/2;i++){
        ab_plus_cd.append("0");
    }
    string Result = add(ac,add(bd,ab_plus_cd));
    return Result.erase(0, min(Result.find_first_not_of('0'), Result.size()-1));
}
int main(){
    string num1,num2;
    cout<<"enter the two values to multiply and feel free to enter any length number"<<endl;
    cin>>num1>>num2;
    string Result = multiply(num1,num2);
    cout<<Result;
}

#include<iostream>
#include<cmath>
#include<string.h>
using namespace std;

class hamming{
public:
  void hamm(){
    int n,c,w,pc,g,error = 1,rev,temp;
    c = 0;
    cout<<"1.Even Parity\n2.Odd Parity\n";
    cin>>g;
    cout<<"Enter Lenght\n";
    cin>>n;
    int num[n];
    cout<<"Enter your number\n";
    for(int i = 0;i <  n;i++){
      cin>>num[i];
    }
    //Parity Bit Calculation
    for(int i = 0;i < n;i = pow(2,c) - 1){
      w = i+1;
      pc = 0;
      cout<<"\n";
      for(int j = i;j<n;j=j+w+w){
        for(int k = j;k<j+w;k++){
          if(k<n){
            if(num[k] == 1){
              pc = pc + 1;
            }
          }
        }
      }
      //Printing Parity Bits
      if(pc%2==0){
        if(g==1){
          cout<<"Parity "<<c + 1<<" = 0\n";
          error = error * 10;
      }
        else{
          cout<<"Parity "<<c + 1<<" = 1\n";
          error = error * 10 + 1;
        }

      }
      else{
        if(g==2){
          cout<<"Parity "<<c + 1<<" = 0\n";
          error = error * 10;
        }
        else{
          cout<<"Parity "<<c + 1<<" = 1\n";
          error = error * 10 + 1;
        }
      }
      cout<<"\n";
      c++;
    }
    rev = 0;
    while(error != 0){
      temp = error % 10;
      rev = rev * 10 + temp;
      error = error / 10;
    }
    rev = rev / 10;
    int ans,t;
      c = 0;
      ans = 0;
      n = rev;
      /*Calculating Error Bits
      Binary to Decimal*/
      while(n>0){
        t = n % 10;
        if(t != 0 && t!= 1){
          break;
        }
        ans = ans + t * pow(2,c);
        c++;
        n = n / 10;
      }
      cout<<"Error bit is = "<<ans<<endl;
  }
};

int main(){
  hamming h;
  h.hamm();
  return 0;
}

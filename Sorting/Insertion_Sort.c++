#include <bits/stdc++.h>
using namespace std;
int main(){
    int arr[6]={7,2,4,1,5,3};
    int hole;
    for(int i=0;i<6;i++){
        std::cout<<arr[i]<<" ";
    }
    cout<<"\n";
    for(uint i=1;i<6;i++){
        hole=i;
        while(hole>0 && arr[hole-1]>arr[hole]){
            int temp=arr[hole-1];
            arr[hole-1]=arr[hole];
            arr[hole]=temp;
            hole--;
        }
    }
    for(int i=0;i<6;i++){
        std::cout<<arr[i]<<" ";
    }
}
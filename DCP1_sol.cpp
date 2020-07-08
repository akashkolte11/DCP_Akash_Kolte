#include <bits/stdc++.h>
using namespace std;

int main(){

    int arr[4] = {10, 15, 3, 7};
    int n = sizeof(arr)/sizeof(arr[0]);
    sort(arr, arr+n);
    int i=0;
    int j=n-1;
    int k = 17;
    while(i<j){
        if(arr[i]+arr[j]==k){
            cout << "True";
            break;
        }
        else if(arr[i]+arr[j]<k){
            i++;
        }
        else{
            j--;
        }
    }
    if(arr[i]+arr[j]!=k){
            cout<<"No such pair exists";
        }
   return 0;
}

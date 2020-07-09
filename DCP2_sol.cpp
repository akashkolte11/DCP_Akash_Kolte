#include <bits/stdc++.h>
using namespace std;

void Product(int arr[], int n){
    if(n==1){
        cout << "Array has only one element";
        return;
    }
    int left[n];
    int right[n];
    left[0]=arr[0];
    right[n-1]=arr[n-1];
    for(int i=0; i<n-1; i++){
        left[i+1]=left[i]*arr[i+1];
        right[n-i-2]=right[n-i-1]*arr[n-i-2];
    }
    int ans[n];
    left[-1]=1;
    right[n]=1;
    for(int i=0; i<n; i++){
        ans[i]=left[i-1]*right[i+1];
    }
    int i=0;
    while(i<n){
        cout<<ans[i]<<" ";
        i++;
    }
    return;
}

int main(){
    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr)/sizeof(arr[0]);
    Product(arr, n);
   return 0;
}


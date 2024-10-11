#include<bits/stdc++.h>
using namespace std;

#define foi(n) for(int i = 0; i < n; ++i)
#define foj(n) for(int j = 0; j < n; ++j)
  
void bucketSort(float arr[], int n)
{
    vector<float> b[n];
    foi(n){
        int bi=n*arr[i]; 
        b[bi].push_back(arr[i]);
    }
    foi(n)
        sort(b[i].begin(), b[i].end());
    int index = 0;
    foi(n)
        foj(b[i].size())
            arr[++index] = b[i][j];
}
  
int main()
{
    float arr[]={0.2 , 0.478,0.936,0.945, 0.325, 0.653,0.293};
    int n=sizeof(arr)/sizeof(arr[0]);
    bucketSort(arr, n);
    //display the sorted array
    foi(n)
        cout<<arr[i]<<" ";
}

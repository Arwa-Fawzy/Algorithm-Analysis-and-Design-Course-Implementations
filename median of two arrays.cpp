#include <bits/stdc++.h>
using namespace std;

#define foi(n) for (int i=0; i<n; ++i)
#define foj(y) for (int j=0; j<y; ++j)
 
int Solve(int arr[], int n)
{
    if (n % 2 == 0){
       int z=n/2, s=arr[z], y=arr[z-1], ans=(s+y)/2;
       return ans;
    }else{
       int z = round(n/2);
       return arr[z];
     }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    int arr1[] = { 1, 2, 3, 4, 5 }, arr2[] = { 6, 7, 8, 9, 10, 11};
    int p =sizeof(arr1)/sizeof(arr1[0]), j=sizeof(arr2)/sizeof(arr2[0]), arr3[p+j], l=p+j;
    // Merging the two array into one array
    foi(p){
        arr3[i]=arr1[i];
    }int a=0; 
    foi(l){
        arr3[i]=arr2[++a];
    }
    sort(arr3,arr3+l);
    cout<<"The median is "<<Solve(arr3, l);
}
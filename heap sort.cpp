#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define fo(n) for(int i=0; i<n; ++i)

void heapify(int arr[], int n, int i)
{
    ll largest = i, l = 2 * i + 1, r = 2 * i + 2;
    if (l<n && arr[l]>arr[largest])
        largest=l;
    if (r<n && arr[r]>arr[largest])
        largest=r;
    if (largest!=i) {
        swap(arr[i],arr[largest]);
        heapify(arr,n,largest);
    }
}

void heapSort(int arr[], int n)
{
    for(int i=n/2-1; i>=0; --i)
        heapify(arr,n,i);
    for(int i=n-1; i>0; --i) {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    int arr[]={5, 13, 2, 25, 7, 17, 20, 8, 4}, n=sizeof(arr)/sizeof(1);
    heapSort(arr, n);
    cout<<"The array after sorting is: ";
    fo(n){cout<<arr[i]<<" ";}
}
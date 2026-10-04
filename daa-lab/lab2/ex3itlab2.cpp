#include <iostream>
using namespace std;            
    
int binarysearchiterative(int arr[],int n,int x){
    
    int low=0;int high=n-1;
    while(low<=high){
        int mid=low+(high-low)/2;
        if(arr[mid]==x)return mid;
        else if(arr[mid]>x)high=mid-1;
        else low=mid+1;
    }
    return -1;
}
int main()
{
    int n;
cout<<"enter the size of array: ";
cin>>n;
int arr[n];
cout<<"elements in array in sorted order";
for (int i = 0; i < n; i++)
{
    cin>>arr[i];
}
int x;
cout<<"enter the desired no.: ";
cin>>x;
int result =binarysearchiterative(arr,n,x);
cout<<"result: "<<result;



}
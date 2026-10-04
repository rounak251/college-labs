//min and max of an arr using ls
#include <iostream>
using namespace std;
void lsminmax(int arr[],int n){
int min=arr[0];
int max=arr[0];
for (int i = 1; i < n; i++)
{
  if(min>arr[i]) min =arr[i];
  if(max<arr[i]) max=arr[i];
}
cout<<"minimun "<<min<<endl;
cout<<"maximum"<<max<<endl;
}int main() {
    int arr[] = {3, 5, 1, 8, 2};
    int n = sizeof(arr)/sizeof(arr[0]);
    lsminmax(arr, n);
    return 0;
}

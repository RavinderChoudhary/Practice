/**
 * linearSearch
 * binarySearch
 * interpolationSearch
**/
#include <bits/stdc++.h>
using namespace std;
int linearSearch(vector<int> arr,int key){
    for(int i=0;i<arr.size();i++)
        if(arr[i] == key)
          return i;
    return -1;
}
int binarySearch(vector<int> arr,int key){
    int low = 0;
    int high = arr.size() - 1;
    while(low <= high){
        int mid = (low + high) / 2;
        if(arr[mid] == key)
          return mid;
        else if(arr[mid] > key)
          high = mid - 1;
        else  low = mid + 1;
    }
    return -1;
}
int interpolationSearch(vector<int> arr,int key){
    int low = 0;
    int high = arr.size() - 1;
    
    while(low <= high && key <= arr[high] && key >= arr[low]){
      int index = low +  ((double)(high - low)/(arr[high] - arr[low])) * (key - arr[low]);
      if(arr[index] == key)
        return index;
      else if(arr[index] > key)
        high = index - 1;
      else low = index + 1;
    }
    return -1;
}
int main(){
   vector<int> arr{ 1,2,3,6,13,21,22,24,25,76,78 };
   int key = 74;
   int pos = (*linearSearch) (arr , key);
   pos == -1 ? cout<<"Not Found"<<endl : cout<<pos<<endl;
   
   int (*ptr) (vector<int> , int);
   ptr = binarySearch;
   pos = ptr(arr , key);
   pos == -1 ? cout<<"Not Found"<<endl : cout<<pos<<endl;
   
   pos = (*interpolationSearch) (arr , key);
   pos == -1 ? cout<<"Not Found"<<endl : cout<<pos<<endl;
}

/**
 * knapsackRecursion
 * knapsackDP
 * knapsackGreedyApproach
**/
#include <bits/stdc++.h>
using namespace std;
int knapsackRecursion(vector<int> value,vector<int> weight,int Cap,int n){
      if(n == -1 || Cap == 0)
        return 0;
      if(weight[n] > Cap) return knapsackRecursion(value,weight,Cap,n-1);
      return max(value[n] + knapsackRecursion(value,weight,Cap-weight[n],n-1) , knapsackRecursion(value,weight,Cap,n-1));
}
void knapsackDP(vector<int> value,vector<int> weight,int Cap,int n){
     vector<vector<int> > dp(n+1,vector<int>(Cap+1,0));
     
     for(int i=0;i<=n;i++){
         for(int c=0;c<=Cap;c++){
             if(c == 0) dp[i][c] = 0; 
             else if(i == 0) dp[i][c] = 0;
             else if(c < weight[i-1]) dp[i][c] = dp[i-1][c];
             else dp[i][c] = max(dp[i-1][c] , dp[i-1][c-weight[i-1]] + value[i-1]);
         }
     }
     
     for(int i=0;i<=n;i++){
         for(int c=0;c<=Cap;c++){
             cout<<dp[i][c]<<" ";
         }
         cout<<endl;
     }
}
void knapsackGreedyApproach(vector<int> value,vector<int> weight,int Cap,int n){
     vector<pair<float,int> > profit;
     
     for(int i=0;i<n;i++)
        profit.push_back({value[i]/(weight[i]*1.0),i});
     sort(profit.begin(),profit.end(),[] (pair<float,int> p1,pair<float,int> p2) -> bool { return p1.first > p2.first; });
     
     float sum = 0;
     for(int i=0;i<n;i++){
         int index = profit[i].second;
         if(Cap >= weight[index]){
           Cap -= weight[index];
           sum += value[index];
         }
         else{
            sum += (Cap/(weight[index]*1.0)) * value[index]; 
            break;
         } 
     }
     cout<<sum;
}
int main() {
	vector<int> value{ 10,5,15,7,6,18,3 };
	vector<int> weight{ 2,3,5,7,1,4,1 };
	int Cap = 15;
	int n = value.size();
	cout<<knapsackRecursion(value,weight,Cap,n-1)<<endl;
	knapsackDP(value,weight,Cap,n);
	knapsackGreedyApproach(value,weight,Cap,n);
	return 0;
}

// https://www.codechef.com/problems/DIVMULT

#include <bits/stdc++.h>
using namespace std;


long long int query(long long int *block,long long int *a,long long int l,long long int r,long long int rn)
{
     long long int ans=0;
     
     //left part
     while((l-1)%rn!=0 && l<r && l!=1)
     {
         ans+=(a[l]*a[l]);
         l++;
     }
     
     //middle part 
     while(l+rn<=r)
     {
         int block_id=l/rn;
         ans+=block[block_id];
         l+=rn;
     }
     
     //right part
     while(l<=r)
     {
         ans+=(a[l]*a[l]);
         l++;
     }
     return ans;
      
}

void build(long long int *block,long long int *a,int n ,int rn)
{
 int block_id=-1;
 
 for(int i=1;i<=n;++i)
 {
     if((i-1)%rn==0)
     {block_id++;
     block[block_id]=0;
         
     }
     
     block[block_id]+=(a[i]*a[i]);
 }    
}

int main()
{
    
long long  int n,q,ty,l,r;
 cin>>n>>q;
 
long long  int a[100005];
long long  int rn=sqrt(n);
 long long int *block=new long long int[rn+1]{0};
long long int ans=0;
 
 for(int i=1;i<=n;++i)
 cin>>a[i];
 //build
 int block_id=-1;
 
 for(int i=1;i<=n;++i)
 {
     if((i-1)%rn==0)
     block_id++;
     
     block[block_id]+=(a[i]*a[i]);
 }
 

 while(q--)
 {
     cin>>ty>>l>>r;
     
     if(ty==1)
     {
       cout<<query(block,a,l,r,rn)<<endl;
     }
 
    else
    {
     for(int i=l;i<=r;++i)
     {
         if(i%2==0)
         {
             if(a[i]%256==0)
             a[i]=a[i]/256;
             
             else
             a[i]=a[i]*2;
         }
         else{
             if(a[i]%2==0)a[i]=a[i]/2;
             else
             a[i]=a[i]*256;
         }
     }
     build(block,a,n,rn);

 
    }
 
  }
 
}

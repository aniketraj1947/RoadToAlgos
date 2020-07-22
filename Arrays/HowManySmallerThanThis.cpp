/*

Leet Code : https://leetcode.com/problems/how-many-numbers-are-smaller-than-the-current-number/

Given the array nums, for each nums[i] find out how many numbers in the array are smaller than it. That is, for each nums[i] you have to count the number of valid j's such that j != i and nums[j] < nums[i].

Return the answer in an array.


*/


#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define rep(n) for(int i=0;i<n;++i)
#define repi(n) for(int i=1;i<=n;++i)
#define repj(n) for(int j=0;j<n;++j)
int mod=1000000007;
using namespace std;

int power(int xui, int y, int p) 
{ 
	// (xui ^ y ) % p
    int result = 1;
    xui = xui % p; 
  
    while (y > 0) 
    { 
        if (y & 1) 
            result = (result*xui) % p; 
        y = y>>1;
        xui = (xui*xui) % p;   
    } 
    return result%mod; 
}
 
int modInv(int n) 
{ 
    return power(n,mod-2,mod);
}

int32_t main() {
    fast;
    int t;
    cin>>t;
    while(t--){
       int n;
       cin>>n;
       vector<int> v(n);
       rep(n)cin>>v[i];
        vector<int>a(10000);
        vector<int>b(10000);
        for(int i=0;i<n;i++)  // making the frequency array
            a[v[i]]++;
        for(int i=1;i<10000;i++)  //filling the prefix sum array
            b[i]=b[i-1]+a[i-1];

        for(int i=0;i<n;i++){
           cout<<b[v[i]]<<" ";
        }
        cout<<'\n';
    }//end of tt
    

}
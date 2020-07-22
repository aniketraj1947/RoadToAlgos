vector<int> Solution::plusOne(vector<int> &A) {
    vector<int> ans;
    int n = A.size();
    int lastDigit= A[n-1];
    if(lastDigit<9){
        int f=0;
        for(int i=0;i<A.size()-1;++i){
            if(f==0 && A[i]==0)continue;
            f=1;
            ans.push_back(A[i]);
        }
        ans.push_back(A[A.size()-1]+1);
        return ans;
    }
    else{
        reverse(A.begin(),A.end());
        A.push_back(0);
        int p=0;
        for(int i=0;i<A.size();++i){
            if(A[i]==9 && p==0)ans.push_back(0);
            else if(p==0){
                p=1;
                ans.push_back(A[i]+1);
            }
            else{
                ans.push_back(A[i]);
            }
        }
        reverse(ans.begin(),ans.end());
        int f=0;
        vector<int> ans2;
        for(int i=0;i<ans.size();++i){
            if(f==0 && ans[i]==0)continue;
            f=1;
            ans2.push_back(ans[i]);
        }
        return ans2;
        
    }
}

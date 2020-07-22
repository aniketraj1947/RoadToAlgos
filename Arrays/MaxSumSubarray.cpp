//Find the contiguous subarray within an array, A of length N which has the largest sum.

int Solution::maxSubArray(const vector<int> &A) {
    int sum_so_far=0;
    int max_so_far=0;
    for(int i=0;i<A.size();++i){
        max_so_far=max(max_so_far,sum_so_far);
        if(sum_so_far+A[i]>0){
            sum_so_far+=A[i];
        }
        else{
            max_so_far=max(max_so_far,sum_so_far);
            sum_so_far=0;
        }
    }
    int f=0;
    for(int i=0;i<A.size();++i){
        if(A[i]>0){f=1;break;}
    }
    if(f==1)return max_so_far;
    else return *max_element(A.begin(),A.end()); 
}


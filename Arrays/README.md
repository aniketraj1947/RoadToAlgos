#   Arrays

## Here are few tips for solving questions involving arrays

 1.  Understand the concept of Prefix Sum array from GeekForGeeks portal. Solve some questions on that. This will be a good start in dealing with beginner level questions of Arrays. Example Here : HowManySmallerThanThis.cpp

Another Example from GFG, 

Consider an array of size n with all initial values as 0. Perform given ‘m’ add operations from index ‘a’ to ‘b’ and evaluate highest element in array. An add operation adds 100 to all elements from a to b

1 : Run a loop for 'm' times, inputting 'a' and 'b'.
2 : Add 100 at index 'a' and subtract 100 from index 'b+1'.
3 : After completion of 'm' operations, compute the prefix sum array.
4 : Scan the largest element and we're done.

 2. Max Sum Contiguous Array is another classical problem in this category. Try get the intuition of such problems where you have a sliding window and you keep traversing as long as it is going good for you and otherwise flip it back to start while saving the last config in max_sum_so_far. That's a classic approach in many beginner level problems. Example here : MaxSumSubarray.cpp

 3. Also have a look at Add 1 to a number represented by an array of its digits. Have uploaded my solution which is not so readable and longer than publicly available solutions but if you understand it, you'll get the intuition better than crispy solutions available online.

 4. Bucketing is also a common strategy in arrays where you split the arrays and then approach the problem. An ez pz example could be sort an array only made of 0s, 1s and 2s. A good example of bucketing could be find if there exists a triplet in the given array such that 1 < x + y + z < 2. Here we partition the array as A=(0,2/3), B=[2/3,1], C=(1,2) and list out cases and solve!

 5. Many a times, a problem needs only customised sorting. This can be by using : `sort(v.begin(),v.end(),myCompare)`. Now you may simply write a function `int myCompare(int i,int j)` and return i < j logic based on your custom need. Example Here : ComparisonSort.cpp


class NumArray {
public:
    NumArray(vector<int>& nums) : theNums(nums){
        size_t i = {};
        thePrefixSum.push_back(theNums[i]);
        ++i;
        for (; i<theNums.size(); i++)
        {
            thePrefixSum.push_back(thePrefixSum[i-1] + theNums[i]);
        }
    }
    
    int sumRange(int left, int right) {
        return thePrefixSum[right] - thePrefixSum[left] + theNums[left];
    }

private:
    const std::vector<int> theNums;
    std::vector<int> thePrefixSum;
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */
class KthLargest {
public:
 int el=0;
 vector<int>arr;
    KthLargest(int k, vector<int>& nums) {
        el=k;
        arr.resize(nums.size());
        arr=nums;
    }
    
    int add(int val) {
        arr.push_back(val);
        sort(arr.rbegin(),arr.rend());
        return arr[el-1];
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
class Solution {
public:
int Binsearch(vector<int>arr, int l, int h, int key)
{
	if (l > h)
		return -1;

	int mid = (l + h) / 2;
	if (arr[mid] == key)
		return mid; 
	if (arr[l] <= arr[mid]) {
	
		if (key >= arr[l] && key <= arr[mid])
			return Binsearch(arr, l, mid - 1, key);
	 
		return Binsearch(arr, mid + 1, h, key);
	}
 
	if (key >= arr[mid] && key <= arr[h])
		return Binsearch(arr, mid + 1, h, key);

	return Binsearch(arr, l, mid - 1, key);
}

    int search(vector<int>& nums, int target) {
        return Binsearch(nums,0,nums.size()-1,target);
    }
};
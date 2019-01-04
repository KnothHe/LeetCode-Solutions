class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int total = nums1.size() + nums2.size();
        if (total & 0x1) 
            return findKth(nums1, 0, nums2, 0, total/2+1);
        else
            return (findKth(nums1, 0, nums2, 0, total/2) 
                + findKth(nums1, 0, nums2, 0, total/2+1)) / 2.0;
    }
    double findKth(vector<int> &nums1, int n1, vector<int> &nums2, int n2, int k) {
        if (n1 >= nums1.size()) return nums2[n2+k-1];
        if (n2 >= nums2.size()) return nums1[n1+k-1];
        if (k == 1) return min(nums1[n1], nums2[n2]);
        int tmpn1 = n1 + k/2 - 1 < nums1.size() ? nums1[n1+k/2-1] : INT_MAX;
        int tmpn2 = n2 + k/2 - 1 < nums2.size() ? nums2[n2+k/2-1] : INT_MAX;
        if (tmpn1 < tmpn2)
            return findKth(nums1, n1 + k/2, nums2, n2, k - k/2);
        else
            return findKth(nums1, n1, nums2, n2 + k/2, k - k/2);
    }
};

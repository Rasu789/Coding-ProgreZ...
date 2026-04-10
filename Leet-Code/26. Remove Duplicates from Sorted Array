class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        
        // Step 1: create a vector initialized with '_'
        vector<int> ans(n, -1); // using -1 as placeholder
        
        // Step 2: use stack to keep unique elements
        stack<int> st;
        
        for (int i = 0; i < n; i++) {
            if (st.empty() || st.top() != nums[i]) {
                st.push(nums[i]);
            }
        }
        
        // Step 3: transfer stack to vector (reverse order)
        int k = st.size();
        int index = k - 1;
        
        while (!st.empty()) {
            ans[index--] = st.top();
            st.pop();
        }
        
        // Step 4: copy back to nums
        for (int i = 0; i < k; i++) {
            nums[i] = ans[i];
        }
        
        return k;
    }
};

// class Solution {
// public:
//     void rotate(vector<int>& nums, int k) {
//         int n = nums.size();
//         vector<int> res(n);
//         k=k%n;

//         //SOLUTION 1
//         int j=0;
//         for(int i=n-k;i<n;i++){
//             res[j++]=nums[i];
//         }

//         for(int i=0;i<n-k;i++){
//             res[j++]=nums[i];
//         }

//         for(int i=0;i<n;i++){
//             nums[i] = res[i];
//         }

//         // SOLUTION 2
//         // reverse(nums.begin(),nums.begin()+n-k);
//         // reverse(nums.begin()+n-k,nums.end());
//         // reverse(nums.begin(),nums.end());
//     }
// };

class Solution {
public:

    void reverseArray(vector<int> &nums, int s, int e) {
        while(s < e) {
            swap(nums[s],nums[e]);
            s++;
            e--;
        }
    }
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k%n;
        cout<<n<<endl;
        cout<<k<<endl;
        reverseArray(nums, 0, n-k-1);
        for(int i = 0; i < n - k ; i++){
            cout<<nums[i]<<" ";
        }
        cout<<endl;
        reverseArray(nums, n-k, n-1);
        for(int i = n-k; i < n ; i++){
            cout<<nums[i]<<" ";
        }
        reverseArray(nums,0,n-1);
    }
};
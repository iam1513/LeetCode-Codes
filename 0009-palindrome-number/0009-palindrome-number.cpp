class Solution {
public:
    
    bool f(int num, int & temp){
        if(num>=0 && num<=9){
            int lst = temp%10;
            temp = temp/10;
            
            return (num == lst);
        }
        
        bool res = f(num/10,temp) && (num%10 == temp%10);
        temp/=10;
        return res;
    }
    
    bool isPalindrome(int x) {
         int temp = x;
        if(x<0){
            return false;
        }
        return f(x,temp);
    }
};

// class Solution {
// public:
//     bool isPalindrome(int x) {
//         if(x<0){
//             return false;
//         }

//         long long reversed = 0;
//         long long temp = x;

//         while(temp!=0){
//             int num = temp%10;
//             reversed = reversed * 10 + num;
//             temp = temp/10;
//         }

//         return (reversed == x);
//     }
// };
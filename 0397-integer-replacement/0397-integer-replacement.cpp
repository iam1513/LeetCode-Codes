class Solution {
public:
    
    int f(long n,long cnt){
        if(n == 1){
            return cnt;
        }
        
        if(n%2==0){
            return f(n/2,cnt+1);
        }
        
        else{
            return min(f(n-1,cnt+1),f(n+1,cnt+1));
        }
    }
    
    int integerReplacement(int n) {
        long cnt = 0;
        return f(n,cnt);
    }
};
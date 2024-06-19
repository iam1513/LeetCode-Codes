class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> ans;
        
        for(int i = 0; i < n; i++){
            if((i+1)%3 == 0 && (i+1)%5==0){
                string st = "FizzBuzz";
                ans.push_back(st);
            }
            else if((i+1)%3 == 0){
                string st = "Fizz";
                ans.push_back(st);
            }
            else if((i+1)%5 == 0){
                string st = "Buzz";
                ans.push_back(st);
            }
            else{
                string st = to_string(i+1);
                ans.push_back(st);
            }
            
        }
        
        return ans;
    }
};
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        int n = tokens.size();
        stack<int> st;
        for(int i = 0; i < n; i++){
            if(isdigit(tokens[i][0]) || (tokens[i].size() > 1 && tokens[i][0] == '-' && isdigit(tokens[i][1]))) {
                st.push(stoi(tokens[i])); // stoi  stands for string to integer.
                
                /*(tokens[i].size() > 1 && tokens[i][0] == '-' && isdigit(tokens[i][1])) checks if the string tokens[i] has 
                more  than one character and if the first character is a minus sign ('-') and the second character is a digit. 
                This condition ensures that the string represents a negative number.*/
            } else {
                int a = st.top();
                st.pop();
                int b = st.top();
                st.pop();
                if(tokens[i] == "+") {
                    st.push(b + a);
                } else if(tokens[i] == "-") {
                    st.push(b - a);
                } else if(tokens[i] == "*") {
                    st.push(b * a);
                } else if(tokens[i] == "/") {
                    st.push(b / a);
                }
            }
        }
        return st.top();
    }
};


/*class Solution {
public:
    int evalRPN(std::vector<std::string>& tokens) {
        std::stack<int> stack;

        for (const std::string& token : tokens) { //PROBLEM HERE
            if (token == "+") {
                int a = stack.top();
                stack.pop();
                int b = stack.top();
                stack.pop();
                stack.push(b + a);
            } else if (token == "-") {
                int a = stack.top();
                stack.pop();
                int b = stack.top();
                stack.pop();
                stack.push(b - a);
            } else if (token == "*") {
                int a = stack.top();
                stack.pop();
                int b = stack.top();
                stack.pop();
                stack.push(b * a);
            } else if (token == "/") {
                int a = stack.top();
                stack.pop();
                int b = stack.top();
                stack.pop();
                stack.push(b / a);
            } else {
                stack.push(std::stoi(token));
            }
        }

        return stack.top();
    }
};*/
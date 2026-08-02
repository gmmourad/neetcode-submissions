class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        std::stack<int> token_stack{};
        for (const auto & tok: tokens)
        {

            if (tok == "/")
            {
                long val_1 = token_stack.top();
                token_stack.pop();
                long val_2 = token_stack.top();
                long result = val_2 / val_1;
                token_stack.pop();
                token_stack.push(static_cast<int>(result));
            }
            else if (tok == "-")
            {
                long val_1 = token_stack.top();
                token_stack.pop();
                long val_2 = token_stack.top();
                long result = val_2 - val_1;
                token_stack.pop();
                token_stack.push(static_cast<int>(result));
            }
            else if (tok == "*")
            {
                long val_1 = token_stack.top();
                token_stack.pop();
                long val_2 = token_stack.top();
                long result = val_2 * val_1;
                token_stack.pop();
                token_stack.push(static_cast<int>(result));
            }
            else if (tok == "+")
            {
                long val_1 = token_stack.top();
                token_stack.pop();
                long val_2 = token_stack.top();
                long result = val_2 + val_1;
                token_stack.pop();
                token_stack.push(static_cast<int>(result));
            }
            else
            {
                token_stack.push(std::stoi(tok));

            }
        }
        return token_stack.top();
    }
};

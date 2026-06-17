class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> nums;

        auto get_operands = [&nums]() {
            int r = nums.top(); nums.pop();
            int l = nums.top(); nums.pop();
            return pair{l, r};
        };

        for (const auto& token : tokens) {
            if (token.size() > 1 || isdigit(token[0])) {
                nums.push(stoi(token));
                continue;
            }

            auto [l, r] = get_operands();

            switch (token[0]) {
                case '+': nums.push(l + r); break;
                case '-': nums.push(l - r); break;
                case '*': nums.push(l * r); break;
                case '/': nums.push(l / r); break;
            }
        }

        return nums.top();
    }
};
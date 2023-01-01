#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <math.h>
#include <queue>
#include <stack>
#include <set>
using namespace std;
#define watch(x) std::cout << (#x) << " is " << (x) << std::endl


class Solution
{
public:
    int eval(int x, int y, string opr)
    {
        int op = opr[0];
        int res;
        switch (op)
        {
        case '+':
            res = x + y;
            break;
        case '-':
            res = x - y;
            break;
        case '*':
            res = x * y;
            break;
        case '/':
            res = x / y;
            break;
        }
        return res;
    }
    int evalRPN(vector<string> &tokens)
    {

        stack<int> s;
        set<string> op = {"+", "-", "*", "/"};

        for (auto &token : tokens)
        {
            if (op.count(token))
            {
                int oprnd2 = s.top();
                s.pop();
                int oprnd1 = s.top();
                s.pop();
                int res = eval(oprnd1, oprnd2, token);
                s.push(res);
            }
            else
            {
                s.push(stoi(token));
            }
        }

        return s.top();
    }
};

int main()
{
    Solution s;
    vector<string> p = {"4", "13", "5", "/", "+"};
    int ans = s.evalRPN(p);
    watch(ans);
}

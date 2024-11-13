//Runtime: 0 ms, 100.00%
//Memory: 8.01 MB, 26.26% 


class Solution {
public:
	bool isValid(string s)
	{
		stack<char> strStack;

		for (int i = 0; i < s.length(); i++)
		{
			if (s[i] == '(' || s[i] == '[' || s[i] == '{')
			{
				strStack.push(s[i]);
			}
			else
			{
				if (strStack.size() == 0)
				{
					return false;
				}
				else
				{
					char c = strStack.top();
					strStack.pop();
					if ((s[i] == ')' && c != '(') ||
						(s[i] == '}' && c != '{') ||
						(s[i] == ']' && c != '['))
					{
						return false;
					}
				}
			}
		}

		return strStack.size() == 0;
	}
};
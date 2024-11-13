//Runtime: 0 ms, 100.00%
//Memory: 9.92 MB, 90.22% 

class Solution {
public:
	string simplifyPath(string path)
	{
		string ret;
		vector<string> strStack;
		char* temp = strdup(path.c_str());
		char* token = strtok(temp, "/");

		while (token != NULL)
		{
			if (strcmp(token, "..") == 0)
			{
				if (strStack.size())
					strStack.pop_back();
			}
			else if (strcmp(token, ".") != 0)
			{
				strStack.push_back(token);
			}

			token = strtok(NULL, "/");
		}

		for (const auto& s : strStack)
		{
			ret += "/";
			ret += s;
		}

		free(temp);

		return ret.length() == 0 ? "/" : ret;
	}
};
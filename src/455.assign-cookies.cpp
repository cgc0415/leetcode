#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	int findContentChildren(vector<int>& g, vector<int>& s) {
		int count = 0;
		sort(g.begin(), g.end());
		sort(s.begin(), s.end());

		vector <int>::iterator it = g.begin();
		vector <int>::iterator it_s = s.begin();
		while (it != g.end() && it_s != s.end())
		{
			if (*it <= *it_s) {
				count++;
				it++;
			}
			it_s++;
		}
		return count;
	}
};
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <list>
#include <set>
#include <stack>
#include <numeric>
#include <unordered_map>

using namespace std;


void RecursiveDelete(unordered_map<int, pair<int, list<int>>>& tree, int delete_index)
{
	auto d_itr = tree.find(delete_index);
	if (d_itr != tree.end())
	{
		while (!d_itr->second.second.empty())
		{
			auto next = d_itr->second.second.front();
			RecursiveDelete(tree, next);
		}

		if (d_itr->second.first != -1)
		{
			tree[d_itr->second.first].second.erase(find(tree[d_itr->second.first].second.begin(), tree[d_itr->second.first].second.end(), delete_index));

		}

		tree.erase(d_itr);
	}
}



int main()
{
	int c;
	cin >> c;

	unordered_map<int, pair<int, list<int>>> tree;

	for (int idx = 0; idx < c; idx++)
		tree[idx] = make_pair(0, list<int>());

	for (int idx = 0; idx < c; idx++)
	{
		int branch;
		cin >> branch;

		if (branch != -1)
		{
			tree[branch].second.push_back(idx);
		}

		tree[idx].first = branch;
	}


	int d_idx;
	cin >> d_idx;

	RecursiveDelete(tree, d_idx);

	int leaf_count = 0;
	for (auto& t : tree)
	{
		if (t.second.second.empty())
			leaf_count++;
	}

	cout << leaf_count;

	return 0;
}


#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int visit[101] = {0, 1};

int main()
{
	int n = 0;
	cin >> n;

	int edges = 0;
	cin >> edges;

	vector<pair<int, int>> network;
	for (int i = 0; i < edges; i++)
	{
		int fst, snd;
		cin >> fst >> snd;
		network.push_back(make_pair(fst, snd));
	}

	queue<int> q;
	q.push(1);

	int answer = 0;
	while(!q.empty())
	{
		int target = q.front();
		q.pop();

		for (int i = 0; i < network.size(); i++)
		{
			int fst = network[i].first;
			int snd = network[i].second;

			if (fst == target && !visit[snd])
			{
				visit[snd] = true;
				q.push(snd);

				answer++;
			}
			else if(snd == target && !visit[fst])
			{
				visit[fst] = true;
				q.push(fst);

				answer++;
			}
		}
	}

	cout << answer << endl;

	return 0;
}
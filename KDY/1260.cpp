#include <iostream>
#include <queue>
#include <vector>

using namespace std;
int n = 0, m = 0, v = 0;
int c1[1001];
int c2[1001];
vector<int> a[1001];
queue<int> q;

void dfs(int x) {
	if (c1[x])
		return;

	c1[x] = true;
	cout << x << ' ';

	// 내림차순 정렬
	for (int i = 1; i < a[x].size(); i++) {
		
		int temp = a[x][0];
		if (a[x][i] < temp) {
			a[x][0] = a[x][i];
			a[x][i] = temp;
		}
	}

	for (int i = 0; i < a[x].size(); i++) {
		int y = a[x][i];
		dfs(y);
	}
}


void bfs(int start) {
	q.push(start);
	c2[start] = true;

	// 내림차순 정렬
	for (int i = 1; i < a[start].size(); i++) {
		
		int temp = a[start][0];
		if (a[start][i] < temp) {
			a[start][0] = a[start][i];
			a[start][i] = temp;
		}
	}

	while (!q.empty()) {
		int x = q.front();
		q.pop();
		c2[x] = true;

		cout << x << ' ';
		for (int i = 0; i < a[x].size(); i++) {
			int y = a[x][i];

			if (!c2[y]) {
				q.push(y);
				c2[y] = true;
			}
		}
	}
}


int main() {
	cin >> n >> m >> v;
	int n1, n2;

	for (int i = 0; i < m; i++) {
		cin >> n1 >> n2;
		a[n1].push_back(n2);
		a[n2].push_back(n1);
	}
	
	dfs(v);
	cout << "\n";
	bfs(v);
	return 0;
}

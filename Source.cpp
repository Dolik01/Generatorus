#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <deque>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <cstdlib>
#include <cstdio>
using namespace std;
int getrand(int v) {
	int x = rand(), y = rand() << 15;
	y |= x;
	y %= v;
	//y++;
	return y;
}

long long getLongRand(long long v) {
	long long x = rand(), y = rand() << 15;
	y |= x;
	y %= v;
	x = rand(), y = rand() << 15;
	y |= x;
	y %= v;
	//y++;
	return y;
}
//min N is 2, min M is 1.

void makeWeiNonOrGraph(int N, int M, int maxWeight) {
	vector<vector<int>>gr(N+13);
	set<pair<int, int>> rebra;
	map<pair<int, int>, int> wgs;
	int numOfEdges = 1;
	int U1 = 1;
	int W1 = 2;
	gr[U1].push_back(W1);
	gr[W1].push_back(U1);
	wgs[{U1, W1}] = getrand(maxWeight) + 1;
	wgs[{W1, U1}] = wgs[{U1, W1}];
	rebra.insert({ min(U1,W1),max(U1,W1) });
	cout << U1 << ' ' << W1 << ' ' << wgs[{U1, W1}] << endl;
	int curSz = 2;
	for (int i = 3; i <= N; ++i) {
		 U1 = getrand(curSz) + 1;
		 W1 = i;
		 gr[U1].push_back(W1);
		 gr[W1].push_back(U1);
		 wgs[{U1, W1}] = getrand(maxWeight) + 1;
		 wgs[{W1, U1}] = wgs[{U1, W1}];
		 rebra.insert({ min(U1,W1),max(U1,W1) });
		 cout << U1 << ' ' << W1 << ' ' << wgs[{U1, W1}] << endl;
		 ++curSz;
		 ++numOfEdges;
	}
	
	while (numOfEdges < M) {
		bool flag1 = 1;
		while (flag1) {
			
			int U2 = getrand(N) + 1;
			if (gr[U2].size() >= N - 1) {
				continue;
			}
			bool flag2 = 1;
			int V2;
			while (flag2) {
				V2 = getrand(N) + 1;
				if (rebra.find({ min(U2,V2),max(U2,V2) }) != rebra.end() || gr[V2].size() >= N - 1 || V2 == U2) {
					continue;
				}
				flag2 = 0;
			}
			gr[U2].push_back(V2);
			gr[V2].push_back(U2);
			wgs[{U2, V2}] = getrand(maxWeight) + 1;
			wgs[{V2, U2}] = wgs[{U2, V2}];
						
			if (wgs[{U2, V2}] % 2) {
				swap(U2, V2);
			}
			cout << U2 << ' ' << V2 << ' ' << wgs[{U2, V2}] << endl;
			rebra.insert({ min(U2,V2),max(U2,V2) });
			flag1 = 0;
			++numOfEdges;
		}
	}
}


string randname(int len) {
	//int len = getrand(10) + 1;
	string ans;
	for (int i = 0; i < len; ++i) {
		int rnd = getrand(26);
		ans += ('a' + rnd);
	}
	return ans;
}
int a[113][113];
void nextDate(string& s) {
	if (s[1] != '9') {
		++s[1];
	}
	else {
		++s[0];
		s[1] = '0';
	}
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	srand(time(NULL)); //0xdead 0xbeef 0xdeadbeef
	char ch[113];
	for (int jj = 1; jj <= 31; jj++) {
		sprintf(ch, "0%d.dat", jj);
		freopen(ch, "wt", stdout);
		int a = getrand(1000000000)+1;
		int b = getrand(1000000000) +1;
		cout << a << ' ' << b;
		/*int n = 100000;//getrand(100000) + 1;
		cout << n << endl;
		for (int i = 0; i < n; ++i) {
			cout << getrand(5000) + 1 << endl;
		}
		cout << "###" << endl;
		int k = 100;// getrand(100) + 1;
		cout << k << endl;
		for (int i = 0; i < k; ++i) {
			cout << 50000 + i << endl;
		}*/
	}
	return 0;
}
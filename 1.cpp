#include <iostream>
#include <vector>
#include <algorithm>
#define endl "\n"
#define fast ios::sync_with_stdio(0), cin.tie(nullptr), cout.tie(nullptr)
using namespace std;

int main() {
	int N, M;
	cin >> N >> M;
	vector<int> Number;
	int Num;
	for (int i = 0; i < N; i++) {
		cin >> Num;
		Number.push_back(Num);
	}
	sort(Number.begin(), Number.end());
	int count = 0;
	int A = 0;
	int B = Number.size()-1;
	while (A<B) {
		if (Number[A] + Number[B] == M) {
			count++;
			for (int i = A + 1; i < Number.size(); i++)
				Number[i - 1] = Number[i];
			for (int i = B + 1; i < Number.size(); i++)
				Number[i - 1] = Number[i];
			Number.resize(Number.size() - 2);
			A = 0;
			B = Number.size() - 1;
		}
		else if (Number[A] + Number[B] < M)
			A += 1;
		else
			B -= 1;
	}
	cout << count;
}
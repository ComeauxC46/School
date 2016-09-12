#include <iostream>
#include <vector>
using namespace std;

vector<int> v(10);

vector<int> &f() {
	for(int i=0;i<10;++i) v[i] = i;
	return v;
}

void printVector(const vector<int> &v) {
	for(vector<int>::const_iterator it=v.begin();it!=v.end();++it)
		cout << (*it) << ' ';
	cout << endl;
}

int main(int argc, char **argv) {
	vector<int> vec = f();
	printVector(vec);
	vec.push_back(10);
	printVector(vec);
	return 0;
}
#include <iostream>
#include <algorithm> 
#include <vector>
#include <map> 
using namespace std;
int fun(int i, int a){
	if( i > a) return i - a; 
	else return a - i;
}

struct cmp{
	bool operator()(int a, int b)  { 
	return a > b; 
	}	
};

	
int main(int argc, char** argv) {
	int N;
	cin >> N;
	vector<int> vec;
	for(int i = 0; i < N; i++){
		int temp; cin >> temp; 
		vec.push_back(temp);
	}
	for(int i = 0; i < vec.size(); i++){
		vec[i] = fun(i + 1,vec[i]);
	}
//	for(auto it: vec)
//		cout << it <<" ";
//	cout << endl;
	//map计数器 O = N*logN
	map<int,int,cmp> m;
	for(auto it:vec)
		m[it]++; 
	for(auto it:m){
		if(it.second > 1)
			cout << it.first << " " << it.second<<endl;
	} 
	return 0;
}

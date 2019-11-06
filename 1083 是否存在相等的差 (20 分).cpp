#include <iostream>
#include <algorithm> 
#include <vector>
#include <map> 
using namespace std;
int fun(int i, int a){
	return i>a ? i-a : a-i;
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
	

	cout << "MAP 计算器" << endl;
	//map计数器 O = N*logN
	map<int,int,cmp> m;
	for(auto it:vec)
		m[it]++; 
	for(auto it:m){
		if(it.second > 1)
			cout << it.first << " " << it.second<<endl;
	} 

	// hash 映射 O = N
	cout << "开辟一个数组 hash映射" <<endl;
	vector<int> h(N);
	for(auto it:vec){
		h[it]++;
	}
	for(int i = N -1 ; i >= 0;i--){
		if(h[i] > 1)
			cout << i << " " << h[i] << endl;
	}
	return 0;
}

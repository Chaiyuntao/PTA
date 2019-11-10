#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

void DFS(vector<vector<int>> &G1,int v,vector<int>& visited){
	visited[v] = 1;
	cout << v<<" ";
	for(int i = 0;i < G1[v].size();i++){
		if(visited[G1[v][i]] == 0)
			DFS(G1,G1[v][i],visited);
	}
}
void BFS(vector<vector<int>> &G,int v,vector<int>& visited){
	queue<int>Q;
	Q.push(v);
	visited[v] = 1;
	while(Q.empty() == false){
		v = Q.front();
		cout << v<<" ";
		Q.pop();
		for(int i = 0;i < G[v].size(); i++){
			if(visited[G[v][i]] == 0)
				Q.push(G[v][i]);
				visited[G[v][i]] = 1;
		}
	}

}
int main(int argc, char** argv) {
	int N,K;
	cin >> N >> K;
	//DFS
	vector<int>visited1(N);
	vector<vector<int>> G1(N);
	for(int i = 0;i < K; i++){
		int v1,v2;
		cin >> v1 >>v2;
		G1[v1].push_back(v2);
		G1[v2].push_back(v1);
	}
	for(int i = 0; i < N;i++)
		sort(G1[i].begin(),G1[i].end());
	for(int i = 0; i < N;i++){
		if(visited1[i] == 0){
			cout << "{ ";
			DFS(G1,i,visited1);
			cout << "}"<<endl;
		}
			
	}
	//BFS
	for(auto &it :visited1)
		it = 0;
	for(int i = 0; i < N;i++){
		if(visited1[i] == 0){
			cout << "{ ";
			BFS(G1,i,visited1);
			cout << "}"<<endl;
		}			
	}
	return 0;
}

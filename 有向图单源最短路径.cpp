#include <iostream>
#include <vector>
#include <queue>
#include <map>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
struct node{
	int V;
	int weight;
}node;
struct node_1{
	int dist;
	int path;
	bool mark; 
}node1;
int findmin(map<int,struct node_1> &S){
	int temp = 1000;int V = 1000;
	for(auto it: S){
		if(it.second.mark == 0 && it.second.dist < temp){
				temp = 	it.second.dist;	
				V = it.first;				
			}
		}		
	}
	return V;
}
void dijkstr(vector<vector<struct node>> &G,int V,map<int,struct node_1> &S,vector<bool> &visi){
	//找到最小值 
	int cur_V;
	while(1){
		cur_V = findmin(S);
		if(cur_V == 1000)	break;
		cout << "cur_v:" << cur_V;
		auto cur_search = S.find(cur_V);
			cur_search->second.mark = 1;
		//遍历 V 的临界点 
		for(int i = 0;i< G[cur_V].size();i++){
			int next_V = G[cur_V][i].V;					 		
			auto next_search = S.find(next_V);
			//S中不存在 V 第一次插入
	    	if (next_search == S.end())
	    	//dist = 上一个节点的 dist + 这个节点的权值 ，path记录上一个节点，mark不标记 
				S[next_V] = {G[cur_V][i].weight + cur_search->second.dist,cur_V,0};
			//S中存在V 判断是否为最短路径 
			else{
				//如果 新的路径dist < 之前的dist，更新 dist ，和path，mark保持不变 
				 if( G[cur_V][i].weight + cur_search->second.dist < next_search->second.dist ) 
				 	S[next_V] = {G[cur_V][i].weight + cur_search->second.dist,cur_V, 0};
			} 
		}
		for(auto it: S){
		cout << "V:"<<it.first<<"dist:" << it.second.dist << " path:"<<it.second.path << " mark:"<<it.second.mark <<endl;
		}	
		cout << endl;		
	}	
}
int main(int argc, char** argv) {
	int V,E;
	cin >> V >> E;
	vector<vector<struct node>> G(V);
	vector<int> dis(V,-1);
	vector<int> path(V,-1);
	map<int,struct node_1> S;
	//无向图 
	for(int i = 0;i < E;i++){
		int v1,v2,weight;
		cin >> v1 >> v2 >> weight;
		G[v1].push_back({v2,weight});
	}	
	//有权图的单源最短路，以0为起点 
	//初始化S 距离 路径 标记 
	S[0] ={0,-1,1};
	for(int i = 0;i<G[0].size();i++){
		S[G[0][i].V] = {G[0][i].weight,0,0};
	}
	for(auto it: S){
		cout << "V:"<<it.first<<"dist:" << it.second.dist << " path:"<<it.second.path <<endl;
	}
	cout << endl;
	dijkstr(G,0,S,visited); 
	for(auto it: S){
		cout << "V:"<<it.first<<"dist:" << it.second.dist << " path:"<<it.second.path <<endl;
	}
	return 0;
}





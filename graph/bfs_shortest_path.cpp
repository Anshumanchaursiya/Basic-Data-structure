#include<iostream>
#include<list>
#include<queue>
using namespace std;

class graph{


private:
	//because we have to n number of vertices in the graph
	int V;
	//array of linked list
	list<int> *adjlist;

public:
	
	graph(int v){
		V = v;
		adjlist = new list<int>;
	}

	void addEdge(int u,int v,bool bidir=true){
		adjlist[u].push_back(v);
		if(bidir){
			adjlist[v].push_back(u);
		}
	}

	void printAdjList(){
		for(int i=0;i<V;i++){
			cout<<i<<"->";
			//for each loop
			for(int node : adjlist){
				cout<<node<<",";
			}
			cout<<endl;
		}
	}

	void bfs(int src,int dest){

		queue<int> q;
		int* dist = new int[V+1]{0};
		int* parent = new int[V+1];

		//initialize all node's parent to -1
		for(int i=0;i<V;i++){
			parent[i] = -1;
		}

		//V is number of vertices
		bool* visited = new bool[V+1]{0};

		q.push(src);
		visited[src] = true;

		while(!q.empty()){

			int node = q.front();
			cout<<node<<" ";
			q.pop();

			for(int neighbour : adjlist[node]){
				if(!vesited[neighbour]){
					q.push(neighbour);
					visited[neighbour] = true;

					dist[neighbour] = dist[node] + 1;
					parent[neighbour] = node;
				}
			}
		}

		cout<<endl;
		cout<<"sortest distance is: "<<dist[dest]<<endl;
		cout<<"sortest path is: "<<dest;
		int temp = dest;
		while(temp!=-1){
			cout<<"<--"<<parent[temp];
			temp = parent[temp];
		}
	}
	

};


int main(){

	graph g(4);
	g.addEdge(0,1);
	g.addEdge(0,2);
	g.addEdge(0,3);
	g.addEdge(1,3);
	g.addEdge(3,2);
	//g.printAdjList();




	return 0;
}
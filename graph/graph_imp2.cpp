#include<iostream>
#include<list>
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


};


int main(){

	graph g(4);
	g.addEdge(0,1);
	g.addEdge(0,2);
	g.addEdge(0,3);
	g.addEdge(1,3);
	g.addEdge(3,2);
	g.printAdjList();


	return 0;
}
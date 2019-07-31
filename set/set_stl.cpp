//we can erase any element present in set in o(logn) time

//std::set is commonly implemented as a red-black binary search tree.
// Insertion on this data structure has a worst-case of O(log(n)) complexity, as the tree is kept balanced.

#include<iostream>
#include<set>
#include<iterator>
using namespace std;

int main(){

	set<int> s;
	s.insert(-1);
	s.insert(10);
	s.insert(5);
	s.insert(-10);
	s.insert(-10);

	set<int>:: iterator it;
	//auto it; //->this is also correct to declare it 

	for(it = s.begin();it != s.end();it++){

		cout<<*it<<" ";
	}

	//another approach to print all the eliment of set in order
	/*
	for(int x: s){
		cout<<x<<" ";
	}
	*/

	cout<<endl;

	set<int>:: iterator it2 = s.find(-1);
	if(it2!=s.end()){
		cout<<"present"<<endl;
	}
	else{
		cout<<"not present"<<endl;
	}

	set<int>:: iterator it3 = s.lower_bound(-10);
	set<int>:: iterator it4 = s.upper_bound(-10);
	cout<<"lower_bound : "<<*it3<<endl<<"upper_bound : "<<*it4<<endl;

	set<int>:: iterator it5 = s.upper_bound(100);
	
	if(it5 == s.end()){
		cout<<"sorry the eliment is not found"<<endl;
	}


	return 0;
}

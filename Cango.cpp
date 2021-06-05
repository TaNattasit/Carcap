#include<iostream>
#include<list>
#include<map>
using namespace std;

class Graph{
	public:
		int V;
		map<int,list<int> > adj;
		map<int,list<int> > countlist;
		
		Graph(int sum)
		{
			this->V = sum; 
		}
	
		void addEdge(int x,int y)
		{
			adj[x].push_back(y);
		}
		
		void Print()
		{
			list<int> :: iterator nbr;
			for(int i=1;i<=V;i++)
			{
				cout<<"Vertex : "<<i<<"->";
				for(nbr=adj[i].begin();nbr!=adj[i].end();nbr++)
				{
					cout<<*nbr<<" ";
				}
				cout<<"\n";
			}
		}
		
		bool count(int V,int search)
		{
			list<int> :: iterator nbr;
			list<int> :: iterator nbr2;
			//cout<<V<<"->";
			for(nbr=adj[V].begin();nbr!=adj[V].end();nbr++)
			{	
			//	cout<<*nbr<<" ";
				if(search==*nbr)
				{
					return true;
				}
				for(nbr2=adj[*nbr].begin();nbr2!=adj[*nbr].end();nbr2++)
				{
				//	cout<<*nbr2<<" ";
					if(search==*nbr2)
					{
						return true;
					}
				}
			}
			return false;
		}
	
	
};


int main()
{
	int V,E,x,y,c,find,result;
	cin>>V>>E;
	Graph g(V);
	int first=1;
	for(int i=0;i<E;i++)
	{
		cin>>x>>y;
		g.addEdge(x,y);
	}
//	g.Print();
	cin>>c>>find;
	result = g.count(c,find);
	if(result==1)
	{
		cout<<"YES";
	}else{
		cout<<"NO";
	}
	
	
	
	
}

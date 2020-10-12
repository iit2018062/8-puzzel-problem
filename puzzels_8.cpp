#include<bits/stdc++.h>
using namespace std;
class agent
{
	public:
		vector<vector<int> >arr;
		agent()
		{   vector<vector<int> >vect(3,vector<int>(3,0));
			for(int i=0;i<3;i++ )
			{
				for(int j=0;j<3;j++)
				{
					cin>>vect[i][j];
				}
			}
			arr=vect;
			
		}
		void bfs(vector<vector<int> >&goal);
		void printer();
};

int dx[4]={-1,1,0,0};
int dy[4]={0,0,-1,1};
bool isvalid(int row,int col,int m,int n)
{ 
	if(row<0 || row>=m||col<0||col>=n)
	return false;
	return true;
}
void finder(int &row,int &col,vector<vector<int> >&arr)
{
	for(row=0;row<3;row++)
	{
		for(col=0;col<3;col++)
		{
			if(arr[row][col]==0)
			return;
		}
	}
}
bool safe(vector<vector<int> >&arr,vector<vector<int> >&goal)
{ 
   for(int i=0;i<3;i++)
   {
   	for(int j=0;j<3;j++)
   	{
   		if(arr[i][j]!=goal[i][j])
   		{    
   			 	return false;
		   }
   	
	   }
   }
   
   return true;
}
void agent::printer()
{
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<3;j++)
		{
			cout<<arr[i][j]<<" ";
		}
		cout<<endl;
	}
}
void agent:: bfs(vector<vector<int> >&goal)
{
queue<vector<vector<int> > >q;
q.push(arr);
int x=0,y=0;
while(!q.empty())
{  
    arr = q.front();
    q.pop();
    finder(x,y,arr);
    for(int i=0;i<4;i++)
    {
    	int row=x+dx[i];
    	int col=y+dy[i];
		if(isvalid(row,col,3,3))
		{
			arr[x][y]=arr[row][col];
			arr[row][col]=0;
			q.push(arr);
			if(safe(arr,goal))return;
			arr[row][col]=arr[x][y];
			arr[x][y]=0;
	     }
	}
	if(safe(arr,goal))return;


}



}
int main()
{
  vector<vector<int> >vect(3,vector<int>(3,0));
cout<<"enter the 8 puzzel formate matrix (3*3)\n";
cout<<"please be sure to enter a valid 8 puzzel for which there exists a solution else while loop will turn into infinte loop!!\n";
cout<<"sorry for incoveniences caused\n";
cout<<"enter 0 at the place where there is empty cell :)\n";
agent a;

vector<vector<int> >goal(3,vector<int>(3,0));
goal[0][0]=1;goal[0][1]=2;goal[0][2]=3;
goal[1][0]=4;goal[1][1]=5;goal[1][2]=6;
goal[2][0]=7;goal[2][1]=8;goal[2][2]=0;

a.bfs(goal);
a.printer();
}

//Popescu Adrian UPB
//N^2
#include <fstream> 
#include <vector> 
#include <queue> 
#include <set> 
#include <unordered_map> 
using namespace std; 
ifstream cin("aventura.in"); 
ofstream cout("aventura.out"); 
vector<int>adj[500005]; 
unordered_map<int,int>adj2; 
int fre[500005]; 
int main() 
{ 
    int n,i,j,k,t,x,curr; 
    cin>>t; 
    for(int op=1;op<=t;op++) 
    { 
        cin>>n; 
        queue<int>qu; 
        for(i=1;i<=n;i++) 
        { 
            cin>>k; 
            for(j=1;j<=k;j++) 
            { 
                cin>>x; 
                adj[x].push_back(i); 
            } 
            fre[i]=k; 
        } 
        int change=1,cnt=0; 
        while(change) 
        { 
            change=0; 
            for(j=1;j<=n;j++) 
            { 
                if(fre[j]==0) 
                { 
                    cnt++; 
                    change=1; 
                    for(auto vec:adj[j]) 
                    { 
                        fre[vec]--; 
                    } 
                    fre[j]=-1; 
                } 
            } 
        } 
        cout<<cnt<<'\n'; 
        for(i=1;i<=n;i++) 
        { 
            adj[i].clear(); 
        } 
    } 
    return 0; 
}
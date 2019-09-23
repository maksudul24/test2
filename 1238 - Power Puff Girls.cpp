#include <bits/stdc++.h>
#define P(X) cout<<"db "<<X<<endl;
#define P2(X,Y) cout<<"d2 "<<X<<" "<<Y<<endl;
#define ll long long
#define rep(i,n) for(i=1;i<=n;i++)
#define FO freopen("out.txt","w",stdout)
#define FI freopen("in.txt","r",stdin)
#define MS(XX,YY) memset(XX,YY,sizeof(XX));
#define SIZE 50
#define uu first
#define vv second
#define pii pair<int,int>

using namespace std;

pii home,girls[5];
int fx[]={1,-1,0,0},home_x,home_y;
int fy[]={0,0,1,-1};
int cell[100][100];
int d[100][100],vis[100][100]; //d means destination from source.
int row,col;
int bfs(int sx,int sy) //Source node is in [sx][sy] cell.
{
	memset(vis,0,sizeof vis);
	vis[sx][sy]=1;
	queue<pii>q;
	q.push(pii(sx,sy));
	while(!q.empty())
	{
		pii top=q.front(); q.pop();
		for(int k=0;k<4;k++)
		{
			int tx=top.uu+fx[k];
			int ty=top.vv+fy[k];
			if(tx>=0 and tx<row and ty>=0 and ty<col and cell[tx][ty]!=-1 and vis[tx][ty]==0)
			{
				vis[tx][ty]=1;
				d[tx][ty]=d[top.uu][top.vv]+1;
				if(tx==home.uu && ty==home.vv){
                    return d[tx][ty];
				}
				q.push(pii(tx,ty));
			}
		}
	}
	return 0;
}


int main()
{
    int i,j,cas=0,ts,ans,dist,k,n,m;
    char ara[SIZE];
    FI;
    scanf("%d",&ts);
    while(ts--){
        memset(cell,0,sizeof(cell));
        scanf("%d %d",&n,&m);
        k=0,ans=-1;
        for(i=0;i<n;i++){
            scanf(" %s",ara);
            for(j=0;j<m;j++){
                if(ara[j]=='#' || ara[j]=='m'){
                    cell[i][j]=-1;
                }
                else if(ara[j]=='h'){
                    home.uu=i,home.vv=j;
                }
                else if(ara[j]=='.'){
                    //nothing
                }
                else{
                    girls[k++].uu=i,girls[k-1].vv=j;
                }
            }
        }
        for(i=0;i<3;i++){
            dist=bfs(girls[i].uu,girls[i].vv);
            if(dist>ans) ans=dist;
        }
        printf("Case %d: %d\n",++cas,ans);
    }
    return 0;
}

/*range update range query in 2d matrix*/


#include<cstdio>
#include<iostream>
using namespace std;
typedef long long ll;
ll n,m;
ll bit2d1[504][504],bit2d2[504][504],arr[504][504];

void moveup(ll ftree[],ll k,ll v);
ll movedown(ll ftree[],ll k);


ll query(ll f,ll p)
{
return f*movedown(bit2d1[p],f) - movedown(bit2d2[p],f);
}

ll range_query(ll g,ll h,ll p)
{
return query(h,p)-query(g-1,p);
}

void range_update(ll g,ll h,ll v,ll p)
{
moveup(bit2d1[p],g,v);
moveup(bit2d1[p],h+1,-v);
moveup(bit2d2[p],g,v*(g-1));
moveup(bit2d2[p],h+1,-v*h);
}




int main()
{
ll i,j;
ll k,x1,x2,y1,y2,v,ans;
scanf("%lld%lld",&n,&m);

for(i=0;i<=n;i++)
{
for(j=0;j<=m;j++)
{
bit2d1[i][j]=0;bit2d2[i][j]=0;
}
}

for(i=1;i<=n;i++)
{
for(j=1;j<=m;j++)
{
scanf("%lld",&arr[i][j]);
range_update(j,j,arr[i][j],i);
}
}
/*
for(i=1;i<=n;i++)
{
for(j=1;j<=m;j++)
{
printf("%lld ",bit2d1[i][j]);
}
printf("\n");
}

for(i=1;i<=n;i++)
{
for(j=1;j<=m;j++)
{
printf("%lld ",bit2d2[i][j]);
}
printf("\n");
}
*/

//memset(bit2d1[i], 0, (m+1) * sizeof(long long));
//memset(Bit2d2[i], 0, (m+1) * sizeof(long long));

ll q;
scanf("%lld",&q);
while(q--)
{
scanf("%lld",&k);
if(k==1)
{
scanf("%lld%lld%lld%lld%lld",&x1,&y1,&x2,&y2,&v);
for(i=x1;i<=x2;i++)
{
range_update(y1,y2,v,i);
}

}
else 
{ans=0;
scanf("%lld%lld%lld%lld",&x1,&y1,&x2,&y2);
for(i=x1;i<=x2;i++)
{
ans=ans+range_query(y1,y2,i);
}
printf("%lld\n",ans);
}

}

return 0;
}

void moveup(ll ftree[],ll k,ll v)
{
while(k<=m)
{
ftree[k]=ftree[k]+v;
k=k+(k&(-k));
}

}

ll movedown(ll ftree[],ll k)
{
ll sum=0;
while(k>0)
{
sum=sum+ftree[k];
//printf("%lld %lld\n",sum,k);
k=k-(k&(-k));
}
return sum;
}

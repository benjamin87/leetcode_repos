#define maxn 200002
#include<cstdio>
#include<iostream>
#include<climits>
using namespace std;

int n,q;
int ir, il, ix;
struct node
{
    long long w,m;
    long long lazy;
}tree[4*maxn+1];

int read()
{
    int w=0,c=1; char ch=getchar();
    while (ch<'0' || ch>'9')
      {
        if (ch=='-') c=-1;
        ch=getchar();
      }
    while (ch>='0' && ch<='9')
      w=w*10+ch-'0',ch=getchar();
    return w*c;
}

void update(int rt)
{
	tree[rt].w = tree[rt<<1].w + tree[rt<<1|1].w;
    tree[rt].m = min(tree[rt<<1].m, tree[rt<<1|1].m);
}

void build(int l, int r, int rt)
{
    if(l == r)
    {
        scanf("%d", &tree[rt].w);
        tree[rt].m = tree[rt].w;
        return;
    }
    int mid = (l+r)>>1;
    build(l, mid, rt<<1);
    build(mid+1, r, rt<<1|1);
    update(rt);
}

void paint(int rt, long long z, int l, int r)
{
    tree[rt].w += z*(r-l+1);
    tree[rt].m += z;
    tree[rt].lazy += z;
}

void pushdown(int rt, int l, int r)
{
    if(tree[rt].lazy)
    {
        int mid=(l+r)>>1;
        paint(rt<<1, tree[rt].lazy, l, mid);
        paint(rt<<1|1, tree[rt].lazy, mid+1, r);
        tree[rt].lazy = 0;
    }
}

void changeSegment(int L, int R, int c, int l,int r, int rt)
{
    int mid = (l+r)>>1;
    if(L <= l && r <= R)
    {
        paint(rt, c, l, r);
        return;
    }
    pushdown(rt, l, r);
    if(L<=mid) changeSegment(L, R, c, l, mid, rt<<1);
    if(R>mid) changeSegment(L, R, c, mid+1, r, rt<<1|1);
    update(rt);
}

long long query_sum(int L, int R, int l, int r, int rt)
{
    int mid = (l+r)>>1;
    long long ans = 0;
    if(L <= l && r <= R)
    {
        return tree[rt].w;
    }
    
    pushdown(rt, l, r);
    if(L<=mid) ans+=query_sum(L, R, l, mid, rt<<1);
    if(R>mid) ans+=query_sum(L, R, mid+1, r, rt<<1|1);
    update(rt);
    return ans;
}

long long query_min(int L, int R, int l, int r, int rt)
{
    int mid = (l+r)>>1;
    long long ans;
    if(L <= l && r <= R)
    {
        return tree[rt].m;
    }    
    pushdown(rt, l, r);
    
    if(L <= mid) ans = query_min(L, R, l, mid, rt<<1);
    else ans = INT_MAX;
    if(R > mid) ans = min(ans, query_min(L, R, mid+1, r, rt<<1|1));
    update(rt);
    return ans;
}

int main()
{
    char c[10];
    scanf("%d%d", &n, &q);
    int i;
    build(1, n, 1);
    
    for(i=0;i<q;++i)
    {
        scanf("%s", &c);
        il = read();
        ir = read();
        
        if(c[0] == 'M')
        {
            printf("%lld\n", query_min(il, ir, 1, n, 1));
        }
        else if(c[0] == 'P')
        {
            ix = read();
            changeSegment(il, ir, ix, 1, n, 1);
        }
        else if(c[0] == 'S')
        {
            printf("%lld\n", query_sum(il, ir, 1, n, 1));
        }
    }
    return 0;
}
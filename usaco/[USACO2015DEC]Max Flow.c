#define max(x,y)  ((x) > (y) ? (x) : (y))
#define maxn 50005

#include <stdio.h>
#include <string.h>

int n,k,x,y;
int head[maxn], dep[maxn], fa[maxn], size[maxn], son[maxn], top[maxn], rnk[maxn], id[maxn], sum[maxn];
struct Edge
{
    int ne;
    int to;
} edge[maxn<<1];

int edge_cnt = 0;
void add(int x, int y)
{
    // 链式前向星
    edge[++edge_cnt].ne = head[x];
    edge[edge_cnt].to = y;
    head[x] = edge_cnt;
}

void dfs1(int now)
{
    int v;
    size[now] = 1;  //
    // i - edge
    for(register int i = head[now]; i; i = edge[i].ne)
    {
        v = edge[i].to;
        if(v == fa[now]) continue;
        dep[v] = dep[now] + 1;
        fa[v] = now;
        dfs1(v);
        size[now] += size[v];
        if(son[now] == 0 || size[son[now]] < size[v]) son[now] = v;
    }
}

// 检索重链
int cnt = 0;
void dfs2(int n, int t)
{
    top[n] = t;
    id[n] = ++cnt;
    rnk[cnt] = n;
    if(son[n] != 0) dfs2(son[n], t);

    int v;
    for(register int i = head[n]; i; i = edge[i].ne)
    {
        v = edge[i].to;
        if(v != son[n] && v != fa[n])
            dfs2(v, v);
    }
}

void swap(int *a, int *b){
    int t;
    t = *a;
    *a = *b;
    *b = t;
}   

void update_lca(int x, int y)
{
    while(top[x] != top[y])
    {
        if(dep[top[x]] < dep[top[y]]) swap(&x, &y);   //
        x = fa[top[x]];
    }
    if(dep[x] > dep[y]) swap(&x, &y);
    sum[x]--;
    sum[fa[x]]--;
}

int ans = -0x7fffffff;
void dfs3(int n)
{
    int v;
    for(register int i = head[n];i;i = edge[i].ne)
    {
        v = edge[i].to;
        if(v == fa[n])continue;
        dfs3(v);
        sum[n] += sum[v];
    }
    ans = max(ans, sum[n]);
}

int main()
{
    memset(head, 0, maxn);
    memset(sum, 0, maxn);
    scanf("%d%d", &n, &k);
    for(register int i = 1; i < n; ++i)
    {
        scanf("%d%d", &x, &y);
        add(x, y);add(y, x);    //  
    }
    
    dep[1] = 1;
    fa[1] = 0;  //
    dfs1(1);
    dfs2(1, 1);

    for(register int i = 0; i < k; ++i)
    {
        scanf("%d%d", &x, &y);
        sum[x]++;
        sum[y]++;
        // lca-- fa[lca]--
        update_lca(x, y);
    }
    dfs3(1);
    printf("%d\n", ans);
    return 0;
}

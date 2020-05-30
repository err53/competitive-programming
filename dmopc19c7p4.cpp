#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MM = 3e5 + 5, mod = 10e9 + 7;

// DOES NOT WORK

struct E
{
	ll a, b, c, d;
};
struct node
{
	int l, r;
	E v;
} seg[4 * MM];
int N, Q, a[MM];

E comb(E x, E y)
{
	E r;
	r.a = (x.a * y.a + x.b * y.c) % mod;
	r.b = (x.a * y.b + x.b * y.d) % mod;
	r.c = (x.c * y.a + x.d * y.c) % mod;
	r.d = (x.c * y.b + x.d * y.d) % mod;
	return r;
}

void build(int l, int r, int rt)
{
	seg[rt].l = l;
	seg[rt].r = r;
	if (l == r)
	{
		seg[rt].v = E{a[l], 1, 1, 0};
	}
	else
	{
		int mid = (l + r) / 2;
		build(l, mid, 2 * rt);
		build(mid + 1, r, 2 * rt + 1);
		seg[rt].v = comb(seg[2 * rt].v, seg[2 * rt + 1].v);
	}
}

E query(int l, int r, int rt)
{
	if (seg[rt].l == l && seg[rt].r == r)
		return seg[rt].v;
	int mid = (seg[rt].l + seg[rt].r) / 2;
	if (r <= mid)
	{
		return query(l, r, 2 * rt);
	}
	else if (l > mid)
	{
		return query(l, r, 2 * rt + 1);
	}
	else
	{
		return comb(query(1, mid, 2 * rt), query(mid + 1, r, 2 * rt + 1));
	}
}

int main()
{
	scanf("%d%d", &N, &Q);
	for (int i = 1; i <= N; i++)
	{
		scanf("%d", &a[i]);
	}
	build(1, N, 1);
	for (int i = 1; i <= Q; i++)
	{
		int l, r;
		scanf("%d%d", &l, &r);
		E ans = query(l, r, 1);
		printf("%lld %lld\n", ans.a, ans.c);
	}
}
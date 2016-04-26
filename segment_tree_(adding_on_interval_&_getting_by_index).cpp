/// Good, nice segment tree. It also provides user-friendly interface.
/// update(l, r, delta) ---> add delta to all numbers from l to r
/// get(idx) get element by index idx


class Tree
{
public:
    vector<int> t;
    int n;
    Tree(vector<int>& a)
    {
        n = a.size();
        t.resize(4 * n);
        build(t, a, 1, 0, n - 1);
    }

    void build(vector<int>& tree, vector<int>& a, int v, int tl, int tr)
    {
        if(tl == tr)
        {
            t[v] = a[tl];
        }
        else
        {
            int tm = (tl + tr) / 2;
            build(tree, a, 2 * v, tl, tm);
            build(tree, a, 2 * v + 1, tm + 1, tr);
        }
    }

    void _update(vector<int>& tree, int v, int tl, int tr, int l, int r, int delta)
    {
        if(l > r)
        {
            return;
        }
        if(tl == l && tr == r)
        {
            tree[v] += delta;
        }
        else
        {
            int tm = (tl + tr) / 2;
            _update(tree, 2 * v, tl, tm, l, min(r, tm), delta);
            _update(tree, 2 * v + 1, tm + 1, tr, max(l , tm + 1), r, delta);
        }
    }

    void update(int l, int r, int delta)
    {
        _update(t, 1, 0, n - 1, l, r, delta);
    }

    int _get(vector<int>& tree, int v, int tl, int tr, int idx)
    {
        if(tl == tr)
        {
            return tree[v];
        }
        else
        {
            int tm = (tl + tr) / 2;
            if(idx <= tm)
            {
                return tree[v] + _get(tree, 2 * v, tl, tm, idx);
            }
            else
            {
                return tree[v] + _get(tree, 2 * v + 1, tm + 1, tr, idx);
            }
        }
    }

    int get(int idx)
    {
        return _get(t, 1, 0, n - 1, idx);
    }
};
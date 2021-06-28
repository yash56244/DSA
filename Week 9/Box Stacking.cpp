static bool cmp(tuple < int, int, int > & a, tuple < int, int, int > & b) {
    return get < 0 > (a) * get < 1 > (a) > get < 0 > (b) * get < 1 > (b);
}
int maxHeight(int h[], int w[], int l[], int n) {
    vector < tuple < int, int, int > > v;
    for (int i = 0; i < n; i++) {
        if (l[i] > w[i])
            v.push_back(make_tuple(l[i], w[i], h[i]));
        else
            v.push_back(make_tuple(w[i], l[i], h[i]));
        if (w[i] > h[i])
            v.push_back(make_tuple(w[i], h[i], l[i]));
        else
            v.push_back(make_tuple(h[i], w[i], l[i]));
        if (h[i] > l[i])
            v.push_back(make_tuple(h[i], l[i], w[i]));
        else
            v.push_back(make_tuple(l[i], h[i], w[i]));
    }
    sort(v.begin(), v.end(), cmp);
    vector < int > lis;
    for (int i = 0; i < 3 * n; i++)
        lis.push_back(get < 2 > (v[i]));
    int mx = lis[0];
    for (int i = 1; i < 3 * n; i++) {
        for (int j = 0; j < i; j++) {
            if (get < 0 > (v[i]) < get < 0 > (v[j]) && get < 1 > (v[i]) < get < 1 > (v[j]) &&
                lis[j] + get < 2 > (v[i]) > lis[i]) {
                lis[i] = lis[j] + get < 2 > (v[i]);
            }
        }
        mx = max(mx, lis[i]);
    }
    return mx;
}

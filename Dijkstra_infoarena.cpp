#include <fstream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

ifstream fin("dijkstra.in");
ofstream fout("dijkstra.out");

const int Inf = 0x3f3f3f3f;
using PII = pair<int, int>;
vector<vector<PII>> G;

struct Pair {
    int node;      // varful
    int dist;      // dist de la sursa la v
    bool operator < (const Pair& p) const
    {
        return dist > p.dist;
    }
};

int n, m;

void Read();
void Dijkstra(int S, vector<int>& d);
void Print(vector<int>& d);

int main()
{
    vector<int> D;
    Read();
    Dijkstra(1, D);
    Print(D);
}

void Dijkstra(int S, vector<int>& d)  // O(m * log n)
{
    // d.resize(n + 1, Inf);
    d = vector<int>(n + 1, Inf);
    priority_queue<Pair> Q;
    d[S] = 0;
    Q.push({S, 0});

    while ( !Q.empty())
    {
        int x = Q.top().node;
        int dx = Q.top().dist;
        Q.pop();
        if ( dx > d[x] )
            continue;

        for (const auto& p: G[x])
        {
            int y = p.first;
            int w = p.second;
            if ( d[y] > d[x] + w )
            {
                d[y] = d[x] + w;
                Q.push({y, d[y]});
            }
        }
    }
}

void Read()
{
    fin >> n >> m;
   // G = vector<vector<PII>>(n + 1, vector<PII>());
    G.resize(n + 1);
    int x, y, w;
    while ( m--)
    {
        fin >> x >> y >> w;
        G[x].push_back({y, w});
    }
    fin.close();
}

void Print(vector<int>& d)
{
    for (size_t i = 1; i <= n; ++i)
        if ( d[i] != Inf)
            fout << d[i] << ' ';
        else
            fout << 0 << ' ';
}


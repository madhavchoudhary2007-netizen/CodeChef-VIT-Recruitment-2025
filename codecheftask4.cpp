#include <iostream>
#include <vector>
#include <queue>

void runCase() {
int n, m;
if (!(std::cin >> n >> m)) return;

// Graph storage
std::vector<std::vector<int>> graph(n + 1);
std::vector<int> deg(n + 1, 0);

// Build edges
for (int i = 0; i < m; ++i) {
    int a, b;
    std::cin >> a >> b;
    graph[a].push_back(b);
    graph[b].push_back(a);
    deg[a]++;
    deg[b]++;
}

int king;
std::cin >> king;

// Collect leaves
std::queue<int> q;
for (int i = 1; i <= n; ++i) {
    if (deg[i] <= 1) {
        q.push(i);
    }
}

std::vector<bool> gone(n + 1, false);

// Assume king survives unless peeled
bool kingPeeled = false;

while (!q.empty()) {
    int u = q.front();
    q.pop();

    if (gone[u]) {
       //small defensive check
        continue;
    }

    gone[u] = true;

    if (u == king) {
        kingPeeled = true;
        
    }

    // Update neighbors
    for (int v : graph[u]) {
        if (!gone[v]) {
            deg[v]--;
            if (deg[v] == 1) {
                q.push(v);
            }
        }
    }
}

// Output result
if (kingPeeled) {
    std::cout << "YES\n";
} else {
    std::cout << "NO\n";
}


}

int main() {
std::ios_base::sync_with_stdio(false);
std::cin.tie(NULL);

int t;
if (std::cin >> t) {
    while (t--) {
        runCase();
    }
}
return 0;


}
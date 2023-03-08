#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Edge {
    int u, v, w;
    Edge(int u, int v, int w) : u(u), v(v), w(w) {}
};

struct DisjointSet {
    vector<int> parent;

    DisjointSet(int n) {
        for (int i = 0; i < n; i++) {
            parent.push_back(i);
        }
    }

    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    void merge(int x, int y) {
        parent[find(x)] = find(y);
    }
};

int main() {
    int n, m;
    cin >> n >> m;

    // Đọc các cạnh vào danh sách
    vector<Edge> edges;
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        edges.emplace_back(u, v, w);
    }

    // Sắp xếp các cạnh theo trọng số tăng dần
    sort(edges.begin(), edges.end(), [](const Edge &a, const Edge &b) {
        return a.w < b.w;
    });

    // Tạo tập các tập con riêng biệt
    DisjointSet ds(n);

    // Khởi tạo giá trị trọng số cây khung nhỏ nhất ban đầu là 0
    int min_tree_weight = 0;

    // Duyệt qua tất cả các cạnh
    for (const auto &e : edges) {
        int u = e.u, v = e.v, w = e.w;
        // Nếu 2 đỉnh của cạnh này không thuộc cùng 1 tập con riêng biệt
        // thì merge tập con của 2 đỉnh này và còn lại cộng trọng số cạnh này vào trọng số cây khung nhỏ nhất
        if (ds.find(u) != ds.find(v)) {
            ds.merge(u, v);
            min_tree_weight += w;
            cout << "Chon canh (" << u << ", " << v << ") co trong so " << w << endl;
        }
    }
    cout << "Trong so cay khung nho nhat la: " << min_tree_weight << endl;

    return 0;
}

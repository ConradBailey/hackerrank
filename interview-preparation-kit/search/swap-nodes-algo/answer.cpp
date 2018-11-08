#include <bits/stdc++.h>
using namespace std;

struct Node {
	Node(int val,
			 int depth,
			 Node *p = nullptr,
			 Node *l = nullptr,
			 Node *r = nullptr) :
		val(val), depth(depth), p(p), l(l), r(r)
	{}

	void traverse() {
		if (l) l->traverse();
		cout << val << ' ';
		if (r) r->traverse();
	}

	int val, depth;
	Node *p, *l, *r;
};

int main() {
	int n;
	cin >> n;

	unordered_map<int, set<Node *>> depth2nodes;
	vector<Node *> tree(n, nullptr);
	tree[0] = new Node(1, 0);
	depth2nodes[0].insert(tree[0]);

	int l, r;
	int max_depth{0};
	for (int i{0}; i < n; ++i) {
		cin >> l >> r;
		if (l != -1) tree[l-1] = tree[i]->l = new Node(l, tree[i]->depth+1, tree[i]);
		if (r != -1) tree[r-1] = tree[i]->r = new Node(r, tree[i]->depth+1, tree[i]);
		depth2nodes[tree[i]->depth+1].insert(tree[l-1]);
		depth2nodes[tree[i]->depth+1].insert(tree[r-1]);
		max_depth = max(max_depth, tree[i]->depth+1);
	}

	int t;
	cin >> t;

	while (t--) {
		int k;
		cin >> k;

		for (int d{k-1}; d <= max_depth; d += k)
			for (Node *p : depth2nodes[d])
				if (p) swap(p->l, p->r);

		tree[0]->traverse();
		cout << endl;
	}
}

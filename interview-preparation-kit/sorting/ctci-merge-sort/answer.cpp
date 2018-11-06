#include <bits/stdc++.h>
using namespace std;

struct RB_Tree {
	struct Node {
		enum Color : bool { Red, Black };

		Node(int val, Node::Color color, Node *parent = nullptr,
				 Node *left = nullptr, Node *right = nullptr)
				: val(val), color(color), parent(parent), left(left), right(right) {}

		~Node() {
			delete left;
			delete right;
		}

		int val;
		Node::Color color;
		Node *parent;
		Node *left;
		Node *right;
		size_t size = 1;
	};

	enum Direction { Left, Right };

	~RB_Tree() { delete root; }

	void rotate(Node *x, Direction d) {
		Node *&x_child{(d == Right) ? x->left : x->right};
		Node *y{x_child};
		Node *&y_child{(d == Right) ? y->right : y->left};

		y->parent = x->parent;
		if (x->parent == nullptr)
			root = y;
		else {
			Node *&k = (x == x->parent->left) ? x->parent->left : x->parent->right;
			k = y;
		}

		x_child = y_child;
		if (x_child) {
			x_child->parent = x;
			y->size -= x_child->size;
		}

		y_child = x;
		x->parent = y;
		x->size -= y->size;
		y->size += x->size;
	}

	void insert(int val) {
		Node *p{nullptr};
		Node **x{&root};
		while (*x != nullptr) {
			p = *x;
			p->size += 1;
			x = (val < p->val) ? &(p->left) : &(p->right);
		}
		*x = new Node(val, Node::Color::Red, p);
		repair(*x);
	}

	void repair(Node *c) {
		Node *p{c->parent};
		if (p == nullptr) {
			c->color = Node::Color::Black;
			return;
		}

		if (p->color == Node::Color::Black) {
			return;
		}

		Node *g{p->parent};
		Node *u{g->left == p ? g->right : g->left};
		if (u && u->color == Node::Color::Red) {
			p->color = Node::Color::Black;
			u->color = Node::Color::Black;
			g->color = Node::Color::Red;
			repair(g);
		} else {
			if (g->left && c == g->left->right) {
				rotate(p, Direction::Left);
				c = c->left;
			} else if (g->right && c == g->right->left) {
				rotate(p, Direction::Right);
				c = c->right;
			}
			p = c->parent;
			rotate(g, (c == p->left) ? Direction::Right : Direction::Left);
			p->color = Node::Color::Black;
			g->color = Node::Color::Red;
		}
	}

	size_t count_gt(int val) {
		size_t count{0};
		Node *p{root};
		while (p != nullptr) {
			if (val < p->val) {
				count += 1 + (p->right ? p->right->size : 0);
				p = p->left;
			} else {
				p = p->right;
			}
		}
		return count;
	}

	Node *root = nullptr;
};

size_t count_shifts(const vector<int> &v) {
	size_t total_swaps{0};
	RB_Tree bst;
	for (size_t i{0}; i < v.size(); ++i) {
		total_swaps += bst.count_gt(v[i]);
		bst.insert(v[i]);
	}
	return total_swaps;
}


int main() {
	int d;
	cin >> d;

	while (d--) {
		int n;
		cin >> n;

		vector<int> v(n);
		while (n--)
			cin >> v[v.size()-1 - n];

		cout << count_shifts(v) << endl;
	}
}

#include <iostream>
#include <limits>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

class AhoCorasick {
public:
	class Node {
	public:
		Node(char c);
		~Node();
		Node * get_child(char c);
		vector<Node *> get_children();
		Node * add_child(char c);

		char val;
		vector<unsigned long long> healths;
		vector<unsigned long long> index;
		bool accept = false;
		Node *suffix = nullptr;
		Node *output = nullptr;
		vector<Node *> children;
	};

	AhoCorasick(const vector<string>& genes, const vector<unsigned long long>& healths) :
		root(new Node(' '))
	{
		for (size_t i{0}; i < genes.size(); ++i) {
			auto last{insert(genes[i])};
			last->accept = true;
			last->healths.emplace_back(healths[i]);
			last->index.emplace_back(i);
		}
		find_links();
		reset();
	}

	void reset() {
		state = root;
	}

	unsigned long long feed(char c, size_t beg, size_t end) {
		while (state->get_child(c) == nullptr) {
			if (state == root) break;
			state = state->suffix;
		}

		auto next_state = state->get_child(c);
		if (next_state != nullptr) state = next_state;

		unsigned long long h{0};
		for (auto out = state; out != nullptr; out = out->output) {
			if (out->accept) {
				for (auto i = lower_bound(out->index.begin(), out->index.end(), beg);
						 i != out->index.end() && *i <= end; ++i) {
					h += out->healths[distance(out->index.begin(), i)];
				}
			}
		}
		return h;
	}

private:
	void find_links() {
		queue<Node *> q;
		root->suffix = nullptr;
		for (auto c : root->get_children()) {
			c->suffix = root;
			q.push(c);
		}

		while (!q.empty()) {
			Node *w{q.front()};
			q.pop();

			for (auto a : w->get_children()) {
				Node *x{w->suffix};
				while (a->suffix == nullptr) {
					if (x->get_child(a->val) != nullptr) a->suffix = x->get_child(a->val);
					else if (x == root) a->suffix = root;
					else x = x->suffix;
				}
				a->output = (a->suffix->accept) ? a->suffix : a->suffix->output;
				q.push(a);
			}
		}
	}

	Node * insert(const string& s) {
		Node *n{root};
		for (auto c : s) {
			n = n->add_child(c);
		}
		return n;
	}

	Node *root;
	Node *state;
};



AhoCorasick::Node::Node(char c) : val(c), children(26, nullptr) {}

AhoCorasick::Node::~Node() {
	for (auto c : children) {
		delete c;
	}
}

AhoCorasick::Node * AhoCorasick::Node::get_child(char c) {
	return children[c - 'a'];
}

vector<AhoCorasick::Node *> AhoCorasick::Node::get_children() {
	vector<AhoCorasick::Node *> v;
	for (auto c : children) {
		if (c != nullptr) {
			v.push_back(c);
		}
	}
	return v;
}

AhoCorasick::Node * AhoCorasick::Node::add_child(char c) {
	AhoCorasick::Node *&child{children[c - 'a']};
	if (child == nullptr) {
		child = new AhoCorasick::Node(c);
	}
	return child;
}





unsigned long long eval_dna(AhoCorasick& ac, size_t start, size_t end, const string& d) {
	unsigned long long h{0};
	for (auto c : d) {
		h += ac.feed(c, start, end);
	}
	ac.reset();
	return h;
}

int main() {
	size_t num_genes; cin >> num_genes;

	vector<string> genes(num_genes);
	for (size_t i{0}; i < num_genes; ++i) cin >> genes[i];

	vector<unsigned long long> healths(num_genes);
	for (size_t i{0}; i < num_genes; ++i) cin >> healths[i];

	AhoCorasick ac(genes, healths);

	int s; cin >> s;

	unsigned long long hmin{numeric_limits<unsigned long long>::max()};
	unsigned long long hmax{numeric_limits<unsigned long long>::min()};
	while (s--) {
		size_t start, end; cin >> start >> end;
		string d; cin >> d;

		unsigned long long h{eval_dna(ac, start, end, d)};
		if (h < hmin) hmin = h;
		if (h > hmax) hmax = h;
	}

	cout << hmin << ' ' << hmax;
}

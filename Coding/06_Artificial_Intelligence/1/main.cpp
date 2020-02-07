#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <cmath>
#include <sstream>
#include <bits/stdc++.h>

using namespace std;

const int MAXBUF = 1 << 20;
char buf[MAXBUF];

map<string, vector<int> > dict;

const int MAXC = 7000;
int alphabet[256 * 256 * 256];
unsigned alphabet_rev[MAXC];
int f1[MAXC];
int f2[MAXC][MAXC];

void printw(ofstream& fw, unsigned w) {
	char c1 = w / 256 / 256, c2 = (w / 256) % 256, c3 = w % 256;
	fw << c1 << c2 << c3;
}

unsigned getw(uint8_t c1, uint8_t c2, uint8_t c3) {
	return c1 * 256 * 256 + c2 * 256 + c3;
}

void load_alphabet() {
	FILE* f = fopen("alphabet.txt", "r");
	int n = fread(buf, 1, MAXBUF, f);
	for (int i = 2; i < n; i += 3) {
		unsigned w = getw(buf[i - 2], buf[i - 1], buf[i]);
		int j = (i + 1) / 3;
		alphabet[w] = j;
		alphabet_rev[j] = w;
	}
	fclose(f);
}

void load_dict() {
	FILE* f = fopen("dict.txt", "r");
	if (fscanf(f, "%s", buf) < 1) return;
	while (true) {
		bool has_next = true;
		string key = buf;
		vector<int> candidates;
		while ((has_next = (fscanf(f, "%s", buf) == 1)) && (uint8_t)buf[0] > 127) {
			candidates.push_back(alphabet[getw(buf[0], buf[1], buf[2])]);
		}
		dict[key] = move(candidates);
		if (!has_next) break;
	}
	fclose(f);
}

void load_data() {
	printf("begin loading data...\n");
	FILE* f = fopen("db.txt", "r");	
	while (true) {
		int x1, v;
		if (fscanf(f, "%d", &v) < 1 || !v) break;
		fscanf(f, "%d", &x1);
		f1[x1] = v;
	}
	printf("loading finished...\n");
	while (true) {
		int x1, x2, v;
		if (fscanf(f, "%d", &v) < 1 || !v) break;
		fscanf(f, "%d%d", &x1, &x2);
		f2[x1][x2] = v;
	}
	printf("read finished...\n");
	fclose(f);
}

void save_data() {
	FILE *f = fopen("db.txt", "w");
	for (int i = 0; i < MAXC; ++i) if (f1[i]) {
		fprintf(f, "%d %d ", f1[i], i);
	}
	fprintf(f, "0 ");
	for (int i = 0; i < MAXC; ++i) for (int j = 0; j < MAXC; ++j) if (f2[i][j]) {
		fprintf(f, "%d %d %d ", f2[i][j], i, j);
	}
	fprintf(f, "0\n");
	fclose(f);
}

void load_corpus(const char* filename) {
	FILE* f = fopen(filename, "r");
	int p, q;
	uint8_t c1 = 0, c2 = 0, c3 = 0;
	int w1 = 0, w2 = 0;
	while ((q = fread(buf, 1, MAXBUF, f))) {
		p = 0;
		while (p < q) {
			c1 = c2; c2 = c3; c3 = buf[p++];
			if (c1 && c2 && c3) {
				unsigned w = getw(c1, c2, c3);
				if (alphabet[w]) {
					w1 = w2; w2 = alphabet[w];
					f1[w2] += 1;
					if (w2) f2[w1][w2] += 1;
					c1 = c2 = c3 = 0;
				} else {
					w1 = w2 = 0;
				}
			}
		}
	}
	fclose(f);
}

const int MAXN = 10000;
map<int, double> dp[MAXN];
map<int, int> pre[MAXN];

vector<int> translate(const vector<string>& a) {
	vector<int> res;
	if (!a.size()) return res;
	int n = a.size();
	assert(n < MAXN);
	for (int i = 0; i < n; ++i) {
		dp[i].clear();
		pre[i].clear();
		auto& candidates = dict[a[i]];
		if (!candidates.size()) {
			// fprintf(stderr, "fucker");
			return res;
		}
		if (i == 0) {
			for (auto j : candidates) {
				dp[i][j] = log(f1[j]);
			}
		} else {
			for (auto u : dp[i - 1]) {
				int j = u.first;
				double v = u.second;
				for (auto k : candidates) {
					int e1 = f1[j];
					int e2 = f2[j][k];
					if (!e1 || !e2) {
						e2 = 1;
						e1 = 1000;
					}
					if (e1 && e2) {
						double t = dp[i - 1][j] + log(e2) - log(e1);
						if (!dp[i].count(k)) {
							dp[i][k] = t;
							pre[i][k] = j;
						} else {
							if (t > dp[i][k]) {
								dp[i][k] = t;
								pre[i][k] = j;
							}
						}
					}
				}
			}
		}
	}
	double max_p = -1e6;
	int now_j = -1;
	for (auto u : dp[n - 1]) {
		if (u.second > max_p) {
			max_p = u.second;
			now_j = u.first;
		}
	}
	if (now_j < 0) {
		return res;
	}
	for (int i = n - 1; i >= 0; --i) {
		res.push_back(now_j);
		now_j = pre[i][now_j];
	}
	reverse(res.begin(), res.end());
	return res;
}

void test(const string& input_file, const string& output_file) {
	ifstream fr;
	ofstream fw;
	fr.open(input_file);
	fw.open(output_file);

	string line;
	// printf("I FUCK\n");
	while (getline(fr, line)) {
	
		stringstream ss;
		ss << line;
		vector<string> a;
		string t;
		
		while (ss >> t) {
			a.push_back(t);
		}
		// printf("ri1\n");
		auto res = translate(a);
		// printf("ri2\n");
		for (auto x : res) {
			printw(fw, alphabet_rev[x]);
		}
		
		fw << endl;
	}
	// printf("I END\n");
}

int main(int argc, char* argv[]) {
	// printf("fuck0\n");
	if (argc != 3) {
		fprintf(stderr, "usage: pinyin [input_file] [output_file]\n");
		return 0;
	}

	load_alphabet();

	load_dict();

	load_data();


	// load_corpus("corpus/16_02_re.txt");
	// load_corpus("corpus/16_08_re.txt");
	// load_corpus("corpus/16_10_re.txt");

	test(argv[1], argv[2]);
	/*
	save_data();
	*/
	return 0;
}

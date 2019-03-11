#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <stack>
#include <set>
#include <cstring>
#include <queue>
#include <stdlib.h>
#include <iomanip>
using namespace std;
void faprocess(char s[], char token[], int &p, int &stat, int &count) {
	switch (stat) {
	case 0:
		for (int j = 0; j < 20; j++) token[j] = 'x';
		switch (s[p]) {
		case 'a':
		case 'b':
		case 'd':
			stat = 1;
			break;
		case 'c':
			stat = 2;
			break;
		case 'e':
			stat = 3;
			break;
		case 'f':
			stat = 4;
			break;
		case 'g':
			stat = 5;
			break;
		case '0':
		case '1':
			stat = 6;
			break;
		case '+':
			stat = 11;
			break;
		case '-':
			stat = 12;
			break;
		case '<':
			stat = 13;
			break;
		case '>':
			stat = 14;
			break;
		case '=':
			stat = 15;
			break;
		case '?':
			stat = 16;
			break;
		case ',':
			stat = 17;
			break;
		case '{':
			stat = 18;
			break;
		case '}':
			stat = 19;
			break;
		case '(':
			stat = 20;
			break;
		case ')':
			stat = 21;
			break;
		case ';':
			stat = 22;
			break;
		case '$':
			stat = -1;
			break;
		default:
			break;
		}
		token[count++] = s[p++];
		break;
	case 1:
		if (s[p] >= 'a'&&s[p] <= 'g')
			token[count++] = s[p++];
		else if (s[p] == ' ') {
			token[count] = '\0';
			p++;
		}
		else;
		break;
	case 2:
		if (s[p] == 'c') {
			stat = 7;
			token[count++] = s[p++];
		}
		else if (s[p] >= 'a'&&s[p] <= 'g') {
			token[count++] = s[p++];
			stat = 1;
		}
		else if (s[p] == ' ') {
			token[count] = '\0';
			p++;
		}
		else;
		break;
	case 3:
		if (s[p] == 'e') {
			stat = 8;
			token[count++] = s[p++];
		}
		else if (s[p] >= 'a'&&s[p] <= 'g') {
			token[count++] = s[p++];
			stat = 1;
		}
		else if (s[p] == ' ') {
			token[count] = '\0';
			p++;
		}
		else;
		break;
	case 4:
		if (s[p] == 'f') {
			stat = 9;
			token[count++] = s[p++];
		}
		else if (s[p] >= 'a'&&s[p] <= 'g') {
			token[count++] = s[p++];
			stat = 1;
		}
		else if (s[p] == ' ') {
			token[count] = '\0';
			p++;
		}
		else;
		break;
	case 5:
		if (s[p] == 'g') {
			stat = 10;
			token[count++] = s[p++];
		}
		else if (s[p] >= 'a'&&s[p] <= 'g') {
			token[count++] = s[p++];
			stat = 1;
		}
		else if (s[p] == ' ') {
			token[count] = '\0';
			p++;
		}
		else;
		break;
	case 6:
		if (s[p] == ' ') {
			token[count] = '\0';
			p++;
		}
		else if (s[p] == '1' || s[p] == '0') token[count++] = s[p++];
		else;
		break;
	case 7:
	case 8:
	case 9:
	case 10:
		if (s[p] == ' ') {
			token[count] = '\0';
			p++;
		}
		else if (s[p] >= 'a'&&s[p] <= 'g') {
			token[count++] = s[p++];
			stat = 1;
		}
		else;
		break;
	case 11:
	case 12:
	case 13:
	case 14:
	case 15:
	case 16:
	case 17:
	case 18:
	case 19:
	case 20:
	case 21:
	case 22:
		if (s[p] == ' ') {
			token[count] = '\0';
			p++;
		}
		else;
		break;
	default:
		break;
	}
}
void filter(char r[], int p)
{
	char tstr[10000];
	int count = 0;
	for (int i = 0; i <= p; i++) {
		if (r[i] == '/'&&r[i + 1] == '/')
			while (r[i] != '\n')
				i++;
		if (r[i] == '/'&&r[i + 1] == '*') {
			i += 2;
			while (r[i] != '*' || r[i + 1] != '/') {
				i++;
				if (r[i] == '$') {
					printf("didn't find */...\n");
					exit(0);
				}
			}
			i += 2;
		}
		if (r[i] != '\n'&&r[i] != '\t'&&r[i] != '\v'&&r[i] != '\r')
			tstr[count++] = r[i];
	}
	tstr[count] = '\0';
	strcpy(r, tstr);
}
map<char, int>getnum;
char getChar[10000];
vector<string>proce;
int table[3000][3000];
int tb_s_r[3000][3000];
int num = 0; int numvt = 0;
void rein() {
	memset(table, -1, sizeof(table));
	getnum['$'] = 0;
	getChar[0] = '$';
	getnum['i'] = ++num;
	getChar[num] = 'i';
	getnum['f'] = ++num;
	getChar[num] = 'f';
	getnum['g'] = ++num;
	getChar[num] = 'g';
	getnum['+'] = ++num;
	getChar[num] = '+';
	getnum[','] = ++num;
	getChar[num] = ',';
	getnum['c'] = ++num;
	getChar[num] = 'c';
	getnum['='] = ++num;
	getChar[num] = '=';
	getnum[';'] = ++num;
	getChar[num] = ';';
	getnum['$'] = ++num;
	getChar[num] = '$';
	numvt = ++num;
	getnum['W'] = ++num;
	getChar[num] = 'W';
	getnum['S'] = ++num;
	getChar[num] = 'S';
	getnum['A'] = ++num;
	getChar[num] = 'A';
	proce.push_back("WS");
	proce.push_back("Si=A;S");
	proce.push_back("SfA,S");
	proce.push_back("SgA;S");
	proce.push_back("S$");
	proce.push_back("Ai");
	proce.push_back("Ac");
	proce.push_back("Ac+c");
	proce.push_back("Ac+i");
	proce.push_back("Ai+i");
	proce.push_back("Ai+c");
}
struct regular {
	int nump;
	int id;
	string fiest;
};
string getp[10000];
void getpp() {
	for (int i = 0; i < proce.size(); i++) {
		int temp = getnum[proce[i][0]];
		getp[temp] += char('0' + i);
	}
}
string first[10000];
bool gotfirst[10000];
void dfsgetfirst(int nv, int nump) {
	int temp = getnum[proce[nump][1]];
	gotfirst[nump] = 1;
	if (temp <= numvt)first[nv] += char('0' + temp);
	else {
		for (int i = 0; i < getp[temp].size(); i++) {
			if (proce[nump][0] == proce[nump][1])continue;
			dfsgetfirst(temp, getp[temp][i] - '0');
		}
		first[nv] += first[temp];
	}
}
void get_first() {
	for (int i = 1; i <= numvt; i++) {
		first[i] = char('0' + i);
	}
	for (int i = 0; i < proce.size(); i++) {
		if (proce[i][0] == proce[i][1])continue;
		if (gotfirst[i])continue;
		int temp = getnum[proce[i][0]];
		dfsgetfirst(temp, i);
	}
}
vector<vector<regular> >v;
int e[10000][300]; int head[10000]; int nume = 0;
void addegde(int from, int to, int w) {
	e[nume][0] = to; e[nume][1] = head[from]; head[from] = nume;
	e[nume++][2] = w;
}
void clear() {
	for (int i = 0; i < 10000; i++)
		head[i] = -1;
	for (int i = 0; i < 3000; i++)
		for (int j = 0; j < 3000; j++)
			tb_s_r[i][j] = table[i][j] = -1;
	nume = 0;
}
inline bool reeq(regular a, regular b) {
	if (a.fiest == b.fiest&&a.id == b.id&&a.nump == b.nump)return 1;
	return 0;
}
bool isin(regular a, vector<regular> b) {
	for (int i = 0; i < b.size(); i++)
		if (reeq(a, b[i]))return 1;
	return 0;
}
vector<regular>  hebing(vector<regular>a, vector<regular>b) {
	for (int i = 0; i < b.size(); i++) {
		if (isin(b[i], a))continue;
		else
			a.push_back(b[i]);
	}
	return a;
}
bool rejieq(vector<regular> a, vector<regular> b) {
	if (a.size() != b.size())return 0;
	for (int i = 0; i < a.size(); i++)
		if (!isin(a[i], b))return 0;
	return 1;
}
int reji_isin_rejizu(vector<regular>a, vector<vector<regular> >b) {
	for (int i = 0; i < b.size(); i++) {
		if (rejieq(a, b[i]))return i;
	}
	return -1;
}
vector<regular> get_close(regular t) {
	vector<regular> temp;
	temp.push_back(t);
	queue<regular> q;
	q.push(t);
	while (!q.empty()) {
		regular cur = q.front();
		q.pop();
		if (cur.id == proce[cur.nump].size())
			continue;
		int tt = getnum[proce[cur.nump][cur.id]];
		if (tt <= numvt)continue;
		for (int i = 0; i < getp[tt].size(); i++) {
			regular c;
			c.id = 1;
			c.nump = getp[tt][i] - '0';
			if (proce[cur.nump].size() - cur.id == 1)
				c.fiest += cur.fiest;
			else {
				int tttnum = getnum[proce[cur.nump][cur.id + 1]];
				c.fiest += first[tttnum];
			}
			if (!isin(c, temp)) {
				q.push(c);
				temp.push_back(c);
			}
		}
	}
	return temp;
}
void get_regularjizu() {
	vector<regular>temp;
	regular t;
	t.nump = 0; t.id = 1; t.fiest += '0';
	temp = get_close(t);
	queue<vector<regular> >q;
	q.push(temp);
	v.push_back(temp);
	while (!q.empty()) {
		vector<regular> cur = q.front();
		q.pop();
		for (int i = 1; i <= num; i++) {
			if (i == numvt)continue;
			vector<regular> temp;
			for (int j = 0; j < cur.size(); j++) {
				if (cur[j].id == proce[cur[j].nump].size())continue;
				int tt = getnum[proce[cur[j].nump][cur[j].id]];
				if (tt == i) {
					regular tempt;
					tempt.fiest = cur[j].fiest;
					tempt.id = cur[j].id + 1;
					tempt.nump = cur[j].nump;
					temp = hebing(temp, get_close(tempt));
				}
			}
			if (temp.size() == 0)continue;
			int numcur = reji_isin_rejizu(cur, v);
			int tttnum = reji_isin_rejizu(temp, v);
			if (tttnum == -1) {
				v.push_back(temp);
				q.push(temp);
				addegde(numcur, v.size() - 1, i);
			}
			else
				addegde(numcur, tttnum, i);
		}
	}
}
bool get_table() {
	for (int i = 0; i < v.size(); i++) {
		for (int j = head[i]; j != -1; j = e[j][1]) {
			if (table[i][e[j][2]] != -1)return 0;
			table[i][e[j][2]] = e[j][0];
			tb_s_r[i][e[j][2]] = -1;
		}
	}
	for (int i = 0; i < v.size(); i++)
		for (int j = 0; j < v[i].size(); j++)
			if (v[i][j].id == proce[v[i][j].nump].size())
				for (int k = 0; k < v[i][j].fiest.size(); k++)
				{
					if (table[i][(v[i][j].fiest)[k] - '0'] != -1)return 0;
					if ((v[i][j].fiest)[k] == '0'&&v[i][j].nump == 0)
						table[i][(v[i][j].fiest)[k] - '0'] = -3;
					else
					{
						table[i][(v[i][j].fiest)[k] - '0'] = v[i][j].nump;
						tb_s_r[i][(v[i][j].fiest)[k] - '0'] = -2;
					}
				}
	return 1;
}
string word;
void  print_restate(int count, stack<int>state, stack<int>wd, int i, FILE* wf)
{
	stack<int>temp;
	while (!wd.empty()) {
		temp.push(wd.top());
		wd.pop();
	}
	string s;
	while (!temp.empty()) {
		s += getChar[temp.top()];
		temp.pop();
	}
	cout << left << setw(30) << s;
	fprintf(wf, "%-30s", s.data());
	string s2;
	for (int j = i; j < word.size(); j++)
		s2 += word[j];
	cout << left << setw(30) << s2;
	fprintf(wf, "%-30s", s2.data());
}
bool analyze() {
	FILE* wf2;
	if ((wf2 = fopen("./sequence_of_reductions.txt", "w+")) == NULL) {
		cout << "can't open this file";
		exit(0);
	}
	cout << word << endl << endl;
	cout << "The syntax is:\n(The syntax use i-id, f-ff, g-gg, c-constant)" << endl;
	fprintf(wf2, "The syntax is:\n(The syntax use i-id, f-ff, g-gg, c-constant)\n");
	cout << "W->S\nS->i = A; S\nS->fA, S\nS->gA; S\nS->$\nA->i\nA->c\nA->c + c\nA->c + i\nA->i + i\nA->i + c" << endl << endl;
	fprintf(wf2, "W->S\nS->i = A; S\nS->fA, S\nS->gA; S\nS->$\nA->i\nA->c\nA->c + c\nA->c + i\nA->i + i\nA->i + c\n");
	cout << "Sequence of reductions: " << endl;
	fprintf(wf2, "Sequence of reductions: \n");
	stack<int>state;
	stack<int>wd;
	int count = 0;
	state.push(0);
	wd.push(0);
	for (int i = 0;;) {
		int cur = state.top();
		if (table[cur][getnum[word[i]]] == -1)return 0;
		if (table[cur][getnum[word[i]]] == -3) {
			print_restate(count++, state, wd, i, wf2);
			cout << "acc!" << endl;
			fprintf(wf2, "acc! \n");
			return 1;
		}
		if (tb_s_r[cur][getnum[word[i]]] == -1) {
			print_restate(count++, state, wd, i, wf2);
			int newstate = table[cur][getnum[word[i]]];
			string s = "action[" + to_string(cur) + "," + to_string(getnum[word[i]]) + "]=" + to_string(newstate) + "\n";
			cout << "action[" << cur << "," << getnum[word[i]] << "]=" << newstate << endl;
			fprintf(wf2, s.data());
			wd.push(getnum[word[i]]);
			state.push(newstate);
			i++;
		}
		else if (tb_s_r[cur][getnum[word[i]]] == -2) {
			print_restate(count++, state, wd, i, wf2);
			int numpro = table[cur][getnum[word[i]]];
			int len = proce[numpro].size() - 1;
			for (int ii = 0; ii < len; ii++) {
				wd.pop();
				state.pop();
			}
			wd.push(getnum[proce[numpro][0]]);
			int cur = state.top();
			string ss;
			cout << proce[numpro][0] << "->";
			ss += proce[numpro][0];
			ss += "->";
			for (int ii = 1; ii <= len; ii++) {
				cout << proce[numpro][ii];
				ss += proce[numpro][ii];
			}
			fprintf(wf2, (ss + "\n").data());
			cout << endl;
			state.push(table[cur][getnum[proce[numpro][0]]]);
		}
	}
	return 1;
}
int main() {
	char id_table[1000][20] = { "" };
	char s[10000];
	char token[20] = { 0 };
	int  count = 0, stat = 0, i = 0, p = 0, j = 0;
	FILE *rf, *wf, *wf2;
	if ((rf = fopen("./source_code.txt", "r")) == NULL) {
		cout << "can't open this file";
		exit(0);
	}
	s[p] = fgetc(rf);
	while (s[p] != '$') {
		p++;
		s[p] = fgetc(rf);
	}
	s[++p] = '\0';
	fclose(rf);
	cout << "The source code is:" << endl;
	cout << s << endl;
	filter(s, p);
	cout << endl << "After filter:" << endl;
	cout << s << endl << endl;
	p = 0;
	if ((wf = fopen("./mid_code.txt", "w+")) == NULL) {
		cout << "can't open this file";
		exit(0);
	}
	if ((wf2 = fopen("./sequence_of_tokens.txt", "w+")) == NULL) {
		cout << "can't open this file";
		exit(0);
	}
	cout << "Binary code: " << endl;
	fprintf(wf2, "In this language, use ff as if, and gg as goto. \nThis language only uses letter: a,b,c,d,e,f,g, uses numbers 0 and 1. \nAnd the calculator +, symbol ',', ';'etc.. \nOthers are identifier consisted with these seven letters. \n");
	while (stat != -1) {
		faprocess(s, token, p, stat, count);
		if (token[count] == '\0') {
			switch (stat) {
			case 1:
			case 2:
			case 3:
			case 4:
			case 5:
				for (i = 0; i < 1000; i++) {
					if (strcmp(id_table[i], token) == 0) {
						break;
					}
					if (strcmp(id_table[i], "") == 0) {
						strcpy(id_table[i], token);
						j++;
						break;
					}
				}
				printf("(id,%s)\n", token);
				fprintf(wf2, "(id,%s)\n", token);
				fprintf(wf, "id\n");
				break;
			case 6:
				printf("(constant, %s)\n", token);
				fprintf(wf, "cc\n");
				break;
			case 7:
			case 8:
			case 9:
			case 10:
				printf("(%s, reserve)\n", token);
				fprintf(wf2, "(%s, reserve)\n", token);
				fprintf(wf, "%s\n", token);
				break;
			case 11:
			case 12:
			case 13:
			case 14:
				printf("(%s, calculator)\n", token);
				fprintf(wf2, "(%s, calculator)\n", token);
				fprintf(wf, "%s\n", token);
				break;
			case 15:
			case 16:
			case 17:
			case 18:
			case 19:
			case 20:
			case 21:
			case 22:
				printf("(%s, symbol)\n", token);
				fprintf(wf2, "(%s, symbol)\n", token);
				fprintf(wf, "%s\n", token);
				break;
			default:
				break;
			}
			count = 0;
			stat = 0;
			while (s[p] == ' ') p++;
		}
	}
	fprintf(wf, "$");
	fclose(wf);
	fclose(wf2);
	char rs[10000];
	char rs2[10000];
	int p1 = 0, count2 = 0;
	clear();
	rein();
	getpp();
	get_first();
	get_regularjizu();
	if (!get_table()) {
		cout << "This syntax has too many entry points, it's not a LR(1) syntax..." << endl;
		system("pause");
		return 0;
	}
	cout << endl << "The syntax code£º" << endl;
	FILE *rf1;
	if ((rf1 = fopen("./mid_code.txt", "r")) == NULL) {
		cout << "can't open this file";
		exit(0);
	}
	rs[p1] = fgetc(rf1);
	while (rs[p1] != '$') {
		p1++;
		rs[p1] = fgetc(rf1);
	}
	rs[++p1] = '\0';
	fclose(rf1);
	char *pp;
	pp = strtok(rs, "\n");
	while (pp) {
		if (pp == "id")
			rs2[count2++] = 'i';
		else if (pp == "ff")
			rs2[count2++] = 'f';
		else if (pp == "gg")
			rs2[count2++] = 'g';
		else if (pp == "cc")
			rs2[count2++] = 'o';
		else rs2[count2++] = pp[0];
		pp = strtok(NULL, "\n");
	}
	rs2[count2] = '\0';
	word = rs2;
	if (!analyze())cout << "error!" << endl; else;
	system("pause");
	return 0;
}
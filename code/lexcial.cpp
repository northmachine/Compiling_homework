#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <stdlib.h>

using namespace std;

void faprocess(char s[], char token[], int &p, int &stat,int &count) {
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
		if(s[p]>='a'&&s[p]<='g')
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
		else if(s[p]=='1'||s[p]=='0') token[count++] = s[p++];
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

int main() {
	char id_table[1000][20] = { "" };
	char s[10000];
	char token[20] = { 0 };
	int  count = 0, stat = 0, i = 0, p = 0, j = 0;
	FILE *rf, *wf,*wf2;
	if ((rf = fopen("./source_code.txt", "r")) == NULL){
		cout << "can't open this file";
		exit(0);
	}
	s[p] = fgetc(rf);
	while (s[p] != '$'){
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
	if ((wf = fopen("./mid_code.txt", "w+")) == NULL){
		cout << "can't open this file";
		exit(0);
	}
	if ((wf2 = fopen("./sequence_of_tokens.txt", "w+")) == NULL){
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
					if (strcmp(id_table[i], token) == 0){
						break;
					}
					if (strcmp(id_table[i], "") == 0){
						strcpy(id_table[i], token);
						j++;
						break;
					}
				}
				printf("(id,%s)\n", token);
				fprintf(wf2,"(id,%s)\n", token);
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
				fprintf(wf2,"(%s, reserve)\n", token);
				fprintf(wf, "%s\n", token);
				break;
			case 11:
			case 12:
			case 13:
			case 14:
				printf("(%s, calculator)\n", token);
				fprintf(wf2,"(%s, calculator)\n", token);
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
				fprintf(wf2,"(%s, symbol)\n", token);
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
	system("pause");
	return 0;
}
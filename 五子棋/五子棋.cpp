#include<cstdio>
#include<iostream>
#include <string.h>
#include "conio.h"
using namespace std;

int map[15][15];

void output(int, int);
bool ifend(int, int, bool);

int main() {
	int localx = 0, localy = 0;
	bool flagblue = true, out = true;
	char tmp;
	output(localx, localy);
	do
	{
		out = true;
		flagblue = !flagblue;
		while (out) {
			tmp = getch();
			switch (tmp)
			{
			case 'w':
				if (localx > 0)
					localx--;
				break;
			case 's':
				if (localx < 14)
					localx++;
				break;
			case 'a':
				if (localy > 0)
					localy--;
				break;
			case 'd':
				if (localy < 14)
					localy++;
				break;
			case ' ':
				if (map[localx][localy] == 0) {
					map[localx][localy] = flagblue + 1;
					out = false;
				}
				break;
			default:
				break;
			}
			output(localx, localy);
		}
	} while (ifend(localx, localy, flagblue));
	return 0;
}

void output(int x,int y) {
	//==0 空 ==1 红方 ==2蓝方
	cout << "\033[2J\033[0;0H";
	for (int i = 0; i < 15; i++) {
		for (int j = 0; j < 15; j++) {
			switch (map[i][j])
			{
			case 0:
				if (i == x && j == y) {
					cout << "\033[40;37m" << "■" << "\033[0m";
				}
				else {
					cout << "\033[40;30m" << "■" << "\033[0m";
				}
				break;
			case 1:
				if (i == x && j == y) {
					cout << "\033[47;31m" << "■" << "\033[0m";
				}
				else {
					cout << "\033[40;31m" << "■" << "\033[0m";
				}
				break;
			case 2:
				if (i == x && j == y) {
					cout << "\033[47;34m" << "■" << "\033[0m";
				}
				else {
					cout << "\033[40;34m" << "■" << "\033[0m";
				}
				break;
			default:
				printf("\nERROR");
				exit(0);
			}
		}
		printf("\n");
	}
}

bool ifend(int x, int y, bool color) {
	int weight[4], step = 1;
	memset(weight, 0, sizeof(weight));
	while (x+step < 15) {
		if (map[x + step][y] == color + 1) {
			weight[0]++;
			step++;
		}
		else
			break;
	}
	step = 1;
	while (x - step > -1) {
		if (map[x - step][y] == color + 1) {
			weight[0]++;
			step++;
		}
		else
			break;
	}
	step = 1;
	while (y + step < 15) {
		if (map[x][y + step] == color + 1) {
			weight[2]++;
			step++;
		}
		else
			break;
	}
	step = 1;
	while (y - step > -1) {
		if (map[x][y - step] == color + 1) {
			weight[2]++;
			step++;
		}
		else
			break;
	}
	step = 1;
	while (y - step > -1 && x - step > -1) {
		if (map[x - step][y - step] == color + 1) {
			weight[3]++;
			step++;
		}
		else
			break;
	}
	step = 1;
	while (y + step < 15 && x + step < 15) {
		if (map[x + step][y + step] == color + 1) {
			weight[3]++;
			step++;
		}
		else
			break;
	}
	step = 1;
	while (y + step < 15 && x - step > -1) {
		if (map[x - step][y + step] == color + 1) {
			weight[1]++;
			step++;
		}
		else
			break;
	}
	step = 1;
	while (y - step > -1 && x + step < 15) {
		if (map[x + step][y - step] == color + 1) {
			weight[1]++;
			step++;
		}
		else
			break;
	}
	for (int i = 0; i < 4; i++)
		printf("%d ", weight[i]);
	for (int i = 0; i < 4; i++) {
		if (weight[i] >= 4) {
			printf("false");
			return false;
		}	
	}
	return true;
}
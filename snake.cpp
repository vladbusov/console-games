#include <iostream>
#include <time.h> 
#include <windows.h>
#include <dos.h>
#include <conio.h>
using namespace std;

typedef struct cat {
	int x;
	int y;
} cat;

int main(){
	

	int y = 1;

	int p = 0;
	bool dir = 0;

	bool lovit = 0;
	int fish = 0;

	cat f;
	f.x = 0;
	f.y = 0;

	int poplavok = 9;

	while (1){

		for (int i = 0; i < 9; i++){
			if (i >= poplavok){
				cout << "..";
			}
			else {
				cout << "  ";
			}

		}
		cout << '\\' << "?" << endl;

		for (int i = 0; i < 10; i++){
			for (int j = 0; j < 10; j++){
				if (j == p && i == y && dir == 0) { cout << '>' << " "; }
				else if (j == p && i == y && dir == 1) { cout << '<' << " "; }
				else if (j == poplavok && i == 0) { cout << 1 << " "; }
				else if (j == f.x && i < f.y && lovit == 1) { cout << '|' << " "; }
				else if (j == f.x && i == f.y && lovit == 1) { cout << ']' << " "; }
				else { cout << 0 << " "; }
			}
			cout << '-';
			cout << endl;
		}

		cout << "fish " << fish << endl << "keys: (a - left) (d - right) (s - catch) (q - exit)" << endl;
		cout << "lvl -" << " " << y << endl;

		if (_kbhit())
		{
			int c = _getch();
			if (c == 'q')
				return 0;
			if (c == 'd' && lovit == 0){
				if (poplavok < 9)
					poplavok++;
				cout << "right"<< endl;
			}
			if (c == 'a' && lovit == 0){
				if (poplavok > 0)
					poplavok--;
				cout << "left" << endl;
			}
			if (c == 's'){
				lovit = 1;
				cout << "catch" << endl;
				f.x = poplavok;
				f.y = 0;
			}
		}

		Sleep(300);

		if (p < 9 && dir == 0 && p > 0){
			p++;
		}
		else if (p < 9 && dir == 1 && p > 0){
			p--;
		}
		else if (p == 0){
			dir = 0;
			p++;
		}
		else if (p == 9){
			dir = 1;
			p--;
		}

		if (lovit == 1)
			if (f.y < y){
				f.y++;
			}
			else {
				if (p == f.x && f.y == y){
					fish++;
					lovit = 0;
					f.x = 0;
					f.y = 0;
					if (y < 9){
						y++;
						p = 0;
						dir = 0;
					}
					else {
						system("cls");
						cout << "You win!" << endl;
						system("PAUSE");
						return 0;
					}
				}
				if (f.y < 9){
					f.y++;
				}
				else {
					lovit = 0;
					f.x = 0;
					f.y = 0;
				}
			}

		system("cls");
	}



	return 0;
}
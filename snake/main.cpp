

#include <Windows.h>

#include <iostream>

#include <conio.h>



		 using namespace std;



struct cell{

	int direction;

	int x;

	int y;

	cell& operator=(cell& kek){

		x = kek.x;

		y = kek.y;

		direction = kek.direction;

		return *this;

	}

};



struct Zmeyka {

	cell * arr;

	int size;



	Zmeyka(){

		arr = new cell[2];

		size = 2;

		for (int i = 0; i < 2; i++){

			arr[i].direction = 0;

		}



		arr[0].x = 2;

		arr[0].y = 17;

		arr[1].x = 2;

		arr[1].y = 18;



	}



	void increase(){

		cell *buff = new cell[size++];

		for (int i = 0; i < (size - 1); i++){

			buff[i] = arr[i];

		}

		//delete[] arr;

		arr = buff;

		if (arr[size - 2].direction == 2){

			arr[size - 1].x = arr[size - 2].x;

			arr[size - 1].y = arr[size - 2].y - 1;

			arr[size - 1].direction = arr[size - 2].direction;

		}

		if (arr[size - 2].direction == 0){

			arr[size - 1].x = arr[size - 2].x;

			arr[size - 1].y = arr[size - 2].y + 1;

			arr[size - 1].direction = arr[size - 2].direction;

		}

		if (arr[size - 2].direction == 1){

			arr[size - 1].x = arr[size - 2].x - 1;

			arr[size - 1].y = arr[size - 2].y;

			arr[size - 1].direction = arr[size - 2].direction;

		}

		if (arr[size - 2].direction == 3){

			arr[size - 1].x = arr[size - 2].x + 1;

			arr[size - 1].y = arr[size - 2].y;

			arr[size - 1].direction = arr[size - 2].direction;

		}



	}



	~Zmeyka(){

		//delete[] arr;

	}



};



struct turn {

	turn(){

		yes = 0;

		y = 0;

		x = 0;

		dir = 0;

	}



	bool yes;

	int dir;

	int y;

	int x;



	turn& operator=(turn& kek){

		x = kek.x;

		y = kek.y;

		yes = kek.yes;

		dir = kek.dir;

		return *this;

	}

};





struct turns {



	turns(){

		size = 0;

	}



	turn * arr;

	int size;

	void clean(){

		for (int i = 0; i < size; i++){

			if (arr[i].yes == 0){

				size--;

				for (int j = i; j < size; j++){

					arr[j] = arr[j + 1];

					//ïðîáëåìñ

				}

				//delete &(arr[size]);

			}

		}



	}



	void add(int x, int y, int dir){

		turn * buff = new turn[size++];

		for (int i = 0; i < size - 1; i++)

			buff[i] = arr[i];

		// delete[] arr;

		arr = buff;

		arr[size - 1].x = x;

		arr[size - 1].y = y;

		arr[size - 1].yes = 1;

		arr[size - 1].dir = dir;

	}







};









struct apple

{

	apple(){

		yes = 0;

	}

	bool yes;

	int x;

	int y;

	void generate(){

		x = (rand() % 19);

		y = (rand() % 19);

		yes = true;

	}

};





bool check_collision(Zmeyka *sn){

	for (int i = 0; i < sn->size; i++){

		for (int j = 0; j < sn->size; j++){

			if (sn->arr[j].x == sn->arr[i].x && sn->arr[j].y == sn->arr[i].y)

				if (i != j)

					return 1;

		}

	}

	return 0;

}



int main(){



	Zmeyka snake;

	apple ap;

	turns l;

	turn t;



	while (true)

	{



		if (_kbhit())

		{

			 int c= _getch();

			if (c == 'q')

				return 0;

			if (c == 'w'){

				if (snake.arr[0].direction != 2){

					snake.arr[0].direction = 0;

					l.add(snake.arr[0].x, snake.arr[0].y, snake.arr[0].direction);

				}

			}

			if (c == 's'){

				if (snake.arr[0].direction != 0){

					snake.arr[0].direction = 2;

					l.add(snake.arr[0].x, snake.arr[0].y, snake.arr[0].direction);

				}

			}

			if (c == 'a'){

				if (snake.arr[0].direction != 1){

					snake.arr[0].direction = 3;

					l.add(snake.arr[0].x, snake.arr[0].y, snake.arr[0].direction);

				}

			}

			if (c == 'd'){

				if (snake.arr[0].direction != 3){

					snake.arr[0].direction = 1;

					l.add(snake.arr[0].x, snake.arr[0].y, snake.arr[0].direction);

				}

			}

		}







		if (ap.yes == 0){

			ap.generate();

		}





		for (int i = 0; i < 20; i++){

			for (int j = 0; j < 20; j++){



				bool comparison = 0;



				for (int k = 0; k < snake.size; k++){

					if (i == snake.arr[k].y && j == snake.arr[k].x)

						comparison = 1;

				}



				if (comparison == 1){

					cout << "x" << " ";

				}

				else if (i == ap.y && j == ap.x){

					cout << "O" << " ";

				}

				else {

					cout << '.' << " ";

				}

			}

			cout << endl;

		}





		if (ap.x == snake.arr[0].x && ap.y == snake.arr[0].y){

			snake.increase();

			ap.yes = 0;

		}







		for (int s = 0; s < l.size; s++){

			if (l.arr[s].yes == 1){

				for (int i = 0; i < snake.size; i++){

					if (l.arr[s].x == snake.arr[i].x)

						if (l.arr[s].y == snake.arr[i].y){

							snake.arr[i].direction = l.arr[s].dir;

							/*

							bool jiest = 0;

							for (int y = 0; y < snake.size; y++){

							if (snake.arr[y].direction != l.arr[s].dir)

							jiest = 1;

							}*/

							if (i == snake.size - 1){

								l.arr[s].yes = 0;

								//l.clean();

							}

						}

				}

			}

		}







		for (int i = 0; i < snake.size; i++){

			if (snake.arr[i].direction == 0){



				bool ok = 0;

				for (int u = 0; u < snake.size; u++){

					if (u != i){

						if (snake.arr[u].y == snake.arr[i].y - 1)

							if (snake.arr[u].y == 0)

								if (snake.arr[u].x == snake.arr[i].x)

									ok = 1;

					}

				}

				if (ok != 1){

					if (snake.arr[i].y > 0)

						snake.arr[i].y--;

				}

				else {

					system("cls");

					cout << endl << '\a' << endl << endl << '\t' << "GAME OVER!" << endl << endl;

					system("PAUSE");

					return 0;

				}

			}

			if (snake.arr[i].direction == 1){

				bool ok = 0;

				for (int u = 0; u < snake.size; u++){

					if (u != i){

						if (snake.arr[u].y == snake.arr[i].y)

							if (snake.arr[u].x == 19)

								if (snake.arr[u].x == snake.arr[i].x + 1)

									ok = 1;

					}

				}

				if (ok != 1){

					if (snake.arr[i].x < 19)

						snake.arr[i].x++;

				}

				else {

					system("cls");

					cout << endl << '\a' << endl << endl << '\t' << "GAME OVER!" << endl << endl;

					system("PAUSE");

					return 0;

				}

			}

			if (snake.arr[i].direction == 2){

				bool ok = 0;

				for (int u = 0; u < snake.size; u++){

					if (u != i){

						if (snake.arr[u].y == snake.arr[i].y + 1)

							if (snake.arr[u].y == 19)

								if (snake.arr[u].x == snake.arr[i].x)

									ok = 1;

					}

				}

				if (ok != 1){

					if (snake.arr[i].y < 19)

						snake.arr[i].y++;

				}

				else {

					system("cls");

					cout << endl << '\a' << endl << endl << '\t' << "GAME OVER!" << endl << endl;

					system("PAUSE");

					return 0;

				}

			}

			if (snake.arr[i].direction == 3){

				bool ok = 0;

				for (int u = 0; u < snake.size; u++){

					if (u != i){

						if (snake.arr[u].y == snake.arr[i].y)

							if (snake.arr[u].x == 0)

								if (snake.arr[u].x == snake.arr[i].x - 1)

									ok = 1;

					}

				}

				if (ok != 1){

					if (snake.arr[i].x > 0)

						snake.arr[i].x--;

				}

				else {

					system("cls");

					cout << endl << '\a' << endl << endl << '\t' << "GAME OVER!" << endl << endl;

					system("PAUSE");

					return 0;

				}

			}



		}





		l.clean();



		if (check_collision(&snake) == 1){

			system("cls");

			cout << endl << '\a' << endl << endl << '\t' << "GAME OVER!" << endl << "You ate yourself!" << endl;

			system("PAUSE");

			return 0;

		}



		cout << endl << '\t' << "Your score now: " << snake.size - 2 << endl;

		Sleep(300);

		system("cls");



	}

	return 0;

}

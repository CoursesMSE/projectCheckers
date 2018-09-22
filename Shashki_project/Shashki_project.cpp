#include "pch.h"
#include <iostream>
#include <string>
#include <string.h>

using namespace std;
const int SIZE = 8;

class checker
{
public:
	string coord;
	string color;
	void set_checker(string str, string color);
	void delete_checker();
};

class field
{
public:
	bool checker_is;
	string coord;
	checker bot;
	void move_checker(string old_c, string new_c, field p[][SIZE], string);
};

void create_field(field p[][8]);
void inicialization_field(field p[][SIZE]);
void finding(string str, field p[][SIZE]);

int main()
{
	setlocale(0, "Russian");
	field pole[SIZE][SIZE];
	inicialization_field(pole);
	create_field(pole); 
	string coord_turn_choise, new_coord;
	while (true)
	{
		getline(cin, coord_turn_choise);
		getline(cin, new_coord);
		for (int i = 0; i < 8; i++)
			for (int j = 0; j < 8; j++)
				if (pole[i][j].coord == coord_turn_choise)
					pole[i][j].move_checker(coord_turn_choise, new_coord, pole, pole[i][j].bot.color);
		create_field(pole);
	}			
	return 0;
}

void checker::delete_checker()
{

}
void field::move_checker(string old_c, string new_c, field p[][SIZE], string color)
{
	for (int i = 0; i < 8; i++)
		for (int j = 0; j < 8; j++)
		{
			if (p[i][j].coord == new_c)
			{

				p[i][j].checker_is = true;
				p[i][j].bot.coord = new_c;
				p[i][j].bot.color = color;
			}
			else if (p[i][j].coord == old_c)
			{
				p[i][j].checker_is = false;
				p[i][j].bot.coord = "";
				p[i][j].bot.color = "";
			}
		}
}
void checker::set_checker(string str, string c)
{
	coord = str;
	color = c;
}


void create_field(field p[][SIZE])
{
	for (int i = -1; i < SIZE; i++)
	{
		for (int k = 0; k <= (SIZE + 1) * 2; k++)
			cout << '-';
		cout << endl;
		for (int j = -1; j < SIZE; j++)
		{
			cout << '|';
			if (j == -1)
			{
				if (i != -1)
					cout << char(i + 49) << '|';
				else
					cout << ' ' << '|';
			} else if (i == -1)
			{
				if (j != -1)
					cout << char(j + 65);
				else
					cout << ' ';
			} else if (p[i][j].checker_is)
			{
				if (p[i][j].bot.color == "white")
					cout << 'Б';
				else if (p[i][j].bot.color == "black")
					cout << 'Ч';
				//cout << p[i][j].coord;
			}
			else
				cout << ' ';
		}
		cout << '|' << endl;
	}
	for (int k = 0; k <= (SIZE + 1) * 2; k++)
		cout << '-';
	cout << endl;
}

void inicialization_field(field p[][SIZE])
{
	string str;
	for (int i = 0; i < 8; i++)
		for (int j = 0; j < 8; j++)
		{
			p[i][j].coord += char(j + 65);
			p[i][j].coord += char(i + 49);
			p[i][j].checker_is = false;
			if (i >= 0 && i <= 2 && (i + j) % 2 == 1)
			{
				str += char(j + 65);
				str += char(i + 49);
				p[i][j].bot.set_checker(str, "black");
				p[i][j].checker_is = true;
			}
			if (i >= 5 && i <= 7 && (i + j) % 2 == 1)
			{
				str += char(j + 65);
				str += char(i + 49);
				p[i][j].bot.set_checker(str, "white");
				p[i][j].checker_is = true;
			}
		}
};
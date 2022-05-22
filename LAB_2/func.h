#include <iostream>
#include <string>
#include <fstream>
#include <ctime>
#include <vector>
#pragma warning(disable : 4996)

using namespace std;

struct Car {
    char name[255];
    char release_date[255];
    char sell_date[255];
};

string enter_mode();
void creating_first_file(string, string);
void creating_second_file(string, string);
void read_cars(string);
void output_used_cars(string);
vector<string> split(string, char sep=' ');

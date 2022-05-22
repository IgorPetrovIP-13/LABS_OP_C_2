#include "Header.h"

int main()
{
    string first_path = "Allcars.bin";
    string second_path = "Recentcars.bin";
    string mode = enter_mode();
    creating_first_file(first_path, mode);
    creating_second_file(first_path, second_path);
    cout << "\nAll cars:\n";
    read_cars(first_path);
    cout << "\nRecent cars:\n";
    read_cars(second_path);
    cout << "\nUsed cars: \n";
    output_used_cars(first_path);
}
#include "func.h"

string enter_mode() {
    string file_mode;
    cout << "Enter 'w' to overwrite file or 'a' to append information to file: " << endl;
    cin >> file_mode;
    while (file_mode != "w" and file_mode != "a") {
        cout << "Incorrect input. Enter 'w' or 'a'.Enter 'w' to overwrite file or 'a' to append information to file : " << endl;
        cin >> file_mode;
    }
    return file_mode;
}


void creating_first_file(string path, string mode) {
    ofstream file;
    if (mode == "w") {
        file.open(path, ios::binary);
    }
    else {
        file.open(path, ios::binary | ios::app);
    }
    string line;
    cout << "Enter cars in format: name DD.MM.YYYY(release date) DD.MM.YYYY(sell date).\n"
        "To finish entering go to a new line and press <Ctrl + S>:\n";
    getline(cin, line);
    while (line[0] != char(19)) {
        if (line.length() > 0) {
            Car car;
            vector<string>splitted = split(line);
            string name;
            for (size_t i = 0; i < splitted.size() - 2; i++)
            {
                name += splitted[i] + ' ';
            }
            name.pop_back();
            strcpy_s(car.name, name.c_str());
            strcpy_s(car.release_date, splitted[splitted.size() - 2].c_str());
            strcpy_s(car.sell_date, splitted[splitted.size() - 1].c_str());
            file.write((char*)&car, sizeof(Car));
        }
        getline(cin, line);
    }
}

void creating_second_file(string first_path, string second_path) {
    ifstream first_file(first_path, ios::binary);
    if (first_file.is_open()) {
        ofstream second_file(second_path, ios::binary);
        if (second_file.is_open()) {
            Car car;
            time_t t = time(0);
            tm* now = localtime(&t);
            const int current_year = now->tm_year + 1900;
            const int current_month = now->tm_mon + 1;
            while (first_file.read((char*)&car, sizeof(Car))) {
                if (current_month == stoi(split(car.sell_date, '.')[1]) and current_year == stoi(split(car.sell_date, '.')[2])) {
                    second_file.write((char*)&car, sizeof(Car));
                }
            }
        }
        else {
            cerr << "Fatal error";
        }
        second_file.close();
    }
    else {
        cerr << "Fatal error";
    }
    first_file.close();
}

void read_cars(string path) {
    ifstream file(path, ios::binary);
    Car car;
    while (file.read((char*)&car, sizeof(Car))) {
        cout << "Name: " << car.name << ", release date: " << car.release_date << ", sell date: " << car.sell_date << endl;
    }
    file.close();
}

void output_used_cars(string file_path) {
    ifstream file(file_path, ios::binary);
    if (file.is_open()) {
        Car car;
        vector <Car> car_list;
        while (file.read((char*)&car, sizeof(Car))) {
            car_list.push_back(car);
        }
        int s_day, s_month, s_years, r_day, r_month, r_years, delta_year, delta_month, delta_day;
        string string_sell, string_release;
        for (size_t i = 0; i < car_list.size(); i++)
        {
            string_sell = string(car_list[i].sell_date);
            vector<string>splitted_sell = split(string_sell, '.');
            s_day = stoi(splitted_sell[0]);
            s_month = stoi(splitted_sell[1]);
            s_years = stoi(splitted_sell[2]);
            string_release = string(car_list[i].release_date);
            vector<string>splitted_release = split(string_release, '.');
            r_day = stoi(splitted_release[0]);
            r_month = stoi(splitted_release[1]);
            r_years = stoi(splitted_release[2]);
            delta_year = s_years - r_years;
            delta_month = s_month - r_month;
            delta_day = s_day - r_day;
            if (delta_year > 1 or (delta_year == 1 and delta_month > 0) or (delta_year == 1 and delta_month == 0 and delta_day > 0)) {
                cout << "Name: " << car_list[i].name << ", release date: " << car_list[i].release_date << ", sell date: " << car_list[i].sell_date << endl;
            }
        }
    }
    else {
        cout << "Fatal error";
    }
    file.close();
}

vector<string> split(string line, char sep) {
    vector<string> res;
    string slice = "";
    line += sep;
    for (int i = 0; i < int(line.length()); i++) {
        if (line[i] == sep) {
            if (slice.length() > 0) res.push_back(slice);
            slice = "";
        }
        else slice += line[i];
    }
    return res;
}

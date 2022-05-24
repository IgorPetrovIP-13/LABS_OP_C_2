#include "func.h"

Numeral_16::Numeral_16(int dec_num) {
    string temp;
    int temp_int;
    while (dec_num) {
        temp_int = dec_num % 16;
        if (temp_int < 10) temp += (char)(temp_int + 48);
        else temp += (char)(temp_int + 55);
        dec_num /= 16;
    }
    int length = temp.length();
    for (int i = temp.length() - 1; i >= 0; i--) {
        num_16 += temp[i];
    }
}

Numeral_16::Numeral_16(const string& hex_num) {
	this->num_16 = hex_num;
}

string Numeral_16::get_num_16() {
	return num_16;
}

Numeral_16 Numeral_16::operator ++() {
    int dec_num = stoi(num_16, nullptr, 16);
    this->num_16 = Numeral_16(++dec_num).num_16;
    return *this;
}

const Numeral_16 Numeral_16::operator +(const Numeral_16& obj) {
    return Numeral_16(stoi(num_16, nullptr, 16) + stoi(obj.num_16, nullptr, 16)).num_16;
}

const Numeral_16 Numeral_16::operator +=(const string& hex_num) {
    num_16 = Numeral_16(stoi(num_16, nullptr, 16) + stoi(hex_num, nullptr, 16)).num_16;
    return *this;
}

const Numeral_16 Numeral_16::operator +=(int dec_num) {
    num_16 = Numeral_16(stoi(num_16, nullptr, 16) + dec_num).num_16;
    return *this;
}

string Numeral_16::bin_short() {
    string bin_num;
    for (char c : num_16) {
        switch (c) {
        case '0':
            bin_num += "0000";
            break;
        case '1':
            bin_num += "0001";
            break;
        case '2':
            bin_num += "0010";
            break;
        case '3':
            bin_num += "0011";
            break;
        case '4':
            bin_num += "0100";
            break;
        case '5':
            bin_num += "0101";
            break;
        case '6':
            bin_num += "0110";
            break;
        case '7':
            bin_num += "0111";
            break;
        case '8':
            bin_num += "1000";
            break;
        case '9':
            bin_num += "1001";
            break;
        case 'A':
        case 'a':
            bin_num += "1010";
            break;
        case 'B':
        case 'b':
            bin_num += "1011";
            break;
        case 'C':
        case 'c':
            bin_num += "1100";
            break;
        case 'D':
        case 'd':
            bin_num += "1101";
            break;
        case 'E':
        case 'e':
            bin_num += "1110";
            break;
        case 'F':
        case 'f':
            bin_num += "1111";
            break;
        }
    }
    bin_num.erase(0, bin_num.find_first_not_of('0'));
    return bin_num;
}

string Numeral_16::bin_long() {
    int dec_num = stoi(num_16, nullptr, 16);
    string bin_num;
    string temp;
    int temp_int;
    while (dec_num) {
        temp_int = dec_num % 2;
        temp += (char)(temp_int + 48);
        dec_num /= 2;
    }
    for (int i = temp.length() - 1; i >= 0; i--) {
        bin_num += temp[i];
    }
    return bin_num;
}

string choose_mode() {
    string mode;
    cout << "Enter number format to add to N2.\n'h' for hex format or 'd' for decimal format: " ; cin >> mode;
    while (mode != "h" and mode != "d") {
        cout << "Incorrect input. Enter 'h' or 'd': ";  cin >> mode;
    }
    return mode;
}
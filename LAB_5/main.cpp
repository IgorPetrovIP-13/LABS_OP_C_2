#include "func.h"

int main() {
	int n;
	cout << "Number of quadrangles: "; cin >> n;
	double s_sum = 0, p_sum = 0;
    for (size_t i = 0; i < n; i++)
    {
        int choice = make_choice();
        cout << "Enter coordinates clockwise, starting with the left upper corner." << endl;
        vector<vector<int>>points = enter_points();
        cin.clear();
        if (choice == 1) {
            Parallelogram obj(points);
            p_sum += obj.get_p();
            cout << "P: " << obj.get_p() << endl;
            cout << "S: " << obj.get_s() << endl;
        }
        else if (choice == 2) {
            Rectangle obj(points);
            s_sum += obj.get_s();
            cout << "P: " << obj.get_p() << endl;
            cout << "S: " << obj.get_s() << endl;
        }
        else {
            Square obj(points);
            s_sum += obj.get_s();
            cout << "P: " << obj.get_p() << endl;
            cout << "S: " << obj.get_s() << endl;
        }
    }
    cout << "\nSum of P of all the parallelograms: " << p_sum << endl;
    cout << "Sum of S of all the squares and rectangles: " << s_sum << endl;
}
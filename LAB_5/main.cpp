#include "quadrangle.h"
#include "func.h"

int main() {
    int n;
    cout << "Number of quadrangles: "; cin >> n;
    double s_sum = 0, p_sum = 0;
    vector <TQuadrangle*> quadrangles;
    for (size_t i = 0; i < n; i++)
    {
        int choice = make_choice();
        cout <<"Quadrangle #" << i+1 << "\nEnter coordinates clockwise, starting with the left upper corner." << endl;
        vector<vector<int>>points = enter_points();
        if (choice == 1) {
            Parallelogram obj(points);
            if (obj.check_quadrangle()) {
                p_sum += obj.get_p();
            }
            quadrangles.push_back(new Parallelogram(points));
        }
        else if (choice == 2) {
            Rectangle obj(points);
            if (obj.check_quadrangle()) {
                s_sum += obj.get_s();
            }
            quadrangles.push_back(new Rectangle(points));
        }
        else {
            Square obj(points);
            if (obj.check_quadrangle()) {
                s_sum += obj.get_s();
            }
            quadrangles.push_back(new Square(points));
        }
    }
    for (size_t i = 0; i < n; i++)
    {
        cout << "\nQuadrangle #" << i + 1 << endl;
        if (quadrangles[i]->check_quadrangle()) {
            cout << "P: " << quadrangles[i]->get_p() << "\nS: " << quadrangles[i]->get_s() << endl;
        }
        else {
            cout << "Quadrangle doesn't exist" << endl;
        }
    }
    cout << "\nSum of P of all the parallelograms: " << p_sum << endl;
    cout << "Sum of S of all the squares and rectangles: " << s_sum << endl;
}
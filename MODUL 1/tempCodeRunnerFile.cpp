#include <iostream>
using namespace std;

int main() {
    int bilanganbulat;
    cout << "inputan: ";
    cin >> bilanganbulat;

    for (int i = 0; i <= bilanganbulat; i++) { 
    
        for (int j = 0; j < i; j++) {
            cout << "  ";
        }
        int input = bilanganbulat - i;
        for (int k = input; k >= 1; k--) {
            cout << k << " ";
        }
        cout << "* ";
        for (int k = 1; k <= input; k++) {
            cout << k << " ";
        }

        cout << endl;
    }

    return 0;
}

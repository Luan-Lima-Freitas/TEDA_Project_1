#include <iostream>
#include <limits>

using namespace std;

struct Vector
{
    int length;
    float values[];

    ~Vector(){}

    void set_length()
    {
        cout << "Input length: ";
        cin >> length;
        while(cin.fail() || length < 1)
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Length must be positive integer." << endl;
            cout << "Input length: ";
            cin >> length;
        }
    }

    void set_values()
    {
        int i;
        for(i = 0; i < length; i++)
        {
            cout << "Input value " << i+1 << " : ";
            cin >> values[i];
            while(cin.fail())
            {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Value must be float." << endl;
                cout << "Input value " << i+1 << " : ";
                cin >> values[i];
        }
        }
    }

    void print()
    {
        cout << "(" << values[0];
        int i;
        for(i = 1; i < length; i++)
        {
            cout << ", " << values[i];
        }
        cout << ")";
    }
};

int main()
{
    Vector m[10];

    m[0].set_length();
    m[0].set_values();
    m[0].print();

    cout << "\n";

    m[1].set_length();
    m[1].set_values();
    m[1].print();

    cout << "\n";

    cout << "m[0] = "; m[0].print(); cout << "\n";
    cout << "m[1] = "; m[1].print(); cout << "\n";

    m[2].set_length();
    m[2].set_values();
    m[2].print();

    cout << "\n";

    cout << "m[0] = "; m[0].print(); cout << "\n";
    cout << "m[1] = "; m[1].print(); cout << "\n";
    cout << "m[2] = "; m[2].print(); cout << "\n";
    return 0;
}

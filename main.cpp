#include <iostream>
#include <limits>

using namespace std;

struct Vector
{
    int length;
    float values[];

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
        cout << ")" << endl;
    }
};

int main()
{
    Vector v;
    v.set_length();
    v.set_values();
    v.print();

    int x = 0;

    return 0;
}

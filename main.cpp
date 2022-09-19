#include <iostream>
#include <limits>
#include <cmath>

using namespace std;

struct Vector
{
    int length;
    float values[100];

    ~Vector(){}

    void set_length()
    {
        cout << "Enter length: ";
        cin >> length;
        while(cin.fail() || length < 1 || length > 100)
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Length must be positive integer lesser or equal to 100." << endl;
            cout << "Enter length: ";
            cin >> length;
        }
    }

    void set_values()
    {
        int i;
        for(i = 0; i < length; i++)
        {
            cout << "Enter value " << i+1 << ": ";
            cin >> values[i];
            while(cin.fail())
            {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Value must be float." << endl;
                cout << "Enter value " << i+1 << " : ";
                cin >> values[i];
        }
        }
    }

    void display()
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

Vector Memory[100];
int num_vectors;

void menu_text(void)
{
    cout << "1 - Enter new vector" << endl;
    cout << "2 - Display all vectors" << endl;
    cout << "3 - Operate vectors" << endl;
    cout << "4 - Exit" << endl;
    cout << "\n";
    cout << "Enter option: ";
}

void option_1(void)
{
    Memory[num_vectors].set_length();
    Memory[num_vectors].set_values();
    cout << "\n";
    num_vectors++;
}

void option_2(void)
{
    int i;
    for(i = 0; i < num_vectors; i++)
    {
        cout << "#" << i << ": ";
        Memory[i].display();
        cout << "\n";
    }
    cout << "\n";
}

void option_3_text(void)
{
    cout << "\n";
    cout << "1 - Multiply vector by scalar" << endl;
    cout << "2 - Sum two vectors" << endl;
    cout << "3 - Compute linear combination between two vectors" << endl;
    cout << "4 - Compute dot product between two vectors" << endl;
    cout << "5 - Compute vector norm" << endl;
    cout << "6 - Verify linear dependency" << endl;
    cout << "7 - Return to menu" << endl;
    cout << "\n";
    cout << "Enter option: ";
}

int get_id(string text)
{
    int id;
    cout << text;
    cin >> id;
    while(cin.fail() || id < 0 || id >= num_vectors)
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "# must be non-negative integer lesser than " << num_vectors << "." << endl;
        cout << text;
        cin >> id;
    }
    return id;
}

float get_scalar(string text)
{
    float scalar;
    cout << text;
    cin >> scalar;
    while(cin.fail())
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Scalar must be float." << endl;
        cout << text;
        cin >> scalar;
    }
    return scalar;
}

Vector multiply_by_scalar(float a, Vector x)
{
    Vector y;
    y.length = x.length;
    int i;
    for(i = 0; i < x.length; i++)
    {
        y.values[i] = a*x.values[i];
    }
    return y;
}

Vector sum(Vector x, Vector y)
{
    Vector z;
    z.length = x.length;
    int i;
    for(i = 0; i < x.length; i++)
    {
        z.values[i] = x.values[i] + y.values[i];
    }
    return z;
}

float dot_product(Vector x, Vector y)
{
    float sum = 0;
    int i;
    for(i = 0; i < x.length; i++)
    {
        sum = sum + x.values[i]*y.values[i];
    }
    return sum;
}

void operation_1(void)
{
    int id = get_id("Enter vector #: ");
    float scalar = get_scalar("Enter scalar: ");

    Memory[num_vectors] = multiply_by_scalar(scalar, Memory[id]);
    cout << "Result: "; Memory[num_vectors].display(); cout << "\n";
    num_vectors++;
}

void operation_2(void)
{
    int id_1 = get_id("Enter 1st vector #: ");
    int id_2 = get_id("Enter 2nd vector #: ");

    if(Memory[id_1].length != Memory[id_2].length)
    {
        cout << "Vectors must have the same length." << endl;
    }
    else
    {
        Memory[num_vectors] = sum(Memory[id_1], Memory[id_2]);
        cout << "Result: "; Memory[num_vectors].display(); cout << "\n";
        num_vectors++;
    }
}

void operation_3(void)
{
    int id_1 = get_id("Enter 1st vector #: ");
    float a = get_scalar("Enter 1st coefficient: ");
    int id_2 = get_id("Enter 2nd vector #: ");
    float b = get_scalar("Enter 2nd coefficient: ");

    if(Memory[id_1].length != Memory[id_2].length)
    {
        cout << "Vectors must have the same length." << endl;
    }
    else
    {
        Memory[num_vectors] = sum(multiply_by_scalar(a, Memory[id_1]), multiply_by_scalar(b, Memory[id_2]));
        cout << "Result: "; Memory[num_vectors].display(); cout << "\n";
        num_vectors++;
    }
}

void operation_4(void)
{
    int id_1 = get_id("Enter 1st vector #: ");
    int id_2 = get_id("Enter 2nd vector #: ");

    if(Memory[id_1].length != Memory[id_2].length)
    {
        cout << "Vectors must have the same length." << endl;
    }
    else
    {
        cout << "Result: " << dot_product(Memory[id_1], Memory[id_2]) << endl;
    }
}

void operation_5(void)
{
    int id = get_id("Enter vector #: ");

    cout << "Result: " << sqrt(dot_product(Memory[id], Memory[id])) << endl;
}

void operation_6(void)
{
    int id_1 = get_id("Enter 1st vector #: ");
    int id_2 = get_id("Enter 2nd vector #: ");

    if(Memory[id_1].length != Memory[id_2].length)
    {
        cout << "Vectors must have the same length." << endl;
    }
    else
    {
        float coefs[Memory[id_1].length];
        int num_coefs = 0;

        int i;
        for(i = 0; i < Memory[id_1].length; i++)
        {
            if(Memory[id_2].values[i] != 0)
            {
                coefs[num_coefs] = Memory[id_1].values[i]/Memory[id_2].values[i];
                num_coefs++;
            }
            else if(Memory[id_1].values[i] != 0)
            {
                coefs[num_coefs] = 0;
                num_coefs++;
            }
        }

        bool ld = 1;

        if(num_coefs > 1)
        {
            int j;
            for(j = 1; j < num_coefs; j++)
            {
                if(coefs[j] != coefs[0])
                {
                    ld = 0;
                    break;
                }
            }
        }

        if(ld)
        {
            cout << "Vectors are linearly dependent." << endl;
        }
        else
        {
            cout << "Vectors are linearly independent." << endl;
        }
    }
}

void option_3(void)
{
    char operation;
    bool done = 0;
    do
    {
        option_3_text();
        cin >> operation;
        switch(operation)
        {
            case '1': operation_1(); done = 1; break;
            case '2': operation_2(); done = 1; break;
            case '3': operation_3(); done = 1; break;
            case '4': operation_4(); done = 1; break;
            case '5': operation_5(); done = 1; break;
            case '6': operation_6(); done = 1; break;
            case '7': done = 1; break;
            default: cout << "Invalid option." << endl;
        }
    }
    while(!done);
    cout << "\n";
}

void menu(void)
{
    char option;
    do
    {
        menu_text();
        cin >> option;
        switch(option)
        {
            case '1': option_1(); break;
            case '2': option_2(); break;
            case '3': option_3(); break;
            case '4': break;
            default: cout << "Invalid option." << endl; cout << "\n";
        }
    }
    while(option != '4');
}

int main()
{
    num_vectors = 0;
    menu();

    return 0;
}

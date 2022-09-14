#include <iostream>
#include <limits>

using namespace std;

float values[]; // There might be an arbitrary number of values!
int heads[100];
int num_vectors = 2;

void print_vector(int i)
{
    cout << "(" << values[heads[i]];
    int j;
    for(j = heads[i]+1; j < heads[i+1]; j++)
    {
        cout << ", " << values[j];
    }
    cout << ")";
}
void print_all_vectors()
{
    int i;
    for(i = 0; i < num_vectors; i++)
    {
        print_vector(i);
        cout << "\n";
    }
}

int main()
{
    heads[0] = 0;
    heads[1] = 2;
    heads[2] = 8;

    int i;
    for(i = 0; i < heads[2]; i++)
    {
        values[i] = 2*i;
    }

    print_all_vectors();

    return 0;
}

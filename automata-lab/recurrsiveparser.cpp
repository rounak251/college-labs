#include <iostream>
#include <string>
using namespace std;

string input;
int i = 0;

// Function declarations
void E();
void Edash();
void T();
void Tdash();
void F();

void error()
{
    cout << "Parsing Failed: ERROR\n";
    exit(0);
}

// E → T E'
void E()
{
    T();
    Edash();
}

// E' → + T E' | ε
void Edash()
{
    if (input[i] == '+')
    {
        i++;
        T();
        Edash();
    }
}

// T → F T'
void T()
{
    F();
    Tdash();
}

// T' → * F T' | ε
void Tdash()
{
    if (input[i] == '*')
    {
        i++;
        F();
        Tdash();
    }
}

// F → (E) | id
void F()
{
    if (input.substr(i,2) == "id")
    {
        i += 2;
    }
    else if (input[i] == '(')
    {
        i++;
        E();

        if (input[i] == ')')
        {
            i++;
        }
        else
        {
            error();
        }
    }
    else
    {
        error();
    }
}

int main()
{
    cout << "Enter the input string: ";
    cin >> input;

    E();

    if (input[i] == '$')
        cout << "Successfully Parsed\n";
    else
        cout << "Parsing Failed\n";

    return 0;
}
#include <iostream>

using namespace std;

int main()
{
    char c;
    while(1)
    {
        cin.get(c);
        if(cin.fail()) break;
        switch (c)
        {
            case '=':
                cout.put('0');
                break;
            case '-':
                cout.put('9');
                break;
            case '0':
                cout.put('8');
                break;
            case '9':
                cout.put('7');
                break;
            case '8':
                cout.put('6');
                break;
            case '7':
                cout.put('5');
                break;
            case '6':
                cout.put('4');
                break;
            case '5':
                cout.put('3');
                break;
            case '4':
                cout.put('2');
                break;
            case '3':
                cout.put('1');
                break;
            case '2':
                cout.put('`');
                break;
            case '\\':
                cout.put('[');
                break;
            case ']':
                cout.put('p');
                break;
            case '[':
                cout.put('o');
                break;
            case 'p':
                cout.put('i');
                break;
            case 'o':
                cout.put('u');
                break;
            case 'i':
                cout.put('y');
                break;
            case 'u':
                cout.put('t');
                break;
            case 'y':
                cout.put('r');
                break;
            case 't':
                cout.put('e');
                break;
            case 'r':
                cout.put('w');
                break;
            case 'e':
                cout.put('q');
                break;
            case '\'':
                cout.put('l');
                break;
            case ';':
                cout.put('k');
                break;
            case 'l':
                cout.put('j');
                break;
            case 'k':
                cout.put('h');
                break;
            case 'j':
                cout.put('g');
                break;
            case 'h':
                cout.put('f');
                break;
            case 'g':
                cout.put('d');
                break;
            case 'f':
                cout.put('s');
                break;
            case 'd':
                cout.put('a');
                break;
            case '/':
                cout.put(',');
                break;
            case '.':
                cout.put('m');
                break;
            case ',':
                cout.put('n');
                break;
            case 'm':
                cout.put('b');
                break;
            case 'n':
                cout.put('v');
                break;
            case 'b':
                cout.put('c');
                break;
            case 'v':
                cout.put('x');
                break;
            case 'c':
                cout.put('z');
                break;
            default:
                cout.put(c);
                break;
        }
    }
    return 0;
}
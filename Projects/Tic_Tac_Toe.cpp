/*
 * Author : Mohit Radadiya
 *
 */

#include<bits/stdc++.h>
using namespace std;
char a[10] = {'o','1','2','3','4','5','6','7','8','9'};

int iswin()
{
    if (a[1] == a[2] && a[2] == a[3])return 1;
    else if (a[4] == a[5] && a[5] == a[6])return 1;
    else if (a[7] == a[8] && a[8] == a[9])return 1;
    else if (a[1] == a[4] && a[4] == a[7])return 1;
    else if (a[2] == a[5] && a[5] == a[8])return 1;
    else if (a[3] == a[6] && a[6] == a[9])return 1;
    else if (a[1] == a[5] && a[5] == a[9])return 1;
    else if (a[3] == a[5] && a[5] == a[7])return 1;
    else if (a[1] != '1' && a[2] != '2' && a[3] != '3' && a[4] != '4' && a[5] != '5' && a[6] != '6' && a[7] != '7' && a[8] != '8' && a[9] != '9') return 0;
    else return -1;
}

void design_board()
{
    system("cls");
    cout << "\n\n\tTic Tac Toe\n\n";
    cout << "p 1 (X)  -  p 2 (O)" << "\n" << "\n";
    cout << "\n";
    cout << "     |     |     " << "\n";
    cout << "  " << a[1] << "  |  " << a[2] << "  |  " << a[3] << "\n";
    cout << "_ _ _|_ _ _|_ _ _" << "\n";
    cout << "     |     |     " << "\n";
    cout << "  " << a[4] << "  |  " << a[5] << "  |  " << a[6] << "\n";
    cout << "_ _ _|_ _ _|_ _ _" << "\n";
    cout << "     |     |     " << "\n";
    cout << "  " << a[7] << "  |  " << a[8] << "  |  " << a[9] << "\n";
    cout << "     |     |     " << "\n" << "\n";
}

int main()
{
	int p = 1,i,choice;
    char mark;
    do
    {
        design_board();
        p=(p%2)?1:2;

        cout << "p " << p << ", enter a number:  ";
        cin >> choice;

        mark=(p == 1) ? 'X' : 'O';

        if (choice == 1 && a[1] == '1')a[1] = mark;
        else if (choice == 2 && a[2] == '2')a[2] = mark;
        else if (choice == 3 && a[3] == '3')a[3] = mark;
        else if (choice == 4 && a[4] == '4')a[4] = mark;
        else if (choice == 5 && a[5] == '5')a[5] = mark;
        else if (choice == 6 && a[6] == '6')a[6] = mark;
        else if (choice == 7 && a[7] == '7')a[7] = mark;
        else if (choice == 8 && a[8] == '8')a[8] = mark;
        else if (choice == 9 && a[9] == '9')a[9] = mark;
        else
        {
            cout<<"Invalid move\n"; p--; cin.ignore(); cin.get();
        }
        i=iswin(); p++;
    }while(i==-1);
    design_board();
    if(i==1)cout<<"\aBravo! player "<<--p<<" win ";
    else cout<<"\aHurayy! Game draw";

    cin.ignore();
    cin.get();
    return 0;
}

/*
 Output:
 
         Tic Tac Toe

p 1 (X)  -  p 2 (O)


     |     |
  X  |  X  |  X
_ _ _|_ _ _|_ _ _
     |     |
  4  |  5  |  O
_ _ _|_ _ _|_ _ _
     |     |
  7  |  8  |  O
     |     |

Bravo! player 1 win
*/

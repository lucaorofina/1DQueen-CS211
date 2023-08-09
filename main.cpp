#include <iostream>
using namespace std;



int main() {

    int sol_num = 1; // add counter

    int q[8][8] = {}; // create the chessboard

    int r = 0, c = 0;

    q[r][c] = 1; // we start coding with placing 1st queen at [0][0]

nc:

    c++;


    if (c == 8) goto print; // achieve 1 solution, need to print it out
    r = -1; // question: why -1 here?

nr:

    r++;

    if (r == 8) goto backtrack; // backtrack

     for (int i = 0; i < c; i++){// for-loop, check the same row

        if (q[r][i] == 1) goto nr;
     }

    for(int i = 0;(r + i < 8) && (c - i >= 0); i++){ // for-loop, check upper diag

        if(q[r - i][c - i] == 0) goto nr;
    }

    for(int i = 0;(r + i < 8) && (c - i >= 0); i++){ // for-loop, check the down diag
/* is this better?:  for (int i = 1; ((r-i)>=0 && (c-i)>=0); i++){ */
        if(q[r + i][c - i] == -1) goto nr; 
    }
            q[r][c] = 1;

            goto nr;

}

    q[r][c] = 1; // pass the tests, place a queen

    goto nc; // jump to nc

backtrack:

    c--;

    if (c < 0) return 0; // end up the program

    /* r = 0;*/
    while(q[r][c] != 1) r++; // find last queen position and remove, next row= r++

    q[r][c] = 0;

    goto nr;

print:

    cout << "Solution #: " << sol_num++ << endl;

    for (int i = 0; i < 8; i++) {

      for (int j = 0; j < 8; j++){ // for-loop to print a solution

        cout << q[i][j] << " ";

        }

    cout << endl;

        }
    cout << endl;
    goto backtrack; // backtrack to look for next solution

}


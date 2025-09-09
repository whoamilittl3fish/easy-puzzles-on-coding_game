#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    cin >> n; cin.ignore();
    int l;
    cin >> l; cin.ignore();

    //input the array
    string cell[n][n];
    int i,j, x, y;
    for (i=0; i < n; i++) {
        for (j=0; j < n; j++) {
            cin >> cell[i][j]; cin.ignore();
        }
    }



    // for (i=0;i<n;i++)
    //     for (j=0;j<n;j++){
    //         if (cell[i][j] == "C")
    //         cout << i << " " << j << endl;
    // }
    // out put the postion of C

    // for (i=0;i<n;i++)
    //     for (j=0;j<n;j++){
    //         if (cell[i][j] == "C")
    //         for (x=i;x<(l+i);x++){
    //             for (y=j;y<(l+i);y++){
    //                 cell[x][y] = "L";
    //             }
    //         }
    // }


    // x = rows
    // y = columns

    // Set light to L
    for (i=0;i<n;i++)
        for (j=0;j<n;j++){
            if (cell[i][j] == "C")
            {
                  // Scan light to Right and Down
                for (x=i;(x<(i+l)&&x<n)&&x>=0;x++){
                    for (y=j;(y<(j+l)&&y<n)&&y>=0;y++){
                        if (cell[x][y] != "C" && cell[x][y] != "L")
                            cell[x][y] = "L";
                }
            }

                // Scan light to Right and Up
                for (x=i;(x>(i-l)&&x<n)&&x>=0;x--){
                    for (y=j;(y<(j+l)&&y<n)&&y>=0;y++){
                        if (cell[x][y] != "C" && cell[x][y] != "L")
                            cell[x][y] = "L";
                    }
                }

                // Scan light to Left and Down
                for (x=i;(x<(i+l)&&x<n)&&x>=0;x++){
                    for (y=j;(y>(j-l)&&y<n)&&y>=0;y--){
                        if (cell[x][y] != "C" && cell[x][y] != "L")
                            cell[x][y] = "L";
                    }
                }

                // Scan light to Left and Up
                for (x=i;(x>(i-l)&&x<n)&&x>=0;x--){
                    for (y=j;(y>(j-l)&&y<n)&&y>=0;y--){
                        if (cell[x][y] != "C" && cell[x][y] != "L")
                            cell[x][y] = "L";
                    }
                }
            }
            
    }
    
    //output the array
    cout << endl;
    for (i=0; i < n; i++) {
        for (j=0; j < n; j++) {
            cout << cell[i][j] << " ";
        }
        cout << endl;
    }

    // output the number of dark cells
    int sum_dark =0;
    for (i=0; i < n; i++) {
        for (j=0; j < n; j++) {
            if (cell[i][j] == "X")
                sum_dark += 1;
        }
    }
    cout << sum_dark << endl;


    // out put C to 4
}
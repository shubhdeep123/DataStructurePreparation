#include <iostream>
using namespace std;

int goldmine(int **input, int n, int m) {
    int **output = new int *[n];
    for (int i = 0; i < n; i++) {
        output[i] = new int[m];
    }

    //outer loop is for column and inner is for rows
    for (int j = m - 1; j >= 0; j--) {
        for (int i = n - 1; i >= 0;i--) {
            if (j==m-1) {
                output[i][j] = input[i][j];
            }
            else if (i == 0)
            {
                output[i][j] = input[i][j] + max(output[i + 1][j + 1], output[i][j + 1]);
            }
            else if (i == n - 1)
            {
                output[i][j] = input[i][j] + max(output[i][j + 1], output[i - 1][j + 1]);
            }
            else
            {
                output[i][j] = input[i][j] + max(output[i][j + 1], max(output[i - 1][j + 1], output[i + 1][j + 1]));
            }
        }
    }

    int max = output[0][0];
    for (int i = 1; i < n;i++) {
        if (output[i][0] > max) {
            max = output[i][0];
        }
    }

    for (int i = 0; i < n; i++) {
        delete[] output[i];
    }

    delete[] output;

    return max;
}

int main() {
    int n, m;
    cin >> n >> m;
    int **input = new int*[n];
    for (int i = 0; i < n; i++) {
        input[i] = new int[m];
        for (int j = 0; j < m; j++)
        {
            cin >> input[i][j];
        }
    }

    cout << goldmine(input, n, m) << endl;
}
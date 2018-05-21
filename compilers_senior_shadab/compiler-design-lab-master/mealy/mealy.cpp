#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;
#define MAX_ROWS 5
#define MAX_COLS 5
#define INPUT_FILE "input.txt"
/*
INPUT FILE FORMAT:
1/0 0/1
1/1 0/0
*/
int  state_matrix[MAX_ROWS][MAX_COLS];
int output_matrix[MAX_ROWS][MAX_COLS];

void print_arr(int arr[], int size) {
    for (int i = 0; i < size; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
} //print array function

void print_matrix(int mat[][MAX_COLS], int rows, int cols) {
    for (int i = 0; i < rows; ++i) {
        print_arr(mat[i], cols);
    }
    cout << endl;
} // print matrix function

void read_file() {
    ifstream file(INPUT_FILE);
    if (!file.is_open()) 
	{
        cerr << "Couldn't open input file: " << INPUT_FILE;
    }
    string line;
    int i = 0,m=0,n=0;
    while (getline(file, line)) {

        string cell; // Cell->'state/output'
        istringstream line_stream(line);
        int j = 0;
        while(getline(line_stream, cell, ' ')) {
             state_matrix[i][j] = cell[0] - 48; //convert into int then store
            output_matrix[i][j] = cell[2] - 48;
            j++;
        }
        for(m=0;m<i;m++)
        {
        	for(n=0;n<j;n++)
			{
				cout<<state_matrix[m][n];
			}
	} // print state matrix
	cout<<"\n";
		for(m=0;m<i;m++)
        {
        	for(n=0;n<j;n++)
			{
				cout<<output_matrix[m][n];
			}
	} 
	cout<<"\n";// print output matrix
        i++;
    }
} // Read file and fill matrices

int main(int argc, char const *argv[])
{
    read_file();

    // Initial State
    int cur_state = 0;

    // Current Output
    int cur_output = 0;

    // Input String
    string input;

    cout << "Enter input string: ";
    cin >> input;
    cout << endl;

    // Header
    cout << "Output: " << endl << endl;
    cout << "S - O" << endl;
    cout << "-----" << endl;

    int length = input.length();
    for (int i = 0; i < length; ++i)
    {
        // Convert char '1'/'0' to int 1/0
        int cur_input = int(input[i]) - 48;

        cur_state = state_matrix[cur_state][cur_input];
        cur_output = output_matrix[cur_state][cur_input];

        cout << cur_state << " - " << cur_output << endl;
    }

    return 0;
}

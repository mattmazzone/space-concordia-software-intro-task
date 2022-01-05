#include <iostream>
#include <fstream>
#include <set>

// Check for duplicates in row
bool notInRow(int arr[][9], int row) {
    // Set to store integers
    std::set<int> encountered;

    for (int i = 0; i < 9; i++) {
        // If duplicate, return false
        if (encountered.find(arr[row][i]) != encountered.end())
            return false;
        // If cell is not empty, add to set
        if (arr[row][i] != 0)
            encountered.insert(arr[row][i]);
    }
    return true;
}

//Check for duplicates in row
bool notInCol(int arr[][9], int col) {
    // Set to store integers
    std::set<int> encountered;

    for (int i = 0; i < 9; i++) {

        // If duplicate, return false
        if (encountered.find(arr[i][col]) != encountered.end())
            return false;
        // If cell is not empty, add to set
        if (arr[i][col] != 0)
            encountered.insert(arr[i][col]);
    }
    return true;
}

//Check for duplicates in grid (3x3)
bool notInGrid(int arr[][9], int startRow, int startCol) {
    std::set<int> encountered;

    for (int row = 0; row < 3; row++) {
        for (int col = 0; col < 3; col++) {
            char curr = arr[row + startRow][col + startCol];

            // If duplicate, return false
            if (encountered.find(curr) != encountered.end())
                return false;
            // If cell is not empty, add to set
            if (curr != 0)
                encountered.insert(curr);
        }
    }
    return true;
}

// Runs all tests to check for valid board
bool isValid(int arr[][9], int row, int col) {
    return notInRow(arr, row) && notInCol(arr, col) &&
           notInGrid(arr, row - row % 3, col - col % 3);
}

// Pass row and col to isValid()
bool isValidConfig(int arr[][9]) {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {

            if (!isValid(arr, i, j))
                return false;
        }
    }
    return true;
}

int main() {
    int board[9][9];

    std::ifstream myFile;
    myFile.open("sample-board.txt");
    std::string myLine;
    int lineCounter = 0;

    if (myFile.is_open()) {
        while (myFile) {
            std::getline(myFile, myLine);

            for (int i = 0; i < 9; i++) {
                char individualChar;
                individualChar = myLine[i];

                int individualNumber = individualChar - '0';

                if (lineCounter < 9) {
                    board[i][lineCounter] = individualNumber;
                }
            }
            lineCounter++;

        }
    } else {
        std::cout << "Couldn't open file\n";
        return 0;
    }

    //Print stored board
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            std::cout << board[j][i];
        }
        std::cout << "\n";
    }


    std::cout << (isValidConfig(board) ? "The board is valid\n" : "The board is not valid\n");

    return 0;
}



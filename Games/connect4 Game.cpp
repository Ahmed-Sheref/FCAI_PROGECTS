//  File: connect 4
//  Purpose: Connect4 is a two-player connection game where players first choose a square and then take turns dropping colored discs from the top into seven columns.
//  Author: Ahmed Sheref Sayed
//  ID: 20230542
// version (1.0)
// Date\ 29 Feb.2024

#include "iostream"
#include "vector"
#include "string"
#include "algorithm"

using namespace std;

// Function to print the game board
void Print_Game(string list[6][7])
{
    // Loop through each row and column of the game board
    for (int i = 0; i < 6; ++i)
    {
      for (int j = 0; j < 7; ++j)
          cout << "| " << list[i][j] << " |";
      cout << "\n"; // Move to the next row after printing each row
    }
}

// Function to validate user input for column selection
int valid_input(string column)
{
  string Chek_input = column;

  // Check if the input contains non-digit characters
  for (int ch : Chek_input)
  {
      if (isdigit(ch) == false)
      {
          cout << "Please enter a valid number (1_7)\n";
          cin >> Chek_input;
          return valid_input(Chek_input); // Recursively call valid_input until a valid number is entered
      }
  }

  int valid_number = stoi(Chek_input); // Convert the validated string to an integer

  // Validate the column number entered by the user
  while (true)
  {
      if (stoi(column) > 7 || stoi(column) < 1)
      {
          cout << "Please enter a valid number (1_7)\n";
          cin >> valid_number;
          return valid_input(to_string(valid_number)); // Recursively call valid_input with the corrected input
      }
      else
          break; // Exit the loop if the input is valid
  }

    return valid_number; // Return the valid column number
}

// Function to check if a player has won by forming a sequence of 4 pieces in a column
bool Chek_winner_coulm(string list[6][7], string Player, int Player_role)
{
    int result = 0; // Variable to count consecutive pieces
    for (int i = 0; i < 7; ++i)
    {
        result = 0; // Reset the count for each column
        for (int j = 0; j < 6; ++j)
        {
            if (list[j][i] == Player) // Check if the current cell contains the player's piece
            {
                result = result + 1; // Increment the count
                if (result == 4) // Check if there are 4 consecutive pieces
                {
                    cout << "Player: " << Player_role << " won by column";
                    return true; // Return true if the player wins
                }
            }
            else
                result = 0; // Reset the count if the sequence is interrupted
        }
    }
    return false; // Return false if no winning sequence is found
}

// Function to check if a player has won by forming a sequence of 4 pieces in a row
bool Chek_winner_row(string list[6][7], string Player, int Player_role)
{
    int result = 0; // Variable to count consecutive pieces
    for (int i = 0; i < 6; ++i)
    {
        result = 0; // Reset the count for each row
        for (int j = 0; j < 7; ++j)
        {
            if (list[i][j] == Player) // Check if the current cell contains the player's piece
            {
                result = result + 1; // Increment the count
                if (result == 4) // Check if there are 4 consecutive pieces
                {
                    cout << "Player: " << Player_role << " won by row";
                    return true; // Return true if the player wins
                }
            }
            else
                result = 0; // Reset the count if the sequence is interrupted
        }
    }
    return false; // Return false if no winning sequence is found
}

// Function to check if a player has won by forming a sequence of 4 pieces diagonally (right)
bool Chek_winner_Diagonal_rigth(string list[6][7], string Player, int Player_role)
{
    int result = 0; // Variable to count consecutive pieces
    int Plus_index = 0; // Variable to adjust row index while moving diagonally
    for (int i = 0; i < 6; ++i)
    {
        Plus_index = 0; // Reset the adjustment index for each row
        result = 0; // Reset the count for each row
        for (int j = 0; j < 7; ++j)
        {
            if (list[i - Plus_index][j] == Player) // Check if the current cell contains the player's piece
            {
                result = result + 1; // Increment the count
                Plus_index++; // Adjust the row index for diagonal movement
                if (result == 4) // Check if there are 4 consecutive pieces
                {
                    cout << "Player: " << Player_role << " won by Diagonal_right";
                    return true; // Return true if the player wins
                }
            }
            else
                result = 0; // Reset the count if the sequence is interrupted
        }
    }
    return false; // Return false if no winning sequence is found
}

// Function to check if a player has won by forming a sequence of 4 pieces diagonally (left)
bool Chek_winner_Diagonal_left(string list[6][7], string Player, int Player_role)
{
    int result = 0; // Variable to count consecutive pieces
    int Plus_index = 0; // Variable to adjust row index while moving diagonally
    for (int i = 0; i < 6; ++i)
    {
        Plus_index = 0; // Reset the adjustment index for each row
        result = 0; // Reset the count for each row
        for (int j = 0; j < 7; ++j)
        {
            if (list[i + Plus_index][j] == Player) // Check if the current cell contains the player's piece
            {
                result = result + 1; // Increment the count
                Plus_index++; // Adjust the row index for diagonal movement
                if (result == 4) // Check if there are 4 consecutive pieces
                {
                    cout << "Player: " << Player_role << " won by Diagonal_left";
                    return true; // Return true if the player wins
                }
            }
            else
                result = 0; // Reset the count if the sequence is interrupted
        }
    }
    return false; // Return false if no winning sequence is found
}

// Function to assign a player's piece to a specific column
void assign_level(string list[6][7], int Player_role)
{
  while (true)
  {
    int main_column = 5, column;
    string answer, test_column;
    cout << "Player: " << Player_role << " column is: ";
    cin >> test_column;
    column = valid_input(test_column); // Validate the user's column input
    while (true)
    {
      while (main_column < 0) // Chek if input out of range of column (1-7)
      {
        main_column = 5;
        cout << "Out of Range, enter valid number: \n";
        cout << "Player: " << Player_role << " coulm is: "; cin >> test_column;
        column = valid_input(test_column);
      }
      // Check if the selected column is not full
      if (list[main_column][column - 1] != "#")
          main_column--;
      else
      {
          list[main_column][column - 1] = (Player_role == 1 ? "X" : "O"); // Assign the player's piece to the selected column
          return;
      }
    }
  }
}

int main()
{
    cout << "\n*** Hello To connect 4 *** \n";
    cout << "### Player1 => \"X\"\n";
    cout << "### Player2 => \"O\"\n";
    string list[6][7];

    // Initialize the game board with empty cells
    for (int i = 0; i < 6; ++i)
    {
        for (int j = 0; j < 7; ++j)
            list[i][j] = "#";
    }

    Print_Game(list); // Print the initial game board

    int column, result = 0;
    char answer;

    while (true)
    {
        assign_level(list, 1); // Player 1's turn
        Print_Game(list);
        if (Chek_winner_Diagonal_left(list, "X", 1) || Chek_winner_Diagonal_rigth(list, "X", 1) || Chek_winner_coulm(list, "X", 1) || Chek_winner_row(list, "X", 1))
            return 0; // Check if Player 1 has won
        assign_level(list, 2); // Player 2's turn
        Print_Game(list);
        if (Chek_winner_Diagonal_left(list, "O", 2) || Chek_winner_Diagonal_rigth(list, "O", 2) || Chek_winner_coulm(list, "O", 2) || Chek_winner_row(list, "O", 2))
            return 0; // Check if Player 2 has won

        // Check if the game ended in a draw
        result = 0;
        for (int i = 0; i < 6; ++i)
        {
            for (int j = 0; j < 7; ++j)
            {
                if (list[i][j] != "#")
                    result += 1; // Count the number of filled cells
                if (result == 42) // If all cells are filled and no winner is determined
                {
                    cout << "*** Draw ***\n";
                    return 0;
                }
            }
        }
    }

    return 0;
}
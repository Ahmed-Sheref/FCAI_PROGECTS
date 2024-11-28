#include <iostream>
#include <vector>
#include <numeric>
#include <regex>

using namespace std;

// Function Declarations
// **************************************************************************************
string remove_spaces(string number); // Remove spaces from a string
bool check(const string& input); // Check if the input string matches the required format
string getValidInput(); // Get a valid input string from the user
// ***************************************************************************************

// Main Function
// ***************************************************************************************
int main()
{
    // >>>>>>>>>>>>>>>>>> (Part about Ahmed Sheref) <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<

    cout << "\033[3;32m╭──────────────────────────────────────╮\033[0m" << endl;
    cout << "\033[3;32m│  Welcome to our Fraction calculator! │\033[0m" << endl;
    cout << "\033[3;32m╰──────────────────────────────────────╯\033[0m" << endl;
    cout << endl;

    // Main loop to keep the calculator running until the user chooses to exit
    while (true)
    {
        // Declare variables to store input operands and operators
        string num1_nem, num1_den, num2_nem, num2_den;
        char secound_obr;

        // Prompt user to start or exit the program
        cout << "\nWrite \"exit\" or \"2\" to finish the program\nEnter \"1\" or anything else to start the program\n";

        // Read user choice
        string choose;
        cin >> choose;
        cin.ignore();

        // Check if user wants to exit
        if (choose == "exit" || choose == "2")
        {
            cout << "Thank you for using the rational number calculator.\n";
            cout << "\033[3;31m  Exit... \033[0m" << endl;
            return 0;
        }

        // Get valid input from user
        string number = getValidInput();
        string num_not_sp = remove_spaces(number);

        // >>>>>>>>>>>>>>>>>> (Part about Ahmed Sheref) <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<

        // Initialize variables for parsing
        vector<char> oprs;
        int start = 0; // To specify the locations of the signs for dividing the numerator and denominator
        int i = 0;

        // Parse the first operand
        if (num_not_sp[0] == '-' || num_not_sp[0] == '+') // Check if the first character is a -ve or +ve
        {
            ++i; // Increment index To take into consideration
        }
        bool sign = false; // Flag to indicate to read sign ve like -5 , +5
        for (; i < num_not_sp.size(); ++i)
        {
            if (num_not_sp[i] == '+' || num_not_sp[i] == '-' || num_not_sp[i] == '*' || num_not_sp[i] == '/')
            { // Check if an operator is encountered
                for (int j = 0; j < i; ++j) // Iterate through the characters before the operator
                {
                    num1_nem += num_not_sp[j]; // Append characters to the numerator of the first operand
                }
                start = i + 1; // Set the starting index for the next operand
                if (num_not_sp[start] == '-' || num_not_sp[start] == '+') // Check if the next character is a sign
                {
                    sign = true; // Set the sign flag to true
                    start++; // Increment the index to skip the sign
                }
                break; // Exit the loop after processing the first operand
            }
        }

        // Handle denominator of first number
        if ((num_not_sp[start - 2]) != '/' && sign == true)
        {
            oprs.push_back('/'); // Add division operator to the operators vector
            num1_den = "1";      // Set the denominator of the first number to 1
            oprs.push_back(num_not_sp[start - 1]); // Add the sign of the first number to the operators vector
        }
        else if ((num_not_sp[start - 1]) != '/' && sign == false)
        {
            oprs.push_back('/');
            num1_den = "1";
            oprs.push_back(num_not_sp[start - 1]);
        }
        else
        {
            for (int i = start; i < num_not_sp.size(); ++i)
            {
                if (num_not_sp[i] == '+' || num_not_sp[i] == '-' || num_not_sp[i] == '*' || num_not_sp[i] == '/')
                {
                    int j = (sign == true ? start - 1 : start);
                    for (; j < i; ++j)
                    {
                        num1_den += (num_not_sp[j]);
                    }
                    start = j + 1;
                    secound_obr = num_not_sp[start - 1];
                    break;
                }
            }
        }

        // Parse the second operand
        for (int i = start - 1; i < num_not_sp.size(); ++i)
        {
            if (num_not_sp[i + 1] == '+' || num_not_sp[i + 1] == '-' || num_not_sp[i + 1] == '*' || num_not_sp[i + 1] == '/')
            {
                num2_nem += num_not_sp[i + 1];
                start++;
            }
            if (num_not_sp[i] == '+' || num_not_sp[i] == '-' || num_not_sp[i] == '*' || num_not_sp[i] == '/')
            {
                int j = start;
                for (; isdigit(num_not_sp[j]); ++j)
                {
                    num2_nem += num_not_sp[j];
                    if (num_not_sp[j + 1] == '\0')
                    {
                        num2_den = "1";
                    }
                }
                start = j + 1;
                break;
            }
        }

        // Handle denominator of second number
        for (int i = start; i <= num_not_sp.size(); ++i)
        {
            num2_den += num_not_sp[i];
        }

        // Variable to store the greatest common divisor
        int gc;

        // Check if there are no operators present
        if (oprs.empty())
        {
            secound_obr = secound_obr;
        }
        else
        {
            secound_obr = oprs[1];
        }

        // Check if the denominator of the first number is empty (which means it's an integer)
        if (num1_den == "")
        {
            gc = gcd(stoi(num1_nem), stoi(num2_nem));
            cout << "Result in Fraction: " << stod(num1_nem) / gc << '/' << stod(num2_nem) / gc;
            cout << " ==>> " << stod(num1_nem) / stod(num2_nem);
            continue;
        }

        // Check if the numerator of the second number is empty (which means it's a whole number)
        if (num2_nem == "")
        {
            cout << num2_den;
            continue;
        }

        double mult_den;  // Variable to store the product of denominators
        double sum_nem;   // Variable to store the sum of numerators

        // Check if any denominator is zero to avoid division by zero
        if (num1_den == "0" || num2_den == "0")
        {
            cout << "\nError ==> There is a zero in one of the denominators\n\n"; // Print error message
            continue; // Skip to the next iteration
        }

        // Perform operations based on the second operator
        switch (secound_obr)
        {
        case '+': // Addition operation
            mult_den = stod(num1_den) * stod(num2_den); // Calculate the common denominator
            sum_nem = (stod(num1_den) * stod(num2_nem)) + (stod(num2_den) * stod(num1_nem)); // Calculate the sum of numerators
            gc = gcd(int(mult_den), int(sum_nem));  // Find the greatest common divisor
            cout << "Result in Fraction: " << sum_nem / gc << '/' << mult_den / gc; // Output the result as a fraction
            cout << " ==>> " << sum_nem / mult_den; // Output the result as a decimal
            break;

        case '-': // Subtraction operation
            mult_den = stod(num1_den) * stod(num2_den); // Calculate the common denominator
            sum_nem = (stod(num2_den) * stod(num1_nem)) - (stod(num1_den) * stod(num2_nem)); // Calculate the difference of numerators
            gc = gcd(int(mult_den), int(sum_nem)); // Find the greatest common divisor
            cout << "Result in Fraction: " << sum_nem / gc << '/' << mult_den / gc; // Output the result as a fraction
            cout << " ==>> " << sum_nem / mult_den; // Output the result as a decimal
            break;

        case '*': // Multiplication operation
            mult_den = stod(num1_den) * stod(num2_den); // Calculate the new denominator
            sum_nem = (stod(num2_nem) * stod(num1_nem)); // Calculate the new numerator
            gc = gcd(int(mult_den), int(sum_nem)); // Find the greatest common divisor
            cout << "Result in Fraction: " << sum_nem / gc << '/' << mult_den / gc; // Output the result as a fraction
            cout << " ==>> " << sum_nem / mult_den; // Output the result as a decimal
            break;

        case '/': // Division operation
            mult_den = stod(num1_nem) * stod(num2_den); // Calculate the new denominator
            sum_nem = (stod(num1_den) * stod(num2_nem)); // Calculate the new numerator
            gc = gcd(int(mult_den), int(sum_nem)); // Find the greatest common divisor
            cout << "Result in Fraction: " << mult_den / gc << '/' << sum_nem / gc; // Output the result as a fraction
            cout << " ==>> " << mult_den / sum_nem; // Output the result as a decimal
            break;
        }

        cout << "\n\n"; // Add newlines for clarity
    }
}

// Function Definitions
// *******************************************************************************************

// Function to remove spaces from a string
string remove_spaces(string number)
{
    string remove_s;
    for (char ch : number)
    {
        if (!isspace(ch))
        {
            remove_s += ch;
        }
    }
    return remove_s;
}

// Function to check if the input string matches the required format
bool check(const string& input)
{
    // Regular expression pattern to match the required format
    regex pattern("^(?!.*[a-z]\\s*/).*\\s*-?\\d+\\s*(?:/\\s*-?\\d+)?\\s*[+\\-*/]\\s*-?\\d+\\s*(?:/\\s*-?\\d+)?\\s*$");
    return regex_search(input, pattern);
}

// Function to get a valid input string from the user
string getValidInput()
{
    string input;
    cout << "Enter a rational number operation: ";
    getline(cin, input);
    if (!check(input))
    {
        cout << "Invalid input format. Please try again.\n";
        input = getValidInput();
    }
    return input;
}

// Purpose: A special program for encryption algorithms and returning them to the original text. It also finds an encryption key in some algorithms.
// Bonus part and maked 3 additional games ==>> Total 4 games
// Author1: Ahmed Sheref Sayed   ID:20230542  Email:ahmedsheref2288@yahoo.com   section 21,22 <> Atbash Cipher , Affine_Cipher , Vignere_Cipher , Simple_Substitution_Cipher
// Version: 1.0
// Date: 18.March 2024

#include<iostream>
#include<cmath>
#include <string>
#include <map>
#include <cctype>
#include<vector>
using namespace std;

//                        >>>>>>>>>>>>>>>>>>> Declare Functions <<<<<<<<<<<<<<<<<<<<<<<<<<<
// ********************************************(abtash cipher)********************************************************

string valid_input(string input); // Function to validate user input as a number
string encryption_Text(string text, int choose, int key); // Function to perform Abtash cipher encryption or decryption
int Abtash_cipher(); // Function to execute Abtash cipher operations
// ------------------------------------------------------------------------------------------------------------------

// ********** *********************************( Affine_Cipher )*****************************************************
string Affine_Cipher(string text,int a,int b);
string Affine_Cipher_decipher (string text,int y,int b);
void main_Affine_Cipher ();
// ------------------------------------------------------------------------------------------------------------------

// ********************************************( Vignere_Cipher )****************************************************
void main_function_Vignere_Cipher();
// ------------------------------------------------------------------------------------------------------------------

// ***************************************( Simple_Substitution_Cipher )*********************************************
void Simple_Substitution_Cipher();


// Main function to start the encryption program
int main()
{
    // Infinite loop to keep the program running until the user chooses to exit
    while (true)
    {
    // Welcome message and menu for encryption methods
    cout << "╔════════════════════════════════════════╗\n";
    cout << "║        Welcome to Encryption Hub       ║\n";
    cout << "║                                        ║\n";
    cout << "║  We have 4 methods of encryption.      ║\n";
    cout << "║  Choose one of the following options:  ║\n";
    cout << "║  1. Atbash Cipher                      ║\n";
    cout << "║  2. Affine Cipher                      ║\n";
    cout << "║  3. Vigenere Cipher                    ║\n";
    cout << "║  4. Simple Substitution Cipher         ║\n";
    cout << "║  5. Exit                               ║\n";
    cout << "╚════════════════════════════════════════╝\n\n";

    cout << "\033[4;32mEnter your choice: \033[0m";

        // Prompt the user to choose an option
        string test_choose;
        getline(cin , test_choose);
        int number_choose = stoi(valid_input(test_choose)); // Make sure it is a number and convert it

        // Validate the user's choice
        while (number_choose != 1 && number_choose != 2 && number_choose != 3 && number_choose != 4 && number_choose != 5)
        {
            cout << "Enter your choice (1-5): ";
            cin >> test_choose;
            cin.ignore();
            number_choose = stoi(valid_input(test_choose));
        }

        // Execute the selected encryption method based on the user's choice
        switch (number_choose)
        {
        case 1:
            Abtash_cipher(); // Execute Abtash Cipher method
            break;
        case 2:
            main_Affine_Cipher(); // Execute Affine_Cipher method
            break;
        case 3:
            main_function_Vignere_Cipher(); // Execute Vignere_Cipher method
            break;
        case 4:
            Simple_Substitution_Cipher(); // Execute Simple_Substitution_Cipher method
            break;
        case 5:
            cout << "\033[3;31m  Exit... \033[0m" << endl; // Exit the program
            return 0;
        }

        // Prompt the user if they want to continue playing
        cout << "\nDo you want to continue playing?\n";
        cout << "  1. Yes\n";
        cout << "  2. No\n";

        // Prompt the user to choose whether to continue or exit
        string test_Try_again;
        cin >> test_Try_again;
        cin.ignore();
        int number_Try_again = stoi(valid_input(test_Try_again)); // convert input to int after validate

        // Validate the user's choice
        while (number_Try_again != 1 && number_Try_again != 2)
        {
            cout << "Enter your choice (1-2): ";
            cin >> test_Try_again;
            number_Try_again = stoi(valid_input(test_Try_again)); // convert input to int after validate
        }

        // Execute the selected action based on the user's choice
        switch (number_Try_again)
        {
        case 1:
            break; // Continue with the loop
        case 2:
            cout << "\033[3;31m  Exit... \033[0m" << endl; // Exit the program
            return 0;
        }
    }
}



//                                 >>>>>>>> All Functions our Program <<<<<<<<<<<<

// ********************************************( abtash cipher )*****************************************************
string valid_input(string input)
{
    string Chek_input = input;
    // Loop through each character in the input
    for (auto ch : Chek_input)
    {
        // Check if the character is not a digit
        if (!isdigit(ch))
        {
            cout << "Please enter a valid number\n"; // Prompt the user to enter a valid number
            cin >> Chek_input; // Read the input again
            return valid_input(Chek_input); // Recursively call the function to validate the new input
        }
    }
    return Chek_input; // Return the validated input
}

// Function to perform text encryption using the Abtash cipher algorithm
string encryption_Text(string text, int choose, int key) 
{
    // Define the key values for encryption
    int numbers[2] = { 0, 13 }; // The first key reverses the letters, and the second key divides the letters and reverses each section
    cout << (choose == 1 ? "Text After cipher => " : "Text Before cipher => ");
    int ky = numbers[key - 1];
    string text_after_cipher = "";

    // Loop through each character in the input text
    for (char ch : text)
    {
        // Check if the character is an alphabet
        if (isalpha(ch))
        {
            // Perform encryption based on the chosen option
            char encrypted_char;
            if (islower(ch))
            { // Lowercase letters
                encrypted_char = 'a' + ('z' - tolower(ch) + ky) % 26;
            }
            else
            { // Uppercase letters
                encrypted_char = 'A' + ('Z' - toupper(ch) + ky) % 26;
            }
            text_after_cipher += encrypted_char;
        }
    }
    return text_after_cipher; // Return the encrypted text
}





// Function to implement the Abtash cipher
int Abtash_cipher()
{
    cout << "*** Welcome to Abtash_cipher ***\n\n";
    while (true) // Infinite loop to keep the program running until the user exits
    {
        string Text_before_cipher;
        cout << "Text: "; // Prompt the user to enter the text for encryption
        getline(cin, Text_before_cipher); // Read the input text

        string choose;
        cout << "\n1-Cipher a message\n2-Decipher a message\n(1\\2) => ";
        cin >> choose;
        cin.ignore();
        int choose_number = stoi((valid_input(choose)));

        // Validate the user's choice
        while (true)
        {
            if (choose_number == 1 || choose_number == 2)
                break;
            cout << "Please enter valid input (1\\2) ";
            cin >> choose_number;
            cin.ignore();
        }

        cout << "You want to divide the letters into several sections => Key: ";
        string test_key;
        cin >> test_key; // Prompt the user to enter the key
        cin.ignore();
        int key = stoi(valid_input(test_key)); // Convert the key to an integer

        // Validate the key
        while (true)
        {
            if (key < 1 || key > 2)
            {
                cout << "Please enter key => 1-2 only: ";
                cin >> test_key;
                cin.ignore();
                key = stoi(valid_input(test_key));
            }
            else
                break;
        }

        // Perform encryption or decryption based on the user's choice
        if (choose_number == 1 || choose_number == 2)
        {
            string text_after_cipher = encryption_Text(Text_before_cipher, choose_number, key); // Call the encryption function
            cout << text_after_cipher << endl; // Display the result
        }

        string test_try_again;
        cout << "\n1) Try again\n2)Exit\n(1\\2) => ";
        cin >> test_try_again;
        cin.ignore();
        int try_again = stoi(valid_input(test_try_again));

        // Validate the user's choice to retry or exit
        if (try_again != 1)
        {
            if (try_again == 2)
            {
                cout << "Exit...From This method";
                return 0; // Exit the program
            }
            while (true)
            {
                cout << "Please enter 1-2 Only: ";
                cin >> test_try_again;
                try_again = stoi(valid_input(test_try_again));
                if (try_again == 2)
                {
                    cout << "Exit...From This method";
                    return 0; // Exit the program
                }
                else if (try_again == 1)
                {
                    break;
                }
            }
        }
    }
}

// ------------------------------------------------------------------------------------------------------------------

// ********************************************( Affine_Cipher )*****************************************************
// Encryption part
string Affine_Cipher(string text, int a, int b)
{
  string new_text = ""; // Initialize an empty string to store the encrypted text
  int x; // Declare a variable to store the numerical value of each character
  for (int i = 0; i < text.size(); i++)
  {
    if (isalpha(text[i])) 
    {
      x = tolower(text[i]) - 97; // Convert the character to lowercase and calculate its numerical value (0-25)
      /*
      Apply the affine cipher encryption formula: E(x) = (ax + b) mod 26, where 'a' is the multiplier
      , 'x' is the numerical value of the character,  'b' is the shift value
      */
      new_text += toupper(char(((a * x + b) % 26) + 65));
    }
  }
  return new_text; // Return the encrypted text
}

// Return encryption
string Affine_Cipher_decipher(string text, int c, int b)
{
  string new_text = "";
  int y;
  int value1; // Declare a variable to store the intermediate result of the decryption
  int value2; // Declare a variable to store the final decrypted numerical value
  for (int i = 0; i < text.size(); i++) 
  {
    if (isalpha(text[i])) // Check if the character is an alphabet
    {
      y = tolower(text[i]) - 97; // Convert the character to lowercase and calculate its numerical value (0-25)
      value1 = (c * (y - b)); // Calculate the intermediate result
      value2 = abs(value1 < 0 ? value1 % 26 + 26 : value1 % 26); // Ensure the result stays positive and within the range of alphabets
      new_text += tolower(char(value2 + 97)); // Convert the decrypted numerical value back to lowercase ASCII character and append it to the decrypted text
    }
  }
  return new_text; // Return the decrypted text
}

// // Main function for executing the Affine Cipher algorithm.
// This function allows the user to input text and encryption/decryption keys.
void main_Affine_Cipher()
{
  while (true) // Loop indefinitely until the user decides to exit
  {
    cout << "*** Welcome to Affine_Cipher ***\n\n";
    string text;
    cout << "Text: ";
    getline(cin, text); // Prompt the user to enter the text to be ciphered or deciphered

    // Prompt the user to enter the keys for the affine cipher
    int a, b, c;
    cout << "\na, b, c  => (a * x + b) % 26 , c * (x - b) % 26:\n";
    cout << "number key a: "; cin >> a;
    while (a < 0 || a > 25) // Validate that 'a' is positive
    {
      cout << "please enter a positive number (0-25): \n";
      cin >> a;
    }
    cout << "number key b: "; cin >> b;
    while (b < 0 || b > 25) // Validate that 'b' is positive
    {
      cout << "please enter a positive number (0-25): \n";
      cin >> b;
    }
    cout << "number key c: "; cin >> c;
    while (c < 0 || c > 25) // Validate that 'c' is positive
    {
      cout << "please enter a positive number (0-25): \n";
      cin >> c;
    }

    string choose;
    cout << "\n1-Cipher a message\n2-Decipher a message\n(1\\2) => ";
    cin >> choose; // Prompt the user to choose between ciphering or deciphering
    cin.ignore(); // Clear the input buffer
    int choose_number = stoi(valid_input(choose)); // Convert user input to integer
    // Validate the user's choice
    while (true)
    {
      if (choose_number == 1 || choose_number == 2)
          break;
      cout << "Please enter valid input (1\\2) ";
      cin >> choose_number;
      cin.ignore();
    }

    switch (choose_number)
    {
      case 1:
        cout << "Text After Cipher: ";
        cout << Affine_Cipher(text, a, b); // Cipher the input text using the Affine Cipher algorithm
        break;
      case 2:
        cout << "Text Before Cipher: ";
        cout << Affine_Cipher_decipher(text, c, b); // Decipher the input text using the Affine Cipher algorithm
        break;
    }

    string try_again;
    cout << "\nAnother text?:\n1-Yes\n2-No \n";
    cin >> try_again; // Prompt the user to decide whether to continue or exit
    int try_again_number = stoi((((try_again)))); // Convert user input to integer
    // Validate the user's choice
    while (true)
    {
      if (try_again_number == 1 || try_again_number == 2)
          break;
      cout << "Please enter valid input (1\\2) ";
      cin >> try_again;
      try_again_number = stoi(((try_again)));
      cin.ignore();
    }

    if (try_again_number == 2) // If the user chooses to exit
    {
      cout << "Exit...for Affine cipher\n";
      break; // Exit the loop
    }

    cin.ignore(); // Clear the input buffer
  }
}

// ********************************************( Vignere_Cipher )****************************************************
// // Main function for executing the Vigenère Cipher algorithm.
void main_function_Vignere_Cipher()
{
  cout << "*** Welcome to Vignere_Cipher ***\n\n";
  string key;
  cout << "Enter the keyword: "; // Prompt the user to enter the Vigenere cipher keyword
  getline(cin, key); // Read the keyword from the user

  // Convert the characters of the keyword to their corresponding ASCII values and store them in a vector
  vector<int> keyIndices;
  for (char character : key) 
  {
    keyIndices.push_back(int(toupper(character))); // Convert characters to uppercase and store their ASCII values
  }

  string text;
  cout << "Text: ";
  getline(cin, text); // Prompt the user to enter the text to be ciphered or deciphered

  string new_text = ""; // Initialize a string to store the ciphered or deciphered text
  string choose;
  cout << "\n1-Cipher a message\n2-Decipher a message\n(1\\2) => ";
  getline(cin, choose); // Prompt the user to choose between ciphering or deciphering
  int choose_number = stoi(choose); // Convert user input to an integer
  // Validate the user's choice
  while (true)
  {
    if (choose_number == 1 || choose_number == 2)
      break;
    cout << "Please enter valid input (1\\2) ";
    cin >> choose;
    cin.ignore();
    choose_number = stoi(valid_input(choose));
  }

  switch (choose_number)
  {
    int val;
    int val2;
    case 1: // Cipher the text
      for (int i = 0, k = 0; i < text.size(); ++i)
      {
        if (k == keyIndices.size())
        {
          k = 0; // Wrap around the keyword index if it reaches the end
        }
        if (isalpha(text[i]))
        {
          val = int(text[i] + keyIndices[k]); // Add the corresponding keyword character to the text character
          val2 = val % 26; // Wrap around the alphabet if needed
          new_text += (isupper(text[i]) ? val2 + 'A' : val2 + 'a'); // Append the ciphered character to the new text
          k++; // Move to the next keyword character
        }
        else
        {
          k++; // Move to the next keyword character
          new_text += text[i]; // Append non-alphabetic characters directly to the new text
        }
      }
      cout << new_text; // Output the ciphered text
      break;
    case 2: // Decipher the text
      for (int i = 0, k = 0; i < text.size(); ++i)
      {
        if (k == keyIndices.size())
        {
          k = 0; // Wrap around the keyword index if it reaches the end
        }
        if (isalpha(text[i]))
        {
          val = int((isupper(text[i]) ? keyIndices[k] - 'A' : keyIndices[k] - 'a')); // Subtract the keyword character from the text character
          val2 = int(val < 65 ? text[i] - val : text[i] - val); // Wrap around the alphabet if needed
          new_text += char(val2 < 65 ? val2 + 26 : text[i] - val); // Append the deciphered character to the new text
          k++; // Move to the next keyword character
        }
        else
        {
          k++; // Move to the next keyword character
          new_text += text[i]; // Append non-alphabetic characters directly to the new text
        }
      }
      cout << new_text; // Output the deciphered text
  }
}


// ********************************************( Simple_Substitution_Ciphe )******************************************

// Function for implementing the Simple Substitution Cipher algorithm.
void Simple_Substitution_Cipher()
{
    cout << "*** Welcome to Simple_Substitution_Cipher ***\n\n";
  // Define the main alphabet and initialize variables
  string main_alpha = "abcdefghijklmnopqrstuvwxyz";
  string new_alpha;
  string key;
  
  // Prompt the user to enter the substitution key
  cout << "Enter the substitution key: ";
  getline(cin , key);
  
  // Validate the substitution key to ensure it contains only alphabetic characters
  for (int i = 0; i < key.size(); ++i)
  {
    if (!isalpha(key[i]))
    {
      cout << "Please enter only alphabetic characters: ";
      getline(cin , key);
      i = 0; // Reset the loop to check the modified input
    }
  }

  // Create a new alphabet based on the substitution key
  bool chak_alpha = true;
  new_alpha += key;
  for (int i = 0; i < main_alpha.size(); ++i)
  {
    chak_alpha = true;
    for (int j = 0; j < key.size(); j++)
    {
      if (main_alpha[i] == key[j])
      {
        chak_alpha = false; // Mark characters already in the key
        break;
      }
    }
    if (chak_alpha == false)
    {
      continue;
    }
    else
    {
      new_alpha += main_alpha[i]; // Append characters not in the key to the new alphabet
    }
  }

  // Convert alphabets to vectors for easier access
  vector <char> main_alpha_2;
  vector <char> new_alpha_2;
  for (int i = 0; i < main_alpha.size(); ++i)
  {
    main_alpha_2.push_back(main_alpha[i]);
  }
  for (int i = 0; i < new_alpha.size(); ++i)
  {
    new_alpha_2.push_back(new_alpha[i]);
  }

  // Prompt the user to choose between ciphering or deciphering
  string choose;
  cout << "\n1-Cipher a message\n2-Decipher a message\n(1\\2) => ";
  getline(cin , choose);
  int choose_number = stoi(valid_input(choose));
  
  // Validate the user's choice
  while (true)
  {
    if (choose_number == 1 || choose_number == 2)
      break;
    cout << "Please enter valid input (1\\2) ";
    cin >> choose;
    cin.ignore();
    choose_number = stoi(choose);
  }

  // Perform the chosen operation: ciphering or deciphering
  switch(choose_number)
  {
    case 1: // Cipher the message
    {
      cout << "Enter the message to cipher: ";
      string text_after_cipher = "";
      cin.ignore();
      getline(cin , text_after_cipher);
      cout << "Text after cipher: ";
      
      // Iterate through the input text and replace each character with its substitution
      for (int i = 0; i < text_after_cipher.size(); ++i)
      {
        if (!isalpha(text_after_cipher[i]))
        {
          cout << text_after_cipher[i]; // Keep non-alphabetic characters unchanged
        }
        else
        {
          // Find the substitution character for each input character and print it
          for (int j = 0; j < new_alpha_2.size(); ++j)
          {
            if (char(tolower(text_after_cipher[i])) == char(tolower(main_alpha_2[j])))
            {
              cout << new_alpha_2[j];
              break;
            }
          }
        }
      }
      cout << endl;
      break;
    }
    case 2: // Decipher the message
    {
      cout << "Enter the message to decipher: ";
      string text_after_cipher = "";
      getline(cin , text_after_cipher);
      cout << "Text before decipher: ";
      
      // Iterate through the input text and replace each character with its original character
      for (int i = 0; i < text_after_cipher.size(); ++i)
      {
        if (!isalpha(text_after_cipher[i]))
        {
          cout << text_after_cipher[i]; // Keep non-alphabetic characters unchanged
        }
        else
        {
          // Find the original character for each substitution character and print it
          for (int j = 0; j < new_alpha_2.size(); ++j)
          {
            if (char(tolower(text_after_cipher[i])) == char(tolower(new_alpha_2[j])))
            {
              cout << main_alpha_2[j];
              break;
            }
          }
        }
      }
      cout << endl;
      break;
    }
  }
}
  //made by engineer ahmed sherief
  #include<iostream>
  #include<cmath>
  #include <string>
  using namespace std;

  string valid_input (string input)
  {
    string Chek_input = input;
    for (auto ch : Chek_input)
    {
      if (isdigit(ch) == false)
      {
        cout << "Please enter a valid number\n";
        cin >> Chek_input;
        return valid_input(Chek_input);
      }
    }
    return (Chek_input);
  }


  string encryption_Text(string text, int choose) 
  {
    cout << (choose == 1 ? "Text After cipher => " : "Text Before cipher => ");
    string text_after_cipher = "";
    for (char ch : text)
    {
      if ((ch >= 65 && ch <= 90) || (ch >= 97 && ch <= 122))
      {
        if (ch <= 109 && ch >= 97) 
          text_after_cipher += toupper(((25 - (ch - 97)) + 97));
        else if (ch >= 109 && ch >= 97)
          text_after_cipher += toupper((109 - ((ch - 110))));
        else if (ch <= 77 && ch >= 65) 
          text_after_cipher += toupper(((25 - (ch - 65)) + 65));
        else if (ch >= 77 && ch >= 65) 
          text_after_cipher += toupper((77 - ((ch - 78))));
      } 
    }
    return text_after_cipher;
  }

  int main() 
  {
    while (true) 
    {
      string Text_before_cipher;
      cout << "Text: ";
      getline(cin, Text_before_cipher);

      string choose;
      cout << "\n1-Cipher a message\n2-Decipher a message\n(1\\2) => ";
      cin >> choose;
      cin.ignore();
      int choose_number = stoi((valid_input(choose)));

      while(true)
      {
        if (choose_number == 1 || choose_number == 2)
          break;
        cout << "Please enter valid input (1\\2\\3) ";
        cin >> choose_number;
        cin.ignore();
      }
      if (choose_number == 1 || choose_number == 2)
      {
        string text_after_cipher = encryption_Text(Text_before_cipher, choose_number);
        cout << text_after_cipher << endl;
      }
      else if (choose_number == 3)
      {
        cout << "text_after_cipher: " << reverse_text(Text_before_cipher) << endl;
      }

      int try_again;
      cout << "\n1) Try again\n2)Exit\n(1\\2) => ";
      cin >> try_again;
      cin.ignore();
      if (try_again != 1) 
      {
        cout << "Exit...\n";
        return 0;
      }
    }
  }
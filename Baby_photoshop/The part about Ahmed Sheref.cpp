// Purpose: 
/*
  This program implements various image processing functions.
*/
//                                                                                    -------------------------------------------------------------
// Author1: Ahmed Sheref Sayed  ID:20230542  Email:ahmedsheref2288@yahoo.com S21,S22  | (valid_input),(print_message),                            |
//                                                                                    | (Grayscale_Conversion),(merge_image),                     |
//                                                                                    | (Darken_and_light), (Detect_Image_Edges) , (Purple_lffy)  |
//                                                                                    -------------------------------------------------------------

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include "Image_Class.h" // Include the header file for the Image class
#include "string" 

using namespace std;



// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> part of ahmed sheref <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
string IF_FILE_EXISTS (string namefile);
string valid_input(string input);
void pirnt_message();
void Grayscale_Conversion ();
void merge_image();
void Darken_and_light ();
void Detect_Image_Edges();
void Purple_lffy();
void save_image (string &filename , Image &image); // Ask the user if he wants to save the image or not 
// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> end part of ahmed sheref <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<

string Main_name;
string original_photo;
string edited_photo;
Image Main_image;
int main ()
{
  cout << "\nPlease Enter Image_name: ";
  cin >> Main_name;
  cin.ignore();
  Main_name = IF_FILE_EXISTS(Main_name);
  original_photo = Main_name;
  Image Main_image(Main_name);
  while (true)
  {
    cout << "╔════════════════════════════════════════╗\n";
    cout << "║              \033[7;31m R \033[0m ";    // Red
    cout << "\033[7;32m G \033[0m ";                   // Green
    cout << "\033[7;34m B \033[0m               ║\n";  // Blue
    cout << "║  We have 6 methods of photoshop.       ║\n";
    cout << "║  Choose one of the following options:  ║\n";
    cout << "║  1. Grayscale_Conversion_Image         ║\n";
    cout << "║  2. merge_image                        ║\n";
    cout << "║  3. Darken_and_light_Image             ║\n";
    cout << "║  4. Detect_Edges_Image                 ║\n";
    cout << "║  5. Purple_lffy_image                  ║\n";
    cout << "║  6. Exit                               ║\n";
    cout << "╚════════════════════════════════════════╝\n\n";

    string test_choose;
    cout << "--> ";
    getline(cin , test_choose); // Read user choice
    int number_choose = stoi(valid_input(test_choose)); // Convert user choice to integer

    // Validate user choice
    vector <int> menu = {1,2,3,4,5,6};
    int found = count(menu.begin(),menu.end(),number_choose);
    while (!found)
    {
      cout << "Enter your choice (1-6): ";
      cin >> test_choose; // Read user choice again
      number_choose = stoi(valid_input(test_choose)); // Convert user choice to integer
      found = count(menu.begin(),menu.end(),number_choose);
    }

    switch (number_choose)
    {
      case 1:
        Grayscale_Conversion(); // Call grayscale conversion function
        break;
      case 2:
        merge_image(); // Call merge image function
        break;
      case 3:
        Darken_and_light(); // Call rotate image function
        break;
      case 4:
        Detect_Image_Edges(); // Call invert image function
        break;
      case 5:
        Purple_lffy(); // Call resize image function
        break;
    case 16:
        cout << "Exit...\n";
        return 0;
    }
// Prompt the user if they want to continue editing pictures
    cout << "\n----------------------------------------------\n";
    cout << "\nDo you want to continue editing which pictures?\n";
    cout << "  1. original image\n";
    cout << "  2. edited image\n";
    cout << "  3. change image\n";
    cout << "  4. Exit Programming\n";
    cout << "\n----------------------------------------------\n";

    // Read user choice
    string test_Try_again;
    cin >> test_Try_again;
    cin.ignore();
    int number_Try_again = stoi(valid_input(test_Try_again)); // Convert user choice to integer

    // Validate user choice
    while (number_Try_again != 1 && number_Try_again != 2 && number_Try_again != 3 && number_Try_again != 4)
    {
      cout << "Enter your choice (1-4): ";
      cin >> test_Try_again; // Read user choice again
      number_Try_again = stoi(valid_input(test_Try_again)); // Convert user choice to integer
    }

    // Execute the selected action based on the user's choice
    switch (number_Try_again)
    {
    case 1:
      Main_name = original_photo;
      break; // Continue with the loop
    case 2:
      Main_name = edited_photo;
      break; // Continue with the loop
    case 3:
      cout << "Change Image __ Enter New name Image: ";
      cin >> Main_name;
      cin.ignore();
      Main_name = IF_FILE_EXISTS(Main_name);
      break; // Continue with the loop
    case 4:
      cout << "\033[3;31m  Exit... \033[0m" << endl; // Inform about program exit
      return 0; // Exit the program
    }
  }
  return 0;
}

// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> part of ahmed sheref <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
void save_image (string &filename , Image &image)
{
  string test_save;
  // cin.ignore(); // Ignore any remaining characters in the input buffer
  cout << "\n-----------------------\n\n";
  cout << "1) Save to the new image\n";
  cout << "2) Not save\n";
  cout << "\n-----------------------\n";
  getline(cin, test_save); // Read user choice
  int number_save = stoi(valid_input(test_save)); // Convert user choice to integer

  // Validate user choice
  while (number_save != 1 && number_save != 2)
  {
    cout << "Enter your choice (1-2): ";
    cin >> test_save; // Read user choice again
    cin.ignore(); // Ignore any remaining characters in the input buffer
    number_save = stoi(valid_input(test_save)); // Convert user choice to integer
  }

  switch (number_save)
  {
  case 1:
    cout << "Pls enter image name to store new image\n";
    cout << "and specify extension .jpg, .bmp, .png, .tga: ";
    cin >> filename; // Read filename from user
    image.saveImage(filename); // Save image with the specified filename
    edited_photo = filename;
    cout << "Saved successfully\n";
    break;
  case 2:
    break; // Do not save the image
  }
}

string IF_FILE_EXISTS (string namefile)
{
  while (true) // Loop until a valid file is found
  {
    ifstream file; // Declare input file stream
    file.open(namefile); // Attempt to open the file with the given name
    if (!file) // If the file does not exist or cannot be opened
    {
      cout << "Please check the file format or the file does not exist\n"; // Inform the user about the issue
      cin >> namefile; // Prompt the user to enter a new file name
      cin.ignore();
    }
    else // If the file exists and can be opened
    {
      break; // Exit the loop
    }
  }
  return namefile; // Return the valid file name
}


// Function to validate user input
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

void pirnt_message()
{
  cout << "\033[5;31m R \033[0m"; // Print 'R' in red
  cout << "\033[5;32m G \033[0m"; // Print 'G' in green
  cout << "\033[5;34m B \033[0m"; // Print 'B' in blue
  cout << " <<<<<<<<<<<<";
  cout << endl;
}

// Function for grayscale conversion
void Grayscale_Conversion()
{
  cout << "Welcome to Grayscale_Conversion programming :\n>>>>>>>>> ";
  pirnt_message();
  Image photo(Main_name); // Load the photo from the provided photoname

  for (int i = 0; i < photo.width; ++i)
    {
      for (int j = 0; j < photo.height; ++j)
      {
        int middle = 0; // Initialize average value

        // Calculate average pixel value
        for (int k = 0; k < 3; ++k)
        {
            middle += photo(i, j, k); // Accumulate pixel values
        }

        middle /= 3; // Calculate average

        // Set all channels to the average value
        photo(i, j, 0) = middle;
        photo(i, j, 1) = middle;
        photo(i, j, 2) = middle;
      }
    }
    string test_name;
    save_image(test_name, photo); // Save the modified image
}

// Function to print message


// Function to merge images
void merge_image()
{
  cout << "Welcome to merge_image programming :\n>>>>>>>>> ";
  pirnt_message(); // Print message
  string  photoname2;
  cout << "Pls enter colored image_1 name : ";
  cout << "Pls enter colored image_2 name : ";
  cin >> photoname2;
  photoname2 = IF_FILE_EXISTS(photoname2);

  Image image(Main_name);
  Image image2(photoname2);
  Image image3;

  // Determine the size of the resulting image
  if ((image.width * image.height) < image2.width * image2.height)
  {
    image3.loadNewImage(Main_name);
  }
  else
  {
    image3.loadNewImage(photoname2);
  }

  // Merge the images
  for (int i = 0; i < image3.width; ++i) 
  {
  // Loop through each column of the image
  for (int j = 0; j < image3.height; ++j)
  {
    // Loop through each row of the image
    for (int k = 0; k < image3.channels; ++k) 
    {
        // Loop through each channel (e.g., Red, Green, Blue)
        int pixel_value = 0;
        
        // Compute the pixel value for the current pixel in image3
        // by blending corresponding pixels from image and image2
        pixel_value += image(i, j, k) * 0.7; // Blend pixel from image
        pixel_value += image2(i, j, k) * 0.7; // Blend pixel from image2
        
        // Ensure the pixel value is within the range [0, 255]
        image3(i, j, k) = min(pixel_value, 255);
    }
  }
}

  string file_name3;
  cin.ignore();
  save_image(file_name3, image3); // Save the merged image
}

void Darken_and_light ()
{
  cout << "Welcome to Darken_and_light programming :\n>>>>>>>>> ";
  pirnt_message(); // Print message
  int choose_persnteg;
  cout << "\n1) 50 % -> dark\n2) 50 % -> light\n";
  cin >> choose_persnteg;
  Image image(Main_name);

  int new_pixel = 0;
  // Merge the images
  for (int i = 0; i < image.width; ++i) 
  {
  // Loop through each column of the image
    for (int j = 0; j < image.height; ++j)
    {
      new_pixel = 0;
      switch(choose_persnteg)
      {
        case 1:
          for (int k = 0; k < image.channels; ++k) 
          {
            new_pixel = image(i, j, k) * 0.5;
            image(i, j, k) = min(new_pixel,255);
          }
        break;
        case 2:
          for (int k = 0; k < image.channels; ++k) 
          {
            new_pixel = image(i, j, k) * 1.5;
            image(i, j, k) = min(new_pixel,255);
          }
        break;
      }
    }
  }
  string file_name;
  cin.ignore();
  save_image(file_name,image);
}

void Detect_Image_Edges() 
{
  cout << "Welcome to Detect Image Edges programming :\n>>>>>>>>> ";
  pirnt_message(); // Print message

  // Load the photo from the provided photoname
  Image photo(Main_name);

  // Define horizontal and vertical edge detection kernels
  int HR[3][3] = 
  {
    {-1, 0, 1},
    {-2, 0, 2},
    {-1, 0, 1}
  };
  int Vr[3][3] = 
  {
    {1, 2, 1},
    {0, 0, 0},
    {-1, -2, -1}
  };

  // Initialize variables to store image dimensions
  long long int height = photo.height;
  long long int width = photo.width;

  // Initialize arrays to store gradient magnitudes
  long long int IX[height - 2][width - 2];
  long long int IY[height - 2][width - 2];
  long long int IXY[height - 2][width - 2];
  long long int sum_IX = 0;
  long long int sum_IY = 0;
  long long int pixell = 0;
  long long int sum_IXY = 0;

  // Compute gradient magnitudes using Sobel operator
  for (long long int i = 0; i < photo.width - 2; i++) 
  {
    for (long long int j = 0; j < photo.height - 2; j++) 
    {
      sum_IX = 0;
      sum_IY = 0;
      pixell = 0;
      for (long long int k = 0; k < 3; k++) 
      {
        for (long long int n = 0; n < 3; n++) 
        {
          pixell = 0;
          // Compute grayscale intensity using weighted sum of RGB channels
          pixell += photo(i + k, j + n, 0) * 0.299;
          pixell += photo(i + k, j + n, 1) * 0.587;
          pixell += photo(i + k, j + n, 2) * 0.114;
          sum_IX += HR[k][n] * pixell; // Compute horizontal gradient
          sum_IY += Vr[k][n] * pixell; // Compute vertical gradient
        }
      }
      IX[i][j] = sum_IX;
      IY[i][j] = sum_IY;
    }
  }

  // Compute gradient magnitude magnitude and average
  for (long long int i = 0; i < photo.width - 2; i++) 
  {
    for (long long int j = 0; j < photo.height - 2; j++) 
    {
      IXY[i][j] = sqrt(pow(IX[i][j], 2) + pow(IY[i][j], 2)); // Compute gradient magnitude
      sum_IXY += IXY[i][j]; // Accumulate gradient magnitudes
    }
  }
  long long int avr_IXY = sum_IXY / ((height - 2) * (width - 2)); // Compute average gradient magnitude

  // Threshold gradient magnitudes to generate edge map
  for (long long int i = 0; i < photo.width - 2; i++) 
  {
    for (long long int j = 0; j < photo.height - 2; j++) 
    {
      IXY[i][j] = (IXY[i][j] > avr_IXY ? 0 : 255); // Apply thresholding
    }
  }

  // Update image with edge map
  for (long long int i = 0; i < photo.width - 2; i++) 
  {
    for (long long int j = 0; j < photo.height - 2; j++) 
    {
      photo(i, j, 0) = IXY[i][j];
      photo(i, j, 1) = IXY[i][j];
      photo(i, j, 2) = IXY[i][j];
    }
  }

  // Save the modified image
  string file_name;
  save_image(file_name, photo);
}


void Purple_lffy ()
{
  cout << "Welcome to Purple_lffy programming :\n>>>>>>>>> ";
  pirnt_message(); // Print message
  // string photoname;
  // cout << "Pls enter colored image name: ";
  // cin >> photoname; // Read user input for image name
  // photoname = IF_FILE_EXISTS(photoname);
  Image photo(Main_name); // Load the photo from the provided photoname

  for (int i = 0; i < photo.width; ++i)
    {
      for (int j = 0; j < photo.height; ++j)
      {
          photo(i, j, 0) = photo(i, j, 0);
          photo(i, j, 1) = photo(i, j, 1) * 0.65;
          photo(i, j, 2) = photo(i, j, 2);
      }
    }
    string photoname;
    save_image(photoname, photo); // Save the modified image
}
// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> end part of ahmed sheref <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
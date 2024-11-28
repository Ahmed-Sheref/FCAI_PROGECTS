#  Program: PDF Separate and Merge Application - A tool to merge, extract specific pages, and split PDF files.
#  Input format:
'''
merge_pdfs => input_path => "location:\name_file.pdf" => "D:\icpc123-merged.pdf", etc..
merge_pdfs => output_path => "location:\name_file.pdf" => "D:\icpc123-merged.pdf", etc..

extract_page => input_path => "location:\name_file.pdf" => "D:\icpc123-merged.pdf", etc..
Page_index => 0_end_Pages

split_pdf => input_path => "location:\name_file.pdf" => "D:\icpc123-merged.pdf", etc..
split_pdf => output_path => "D:\", "C:\", etc..
'''
#  Author:  
#  - Ahmed Sheref Sayed (20230542) - merge_pdfs Function 
#  - Hassan Walid Hasaan (20230544) - extract_page Function
#  - Abdelrahman Mohamed (20230216) - split_pdf Function
#  Version: 1.0
#  Date: 3 March 2024

# Import the necessary modules
import PyPDF2
import os

# Function to merge multiple PDF files into one
def merge_pdfs(output_path, *pdf_paths):
    # Create a PdfMerger object
    merger = PyPDF2.PdfMerger()
    
    # Iterate over each input PDF file path
    for pdf_path in pdf_paths:
        # Append the PDF file to the merger object
        merger.append(pdf_path)
    
    # Write the merged PDF to the output path
    merger.write(output_path)
    
    # Close the merger object
    merger.close()
    
    # Print a success message
    print("PDF files merged successfully!")

# Function to extract a specific page from a PDF file
def extract_page(input_pdf, page_number):
    # Open the input PDF file in read-binary mode
    with open(input_pdf, 'rb') as file:
        # Create a PdfReader object
        reader = PyPDF2.PdfReader(file)
        
        # Check if the page number is valid
        if page_number < 0 or page_number >= len(reader.pages):
            print("Invalid page number")
            return
        
        # Generate the output PDF file name
        output_pdf = f"{os.path.splitext(input_pdf)[0]}-{page_number + 1}.pdf"
        
        # Create a PdfWriter object
        writer = PyPDF2.PdfWriter()
        
        # Add the specified page to the writer object
        writer.add_page(reader.pages[page_number])
        
        # Write the extracted page to the output PDF file
        with open(output_pdf, 'wb') as output:
            writer.write(output)
        
        # Print a success message
        print(f"Page {page_number + 1} extracted successfully to '{output_pdf}'")

# Function to split a PDF file into separate pages
def split_pdf(input_pdf, output_folder, start_page, end_page):
    # Open the input PDF file in read-binary mode
    with open(input_pdf, 'rb') as file:
        # Create a PdfReader object
        reader = PyPDF2.PdfReader(file)
        
        # Extract the base name of the input PDF file
        base_name = os.path.splitext(os.path.basename(input_pdf))[0]
        
        # Output directory path for storing split PDF files
        output_directory = output_folder  
        
        # Check if the output directory exists, if not, create it
        if not os.path.exists(output_directory):  
            os.makedirs(output_directory)  

        # Iterate over the specified range of pages
        for page_number, page in enumerate(reader.pages[start_page - 1:end_page], start=start_page):
            # Generate the output PDF file name for each page
            output_pdf = os.path.join(output_directory, f"{base_name}-{page_number}.pdf")
            
            # Create a PdfWriter object
            writer = PyPDF2.PdfWriter()
            
            # Add the current page to the writer object
            writer.add_page(page)
            
            # Write the page to the output PDF file
            with open(output_pdf, 'wb') as output:
                writer.write(output)
            
            # Print a success message for each extracted page
            print(f"Page {page_number} extracted successfully to '{output_pdf}'")

        # Merge the split PDF files into a single PDF file
        output_merged_pdf = os.path.join(output_folder, f"{base_name}-merged.pdf")
        merge_pdfs(output_merged_pdf, *[
            os.path.join(output_directory, f"{base_name}-{i}.pdf") for i in range(start_page, end_page + 1)
        ])
        print(f"Split PDF pages merged successfully into '{output_merged_pdf}'")

# Main function for user interaction
def main():
    # Display a welcome message
    print("*** Welcome to the PDF Separate and Merge Application ***")
    
    # Main program loop
    while True:
        # Display available options to the user
        print("\nWhat would you like to do?")
        print("1. Merge two PDF files")
        print("2. Extract a page from a PDF file")
        print("3. Split a PDF file into separate pages")
        print("4. Exit")
        
        # Prompt the user for choice
        choice = input("Enter your choice (1-4): ")
        
        # Process user's choice
        if choice == '1':
            file1_path = input("Enter the path to the first PDF file: ").strip().strip('"')
            file2_path = input("Enter the path to the second PDF file: ").strip().strip('"')
            output_path = input("Enter the output path for the merged PDF file: ").strip().strip('"')
            merge_pdfs(output_path, file1_path, file2_path)
        elif choice == '2':
            input_pdf = input("Enter the path to the PDF file: ").strip().strip('"')
            page_number = int(input("Enter the page number to extract (0-indexed): "))
            extract_page(input_pdf, page_number)
        elif choice == '3':
            input_pdf = input("Enter the path to the PDF file: ").strip().strip('"')
            output_folder = input("Enter the output folder path: like this \"D:\\\"\\,,\"C:\\\"\\,,etc.. =>> ").strip().strip('"')
            start_page = int(input("Enter the start page number to split: "))
            end_page = int(input("Enter the end page number to split: "))
            split_pdf(input_pdf, output_folder, start_page, end_page)
        elif choice == '4':
            print("Exiting program...")
            break
        else:
            print("Invalid choice. Please enter a number from 1 to 4.")

# Call the main function to run the program

main()

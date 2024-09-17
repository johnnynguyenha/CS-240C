
# Student Manager
This Student Manager project is an interactive database system written in C. It allows users to manage student records efficiently, supporting various operations such as adding, removing, and searching for student information. The project utilizes C structs to represent students and works with binary files for persistent storage.

Features
The Student Manager project provides the following capabilities:

  Copy Database: Create a backup of the current binary file containing the student records.  
  View All Records: Output all student records stored in the database.  
  Search by ID: Retrieve and display a student's information using their unique ID number.  
  View by Position: Display the student record at a specific position in the database.  
  Add a New Student: Add a new student's details, including name, ID, major, classification, phone number, GPA, and zip code, to the database.  
  Remove a Student: Delete a student's record from the database by their ID.  

# Data Structure
The project uses a struct to store the following information about each student:

Name: Full name of the student.  
ID: Unique identification number.  
Major: The student’s field of study.  
Classification: Year or level (e.g., freshman, sophomore, etc.).  
Phone Number: Contact number.  
GPA: Current grade point average.  
Zip Code: Area code for the student's address.  

# Project Structure
final.c: Main source file containing the implementation of the student manager functions.  
student.h: Header file that declares the structures used in the project.  
students.bin: Binary file where student data is stored and retrieved from.  

# Usage
Once the program is running, you will be presented with a menu to interact with the student database. You can choose from the following options:

    C = Copy to backup file
    O = Output all student records
    F = Find and show a student by cwid number
    P = Position: show the struc data at a given position.
    M = Menu: show this menu
    N = New student will be added to the student roster file.
    R = Remove a student’s data
    X = Exit from this program.
    Please enter a selection: 

Contributions
Feel free to submit pull requests or open issues if you'd like to contribute or report any bugs!

// Johnny Nguyen
// johnnynguyenha@csu.fullerton.edu
// Today's Date: May 14, 2024


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "student.h"

void studentrecords() { //show all student records
    char selection;
    printf("\n");
    int i = 0;
    FILE *inputFile = fopen("students.bin", "rb"); //open the binary file with read permission
    Student s1;
    while (fread(&s1, sizeof(Student), 1, inputFile) == 1) {
         if (s1.id > 0){ //make sure the id is not negative
            printf("Name: %s\n", s1.name); 
            printf("ID: %d\n", s1.id);
            printf("Major: %s\n", s1.major);
            printf("Classification: %s\n", s1.classification);
            printf("Phone: %s\n", s1.phone);
            printf("GPA: %.1f\n", s1.gpa);
            printf("Zip: %d\n", s1.zip);
            printf("\n");
            printf("-------------------------------------");
            printf("\n");
            i++; //counter for the amount of records
       }
    }
    printf("%s%i%s", "Number of data records is ", i ,".");
    // Close the file
    fclose(inputFile);
    printf("%s", "\nPlease enter a selection: ");
    selection = getchar(); // loop back into the main
}
void findcwid() { //display the information of the student with the cwid inputted
    char selection;
    int input = 0;
    int flag = 0;
    printf("\n");
    FILE *inputFile = fopen("students.bin", "rb"); // open the binary file with read permission
    Student s1;
    printf("Enter the cwid of the student you want to view: ");
    scanf("%i", &input);
    while (fread(&s1, sizeof(Student), 1, inputFile) == 1) {
        if (s1.id == input) { //print the attributes of the struct
            printf("Name: %s\n", s1.name);
            printf("ID: %d\n", s1.id);
            printf("Major: %s\n", s1.major);
            printf("Classification: %s\n", s1.classification);
            printf("Phone: %s\n", s1.phone);
            printf("GPA: %.1f\n", s1.gpa);
            printf("Zip: %d\n", s1.zip);
            printf("\n");
            printf("-------------------------------------");
            printf("\n");
            flag = 1; // if we find a student with the cwid, change the flag so the code skips the next if statement
        }
    }
    if (flag == 0){ // if the flag wasnt changed, then show that the record wasn't found
        printf("%s", "\nRecord not found\n");
    }
    // Close the file
    fclose(inputFile);
    printf("%s", "\nPlease enter a selection: ");
    selection = getchar(); // loop back into the main
}
void showposition() { //display the student at the position inputted
    char selection;
    printf("\n");
    int i = 0;
    int input = 0;
    FILE *inputFile = fopen("students.bin", "rb"); // open the binary file
    Student s1;
    printf("What position do you want to view? "); 
    scanf("%i", &input); //prompt the user for the position
    printf("%s%i%s", "The data record at position ", input, " is this");
    for (int i = 0; i < input; i++) { // code to skip past the students that are before the input
        if (fread(&s1, sizeof(Student), 1, inputFile) != 1) {
            printf("Error: Unable to read file students.bin\n");
            fclose(inputFile);
            return;
        }
    }
    if (fread(&s1, sizeof(Student), 1, inputFile) != 1) {
        printf("Error: Unable to read file students.bin\n");
        fclose(inputFile);
        return;
    } //print attributes of the struct
        printf("\n");
        printf("Name: %s\n", s1.name);
        printf("ID: %d\n", s1.id);
        printf("Major: %s\n", s1.major);
        printf("Classification: %s\n", s1.classification);
        printf("Phone: %s\n", s1.phone);
        printf("GPA: %.1f\n", s1.gpa);
        printf("Zip: %d\n", s1.zip);
        printf("\n");
    // Close the file
    fclose(inputFile);
    printf("%s", "\nPlease enter a selection: ");
    selection = getchar(); // loop back into the main
}
void removestudent() { //remove a student from file using cwid
    char selection;
    int input = 0;
    int flag = 0;
    printf("\n");
    FILE *inputFile = fopen("students.bin", "r+b"); // read and write permission
    Student s1;
    printf("Enter the cwid of the student you want to remove: ");
    scanf("%i", &input);
    fseek(inputFile, 0, SEEK_SET);
    while (fread(&s1, sizeof(Student), 1, inputFile) == 1) {
        if (s1.id == input) {
            s1.id = -1; // set the cwid to a negative number
            fseek(inputFile, -sizeof(Student), SEEK_CUR); // go to where the student is
            fwrite(&s1, sizeof(Student), 1, inputFile); // write over the student
            flag = 1;
        }
    }
    if (flag == 0){ // if the student wasn't found, output
        printf("%s", "\nRecord not found\n");
    }
    // Close the file
    fclose(inputFile);
    printf("%s", "\nStudent removed.");
    printf("%s", "\nPlease enter a selection: ");
    selection = getchar(); // loop back into the main
}
void showmenu () {
    char selection; //display all options
    printf("%s", "\nPlease select one of the following options by entering the associated single character." );
    printf("%s", "\nC = Copy to backup file");
    printf("%s", "\nO = Output all student records");
    printf("%s", "\nF = Find and show a student by cwid number");
    printf("%s", "\nP = Position: show the struc data at a given position.");
    printf("%s", "\nM = Menu: show this menu");
    printf("%s", "\nN = New student will be added to the student roster file.");
    printf("%s", "\nR = Remove a student’s data");
    printf("%s", "\nX = Exit from this program.");
    printf("%s", "\nPlease enter a selection: ");
    selection = getchar(); // Consume the newline character
}
void addperson () { //function that prompts user for input to add a new person to file
    char selection;
    printf("\n");
    int i = 0;
    FILE *inputFile = fopen("students.bin", "r+b"); //open the binary file with read and write permission
    fseek(inputFile, 0, SEEK_SET);
    Student s1;
    Student s2;
    printf("\nEnter new student name: ");
    getchar(); 
    scanf(" %[^\n]", s2.name);
    printf("\nEnter new cwid: ");
    scanf("%d", &s2.id);
    printf("\nEnter new student major: ");
    getchar();
    scanf(" %[^\n]", s2.major);
    printf("\nEnter new student class level: ");
    scanf(" %s", s2.classification);
    getchar(); // consume the newline character
    printf("\nEnter new student phone: ");
    scanf(" %s", s2.phone);
    getchar(); // consume the newline character
    printf("\nEnter new student GPA: ");
    scanf(" %f", &s2.gpa);
    getchar(); // consume the newline character
    printf("\nEnter new student zip: ");
    scanf(" %i", &s2.zip);
    getchar(); // consume the newline character

    int found = 0; //flag
    fseek(inputFile, 0, SEEK_SET);
    while (fread(&s1, sizeof(Student), 1, inputFile)) { 
        if (s1.id < 0 && found == 0) { //if the id is negative and the flag is still 0, write the new student over the old one
            fseek(inputFile, -sizeof(Student), SEEK_CUR);
            fwrite(&s2, sizeof(s2), 1, inputFile);
            found = 1;
            printf("%s%i", "\nThank you. The new data was added to position ", i);
        }
        i++;
    }
    if (found == 0) { //if there is no negative id, write to the end
        fseek(inputFile, 0, SEEK_END);
        fwrite(&s2, sizeof(s2), 1, inputFile);
        printf("\nThank you. The new data was appended to the end of the data set.");
    }
    // Close the file
    fclose(inputFile);
    printf(" %s", "\nThank you, please run the program again to use other options.");
    exit(1);
}
void unknown(){ // function incase the input is not one of the options
    char selection;
    printf("\nInput unknown. Please enter again: ");
    selection = getchar();
}
void backup(){ //function to backup data to a bak file without the negative ids
    char filename[50] = "students.bin";
    char backupname[50];
    char selection;
    printf("\n");
    char *dot = strrchr(filename, '.');
    strncpy(backupname, filename, dot - filename); // need to remove the .bin from the original file
    backupname[dot - filename] = '\0';
    FILE* outputFile = fopen(strcat(backupname, ".bak"), "wb"); //open the .bin file as write to binary
    FILE *inputFile = fopen(filename, "rb"); //open the binary file with read permission
    Student s1;
    while (fread(&s1, sizeof(Student), 1, inputFile) == 1) {
        if (s1.id > 0){ //make sure the id is not negative
            fwrite(&s1, sizeof(Student), 1, outputFile);
        }
    }
    // Close the file
    fclose(inputFile);
    fclose(outputFile);
    printf ("%s%s", "The data was backed up to ", backupname);
    printf("%s", "\nPlease enter a selection: ");
    selection = getchar(); // loop back into the main  
}
int main(int argc, char* argv[]){
    char c;
    char selection;
    printf("%s", "Welcome to student roster file");
    printf("%s", "\nWe keep your records current.");
    printf("%s", "\nThis program is maintained by Johnny Nguyen,");
    printf("%s", "\nPlease select one of the following options by entering the associated single character." );
    printf("%s", "\nC = Copy to backup file");
    printf("%s", "\nO = Output all student records");
    printf("%s", "\nF = Find and show a student by cwid number");
    printf("%s", "\nP = Position: show the struc data at a given position.");
    printf("%s", "\nM = Menu: show this menu");
    printf("%s", "\nN = New student will be added to the student roster file.");
    printf("%s", "\nR = Remove a student’s data");
    printf("%s", "\nX = Exit from this program.");
    printf("%s", "\nPlease enter a selection: ");
    while ('X' != (c=getchar())) {
        switch(c){
            case 'C':
                backup();
                break;
            case 'O': //Call the function to show all student structs DONE
                studentrecords();
                break;
            case 'F': //Ask for cwid number to be inputted DONE
                    //Call the function that finds and shows one student
                findcwid();
                break;
            case 'P': //Input a position integer number DONE
                        //Call the function that go to the correct struct, reads it, displays it
                showposition();
                break;
            case 'M': //show this menu DONE
                showmenu();
                break;
            case 'N': //Declare an object of student type
                        //One by one fill the fields of that object
                        //Call fwrite to write that object at the end of the binary file
                addperson();
                break;
            case 'R': //Remove a student's data DONE
                removestudent();
                break;
            default: //Output a message that the switch variable is unknown. Try again.
                unknown();
                break;
            }// End of switch
        }//End of while
        printf("%s", "Thank you for using the Student Record System.\n");
        printf("%s", "You may use this software at any time. Bye.");
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define false 0
#define true 1
typedef unsigned char bool;



// Student's Data
typedef struct student {
    int id;
    char name[50];
    int age;
    float gpa;
} student;


// Defining a Structure to represent node in linked list

typedef struct node {
    student data;
    struct node *next;
} node;


node *head = NULL;
node *tail = NULL;


// Function to check if linked list is Empty or not

bool is_empty() {
    return head == NULL;
}


// Function to add student data into linked list

void add_student(const student * const ptr) {
    node *link = (node *)malloc(sizeof(node));

    // Checking if Memory allocation Failed
    if (link == NULL) {
        printf("Memory allocation failed\n");
        return;
    }

    node *current = head;

    
    // Checking if the Student exist
    while(current != NULL){

        if(current->data.id == ptr->id){
            printf("Error , Student is already exist\n");
            return;
        }
        current = current->next;
    }



    // Adding Student to Linked list
    link->data.id = ptr->id;
    strcpy(link->data.name, ptr->name);
    link->data.age = ptr->age;
    link->data.gpa = ptr->gpa;
    link->next = NULL;


    // Checking if Linked list is empty
    if (head == NULL && tail == NULL) {
        head = tail = link;
    }

    else {
        tail->next = link;
        tail = link;
    }
}

// Function responsible for getting Student data from User

void process_data() {
    student st; // Local student variable

    // Getting ID from user
    printf("Enter Student ID: ");
    scanf("%d", &st.id);

    // Clear the input buffer
    while (getchar() != '\n');

    // Getting name
    printf("Enter name: ");
    scanf("%s" , &st.name);

    // Getting age
    printf("Enter age: ");
    scanf("%d", &st.age);

    // Getting GPA
    printf("Enter GPA: ");
    scanf("%f", &st.gpa);

    add_student(&st);
}


// Function to Print all the Students in Linked list

void Display_Students(){

    // Checking if linked list is empty;
    if(is_empty()){
        printf("No Students\n");
        return;
    }

    node * current = head;

    while(current != NULL){

        printf("[ ID : %d , Name : %s , Age : %d , GPA : %.2f ]\n" , current->data.id , current->data.name , current->data.age, current->data.gpa);
        current = current->next;
    }

}


// Function that Search the Student Data by his ID

void Search_by_id(int id){
    node *current = head;


    if(is_empty()){
        printf("No Students\n");
        return ;
    }

    while(current != NULL){

        if(current->data.id == id){
            printf("Student found :\n");
            printf("ID : %d , Name : %s , Age : %d , GPA : %.2f \n" , current->data.id , current->data.name , current->data.age, current->data.gpa);
            return ;
        }
        current = current -> next;
    }

    printf("Student with ID %d Not Found\n" , id);

}


// Function that Update Student Data by his ID

void Update_Student(int id){

    if(is_empty()){
        printf("No Students\n");
        return ;
    }

    node *current = head;

    while(current != NULL){
        if(current->data.id == id){
            printf("-----------------------------------------------------\n");
            printf("Enter new details for the student with ID %d : ", id);

            printf("Enter new name : ");
            scanf("%s", &current->data.name);

            printf("Enter new age : ");
            scanf("%d" , &current->data.age);

            printf("Enter new GPA : ");
            scanf("%f" , &current->data.gpa);

            printf("Student details updated successfully .\n");

            return;
        }
        current = current->next;
    }

    printf("Student not found\n");

}


// Function to delete student from linked list  by his id
void delete_student(int id) {
    if (is_empty()) {
        printf("No Students\n");
        return;
    }

    node *current = head;
    node *previous = NULL;

    while (current != NULL) {
        if (current->data.id == id) {
            if (previous == NULL) {
                head = current->next;
            } else {
                previous->next = current->next;
            }
            if (current == tail) {
                tail = previous;
            }
            free(current);
            printf("Student with ID %d deleted successfully\n", id);
            return;
        }
        previous = current;
        current = current->next;
    }

    printf("Student with ID %d not found\n", id);
}


// Function Responsible for Calculating the Average GPA of all Students

float Calculate_Average_GPA(){

    node*current = head;

    float sum = 0;
    int number_of_students = 0;

    if(is_empty()){
        printf("No Students\n");
        return 0.0;
    }

    while(current != NULL){
        sum += current->data.gpa;
        current = current->next;
        number_of_students++;
    }

    return sum / number_of_students;
}


// Function responsible for Searching student with highest GPA

void Search_Highest_GPA(){

    node *current = head;

    if(is_empty()){
        printf("No Students\n");
        return ;
    }

    node *ptr = NULL;

    float max_gpa = 0;

    while(current != NULL){

        if(current->data.gpa > max_gpa){
            max_gpa = current->data.gpa;
            ptr = current;
        }

        current = current->next;
    }

    printf("Student With highest GPA : \n");
    printf("[ ID : %d , Name : %s , Age : %d , GPA : %.2f ] \n" , ptr->data.id , ptr->data.name , ptr->data.age, ptr->data.gpa);

}


int main() {

    setvbuf(stdout, NULL, _IONBF, 0);
    setvbuf(stderr, NULL, _IONBF, 0);

    int choice;

    while (true) {
        printf("-----------------------------------------------------\n");
        printf("1. Add Student\n");
        printf("2. Display Students\n");
        printf("3. Search Student by ID\n");
        printf("4. Update Student Information\n");
        printf("5. Delete Student\n");
        printf("6. Calculate Average GPA\n");
        printf("7. Search for Student with Highest GPA\n");
        printf("8. Exit\n");
        printf("Enter Choice: ");
        scanf("%d", &choice);
        printf("-----------------------------------------------------\n");

        
        // Switch Statement to make user Choose from the function
        
        switch (choice) {
            case 1:
                process_data();
                break;
            case 2 :
                Display_Students();
                break;

            case 3 :
                int required_id;
                printf("Enter Student ID to search : ");
                scanf("%d",&required_id);
                printf("\n");
                Search_by_id(required_id);
                break;

            case 4 :
                int req_id;
                printf("Enter Student ID to update it's information : ");
                scanf("%d" , &req_id);
                printf("\n");
                Update_Student(req_id);
                break;

            case 5:
                int del_id;
                printf("Enter Student ID to Delete it's Data : ");
                scanf("%d" , &del_id);
                delete_student(del_id);
                break;

            case  6:
                float result = Calculate_Average_GPA();
                printf("Average GPA : %f\n" , result);
                break;
            case 7 :
                Search_Highest_GPA();
                break;
            case 8:
                return 0;
        }
    }
}

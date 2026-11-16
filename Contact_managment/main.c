#include <stdio.h>
#include <stdbool.h>
#include <string.h>

struct contact {
    char name[50] ;
    char phone[20];
    int age;
};

void listContact(struct contact *contacts , int length){
    int i = 0 ;
    while (i < length){

        printf("name : %s \n" ,contacts[i].name);
        printf("phone : %s \n",contacts[i].phone);
        printf("age : %d \n",contacts[i].age);
        i++ ;
    };
    
}

void addContact(struct contact *contacts, int *length){
    if (*length < 5){
        printf("please specify users name : ");
        scanf("%49s",contacts[*length].name); 
        printf("please specify users phone number : ");
        scanf("%19s",contacts[*length].phone);
        while (1)
        {
            printf("please specify users age : ");
            if (scanf("%d", &contacts[*length].age) != 1){
                printf("Please enter the age as a number.\n");
                int ch;
                while ((ch = getchar()) != '\n' && ch != EOF) {
                }
                
            }else if (contacts[*length].age >= 18 && contacts[*length].age <= 120)
            {
                break;
            }else{
                printf("Please enter an age between 18 and 120.\n");
            }
        }
        (*length) ++;
    }else{
        printf("We are sorry, the contact list is full.\n");
    }
}

void searchContact(struct contact *contacts, int length){
    char search[50];
    int i = 0 ;
    printf("welcome to our simple fileter where you can search for contact by name\n");
    printf("please enter the name of the contact :");
    scanf("%49s", search);
    while (i < length){
        if (strcmp(contacts[i].name, search) == 0){
            printf("==========\n");
            printf("name : %s \n" ,contacts[i].name);
            printf("phone : %s \n",contacts[i].phone);
            printf("age : %d \n",contacts[i].age);

            return;
        }
        i++;
    }
    printf("no contact found with the name %s\n" , search);
}


void deleteContact(struct contact *contacts, int *length){
    char search[50];
    int i = 0 ;
    printf("please enter the name of the contact you want to delte \n");
    scanf("%49s", search);
    while (i < *length){
        if (strcmp(contacts[i].name, search) == 0){
            int b = i;
           while (b < *length - 1) {
                contacts[b] = contacts[b + 1];
                b++;
            }
           printf("contact deleted\n");
           (*length) --;
           return;
        }
        i++;
    }
    printf("no contact found with the name %s\n" , search);
}

int main()
{
    int length = 4;
    struct contact contacts[5];
    int choice;

    strcpy(contacts[0].name, "Alice");
    strcpy(contacts[0].phone, "041395655");
    contacts[0].age = 23;

    strcpy(contacts[1].name, "Khatchig");
    strcpy(contacts[1].phone, "091234567");
    contacts[1].age = 24;

    strcpy(contacts[2].name, "David");
    strcpy(contacts[2].phone, "077654321");
    contacts[2].age = 31;

    strcpy(contacts[3].name, "Anna");
    strcpy(contacts[3].phone, "055123456");
    contacts[3].age = 28;

    do{
        printf("===== CONTACT MANAGEMENT =====\n");
        printf("1. List contacts\n");
        printf("2. Add contact\n");
        printf("3. Search contact\n");
        printf("4. Delete contact\n");
        printf("5. Exit\n");
        printf("\n");
        printf("Choose an option: ");
        scanf("%d", &choice);
        switch (choice)
        {
            case 1:
                listContact(contacts, length);
                break;
            case 2:
                addContact(contacts, &length);
                break;
            case 3:
                searchContact(contacts, length);
                break;
            case 4:
                deleteContact (contacts, &length);
                break;
            case 5:
                break;
        default:
            printf("option is not valid please enter the options number :");

        }
    }while (choice != 5);
    return 0;
}
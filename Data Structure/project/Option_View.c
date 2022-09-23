#include "../FUN_DEC/prototypes.h"
#include "stdio.h"

void View (){
    
u8_t choose ;

printf("Add student : 1\n");
printf("Delete student : 2\n");    
printf("Get IDs List : 3\n");
printf("Get the number of students : 4\n");
printf("check if database is full : 5\n");
printf("check if ID is Exist : 6\n");
printf("Show the data of ID : 7\n");

printf("choose your option : ");
scanf("%d",&choose);
printf("\n");

switch (choose)
{

case 1 :
    printf("Enter ID : ");
    scanf("%d",&ID);
    printf("Enter Year : ");
    scanf("%d",&Year);
    for (u8_t i =0 ; i<3 ;i++)
    {
        printf("Enter Course %d ID : ", i+1);
        scanf(" %d", &Course[i]);
        
    }
     for (u8_t i =0 ; i<3 ;i++)
    {
        printf("Enter Course %d grade : ",Course[i]);
        scanf(" %d", &Grades[i]);    
    }
        printf("\n");
    if (SDB_AddEntry(ID,Year,Course,Grades) == 1)
    {
        printf("Entry Added successfully\n\n");
    }
    else{
        printf("Error ! Entry could not be added \n\n");
    }
    printf("\n");
    break;

case 2 :
    printf("Enter ID : ");
    scanf("%d",&ID);
    SDB_DeleteEntry(ID);
    break;

case 3 :
    printf("IDs List :\n");
    SDB_GetIdList(&NO_IDs,ID_List);
    for (u8_t j = 0; j < NO_IDs; j++)
    {
        printf("%d\n",ID_List[j]);
    }
    printf("\n");
    printf("NO.IDs : %d\n",NO_IDs);
    break;

case 4 :
    printf("Number of Entries : %d",SDB_GetUsedSize());
    printf("\n\n");
    break;    

case 5 :
    if ( SDB_IsFull() == 1 )
    {
        printf("DataBase is Full !\n\n");
    }
    else{
        printf("DataBase is Not Full !\n\n");
    }
    break;    

case 6 :
    printf("Enter ID : ");
    scanf("%d",&ID);
    if ( SDB_IsIdExist(ID) ==  1 )
    {
        printf("ID does Exist\n\n");
    }
    else{
        printf("ID does not Exist\n\n");
    }
    break;    

case 7 :
    printf("Enter ID : ");
    scanf("%d",&ID);
    
    if (SDB_ReadEntry(ID,&Year,Course,Grades) == 1)
    {
        printf("ID : %d\n",ID);
        printf("year : %d\n",Year);

        for (u8_t k = 0; k < 3; k++)
        {
            printf("Subject %d : %d\n",k+1 , Course[k] );
            printf("Grade : %d\n", Grades[k] );
        }
        printf("\n\n");
    }
    else{
        printf("ID does not exist !\n\n");
    }
    break;    
default:
    printf("Invalid choise ! \n\n");
     View();
    break;
}

    return ;
}
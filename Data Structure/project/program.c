#include "stdio.h"
#include "../FUN_DEC/prototypes.h"

entry_t database[10];
bool flag  ;
entry_t *Push_ptr = database ;

u8_t ID_List[10]  ;
u8_t ID ;
u8_t NO_IDs = 0 ;
u8_t Year  ;
u8_t Course[3] = {101,102,103};
u8_t Grades[3] = {10,20,100};

int main (void)
{
    u8_t x ; 

while (1)
{
View();
printf("\n\n contiue : 1 \n Exit : 0\n");
scanf("%d",&x);
if (x == 1)
{
    continue;
}
else if (x == 0)
{
    break;
}
else {
     printf("\n");
     printf("Invalid choise ! \n\n");
     View();
     continue;
}
}
    return 0 ;
}

#include "stdio.h"

void SDB_DeleteEntry(u8_t id){

entry_t *Del_ptr=NULL ;
entry_t *Next_ptr=NULL ;

for (u8_t i = 0; i < 10; i++)
{
    if (database[i].Student_ID == id )
    {
        Del_ptr =&database[i];
        break;
    }
}

        while (Del_ptr <= &database[9])
        {
            if (Del_ptr == &database[9])
            {
                Del_ptr->Student_ID = 0;
                break;
            }
            else{
                
                Next_ptr = Del_ptr+1;
                Del_ptr->Student_ID = Next_ptr->Student_ID ;
                Del_ptr->Student_Year = Next_ptr->Student_Year ;
                for (u8_t j = 0; j < 3; j++)
                {
                    Del_ptr->Student_Course[j]= Next_ptr->Student_Course[j];
                    Del_ptr->Student_Grade[j]= Next_ptr->Student_Grade[j];
                }

            Del_ptr++ ;
            Del_ptr->Student_ID = 0 ;
            }
        }

return ;
}

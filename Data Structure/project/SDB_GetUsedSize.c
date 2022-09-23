
u8_t SDB_GetUsedSize(void){

u8_t counter = 0 ;
entry_t *ptr = database ;
while (ptr->Student_ID !=0 && ptr<= &database[9])
{
    counter++ ;
    ptr ++ ;
}

return counter ;
}

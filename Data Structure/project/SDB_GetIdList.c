
void SDB_GetIdList(u8_t *count , u8_t* list){

entry_t *Get_ptr = database ;
u8_t i = 0 ;
while (Get_ptr->Student_ID !=0 && Get_ptr <= &database[9] )
{
    list[i] = Get_ptr->Student_ID ;
    Get_ptr ++ ;
    i++ ;
    *count = i ;
}

return ;
}
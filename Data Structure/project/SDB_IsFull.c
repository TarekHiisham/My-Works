
bool SDB_IsFull (void){

entry_t *search_ptr = database ;
while ( search_ptr->Student_ID != 0 )
{
    if (search_ptr == &database[9])
    {
        flag = TRUE ;
        break;
    }
    else{
        flag = FALSE ;
        search_ptr++ ;
    }
}



return flag ;
}
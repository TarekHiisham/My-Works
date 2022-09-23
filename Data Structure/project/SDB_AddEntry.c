
bool SDB_AddEntry (u8_t id ,u8_t year , u8_t*subject ,u8_t*grades)
{
 Push_ptr = database ;
if (Push_ptr >= &database[0] && Push_ptr <= &database[9])
{
    while ( Push_ptr->Student_ID != 0 )
    {
        Push_ptr ++ ;
    }
    
    for( u8_t i=0 ; i<3 ;i++ )
    {
        if ( grades[i]>=0 && grades[i]<=100 )
        {
            flag = TRUE ;
        }
        else
        {
            flag = FALSE ;
            break;
        }
    }
    if (flag == TRUE)
    {
        Push_ptr->Student_ID = id ;
        Push_ptr->Student_Year = year ;
        for (u8_t j= 0; j<3; j++)
        {
            Push_ptr->Student_Course[j] = subject[j] ;
            Push_ptr->Student_Grade[j] = grades[j] ;
        }

    }
    else{
        flag = FALSE ;
    }
}

else{
    flag = FALSE ;
}

return flag  ;
}
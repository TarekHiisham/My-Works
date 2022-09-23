
bool SDB_IsIdExist(u8_t ID){

for (u8_t i = 0; i < 10; i++)
{
  if (database[i].Student_ID == ID)
  {
    flag = TRUE ;
    break;
  }

  else if (i == 9)
  {
    flag = FALSE ;
    break;
  }
  else{
    /*Do Nothing*/
  }
  
}

return flag ;
}








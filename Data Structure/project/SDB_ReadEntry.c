
bool SDB_ReadEntry(u8_t id ,u8_t *year ,u8_t *subject ,u8_t *grades){

u8_t i =0 ;

for (i = 0; i < 10; i++)
{
  if (database[i].Student_ID == id)
  {
    flag = TRUE ;
    break;
  }

  else if (i == 9)
  {
    flag = FALSE ;
    break;
  }
}
  
if (flag == 1 )
{
  (*year) = database[i].Student_Year ;
  for (u8_t j = 0; j < 3; j++)
  {
      subject[j]= database[i].Student_Course[j] ;
      grades[j] = database[i].Student_Grade[j] ;
  }
}
else 
{
  flag = FALSE ;
}
        
return flag;
}
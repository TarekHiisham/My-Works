#include "LSTD_TYPES.h"
#include "LBIT_MATH.h"
#include "HLCD_interface.h"
#include "HKPD_interface.h"
#include "stdlib.h"
#include "avr/io.h"
#include "util/delay.h"

#define NUMBER_OF_DIGITS        (2)
#define AVAILBLE_NUMBER         (2)
#define RESULT_DIGITS           (4)

typedef struct 
{
   u8_t Num_Str[3];

}NUM_info;

/*Array of availible numbers that can do operation on them*/
NUM_info NUM_Arr[AVAILBLE_NUMBER] ;


    u8_t button ;
    u8_t i = 0 ;
    u8_t j = 0 ;
    u8_t operation ;
    u8_t Result_str[RESULT_DIGITS] ;

/**
 * @brief this function get the two numbers and the operation that will be done on them
 * 
 */
void Getoperation(void);

/**
 * @brief this function execute the operation  
 * 
 */
void DOoperation(void);

/**
 * @brief this function reset all variables to default 
 * 
 */
void Reset(void);


void Reset(void)
{
  i = 0 ;
  j = 0 ;

  for (u8_t l = 0; l < 4; l++)
  {
    Result_str[l]=0 ;
  }
 
  for (u8_t k = 0; k < 2; k++)
  {
    for (u8_t c = 0; c < 2; c++)
    {
        NUM_Arr[k].Num_Str[c]= 0 ;
    }
  }
  
  return ;
}

void Getoperation(void)
{   
        hkpd_getPressedButton(&button);
 
    /*checking on button that pressed*/

    if (button == 'O')
    {
        /* O button reset calculator to take new operation*/
        hlcd_cleardisplay();
        Reset();
    }


    else if (button == '=')
    {
        /*move cursor to new line*/
        hlcd_displayPosition(LCD_ROW_1 , LCD_COL_12);

        /*calling do function to execute the operation*/
        DOoperation();

        /*reset all variables*/
        Reset();
    }

    else if (button == '+' ||button == '-' ||button == 'x' ||button == '/' )
    {
        hlcd_displayCharacter(button);
        operation = button ;
        i++ ;
        j = 0 ;
    }

    else if(button != 0)
    {
        hlcd_displayCharacter(button);
        /*store the character represent number*/
        NUM_Arr[i].Num_Str[j] = button;
        j++ ;
    } 

    else
    {
        /*Do Nothing*/
    }

    _delay_ms(100);
    
    return ;
}

void DOoperation(void)
{
    switch (operation)
    {
    case '+':
      itoa(ADD_NUMS(atoi(NUM_Arr[0].Num_Str) , atoi(NUM_Arr[1].Num_Str)) ,Result_str,10) ;
    break;

    case '-':
        itoa(SUB_NUMS(atoi(NUM_Arr[0].Num_Str) , atoi(NUM_Arr[1].Num_Str)) ,Result_str,10) ;
    break;

    case 'x':
        itoa(MUL_NUMS(atoi(NUM_Arr[0].Num_Str) , atoi(NUM_Arr[1].Num_Str)) ,Result_str,10) ;
    break;

    case '/':
        itoa(DIV_NUMS(atoi(NUM_Arr[0].Num_Str) , atoi(NUM_Arr[1].Num_Str)) ,Result_str,10) ;
    break;
    
    default:
        break;
    }
        hlcd_displayString((u8_t*)Result_str);
    return ;
}

int main(void)
{ 
    hkpd_init();
    hlcd_init();
while (1)
{
    Getoperation();   
}

return 0;
}
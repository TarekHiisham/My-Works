#ifndef TYPEDEFS
#define TYPEDEFS

typedef unsigned char u8_t;
typedef unsigned short int u16_t;
typedef unsigned long int u32_t;

typedef signed char s8_t;
typedef signed short int s16_t;
typedef signed long int s32_t;

typedef float f32_t;
typedef double f64_t;

typedef struct 
{
    u8_t Student_ID ;
    u8_t Student_Year ;
    u8_t Student_Course[3];
    u8_t Student_Grade[3];

}entry_t;

typedef enum {
   FALSE,
   TRUE
}bool;

extern entry_t database[10];
extern bool flag ;
extern entry_t *Push_ptr ;

extern u8_t ID ;
extern u8_t ID_List[10]  ;
extern u8_t Year ;
extern u8_t NO_IDs ;
extern u8_t Course[3]  ;
extern u8_t Grades[3]  ;




#endif
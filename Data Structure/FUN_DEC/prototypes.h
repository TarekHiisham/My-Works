#ifndef __Prototypes_t
#define __Prototypes_t

#include "../LIB/typedef.h"

bool SDB_AddEntry (u8_t id ,u8_t year , u8_t*subject ,u8_t*grades);
bool SDB_ReadEntry(u8_t id ,u8_t *year ,u8_t*subject ,u8_t *grades);
void SDB_DeleteEntry(u8_t id);
void SDB_GetIdList(u8_t *count , u8_t* list);
bool SDB_IsFull (void);
bool SDB_IsIdExist(u8_t ID);
u8_t SDB_GetUsedSize(void);

void View ();



#endif

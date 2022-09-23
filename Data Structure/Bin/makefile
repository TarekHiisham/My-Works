
COMPILER := gcc

C_FILES := ../Project/program.c
C_FILES += ../Project/SDB_AddEntry.c
C_FILES += ../Project/SDB_DeleteEntry.c
C_FILES += ../Project/SDB_GetIdList.c
C_FILES += ../Project/SDB_GetUsedSize.c
C_FILES += ../Project/SDB_IsFull.c
C_FILES += ../Project/SDB_IsIdExist.c
C_FILES += ../Project/SDB_ReadEntry.c
C_FILES += ../Project/Option_View.c


O_FILES := program.o
O_FILES += SDB_AddEntry.o
O_FILES += SDB_DeleteEntry.o
O_FILES += SDB_GetIdList.o
O_FILES += SDB_GetUsedSize.o
O_FILES += SDB_IsFull.o
O_FILES += SDB_IsIdExist.o
O_FILES += SDB_ReadEntry.o
O_FILES += Option_View.o

EXE_FILES := program.exe

all: clean linking

build: $(C_FILES)
	@$(COMPILER) -c $(C_FILES) 
linking: build 	
	@$(COMPILER) $(O_FILES) -o $(EXE_FILES)
clean:
	rm -rf *.o *.exe		



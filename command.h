#ifndef COMMAND_H_INCLUDED
#define COMMAND_H_INCLUDED

#include <stdbool.h>

#define COMMAND_NAME_SIZE 64
#define COMMAND_VALUE_SIZE 128
#define COMMAND_LIST_INITIAL_SIZE 16

/////////////////////////////////////////////////////////////

typedef struct {
    char name[COMMAND_NAME_SIZE + 1];
    char value[COMMAND_VALUE_SIZE + 1];
} Command;

typedef struct {
    int size;
    int cap;
    Command* commands;
} CommandList;

////////////////////////////////////////////////////////////


Command* command_create(char name[], char value[]);
void command_destroy(Command* target);
bool command_equals(Command* a, Command* b);

////////////////////////////////////////////////////////////

CommandList* command_list_create();
CommandList* command_list_create_with_size(int size);
void command_list_destroy(CommandList* list);
void command_list_add(CommandList* list, Command* cmd);
bool command_list_remove(CommandList* list, Command* target);
bool command_list_remove_by_name(CommandList* list, char name[]);
bool command_list_contains(CommandList* list, char name[]);
Command* command_list_find_by_name(CommandList* list, char name[]);
void command_list_clear(CommandList* list);


#endif // COMMAND_H_INCLUDED

#include "command.h"
#include "types.h"
#include "strutils.h"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>


/////////////////////////////////////////////////////////////////////////////


Command* command_create(char name[], char value[]) {
    Command* command = (Command*) malloc(sizeof(Command));
    memset(command, 0, sizeof(Command));
    strncpy(command->name, name, COMMAND_NAME_SIZE);
    strncpy(command->value, value, COMMAND_VALUE_SIZE);
    return command;
}

void command_destroy(Command* target) {
    free(target);
}

bool command_equals(Command* a, Command* b) {
    int comp1 = strncmp(a->name, b->name, COMMAND_NAME_SIZE);
    int comp2 = strncmp(a->value, b->value, COMMAND_VALUE_SIZE);
    return comp1 == 0 && comp2 == 0;
}


/////////////////////////////////////////////////////////////////////////////


CommandList* command_list_create() {
    CommandList* list = (CommandList*) malloc(sizeof(CommandList));
    list->size = 0;
    list->cap = COMMAND_LIST_INITIAL_SIZE;
    list->commands = (Command*) malloc(sizeof(Command) * list->cap);
    memset(list->commands, 0, sizeof(Command) * list->cap);
    return list;
}

CommandList* command_list_create_with_size(int size) {
    CommandList* list = (CommandList*) malloc(sizeof(CommandList));
    list->size = 0;
    list->cap = size;
    list->commands = (Command*) malloc(sizeof(Command) * list->cap);
    memset(list->commands, 0, sizeof(Command) * list->cap);
    return list;
}

void command_list_destroy(CommandList* list) {
    free(list->commands);
    free(list);
}

void command_list_grow(CommandList* list) {
    int newCap = list->cap << 1;
    Command* bigger = (Command*) realloc(list->commands, sizeof(Command) * newCap);
    list->commands = bigger;
    list->cap = newCap;
}

void command_list_add(CommandList* list, Command* cmd) {
    if (list->size == list->cap)
        command_list_grow(list);
    list->commands[list->size++] = *cmd;
}

void command_list_shrink(CommandList* list) {
    int newCap = list->cap >> 1;
    Command* smaller = (Command*) realloc(list->commands, sizeof(Command) * newCap);
    list->commands = smaller;
    list->cap = newCap;
}

bool command_list_remove(CommandList* list, Command* target) {
    int index = -1;
    for (int i = 0; i < list->size; i++) {
        if (command_equals(target, &list->commands[i])) {
            index = i;
            break;
        }
    }

    if (index == -1)
        return false;

    for (int i = 0, j = 0; i < list->size;) {
        if (i == index) {
            i++;
            continue;
        }

        if (i == j) {
            i++;
            j++;
            continue;
        }

        list->commands[j++] = list->commands[i++];
    }

    list->size--;
    memset(list->commands + list->size, 0, sizeof(Command));

    if (list->size < list->cap >> 1) {
        command_list_shrink(list);
    }

    return true;
}

bool command_list_remove_by_name(CommandList* list, char name[]) {
    Command* c = command_list_find_by_name(list, name);
    if (c == NULL) {
        return false;
    }
    return command_list_remove(list, c);
}

bool command_list_contains(CommandList* list, char name[]) {
    if (list->size == 0) {
        return false;
    }

    for (int i = 0; i < list->size; i++) {
        if (str_equals_ignore_case(name, list->commands[i].name, COMMAND_NAME_SIZE)) {
            return true;
        }
    }

    return false;
}

Command* command_list_find_by_name(CommandList* list, char name[]) {
    for (int i = 0; i < list->size; i++) {
        if (str_equals_ignore_case(list->commands[i].name, name, COMMAND_NAME_SIZE)) {
            return &list->commands[i];
        }
    }

    return NULL;
}

void command_list_clear(CommandList* list) {
    list->size = 0;
    memset(list->commands, 0, sizeof(Command) * list->cap);
}

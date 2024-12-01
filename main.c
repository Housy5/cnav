#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "command.h"
#include "fileio.h"
#include "strutils.h"

bool is_valid_name(char name[]) {
    if (str_equals_ignore_case(name, "-help", 5))
        return false;
    if (str_equals_ignore_case(name, "-add", 4))
        return false;
    if (str_equals_ignore_case(name, "-rem", 4))
        return false;
    if (str_equals_ignore_case(name, "-print", 6))
        return false;
    if (str_equals_ignore_case(name, "-clear", 6))
        return false;
    return true;
}

int main(int argc, char* argv[]) {
    if (argc == 1)
        return 0;

    CommandList* list = fileio_read_command_list();

    if (argc == 2 && str_equals_ignore_case(argv[1], "-help", 5)) {
        puts("cnav Help");
        puts("- cnav -help               Show help.");
        puts("- cnav -add {alias} {cmd}  Add an alias.");
        puts("- cnav -rem {alias}        Remove an alias.");
        puts("- cnav -print              List all aliases.");
        puts("- cnav -clear              Clears all commands.");
        puts("- cnav {alias}             Run the alias command.");
        goto exit;
    }

    //program -add name value
    if (argc == 4 && str_equals_ignore_case(argv[1], "-add", 4)) {
        if (!is_valid_name(argv[2])) {
            printf("%s is a reserved command and cannot be used as an alias.\n", argv[2]);
            goto exit;
        }

        if (command_list_contains(list, argv[2])) {
            perror("This command already exists!");
            goto exit;
        }

        Command* new_command = command_create(argv[2], argv[3]);
        command_list_add(list, new_command);
        command_destroy(new_command);
        goto exit;
    }

    //program -print
    if (argc == 2 && str_equals_ignore_case(argv[1], "-print", 6)) {
        if (list->size == 0) {
            puts("There currently are no commands!");
            goto exit;
        }

        puts("Commands:");
        for (int i = 0; i < list->size; i++) {
            printf("Name: %32s, Value: %32s\n", list->commands[i].name, list->commands[i].value);
        }

        goto exit;
    }

    if (argc == 3 && str_equals_ignore_case(argv[1], "-rem", 4)) {
        if (command_list_remove_by_name(list, argv[2])) {
            puts("Command successfully removed.");
        } else {
            puts("Couldn't find the specified command.");
        }
        goto exit;
    }

    if(argc == 2 && str_equals_ignore_case(argv[1], "-clear", 6)) {
        printf("Are you sure you want to clear everything? (can't be undone) (y/n)\nInput: ");
        char confirm = getc(stdin);
        if (confirm != 'y') {
            goto exit;
        }

        command_list_clear(list);
        goto exit;
    }

    if (argc == 2 && command_list_contains(list, argv[1])) {
        Command* c = command_list_find_by_name(list, argv[1]);
        if (c == NULL) {
            perror("Couldn't find the specified command!");
            goto exit;
        }
        system(c->value);
        goto exit;
    }

    printf("Alias '%s' not found.\nUse '-help' to see available commands.\n", argv[1]);

exit:
    fileio_write_command_list(list);
    free(list);
}

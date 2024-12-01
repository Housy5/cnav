#ifndef FILEIO_H_INCLUDED
#define FILEIO_H_INCLUDED

#include "command.h"
#include <stdbool.h>
#define SAVE_FILE "commands.bin"

void fileio_write_command_list(CommandList* list);
CommandList* fileio_read_command_list();

#endif // FILEIO_H_INCLUDED

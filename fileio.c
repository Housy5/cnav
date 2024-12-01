#include "fileio.h"
#include "types.h"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void fileio_write_command_list(CommandList* list) {
    FILE* file = fopen(SAVE_FILE, "wb");

    if (file == NULL) {
        perror("Saving failed.");
        return;
    }

    int total_size = sizeof(int) * 2 + sizeof(Command) * list->cap;
    byte data[total_size];

    memcpy(data, (byte*) &list->size, sizeof(int));
    memcpy(data + sizeof(int), (byte*) &list->cap, sizeof(int));
    memcpy(data + (sizeof(int) << 1), (byte*) list->commands, sizeof(Command) * list->cap);

    fwrite(data, sizeof(byte), total_size, file);
    fclose(file);
}

CommandList* fileio_read_command_list() {
    FILE* file = fopen(SAVE_FILE, "rb");

    if (file == NULL) {
        return command_list_create();
    }

    fseek(file, 0, SEEK_END);
    int file_len = ftell(file);
    rewind(file);

    byte buffer[file_len];
    fread(buffer,  file_len, 1, file);
    fclose(file);

    int c_size = ((int*) buffer)[0];
    int c_cap = ((int*) buffer)[1];

    CommandList* list = command_list_create_with_size(c_cap);
    list->size = c_size;

    memcpy((byte*) list->commands, buffer + sizeof(int) * 2, sizeof(Command) * c_cap);

    return list;
}

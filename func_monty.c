#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "monty.h"

#define MAX_LINE_LENGTH 1000

void read_file(char *filename, stack_t **stack)
{
    char buffer[MAX_LINE_LENGTH];
    char *line;
    int line_count = 1;
    instruct_func s;
    int check;
    FILE *file = fopen(filename, "r");

    if (file == NULL)
    {
        printf("Error: Can't open file %s\n", filename);
        error_exit(stack);
    }

    while (fgets(buffer, sizeof(buffer), file) != NULL)
    {
        line = parse_line(buffer);
        if (line == NULL || line[0] == '#')
        {
            line_count++;
            continue;
        }
        s = get_op_func(line);
        if (s == NULL)
        {
            printf("L%d: unknown instruction %s\n", line_count, line);
            error_exit(stack);
        }
        s(stack, line_count);
        line_count++;
    }

    check = fclose(file);
    if (check == -1)
        exit(-1);
}

char *parse_line(char *line)
{
    char *op_code;

    op_code = strtok(line, " \t\n");
    if (op_code == NULL)
        return NULL;
    return op_code;
}


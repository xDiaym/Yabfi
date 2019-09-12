#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#define STACK_SIZE (30000)

static char stack[STACK_SIZE] = {0};

static size_t get_file_size(FILE *fp)
{
    fseek(fp, 0L, SEEK_END);
    size_t size = ftell(fp);
    fseek(fp, 0L, SEEK_SET);
    return size;
}

static char *read_content(const char *filename)
{
    char *buffer;

    FILE *fp = fopen(filename, "r");
    if (fp == NULL)
        exit(EXIT_FAILURE);

    size_t file_size = get_file_size(fp);

    buffer = (char *)calloc(file_size, sizeof(char));
    if (buffer == NULL)
        exit(EXIT_FAILURE);

    fread(buffer, sizeof(char), file_size, fp);

    fclose(fp);

    return buffer;
}

void interpreter(char *program)
{
    size_t op_num = -1, cell_num = 0;
    char operator;

    while ((operator= program[++op_num]) != '\0')
    {
        switch (operator)
        {
        case '+':
        {
            ++stack[cell_num];
            break;
        }

        case '-':
        {
            --stack[cell_num];
            break;
        }

        case '>':
        {
            assert(cell_num < STACK_SIZE);
            cell_num++;
            break;
        }

        case '<':
        {
            assert(cell_num >= 0);
            --cell_num;
            break;
        }

        case '.':
        {
            putchar(stack[cell_num]);
            break;
        }

        case ',':
        {
            stack[cell_num] = getchar();
            break;
        }

        case '[':
        {
            unsigned long nesting_level = 1;

            if (stack[cell_num] == 0)
            {
                while (nesting_level > 0)
                {
                    operator= program[++op_num];
                    if (operator== ']')
                    {
                        --nesting_level;
                    }
                    else if (operator== '[')
                    {
                        ++nesting_level;
                    }
                }
            }
            break;
        }

        case ']':
        {
            unsigned long nesting_level = 1;

            if (stack[cell_num] != 0)
            {
                while (nesting_level > 0)
                {
                    operator= program[--op_num];
                    if (operator== ']')
                    {
                        ++nesting_level;
                    }
                    else if (operator== '[')
                    {
                        --nesting_level;
                    }
                }
            }
            break;
        }

        default:
            break;
        }
    }
}

int main(int argc, char *argv[])
{
    if (argc == 1)
    	return EXIT_FAILURE;

    char *c = read_content(argc[1]);
    interpreter(c);

    system("pause");
    return 0;
}
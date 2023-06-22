#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

void changeCase(FILE *source, FILE *destination, int option) {
    char c;
    while ((c = fgetc(source)) != EOF) {
        if (option == 1)
            c = toupper(c);
        else if (option == 2)
            c = tolower(c);
        else if (option == 3)
            c = islower(c) ? toupper(c) : c;

        fputc(c, destination);
    }
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Usage: %s [-u | -l | -s] source_file destination_file\n", argv[0]);
        return 1;
    }

    FILE *source = fopen(argv[2], "r");
    if (source == NULL) {
        printf("Unable to open source file.\n");
        return 1;
    }

    FILE *destination = fopen(argv[3], "w");
    if (destination == NULL) {
        printf("Unable to create destination file.\n");
        fclose(source);
        return 1;
    }

    int option = 0;
    if (argc > 3) {
        if (argv[1][0] == '-') {
            switch (argv[1][1]) {
                case 'u':
                    option = 1;
                    break;
                case 'l':
                    option = 2;
                    break;
                case 's':
                    option = 3;
                    break;
                default:
                    printf("Invalid option.\n");
                    fclose(source);
                    fclose(destination);
                    return 1;
            }
        } else {
            printf("Invalid option.\n");
            fclose(source);
            fclose(destination);
            return 1;
        }
    }

    changeCase(source, destination, option);

    fclose(source);
    fclose(destination);

    printf("File copied successfully.\n");

    return 0;
}

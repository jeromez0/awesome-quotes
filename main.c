#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>


int file_read(char* argv) {

    int fdes;
    char buffer[1];
    int r;

    fdes = open(argv, O_RDONLY);
    if (fdes == -1) {
        fprintf(stderr, "Unable to open %s\n", argv);
        return(1);
    }

    while(1) {
        r = read(fdes, buffer, 1);
        if (r == 0) 
            break;
        if (r == -1) {
            fprintf(stderr,"File read error\n");
            break;
        }
        putchar(buffer[0]);
    }
    close(fdes);

    return(0);
}

int main(int argc, char* argv[]) {

    if (argc==2) {
        file_read(argv[1]);
        return(0);
    }

    else if (argc > 2) {
        printf("Too many arguments supplied\n");
        return (1);
    }
    else {
        printf("One argument expected\n");
        return (1);
    }
}
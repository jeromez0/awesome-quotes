#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>


int main() {

    const char filename[]="awesomequotes.txt";
    int fdes;
    char buffer[1];
    int r;

    fdes = open(filename, O_RDONLY);
    if (fdes == -1) {
        fprintf(stderr, "Unable to open %s\n", filename);
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
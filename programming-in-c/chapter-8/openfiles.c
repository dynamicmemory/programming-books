#include <fcntl.h>

int main() {

    int fd;
    fd = open("test.txt", O_RDONLY, 0);
    char c;
    

    return 0;
}

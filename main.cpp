#include <unistd.h>

int main() {
    if (fork())
        execlp("python3", "python3", "src/Python/main.py", nullptr);

    return 0;
}

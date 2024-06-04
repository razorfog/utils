#include <errno.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

/*
 *  Executable is excpected to be owned by root and have the effective-uid bit on.
 */
int main(int argc, char* argv[]) {
    int rv = 0;
    const uid_t eid = geteuid();
    if (setuid(eid) == 0) {
        const char *execFile = argc == 1 ? "bash" : argv[1];
        rv = execvp(execFile, &argv[1]);
        fprintf(stderr, "Exec %s failed: %s\n", execFile, strerror(errno));
    } else {
        rv = 1;
        fprintf(stderr,"Failed to setuid(0) euid=%d: errno=%d => %s\n", errno, eid, strerror(errno));
    }
    return rv;
}


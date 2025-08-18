#include <stdio.h>

int main (void)
    FILE *p = popen ("nvim --headless + d'lua print(vim.v.oldfiles[1] or \"\")'"
    if (!p)
        return 0;
    char buff[4096];

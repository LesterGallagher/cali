#include <stdlib.h>
#include <stdio.h>

#include "config.h"
#include "CMemLeak.h"
#include "hexdump.h"

char t (int i) {
    return i && !(i & (i - 1));
}

int main(int argc, char* argv[]) {
    for(int i = 0; i < argc; i++) {
        printf("%s\n", argv[i]);
    }

    #ifdef _DEBUG
    XWBReport("Done");
    #endif
}








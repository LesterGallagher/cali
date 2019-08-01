#include <stdlib.h>
#include <stdio.h>

#include "config.h"

#include "CMemLeak.h"

#include "list.h"
#include "map.h"

char t (int i) {
    return i && !(i & (i - 1));
}

int main(int argc, char* argv[]) {
    for(int i = 0; i < argc; i++) {
        printf("%s\n", argv[i]);
    }

	list(int) *v = list_new(int);

    list_push(v, 42);
    list_push(v, 64);

    list_print(v);

    hashmap_kvp(int);

    hashmap(int) *m = hashmap_new(int);

    char *key = "meaning of life";

    struct hashmap_kvp_int *kvp;
    
    kvp = hashmap_get(m, key);

    // hashmap_put(m, key, 42);

    // hashmap_kvp(int) item = hashmap_get(m, "meaning of life");
    
    #ifdef _DEBUG
    XWBReport("Done");
    #endif

    getchar();
}








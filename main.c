#include <stdlib.h>
#include <stdio.h>

#include "config.h"

#include "CMemLeak.h"

#define list_base       \
    struct {            \
        size_t cap, len;\
    }

#define list(T)         \
    struct list_##T {   \
        list_base;      \
        T data[];       \
    }


#define list_new(T)																\
	({																				\
		const size_t initial_size = 16;												\
		struct list_##T *v = malloc(sizeof(list(int)) + sizeof(T) * initial_size);	\
		v->cap = initial_size;														\
		v->len = 0;																	\
		v;																			\
	})

char t (int i) {
    return i && !(i & (i - 1));
}

int main(int argc, char* argv[]) {
    for(int i = 0; i < argc; i++) {
        printf("%s\n", argv[i]);
    }

	list(int) *v = list_new(int);

    #ifdef _DEBUG
    XWBReport("Done");
    #endif

    getchar();
}








#include <stdlib.h>
#include <stdbool.h>
#include <stddef.h>

#define list_base       \
    struct {            \
        size_t cap, len;\
    }

#define list(T)         \
    struct list_##T {   \
        list_base;      \
        T data[];       \
    }


#define list_new(T)                                                           \
({                                                                           \
    const size_t initial_size = 16;                                           \
    struct list_##T *v = malloc(sizeof(list_##T) + sizeof(T) * initial_size);	 \
    v->cap = initial_size;                                                    \
    v->len = 0;                                                               \
    v;                                                                        \
})

#define list_pop(v) (v->data[--v->len])

#define list_ref(v, i) (&v->data[i])

#define list_at(v, i) (*(list_ref(v, i)))

#define list_push(v, i)                                                 \
({                                                                      \
    if (v->len >= v->cap) {                                             \
        v->cap *= 2;                                                    \
        v = realloc(v, sizeof(list_base) + v->cap * sizeof(*v->data));  \
    }                                                                   \
    v->data[v->len++] = (i);                                            \
})

#define list_free(v) free(v)

#define list_trim(v)													\
({																		\
	if (v->len != v->cap) {												\
		v->cap = v->len;                                                \
		v = realloc(v, sizeof(list_base) + v->cap * sizeof(*v->data));  \
	}                                                                   \
	v->data[v->len++] = (i);											\
})

#define GET_FMT_SPEC(x) _Generic((x), int: "%d", float: "%f", char*: "%s")

#define list_print(v)													\
({																		\
    printf("[");														\
    for (int i = 0; i < v->len; ++i) {									\
        printf(GET_FMT_SPEC(v->data[i]), v->data[i]);					\
        if (i + 1 < v->len)												\
            printf(", ");												\
    }																	\
    printf("]\n");														\
 })



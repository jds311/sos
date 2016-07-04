#include "libk.h"
#include "paging.h"

void *memset(void *p, int b, size_t n) {
    char *_p = (char *)p;
    while(n --> 0) {
        *_p++ = b;
    }
    return p;
}

void *page_frame_copy(void *src, size_t spf, void *dest, size_t dpf, size_t bytes) {
    void *_src = src;
    if (spf) {
        _src = (void *)translate_address(src);
        if (!_src) {
            ERROR("SRC NOT MAPPED PAGE");
        }
    }

    if (dpf) {
        dest = (void *)translate_address(dest);
        if (!dest) {
            ERROR("DEST NOT MAPPED PAGE");
        }
    }

    while(bytes --> 0) {
        ((char *)dest)[bytes] = ((char *)_src)[bytes];
    }

    return src;
}

void wait(void) {
    for(int i=0;i<100000000;i++);
}

void *memcpy(void *_dest, void *_src, size_t bytes) {
    char *dest = (char *)_dest;
    char *src = (char *)_src;
    while(bytes --> 0) {
        *dest++ = *src++;
    }
}

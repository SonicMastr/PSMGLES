#include <string.h>
#include "PSMGLES/pgl.h"
#include "PSMGLES/gl.h"

int (*pglContextGLES2GetCurrentContext)(void);
int (*pglResourceManagerGetResource)(unsigned int program);
unsigned int (*pglResourceManagerIsResourceOfType)(unsigned int program, unsigned int type);
void (*pglContextGLES2SetCurrentError)(unsigned int error);
unsigned int (*pglStringLength)(const char *name);
char* (*pglPlatformStringCopy)(char *destination, char *source, unsigned int size);

int pglProgramSetAttributeLocation (int context, const char *name, unsigned int index) {
    if (index > 0xf) {
        return index & 0xffffff00;
    }
    char *var1 = (char *)(index * 0x8c) + context;
    char *dst = var1 + 0x3c;
    char *var2 = (char *)(index * 0x8c);
    if (dst != (char *)0x0) {
        var2 = (char *)memset(dst,0,0x8c);
        if ((dst != (char *)0x0) && (var2 = name, var2 != (char *)0x0)) {
            var2 = pglPlatformStringCopy(dst,name,0x80);
        }
    }
    *(uint16_t *)(var1 + 0xc4) = 0x101;
    return 1;
}
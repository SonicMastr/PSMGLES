#include "PSMGLES/pgl.h"

int (*pglContextGLES2GetCurrentContext)(void);
int (*pglResourceManagerGetResource)(unsigned int program);
unsigned int (*pglResourceManagerIsResourceOfType)(unsigned int program, unsigned int type);
void (*pglContextGLES2SetCurrentError)(unsigned int error);
unsigned int (*pglStringLength)(const char *name);
char* (*pglPlatformStringCopy)(char *destination, char *source, unsigned int size);
#ifndef PGL_H
#define PGL_H

extern int (*pglContextGLES2GetCurrentContext)(void);
extern int (*pglResourceManagerGetResource)(unsigned int program);
extern unsigned int (*pglResourceManagerIsResourceOfType)(unsigned int program, unsigned int type);
extern void (*pglContextGLES2SetCurrentError)(unsigned int error);
extern unsigned int (*pglStringLength)(const char *name);
extern char* (*pglPlatformStringCopy)(char *destination, char *source, unsigned int size);

#endif
#include "PSMGLES/egl.h"
#include "PSMGLES/gl.h"
#include "PSMGLES/pgl.h"
#include "PSMGLES/taiutils.h"

int exportEGL(void)
{
    tai_module_info_t tai_info;
    if (!getModuleInfo(&tai_info))
    {
        module_get_offset(tai_info.modid, 0, 0xB418 | 1, &_eglGetDisplay);
        module_get_offset(tai_info.modid, 0, 0xBE48 | 1, &_eglSwapBuffers);
        module_get_offset(tai_info.modid, 0, 0xB58E | 1, &_eglChooseConfig);
        module_get_offset(tai_info.modid, 0, 0xB456 | 1, &_eglInitialize);
        module_get_offset(tai_info.modid, 0, 0xBC0E | 1, &_eglBindAPI);
        module_get_offset(tai_info.modid, 0, 0xB52E | 1, &_eglGetConfigs);
        module_get_offset(tai_info.modid, 0, 0xB866 | 1, &_eglCreateWindowSurface);
        module_get_offset(tai_info.modid, 0, 0xB7EA | 1, &_eglGetConfigAttrib);
        module_get_offset(tai_info.modid, 0, 0xBC3A | 1, &_eglCreateContext);
        module_get_offset(tai_info.modid, 0, 0xBD88 | 1, &_eglMakeCurrent);
        return 0;
    }
    return 1;
}

int exportGL(void)
{
    tai_module_info_t tai_info;
    if (!getModuleInfo(&tai_info))
    {
        module_get_offset(tai_info.modid, 0, 0xB4C54 | 1, &_glShaderSource);
        module_get_offset(tai_info.modid, 0, 0xB1BF6 | 1, &_glCreateShader);
        module_get_offset(tai_info.modid, 0, 0xB1746 | 1, &_glCompileShader);
        module_get_offset(tai_info.modid, 0, 0xB44A8 | 1, &_glGetShaderiv);
        module_get_offset(tai_info.modid, 0, 0xB4550 | 1, &_glGetShaderInfoLog);
        module_get_offset(tai_info.modid, 0, 0xB1F8C | 1, &_glDeleteShader);
        module_get_offset(tai_info.modid, 0, 0xB1BB8 | 1, &_glCreateProgram);
        module_get_offset(tai_info.modid, 0, 0xB0F24 | 1, &_glAttachShader);
        module_get_offset(tai_info.modid, 0, 0xB4772 | 1, &_glLinkProgram);
        module_get_offset(tai_info.modid, 0, 0xB43B6 | 1, &_glGetProgramiv);
        module_get_offset(tai_info.modid, 0, 0xB442A | 1, &_glGetProgramInfoLog);
        module_get_offset(tai_info.modid, 0, 0xB1DA2 | 1, &_glDeleteProgram);
        module_get_offset(tai_info.modid, 0, 0xB15DA | 1, &_glClearColor);
        module_get_offset(tai_info.modid, 0, 0xB62E6 | 1, &_glViewport);
        module_get_offset(tai_info.modid, 0, 0xB152C | 1, &_glClear);
        module_get_offset(tai_info.modid, 0, 0xB611A | 1, &_glUseProgram);
        module_get_offset(tai_info.modid, 0, 0xB61DE | 1, &_glVertexAttribPointer);
        module_get_offset(tai_info.modid, 0, 0xB25EE | 1, &_glEnableVertexAttribArray);
        module_get_offset(tai_info.modid, 0, 0xB225C | 1, &_glDrawArrays);
        module_get_offset(tai_info.modid, 0, 0xB5C9C | 1, &_glUniform4fv);
        module_get_offset(tai_info.modid, 0, 0xB4672 | 1, &_glGetUniformLocation);
        return 0;
    }
    return 1;
}

int exportPGL(void)
{
    tai_module_info_t tai_info;
    if (!getModuleInfo(&tai_info))
    {
        module_get_offset(tai_info.modid, 0, 0xCB20 | 1, &pglContextGLES2GetCurrentContext);
        module_get_offset(tai_info.modid, 0, 0xDD7E | 1, &pglResourceManagerGetResource);
        module_get_offset(tai_info.modid, 0, 0xDDAE | 1, &pglResourceManagerIsResourceOfType);
        module_get_offset(tai_info.modid, 0, 0xCB40 | 1, &pglContextGLES2SetCurrentError);
        module_get_offset(tai_info.modid, 0, 0xE254 | 1, &pglStringLength);
        module_get_offset(tai_info.modid, 0, 0xE276 | 1, &pglPlatformStringCopy);
        return 0;
    }
    return 1;
}

int exportAll(void)
{
    if(exportEGL())
        return -1;
    if(exportGL())
        return -2;
    if(exportPGL())
        return -3;
    return 0;   
}
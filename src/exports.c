#include "PSMGLES/egl.h"
#include "PSMGLES/gl.h"
#include "PSMGLES/pgl.h"
#include "PSMGLES/taiutils.h"

int exportEGL(void)
{
    tai_module_info_t tai_info;
    if (!getModuleInfo(&tai_info))  // 0 on Success
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
    return -1;
}

int exportGL(void)
{
    tai_module_info_t tai_info;
    if (!getModuleInfo(&tai_info))  // 0 on Success
    {
        module_get_offset(tai_info.modid, 0, 0xB0EF4 | 1, &_glActiveTexture);
        module_get_offset(tai_info.modid, 0, 0xB0F24 | 1, &_glAttachShader);
        module_get_offset(tai_info.modid, 0, 0xB0F9E | 1, &_glBindBuffer);
        module_get_offset(tai_info.modid, 0, 0xB104E | 1, &_glBindFramebuffer);
        module_get_offset(tai_info.modid, 0, 0xB10D2 | 1, &_glBindRenderbuffer);
        module_get_offset(tai_info.modid, 0, 0xB1156 | 1, &_glBindTexture);
        // module_get_offset(tai_info.modid, 0, 0xB11F4 | 1, &_glBlendEquationSeparate);
        // module_get_offset(tai_info.modid, 0, 0xB1256 | 1, &_glBlendFuncSeparate);
        // module_get_offset(tai_info.modid, 0, 0xB1394 | 1, &_glBufferData);
        // module_get_offset(tai_info.modid, 0, 0xB05F0 | 1, &_glBufferSubData);
        // module_get_offset(tai_info.modid, 0, 0xB14D2 | 1, &_glCheckFramebufferStatus);
        module_get_offset(tai_info.modid, 0, 0xB152C | 1, &_glClear);
        module_get_offset(tai_info.modid, 0, 0xB15DA | 1, &_glClearColor);
        // module_get_offset(tai_info.modid, 0, 0xB16B2 | 1, &_glClearDepthf);
        // module_get_offset(tai_info.modid, 0, 0xB1700 | 1, &_glClearStencil);
        // module_get_offset(tai_info.modid, 0, 0xB1718 | 1, &_glColorMask);
        module_get_offset(tai_info.modid, 0, 0xB1746 | 1, &_glCompileShader);
        // module_get_offset(tai_info.modid, 0, 0xB177A | 1, &_glCompressedTexImage2D);
        // module_get_offset(tai_info.modid, 0, 0xB17F0 | 1, &_glCompressedTexSubImage2D);
        // module_get_offset(tai_info.modid, 0, 0xB1A30 | 1, &_glCopyTexSubImage2D);
        module_get_offset(tai_info.modid, 0, 0xB1BB8 | 1, &_glCreateProgram);
        module_get_offset(tai_info.modid, 0, 0xB1BF6 | 1, &_glCreateShader);
        // module_get_offset(tai_info.modid, 0, 0xB1C86 | 1, &_glCullFace);
        // module_get_offset(tai_info.modid, 0, 0xB1CC0 | 1, &_glDeleteBuffers);
        // module_get_offset(tai_info.modid, 0, 0xB1D44 | 1, &_glDeleteFramebuffers);
        module_get_offset(tai_info.modid, 0, 0xB1DA2 | 1, &_glDeleteProgram);
        // module_get_offset(tai_info.modid, 0, 0xB1DF0 | 1, &_glDeleteRenderbuffers);
        module_get_offset(tai_info.modid, 0, 0xB1F8C | 1, &_glDeleteShader);
        // module_get_offset(tai_info.modid, 0, 0xB1FC0 | 1, &_glDeleteTextures);
        // module_get_offset(tai_info.modid, 0, 0xB20A4 | 1, &_glDepthFunc);
        // module_get_offset(tai_info.modid, 0, 0xB20DA | 1, &_glDepthMask);
        // module_get_offset(tai_info.modid, 0, 0xB20F2 | 1, &_glDepthRangef);
        module_get_offset(tai_info.modid, 0, 0xB216E | 1, &_glDisable);
        // module_get_offset(tai_info.modid, 0, 0xB2238 | 1, &_glDisableVertexAttribArray);
        module_get_offset(tai_info.modid, 0, 0xB225C | 1, &_glDrawArrays);
        // module_get_offset(tai_info.modid, 0, 0x15F40 | 1, &_glDrawArraysInstancedEXT);
        // module_get_offset(tai_info.modid, 0, 0xB23A8 | 1, &_glDrawElements);
        // module_get_offset(tai_info.modid, 0, 0x160C8 | 1, &_glDrawElementsInstancedEXT);
        // module_get_offset(tai_info.modid, 0, 0xB2518 | 1, &_glEnable);
        module_get_offset(tai_info.modid, 0, 0xB25EE | 1, &_glEnableVertexAttribArray);
        // module_get_offset(tai_info.modid, 0, 0xB2612 | 1, &_glFramebufferRenderbuffer);
        // module_get_offset(tai_info.modid, 0, 0xB26EA | 1, &_glFramebufferTexture2D);
        // module_get_offset(tai_info.modid, 0, 0xB2820 | 1, &_glFrontFace_g);
        // module_get_offset(tai_info.modid, 0, 0xB2852 | 1, &_glGenBuffers);
        // module_get_offset(tai_info.modid, 0, 0xB28A0 | 1, &_glGenerateMipmap);
        // module_get_offset(tai_info.modid, 0, 0xB2906 | 1, &_glGenFramebuffers);
        // module_get_offset(tai_info.modid, 0, 0xB2954 | 1, &_glGenRenderbuffers);
        // module_get_offset(tai_info.modid, 0, 0xB2988 | 1, &_glGenTextures);
        // module_get_offset(tai_info.modid, 0, 0xB29BC | 1, &_glGetActiveAttrib);
        // module_get_offset(tai_info.modid, 0, 0xB2B04 | 1, &_glGetActiveUniform);
        // module_get_offset(tai_info.modid, 0, 0xB2C96 | 1, &_glGetAttribLocation);
        // module_get_offset(tai_info.modid, 0, 0xB2E6A | 1, &_glGetError);
        // module_get_offset(tai_info.modid, 0, 0xB2E72 | 1, &_glGetFloatv);
        // module_get_offset(tai_info.modid, 0, 0xB396E | 1, &_glGetIntegerv);
        module_get_offset(tai_info.modid, 0, 0xB442A | 1, &_glGetProgramInfoLog);
        module_get_offset(tai_info.modid, 0, 0xB43B6 | 1, &_glGetProgramiv);
        module_get_offset(tai_info.modid, 0, 0xB4550 | 1, &_glGetShaderInfoLog);
        module_get_offset(tai_info.modid, 0, 0xB44A8 | 1, &_glGetShaderiv);
        // module_get_offset(tai_info.modid, 0, 0xB45CE | 1, &_glGetString);
        module_get_offset(tai_info.modid, 0, 0xB4672 | 1, &_glGetUniformLocation);
        // module_get_offset(tai_info.modid, 0, 0xB470A | 1, &_glLineWidth);
        module_get_offset(tai_info.modid, 0, 0xB4772 | 1, &_glLinkProgram);
        // module_get_offset(tai_info.modid, 0, 0x15EC4 | 1, &_glPigletGetShaderBinarySCE);
        // module_get_offset(tai_info.modid, 0, 0xB47A6 | 1, &_glPixelStorei);
        // module_get_offset(tai_info.modid, 0, 0xB47E2 | 1, &_glPolygonOffset);
        // module_get_offset(tai_info.modid, 0, 0xB480C | 1, &_glReadPixels);
        // module_get_offset(tai_info.modid, 0, 0xB4A3C | 1, &_glRenderbufferStorage);
        // module_get_offset(tai_info.modid, 0, 0xB4B42 | 1, &_glScissor);
        module_get_offset(tai_info.modid, 0, 0xB4C54 | 1, &_glShaderSource);
        // module_get_offset(tai_info.modid, 0, 0xB4CB6 | 1, &_glStencilFuncSeparate);
        // module_get_offset(tai_info.modid, 0, 0xB4D52 | 1, &_glStencilMaskSeparate);
        // module_get_offset(tai_info.modid, 0, 0xB4DB4 | 1, &_glStencilOpSeparate);
        // module_get_offset(tai_info.modid, 0, 0xB4F3E | 1, &_glTexImage2D);
        // module_get_offset(tai_info.modid, 0, 0xB5188 | 1, &_glTexParameterf);
        // module_get_offset(tai_info.modid, 0, 0xB52FC | 1, &_glTexParameteri);
        // module_get_offset(tai_info.modid, 0, 0xB544C | 1, &_glTexSubImage2D);
        module_get_offset(tai_info.modid, 0, 0xB566C | 1, &_glUniform1fv);
        module_get_offset(tai_info.modid, 0, 0xB578C | 1, &_glUniform1iv);
        module_get_offset(tai_info.modid, 0, 0xB5898 | 1, &_glUniform2fv);
        module_get_offset(tai_info.modid, 0, 0xB598E | 1, &_glUniform2iv);
        module_get_offset(tai_info.modid, 0, 0xB5A82 | 1, &_glUniform3fv);
        module_get_offset(tai_info.modid, 0, 0xB5B92 | 1, &_glUniform3iv);
        module_get_offset(tai_info.modid, 0, 0xB5C9C | 1, &_glUniform4fv);
        module_get_offset(tai_info.modid, 0, 0xB5D98 | 1, &_glUniform4iv);
        module_get_offset(tai_info.modid, 0, 0xB5E8C | 1, &_glUniformMatrix2fv);
        module_get_offset(tai_info.modid, 0, 0xB5F62 | 1, &_glUniformMatrix3fv);
        module_get_offset(tai_info.modid, 0, 0xB6044 | 1, &_glUniformMatrix4fv);
        module_get_offset(tai_info.modid, 0, 0xB611A | 1, &_glUseProgram);
        // module_get_offset(tai_info.modid, 0, 0xB6174 | 1, &_glVertexAttrib4f);
        // module_get_offset(tai_info.modid, 0, 0x16282 | 1, &_glVertexAttribDivisorEXT);
        module_get_offset(tai_info.modid, 0, 0xB61DE | 1, &_glVertexAttribPointer);
        module_get_offset(tai_info.modid, 0, 0xB62E6 | 1, &_glViewport);
        return 0;
    }
    return -1;
}

int exportPGL(void)
{
    tai_module_info_t tai_info;
    if (!getModuleInfo(&tai_info))  // 0 on Success
    {
        module_get_offset(tai_info.modid, 0, 0xCB20 | 1, &pglContextGLES2GetCurrentContext);
        module_get_offset(tai_info.modid, 0, 0xDD7E | 1, &pglResourceManagerGetResource);
        module_get_offset(tai_info.modid, 0, 0xDDAE | 1, &pglResourceManagerIsResourceOfType);
        module_get_offset(tai_info.modid, 0, 0xCB40 | 1, &pglContextGLES2SetCurrentError);
        module_get_offset(tai_info.modid, 0, 0xE254 | 1, &pglStringLength);
        module_get_offset(tai_info.modid, 0, 0xE276 | 1, &pglPlatformStringCopy);
        return 0;
    }
    return -1;
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
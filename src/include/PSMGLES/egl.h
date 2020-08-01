#ifndef EGL_H
#define EGL_H

#include "EGL/egl.h"

extern EGLAPI EGLDisplay EGLAPIENTRY (*_eglGetDisplay)(NativeDisplayType display_id);
extern EGLAPI EGLBoolean EGLAPIENTRY (*_eglSwapBuffers)(EGLDisplay dpy, EGLSurface surface);
extern EGLAPI EGLBoolean EGLAPIENTRY (*_eglChooseConfig)(EGLDisplay dpy, const EGLint *attrib_list, EGLConfig *configs, EGLint config_size, EGLint *num_config);
extern EGLAPI EGLBoolean EGLAPIENTRY (*_eglInitialize)(EGLDisplay dpy, EGLint *major, EGLint *minor);
extern EGLAPI EGLBoolean EGLAPIENTRY (*_eglBindAPI)(EGLenum api);
extern EGLAPI EGLBoolean EGLAPIENTRY (*_eglGetConfigs)(EGLDisplay dpy, EGLConfig *configs, EGLint config_size, EGLint *num_config);
extern EGLAPI EGLSurface EGLAPIENTRY (*_eglCreateWindowSurface)(EGLDisplay dpy, EGLConfig config, EGLNativeWindowType win, const EGLint *attrib_list);
extern EGLAPI EGLBoolean EGLAPIENTRY (*_eglGetConfigAttrib)(EGLDisplay dpy, EGLConfig config, EGLint attribute, EGLint *value);
extern EGLAPI EGLContext EGLAPIENTRY (*_eglCreateContext)(EGLDisplay dpy, EGLConfig config, EGLContext share_context, const EGLint *attrib_list);
extern EGLAPI EGLBoolean EGLAPIENTRY (*_eglMakeCurrent)(EGLDisplay dpy, EGLSurface draw, EGLSurface read, EGLContext ctx);

#endif
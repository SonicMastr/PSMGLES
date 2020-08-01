#ifndef GL_H
#define GH_H

#include "GLES2/gl2.h"

extern GL_APICALL void GL_APIENTRY (*_glShaderSource)(GLuint shader, GLsizei count, const GLchar *const*string, const GLint *length);
extern GL_APICALL GLuint GL_APIENTRY (*_glCreateShader)(GLenum type);
extern GL_APICALL void GL_APIENTRY (*_glCompileShader)(GLuint shader);
extern GL_APICALL void GL_APIENTRY (*_glGetShaderiv)(GLuint shader, GLenum pname, GLint *params);
extern GL_APICALL void GL_APIENTRY (*_glGetShaderInfoLog)(GLuint shader, GLsizei bufSize, GLsizei *length, GLchar *infoLog);
extern GL_APICALL void GL_APIENTRY (*_glDeleteShader)(GLuint shader);
extern GL_APICALL GLuint GL_APIENTRY (*_glCreateProgram)(void);
extern GL_APICALL void GL_APIENTRY (*_glAttachShader)(GLuint program, GLuint shader);
extern GL_APICALL void GL_APIENTRY (*_glLinkProgram)(GLuint program);
extern GL_APICALL void GL_APIENTRY (*_glGetProgramiv)(GLuint program, GLenum pname, GLint *params);
extern GL_APICALL void GL_APIENTRY (*_glDeleteProgram)(GLuint program);
extern GL_APICALL void GL_APIENTRY (*_glClearColor)(GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha);
extern GL_APICALL void GL_APIENTRY (*_glGetProgramInfoLog)(GLuint program, GLsizei bufSize, GLsizei *length, GLchar *infoLog);
extern GL_APICALL void GL_APIENTRY (*_glViewport)(GLint x, GLint y, GLsizei width, GLsizei height);
extern GL_APICALL void GL_APIENTRY (*_glClear)(GLbitfield mask);
extern GL_APICALL void GL_APIENTRY (*_glUseProgram)(GLuint program);
extern GL_APICALL void GL_APIENTRY (*_glVertexAttribPointer)(GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride, const void *pointer);
extern GL_APICALL void GL_APIENTRY (*_glEnableVertexAttribArray)(GLuint index);
extern GL_APICALL void GL_APIENTRY (*_glDrawArrays)(GLenum mode, GLint first, GLsizei count);
extern GL_APICALL void GL_APIENTRY (*_glUniform4fv)(GLint location, GLsizei count, const GLfloat *value);
extern GL_APICALL GLint GL_APIENTRY (*_glGetUniformLocation)(GLuint program, const GLchar *name);

#endif
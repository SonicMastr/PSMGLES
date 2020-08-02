#ifndef GL_H
#define GH_H

#include "GLES2/gl2.h"

GL_APICALL void GL_APIENTRY (*_glShaderSource)(GLuint shader, GLsizei count, const GLchar *const*string, const GLint *length);
GL_APICALL GLuint GL_APIENTRY (*_glCreateShader)(GLenum type);
GL_APICALL void GL_APIENTRY (*_glCompileShader)(GLuint shader);
GL_APICALL void GL_APIENTRY (*_glGetShaderiv)(GLuint shader, GLenum pname, GLint *params);
GL_APICALL void GL_APIENTRY (*_glGetShaderInfoLog)(GLuint shader, GLsizei bufSize, GLsizei *length, GLchar *infoLog);
GL_APICALL void GL_APIENTRY (*_glDeleteShader)(GLuint shader);
GL_APICALL GLuint GL_APIENTRY (*_glCreateProgram)(void);
GL_APICALL void GL_APIENTRY (*_glAttachShader)(GLuint program, GLuint shader);
GL_APICALL void GL_APIENTRY (*_glLinkProgram)(GLuint program);
GL_APICALL void GL_APIENTRY (*_glGetProgramiv)(GLuint program, GLenum pname, GLint *params);
GL_APICALL void GL_APIENTRY (*_glDeleteProgram)(GLuint program);
GL_APICALL void GL_APIENTRY (*_glClearColor)(GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha);
GL_APICALL void GL_APIENTRY (*_glGetProgramInfoLog)(GLuint program, GLsizei bufSize, GLsizei *length, GLchar *infoLog);
GL_APICALL void GL_APIENTRY (*_glViewport)(GLint x, GLint y, GLsizei width, GLsizei height);
GL_APICALL void GL_APIENTRY (*_glClear)(GLbitfield mask);
GL_APICALL void GL_APIENTRY (*_glUseProgram)(GLuint program);
GL_APICALL void GL_APIENTRY (*_glVertexAttribPointer)(GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride, const void *pointer);
GL_APICALL void GL_APIENTRY (*_glEnableVertexAttribArray)(GLuint index);
GL_APICALL void GL_APIENTRY (*_glDrawArrays)(GLenum mode, GLint first, GLsizei count);
GL_APICALL void GL_APIENTRY (*_glUniform1fv)(GLint location, GLsizei count, const GLfloat *value);
GL_APICALL void GL_APIENTRY (*_glUniform1iv)(GLint location, GLsizei count, const GLint *value);
GL_APICALL void GL_APIENTRY (*_glUniform2fv)(GLint location, GLsizei count, const GLfloat *value);
GL_APICALL void GL_APIENTRY (*_glUniform2iv)(GLint location, GLsizei count, const GLint *value);
GL_APICALL void GL_APIENTRY (*_glUniform3fv)(GLint location, GLsizei count, const GLfloat *value);
GL_APICALL void GL_APIENTRY (*_glUniform3iv)(GLint location, GLsizei count, const GLint *value);
GL_APICALL void GL_APIENTRY (*_glUniform4fv)(GLint location, GLsizei count, const GLfloat *value);
GL_APICALL void GL_APIENTRY (*_glUniform4iv)(GLint location, GLsizei count, const GLint *value);
GL_APICALL void GL_APIENTRY (*_glUniformMatrix2fv)(GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
GL_APICALL void GL_APIENTRY (*_glUniformMatrix3fv)(GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
GL_APICALL void GL_APIENTRY (*_glUniformMatrix4fv)(GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
GL_APICALL GLint GL_APIENTRY (*_glGetUniformLocation)(GLuint program, const GLchar *name);

#endif
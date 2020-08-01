#include "PSMGLES/gl.h"
#include "PSMGLES/pgl.h"

/* PGL Functions */
static GLint pglProgramSetAttributeLocation (GLint context, const GLchar *name, GLuint index)
{
    if (index > 15) {
        return index & 0xffffff00;
    }
    GLchar *var1 = (GLchar *)(index * 0x8c) + context;
    GLchar *dst = var1 + 0x3c;
    GLchar *var2 = (GLchar *)(index * 0x8c);
    if (dst != (GLchar *)0x0) {
        var2 = (GLchar *)memset(dst,0,0x8c);
        if ((dst != (GLchar *)0x0) && (var2 = name, var2 != (GLchar *)0x0)) {
            var2 = pglPlatformStringCopy(dst,name,0x80);
        }
    }
    *(uint16_t *)(var1 + 0xc4) = 0x101;
    return 1;
}


/* GL Functions */
GL_APICALL void GL_APIENTRY glShaderSource (GLuint shader, GLsizei count, const GLchar *const*string, const GLint *length)
{
    return _glShaderSource(shader, count, string, length);
}

GL_APICALL GLuint GL_APIENTRY glCreateShader (GLenum type)
{
    return _glCreateShader(type);
}

GL_APICALL void GL_APIENTRY glCompileShader (GLuint shader)
{
    return _glCompileShader(shader);
}

GL_APICALL void GL_APIENTRY glGetShaderiv (GLuint shader, GLenum pname, GLint *params)
{
    return _glGetShaderiv(shader, pname, params);
}

GL_APICALL void GL_APIENTRY glGetShaderInfoLog (GLuint shader, GLsizei bufSize, GLsizei *length, GLchar *infoLog)
{
    return _glGetShaderInfoLog(shader, bufSize, length, infoLog);
}

GL_APICALL void GL_APIENTRY glDeleteShader (GLuint shader)
{
    return _glDeleteShader(shader);
}

GL_APICALL GLuint GL_APIENTRY glCreateProgram (void)
{
    return _glCreateProgram();
}

GL_APICALL void GL_APIENTRY glAttachShader (GLuint program, GLuint shader)
{
    return _glAttachShader(program, shader);
}

GL_APICALL void GL_APIENTRY glBindAttribLocation (GLuint program, GLuint index, const GLchar *name)
{
    GLint context = pglContextGLES2GetCurrentContext();
    if (context) {
        context = pglResourceManagerGetResource(program);
        if (!context || index > 15) {
            pglContextGLES2SetCurrentError(GL_INVALID_VALUE);
            return;
        }
        GLuint stringLength = pglStringLength(name);
        GLuint checkType = pglResourceManagerIsResourceOfType(program, 2);
        if (!checkType || ((((2 < stringLength) && (*name == 'g')) && (name[1] == 'l')) && (name[2] == '_'))) {
            pglContextGLES2SetCurrentError(GL_INVALID_OPERATION);
            return;
        }
        pglProgramSetAttributeLocation(context, name, index);
    }
}

GL_APICALL void GL_APIENTRY glLinkProgram (GLuint program)
{
    return _glLinkProgram(program);
}

GL_APICALL void GL_APIENTRY glGetProgramiv (GLuint program, GLenum pname, GLint *params)
{
    return _glGetProgramiv(program, pname, params);
}

GL_APICALL void GL_APIENTRY glGetProgramInfoLog (GLuint program, GLsizei bufSize, GLsizei *length, GLchar *infoLog)
{
    return _glGetProgramInfoLog(program, bufSize, length, infoLog);
}

GL_APICALL void GL_APIENTRY glDeleteProgram (GLuint program)
{
    return _glDeleteProgram(program);
}

GL_APICALL void GL_APIENTRY glClearColor (GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha)
{
    return _glClearColor(red, green, blue, alpha);
}

GL_APICALL void GL_APIENTRY glViewport (GLint x, GLint y, GLsizei width, GLsizei height)
{
    return _glViewport(x, y, width, height);
}

GL_APICALL void GL_APIENTRY glClear (GLbitfield mask)
{
    return _glClear(mask);
}

GL_APICALL void GL_APIENTRY glUseProgram (GLuint program)
{
    return _glUseProgram(program);
}

GL_APICALL void GL_APIENTRY glVertexAttribPointer (GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride, const void *pointer)
{
    return _glVertexAttribPointer(index, size, type, normalized, stride, pointer);
}

GL_APICALL void GL_APIENTRY glEnableVertexAttribArray (GLuint index)
{
    return _glEnableVertexAttribArray(index);
}

GL_APICALL void GL_APIENTRY glDrawArrays (GLenum mode, GLint first, GLsizei count)
{
    return _glDrawArrays(mode, first, count);
}

GL_APICALL void GL_APIENTRY glUniform4fv (GLint location, GLsizei count, const GLfloat *value){
    return _glUniform4fv(location, count, value);
}

GL_APICALL GLint GL_APIENTRY glGetUniformLocation (GLuint program, const GLchar *name)
{
    return _glGetUniformLocation(program, name);
}
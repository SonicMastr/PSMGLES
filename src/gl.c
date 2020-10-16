#include "PSMGLES/gl.h"
#include "PSMGLES/pgl.h"

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
GL_APICALL void GL_APIENTRY (*_glDisable)(GLenum cap);
GL_APICALL void GL_APIENTRY (*_glActiveTexture)(GLenum texture);
GL_APICALL void GL_APIENTRY (*_glBindBuffer)(GLenum target, GLuint buffer);
GL_APICALL void GL_APIENTRY (*_glBindFramebuffer)(GLenum target, GLuint framebuffer);
GL_APICALL void GL_APIENTRY (*_glBindRenderbuffer)(GLenum target, GLuint renderbuffer);
GL_APICALL void GL_APIENTRY (*_glBindTexture)(GLenum target, GLuint texture);

GL_APICALL void GL_APIENTRY glActiveTexture (GLenum texture) {
    return _glActiveTexture(texture);
}
GL_APICALL void GL_APIENTRY glAttachShader (GLuint program, GLuint shader) {
    return _glAttachShader(program, shader);
}
GL_APICALL void GL_APIENTRY glBindAttribLocation (GLuint program, GLuint index, const GLchar *name) {
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
GL_APICALL void GL_APIENTRY glBindBuffer (GLenum target, GLuint buffer) {
    return _glBindBuffer(target, buffer);
}
GL_APICALL void GL_APIENTRY glBindFramebuffer (GLenum target, GLuint framebuffer) {
	return _glBindFramebuffer (target, framebuffer);
}
GL_APICALL void GL_APIENTRY glBindRenderbuffer (GLenum target, GLuint renderbuffer) {
	return _glBindRenderbuffer (target, renderbuffer);
}
GL_APICALL void GL_APIENTRY glBindTexture (GLenum target, GLuint texture) {
	return _glBindTexture (target, texture);
}
GL_APICALL void GL_APIENTRY glClear (GLbitfield mask) {
    return _glClear(mask);
}
GL_APICALL void GL_APIENTRY glClearColor (GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha) {
    return _glClearColor(red, green, blue, alpha);
}
GL_APICALL void GL_APIENTRY glCompileShader (GLuint shader) {
    return _glCompileShader(shader);
}
GL_APICALL GLuint GL_APIENTRY glCreateProgram (void) {
    return _glCreateProgram();
}
GL_APICALL GLuint GL_APIENTRY glCreateShader (GLenum type) {
    return _glCreateShader(type);
}
GL_APICALL void GL_APIENTRY glDeleteProgram (GLuint program) {
    return _glDeleteProgram(program);
}
GL_APICALL void GL_APIENTRY glDeleteShader (GLuint shader) {
    return _glDeleteShader(shader);
}
GL_APICALL void GL_APIENTRY glDisable (GLenum cap) {
    return _glDisable(cap);
}
GL_APICALL void GL_APIENTRY glDrawArrays (GLenum mode, GLint first, GLsizei count) {
    return _glDrawArrays(mode, first, count);
}
GL_APICALL void GL_APIENTRY glEnableVertexAttribArray (GLuint index) {
    return _glEnableVertexAttribArray(index);
}
GL_APICALL void GL_APIENTRY glGetProgramInfoLog (GLuint program, GLsizei bufSize, GLsizei *length, GLchar *infoLog) {
    return _glGetProgramInfoLog(program, bufSize, length, infoLog);
}
GL_APICALL void GL_APIENTRY glGetProgramiv (GLuint program, GLenum pname, GLint *params) {
    return _glGetProgramiv(program, pname, params);
}
GL_APICALL void GL_APIENTRY glGetShaderInfoLog (GLuint shader, GLsizei bufSize, GLsizei *length, GLchar *infoLog) {
    return _glGetShaderInfoLog(shader, bufSize, length, infoLog);
}
GL_APICALL void GL_APIENTRY glGetShaderiv (GLuint shader, GLenum pname, GLint *params) {
    return _glGetShaderiv(shader, pname, params);
}
GL_APICALL GLint GL_APIENTRY glGetUniformLocation (GLuint program, const GLchar *name) {
    return _glGetUniformLocation(program, name);
}
GL_APICALL void GL_APIENTRY glLinkProgram (GLuint program) {
    return _glLinkProgram(program);
}
GL_APICALL void GL_APIENTRY glShaderSource (GLuint shader, GLsizei count, const GLchar *const*string, const GLint *length) {
    return _glShaderSource(shader, count, string, length);
}
GL_APICALL void GL_APIENTRY glUniform1f (GLint location, GLfloat v0) {
	return _glUniform1fv(location, 1, &v0);
}
GL_APICALL void GL_APIENTRY glUniform1fv (GLint location, GLsizei count, const GLfloat *value) {
	return _glUniform1fv(location, count, value);
}
GL_APICALL void GL_APIENTRY glUniform1i (GLint location, GLint v0) {
	return _glUniform1iv(location, 1, &v0);
}
GL_APICALL void GL_APIENTRY glUniform1iv (GLint location, GLsizei count, const GLint *value) {
	return _glUniform1iv( location, count, value);
}
GL_APICALL void GL_APIENTRY glUniform2f (GLint location, GLfloat v0, GLfloat v1) {
    GLfloat v[] = {v0, v1};
	return _glUniform2fv(location, 1, &v);
}
GL_APICALL void GL_APIENTRY glUniform2fv (GLint location, GLsizei count, const GLfloat *value) {
	return _glUniform2fv(location, count, value);
}
GL_APICALL void GL_APIENTRY glUniform2i (GLint location, GLint v0, GLint v1) {
    GLint v[] = {v0, v1};
	return _glUniform2iv(location, 1, &v);
}
GL_APICALL void GL_APIENTRY glUniform2iv (GLint location, GLsizei count, const GLint *value) {
	return _glUniform2iv(location, count, value);
}
GL_APICALL void GL_APIENTRY glUniform3f (GLint location, GLfloat v0, GLfloat v1, GLfloat v2) {
    GLfloat v[] = {v0, v1, v2};
	return _glUniform3fv(location, 1, &v);
}
GL_APICALL void GL_APIENTRY glUniform3fv (GLint location, GLsizei count, const GLfloat *value) {
	return _glUniform3fv(location, count, value) ;
}
GL_APICALL void GL_APIENTRY glUniform3i (GLint location, GLint v0, GLint v1, GLint v2) {
    GLint v[] = {v0, v1, v2};
	return _glUniform3iv(location, 1, &v);
}
GL_APICALL void GL_APIENTRY glUniform3iv (GLint location, GLsizei count, const GLint *value) {
	return _glUniform3iv(location, count, value);
}
GL_APICALL void GL_APIENTRY glUniform4f (GLint location, GLfloat v0, GLfloat v1, GLfloat v2, GLfloat v3) {
    GLfloat v[] = {v0, v1, v2, v3};
	return _glUniform4fv(location, 1, &v);
}
GL_APICALL void GL_APIENTRY glUniform4fv (GLint location, GLsizei count, const GLfloat *value) {
	return _glUniform4fv(location, count, value);
}
GL_APICALL void GL_APIENTRY glUniform4i (GLint location, GLint v0, GLint v1, GLint v2, GLint v3) {
    GLint v[] = {v0, v1, v2, v3};
	return _glUniform4iv(location, 1, &v);
}
GL_APICALL void GL_APIENTRY glUniform4iv (GLint location, GLsizei count, const GLint *value) {
	return _glUniform4iv(location, count, value);
}
GL_APICALL void GL_APIENTRY glUniformMatrix2fv (GLint location, GLsizei count, GLboolean transpose, const GLfloat *value) {
	return _glUniformMatrix2fv (location, count, transpose, value);
}
GL_APICALL void GL_APIENTRY glUniformMatrix3fv (GLint location, GLsizei count, GLboolean transpose, const GLfloat *value) {
	return _glUniformMatrix3fv (location, count, transpose, value);
}
GL_APICALL void GL_APIENTRY glUniformMatrix4fv (GLint location, GLsizei count, GLboolean transpose, const GLfloat *value) {
	return _glUniformMatrix4fv (location, count, transpose, value);
}
GL_APICALL void GL_APIENTRY glUseProgram (GLuint program) {
    return _glUseProgram(program);
}
GL_APICALL void GL_APIENTRY glVertexAttribPointer (GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride, const void *pointer) {
    return _glVertexAttribPointer(index, size, type, normalized, stride, pointer);
}
GL_APICALL void GL_APIENTRY glViewport (GLint x, GLint y, GLsizei width, GLsizei height) {
    return _glViewport(x, y, width, height);
}
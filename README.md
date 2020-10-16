# PSMGLES
PSM Supplemented Mini GL ES

This is simply a library to make using PSM's GLES implimentation easier.
This potentially opens the door for more accessible, modern ports for the Vita. VitaGL is targeted towards the GL1 library of functions, and this has been a struggle
for porting more modern games. While using PSM has proven to not be a good idea, the ability is here, and that's something to hope for.

Offsets and what led us to finding this: https://forum.devchroma.nl/index.php/topic,285.0.html

When using, make sure the Modules in the "Dependencies" archive are in the directory `app0:Modules/`. Otherwise initialization will fail.

Shader Compilation works btw, but is limited to CG shaders. GLSL is not supported by the Vita's Runtime Shader Compiler

## Example
And example for this can be found [Here](https://github.com/SonicMastr/PSMGLES-Sample)

## Problems
- You have to implement most functions that don't use arrays, ie. glUniform4i (Check gl.c)
- Memory usage at idle is 50MB BEST. This is pretty impractical.
- This uses PSM, which is basically bloatware. That is one of the reasons for the memory usage stated above, and many modules are required for initialization. We have been looking at other, better methods.
- PSM requires SceLibc to function, so the use of VitaSDK doesn't work. You are REQUIRED to use [DolceSDK](https://github.com/DolceSDK/doc).
- Not all GL functions are present in PSM, resulting in an incomplete GLES implimentation. We are also looking at better methods to handle this.

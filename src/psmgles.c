#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <psp2/sysmodule.h>
#include "PSMGLES/egl.h"
#include "PSMGLES/gl.h"
#include "PSMGLES/pgl.h"
#include "PSMGLES/psmgles.h"
#include "PSMGLES/taiutils.h"
#include "PSMGLES/exports.h"

static SceUID psmID, shacccgID, monoBridgeID;
SceBool pgl_initialized = SCE_FALSE;

typedef struct _psmSysModule {
    int HTTP, NP, SSL, LOCATION, SHUTTER;
} psmSysModule;

static void patchShacccg (void)
{
    uint32_t *g_flag_a;
    uint32_t *g_flag_b;
    tai_module_info_t tai_info;
    int (*_SceShaccCg_6F01D573)(void *(*malloc_f)(uint32_t), void (*free_f)(void *));
    getModuleInfo(&tai_info);
    module_get_export_func("SceShaccCg", 0xA05BBEBB, 0x6F01D573, &_SceShaccCg_6F01D573);
    module_get_offset(tai_info.modid, 1, 0xEEC, &g_flag_a);
    module_get_offset(tai_info.modid, 1, 0xEF0, &g_flag_b);
    _SceShaccCg_6F01D573(malloc, free);
    *g_flag_a = 1;
    *g_flag_b = 1;
}

SceBool pglIsInit (void)
{
    return pgl_initialized;
}

int pglInit (void)
{
    if (pgl_initialized)
        return 1;
    int ret;
    psmSysModule disabledModules = {0,0,0,0,0};
    memset(&ret, 0, 4);
    if(sceSysmoduleIsLoaded(SCE_SYSMODULE_HTTP))
    {
        disabledModules.HTTP = 1;
        sceSysmoduleLoadModule(SCE_SYSMODULE_HTTP);
    }
    if(sceSysmoduleIsLoaded(SCE_SYSMODULE_NP))
    {
        disabledModules.NP = 1;
        sceSysmoduleLoadModule(SCE_SYSMODULE_NP);
    }
    if(sceSysmoduleIsLoaded(SCE_SYSMODULE_SSL))
    {
        disabledModules.SSL = 1;
        sceSysmoduleLoadModule(SCE_SYSMODULE_SSL);
    }
    if(sceSysmoduleIsLoaded(SCE_SYSMODULE_LOCATION))
    {
        disabledModules.LOCATION = 1;
        sceSysmoduleLoadModule(SCE_SYSMODULE_LOCATION);
    }
    if(sceSysmoduleIsLoaded(SCE_SYSMODULE_SHUTTER_SOUND))
    {
        disabledModules.SHUTTER = 1;
        sceSysmoduleLoadModule(SCE_SYSMODULE_SHUTTER_SOUND);
    }

    psmID = sceKernelLoadStartModule("app0:modules/libpsm.suprx", 0, SCE_NULL, 0, SCE_NULL, SCE_NULL);
    if (psmID < 0)
        return -1;
    monoBridgeID = sceKernelLoadStartModule("app0:modules/libmono_bridge.suprx", 0, SCE_NULL, 0, SCE_NULL, SCE_NULL);
    if (monoBridgeID < 0)
        return -1;
    shacccgID = sceKernelLoadStartModule("app0:modules/libshacccg.suprx", 0, SCE_NULL, 0, SCE_NULL, SCE_NULL);
    if (shacccgID < 0)
        return -1;
    patchShacccg();
    int exported;
    if (exported = exportAll(), exported)
    {
        printf("Failed to Export Functions! %d", exported);
        return -2;
    }
    if (disabledModules.HTTP)
        sceSysmoduleUnloadModule(SCE_SYSMODULE_HTTP);
    if (disabledModules.NP)
        sceSysmoduleUnloadModule(SCE_SYSMODULE_NP);
    if (disabledModules.SSL)
        sceSysmoduleUnloadModule(SCE_SYSMODULE_SSL);
    if (disabledModules.LOCATION)
        sceSysmoduleUnloadModule(SCE_SYSMODULE_LOCATION);
    if (disabledModules.SHUTTER)
        sceSysmoduleUnloadModule(SCE_SYSMODULE_SHUTTER_SOUND);
    pgl_initialized = SCE_TRUE;
    return 0;
}
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

static void patchShacccg (void)
{
    uint32_t *g_flag_a;
    uint32_t *g_flag_b;
    tai_module_info_t tai_info;
    getModuleInfo(&tai_info);
    int (*_SceShaccCg_6F01D573)(void *(*malloc_f)(uint32_t), void (*free_f)(void *));
    module_get_export_func("SceShaccCg", 0xA05BBEBB, 0x6F01D573, &_SceShaccCg_6F01D573);
    module_get_offset(tai_info.modid, 1, 0xEEC, &g_flag_a);
    module_get_offset(tai_info.modid, 1, 0xEF0, &g_flag_b);
    _SceShaccCg_6F01D573(malloc, free);
    *g_flag_a = 1;
    *g_flag_b = 1;
}

int psmglInit (void)
{
    int ret;
    memset(&ret, 0, 4);
    sceSysmoduleLoadModule(SCE_SYSMODULE_HTTP);
    sceSysmoduleLoadModule(SCE_SYSMODULE_NP);
    sceSysmoduleLoadModule(SCE_SYSMODULE_SSL);
    sceSysmoduleLoadModule(SCE_SYSMODULE_LOCATION);
    sceSysmoduleLoadModule(SCE_SYSMODULE_SHUTTER_SOUND);

    int statusPSM = 0;
    psmID = sceKernelLoadStartModule("app0:modules/libpsm.suprx", 0, SCE_NULL, 0, SCE_NULL, &statusPSM);
    printf("libpsm() 0x%08x\n", psmID);
    if (psmID < 0)
        return 1;
    int statusMonoBridge = 0;
    monoBridgeID = sceKernelLoadStartModule("app0:modules/libmono_bridge.suprx", 0, SCE_NULL, 0, SCE_NULL, &statusMonoBridge);
    printf("libmono_bridge() 0x%08x\n", monoBridgeID);
    if (monoBridgeID < 0)
        return 1;
    int statusshaq = 0;
    shacccgID = sceKernelLoadStartModule("app0:modules/libshacccg.suprx", 0, SCE_NULL, 0, SCE_NULL, &statusshaq);
    printf("libshacccg() 0x%08x\n", shacccgID);
    if (shacccgID < 0)
        return 1;
    patchShacccg();
    exportAll();
    sceSysmoduleUnloadModule(SCE_SYSMODULE_HTTP);
    sceSysmoduleUnloadModule(SCE_SYSMODULE_NP);
    sceSysmoduleUnloadModule(SCE_SYSMODULE_SSL);
    sceSysmoduleUnloadModule(SCE_SYSMODULE_LOCATION);
    sceSysmoduleUnloadModule(SCE_SYSMODULE_SHUTTER_SOUND);
    return 0;
}
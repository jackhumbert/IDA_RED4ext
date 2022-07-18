#include <idc.idc>
#include "RED4ext_Helper.idc"
#include "RED4ext_CName.idc"
#include "RED4ext_CBaseRTTIType.idc"
#include "RED4ext_CClass_EFlags.idc"
#include "RED4ext_CProperty.idc"

static main(void)
{
    RED4ext_CClass();
}

static RED4ext_CClass_Header() {
    add_struc(-1,"RED4ext::CClass",0);
}

static RED4ext_CClass() {
    Message("Adding RED4ext::CClass\n");
    IncludeType("RED4ext::CBaseRTTIType");
    IncludeType("RED4ext::CName");
    IncludeType("RED4ext::CProperty");
    IncludeType("RED4ext::CClass::EFlags");
    
    add_struc(-1,"RED4ext::CClass",0);
    
    set_local_type(-1, "struct __cppobj RED4ext::CClass_vtbl : RED4ext::CBaseRTTIType_vtbl {" +
        "void (*sub_C0)(RED4ext::CClass *);"+
        "uint32_t (*GetMaxAlignment)(RED4ext::CClass *);"+
        "void (*sub_D0)(RED4ext::CClass *);"+
        "void (*ConstructCls)(RED4ext::CClass *, void *);"+
        "void (*DestructCls)(RED4ext::CClass *, void *);"+
        "void *(*AllocMemory)(RED4ext::CClass *);"+
    "}", PT_REPLACE);
    import_type(-1, "RED4ext::CClass_vtbl");  

    set_local_type(-1, "struct __cppobj RED4ext::CClass : RED4ext::CBaseRTTIType {" +
        "RED4ext::CClass *parent;" +
        "RED4ext::CName name;" +
        "RED4ext::CName computedName;" +
        DynArray("RED4ext::CProperty *") + " props;" +
        DynArray("RED4ext::CProperty *") + " overriddenProps;" +
        // DynArray("RED4ext::CClassFunction *") + " funcs;" +
        // DynArray("RED4ext::CClassStaticFunction *") + " staticFuncs;" +
        "uint32_t size;" +
        "uint32_t holderSize;" +
        // "RED4ext::CClass::EFlags flags;" +
        "uint32_t alignment;" +
        HashMap("void*","void*") + " unk78;" +
    "};", PT_REPLACE);
    import_type(-1, "RED4ext::CClass");  
}
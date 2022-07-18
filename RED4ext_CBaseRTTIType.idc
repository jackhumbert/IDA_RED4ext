    
#include <idc.idc>
#include "RED4ext_Helper.idc"
#include "RED4ext_CName.idc"
#include "RED4ext_CString.idc"

static RED4ext_CBaseRTTIType() {
    IncludeType("RED4ext::CString");
    IncludeType("RED4ext::CName");

    Message("Adding RED4ext::CBaseRTTIType\n");
    // auto vftId = get_struc_id("RED4ext::CBaseRTTIType_vtbl");
    // if (vftId == -1) {
    //     vftId = add_struc(-1,"RED4ext::CBaseRTTIType_vtbl",0);
    // }    
    
    auto id = get_struc_id("RED4ext::CBaseRTTIType");
    if (id == -1) {
        id = add_struc(-1,"RED4ext::CBaseRTTIType",0);
    }

    set_local_type(-1, "struct __cppobj RED4ext::CBaseRTTIType_vtbl {" +
        "void (* Destroy)(RED4ext::CBaseRTTIType *);" +
        "RED4ext::CName (* GetName)(RED4ext::CBaseRTTIType *);" +
        "uint32_t (* GetSize)(RED4ext::CBaseRTTIType *);" + 
        "uint32_t (* GetAlignment)(RED4ext::CBaseRTTIType *);" +
        "void * (* GetType)(RED4ext::CBaseRTTIType *);" +  
        "RED4ext::CString (* GetTypeName)(RED4ext::CBaseRTTIType *);" + 
        "RED4ext::CName (* GetComputedName)(RED4ext::CBaseRTTIType *);" + 
        "void (* Construct)(RED4ext::CBaseRTTIType *, void * aMemory);" + 
        "void (* Destruct)(RED4ext::CBaseRTTIType *, void * aMemory);" +
        "bool (* IsEqual)(RED4ext::CBaseRTTIType *,  void * aLhs,  void * aRhs, uint32_t a3);" +
        "void (* Assign)(RED4ext::CBaseRTTIType *, void * aLhs,  void * aRhs);" + 
        "void (* Move)(RED4ext::CBaseRTTIType *, void * aLhs, void * aRhs);" +          
        "bool (* Unserialize)(RED4ext::CBaseRTTIType *, void* aStream, void * aInstance, __int64 a3);" + 
        "bool (* ToString)(RED4ext::CBaseRTTIType *,  void * aInstance, RED4ext::CString* aOut);" +
        "bool (* FromString)(RED4ext::CBaseRTTIType *, void * aInstance,  RED4ext::CString* aString);" + 
        "bool (* sub_78)(RED4ext::CBaseRTTIType *);" +
        "bool (* sub_80)(RED4ext::CBaseRTTIType *, __int64 a1, void * aInstance); " +                          
        "bool (* sub_88)(RED4ext::CBaseRTTIType *, __int64 a1, void * aInstance); " +                               
        "bool (* sub_90)(RED4ext::CBaseRTTIType *, __int64 a1, void * aInstance, RED4ext::CString* a3, __int64 a4); " +
        "bool (* sub_98)(RED4ext::CBaseRTTIType *, __int64 a1, void * aInstance, RED4ext::CString* a3, __int64 a4, bool a5); " +
        "bool (* sub_A0)(RED4ext::CBaseRTTIType *, __int64 a1, RED4ext::CString* a2, bool a3); " +
        "bool (* sub_A8)(RED4ext::CBaseRTTIType *); " +
        "void (* sub_B0)(RED4ext::CBaseRTTIType *, __int64 a1, __int64 a2);  " +
        "void * (* GetAllocator)(RED4ext::CBaseRTTIType *);" +
    "};", PT_REPLACE);
    import_type(-1, "RED4ext::CBaseRTTIType_vtbl");  

    // add_struc_member(vftId, "Destruct", 0x00, FF_QWORD | FF_1OFF | FF_0OFF, 0, 8, 0x01CFE80, 0, REFINFO_RVA);
    // add_struc_member(vftId, "GetName", 0x08, FF_QWORD | FF_1OFF | FF_0OFF, 0, 8, 0x01CFE80, 0, REFINFO_RVA);
    // add_struc_member(vftId, "GetSize", 0x10, FF_QWORD | FF_1OFF | FF_0OFF, 0, 8, 0x01CFE80, 0, REFINFO_RVA);
    // add_struc_member(vftId, "GetAlignment", 0x18, FF_QWORD | FF_1OFF | FF_0OFF, 0, 8, 0x01CFE80, 0, REFINFO_RVA);



    // add_struc_member(id,"__vftable", 0, 0x35500400, -1, 8, -1, 0, 0x000009);
    add_struc_member(id, "__vftable", 0, FF_QWORD | FF_1OFF | FF_0OFF, 0, 8, 0x321FB70, 0, REFINFO_RVA);
        SetType(get_member_id(id, 0x0), "RED4ext::CBaseRTTIType_vtbl *");
    add_struc_member(id,"unk8", 0X8, 0x30000400, -1, 8);
    // set_struc_align(id,4);

    
    // SetType(get_member_id(vftId, 0x00), "void (*Destruct)(RED4ext::CBaseRTTIType *)");
    // IncludeType("RED4ext::CName");
    // SetType(get_member_id(vftId, 0x08), "RED4ext::CName (*GetName)(RED4ext::CBaseRTTIType *)");
    // SetType(get_member_id(vftId, 0x10), "__int32 (*GetSize)(RED4ext::CBaseRTTIType *)");
    // SetType(get_member_id(vftId, 0x18), "__int32 (*GetAlignment)(RED4ext::CBaseRTTIType *)");
}

static main(void)
{
    RED4ext_CBaseRTTIType();
}
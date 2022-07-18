#include <idc.idc>
#include "RED4ext_Helper.idc"
#include "RED4ext_CName.idc"
#include "RED4ext_CBaseRTTIType.idc"

static main(void)
{
    RED4ext_CProperty();
}

static RED4ext_CProperty() {
    Message("Adding RED4ext::CProperty\n");

    IncludeType("RED4ext::CBaseRTTIType");
    IncludeType("RED4ext::CName");
    IncludeTypeHeader("RED4ext::CClass");

    set_local_type(-1, "enum RED4ext::CProperty::EFlags : __int64 {" +
        "RED4ext_CProperty_isEditable = 0x1,     " +
        "RED4ext_CProperty_isNotSerializable = 0x2, " +
        "RED4ext_CProperty_isInline = 0x4,       " +
        "RED4ext_CProperty_b3 = 0x8,             " +
        "RED4ext_CProperty_b4 = 0x10,             " +
        "RED4ext_CProperty_hasDefault = 0x20,     " +
        "RED4ext_CProperty_isReturn = 0x40,       " +
        "RED4ext_CProperty_b7 = 0x80,             " +
        "RED4ext_CProperty_isLocalVar = 0x100,     " +
        "RED4ext_CProperty_isOut = 0x200,          " +
        "RED4ext_CProperty_isOptional = 0x400,     " +
        "RED4ext_CProperty_b11 = 0x800,            " +
        "RED4ext_CProperty_b12 = 0x1000,            " +
        "RED4ext_CProperty_b13 = 0x2000,            " +
        "RED4ext_CProperty_isOverriding = 0x4000,   " +
        "RED4ext_CProperty_b15 = 0x8000,            " +
        "RED4ext_CProperty_isPrivate = 0x10000,      " +
        "RED4ext_CProperty_isProtected = 0x20000,    " +
        "RED4ext_CProperty_isPublic = 0x40000,       " +
        "RED4ext_CProperty_b19 = 0x80000,            " +
        "RED4ext_CProperty_hasValueHolder = 0x100000, " +
        "RED4ext_CProperty_arrayRelated = 0x200000,   " +
        "RED4ext_CProperty_isHandle = 0x400000,       " +
        "RED4ext_CProperty_isPersistent = 0x800000,   " +
        "RED4ext_CProperty_b29 = 0x1000000,            " +
        "RED4ext_CProperty_hasHint = 0x2000000,        " +
        "RED4ext_CProperty_hasInnerType = 0x4000000,   " +
        "RED4ext_CProperty_isNotPersistent = 0x8000000," +
        "RED4ext_CProperty_isSavable = 0x10000000,      " +
        "RED4ext_CProperty_b34 = 0x20000000,            " +
        "RED4ext_CProperty_arrayRelated2 = 0x40000000,  " +
        "RED4ext_CProperty_b36 = 0x80000000,            " +
        "RED4ext_CProperty_isNotSavable = 0x100000000,   " +
    "};", PT_REPLACE);
    import_type(-1, "RED4ext::CProperty::EFlags");  

    set_local_type(-1, "struct RED4ext::CProperty {" + 
        "RED4ext::CBaseRTTIType* type;" + 
        "RED4ext::CName name;" + 
        "RED4ext::CName group;" + 
        "RED4ext::CClass* parent;" + 
        "uint32_t valueOffset;" + 
        "uint32_t scriptRefValueOffset;" + 
        "RED4ext::CProperty::EFlags flags;" +
    "};", PT_REPLACE);
    import_type(-1, "RED4ext::CProperty");  
        // id = import_type(-1, "RED4ext::CClass");
        // id = add_struc(-1, "RED4ext::CClass", 0);
    // add_struc_member(id, "baseclass_0", 0, 0x60000400, typeId, get_struc_size(typeId));
    // SetType(get_member_id(id, 0x00), "RED4ext::CBaseRTTIType");
    // add_struc_member(id, "parent", 0x10, FF_QWORD | FF_1OFF | FF_0OFF, 0, 8, 0, 0, REFINFO_RVA);
        // SetType(get_member_id(id, 0x10), "RED4ext::Class *");
    // add_struc_member(id, "name", 0X18, 0x60000400, IncludeType("RED4ext::CName"), 8);
    // add_struc_member(id, "computedName", 0X20, 0x60000400, IncludeType("RED4ext::CName"), 8);
    // add_struc_member(id,"props", 0X28, 0x60000400, get_struc_id("RED4ext::DynArray_RED4ext::CProperty"), 16);
    // set_struc_align(id,2);
}
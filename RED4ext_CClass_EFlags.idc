#include <idc.idc>
#include "RED4ext_Helper.idc"

static RED4ext_CClass_EFlags() {
    Message("Adding RED4ext::CClass::EFlags\n");
    auto id = get_enum("RED4ext::CClass::EFlags");
    if (id == -1) {
	    id = add_enum(-1,"RED4ext::CClass::EFlags",0x1100000);
    }

	set_enum_bf(id,1);
	add_enum_member(id,"RED4ext_CClass_EFlags_isAbstract",	0X1,	0x1);
	add_enum_member(id,"RED4ext_CClass_EFlags_isNative",	0X2,	0x2);
	add_enum_member(id,"RED4ext_CClass_EFlags_isScriptedClass",	0X4,	0x4);
	add_enum_member(id,"RED4ext_CClass_EFlags_isScriptedStruct",	0X8,	0x8);
	add_enum_member(id,"RED4ext_CClass_EFlags_hasNoDefaultObjectSerialization",	0X10,	0x10);
	add_enum_member(id,"RED4ext_CClass_EFlags_isAlwaysTransient",	0X20,	0x20);
	add_enum_member(id,"RED4ext_CClass_EFlags_isImportOnly",	0X40,	0x40);
	add_enum_member(id,"RED4ext_CClass_EFlags_isPrivate",	0X80,	0x80);
	add_enum_member(id,"RED4ext_CClass_EFlags_isProtected",	0X100,	0x100);
	add_enum_member(id,"RED4ext_CClass_EFlags_isTestOnly",	0X200,	0x200);
	add_enum_member(id,"RED4ext_CClass_EFlags_isSavable",	0X400,	0x400);
	add_enum_member(id,"RED4ext_CClass_EFlags_b10",	0X800,	0x800);
	add_enum_member(id,"RED4ext_CClass_EFlags_b11",	0X1000,	0x1000);
	add_enum_member(id,"RED4ext_CClass_EFlags_isTestOnly2",	0X2000,	0x2000);
	add_enum_member(id,"RED4ext_CClass_EFlags_b13",	0X4000,	0x4000);
	add_enum_member(id,"RED4ext_CClass_EFlags_b14",	0X8000,	0x8000);
}

static main(void)
{
    RED4ext_CClass_EFlags();
}
#include <idc.idc>
#include "RED4ext_Helper.idc"

static RED4ext_CName() {
    Message("Adding RED4ext::CName\n");
    auto id = get_struc_id("RED4ext::CName");
    if (id == -1) {
        id = add_struc(-1,"RED4ext::CName",0);
    }
    del_struc_member(id, 0);
    add_struc_member(id,"hash", 0, FF_QWORD, -1, 8);
}

static main(void)
{
    RED4ext_CName();
}
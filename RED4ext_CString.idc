#include <idc.idc>
#include "RED4ext_Helper.idc"

static RED4ext_CString() {
    Message("Adding RED4ext::CString\n");

    set_local_type(-1, "struct RED4ext::CString {" +
        "char * ptr;" +
        "int8_t unk[8];" +
        "uint32_t capacity;" +
        "uint32_t length;" +
        "void * allocator;" +
    "};", PT_REPLACE);
    import_type(-1, "RED4ext::CString");  
}

static main(void)
{
    RED4ext_CString();
}
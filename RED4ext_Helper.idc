#include <idc.idc>

static SanitizeNamspace(str) {
    auto pos = strstr(str, "::", 0);
    auto newStr = str;
    while (pos != -1) {
        auto len = strlen(newStr);
        newStr = substr(newStr, 0, pos) + "_" + substr(newStr, pos + 2, len);
        pos = strstr(newStr, "::", 0);
    }
    return newStr;
}

static SanitizePointer(str) {
    auto pos = strstr(str, " *", 0);
    auto newStr = str;
    auto len = strlen(newStr);
    if (pos != -1) {
        newStr = substr(newStr, 0, pos) + "_p" + substr(newStr, pos + 2, len);
    } else {
        pos = strstr(str, "*", 0);
        if (pos != -1) {
            newStr = substr(newStr, 0, pos) + "_p" + substr(newStr, pos + 2, len);
        }
    }
    return newStr;
}

static GetTypeId(type) {
    auto id = get_struc_id(type);
    if (id == -1) {
        id = get_enum(type);
    }
    return id;
}

static IncludeType(type) {
    auto typeClean = SanitizeNamspace(type);
    Message("Getting type: " + type + "\n");
    auto id = GetTypeId(type);
    if (id == -1) {
        // auto filepath = "C:\\Users\\Jack\\Documents\\cyberpunk\\" + typeClean + ".idc";
        // Message("* Loading from file: " + filepath + "\n");
        // auto compileError = compile_idc_file(filepath);
        // if (compileError != 0) {
        //     Message("E Could not compile file:\n");
        //     Message("  " + compileError + "\n");
        //     return id;
        // }
        Message("Loading type: " + type + "\n");
        if (exec_idc(typeClean + "();") != 1) {
            Message("E Could not execute file's function: " + typeClean + "()\n");
            return id;
        }
        id = GetTypeId(type);
    }
    return id;
}

static IncludeTypeHeader(type) {
    auto typeClean = SanitizeNamspace(type);
    Message("Getting type header: " + type + "\n");
    auto id = GetTypeId(type);
    if (id == -1) {
        // auto filepath = "C:\\Users\\Jack\\Documents\\cyberpunk\\" + typeClean + ".idc";
        // Message("* Loading from file: " + filepath + "\n");
        // auto compileError = compile_idc_file(filepath);
        // if (compileError != 0) {
        //     Message("E Could not compile file:\n");
        //     Message("  " + compileError + "\n");
        //     return id;
        // }
        Message("Loading type header: " + type + "\n");
        if (exec_idc(typeClean + "_Header();") != 1) {
            Message("E Could not execute file's function: " + typeClean + "_Header()\n");
            return id;
        }
        id = GetTypeId(type);
    }
    return id;
}

static DynArray(innerType) {
    auto innerType_s = SanitizePointer(innerType);
    auto innerId = get_struc_id(innerType);
    auto type = "RED4ext::DynArray_" + innerType_s;
    auto id = get_struc_id(type);
    if (id == -1) { id = add_struc(-1, type, 0); }
    add_struc_member(id,"entries", 0, 0x35500400, 0XFFFFFFFFFFFFFFFF, 8, 0XFFFFFFFFFFFFFFFF, 0, 0x9);
    SetType(get_member_id(id, 0x0), innerType + " *");
    add_struc_member(id, "capacity", 8, FF_DWORD, 0, 4);
    SetType(get_member_id(id, 0x8), "unsigned __int32");
    add_struc_member(id, "size", 0xC, FF_DWORD, 0, 4);
    SetType(get_member_id(id, 0xC), "unsigned __int32");
    return type;
}

static HashMap(key, value) {
    auto key_s = SanitizePointer(key);
    auto value_s = SanitizePointer(value);
    auto keyId = get_struc_id(key);
    auto keySize = sizeof(key);
    if (keySize == -1) {
        keySize = 8;
    }
    auto valueId = get_struc_id(value);
    auto hashMapType = "RED4ext::HashMap_" + key_s + "_" + value_s;
    auto nodeListType = "RED4ext::HashMap::NodeList_" + key_s + "_" + value_s;
    auto nodeType = "RED4ext::HashMap::Node_" + key_s + "_" + value_s;

    auto nodeId = get_struc_id(nodeType);
    if (nodeId == -1) { nodeId = add_struc(-1, nodeType, 0); }
    add_struc_member(nodeId, "next", 0x0, FF_DWORD, 0, 4);
    add_struc_member(nodeId, "hashedKey", 0x4, FF_DWORD, 0, 4);
    add_struc_member(nodeId, "key", 0x8, 0, 0, keySize);
    SetType(get_member_id(nodeId, 0x8), key);
    add_struc_member(nodeId, "value", 0x8 + keySize, 0, 0, sizeof(value));
    SetType(get_member_id(nodeId, 0x8 + keySize), value);

    auto nodeListId = get_struc_id(nodeListType);
    if (nodeListId == -1) { nodeListId = add_struc(-1, nodeListType, 0); }
    add_struc_member(nodeListId,"nodes", 0, 0x35500400, 0XFFFFFFFFFFFFFFFF, 8, 0XFFFFFFFFFFFFFFFF, 0, 0x9);
    SetType(get_member_id(nodeListId, 0x0), nodeType + " *");
    add_struc_member(nodeListId, "capacity", 0x8, FF_DWORD, 0, 4);
    SetType(get_member_id(nodeListId, 0x8), "unsigned __int32");
    add_struc_member(nodeListId, "stride", 0xC, FF_DWORD, 0, 4);
    SetType(get_member_id(nodeListId, 0xC), "unsigned __int32");
    add_struc_member(nodeListId, "nextIdx", 0x10, FF_DWORD, 0, 4);
    add_struc_member(nodeListId, "size", 0x14, FF_DWORD, 0, 4);
    SetType(get_member_id(nodeListId, 0x14), "unsigned __int32");

    auto hashMapId = get_struc_id(hashMapType);
    if (hashMapId == -1) { hashMapId = add_struc(-1, hashMapType, 0); }
    add_struc_member(hashMapId,"entries", 0, 0x35500400, 0XFFFFFFFFFFFFFFFF, 8, 0XFFFFFFFFFFFFFFFF, 0, 0x9);
    SetType(get_member_id(hashMapId, 0x0), "unsigned __int32 *");
    add_struc_member(hashMapId, "size", 0x8, FF_DWORD, 0, 4);
    SetType(get_member_id(hashMapId, 0x8), "unsigned __int32");
    add_struc_member(hashMapId, "capacity", 0xC, FF_DWORD, 0, 4);
    SetType(get_member_id(hashMapId, 0xC), "unsigned __int32");
    add_struc_member(hashMapId, "nodeList", 0x10, FF_STRUCT, 0, 0x18);
    SetType(get_member_id(hashMapId, 0x10), nodeListType);
    add_struc_member(hashMapId, "allocator", 0x28, FF_QWORD, 0, 8);
    return hashMapType;
}
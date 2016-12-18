import os
import sys

def generate_begin():
    return \
        "#pragma once\n\n" \
        "#include \"orm_object.h\"\n\n" \
        "#define SQLITE_ORM_BEGIN(OBJECT_NAME) \\\n" \
            "struct OBJECT_NAME : public SQLiteORM::Row \\\n" \
            "{ \\\n" \
                "OBJECT_NAME() { \\\n" \
				"setName(#OBJECT_NAME); \n\n";

def generate_member(param_count):
    full_content = ""
    member = ""
    member_pattern = "MEMBER%s,"
    for t in range(1, param_count + 1):
        member += member_pattern % (t)
    member = member[:-1]
    full_content += "#define SQLITE_ORM_INITIALIZER%d(%s) \\\n" % (param_count, member)
    full_content += "m_col_list.resize(%d); \\\n" % (param_count)
    member_intialize = \
        "m_col_list[%d-1] = &MEMBER%d; \\\n" \
        "m_col_list[%d-1]->setName(#MEMBER%d); \\\n"
    for t in range(1, param_count + 1):
        full_content += member_intialize % (t, t, t, t)
    full_content += "} \\\n"
    for t in range(1, param_count + 1):
        pattern_list = \
            [
                "SQLiteORM::Column2 MEMBER%d; \\\n" % (t),
            ]            
        for i in pattern_list:
            full_content += i            
    full_content += "\n"
    return full_content

def generate_end():
    return "#define SQLITE_ORM_END() };\n"

def generate_full(param_count):
    print("=== Begin generate orm_marco.h ===")
    full_content = generate_begin()
    for t in range(1, param_count + 1):
        full_content += generate_member(t)
    full_content += generate_end()
    print("=== End generate orm_marco.h ===")
    return full_content

cpp_content = generate_full(20)

path = os.path.realpath(sys.argv[0])  
if os.path.isfile(path):  
    path = os.path.dirname(path)
path += "\\orm_macro.h"

f = open(path, "w")
f.write(cpp_content)


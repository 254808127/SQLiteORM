#pragma once

#include "orm_object.h"

#define SQLITE_ORM_BEGIN(OBJECT_NAME) \
struct OBJECT_NAME : public SQLiteORM::Row \
{ \
OBJECT_NAME() { \
setName(#OBJECT_NAME); 

#define SQLITE_ORM_INITIALIZER1(MEMBER1) \
m_col_list.resize(1); \
m_col_list[1-1] = &MEMBER1; \
m_col_list[1-1]->setName(#MEMBER1); \
} \
SQLiteORM::Column2 MEMBER1; \

#define SQLITE_ORM_INITIALIZER2(MEMBER1,MEMBER2) \
m_col_list.resize(2); \
m_col_list[1-1] = &MEMBER1; \
m_col_list[1-1]->setName(#MEMBER1); \
m_col_list[2-1] = &MEMBER2; \
m_col_list[2-1]->setName(#MEMBER2); \
} \
SQLiteORM::Column2 MEMBER1; \
SQLiteORM::Column2 MEMBER2; \

#define SQLITE_ORM_INITIALIZER3(MEMBER1,MEMBER2,MEMBER3) \
m_col_list.resize(3); \
m_col_list[1-1] = &MEMBER1; \
m_col_list[1-1]->setName(#MEMBER1); \
m_col_list[2-1] = &MEMBER2; \
m_col_list[2-1]->setName(#MEMBER2); \
m_col_list[3-1] = &MEMBER3; \
m_col_list[3-1]->setName(#MEMBER3); \
} \
SQLiteORM::Column2 MEMBER1; \
SQLiteORM::Column2 MEMBER2; \
SQLiteORM::Column2 MEMBER3; \

#define SQLITE_ORM_INITIALIZER4(MEMBER1,MEMBER2,MEMBER3,MEMBER4) \
m_col_list.resize(4); \
m_col_list[1-1] = &MEMBER1; \
m_col_list[1-1]->setName(#MEMBER1); \
m_col_list[2-1] = &MEMBER2; \
m_col_list[2-1]->setName(#MEMBER2); \
m_col_list[3-1] = &MEMBER3; \
m_col_list[3-1]->setName(#MEMBER3); \
m_col_list[4-1] = &MEMBER4; \
m_col_list[4-1]->setName(#MEMBER4); \
} \
SQLiteORM::Column2 MEMBER1; \
SQLiteORM::Column2 MEMBER2; \
SQLiteORM::Column2 MEMBER3; \
SQLiteORM::Column2 MEMBER4; \

#define SQLITE_ORM_INITIALIZER5(MEMBER1,MEMBER2,MEMBER3,MEMBER4,MEMBER5) \
m_col_list.resize(5); \
m_col_list[1-1] = &MEMBER1; \
m_col_list[1-1]->setName(#MEMBER1); \
m_col_list[2-1] = &MEMBER2; \
m_col_list[2-1]->setName(#MEMBER2); \
m_col_list[3-1] = &MEMBER3; \
m_col_list[3-1]->setName(#MEMBER3); \
m_col_list[4-1] = &MEMBER4; \
m_col_list[4-1]->setName(#MEMBER4); \
m_col_list[5-1] = &MEMBER5; \
m_col_list[5-1]->setName(#MEMBER5); \
} \
SQLiteORM::Column2 MEMBER1; \
SQLiteORM::Column2 MEMBER2; \
SQLiteORM::Column2 MEMBER3; \
SQLiteORM::Column2 MEMBER4; \
SQLiteORM::Column2 MEMBER5; \

#define SQLITE_ORM_INITIALIZER6(MEMBER1,MEMBER2,MEMBER3,MEMBER4,MEMBER5,MEMBER6) \
m_col_list.resize(6); \
m_col_list[1-1] = &MEMBER1; \
m_col_list[1-1]->setName(#MEMBER1); \
m_col_list[2-1] = &MEMBER2; \
m_col_list[2-1]->setName(#MEMBER2); \
m_col_list[3-1] = &MEMBER3; \
m_col_list[3-1]->setName(#MEMBER3); \
m_col_list[4-1] = &MEMBER4; \
m_col_list[4-1]->setName(#MEMBER4); \
m_col_list[5-1] = &MEMBER5; \
m_col_list[5-1]->setName(#MEMBER5); \
m_col_list[6-1] = &MEMBER6; \
m_col_list[6-1]->setName(#MEMBER6); \
} \
SQLiteORM::Column2 MEMBER1; \
SQLiteORM::Column2 MEMBER2; \
SQLiteORM::Column2 MEMBER3; \
SQLiteORM::Column2 MEMBER4; \
SQLiteORM::Column2 MEMBER5; \
SQLiteORM::Column2 MEMBER6; \

#define SQLITE_ORM_INITIALIZER7(MEMBER1,MEMBER2,MEMBER3,MEMBER4,MEMBER5,MEMBER6,MEMBER7) \
m_col_list.resize(7); \
m_col_list[1-1] = &MEMBER1; \
m_col_list[1-1]->setName(#MEMBER1); \
m_col_list[2-1] = &MEMBER2; \
m_col_list[2-1]->setName(#MEMBER2); \
m_col_list[3-1] = &MEMBER3; \
m_col_list[3-1]->setName(#MEMBER3); \
m_col_list[4-1] = &MEMBER4; \
m_col_list[4-1]->setName(#MEMBER4); \
m_col_list[5-1] = &MEMBER5; \
m_col_list[5-1]->setName(#MEMBER5); \
m_col_list[6-1] = &MEMBER6; \
m_col_list[6-1]->setName(#MEMBER6); \
m_col_list[7-1] = &MEMBER7; \
m_col_list[7-1]->setName(#MEMBER7); \
} \
SQLiteORM::Column2 MEMBER1; \
SQLiteORM::Column2 MEMBER2; \
SQLiteORM::Column2 MEMBER3; \
SQLiteORM::Column2 MEMBER4; \
SQLiteORM::Column2 MEMBER5; \
SQLiteORM::Column2 MEMBER6; \
SQLiteORM::Column2 MEMBER7; \

#define SQLITE_ORM_INITIALIZER8(MEMBER1,MEMBER2,MEMBER3,MEMBER4,MEMBER5,MEMBER6,MEMBER7,MEMBER8) \
m_col_list.resize(8); \
m_col_list[1-1] = &MEMBER1; \
m_col_list[1-1]->setName(#MEMBER1); \
m_col_list[2-1] = &MEMBER2; \
m_col_list[2-1]->setName(#MEMBER2); \
m_col_list[3-1] = &MEMBER3; \
m_col_list[3-1]->setName(#MEMBER3); \
m_col_list[4-1] = &MEMBER4; \
m_col_list[4-1]->setName(#MEMBER4); \
m_col_list[5-1] = &MEMBER5; \
m_col_list[5-1]->setName(#MEMBER5); \
m_col_list[6-1] = &MEMBER6; \
m_col_list[6-1]->setName(#MEMBER6); \
m_col_list[7-1] = &MEMBER7; \
m_col_list[7-1]->setName(#MEMBER7); \
m_col_list[8-1] = &MEMBER8; \
m_col_list[8-1]->setName(#MEMBER8); \
} \
SQLiteORM::Column2 MEMBER1; \
SQLiteORM::Column2 MEMBER2; \
SQLiteORM::Column2 MEMBER3; \
SQLiteORM::Column2 MEMBER4; \
SQLiteORM::Column2 MEMBER5; \
SQLiteORM::Column2 MEMBER6; \
SQLiteORM::Column2 MEMBER7; \
SQLiteORM::Column2 MEMBER8; \

#define SQLITE_ORM_INITIALIZER9(MEMBER1,MEMBER2,MEMBER3,MEMBER4,MEMBER5,MEMBER6,MEMBER7,MEMBER8,MEMBER9) \
m_col_list.resize(9); \
m_col_list[1-1] = &MEMBER1; \
m_col_list[1-1]->setName(#MEMBER1); \
m_col_list[2-1] = &MEMBER2; \
m_col_list[2-1]->setName(#MEMBER2); \
m_col_list[3-1] = &MEMBER3; \
m_col_list[3-1]->setName(#MEMBER3); \
m_col_list[4-1] = &MEMBER4; \
m_col_list[4-1]->setName(#MEMBER4); \
m_col_list[5-1] = &MEMBER5; \
m_col_list[5-1]->setName(#MEMBER5); \
m_col_list[6-1] = &MEMBER6; \
m_col_list[6-1]->setName(#MEMBER6); \
m_col_list[7-1] = &MEMBER7; \
m_col_list[7-1]->setName(#MEMBER7); \
m_col_list[8-1] = &MEMBER8; \
m_col_list[8-1]->setName(#MEMBER8); \
m_col_list[9-1] = &MEMBER9; \
m_col_list[9-1]->setName(#MEMBER9); \
} \
SQLiteORM::Column2 MEMBER1; \
SQLiteORM::Column2 MEMBER2; \
SQLiteORM::Column2 MEMBER3; \
SQLiteORM::Column2 MEMBER4; \
SQLiteORM::Column2 MEMBER5; \
SQLiteORM::Column2 MEMBER6; \
SQLiteORM::Column2 MEMBER7; \
SQLiteORM::Column2 MEMBER8; \
SQLiteORM::Column2 MEMBER9; \

#define SQLITE_ORM_INITIALIZER10(MEMBER1,MEMBER2,MEMBER3,MEMBER4,MEMBER5,MEMBER6,MEMBER7,MEMBER8,MEMBER9,MEMBER10) \
m_col_list.resize(10); \
m_col_list[1-1] = &MEMBER1; \
m_col_list[1-1]->setName(#MEMBER1); \
m_col_list[2-1] = &MEMBER2; \
m_col_list[2-1]->setName(#MEMBER2); \
m_col_list[3-1] = &MEMBER3; \
m_col_list[3-1]->setName(#MEMBER3); \
m_col_list[4-1] = &MEMBER4; \
m_col_list[4-1]->setName(#MEMBER4); \
m_col_list[5-1] = &MEMBER5; \
m_col_list[5-1]->setName(#MEMBER5); \
m_col_list[6-1] = &MEMBER6; \
m_col_list[6-1]->setName(#MEMBER6); \
m_col_list[7-1] = &MEMBER7; \
m_col_list[7-1]->setName(#MEMBER7); \
m_col_list[8-1] = &MEMBER8; \
m_col_list[8-1]->setName(#MEMBER8); \
m_col_list[9-1] = &MEMBER9; \
m_col_list[9-1]->setName(#MEMBER9); \
m_col_list[10-1] = &MEMBER10; \
m_col_list[10-1]->setName(#MEMBER10); \
} \
SQLiteORM::Column2 MEMBER1; \
SQLiteORM::Column2 MEMBER2; \
SQLiteORM::Column2 MEMBER3; \
SQLiteORM::Column2 MEMBER4; \
SQLiteORM::Column2 MEMBER5; \
SQLiteORM::Column2 MEMBER6; \
SQLiteORM::Column2 MEMBER7; \
SQLiteORM::Column2 MEMBER8; \
SQLiteORM::Column2 MEMBER9; \
SQLiteORM::Column2 MEMBER10; \

#define SQLITE_ORM_INITIALIZER11(MEMBER1,MEMBER2,MEMBER3,MEMBER4,MEMBER5,MEMBER6,MEMBER7,MEMBER8,MEMBER9,MEMBER10,MEMBER11) \
m_col_list.resize(11); \
m_col_list[1-1] = &MEMBER1; \
m_col_list[1-1]->setName(#MEMBER1); \
m_col_list[2-1] = &MEMBER2; \
m_col_list[2-1]->setName(#MEMBER2); \
m_col_list[3-1] = &MEMBER3; \
m_col_list[3-1]->setName(#MEMBER3); \
m_col_list[4-1] = &MEMBER4; \
m_col_list[4-1]->setName(#MEMBER4); \
m_col_list[5-1] = &MEMBER5; \
m_col_list[5-1]->setName(#MEMBER5); \
m_col_list[6-1] = &MEMBER6; \
m_col_list[6-1]->setName(#MEMBER6); \
m_col_list[7-1] = &MEMBER7; \
m_col_list[7-1]->setName(#MEMBER7); \
m_col_list[8-1] = &MEMBER8; \
m_col_list[8-1]->setName(#MEMBER8); \
m_col_list[9-1] = &MEMBER9; \
m_col_list[9-1]->setName(#MEMBER9); \
m_col_list[10-1] = &MEMBER10; \
m_col_list[10-1]->setName(#MEMBER10); \
m_col_list[11-1] = &MEMBER11; \
m_col_list[11-1]->setName(#MEMBER11); \
} \
SQLiteORM::Column2 MEMBER1; \
SQLiteORM::Column2 MEMBER2; \
SQLiteORM::Column2 MEMBER3; \
SQLiteORM::Column2 MEMBER4; \
SQLiteORM::Column2 MEMBER5; \
SQLiteORM::Column2 MEMBER6; \
SQLiteORM::Column2 MEMBER7; \
SQLiteORM::Column2 MEMBER8; \
SQLiteORM::Column2 MEMBER9; \
SQLiteORM::Column2 MEMBER10; \
SQLiteORM::Column2 MEMBER11; \

#define SQLITE_ORM_INITIALIZER12(MEMBER1,MEMBER2,MEMBER3,MEMBER4,MEMBER5,MEMBER6,MEMBER7,MEMBER8,MEMBER9,MEMBER10,MEMBER11,MEMBER12) \
m_col_list.resize(12); \
m_col_list[1-1] = &MEMBER1; \
m_col_list[1-1]->setName(#MEMBER1); \
m_col_list[2-1] = &MEMBER2; \
m_col_list[2-1]->setName(#MEMBER2); \
m_col_list[3-1] = &MEMBER3; \
m_col_list[3-1]->setName(#MEMBER3); \
m_col_list[4-1] = &MEMBER4; \
m_col_list[4-1]->setName(#MEMBER4); \
m_col_list[5-1] = &MEMBER5; \
m_col_list[5-1]->setName(#MEMBER5); \
m_col_list[6-1] = &MEMBER6; \
m_col_list[6-1]->setName(#MEMBER6); \
m_col_list[7-1] = &MEMBER7; \
m_col_list[7-1]->setName(#MEMBER7); \
m_col_list[8-1] = &MEMBER8; \
m_col_list[8-1]->setName(#MEMBER8); \
m_col_list[9-1] = &MEMBER9; \
m_col_list[9-1]->setName(#MEMBER9); \
m_col_list[10-1] = &MEMBER10; \
m_col_list[10-1]->setName(#MEMBER10); \
m_col_list[11-1] = &MEMBER11; \
m_col_list[11-1]->setName(#MEMBER11); \
m_col_list[12-1] = &MEMBER12; \
m_col_list[12-1]->setName(#MEMBER12); \
} \
SQLiteORM::Column2 MEMBER1; \
SQLiteORM::Column2 MEMBER2; \
SQLiteORM::Column2 MEMBER3; \
SQLiteORM::Column2 MEMBER4; \
SQLiteORM::Column2 MEMBER5; \
SQLiteORM::Column2 MEMBER6; \
SQLiteORM::Column2 MEMBER7; \
SQLiteORM::Column2 MEMBER8; \
SQLiteORM::Column2 MEMBER9; \
SQLiteORM::Column2 MEMBER10; \
SQLiteORM::Column2 MEMBER11; \
SQLiteORM::Column2 MEMBER12; \

#define SQLITE_ORM_INITIALIZER13(MEMBER1,MEMBER2,MEMBER3,MEMBER4,MEMBER5,MEMBER6,MEMBER7,MEMBER8,MEMBER9,MEMBER10,MEMBER11,MEMBER12,MEMBER13) \
m_col_list.resize(13); \
m_col_list[1-1] = &MEMBER1; \
m_col_list[1-1]->setName(#MEMBER1); \
m_col_list[2-1] = &MEMBER2; \
m_col_list[2-1]->setName(#MEMBER2); \
m_col_list[3-1] = &MEMBER3; \
m_col_list[3-1]->setName(#MEMBER3); \
m_col_list[4-1] = &MEMBER4; \
m_col_list[4-1]->setName(#MEMBER4); \
m_col_list[5-1] = &MEMBER5; \
m_col_list[5-1]->setName(#MEMBER5); \
m_col_list[6-1] = &MEMBER6; \
m_col_list[6-1]->setName(#MEMBER6); \
m_col_list[7-1] = &MEMBER7; \
m_col_list[7-1]->setName(#MEMBER7); \
m_col_list[8-1] = &MEMBER8; \
m_col_list[8-1]->setName(#MEMBER8); \
m_col_list[9-1] = &MEMBER9; \
m_col_list[9-1]->setName(#MEMBER9); \
m_col_list[10-1] = &MEMBER10; \
m_col_list[10-1]->setName(#MEMBER10); \
m_col_list[11-1] = &MEMBER11; \
m_col_list[11-1]->setName(#MEMBER11); \
m_col_list[12-1] = &MEMBER12; \
m_col_list[12-1]->setName(#MEMBER12); \
m_col_list[13-1] = &MEMBER13; \
m_col_list[13-1]->setName(#MEMBER13); \
} \
SQLiteORM::Column2 MEMBER1; \
SQLiteORM::Column2 MEMBER2; \
SQLiteORM::Column2 MEMBER3; \
SQLiteORM::Column2 MEMBER4; \
SQLiteORM::Column2 MEMBER5; \
SQLiteORM::Column2 MEMBER6; \
SQLiteORM::Column2 MEMBER7; \
SQLiteORM::Column2 MEMBER8; \
SQLiteORM::Column2 MEMBER9; \
SQLiteORM::Column2 MEMBER10; \
SQLiteORM::Column2 MEMBER11; \
SQLiteORM::Column2 MEMBER12; \
SQLiteORM::Column2 MEMBER13; \

#define SQLITE_ORM_INITIALIZER14(MEMBER1,MEMBER2,MEMBER3,MEMBER4,MEMBER5,MEMBER6,MEMBER7,MEMBER8,MEMBER9,MEMBER10,MEMBER11,MEMBER12,MEMBER13,MEMBER14) \
m_col_list.resize(14); \
m_col_list[1-1] = &MEMBER1; \
m_col_list[1-1]->setName(#MEMBER1); \
m_col_list[2-1] = &MEMBER2; \
m_col_list[2-1]->setName(#MEMBER2); \
m_col_list[3-1] = &MEMBER3; \
m_col_list[3-1]->setName(#MEMBER3); \
m_col_list[4-1] = &MEMBER4; \
m_col_list[4-1]->setName(#MEMBER4); \
m_col_list[5-1] = &MEMBER5; \
m_col_list[5-1]->setName(#MEMBER5); \
m_col_list[6-1] = &MEMBER6; \
m_col_list[6-1]->setName(#MEMBER6); \
m_col_list[7-1] = &MEMBER7; \
m_col_list[7-1]->setName(#MEMBER7); \
m_col_list[8-1] = &MEMBER8; \
m_col_list[8-1]->setName(#MEMBER8); \
m_col_list[9-1] = &MEMBER9; \
m_col_list[9-1]->setName(#MEMBER9); \
m_col_list[10-1] = &MEMBER10; \
m_col_list[10-1]->setName(#MEMBER10); \
m_col_list[11-1] = &MEMBER11; \
m_col_list[11-1]->setName(#MEMBER11); \
m_col_list[12-1] = &MEMBER12; \
m_col_list[12-1]->setName(#MEMBER12); \
m_col_list[13-1] = &MEMBER13; \
m_col_list[13-1]->setName(#MEMBER13); \
m_col_list[14-1] = &MEMBER14; \
m_col_list[14-1]->setName(#MEMBER14); \
} \
SQLiteORM::Column2 MEMBER1; \
SQLiteORM::Column2 MEMBER2; \
SQLiteORM::Column2 MEMBER3; \
SQLiteORM::Column2 MEMBER4; \
SQLiteORM::Column2 MEMBER5; \
SQLiteORM::Column2 MEMBER6; \
SQLiteORM::Column2 MEMBER7; \
SQLiteORM::Column2 MEMBER8; \
SQLiteORM::Column2 MEMBER9; \
SQLiteORM::Column2 MEMBER10; \
SQLiteORM::Column2 MEMBER11; \
SQLiteORM::Column2 MEMBER12; \
SQLiteORM::Column2 MEMBER13; \
SQLiteORM::Column2 MEMBER14; \

#define SQLITE_ORM_INITIALIZER15(MEMBER1,MEMBER2,MEMBER3,MEMBER4,MEMBER5,MEMBER6,MEMBER7,MEMBER8,MEMBER9,MEMBER10,MEMBER11,MEMBER12,MEMBER13,MEMBER14,MEMBER15) \
m_col_list.resize(15); \
m_col_list[1-1] = &MEMBER1; \
m_col_list[1-1]->setName(#MEMBER1); \
m_col_list[2-1] = &MEMBER2; \
m_col_list[2-1]->setName(#MEMBER2); \
m_col_list[3-1] = &MEMBER3; \
m_col_list[3-1]->setName(#MEMBER3); \
m_col_list[4-1] = &MEMBER4; \
m_col_list[4-1]->setName(#MEMBER4); \
m_col_list[5-1] = &MEMBER5; \
m_col_list[5-1]->setName(#MEMBER5); \
m_col_list[6-1] = &MEMBER6; \
m_col_list[6-1]->setName(#MEMBER6); \
m_col_list[7-1] = &MEMBER7; \
m_col_list[7-1]->setName(#MEMBER7); \
m_col_list[8-1] = &MEMBER8; \
m_col_list[8-1]->setName(#MEMBER8); \
m_col_list[9-1] = &MEMBER9; \
m_col_list[9-1]->setName(#MEMBER9); \
m_col_list[10-1] = &MEMBER10; \
m_col_list[10-1]->setName(#MEMBER10); \
m_col_list[11-1] = &MEMBER11; \
m_col_list[11-1]->setName(#MEMBER11); \
m_col_list[12-1] = &MEMBER12; \
m_col_list[12-1]->setName(#MEMBER12); \
m_col_list[13-1] = &MEMBER13; \
m_col_list[13-1]->setName(#MEMBER13); \
m_col_list[14-1] = &MEMBER14; \
m_col_list[14-1]->setName(#MEMBER14); \
m_col_list[15-1] = &MEMBER15; \
m_col_list[15-1]->setName(#MEMBER15); \
} \
SQLiteORM::Column2 MEMBER1; \
SQLiteORM::Column2 MEMBER2; \
SQLiteORM::Column2 MEMBER3; \
SQLiteORM::Column2 MEMBER4; \
SQLiteORM::Column2 MEMBER5; \
SQLiteORM::Column2 MEMBER6; \
SQLiteORM::Column2 MEMBER7; \
SQLiteORM::Column2 MEMBER8; \
SQLiteORM::Column2 MEMBER9; \
SQLiteORM::Column2 MEMBER10; \
SQLiteORM::Column2 MEMBER11; \
SQLiteORM::Column2 MEMBER12; \
SQLiteORM::Column2 MEMBER13; \
SQLiteORM::Column2 MEMBER14; \
SQLiteORM::Column2 MEMBER15; \

#define SQLITE_ORM_INITIALIZER16(MEMBER1,MEMBER2,MEMBER3,MEMBER4,MEMBER5,MEMBER6,MEMBER7,MEMBER8,MEMBER9,MEMBER10,MEMBER11,MEMBER12,MEMBER13,MEMBER14,MEMBER15,MEMBER16) \
m_col_list.resize(16); \
m_col_list[1-1] = &MEMBER1; \
m_col_list[1-1]->setName(#MEMBER1); \
m_col_list[2-1] = &MEMBER2; \
m_col_list[2-1]->setName(#MEMBER2); \
m_col_list[3-1] = &MEMBER3; \
m_col_list[3-1]->setName(#MEMBER3); \
m_col_list[4-1] = &MEMBER4; \
m_col_list[4-1]->setName(#MEMBER4); \
m_col_list[5-1] = &MEMBER5; \
m_col_list[5-1]->setName(#MEMBER5); \
m_col_list[6-1] = &MEMBER6; \
m_col_list[6-1]->setName(#MEMBER6); \
m_col_list[7-1] = &MEMBER7; \
m_col_list[7-1]->setName(#MEMBER7); \
m_col_list[8-1] = &MEMBER8; \
m_col_list[8-1]->setName(#MEMBER8); \
m_col_list[9-1] = &MEMBER9; \
m_col_list[9-1]->setName(#MEMBER9); \
m_col_list[10-1] = &MEMBER10; \
m_col_list[10-1]->setName(#MEMBER10); \
m_col_list[11-1] = &MEMBER11; \
m_col_list[11-1]->setName(#MEMBER11); \
m_col_list[12-1] = &MEMBER12; \
m_col_list[12-1]->setName(#MEMBER12); \
m_col_list[13-1] = &MEMBER13; \
m_col_list[13-1]->setName(#MEMBER13); \
m_col_list[14-1] = &MEMBER14; \
m_col_list[14-1]->setName(#MEMBER14); \
m_col_list[15-1] = &MEMBER15; \
m_col_list[15-1]->setName(#MEMBER15); \
m_col_list[16-1] = &MEMBER16; \
m_col_list[16-1]->setName(#MEMBER16); \
} \
SQLiteORM::Column2 MEMBER1; \
SQLiteORM::Column2 MEMBER2; \
SQLiteORM::Column2 MEMBER3; \
SQLiteORM::Column2 MEMBER4; \
SQLiteORM::Column2 MEMBER5; \
SQLiteORM::Column2 MEMBER6; \
SQLiteORM::Column2 MEMBER7; \
SQLiteORM::Column2 MEMBER8; \
SQLiteORM::Column2 MEMBER9; \
SQLiteORM::Column2 MEMBER10; \
SQLiteORM::Column2 MEMBER11; \
SQLiteORM::Column2 MEMBER12; \
SQLiteORM::Column2 MEMBER13; \
SQLiteORM::Column2 MEMBER14; \
SQLiteORM::Column2 MEMBER15; \
SQLiteORM::Column2 MEMBER16; \

#define SQLITE_ORM_INITIALIZER17(MEMBER1,MEMBER2,MEMBER3,MEMBER4,MEMBER5,MEMBER6,MEMBER7,MEMBER8,MEMBER9,MEMBER10,MEMBER11,MEMBER12,MEMBER13,MEMBER14,MEMBER15,MEMBER16,MEMBER17) \
m_col_list.resize(17); \
m_col_list[1-1] = &MEMBER1; \
m_col_list[1-1]->setName(#MEMBER1); \
m_col_list[2-1] = &MEMBER2; \
m_col_list[2-1]->setName(#MEMBER2); \
m_col_list[3-1] = &MEMBER3; \
m_col_list[3-1]->setName(#MEMBER3); \
m_col_list[4-1] = &MEMBER4; \
m_col_list[4-1]->setName(#MEMBER4); \
m_col_list[5-1] = &MEMBER5; \
m_col_list[5-1]->setName(#MEMBER5); \
m_col_list[6-1] = &MEMBER6; \
m_col_list[6-1]->setName(#MEMBER6); \
m_col_list[7-1] = &MEMBER7; \
m_col_list[7-1]->setName(#MEMBER7); \
m_col_list[8-1] = &MEMBER8; \
m_col_list[8-1]->setName(#MEMBER8); \
m_col_list[9-1] = &MEMBER9; \
m_col_list[9-1]->setName(#MEMBER9); \
m_col_list[10-1] = &MEMBER10; \
m_col_list[10-1]->setName(#MEMBER10); \
m_col_list[11-1] = &MEMBER11; \
m_col_list[11-1]->setName(#MEMBER11); \
m_col_list[12-1] = &MEMBER12; \
m_col_list[12-1]->setName(#MEMBER12); \
m_col_list[13-1] = &MEMBER13; \
m_col_list[13-1]->setName(#MEMBER13); \
m_col_list[14-1] = &MEMBER14; \
m_col_list[14-1]->setName(#MEMBER14); \
m_col_list[15-1] = &MEMBER15; \
m_col_list[15-1]->setName(#MEMBER15); \
m_col_list[16-1] = &MEMBER16; \
m_col_list[16-1]->setName(#MEMBER16); \
m_col_list[17-1] = &MEMBER17; \
m_col_list[17-1]->setName(#MEMBER17); \
} \
SQLiteORM::Column2 MEMBER1; \
SQLiteORM::Column2 MEMBER2; \
SQLiteORM::Column2 MEMBER3; \
SQLiteORM::Column2 MEMBER4; \
SQLiteORM::Column2 MEMBER5; \
SQLiteORM::Column2 MEMBER6; \
SQLiteORM::Column2 MEMBER7; \
SQLiteORM::Column2 MEMBER8; \
SQLiteORM::Column2 MEMBER9; \
SQLiteORM::Column2 MEMBER10; \
SQLiteORM::Column2 MEMBER11; \
SQLiteORM::Column2 MEMBER12; \
SQLiteORM::Column2 MEMBER13; \
SQLiteORM::Column2 MEMBER14; \
SQLiteORM::Column2 MEMBER15; \
SQLiteORM::Column2 MEMBER16; \
SQLiteORM::Column2 MEMBER17; \

#define SQLITE_ORM_INITIALIZER18(MEMBER1,MEMBER2,MEMBER3,MEMBER4,MEMBER5,MEMBER6,MEMBER7,MEMBER8,MEMBER9,MEMBER10,MEMBER11,MEMBER12,MEMBER13,MEMBER14,MEMBER15,MEMBER16,MEMBER17,MEMBER18) \
m_col_list.resize(18); \
m_col_list[1-1] = &MEMBER1; \
m_col_list[1-1]->setName(#MEMBER1); \
m_col_list[2-1] = &MEMBER2; \
m_col_list[2-1]->setName(#MEMBER2); \
m_col_list[3-1] = &MEMBER3; \
m_col_list[3-1]->setName(#MEMBER3); \
m_col_list[4-1] = &MEMBER4; \
m_col_list[4-1]->setName(#MEMBER4); \
m_col_list[5-1] = &MEMBER5; \
m_col_list[5-1]->setName(#MEMBER5); \
m_col_list[6-1] = &MEMBER6; \
m_col_list[6-1]->setName(#MEMBER6); \
m_col_list[7-1] = &MEMBER7; \
m_col_list[7-1]->setName(#MEMBER7); \
m_col_list[8-1] = &MEMBER8; \
m_col_list[8-1]->setName(#MEMBER8); \
m_col_list[9-1] = &MEMBER9; \
m_col_list[9-1]->setName(#MEMBER9); \
m_col_list[10-1] = &MEMBER10; \
m_col_list[10-1]->setName(#MEMBER10); \
m_col_list[11-1] = &MEMBER11; \
m_col_list[11-1]->setName(#MEMBER11); \
m_col_list[12-1] = &MEMBER12; \
m_col_list[12-1]->setName(#MEMBER12); \
m_col_list[13-1] = &MEMBER13; \
m_col_list[13-1]->setName(#MEMBER13); \
m_col_list[14-1] = &MEMBER14; \
m_col_list[14-1]->setName(#MEMBER14); \
m_col_list[15-1] = &MEMBER15; \
m_col_list[15-1]->setName(#MEMBER15); \
m_col_list[16-1] = &MEMBER16; \
m_col_list[16-1]->setName(#MEMBER16); \
m_col_list[17-1] = &MEMBER17; \
m_col_list[17-1]->setName(#MEMBER17); \
m_col_list[18-1] = &MEMBER18; \
m_col_list[18-1]->setName(#MEMBER18); \
} \
SQLiteORM::Column2 MEMBER1; \
SQLiteORM::Column2 MEMBER2; \
SQLiteORM::Column2 MEMBER3; \
SQLiteORM::Column2 MEMBER4; \
SQLiteORM::Column2 MEMBER5; \
SQLiteORM::Column2 MEMBER6; \
SQLiteORM::Column2 MEMBER7; \
SQLiteORM::Column2 MEMBER8; \
SQLiteORM::Column2 MEMBER9; \
SQLiteORM::Column2 MEMBER10; \
SQLiteORM::Column2 MEMBER11; \
SQLiteORM::Column2 MEMBER12; \
SQLiteORM::Column2 MEMBER13; \
SQLiteORM::Column2 MEMBER14; \
SQLiteORM::Column2 MEMBER15; \
SQLiteORM::Column2 MEMBER16; \
SQLiteORM::Column2 MEMBER17; \
SQLiteORM::Column2 MEMBER18; \

#define SQLITE_ORM_INITIALIZER19(MEMBER1,MEMBER2,MEMBER3,MEMBER4,MEMBER5,MEMBER6,MEMBER7,MEMBER8,MEMBER9,MEMBER10,MEMBER11,MEMBER12,MEMBER13,MEMBER14,MEMBER15,MEMBER16,MEMBER17,MEMBER18,MEMBER19) \
m_col_list.resize(19); \
m_col_list[1-1] = &MEMBER1; \
m_col_list[1-1]->setName(#MEMBER1); \
m_col_list[2-1] = &MEMBER2; \
m_col_list[2-1]->setName(#MEMBER2); \
m_col_list[3-1] = &MEMBER3; \
m_col_list[3-1]->setName(#MEMBER3); \
m_col_list[4-1] = &MEMBER4; \
m_col_list[4-1]->setName(#MEMBER4); \
m_col_list[5-1] = &MEMBER5; \
m_col_list[5-1]->setName(#MEMBER5); \
m_col_list[6-1] = &MEMBER6; \
m_col_list[6-1]->setName(#MEMBER6); \
m_col_list[7-1] = &MEMBER7; \
m_col_list[7-1]->setName(#MEMBER7); \
m_col_list[8-1] = &MEMBER8; \
m_col_list[8-1]->setName(#MEMBER8); \
m_col_list[9-1] = &MEMBER9; \
m_col_list[9-1]->setName(#MEMBER9); \
m_col_list[10-1] = &MEMBER10; \
m_col_list[10-1]->setName(#MEMBER10); \
m_col_list[11-1] = &MEMBER11; \
m_col_list[11-1]->setName(#MEMBER11); \
m_col_list[12-1] = &MEMBER12; \
m_col_list[12-1]->setName(#MEMBER12); \
m_col_list[13-1] = &MEMBER13; \
m_col_list[13-1]->setName(#MEMBER13); \
m_col_list[14-1] = &MEMBER14; \
m_col_list[14-1]->setName(#MEMBER14); \
m_col_list[15-1] = &MEMBER15; \
m_col_list[15-1]->setName(#MEMBER15); \
m_col_list[16-1] = &MEMBER16; \
m_col_list[16-1]->setName(#MEMBER16); \
m_col_list[17-1] = &MEMBER17; \
m_col_list[17-1]->setName(#MEMBER17); \
m_col_list[18-1] = &MEMBER18; \
m_col_list[18-1]->setName(#MEMBER18); \
m_col_list[19-1] = &MEMBER19; \
m_col_list[19-1]->setName(#MEMBER19); \
} \
SQLiteORM::Column2 MEMBER1; \
SQLiteORM::Column2 MEMBER2; \
SQLiteORM::Column2 MEMBER3; \
SQLiteORM::Column2 MEMBER4; \
SQLiteORM::Column2 MEMBER5; \
SQLiteORM::Column2 MEMBER6; \
SQLiteORM::Column2 MEMBER7; \
SQLiteORM::Column2 MEMBER8; \
SQLiteORM::Column2 MEMBER9; \
SQLiteORM::Column2 MEMBER10; \
SQLiteORM::Column2 MEMBER11; \
SQLiteORM::Column2 MEMBER12; \
SQLiteORM::Column2 MEMBER13; \
SQLiteORM::Column2 MEMBER14; \
SQLiteORM::Column2 MEMBER15; \
SQLiteORM::Column2 MEMBER16; \
SQLiteORM::Column2 MEMBER17; \
SQLiteORM::Column2 MEMBER18; \
SQLiteORM::Column2 MEMBER19; \

#define SQLITE_ORM_INITIALIZER20(MEMBER1,MEMBER2,MEMBER3,MEMBER4,MEMBER5,MEMBER6,MEMBER7,MEMBER8,MEMBER9,MEMBER10,MEMBER11,MEMBER12,MEMBER13,MEMBER14,MEMBER15,MEMBER16,MEMBER17,MEMBER18,MEMBER19,MEMBER20) \
m_col_list.resize(20); \
m_col_list[1-1] = &MEMBER1; \
m_col_list[1-1]->setName(#MEMBER1); \
m_col_list[2-1] = &MEMBER2; \
m_col_list[2-1]->setName(#MEMBER2); \
m_col_list[3-1] = &MEMBER3; \
m_col_list[3-1]->setName(#MEMBER3); \
m_col_list[4-1] = &MEMBER4; \
m_col_list[4-1]->setName(#MEMBER4); \
m_col_list[5-1] = &MEMBER5; \
m_col_list[5-1]->setName(#MEMBER5); \
m_col_list[6-1] = &MEMBER6; \
m_col_list[6-1]->setName(#MEMBER6); \
m_col_list[7-1] = &MEMBER7; \
m_col_list[7-1]->setName(#MEMBER7); \
m_col_list[8-1] = &MEMBER8; \
m_col_list[8-1]->setName(#MEMBER8); \
m_col_list[9-1] = &MEMBER9; \
m_col_list[9-1]->setName(#MEMBER9); \
m_col_list[10-1] = &MEMBER10; \
m_col_list[10-1]->setName(#MEMBER10); \
m_col_list[11-1] = &MEMBER11; \
m_col_list[11-1]->setName(#MEMBER11); \
m_col_list[12-1] = &MEMBER12; \
m_col_list[12-1]->setName(#MEMBER12); \
m_col_list[13-1] = &MEMBER13; \
m_col_list[13-1]->setName(#MEMBER13); \
m_col_list[14-1] = &MEMBER14; \
m_col_list[14-1]->setName(#MEMBER14); \
m_col_list[15-1] = &MEMBER15; \
m_col_list[15-1]->setName(#MEMBER15); \
m_col_list[16-1] = &MEMBER16; \
m_col_list[16-1]->setName(#MEMBER16); \
m_col_list[17-1] = &MEMBER17; \
m_col_list[17-1]->setName(#MEMBER17); \
m_col_list[18-1] = &MEMBER18; \
m_col_list[18-1]->setName(#MEMBER18); \
m_col_list[19-1] = &MEMBER19; \
m_col_list[19-1]->setName(#MEMBER19); \
m_col_list[20-1] = &MEMBER20; \
m_col_list[20-1]->setName(#MEMBER20); \
} \
SQLiteORM::Column2 MEMBER1; \
SQLiteORM::Column2 MEMBER2; \
SQLiteORM::Column2 MEMBER3; \
SQLiteORM::Column2 MEMBER4; \
SQLiteORM::Column2 MEMBER5; \
SQLiteORM::Column2 MEMBER6; \
SQLiteORM::Column2 MEMBER7; \
SQLiteORM::Column2 MEMBER8; \
SQLiteORM::Column2 MEMBER9; \
SQLiteORM::Column2 MEMBER10; \
SQLiteORM::Column2 MEMBER11; \
SQLiteORM::Column2 MEMBER12; \
SQLiteORM::Column2 MEMBER13; \
SQLiteORM::Column2 MEMBER14; \
SQLiteORM::Column2 MEMBER15; \
SQLiteORM::Column2 MEMBER16; \
SQLiteORM::Column2 MEMBER17; \
SQLiteORM::Column2 MEMBER18; \
SQLiteORM::Column2 MEMBER19; \
SQLiteORM::Column2 MEMBER20; \

#define SQLITE_ORM_END() };

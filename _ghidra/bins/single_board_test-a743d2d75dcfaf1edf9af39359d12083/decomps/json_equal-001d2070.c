
/* WARNING: Unknown calling convention */

int json_equal(json_t *json1,json_t *json2)

{
  void *pvVar1;
  char *key;
  uint uVar2;
  int iVar3;
  json_t *pjVar4;
  json_t *pjVar5;
  json_type jVar6;
  json_type jVar7;
  json_array_t *array;
  size_t size;
  size_t sVar8;
  
  if (json1 != (json_t *)0x0 && json2 != (json_t *)0x0) {
    jVar7 = json1->type;
    if (jVar7 != json2->type) {
      return 0;
    }
    if (json1 == json2) {
      return 1;
    }
    switch(jVar7) {
    case JSON_OBJECT:
      if (json1[1].type == json2[1].type) {
        pvVar1 = json_object_iter(json1);
        key = json_object_iter_key(pvVar1);
        while( true ) {
          if (key == (char *)0x0) {
            return 1;
          }
          pjVar4 = json_object_iter_value(key + -0x10);
          if (pjVar4 == (json_t *)0x0) break;
          pjVar5 = json_object_get(json2,key);
          iVar3 = json_equal(pjVar4,pjVar5);
          if (iVar3 == 0) {
            return 0;
          }
          pvVar1 = json_object_iter_next(json1,key + -0x10);
          key = json_object_iter_key(pvVar1);
        }
        return 1;
      }
      break;
    case JSON_ARRAY:
      sVar8 = json1[1].refcount;
      if (sVar8 == json2[1].refcount) {
        if (sVar8 == 0) {
          return 1;
        }
        jVar6 = JSON_ARRAY;
        uVar2 = 0;
        while( true ) {
          if ((jVar6 == JSON_ARRAY) && (uVar2 < json1[1].refcount)) {
            pjVar4 = *(json_t **)(json1[2].type + uVar2 * 4);
          }
          else {
            pjVar4 = (json_t *)0x0;
          }
          if ((jVar7 == JSON_ARRAY) && (uVar2 < json2[1].refcount)) {
            pjVar5 = *(json_t **)(json2[2].type + uVar2 * 4);
          }
          else {
            pjVar5 = (json_t *)0x0;
          }
          iVar3 = json_equal(pjVar4,pjVar5);
          if (iVar3 == 0) break;
          uVar2 = uVar2 + 1;
          if (uVar2 == sVar8) {
            return 1;
          }
          jVar6 = json1->type;
          jVar7 = json2->type;
        }
        return 0;
      }
      break;
    case JSON_STRING:
      if (json1[1].refcount == json2[1].refcount) {
        uVar2 = memcmp((void *)json1[1].type,(void *)json2[1].type,json1[1].refcount);
        iVar3 = 1 - uVar2;
        if (1 < uVar2) {
          iVar3 = 0;
        }
        return iVar3;
      }
      break;
    case JSON_INTEGER:
      return (uint)(json1[1].refcount == json2[1].refcount && json1[1].type == json2[1].type);
    case JSON_REAL:
      return (uint)((double)json1[1] == (double)json2[1]);
    }
  }
  return 0;
}



/* WARNING: Unknown calling convention */
/* Local variable value1_1:json_t *[r0:4] conflicts with parameter, skipped.
   Local variable value2_1:json_t *[r1:4] conflicts with parameter, skipped. */

int json_equal(json_t *json1,json_t *json2)

{
  void *pvVar1;
  char *key_00;
  char *key;
  json_t *value2;
  int iVar2;
  json_t *pjVar3;
  json_t *pjVar4;
  uint uVar5;
  json_type jVar6;
  json_type jVar7;
  json_array_t *array_1;
  json_array_t *array;
  size_t size;
  size_t sVar8;
  json_t *value1;
  
  if (json1 == (json_t *)0x0 || json2 == (json_t *)0x0) {
    return 0;
  }
  uVar5 = 0;
  jVar6 = json1->type;
  if (jVar6 != json2->type) {
    return 0;
  }
  if (json1 != json2) {
    if (jVar6 == JSON_OBJECT) {
      if (json1[1].type != json2[1].type) {
        return 0;
      }
      pvVar1 = json_object_iter(json1);
      key_00 = json_object_iter_key(pvVar1);
      while (key_00 != (char *)0x0) {
        pjVar3 = json_object_iter_value(key_00 + -0x10);
        if (pjVar3 == (json_t *)0x0) {
          return 1;
        }
        pjVar4 = json_object_get(json2,key_00);
        iVar2 = json_equal(pjVar3,pjVar4);
        if (iVar2 == 0) {
          return 0;
        }
        pvVar1 = json_object_iter_next(json1,key_00 + -0x10);
        key_00 = json_object_iter_key(pvVar1);
      }
    }
    else {
      if (jVar6 != JSON_ARRAY) {
        if (jVar6 == JSON_STRING) {
          uVar5 = strcmp((char *)json1[1].type,(char *)json2[1].type);
          iVar2 = 1 - uVar5;
          if (1 < uVar5) {
            iVar2 = 0;
          }
          return iVar2;
        }
        if (jVar6 != JSON_INTEGER) {
          if (jVar6 != JSON_REAL) {
            return 0;
          }
          return (uint)((double)json1[1] == (double)json2[1]);
        }
        return (uint)(json1[1].refcount == json2[1].refcount && json1[1].type == json2[1].type);
      }
      sVar8 = json1[1].refcount;
      if (sVar8 != json2[1].refcount) {
        return 0;
      }
      if (sVar8 != 0) {
        jVar6 = JSON_ARRAY;
        jVar7 = JSON_ARRAY;
        while( true ) {
          if ((jVar6 == JSON_ARRAY) && (uVar5 < json1[1].refcount)) {
            pjVar3 = *(json_t **)(json1[2].type + uVar5 * 4);
          }
          else {
            pjVar3 = (json_t *)0x0;
          }
          if ((jVar7 == JSON_ARRAY) && (uVar5 < json2[1].refcount)) {
            pjVar4 = *(json_t **)(json2[2].type + uVar5 * 4);
          }
          else {
            pjVar4 = (json_t *)0x0;
          }
          iVar2 = json_equal(pjVar3,pjVar4);
          if (iVar2 == 0) {
            return 0;
          }
          uVar5 = uVar5 + 1;
          if (uVar5 == sVar8) break;
          jVar6 = json1->type;
          jVar7 = json2->type;
        }
      }
    }
  }
  return 1;
}


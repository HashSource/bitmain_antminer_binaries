
/* WARNING: Unknown calling convention */

json_t * json_copy(json_t *json)

{
  json_t *result;
  void *pvVar1;
  char *key_00;
  char *key;
  json_t *value;
  json_t *result_1;
  json_t *pjVar2;
  json_t *pjVar3;
  json_type jVar4;
  uint uVar5;
  uint uVar6;
  double in_stack_00000000;
  
  if (json != (json_t *)0x0) {
    jVar4 = json->type;
    if (jVar4 == JSON_OBJECT) {
      pjVar2 = json_object();
      if (pjVar2 != (json_t *)0x0) {
        pvVar1 = json_object_iter(json);
        key_00 = json_object_iter_key(pvVar1);
        while (key_00 != (char *)0x0) {
          pjVar3 = json_object_iter_value(key_00 + -0x10);
          if (pjVar3 == (json_t *)0x0) {
            return pjVar2;
          }
          if (pjVar3->refcount != 0xffffffff) {
            pjVar3->refcount = pjVar3->refcount + 1;
          }
          json_object_set_new_nocheck(pjVar2,key_00,pjVar3);
          pvVar1 = json_object_iter_next(json,key_00 + -0x10);
          key_00 = json_object_iter_key(pvVar1);
        }
      }
      return pjVar2;
    }
    if (jVar4 == JSON_ARRAY) {
      pjVar2 = json_array();
      if (pjVar2 == (json_t *)0x0) {
        return (json_t *)0x0;
      }
      if (json->type != JSON_ARRAY) {
        return pjVar2;
      }
      uVar5 = json[1].refcount;
      if (uVar5 == 0) {
        return pjVar2;
      }
      uVar6 = 0;
      while( true ) {
        pjVar3 = (json_t *)0x0;
        if ((uVar6 < uVar5) &&
           (pjVar3 = *(json_t **)(json[2].type + uVar6 * 4), pjVar3 != (json_t *)0x0)) {
          if (pjVar3->refcount != 0xffffffff) {
            pjVar3->refcount = pjVar3->refcount + 1;
          }
        }
        json_array_append_new(pjVar2,pjVar3);
        if (json->type != JSON_ARRAY) break;
        uVar5 = json[1].refcount;
        uVar6 = uVar6 + 1;
        if (uVar5 <= uVar6) {
          return pjVar2;
        }
      }
      return pjVar2;
    }
    if (jVar4 == JSON_STRING) {
      pjVar2 = json_string_nocheck((char *)json[1].type);
      return pjVar2;
    }
    if (jVar4 == JSON_INTEGER) {
      pjVar2 = json_integer((json_int_t)in_stack_00000000);
      return pjVar2;
    }
    if (jVar4 == JSON_REAL) {
      pjVar2 = json_real(in_stack_00000000);
      return pjVar2;
    }
    if (jVar4 + ~JSON_REAL < 3) {
      return json;
    }
  }
  return (json_t *)0x0;
}


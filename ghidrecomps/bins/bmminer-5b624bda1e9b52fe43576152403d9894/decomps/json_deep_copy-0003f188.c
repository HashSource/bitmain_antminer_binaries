
/* WARNING: Unknown calling convention */

json_t * json_deep_copy(json_t *json)

{
  json_t *result;
  void *iter_00;
  void *iter;
  char *key_00;
  char *key;
  json_t *result_1;
  json_t *pjVar1;
  json_type jVar2;
  uint uVar3;
  uint uVar4;
  json_t *pjVar5;
  double in_stack_00000000;
  
  pjVar5 = json;
  if (json != (json_t *)0x0) {
    jVar2 = json->type;
    if (jVar2 == JSON_OBJECT) {
      pjVar5 = json_object();
      if (pjVar5 != (json_t *)0x0) {
        for (iter_00 = json_object_iter(json); iter_00 != (void *)0x0;
            iter_00 = json_object_iter_next(json,iter_00)) {
          key_00 = json_object_iter_key(iter_00);
          pjVar1 = json_object_iter_value(iter_00);
          pjVar1 = json_deep_copy(pjVar1);
          json_object_set_new_nocheck(pjVar5,key_00,pjVar1);
        }
      }
      return pjVar5;
    }
    if (jVar2 == JSON_ARRAY) {
      pjVar5 = json_array();
      if (((pjVar5 != (json_t *)0x0) && (json->type == JSON_ARRAY)) &&
         (uVar3 = json[1].refcount, uVar3 != 0)) {
        uVar4 = 0;
        do {
          pjVar1 = (json_t *)0x0;
          if (uVar4 < uVar3) {
            pjVar1 = *(json_t **)(json[2].type + uVar4 * 4);
          }
          pjVar1 = json_deep_copy(pjVar1);
          json_array_append_new(pjVar5,pjVar1);
          if (json->type != JSON_ARRAY) {
            return pjVar5;
          }
          uVar3 = json[1].refcount;
          uVar4 = uVar4 + 1;
        } while (uVar4 < uVar3);
      }
    }
    else {
      if (jVar2 == JSON_STRING) {
        pjVar5 = json_string_nocheck((char *)json[1].type);
        return pjVar5;
      }
      if (jVar2 == JSON_INTEGER) {
        pjVar5 = json_integer((json_int_t)in_stack_00000000);
        return pjVar5;
      }
      if (jVar2 == JSON_REAL) {
        pjVar5 = json_real(in_stack_00000000);
        return pjVar5;
      }
      if (2 < jVar2 + ~JSON_REAL) {
        pjVar5 = (json_t *)0x0;
      }
    }
  }
  return pjVar5;
}


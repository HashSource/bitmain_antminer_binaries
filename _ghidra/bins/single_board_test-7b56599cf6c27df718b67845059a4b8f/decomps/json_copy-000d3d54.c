
/* WARNING: Unknown calling convention */

json_t * json_copy(json_t *json)

{
  bool bVar1;
  void *pvVar2;
  char *key;
  json_t *pjVar3;
  json_t *pjVar4;
  size_t *psVar5;
  uint uVar6;
  uint uVar7;
  
  pjVar3 = json;
  if (json != (json_t *)0x0) {
    switch(json->type) {
    case JSON_OBJECT:
      pjVar3 = json_object();
      if (pjVar3 != (json_t *)0x0) {
        pvVar2 = json_object_iter(json);
        key = json_object_iter_key(pvVar2);
        while (key != (char *)0x0) {
          pjVar4 = json_object_iter_value(key + -0x10);
          psVar5 = &pjVar4->refcount;
          if (pjVar4 == (json_t *)0x0) {
            return pjVar3;
          }
          if (pjVar4->refcount != 0xffffffff) {
            do {
              ExclusiveAccess(psVar5);
              bVar1 = (bool)hasExclusiveAccess(psVar5);
            } while (!bVar1);
            *psVar5 = *psVar5 + 1;
            DataMemoryBarrier(0x1f);
          }
          json_object_set_new_nocheck(pjVar3,key,pjVar4);
          pvVar2 = json_object_iter_next(json,key + -0x10);
          key = json_object_iter_key(pvVar2);
        }
      }
      return pjVar3;
    case JSON_ARRAY:
      pjVar3 = json_array();
      if (((pjVar3 != (json_t *)0x0) && (json->type == JSON_ARRAY)) &&
         (uVar6 = json[1].refcount, uVar6 != 0)) {
        uVar7 = 0;
        do {
          pjVar4 = (json_t *)0x0;
          if (uVar7 < uVar6) {
            pjVar4 = *(json_t **)(json[2].type + uVar7 * 4);
            psVar5 = &pjVar4->refcount;
            if ((pjVar4 != (json_t *)0x0) && (pjVar4->refcount != 0xffffffff)) {
              do {
                ExclusiveAccess(psVar5);
                bVar1 = (bool)hasExclusiveAccess(psVar5);
              } while (!bVar1);
              *psVar5 = *psVar5 + 1;
              DataMemoryBarrier(0x1f);
            }
          }
          json_array_append_new(pjVar3,pjVar4);
          if (json->type != JSON_ARRAY) {
            return pjVar3;
          }
          uVar6 = json[1].refcount;
          uVar7 = uVar7 + 1;
        } while (uVar7 < uVar6);
      }
      break;
    case JSON_STRING:
      pjVar3 = json_stringn_nocheck((char *)json[1].type,json[1].refcount);
      return pjVar3;
    case JSON_INTEGER:
      pjVar3 = json_integer((json_int_t)json[1]);
      return pjVar3;
    case JSON_REAL:
      pjVar3 = json_real((double)json[1]);
      return pjVar3;
    case JSON_TRUE:
    case JSON_FALSE:
    case JSON_NULL:
      break;
    default:
      return (json_t *)0x0;
    }
  }
  return pjVar3;
}



/* WARNING: Unknown calling convention */

int json_object_update_missing(json_t *object,json_t *other)

{
  bool bVar1;
  void *pvVar2;
  char *key;
  json_t *value;
  json_t *pjVar3;
  size_t *psVar4;
  
  if ((((object != (json_t *)0x0) && (object->type == JSON_OBJECT)) && (other != (json_t *)0x0)) &&
     (other->type == JSON_OBJECT)) {
    pvVar2 = json_object_iter(other);
    key = json_object_iter_key(pvVar2);
    while( true ) {
      if (key == (char *)0x0) {
        return 0;
      }
      value = json_object_iter_value(key + -0x10);
      if (value == (json_t *)0x0) break;
      pjVar3 = json_object_get(object,key);
      if (pjVar3 == (json_t *)0x0) {
        psVar4 = &value->refcount;
        if (value->refcount != 0xffffffff) {
          do {
            ExclusiveAccess(psVar4);
            bVar1 = (bool)hasExclusiveAccess(psVar4);
          } while (!bVar1);
          *psVar4 = *psVar4 + 1;
          DataMemoryBarrier(0x1f);
        }
        json_object_set_new_nocheck(object,key,value);
      }
      pvVar2 = json_object_iter_next(other,key + -0x10);
      key = json_object_iter_key(pvVar2);
    }
    return 0;
  }
  return -1;
}


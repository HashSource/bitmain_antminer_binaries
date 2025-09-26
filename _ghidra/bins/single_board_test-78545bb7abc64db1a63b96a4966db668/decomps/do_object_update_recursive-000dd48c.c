
/* WARNING: Unknown calling convention */

int do_object_update_recursive(json_t *object,json_t *other,hashtable_t *parents)

{
  bool bVar1;
  int iVar2;
  void *pvVar3;
  char *key;
  json_t *value;
  json_t *object_00;
  size_t *psVar4;
  char loop_key [11];
  
  if ((((object == (json_t *)0x0) || (object->type != JSON_OBJECT)) || (other == (json_t *)0x0)) ||
     ((other->type != JSON_OBJECT ||
      (iVar2 = jsonp_loop_check(parents,other,loop_key,0xb), iVar2 != 0)))) {
    iVar2 = -1;
  }
  else {
    pvVar3 = json_object_iter(other);
    key = json_object_iter_key(pvVar3);
    while (key != (char *)0x0) {
      value = json_object_iter_value(key + -0x10);
      if (value == (json_t *)0x0) break;
      object_00 = json_object_get(object,key);
      if (((object_00 == (json_t *)0x0) || (object_00->type != JSON_OBJECT)) ||
         (value->type != JSON_OBJECT)) {
        psVar4 = &value->refcount;
        if (value->refcount != 0xffffffff) {
          do {
            ExclusiveAccess(psVar4);
            bVar1 = (bool)hasExclusiveAccess(psVar4);
          } while (!bVar1);
          *psVar4 = *psVar4 + 1;
          DataMemoryBarrier(0x1f);
        }
        iVar2 = json_object_set_new_nocheck(object,key,value);
      }
      else {
        iVar2 = do_object_update_recursive(object_00,value,parents);
      }
      if (iVar2 != 0) {
        iVar2 = -1;
        goto LAB_000dd538;
      }
      pvVar3 = json_object_iter_next(other,key + -0x10);
      key = json_object_iter_key(pvVar3);
    }
    iVar2 = 0;
LAB_000dd538:
    hashtable_del(parents,loop_key);
  }
  return iVar2;
}


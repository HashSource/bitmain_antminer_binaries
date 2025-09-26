
/* WARNING: Unknown calling convention */

int json_object_iter_set_new(json_t *json,void *iter,json_t *value)

{
  bool bVar1;
  size_t sVar2;
  size_t *psVar3;
  
  if (((json != (json_t *)0x0) && (json->type == JSON_OBJECT)) &&
     (iter != (void *)0x0 && value != (json_t *)0x0)) {
    hashtable_iter_set(iter,value);
    return 0;
  }
  if ((value != (json_t *)0x0) && (value->refcount != 0xffffffff)) {
    psVar3 = &value->refcount;
    DataMemoryBarrier(0x1f);
    do {
      ExclusiveAccess(psVar3);
      sVar2 = *psVar3;
      bVar1 = (bool)hasExclusiveAccess(psVar3);
    } while (!bVar1);
    *psVar3 = sVar2 - 1;
    if (sVar2 - 1 == 0) {
      json_delete(value);
    }
  }
  return -1;
}


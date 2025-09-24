
/* WARNING: Unknown calling convention */

int json_object_set_new_nocheck(json_t *json,char *key,json_t *value)

{
  bool bVar1;
  int iVar2;
  size_t sVar3;
  size_t *psVar4;
  
  if (value != (json_t *)0x0) {
    if (((json == (json_t *)0x0 || key == (char *)0x0) || (json->type != JSON_OBJECT)) ||
       (json == value)) {
      if (value->refcount == 0xffffffff) {
        return -1;
      }
      psVar4 = &value->refcount;
      DataMemoryBarrier(0x1f);
      do {
        ExclusiveAccess(psVar4);
        sVar3 = *psVar4 - 1;
        bVar1 = (bool)hasExclusiveAccess(psVar4);
      } while (!bVar1);
      *psVar4 = sVar3;
    }
    else {
      iVar2 = hashtable_set((hashtable_t *)(json + 1),key,value);
      if (iVar2 == 0) {
        return 0;
      }
      if (value->refcount == 0xffffffff) {
        return -1;
      }
      psVar4 = &value->refcount;
      DataMemoryBarrier(0x1f);
      do {
        ExclusiveAccess(psVar4);
        sVar3 = *psVar4 - 1;
        bVar1 = (bool)hasExclusiveAccess(psVar4);
      } while (!bVar1);
      *psVar4 = sVar3;
    }
    if (sVar3 == 0) {
      json_delete(value);
    }
  }
  return -1;
}



/* WARNING: Unknown calling convention */

void hashtable_iter_set(void *iter,json_t *value)

{
  bool bVar1;
  json_t *json;
  size_t sVar2;
  size_t *psVar3;
  
  json = *(json_t **)((int)iter + 0xc);
  if ((json != (json_t *)0x0) && (json->refcount != 0xffffffff)) {
    psVar3 = &json->refcount;
    DataMemoryBarrier(0x1f);
    do {
      ExclusiveAccess(psVar3);
      sVar2 = *psVar3;
      bVar1 = (bool)hasExclusiveAccess(psVar3);
    } while (!bVar1);
    *psVar3 = sVar2 - 1;
    if (sVar2 - 1 == 0) {
      json_delete(json);
      *(json_t **)((int)iter + 0xc) = value;
      return;
    }
  }
  *(json_t **)((int)iter + 0xc) = value;
  return;
}


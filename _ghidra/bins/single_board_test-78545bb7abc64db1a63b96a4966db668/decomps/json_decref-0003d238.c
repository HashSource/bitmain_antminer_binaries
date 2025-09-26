
void json_decref(json_t *json)

{
  bool bVar1;
  size_t sVar2;
  size_t *psVar3;
  json_t *json_local;
  
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
    }
  }
  return;
}


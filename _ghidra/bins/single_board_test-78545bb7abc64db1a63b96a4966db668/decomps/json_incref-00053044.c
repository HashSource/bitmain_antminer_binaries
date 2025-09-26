
json_t * json_incref(json_t *json)

{
  bool bVar1;
  size_t *psVar2;
  json_t *json_local;
  
  if ((json != (json_t *)0x0) && (json->refcount != 0xffffffff)) {
    psVar2 = &json->refcount;
    do {
      ExclusiveAccess(psVar2);
      bVar1 = (bool)hasExclusiveAccess(psVar2);
    } while (!bVar1);
    *psVar2 = *psVar2 + 1;
    DataMemoryBarrier(0x1f);
  }
  return json;
}


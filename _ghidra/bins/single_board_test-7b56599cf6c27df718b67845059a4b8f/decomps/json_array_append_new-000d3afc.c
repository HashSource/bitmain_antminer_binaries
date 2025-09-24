
/* WARNING: Unknown calling convention */

int json_array_append_new(json_t *json,json_t *value)

{
  bool bVar1;
  json_t **ppjVar2;
  size_t sVar3;
  size_t *psVar4;
  
  if (value != (json_t *)0x0) {
    if (((json == (json_t *)0x0) || (json->type != JSON_ARRAY)) || (json == value)) {
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
      ppjVar2 = json_array_grow((json_array_t *)json,1,1);
      if (ppjVar2 != (json_t **)0x0) {
        sVar3 = json[1].refcount;
        *(json_t **)(json[2].type + sVar3 * 4) = value;
        json[1].refcount = sVar3 + 1;
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


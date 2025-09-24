
/* WARNING: Unknown calling convention */

int json_array_remove(json_t *json,size_t index)

{
  bool bVar1;
  json_t *json_00;
  int iVar2;
  size_t sVar3;
  size_t *psVar4;
  
  if (((json == (json_t *)0x0) || (json->type != JSON_ARRAY)) ||
     (sVar3 = json[1].refcount, sVar3 <= index)) {
    iVar2 = -1;
  }
  else {
    json_00 = *(json_t **)(json[2].type + index * 4);
    if ((json_00 != (json_t *)0x0) && (json_00->refcount != 0xffffffff)) {
      psVar4 = &json_00->refcount;
      DataMemoryBarrier(0x1f);
      do {
        ExclusiveAccess(psVar4);
        sVar3 = *psVar4;
        bVar1 = (bool)hasExclusiveAccess(psVar4);
      } while (!bVar1);
      *psVar4 = sVar3 - 1;
      if (sVar3 - 1 == 0) {
        json_delete(json_00);
        sVar3 = json[1].refcount;
      }
      else {
        sVar3 = json[1].refcount;
      }
    }
    sVar3 = sVar3 - 1;
    if (index < sVar3) {
      memmove((void *)(json[2].type + index * 4),(void *)(json[2].type + (index + 1) * 4),
              (sVar3 - index) * 4);
      sVar3 = json[1].refcount - 1;
    }
    iVar2 = 0;
    json[1].refcount = sVar3;
  }
  return iVar2;
}


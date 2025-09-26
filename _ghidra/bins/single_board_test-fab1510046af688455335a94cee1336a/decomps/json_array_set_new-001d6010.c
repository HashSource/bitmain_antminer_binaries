
/* WARNING: Unknown calling convention */

int json_array_set_new(json_t *json,size_t index,json_t *value)

{
  bool bVar1;
  json_t *json_00;
  size_t sVar2;
  undefined4 *puVar3;
  size_t *psVar4;
  int iVar5;
  
  if (value != (json_t *)0x0) {
    if (((json == (json_t *)0x0) || (json->type != JSON_ARRAY)) || (json == value)) {
      if (value->refcount == 0xffffffff) {
        return -1;
      }
      psVar4 = &value->refcount;
      DataMemoryBarrier(0x1f);
      do {
        ExclusiveAccess(psVar4);
        sVar2 = *psVar4 - 1;
        bVar1 = (bool)hasExclusiveAccess(psVar4);
      } while (!bVar1);
      *psVar4 = sVar2;
    }
    else {
      if (index < json[1].refcount) {
        iVar5 = index * 4;
        json_00 = *(json_t **)(json[2].type + index * 4);
        puVar3 = (undefined4 *)(json[2].type + iVar5);
        if ((json_00 != (json_t *)0x0) && (json_00->refcount != 0xffffffff)) {
          psVar4 = &json_00->refcount;
          DataMemoryBarrier(0x1f);
          do {
            ExclusiveAccess(psVar4);
            sVar2 = *psVar4;
            bVar1 = (bool)hasExclusiveAccess(psVar4);
          } while (!bVar1);
          *psVar4 = sVar2 - 1;
          if (sVar2 - 1 == 0) {
            json_delete(json_00);
            puVar3 = (undefined4 *)(json[2].type + iVar5);
          }
          else {
            puVar3 = (undefined4 *)(json[2].type + iVar5);
          }
        }
        *puVar3 = value;
        return 0;
      }
      if (value->refcount == 0xffffffff) {
        return -1;
      }
      psVar4 = &value->refcount;
      DataMemoryBarrier(0x1f);
      do {
        ExclusiveAccess(psVar4);
        sVar2 = *psVar4 - 1;
        bVar1 = (bool)hasExclusiveAccess(psVar4);
      } while (!bVar1);
      *psVar4 = sVar2;
    }
    if (sVar2 == 0) {
      json_delete(value);
    }
  }
  return -1;
}


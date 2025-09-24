
/* WARNING: Unknown calling convention */

int json_array_clear(json_t *json)

{
  bool bVar1;
  json_t *json_00;
  uint uVar2;
  size_t sVar3;
  size_t *psVar4;
  uint uVar5;
  
  if ((json != (json_t *)0x0) && (json->type == JSON_ARRAY)) {
    uVar2 = json[1].refcount;
    if (uVar2 != 0) {
      uVar5 = 0;
      do {
        json_00 = *(json_t **)(json[2].type + uVar5 * 4);
        psVar4 = &json_00->refcount;
        if ((json_00 != (json_t *)0x0) && (json_00->refcount != 0xffffffff)) {
          DataMemoryBarrier(0x1f);
          do {
            ExclusiveAccess(psVar4);
            sVar3 = *psVar4;
            bVar1 = (bool)hasExclusiveAccess(psVar4);
          } while (!bVar1);
          *psVar4 = sVar3 - 1;
          if (sVar3 - 1 == 0) {
            json_delete(json_00);
          }
          uVar2 = json[1].refcount;
        }
        uVar5 = uVar5 + 1;
      } while (uVar5 < uVar2);
    }
    json[1].refcount = 0;
    return 0;
  }
  return -1;
}


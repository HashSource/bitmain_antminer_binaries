
/* WARNING: Unknown calling convention */

void json_delete(json_t *json)

{
  bool bVar1;
  void *ptr;
  size_t sVar2;
  size_t *psVar3;
  json_t *json_00;
  uint uVar4;
  uint uVar5;
  
  if (json == (json_t *)0x0) {
switchD_000dd120_default:
    return;
  }
  switch(json->type) {
  case JSON_OBJECT:
    hashtable_close((hashtable_t *)(json + 1));
    jsonp_free(json);
    return;
  case JSON_ARRAY:
    uVar5 = json[1].refcount;
    ptr = (void *)json[2].type;
    if (uVar5 != 0) {
      uVar4 = 0;
      do {
        json_00 = *(json_t **)((int)ptr + uVar4 * 4);
        psVar3 = &json_00->refcount;
        if ((json_00 != (json_t *)0x0) && (json_00->refcount != 0xffffffff)) {
          DataMemoryBarrier(0x1f);
          do {
            ExclusiveAccess(psVar3);
            sVar2 = *psVar3;
            bVar1 = (bool)hasExclusiveAccess(psVar3);
          } while (!bVar1);
          *psVar3 = sVar2 - 1;
          if (sVar2 - 1 == 0) {
            json_delete(json_00);
          }
          ptr = (void *)json[2].type;
          uVar5 = json[1].refcount;
        }
        uVar4 = uVar4 + 1;
      } while (uVar4 < uVar5);
    }
    break;
  case JSON_STRING:
    ptr = (void *)json[1].type;
    break;
  case JSON_INTEGER:
  case JSON_REAL:
    goto switchD_000dd120_caseD_3;
  default:
    goto switchD_000dd120_default;
  }
  jsonp_free(ptr);
switchD_000dd120_caseD_3:
  jsonp_free(json);
  return;
}


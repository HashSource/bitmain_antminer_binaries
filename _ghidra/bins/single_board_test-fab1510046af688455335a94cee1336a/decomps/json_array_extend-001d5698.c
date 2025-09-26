
/* WARNING: Unknown calling convention */

int json_array_extend(json_t *json,json_t *other_json)

{
  bool bVar1;
  json_t **ppjVar2;
  void *__src;
  size_t sVar3;
  uint uVar4;
  int iVar5;
  int *piVar6;
  
  if ((((json != (json_t *)0x0) && (json->type == JSON_ARRAY)) && (other_json != (json_t *)0x0)) &&
     ((other_json->type == JSON_ARRAY &&
      (ppjVar2 = json_array_grow((json_array_t *)json,other_json[1].refcount,1),
      ppjVar2 != (json_t **)0x0)))) {
    sVar3 = other_json[1].refcount;
    uVar4 = 0;
    __src = (void *)other_json[2].type;
    if (sVar3 != 0) {
      do {
        iVar5 = *(int *)((int)__src + uVar4 * 4);
        piVar6 = (int *)(iVar5 + 4);
        if ((iVar5 != 0) && (*(int *)(iVar5 + 4) != -1)) {
          do {
            ExclusiveAccess(piVar6);
            bVar1 = (bool)hasExclusiveAccess(piVar6);
          } while (!bVar1);
          *piVar6 = *piVar6 + 1;
          DataMemoryBarrier(0x1f);
          __src = (void *)other_json[2].type;
          sVar3 = other_json[1].refcount;
        }
        uVar4 = uVar4 + 1;
      } while (uVar4 < sVar3);
    }
    memcpy((void *)(json[2].type + json[1].refcount * 4),__src,sVar3 << 2);
    json[1].refcount = json[1].refcount + other_json[1].refcount;
    return 0;
  }
  return -1;
}


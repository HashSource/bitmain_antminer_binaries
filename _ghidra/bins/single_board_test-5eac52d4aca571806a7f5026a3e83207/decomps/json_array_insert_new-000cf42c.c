
/* WARNING: Unknown calling convention */

int json_array_insert_new(json_t *json,size_t index,json_t *value)

{
  bool bVar1;
  json_t **__src;
  json_t **__dest;
  size_t sVar2;
  size_t *psVar3;
  
  if (value != (json_t *)0x0) {
    if (((json == (json_t *)0x0) || (json->type != JSON_ARRAY)) || (json == value)) {
      if (value->refcount == 0xffffffff) {
        return -1;
      }
      psVar3 = &value->refcount;
      DataMemoryBarrier(0x1f);
      do {
        ExclusiveAccess(psVar3);
        sVar2 = *psVar3 - 1;
        bVar1 = (bool)hasExclusiveAccess(psVar3);
      } while (!bVar1);
      *psVar3 = sVar2;
    }
    else if (json[1].refcount < index) {
      if (value->refcount == 0xffffffff) {
        return -1;
      }
      psVar3 = &value->refcount;
      DataMemoryBarrier(0x1f);
      do {
        ExclusiveAccess(psVar3);
        sVar2 = *psVar3 - 1;
        bVar1 = (bool)hasExclusiveAccess(psVar3);
      } while (!bVar1);
      *psVar3 = sVar2;
    }
    else {
      __src = json_array_grow((json_array_t *)json,1,0);
      if (__src != (json_t **)0x0) {
        __dest = (json_t **)json[2].type;
        if (__dest == __src) {
          memmove(__dest + index + 1,__dest + index,(json[1].refcount - index) * 4);
        }
        else {
          memcpy(__dest,__src,index * 4);
          memcpy((void *)(json[2].type + (index + 1) * 4),__src + index,
                 (json[1].refcount - index) * 4);
          jsonp_free(__src);
        }
        sVar2 = json[1].refcount;
        *(json_t **)(json[2].type + index * 4) = value;
        json[1].refcount = sVar2 + 1;
        return 0;
      }
      if (value->refcount == 0xffffffff) {
        return -1;
      }
      psVar3 = &value->refcount;
      DataMemoryBarrier(0x1f);
      do {
        ExclusiveAccess(psVar3);
        sVar2 = *psVar3 - 1;
        bVar1 = (bool)hasExclusiveAccess(psVar3);
      } while (!bVar1);
      *psVar3 = sVar2;
    }
    if (sVar2 == 0) {
      json_delete(value);
    }
  }
  return -1;
}


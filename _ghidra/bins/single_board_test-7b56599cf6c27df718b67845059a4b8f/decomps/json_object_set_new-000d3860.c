
/* WARNING: Unknown calling convention */

int json_object_set_new(json_t *json,char *key,json_t *value)

{
  bool bVar1;
  size_t length;
  int iVar2;
  size_t sVar3;
  size_t *psVar4;
  
  if (key != (char *)0x0) {
    length = strlen(key);
    iVar2 = utf8_check_string(key,length);
    if (iVar2 != 0) {
      iVar2 = json_object_set_new_nocheck(json,key,value);
      return iVar2;
    }
  }
  if ((value != (json_t *)0x0) && (value->refcount != 0xffffffff)) {
    psVar4 = &value->refcount;
    DataMemoryBarrier(0x1f);
    do {
      ExclusiveAccess(psVar4);
      sVar3 = *psVar4;
      bVar1 = (bool)hasExclusiveAccess(psVar4);
    } while (!bVar1);
    *psVar4 = sVar3 - 1;
    if (sVar3 - 1 == 0) {
      json_delete(value);
    }
  }
  return -1;
}



/* WARNING: Unknown calling convention */

int json_object_set_new(json_t *json,char *key,json_t *value)

{
  int iVar1;
  size_t sVar2;
  
  if ((key != (char *)0x0) && (iVar1 = utf8_check_string(key,-1), iVar1 != 0)) {
    iVar1 = json_object_set_new_nocheck(json,key,value);
    return iVar1;
  }
  if ((value != (json_t *)0x0) &&
     ((value->refcount != 0xffffffff &&
      (sVar2 = value->refcount - 1, value->refcount = sVar2, sVar2 == 0)))) {
    json_delete(value);
  }
  return -1;
}


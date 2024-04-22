
/* WARNING: Unknown calling convention */

int json_object_set_new_nocheck(json_t *json,char *key,json_t *value)

{
  json_object_t *object;
  int iVar1;
  size_t sVar2;
  
  if (value != (json_t *)0x0) {
    if (((json != (json_t *)0x0 && key != (char *)0x0) && (json->type == JSON_OBJECT)) &&
       (json != value)) {
      sVar2 = json[3].refcount;
      json[3].refcount = sVar2 + 1;
      iVar1 = hashtable_set((hashtable_t *)(json + 1),key,sVar2,value);
      if (iVar1 == 0) {
        return 0;
      }
    }
    if ((value->refcount != 0xffffffff) &&
       (sVar2 = value->refcount - 1, value->refcount = sVar2, sVar2 == 0)) {
      json_delete(value);
    }
  }
  return -1;
}


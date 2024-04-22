
/* WARNING: Unknown calling convention */

int json_object_del(json_t *json,char *key)

{
  json_object_t *object;
  int iVar1;
  
  if ((json != (json_t *)0x0) && (json->type == JSON_OBJECT)) {
    object = (json_object_t *)(json + 1);
    iVar1 = hashtable_del((hashtable_t *)object,key);
    return iVar1;
  }
  return -1;
}


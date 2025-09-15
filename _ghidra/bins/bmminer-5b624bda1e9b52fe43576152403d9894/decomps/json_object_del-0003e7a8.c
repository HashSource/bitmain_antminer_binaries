
/* WARNING: Unknown calling convention */

int json_object_del(json_t *json,char *key)

{
  int iVar1;
  
  if ((json != (json_t *)0x0) && (json->type == JSON_OBJECT)) {
    iVar1 = hashtable_del((hashtable_t *)(json + 1),key);
    return iVar1;
  }
  return -1;
}


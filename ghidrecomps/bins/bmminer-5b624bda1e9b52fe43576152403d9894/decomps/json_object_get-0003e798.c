
/* WARNING: Unknown calling convention */

json_t * json_object_get(json_t *json,char *key)

{
  json_object_t *object;
  json_t *pjVar1;
  
  if ((json != (json_t *)0x0) && (json->type == JSON_OBJECT)) {
    object = (json_object_t *)(json + 1);
    pjVar1 = (json_t *)hashtable_get((hashtable_t *)object,key);
    return pjVar1;
  }
  return (json_t *)0x0;
}


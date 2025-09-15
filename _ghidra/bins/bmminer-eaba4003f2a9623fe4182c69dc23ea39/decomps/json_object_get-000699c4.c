
json_t * json_object_get(json_t *json,char *key)

{
  json_t *pjVar1;
  char *key_local;
  json_t *json_local;
  json_object_t *object;
  
  if (((key == (char *)0x0) || (json == (json_t *)0x0)) || (json->type != JSON_OBJECT)) {
    pjVar1 = (json_t *)0x0;
  }
  else {
    pjVar1 = (json_t *)hashtable_get((hashtable_t *)(json + 1),key);
  }
  return pjVar1;
}



/* WARNING: Unknown calling convention */

json_t * json_object(void)

{
  json_t *json;
  int iVar1;
  json_object_t *object;
  
  json = (json_t *)jsonp_malloc(0x28);
  if (json == (json_t *)0x0) {
    json = (json_t *)0x0;
  }
  else {
    if (hashtable_seed == 0) {
      json_object_seed(0);
    }
    json_init(json,JSON_OBJECT);
    iVar1 = hashtable_init((hashtable_t *)(json + 1));
    if (iVar1 == 0) {
      json[4].refcount = 0;
    }
    else {
      jsonp_free(json);
      json = (json_t *)0x0;
    }
  }
  return json;
}


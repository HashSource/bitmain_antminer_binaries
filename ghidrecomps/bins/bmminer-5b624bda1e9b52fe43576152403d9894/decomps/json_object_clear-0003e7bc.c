
/* WARNING: Unknown calling convention */

int json_object_clear(json_t *json)

{
  json_object_t *object;
  
  if ((json != (json_t *)0x0) && (json->type == JSON_OBJECT)) {
    object = (json_object_t *)(json + 1);
    hashtable_clear((hashtable_t *)object);
    json[3].refcount = 0;
    return 0;
  }
  return -1;
}


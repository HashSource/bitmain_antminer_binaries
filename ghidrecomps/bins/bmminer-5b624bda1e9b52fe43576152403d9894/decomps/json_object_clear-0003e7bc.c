
/* WARNING: Unknown calling convention */

int json_object_clear(json_t *json)

{
  if ((json != (json_t *)0x0) && (json->type == JSON_OBJECT)) {
    hashtable_clear((hashtable_t *)(json + 1));
    json[3].refcount = 0;
    return 0;
  }
  return -1;
}


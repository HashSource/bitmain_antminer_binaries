
/* WARNING: Unknown calling convention */

int json_object_iter_set_new(json_t *json,void *iter,json_t *value)

{
  if (((json != (json_t *)0x0) && (json->type == JSON_OBJECT)) &&
     (iter != (void *)0x0 && value != (json_t *)0x0)) {
    hashtable_iter_set(iter,value);
    return 0;
  }
  return -1;
}


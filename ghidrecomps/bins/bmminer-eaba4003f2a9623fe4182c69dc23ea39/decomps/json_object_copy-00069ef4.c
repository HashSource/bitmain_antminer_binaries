
json_t * json_object_copy(json_t *object)

{
  json_t *object_00;
  void *pvVar1;
  json_t *value_00;
  json_t *object_local;
  json_t *value;
  json_t *result;
  char *key;
  
  object_00 = json_object();
  if (object_00 == (json_t *)0x0) {
    object_00 = (json_t *)0x0;
  }
  else {
    pvVar1 = json_object_iter(object);
    key = json_object_iter_key(pvVar1);
    while (key != (char *)0x0) {
      pvVar1 = json_object_key_to_iter(key);
      value_00 = json_object_iter_value(pvVar1);
      if (value_00 == (json_t *)0x0) {
        return object_00;
      }
      json_object_set_nocheck(object_00,key,value_00);
      pvVar1 = json_object_key_to_iter(key);
      pvVar1 = json_object_iter_next(object,pvVar1);
      key = json_object_iter_key(pvVar1);
    }
  }
  return object_00;
}


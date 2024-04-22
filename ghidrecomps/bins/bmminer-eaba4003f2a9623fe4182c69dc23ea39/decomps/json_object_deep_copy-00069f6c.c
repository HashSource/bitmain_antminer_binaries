
json_t * json_object_deep_copy(json_t *object)

{
  json_t *json;
  char *key_00;
  json_t *pjVar1;
  json_t *object_local;
  json_t *value;
  char *key;
  json_t *result;
  void *iter;
  
  json = json_object();
  if (json == (json_t *)0x0) {
    json = (json_t *)0x0;
  }
  else {
    for (iter = json_object_iter(object); iter != (void *)0x0;
        iter = json_object_iter_next(object,iter)) {
      key_00 = json_object_iter_key(iter);
      pjVar1 = json_object_iter_value(iter);
      pjVar1 = json_deep_copy(pjVar1);
      json_object_set_new_nocheck(json,key_00,pjVar1);
    }
  }
  return json;
}


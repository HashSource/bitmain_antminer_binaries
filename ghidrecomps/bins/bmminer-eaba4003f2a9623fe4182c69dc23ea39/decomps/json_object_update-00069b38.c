
int json_object_update(json_t *object,json_t *other)

{
  void *pvVar1;
  json_t *value_00;
  int iVar2;
  json_t *other_local;
  json_t *object_local;
  json_t *value;
  char *key;
  
  if ((((object == (json_t *)0x0) || (object->type != JSON_OBJECT)) || (other == (json_t *)0x0)) ||
     (other->type != JSON_OBJECT)) {
    iVar2 = -1;
  }
  else {
    pvVar1 = json_object_iter(other);
    key = json_object_iter_key(pvVar1);
    while (key != (char *)0x0) {
      pvVar1 = json_object_key_to_iter(key);
      value_00 = json_object_iter_value(pvVar1);
      if (value_00 == (json_t *)0x0) break;
      iVar2 = json_object_set_nocheck(object,key,value_00);
      if (iVar2 != 0) {
        return -1;
      }
      pvVar1 = json_object_key_to_iter(key);
      pvVar1 = json_object_iter_next(other,pvVar1);
      key = json_object_iter_key(pvVar1);
    }
    iVar2 = 0;
  }
  return iVar2;
}



/* WARNING: Unknown calling convention */

int json_object_update(json_t *object,json_t *other)

{
  void *pvVar1;
  char *key;
  json_t *value;
  int iVar2;
  
  if ((((object == (json_t *)0x0) || (object->type != JSON_OBJECT)) || (other == (json_t *)0x0)) ||
     (other->type != JSON_OBJECT)) {
    return -1;
  }
  pvVar1 = json_object_iter(other);
  key = json_object_iter_key(pvVar1);
  while( true ) {
    if (key == (char *)0x0) {
      return 0;
    }
    value = json_object_iter_value(key + -0x10);
    if (value == (json_t *)0x0) break;
    if (value->refcount != 0xffffffff) {
      value->refcount = value->refcount + 1;
    }
    iVar2 = json_object_set_new_nocheck(object,key,value);
    if (iVar2 != 0) {
      return -1;
    }
    pvVar1 = json_object_iter_next(other,key + -0x10);
    key = json_object_iter_key(pvVar1);
  }
  return 0;
}


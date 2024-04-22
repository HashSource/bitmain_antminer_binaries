
/* WARNING: Unknown calling convention */

int json_object_update(json_t *object,json_t *other)

{
  void *pvVar1;
  char *key_00;
  char *key;
  json_t *value_00;
  json_t *value;
  int iVar2;
  
  if ((((object == (json_t *)0x0) || (object->type != JSON_OBJECT)) || (other == (json_t *)0x0)) ||
     (other->type != JSON_OBJECT)) {
    return -1;
  }
  pvVar1 = json_object_iter(other);
  key_00 = json_object_iter_key(pvVar1);
  while( true ) {
    if (key_00 == (char *)0x0) {
      return 0;
    }
    value_00 = json_object_iter_value(key_00 + -0x10);
    if (value_00 == (json_t *)0x0) break;
    if (value_00->refcount != 0xffffffff) {
      value_00->refcount = value_00->refcount + 1;
    }
    iVar2 = json_object_set_new_nocheck(object,key_00,value_00);
    if (iVar2 != 0) {
      return -1;
    }
    pvVar1 = json_object_iter_next(other,key_00 + -0x10);
    key_00 = json_object_iter_key(pvVar1);
  }
  return 0;
}


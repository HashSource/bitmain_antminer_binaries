
/* WARNING: Unknown calling convention */

json_t * json_object(void)

{
  int iVar1;
  json_object_t *object;
  
  object = (json_object_t *)jsonp_malloc(0x24);
  if (object != (json_object_t *)0x0) {
    if (*DAT_0003e784 == 0) {
      json_object_seed(0);
    }
    (object->json).refcount = 1;
    (object->json).type = JSON_OBJECT;
    iVar1 = hashtable_init(&object->hashtable);
    if (iVar1 == 0) {
      object->serial = 0;
      object->visited = 0;
    }
    else {
      _jsonp_free(&object);
      object = (json_object_t *)0x0;
    }
  }
  return &object->json;
}


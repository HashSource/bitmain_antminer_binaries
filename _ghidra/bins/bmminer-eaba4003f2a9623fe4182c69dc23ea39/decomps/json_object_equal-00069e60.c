
int json_object_equal(json_t *object1,json_t *object2)

{
  size_t sVar1;
  size_t sVar2;
  void *pvVar3;
  json_t *json2;
  json_t *json1;
  int iVar4;
  json_t *object2_local;
  json_t *object1_local;
  json_t *value2;
  json_t *value1;
  char *key;
  
  sVar1 = json_object_size(object1);
  sVar2 = json_object_size(object2);
  if (sVar1 == sVar2) {
    pvVar3 = json_object_iter(object1);
    key = json_object_iter_key(pvVar3);
    while (key != (char *)0x0) {
      pvVar3 = json_object_key_to_iter(key);
      json1 = json_object_iter_value(pvVar3);
      if (json1 == (json_t *)0x0) break;
      json2 = json_object_get(object2,key);
      iVar4 = json_equal(json1,json2);
      if (iVar4 == 0) {
        return 0;
      }
      pvVar3 = json_object_key_to_iter(key);
      pvVar3 = json_object_iter_next(object1,pvVar3);
      key = json_object_iter_key(pvVar3);
    }
    iVar4 = 1;
  }
  else {
    iVar4 = 0;
  }
  return iVar4;
}


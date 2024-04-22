
int json_array_clear(json_t *json)

{
  int iVar1;
  json_t *json_local;
  json_array_t *array;
  size_t i;
  
  if ((json == (json_t *)0x0) || (json->type != JSON_ARRAY)) {
    iVar1 = -1;
  }
  else {
    for (i = 0; i < json[1].refcount; i = i + 1) {
      json_decref(*(json_t **)(json[2].type + i * 4));
    }
    json[1].refcount = 0;
    iVar1 = 0;
  }
  return iVar1;
}



int json_array_set_new(json_t *json,size_t index,json_t *value)

{
  int iVar1;
  json_t *value_local;
  size_t index_local;
  json_t *json_local;
  json_array_t *array;
  
  if (value == (json_t *)0x0) {
    iVar1 = -1;
  }
  else if (((json == (json_t *)0x0) || (json->type != JSON_ARRAY)) || (json == value)) {
    json_decref(value);
    iVar1 = -1;
  }
  else if (index < json[1].refcount) {
    json_decref(*(json_t **)(json[2].type + index * 4));
    *(json_t **)(json[2].type + index * 4) = value;
    iVar1 = 0;
  }
  else {
    json_decref(value);
    iVar1 = -1;
  }
  return iVar1;
}


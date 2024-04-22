
int json_array_append_new(json_t *json,json_t *value)

{
  json_t **ppjVar1;
  int iVar2;
  json_t *value_local;
  json_t *json_local;
  json_array_t *array;
  
  if (value == (json_t *)0x0) {
    iVar2 = -1;
  }
  else if (((json == (json_t *)0x0) || (json->type != JSON_ARRAY)) || (json == value)) {
    json_decref(value);
    iVar2 = -1;
  }
  else {
    ppjVar1 = json_array_grow((json_array_t *)json,1,1);
    if (ppjVar1 == (json_t **)0x0) {
      json_decref(value);
      iVar2 = -1;
    }
    else {
      *(json_t **)(json[2].type + json[1].refcount * 4) = value;
      json[1].refcount = json[1].refcount + 1;
      iVar2 = 0;
    }
  }
  return iVar2;
}


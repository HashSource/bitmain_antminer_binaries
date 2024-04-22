
json_t * json_array_get(json_t *json,size_t index)

{
  json_t *pjVar1;
  size_t index_local;
  json_t *json_local;
  json_array_t *array;
  
  if ((json == (json_t *)0x0) || (json->type != JSON_ARRAY)) {
    pjVar1 = (json_t *)0x0;
  }
  else if (index < json[1].refcount) {
    pjVar1 = *(json_t **)(json[2].type + index * 4);
  }
  else {
    pjVar1 = (json_t *)0x0;
  }
  return pjVar1;
}


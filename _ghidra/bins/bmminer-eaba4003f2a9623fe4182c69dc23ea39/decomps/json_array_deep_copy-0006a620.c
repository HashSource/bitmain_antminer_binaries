
json_t * json_array_deep_copy(json_t *array)

{
  json_t *json;
  json_t *pjVar1;
  size_t sVar2;
  json_t *array_local;
  json_t *result;
  size_t i;
  
  json = json_array();
  if (json == (json_t *)0x0) {
    json = (json_t *)0x0;
  }
  else {
    for (i = 0; sVar2 = json_array_size(array), i < sVar2; i = i + 1) {
      pjVar1 = json_array_get(array,i);
      pjVar1 = json_deep_copy(pjVar1);
      json_array_append_new(json,pjVar1);
    }
  }
  return json;
}


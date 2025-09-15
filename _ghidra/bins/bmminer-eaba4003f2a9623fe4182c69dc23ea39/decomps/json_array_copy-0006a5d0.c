
json_t * json_array_copy(json_t *array)

{
  json_t *array_00;
  json_t *value;
  size_t sVar1;
  json_t *array_local;
  json_t *result;
  size_t i;
  
  array_00 = json_array();
  if (array_00 == (json_t *)0x0) {
    array_00 = (json_t *)0x0;
  }
  else {
    for (i = 0; sVar1 = json_array_size(array), i < sVar1; i = i + 1) {
      value = json_array_get(array,i);
      json_array_append(array_00,value);
    }
  }
  return array_00;
}


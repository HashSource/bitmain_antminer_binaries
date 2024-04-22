
/* WARNING: Unknown calling convention */

json_t * json_array_get(json_t *json,size_t index)

{
  json_array_t *array;
  
  if (json != (json_t *)0x0) {
    if ((json->type == JSON_ARRAY) && (index < json[1].refcount)) {
      return *(json_t **)(json[2].type + index * 4);
    }
    json = (json_t *)0x0;
  }
  return json;
}


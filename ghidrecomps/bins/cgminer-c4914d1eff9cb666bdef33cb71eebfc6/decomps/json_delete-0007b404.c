
void json_delete(json_t *json)

{
  json_t *json_local;
  
  if (json != (json_t *)0x0) {
    switch(json->type) {
    case JSON_OBJECT:
      json_delete_object((json_object_t *)json);
      break;
    case JSON_ARRAY:
      json_delete_array((json_array_t *)json);
      break;
    case JSON_STRING:
      json_delete_string((json_string_t *)json);
      break;
    case JSON_INTEGER:
      json_delete_integer((json_integer_t *)json);
      break;
    case JSON_REAL:
      json_delete_real((json_real_t *)json);
    }
  }
  return;
}


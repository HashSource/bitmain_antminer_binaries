
json_t * json_deep_copy(json_t *json)

{
  json_t *json_local;
  
  if (json == (json_t *)0x0) {
    json = (json_t *)0x0;
  }
  else {
    switch(json->type) {
    case JSON_OBJECT:
      json = json_object_deep_copy(json);
      break;
    case JSON_ARRAY:
      json = json_array_deep_copy(json);
      break;
    case JSON_STRING:
      json = json_string_copy(json);
      break;
    case JSON_INTEGER:
      json = json_integer_copy(json);
      break;
    case JSON_REAL:
      json = json_real_copy(json);
      break;
    case JSON_TRUE:
    case JSON_FALSE:
    case JSON_NULL:
      break;
    default:
      json = (json_t *)0x0;
    }
  }
  return json;
}


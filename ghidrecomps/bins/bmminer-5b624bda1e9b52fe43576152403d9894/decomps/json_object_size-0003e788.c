
/* WARNING: Unknown calling convention */

size_t json_object_size(json_t *json)

{
  json_object_t *object;
  
  if (json != (json_t *)0x0) {
    if (json->type == JSON_OBJECT) {
      object = (json_object_t *)json[1].type;
      return (size_t)object;
    }
    json = (json_t *)0x0;
  }
  return (size_t)json;
}



/* WARNING: Unknown calling convention */

size_t json_object_size(json_t *json)

{
  if (json != (json_t *)0x0) {
    if (json->type == JSON_OBJECT) {
      return json[1].type;
    }
    json = (json_t *)0x0;
  }
  return (size_t)json;
}



/* WARNING: Unknown calling convention */

size_t json_string_length(json_t *json)

{
  if (json != (json_t *)0x0) {
    if (json->type == JSON_STRING) {
      return json[1].refcount;
    }
    json = (json_t *)0x0;
  }
  return (size_t)json;
}


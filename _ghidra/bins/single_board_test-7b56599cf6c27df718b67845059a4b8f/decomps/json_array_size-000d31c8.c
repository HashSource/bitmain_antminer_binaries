
/* WARNING: Unknown calling convention */

size_t json_array_size(json_t *json)

{
  if (json != (json_t *)0x0) {
    if (json->type == JSON_ARRAY) {
      return json[1].refcount;
    }
    json = (json_t *)0x0;
  }
  return (size_t)json;
}


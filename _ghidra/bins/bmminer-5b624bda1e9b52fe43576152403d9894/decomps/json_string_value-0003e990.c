
/* WARNING: Unknown calling convention */

char * json_string_value(json_t *json)

{
  if (json != (json_t *)0x0) {
    if (json->type == JSON_STRING) {
      return (char *)json[1].type;
    }
    json = (json_t *)0x0;
  }
  return (char *)json;
}


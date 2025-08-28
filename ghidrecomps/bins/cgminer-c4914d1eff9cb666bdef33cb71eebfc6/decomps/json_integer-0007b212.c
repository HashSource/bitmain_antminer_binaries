
json_t * json_integer(json_int_t value)

{
  json_t *json;
  json_int_t value_local;
  json_integer_t *integer;
  
  json = (json_t *)jsonp_malloc(0x10);
  if (json == (json_t *)0x0) {
    json = (json_t *)0x0;
  }
  else {
    json_init(json,JSON_INTEGER);
    json[1].type = (int)value;
    json[1].refcount = (int)((ulonglong)value >> 0x20);
  }
  return json;
}


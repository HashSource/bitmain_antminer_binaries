
json_t * json_integer(json_int_t value)

{
  json_type in_r0;
  json_t *json;
  size_t in_r1;
  json_int_t value_local;
  json_integer_t *integer;
  
  json = (json_t *)jsonp_malloc(0x10);
  if (json == (json_t *)0x0) {
    json = (json_t *)0x0;
  }
  else {
    json_init(json,JSON_INTEGER);
    json[1].type = in_r0;
    json[1].refcount = in_r1;
  }
  return json;
}


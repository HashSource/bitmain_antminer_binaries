
int json_integer_set(json_t *json,json_int_t value)

{
  json_type in_r2;
  size_t in_r3;
  
  if ((json != (json_t *)0x0) && (json->type == JSON_INTEGER)) {
    json[1].type = in_r2;
    json[1].refcount = in_r3;
    return 0;
  }
  return -1;
}


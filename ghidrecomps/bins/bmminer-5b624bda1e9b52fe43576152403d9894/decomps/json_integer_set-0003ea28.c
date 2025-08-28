
int json_integer_set(json_t *json,json_int_t value)

{
  if ((json != (json_t *)0x0) && (json->type == JSON_INTEGER)) {
    json[1].type = (int)value;
    json[1].refcount = (int)((ulonglong)value >> 0x20);
    return 0;
  }
  return -1;
}


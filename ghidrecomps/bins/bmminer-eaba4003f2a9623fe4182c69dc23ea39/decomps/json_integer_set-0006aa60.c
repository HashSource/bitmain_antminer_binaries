
int json_integer_set(json_t *json,json_int_t value)

{
  int iVar1;
  json_int_t value_local;
  json_t *json_local;
  
  if ((json == (json_t *)0x0) || (json->type != JSON_INTEGER)) {
    iVar1 = -1;
  }
  else {
    json[1].type = (int)value;
    json[1].refcount = (int)((ulonglong)value >> 0x20);
    iVar1 = 0;
  }
  return iVar1;
}


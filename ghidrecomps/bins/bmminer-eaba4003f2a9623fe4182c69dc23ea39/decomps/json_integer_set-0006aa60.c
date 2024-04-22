
int json_integer_set(json_t *json,json_int_t value)

{
  json_type in_r2;
  size_t in_r3;
  int iVar1;
  json_int_t value_local;
  json_t *json_local;
  
  if ((json == (json_t *)0x0) || (json->type != JSON_INTEGER)) {
    iVar1 = -1;
  }
  else {
    json[1].type = in_r2;
    json[1].refcount = in_r3;
    iVar1 = 0;
  }
  return iVar1;
}


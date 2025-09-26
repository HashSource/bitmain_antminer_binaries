
int json_array_append(json_t *array,json_t *value)

{
  json_t *value_00;
  int iVar1;
  json_t *value_local;
  json_t *array_local;
  
  value_00 = json_incref(value);
  iVar1 = json_array_append_new(array,value_00);
  return iVar1;
}


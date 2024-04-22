
int json_object_set_nocheck(json_t *object,char *key,json_t *value)

{
  json_t *value_00;
  int iVar1;
  json_t *value_local;
  char *key_local;
  json_t *object_local;
  
  value_00 = json_incref(value);
  iVar1 = json_object_set_new_nocheck(object,key,value_00);
  return iVar1;
}


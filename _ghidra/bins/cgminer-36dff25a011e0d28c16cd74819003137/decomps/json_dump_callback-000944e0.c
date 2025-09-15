
int json_dump_callback(json_t *json,json_dump_callback_t callback,void *data,size_t flags)

{
  int iVar1;
  size_t flags_local;
  void *data_local;
  json_dump_callback_t callback_local;
  json_t *json_local;
  
  if ((((flags & 0x200) == 0) && ((json == (json_t *)0x0 || (json->type != JSON_ARRAY)))) &&
     ((json == (json_t *)0x0 || (json->type != JSON_OBJECT)))) {
    iVar1 = -1;
  }
  else {
    iVar1 = do_dump(json,flags,0,callback,data);
  }
  return iVar1;
}


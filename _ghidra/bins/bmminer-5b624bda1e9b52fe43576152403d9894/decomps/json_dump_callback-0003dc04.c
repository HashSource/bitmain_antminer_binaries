
/* WARNING: Unknown calling convention */

int json_dump_callback(json_t *json,json_dump_callback_t callback,void *data,size_t flags)

{
  int iVar1;
  
  if (((int)(flags << 0x16) < 0) || ((json != (json_t *)0x0 && (json->type < JSON_STRING)))) {
    iVar1 = do_dump(json,flags,0,callback,data);
  }
  else {
    iVar1 = -1;
  }
  return iVar1;
}


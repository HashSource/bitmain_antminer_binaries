
/* WARNING: Unknown calling convention */

int json_dumpfd(json_t *json,int output,size_t flags)

{
  int iVar1;
  int local_c;
  
  local_c = output;
  iVar1 = json_dump_callback(json,(json_dump_callback_t)0x1d30e1,&local_c,flags);
  return iVar1;
}


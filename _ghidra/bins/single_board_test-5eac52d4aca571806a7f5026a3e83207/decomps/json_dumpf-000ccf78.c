
/* WARNING: Unknown calling convention */

int json_dumpf(json_t *json,FILE *output,size_t flags)

{
  int iVar1;
  
  iVar1 = json_dump_callback(json,(json_dump_callback_t)0xcca09,output,flags);
  return iVar1;
}


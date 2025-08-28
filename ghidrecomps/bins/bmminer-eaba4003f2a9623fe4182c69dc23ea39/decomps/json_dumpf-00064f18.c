
int json_dumpf(json_t *json,FILE *output,size_t flags)

{
  int iVar1;
  size_t flags_local;
  FILE *output_local;
  json_t *json_local;
  
  iVar1 = json_dump_callback(json,(json_dump_callback_t)0x64511,output,flags);
  return iVar1;
}


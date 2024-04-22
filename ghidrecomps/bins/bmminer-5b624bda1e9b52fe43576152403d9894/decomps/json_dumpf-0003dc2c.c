
/* WARNING: Unknown calling convention */

int json_dumpf(json_t *json,FILE *output,size_t flags)

{
  int iVar1;
  
  iVar1 = json_dump_callback(json,dump_to_file + 1,output,flags);
  return iVar1;
}


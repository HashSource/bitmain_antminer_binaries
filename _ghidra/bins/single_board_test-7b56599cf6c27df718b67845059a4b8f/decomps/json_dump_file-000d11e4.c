
/* WARNING: Unknown calling convention */

int json_dump_file(json_t *json,char *path,size_t flags)

{
  FILE *output;
  int iVar1;
  int iVar2;
  
  output = fopen(path,"w");
  if (output != (FILE *)0x0) {
    iVar1 = json_dumpf(json,(FILE *)output,flags);
    iVar2 = fclose(output);
    if (iVar2 == 0) {
      return iVar1;
    }
  }
  return -1;
}


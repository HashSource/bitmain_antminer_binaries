
/* WARNING: Unknown calling convention */

int json_dump_file(json_t *json,char *path,size_t flags)

{
  FILE *output;
  int iVar1;
  
  output = fopen(path,"w");
  if (output == (FILE *)0x0) {
    iVar1 = -1;
  }
  else {
    iVar1 = json_dumpf(json,(FILE *)output,flags);
    fclose(output);
  }
  return iVar1;
}


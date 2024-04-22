
int json_dump_file(json_t *json,char *path,size_t flags)

{
  FILE *output_00;
  int iVar1;
  size_t flags_local;
  char *path_local;
  json_t *json_local;
  int result;
  FILE *output;
  
  output_00 = fopen(path,"w");
  if (output_00 == (FILE *)0x0) {
    iVar1 = -1;
  }
  else {
    iVar1 = json_dumpf(json,(FILE *)output_00,flags);
    fclose(output_00);
  }
  return iVar1;
}


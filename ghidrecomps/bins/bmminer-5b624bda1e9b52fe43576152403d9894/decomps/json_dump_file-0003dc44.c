
/* WARNING: Unknown calling convention */

int json_dump_file(json_t *json,char *path,size_t flags)

{
  FILE *output_00;
  FILE *output;
  int iVar1;
  int result;
  
  output_00 = fopen(path,DAT_0003dc74);
  if (output_00 == (FILE *)0x0) {
    iVar1 = -1;
  }
  else {
    iVar1 = json_dumpf(json,(FILE *)output_00,flags);
    fclose(output_00);
  }
  return iVar1;
}


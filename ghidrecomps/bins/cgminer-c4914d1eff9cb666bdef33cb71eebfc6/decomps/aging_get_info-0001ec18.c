
/* WARNING: Unknown calling convention */

void aging_get_info(void)

{
  FILE *__stream;
  FILE *fd;
  
  __stream = fopen(aging_file,"rb");
  if (__stream == (FILE *)0x0) {
    memset(&aging_info,0,0x99c0);
  }
  else {
    fread(&aging_info,1,0x99c0,__stream);
  }
  aging_info.is_aging_finished = true;
  if (__stream != (FILE *)0x0) {
    fclose(__stream);
  }
  return;
}


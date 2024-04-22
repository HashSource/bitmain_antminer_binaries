
void clear_log(char *file)

{
  FILE *__stream;
  char *file_local;
  FILE *fd;
  
  __stream = fopen(file,"w");
  if (__stream != (FILE *)0x0) {
    fclose(__stream);
  }
  return;
}


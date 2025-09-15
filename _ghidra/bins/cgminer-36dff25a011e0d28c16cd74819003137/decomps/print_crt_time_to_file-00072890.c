
void print_crt_time_to_file(char *file,uint level)

{
  uint level_local;
  char *file_local;
  char buffer [26];
  time_t timer;
  FILE *pFile;
  tm *tm_info;
  
  time(&timer);
  tm_info = (tm *)localtime(&timer);
  strftime(buffer,0x1a,"%Y-%m-%d %H:%M:%S",(tm *)tm_info);
  if (level < log_level) {
    pFile = (FILE *)fopen(file,"a+");
    if (pFile != (FILE *)0x0) {
      fprintf((FILE *)pFile,"%s ",buffer);
    }
    fclose((FILE *)pFile);
  }
  return;
}


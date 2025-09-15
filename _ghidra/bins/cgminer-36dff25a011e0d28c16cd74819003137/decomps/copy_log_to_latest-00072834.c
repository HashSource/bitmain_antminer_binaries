
void copy_log_to_latest(char *file)

{
  char *file_local;
  char cmd [512];
  
  memset(cmd,0,0x200);
  sprintf(cmd,"if [ -f %s ];then cp %s %s_latest;fi;",file,file,file);
  system(cmd);
  return;
}


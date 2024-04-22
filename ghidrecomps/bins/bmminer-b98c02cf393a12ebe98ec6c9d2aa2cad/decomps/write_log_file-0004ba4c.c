
void write_log_file(undefined4 param_1,char *param_2)

{
  FILE *__stream;
  char acStack_110 [260];
  
  sprintf(acStack_110,"%s/%s","/config",param_1);
  __stream = fopen(acStack_110,"w+");
  fputs(param_2,__stream);
  fclose(__stream);
  return;
}


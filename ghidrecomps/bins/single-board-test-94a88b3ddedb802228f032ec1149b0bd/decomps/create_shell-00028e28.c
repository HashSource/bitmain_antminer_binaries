
undefined4 create_shell(undefined4 param_1)

{
  size_t sVar1;
  char local_40c [8];
  undefined2 local_404;
  undefined1 local_402;
  FILE *local_c;
  
  local_c = fopen("/etc/config/run.sh","wb");
  builtin_strncpy(local_40c,"#!/bin/s",8);
  local_404 = 0xa68;
  local_402 = 0;
  sVar1 = strlen(local_40c);
  fwrite(local_40c,1,sVar1,local_c);
  sprintf(local_40c,"%s\n",param_1);
  sVar1 = strlen(local_40c);
  fwrite(local_40c,1,sVar1,local_c);
  fclose(local_c);
  system("chmod +x /etc/config/run.sh");
  return 0;
}


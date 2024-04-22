
int v9_key_read(char *command,int len)

{
  ssize_t sVar1;
  int len_local;
  char *command_local;
  
  lseek(cgpu.key_fd,0,0);
  sVar1 = read(cgpu.key_fd,command,len);
  return sVar1;
}


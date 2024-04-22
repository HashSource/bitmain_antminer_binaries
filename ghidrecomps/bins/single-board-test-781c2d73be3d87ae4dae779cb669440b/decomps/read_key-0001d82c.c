
/* WARNING: Unknown calling convention */

ssize_t read_key(char *value)

{
  ssize_t sVar1;
  
  lseek(key_fd,0,0);
  sVar1 = read(key_fd,value,1);
  if (sVar1 != 1) {
    printf("%s: can\'t read out key value\n","read_key");
    sVar1 = -1;
  }
  return sVar1;
}



/* WARNING: Unknown calling convention */

int fd_get_func(int *fd)

{
  ssize_t sVar1;
  uint uVar2;
  uint8_t c;
  
  sVar1 = read(*fd,&c,1);
  if (sVar1 == 1) {
    uVar2 = (uint)c;
  }
  else {
    uVar2 = 0xffffffff;
  }
  return uVar2;
}


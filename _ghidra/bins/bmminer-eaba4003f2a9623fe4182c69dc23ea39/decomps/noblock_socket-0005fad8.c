
void noblock_socket(long fd)

{
  uint uVar1;
  long fd_local;
  int flags;
  
  uVar1 = fcntl(fd,3,0);
  fcntl(fd,4,uVar1 | 0x800);
  return;
}


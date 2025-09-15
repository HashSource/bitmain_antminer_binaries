
int recv_byte(int sockd)

{
  ssize_t sVar1;
  uint uVar2;
  int sockd_local;
  char c;
  
  sVar1 = recv(sockd,&c,1,0);
  if (sVar1 == -1) {
    uVar2 = 0xffffffff;
  }
  else {
    uVar2 = (uint)(byte)c;
  }
  return uVar2;
}


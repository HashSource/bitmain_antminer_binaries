
/* WARNING: Unknown calling convention */

int recv_byte(int sockd)

{
  uint uVar1;
  char c;
  
  uVar1 = recv(sockd,&c,1,0);
  if (uVar1 != 0xffffffff) {
    uVar1 = (uint)(byte)c;
  }
  return uVar1;
}


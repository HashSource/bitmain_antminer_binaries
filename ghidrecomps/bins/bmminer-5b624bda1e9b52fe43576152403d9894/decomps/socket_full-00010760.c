
/* WARNING: Unknown calling convention */

_Bool socket_full(pool *pool,int wait)

{
  undefined uVar1;
  int iVar2;
  long sock;
  int iVar3;
  __suseconds_t *p_Var4;
  timeval timeout;
  fd_set rd;
  
  iVar2 = pool->sock;
  timeout.tv_sec = wait & ~(wait >> 0x1f);
  p_Var4 = &timeout.tv_usec;
  do {
    p_Var4 = p_Var4 + 1;
    *p_Var4 = 0;
  } while (p_Var4 != rd.fds_bits + 0x1f);
  iVar3 = iVar2 + 0x1f;
  if (-1 < iVar2) {
    iVar3 = iVar2;
  }
  timeout.tv_usec = 0;
  rd.fds_bits[iVar3 >> 5] = 1 << (iVar2 % 0x20 & 0xffU) | rd.fds_bits[iVar3 >> 5];
  iVar3 = select(iVar2 + 1,(fd_set *)&rd,(fd_set *)0x0,(fd_set *)0x0,(timeval *)&timeout);
  iVar2 = iVar3;
  if (iVar3 < 1) {
    iVar2 = 0;
  }
  uVar1 = (undefined)iVar2;
  if (0 < iVar3) {
    uVar1 = 1;
  }
  return (_Bool)uVar1;
}


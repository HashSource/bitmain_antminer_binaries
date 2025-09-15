
_Bool socket_full(pool *pool,int wait)

{
  int iVar1;
  int iVar2;
  int wait_local;
  pool *pool_local;
  fd_set rd;
  timeval timeout;
  fd_set *__arr;
  long sock;
  uint __i;
  
  iVar1 = pool->sock;
  wait_local = wait;
  if (wait < 0) {
    wait_local = 0;
  }
  for (__i = 0; __i < 0x20; __i = __i + 1) {
    rd.fds_bits[__i] = 0;
  }
  iVar2 = iVar1;
  if (iVar1 < 0) {
    iVar2 = iVar1 + 0x1f;
  }
  rd.fds_bits[iVar2 >> 5] = rd.fds_bits[iVar2 >> 5] | 1 << (iVar1 % 0x20 & 0xffU);
  timeout.tv_usec = 0;
  timeout.tv_sec = wait_local;
  iVar1 = select(iVar1 + 1,(fd_set *)&rd,(fd_set *)0x0,(fd_set *)0x0,(timeval *)&timeout);
  return 0 < iVar1;
}


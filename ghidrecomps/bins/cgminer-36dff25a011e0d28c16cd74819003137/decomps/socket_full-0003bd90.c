
_Bool socket_full(pool *pool,int wait)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  int wait_local;
  pool *pool_local;
  fd_set rd;
  timeval timeout;
  fd_set *__arr;
  long sock;
  uint __i;
  
  sock = pool->sock;
  wait_local = wait;
  if (wait < 0) {
    wait_local = 0;
  }
  for (__i = 0; __i < 0x20; __i = __i + 1) {
    rd.fds_bits[__i] = 0;
  }
  uVar2 = sock + 0x1f;
  if (-1 < sock) {
    uVar2 = sock;
  }
  uVar3 = sock & 0x1f;
  if (sock < 1) {
    uVar3 = -(-sock & 0x1fU);
  }
  rd.fds_bits[(int)uVar2 >> 5] = rd.fds_bits[(int)uVar2 >> 5] | 1 << (uVar3 & 0xff);
  timeout.tv_usec = 0;
  timeout.tv_sec = wait_local;
  iVar1 = select(sock + 1,(fd_set *)&rd,(fd_set *)0x0,(fd_set *)0x0,(timeval *)&timeout);
  return 0 < iVar1;
}


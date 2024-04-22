
send_ret __stratum_send(pool *pool,char *s,ssize_t len)

{
  _Bool _Var1;
  size_t sVar2;
  uint uVar3;
  long lVar4;
  int iVar5;
  ssize_t len_local;
  char *s_local;
  pool *pool_local;
  char tmp42 [2048];
  timeval timeout;
  fd_set *__arr;
  long sock;
  uint __i;
  ssize_t sent;
  ssize_t ssent;
  
  sock = pool->sock;
  ssent = 0;
  if (((opt_protocol) && (opt_debug)) && ((use_syslog || ((opt_log_output || (6 < opt_log_level)))))
     ) {
    snprintf(tmp42,0x800,"SEND: %s",s);
    _applog(7,tmp42,false);
  }
  sVar2 = strlen(s);
  *(undefined2 *)(s + sVar2) = DAT_0007b128;
  len_local = len + 1;
  do {
    if (len_local < 1) {
      uVar3 = *(uint *)&(pool->cgminer_pool_stats).times_sent;
      iVar5 = *(int *)((int)&(pool->cgminer_pool_stats).times_sent + 4);
      *(uint *)&(pool->cgminer_pool_stats).times_sent = uVar3 + 1;
      *(uint *)((int)&(pool->cgminer_pool_stats).times_sent + 4) =
           iVar5 + (uint)(0xfffffffe < uVar3);
      uVar3 = *(uint *)&(pool->cgminer_pool_stats).bytes_sent;
      iVar5 = *(int *)((int)&(pool->cgminer_pool_stats).bytes_sent + 4);
      *(uint *)&(pool->cgminer_pool_stats).bytes_sent = ssent + uVar3;
      *(uint *)((int)&(pool->cgminer_pool_stats).bytes_sent + 4) =
           (ssent >> 0x1f) + iVar5 + (uint)CARRY4(ssent,uVar3);
      uVar3 = *(uint *)&(pool->cgminer_pool_stats).net_bytes_sent;
      iVar5 = *(int *)((int)&(pool->cgminer_pool_stats).net_bytes_sent + 4);
      *(uint *)&(pool->cgminer_pool_stats).net_bytes_sent = ssent + uVar3;
      *(uint *)((int)&(pool->cgminer_pool_stats).net_bytes_sent + 4) =
           (ssent >> 0x1f) + iVar5 + (uint)CARRY4(ssent,uVar3);
      return SEND_OK;
    }
    timeout.tv_sec = 1;
    timeout.tv_usec = 0;
    while( true ) {
      for (__i = 0; __i < 0x20; __i = __i + 1) {
        *(undefined4 *)(tmp42 + __i * 4) = 0;
      }
      lVar4 = sock;
      if (sock < 0) {
        lVar4 = sock + 0x1f;
      }
      *(uint *)(tmp42 + (lVar4 >> 5) * 4) =
           *(uint *)(tmp42 + (lVar4 >> 5) * 4) | 1 << (sock % 0x20 & 0xffU);
      iVar5 = select(sock + 1,(fd_set *)0x0,(fd_set *)tmp42,(fd_set *)0x0,(timeval *)&timeout);
      if (0 < iVar5) break;
      _Var1 = interrupted();
      if (!_Var1) {
        return SEND_SELECTFAIL;
      }
    }
    sent = send(pool->sock,s + ssent,len_local,0x4000);
    if (sent < 0) {
      _Var1 = sock_blocks();
      if (!_Var1) {
        return SEND_SENDFAIL;
      }
      sent = 0;
    }
    ssent = ssent + sent;
    len_local = len_local - sent;
  } while( true );
}


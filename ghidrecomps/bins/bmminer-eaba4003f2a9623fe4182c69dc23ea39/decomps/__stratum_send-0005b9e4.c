
send_ret __stratum_send(pool *pool,char *s,ssize_t len)

{
  char *pcVar1;
  _Bool _Var2;
  size_t sVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
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
  
  iVar6 = pool->sock;
  ssent = 0;
  if (((opt_protocol) && (opt_debug)) && ((use_syslog || ((opt_log_output || (6 < opt_log_level)))))
     ) {
    snprintf(tmp42,0x800,"SEND: %s",s);
    _applog(7,tmp42,false);
  }
  sVar3 = strlen(s);
  (s + sVar3)[0] = '\n';
  (s + sVar3)[1] = '\0';
  len_local = len + 1;
  do {
    if (len_local < 1) {
      uVar5 = (uint)(pool->cgminer_pool_stats).times_sent;
      iVar6 = *(int *)((int)&(pool->cgminer_pool_stats).times_sent + 4);
      *(uint *)&(pool->cgminer_pool_stats).times_sent = uVar5 + 1;
      *(uint *)((int)&(pool->cgminer_pool_stats).times_sent + 4) =
           iVar6 + (uint)(0xfffffffe < uVar5);
      uVar5 = (uint)(pool->cgminer_pool_stats).bytes_sent;
      iVar6 = *(int *)((int)&(pool->cgminer_pool_stats).bytes_sent + 4);
      *(uint *)&(pool->cgminer_pool_stats).bytes_sent = ssent + uVar5;
      *(uint *)((int)&(pool->cgminer_pool_stats).bytes_sent + 4) =
           (ssent >> 0x1f) + iVar6 + (uint)CARRY4(ssent,uVar5);
      uVar5 = (uint)(pool->cgminer_pool_stats).net_bytes_sent;
      iVar6 = *(int *)((int)&(pool->cgminer_pool_stats).net_bytes_sent + 4);
      *(uint *)&(pool->cgminer_pool_stats).net_bytes_sent = ssent + uVar5;
      *(uint *)((int)&(pool->cgminer_pool_stats).net_bytes_sent + 4) =
           (ssent >> 0x1f) + iVar6 + (uint)CARRY4(ssent,uVar5);
      return SEND_OK;
    }
    timeout.tv_sec = 1;
    timeout.tv_usec = 0;
    while( true ) {
      for (__i = 0; __i < 0x20; __i = __i + 1) {
        pcVar1 = tmp42 + __i * 4;
        pcVar1[0] = '\0';
        pcVar1[1] = '\0';
        pcVar1[2] = '\0';
        pcVar1[3] = '\0';
      }
      iVar4 = iVar6;
      if (iVar6 < 0) {
        iVar4 = iVar6 + 0x1f;
      }
      *(uint *)(tmp42 + (iVar4 >> 5) * 4) =
           *(uint *)(tmp42 + (iVar4 >> 5) * 4) | 1 << (iVar6 % 0x20 & 0xffU);
      iVar4 = select(iVar6 + 1,(fd_set *)0x0,(fd_set *)tmp42,(fd_set *)0x0,(timeval *)&timeout);
      if (0 < iVar4) break;
      _Var2 = interrupted();
      if (!_Var2) {
        return SEND_SELECTFAIL;
      }
    }
    sent = send(pool->sock,s + ssent,len_local,0x4000);
    if (sent < 0) {
      _Var2 = sock_blocks();
      if (!_Var2) {
        return SEND_SENDFAIL;
      }
      sent = 0;
    }
    ssent = ssent + sent;
    len_local = len_local - sent;
  } while( true );
}


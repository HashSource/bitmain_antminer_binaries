
char * recv_line(pool *pool)

{
  undefined4 uVar1;
  _Bool _Var2;
  char *pcVar3;
  ssize_t sVar4;
  size_t sVar5;
  size_t sVar6;
  uint uVar7;
  int iVar8;
  double dVar9;
  pool *pool_local;
  char tmp42_1 [2048];
  char tmp42 [2048];
  timeval now;
  timeval rstart;
  ssize_t len;
  char *tok;
  ssize_t buflen;
  size_t slen;
  ssize_t n;
  int waited;
  char *sret;
  
  sret = (char *)0x0;
  pcVar3 = strchr(pool->sockbuf,10);
  if (pcVar3 == (char *)0x0) {
    cgtime(&rstart);
    _Var2 = socket_full(pool,0x3c);
    uVar1 = tmp42._40_4_;
    if (_Var2) {
      do {
        memset(tmp42,0,0x2000);
        sVar4 = recv(pool->sock,tmp42,0x1ffc,0);
        if (sVar4 == 0) {
          if ((opt_debug != false) &&
             (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
            builtin_strncpy(tmp42_1,"Socket closed waiting in recv_li",0x20);
            tmp42_1[0x20] = 'n';
            tmp42_1[0x21] = 'e';
            tmp42_1[0x22] = '\0';
            _applog(7,tmp42_1,false);
          }
          suspend_stratum(pool);
          goto LAB_0003c4c8;
        }
        cgtime(&now);
        dVar9 = tdiff(&now,&rstart);
        if (sVar4 < 0) {
          _Var2 = sock_blocks();
          if ((!_Var2) || (_Var2 = socket_full(pool,0x3c - (int)(longlong)dVar9), !_Var2)) {
            if ((opt_debug != false) &&
               (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
              builtin_strncpy(tmp42_1,"Failed to recv sock in recv_line",0x20);
              tmp42_1._32_2_ = tmp42_1._32_2_ & 0xff00;
              _applog(7,tmp42_1,false);
            }
            suspend_stratum(pool);
            goto LAB_0003c4c8;
          }
        }
        else {
          sVar5 = strlen(tmp42);
          recalloc_sock(pool,sVar5);
          strcat(pool->sockbuf,tmp42);
        }
        if ((0x3b < (int)(longlong)dVar9) ||
           (pcVar3 = strchr(pool->sockbuf,10), pcVar3 != (char *)0x0)) goto LAB_0003c4c8;
      } while( true );
    }
    if ((opt_debug != false) &&
       (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
      builtin_strncpy(tmp42,"Timed out waiting for data on socket_full",0x2a);
      tmp42._42_2_ = SUB42(uVar1,2);
      _applog(7,tmp42,false);
    }
  }
  else {
LAB_0003c4c8:
    sVar5 = strlen(pool->sockbuf);
    pcVar3 = strtok(pool->sockbuf,"\n");
    if (pcVar3 == (char *)0x0) {
      if ((opt_debug != false) &&
         (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
        builtin_strncpy(tmp42,"Failed to parse a \\n terminated string in recv_line",0x34);
        _applog(7,tmp42,false);
      }
    }
    else {
      sret = strdup(pcVar3);
      sVar6 = strlen(sret);
      if ((int)(sVar6 + 1) < (int)sVar5) {
        memmove(pool->sockbuf,pool->sockbuf + sVar6 + 1,(sVar5 - sVar6) + 1);
      }
      else {
        *pool->sockbuf = '\0';
      }
      uVar7 = (uint)(pool->cgminer_pool_stats).times_received;
      iVar8 = *(int *)((int)&(pool->cgminer_pool_stats).times_received + 4);
      *(uint *)&(pool->cgminer_pool_stats).times_received = uVar7 + 1;
      *(uint *)((int)&(pool->cgminer_pool_stats).times_received + 4) =
           iVar8 + (uint)(0xfffffffe < uVar7);
      uVar7 = (uint)(pool->cgminer_pool_stats).bytes_received;
      iVar8 = *(int *)((int)&(pool->cgminer_pool_stats).bytes_received + 4);
      *(uint *)&(pool->cgminer_pool_stats).bytes_received = uVar7 + sVar6;
      *(uint *)((int)&(pool->cgminer_pool_stats).bytes_received + 4) =
           iVar8 + ((int)sVar6 >> 0x1f) + (uint)CARRY4(uVar7,sVar6);
      uVar7 = (uint)(pool->cgminer_pool_stats).net_bytes_received;
      iVar8 = *(int *)((int)&(pool->cgminer_pool_stats).net_bytes_received + 4);
      *(uint *)&(pool->cgminer_pool_stats).net_bytes_received = uVar7 + sVar6;
      *(uint *)((int)&(pool->cgminer_pool_stats).net_bytes_received + 4) =
           iVar8 + ((int)sVar6 >> 0x1f) + (uint)CARRY4(uVar7,sVar6);
    }
  }
  if (sret == (char *)0x0) {
    clear_sock(pool);
  }
  else if (((opt_protocol != false) && (opt_debug != false)) &&
          ((use_syslog != false || ((opt_log_output != false || (6 < opt_log_level)))))) {
    snprintf(tmp42,0x800,"RECVD: %s",sret);
    _applog(7,tmp42,false);
  }
  return sret;
}


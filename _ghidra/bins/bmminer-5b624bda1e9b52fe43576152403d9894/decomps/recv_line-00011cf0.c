
/* WARNING: Unknown calling convention */

char * recv_line(pool *pool)

{
  uint64_t *puVar1;
  uint64_t *puVar2;
  uint64_t *puVar3;
  undefined4 uVar4;
  _Bool _Var5;
  char *pcVar6;
  size_t sVar7;
  size_t sVar8;
  uint uVar9;
  ssize_t sVar10;
  int *piVar11;
  int iVar12;
  char *__s;
  uint uVar13;
  int iVar14;
  uint uVar15;
  int iVar16;
  size_t size;
  timeval rstart;
  timeval now;
  char tmp42_2 [2048];
  char tmp42 [2048];
  
  __s = pool->sockbuf;
  pcVar6 = strchr(__s,10);
  if (pcVar6 == (char *)0x0) {
    cgtime(&rstart);
    _Var5 = socket_full(pool,0x3c);
    uVar4 = tmp42._40_4_;
    if (!_Var5) {
      if ((opt_debug != false) &&
         (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
        builtin_strncpy(tmp42,"Timed out waiting for data on socket_full",0x2a);
        tmp42._42_2_ = SUB42(uVar4,2);
        _applog(7,tmp42,false);
      }
      goto LAB_00011e0c;
    }
    while( true ) {
      memset(tmp42,0,0x2000);
      sVar10 = recv(pool->sock,tmp42,0x1ffc,0);
      if (sVar10 == 0) break;
      cgtime(&now);
      iVar12 = (int)(longlong)
                    ((double)(longlong)(now.tv_sec - rstart.tv_sec) +
                    (double)(longlong)(now.tv_usec - rstart.tv_usec) / 1000000.0);
      if (sVar10 < 0) {
        piVar11 = __errno_location();
        if ((*piVar11 != 0xb) || (_Var5 = socket_full(pool,0x3c - iVar12), !_Var5)) {
          if ((opt_debug != false) &&
             (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
            builtin_strncpy(tmp42_2,"Failed to recv sock in recv_line",0x20);
            tmp42_2._32_2_ = tmp42_2._32_2_ & 0xff00;
            _applog(7,tmp42_2,false);
          }
          goto LAB_00011f64;
        }
      }
      else {
        sVar7 = strlen(tmp42);
        pcVar6 = pool->sockbuf;
        sVar8 = strlen(pcVar6);
        uVar9 = sVar7 + sVar8 + 1;
        if (pool->sockbuf_size <= uVar9) {
          size = (uVar9 & 0xffffe000) + 0x2000;
          pcVar6 = (char *)_cgrealloc(pcVar6,size,"util.c","recalloc_sock",0x70b);
          pool->sockbuf = pcVar6;
          memset(pcVar6 + sVar8,0,size - sVar8);
          pcVar6 = pool->sockbuf;
          pool->sockbuf_size = size;
        }
        strcat(pcVar6,tmp42);
      }
      __s = pool->sockbuf;
      if ((0x3b < iVar12) || (pcVar6 = strchr(__s,10), pcVar6 != (char *)0x0)) goto LAB_00011d12;
    }
    if ((opt_debug != false) &&
       (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
      builtin_strncpy(tmp42_2,"Socket closed waiting in recv_li",0x20);
      tmp42_2[0x20] = 'n';
      tmp42_2[0x21] = 'e';
      tmp42_2[0x22] = '\0';
      _applog(7,tmp42_2,false);
    }
LAB_00011f64:
    suspend_stratum(pool);
    __s = pool->sockbuf;
  }
LAB_00011d12:
  sVar7 = strlen(__s);
  pcVar6 = strtok(__s,"\n");
  if (pcVar6 == (char *)0x0) {
    if ((opt_debug != false) &&
       (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
      builtin_strncpy(tmp42,"Failed to parse a \\n terminated string in recv_line",0x34);
      _applog(7,tmp42,false);
    }
  }
  else {
    pcVar6 = (char *)__strdup();
    sVar8 = strlen(pcVar6);
    if ((int)(sVar8 + 1) < (int)sVar7) {
      memmove(pool->sockbuf,pool->sockbuf + sVar8 + 1,(sVar7 - sVar8) + 1);
    }
    else {
      *pool->sockbuf = '\0';
    }
    puVar1 = &(pool->cgminer_pool_stats).bytes_received;
    uVar15 = (uint)*puVar1;
    iVar16 = *(int *)((int)&(pool->cgminer_pool_stats).bytes_received + 4);
    puVar2 = &(pool->cgminer_pool_stats).net_bytes_received;
    uVar13 = (uint)*puVar2;
    iVar14 = *(int *)((int)&(pool->cgminer_pool_stats).net_bytes_received + 4);
    puVar3 = &(pool->cgminer_pool_stats).times_received;
    uVar9 = (uint)*puVar3;
    iVar12 = *(int *)((int)&(pool->cgminer_pool_stats).times_received + 4);
    *(uint *)puVar1 = uVar15 + sVar8;
    *(uint *)((int)&(pool->cgminer_pool_stats).bytes_received + 4) =
         iVar16 + ((int)sVar8 >> 0x1f) + (uint)CARRY4(uVar15,sVar8);
    *(size_t *)puVar2 = sVar8 + uVar13;
    *(uint *)((int)&(pool->cgminer_pool_stats).net_bytes_received + 4) =
         ((int)sVar8 >> 0x1f) + iVar14 + (uint)CARRY4(sVar8,uVar13);
    *(uint *)puVar3 = uVar9 + 1;
    *(uint *)((int)&(pool->cgminer_pool_stats).times_received + 4) =
         iVar12 + (uint)(0xfffffffe < uVar9);
    if (pcVar6 != (char *)0x0) {
      if (opt_protocol == false) {
        return pcVar6;
      }
      if (opt_debug == false) {
        return pcVar6;
      }
      if (((use_syslog == false) && (opt_log_output == false)) && (opt_log_level < 7)) {
        return pcVar6;
      }
      snprintf(tmp42,0x800,"RECVD: %s",pcVar6);
      _applog(7,tmp42,false);
      return pcVar6;
    }
  }
LAB_00011e0c:
  clear_sock(pool);
  return (char *)0x0;
}


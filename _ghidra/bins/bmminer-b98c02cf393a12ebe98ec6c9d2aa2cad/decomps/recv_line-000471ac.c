
char * recv_line(int param_1)

{
  char cVar1;
  char *pcVar2;
  size_t sVar3;
  size_t sVar4;
  int iVar5;
  ssize_t sVar6;
  int *piVar7;
  int iVar8;
  uint uVar9;
  char *__s;
  uint uVar10;
  int iVar11;
  timeval local_2838;
  timeval local_2830;
  char local_2828 [32];
  ushort local_2808;
  undefined1 local_2806;
  char local_2028 [40];
  undefined4 local_2000;
  char acStack_1ffc [8152];
  
  __s = *(char **)(param_1 + 0x250);
  pcVar2 = strchr(__s,10);
  if (pcVar2 == (char *)0x0) {
    gettimeofday(&local_2838,(__timezone_ptr_t)0x0);
    iVar5 = socket_full_isra_2(*(undefined4 *)(param_1 + 0x24c),0x3c);
    if (iVar5 == 0) {
      if ((opt_debug != '\0') &&
         (((use_syslog != '\0' || (opt_log_output != '\0')) || (6 < opt_log_level)))) {
        builtin_strncpy(local_2028,"Timed out waiting for data on socket_ful",0x28);
        local_2000._0_2_ = 0x6c;
        _applog(7,local_2028,0);
      }
      goto LAB_00047302;
    }
    while( true ) {
      memset(local_2028,0,0x2000);
      sVar6 = recv(*(int *)(param_1 + 0x24c),local_2028,0x1ffc,0);
      if (sVar6 == 0) break;
      gettimeofday(&local_2830,(__timezone_ptr_t)0x0);
      iVar5 = (int)(longlong)
                   ((double)(longlong)(local_2830.tv_usec - local_2838.tv_usec) / 1000000.0 +
                   (double)(longlong)(local_2830.tv_sec - local_2838.tv_sec));
      if (sVar6 < 0) {
        piVar7 = __errno_location();
        if ((*piVar7 != 0xb) ||
           (iVar8 = socket_full_isra_2(*(undefined4 *)(param_1 + 0x24c),0x3c - iVar5), iVar8 == 0))
        {
          if ((opt_debug != '\0') &&
             (((use_syslog != '\0' || (opt_log_output != '\0')) || (6 < opt_log_level)))) {
            builtin_strncpy(local_2828,"Failed to recv sock in recv_line",0x20);
            local_2808 = local_2808 & 0xff00;
            _applog(7,local_2828,0);
          }
          goto LAB_0004747e;
        }
      }
      else {
        sVar3 = strlen(local_2028);
        pcVar2 = *(char **)(param_1 + 0x250);
        sVar4 = strlen(pcVar2);
        uVar9 = sVar3 + sVar4 + 1;
        if (*(uint *)(param_1 + 0x254) <= uVar9) {
          iVar11 = (uVar9 & 0xffffe000) + 0x2000;
          iVar8 = _cgrealloc(pcVar2,iVar11,"util.c","recalloc_sock",0x70b);
          *(int *)(param_1 + 0x250) = iVar8;
          memset((void *)(iVar8 + sVar4),0,iVar11 - sVar4);
          pcVar2 = *(char **)(param_1 + 0x250);
          *(int *)(param_1 + 0x254) = iVar11;
        }
        strcat(pcVar2,local_2028);
      }
      __s = *(char **)(param_1 + 0x250);
      if ((0x3b < iVar5) || (pcVar2 = strchr(__s,10), pcVar2 != (char *)0x0)) goto LAB_000471ce;
    }
    if ((opt_debug != '\0') &&
       (((use_syslog != '\0' || (opt_log_output != '\0')) || (6 < opt_log_level)))) {
      builtin_strncpy(local_2828,"Socket closed waiting in recv_li",0x20);
      local_2808 = 0x656e;
      local_2806 = 0;
      _applog(7,local_2828,0);
    }
LAB_0004747e:
    suspend_stratum(param_1);
    __s = *(char **)(param_1 + 0x250);
  }
LAB_000471ce:
  sVar3 = strlen(__s);
  pcVar2 = strtok(__s,"\n");
  if (pcVar2 != (char *)0x0) {
    pcVar2 = (char *)__strdup();
    sVar4 = strlen(pcVar2);
    if ((int)(sVar4 + 1) < (int)sVar3) {
      memmove(*(void **)(param_1 + 0x250),(void *)(sVar4 + 1 + (int)*(void **)(param_1 + 0x250)),
              (sVar3 - sVar4) + 1);
    }
    else {
      **(undefined1 **)(param_1 + 0x250) = 0;
    }
    cVar1 = opt_protocol;
    uVar10 = *(uint *)(param_1 + 0x208);
    uVar9 = *(uint *)(param_1 + 0x210);
    *(uint *)(param_1 + 0x208) = uVar10 + 1;
    *(uint *)(param_1 + 0x20c) = *(int *)(param_1 + 0x20c) + (uint)(0xfffffffe < uVar10);
    uVar10 = *(uint *)(param_1 + 0x218);
    *(uint *)(param_1 + 0x210) = uVar9 + sVar4;
    *(uint *)(param_1 + 0x214) =
         *(int *)(param_1 + 0x214) + ((int)sVar4 >> 0x1f) + (uint)CARRY4(uVar9,sVar4);
    *(uint *)(param_1 + 0x218) = sVar4 + uVar10;
    *(uint *)(param_1 + 0x21c) =
         ((int)sVar4 >> 0x1f) + *(int *)(param_1 + 0x21c) + (uint)CARRY4(sVar4,uVar10);
    if (cVar1 == '\0') {
      return pcVar2;
    }
    if (((use_syslog == '\0') && (opt_log_output == '\0')) && (opt_log_level < 5)) {
      return pcVar2;
    }
    snprintf(local_2028,0x800,"RECVD: %s",pcVar2);
    _applog(5,local_2028,0);
    return pcVar2;
  }
  if ((opt_debug != '\0') &&
     (((use_syslog != '\0' || (opt_log_output != '\0')) || (6 < opt_log_level)))) {
    builtin_strncpy(local_2028,"Failed to parse a \\n terminated string i",0x28);
    local_2000._0_1_ = 'n';
    local_2000._1_1_ = ' ';
    local_2000._2_1_ = 'r';
    local_2000._3_1_ = 'e';
    builtin_strncpy(acStack_1ffc,"cv_line",8);
    _applog(7,local_2028,0);
  }
LAB_00047302:
  clear_sock(param_1);
  return (char *)0x0;
}



void send_result_isra_6(char *param_1,char *param_2,uint param_3,int param_4)

{
  size_t sVar1;
  int iVar2;
  size_t sVar3;
  int *piVar4;
  char *pcVar5;
  size_t sVar6;
  undefined2 *puVar7;
  uint uVar8;
  __suseconds_t *p_Var9;
  uint uVar10;
  int iVar11;
  int iVar12;
  char cVar13;
  timeval local_8b0;
  fd_set local_8a8;
  char acStack_828 [2052];
  
  if (*param_2 != '\0') {
    sVar1 = strlen(param_1);
    (param_1 + sVar1)[0] = ']';
    (param_1 + sVar1)[1] = '\0';
  }
  if (param_4 != 0) {
    sVar1 = strlen(param_1);
    builtin_strncpy(param_1 + sVar1,",\"id\":1}",9);
  }
  sVar1 = strlen(param_1);
  cVar13 = 0xfffffffe < sVar1;
  sVar6 = sVar1 + 1;
  if ((opt_debug != '\0') &&
     (((use_syslog != '\0' || (opt_log_output != '\0')) ||
      (cVar13 = 5 < opt_log_level, 6 < (int)opt_log_level)))) {
    cVar13 = 9 < sVar1;
    puVar7 = (undefined2 *)&DAT_000609ec;
    if (10 < (int)sVar1) {
      puVar7 = &DAT_00057d48;
    }
    snprintf(acStack_828,0x800,"API: send reply: (%d) \'%.10s%s\'",sVar6,param_1,puVar7);
    _applog(7,acStack_828,0);
  }
  uVar8 = param_3 & 0x1f;
  uVar10 = param_3 + 0x1f & (int)param_3 >> 0x20;
  if (cVar13 == '\0') {
    uVar10 = param_3;
  }
  if ((int)param_3 < 1) {
    uVar8 = -(-param_3 & 0x1f);
  }
  iVar11 = 0;
  iVar12 = 0;
  sVar1 = sVar6;
  do {
    while( true ) {
      if ((int)sVar1 < 1 || 4 < iVar12) {
        return;
      }
      p_Var9 = &local_8b0.tv_usec;
      local_8b0.tv_sec = 0;
      local_8b0.tv_usec = 50000;
      do {
        p_Var9 = p_Var9 + 1;
        *p_Var9 = 0;
      } while (local_8a8.fds_bits + 0x1f != p_Var9);
      local_8a8.fds_bits[(int)uVar10 >> 5] =
           local_8a8.fds_bits[(int)uVar10 >> 5] | 1 << (uVar8 & 0xff);
      iVar2 = select(param_3 + 1,(fd_set *)0x0,&local_8a8,(fd_set *)0x0,&local_8b0);
      if (iVar2 < 1) {
        if (((use_syslog == '\0') && (opt_log_output == '\0')) && ((int)opt_log_level < 4)) {
          return;
        }
        snprintf(acStack_828,0x800,"API: send select failed (%d)",iVar2);
        _applog(4,acStack_828,0);
        return;
      }
      sVar3 = send(param_3,param_1,sVar1,0);
      iVar11 = iVar11 + 1;
      if ((int)sVar3 < 0) break;
      if (iVar11 == 1) {
        if (sVar1 != sVar3) {
          if ((opt_debug != '\0') &&
             (((use_syslog != '\0' || (opt_log_output != '\0')) || (6 < (int)opt_log_level)))) {
            snprintf(acStack_828,0x800,"API: sent %d of %d first go",sVar3,sVar1);
            _applog(7,acStack_828,0);
          }
          goto LAB_00015cb0;
        }
        if ((opt_debug == '\0') ||
           (((use_syslog == '\0' && (opt_log_output == '\0')) && ((int)opt_log_level < 7))))
        goto LAB_00015d80;
        snprintf(acStack_828,0x800,"API: sent all of %d first go",sVar1);
        param_1 = param_1 + sVar3;
        _applog(7,acStack_828,0);
        sVar1 = sVar1 - sVar3;
      }
      else if (sVar1 == sVar3) {
        if ((opt_debug != '\0') &&
           (((use_syslog != '\0' || (opt_log_output != '\0')) || (6 < (int)opt_log_level)))) {
          snprintf(acStack_828,0x800,"API: sent all of remaining %d (sendc=%d)",sVar1,iVar11);
          _applog(7,acStack_828,0);
        }
LAB_00015d80:
        param_1 = param_1 + sVar3;
        sVar1 = sVar1 - sVar3;
      }
      else {
        if ((opt_debug != '\0') &&
           (((use_syslog != '\0' || (opt_log_output != '\0')) || (6 < (int)opt_log_level)))) {
          snprintf(acStack_828,0x800,"API: sent %d of remaining %d (sendc=%d)",sVar3,sVar1,iVar11);
          _applog(7,acStack_828,0);
        }
LAB_00015cb0:
        sVar1 = sVar1 - sVar3;
        param_1 = param_1 + sVar3;
        if (sVar3 == 0) goto LAB_00015cb8;
      }
    }
    piVar4 = __errno_location();
    if (*piVar4 != 0xb) {
      if (((use_syslog == '\0') && (opt_log_output == '\0')) && ((int)opt_log_level < 4)) {
        return;
      }
      pcVar5 = strerror(*piVar4);
      snprintf(acStack_828,0x800,"API: send (%d:%d) failed: %s",sVar6,sVar6 - sVar1,pcVar5);
      _applog(4,acStack_828,0);
      return;
    }
LAB_00015cb8:
    iVar12 = iVar12 + 1;
  } while( true );
}


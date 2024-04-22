
void send_result_isra_6(char *param_1,char *param_2,uint param_3,int param_4)

{
  undefined4 uVar1;
  size_t sVar2;
  int iVar3;
  size_t sVar4;
  int *piVar5;
  char *pcVar6;
  size_t sVar7;
  undefined2 *puVar8;
  uint uVar9;
  __suseconds_t *p_Var10;
  uint uVar11;
  int iVar12;
  int iVar13;
  char cVar14;
  timeval local_8b0;
  fd_set local_8a8;
  char acStack_828 [2052];
  
  if (*param_2 != '\0') {
    sVar2 = strlen(param_1);
    *(undefined2 *)(param_1 + sVar2) = s___02d__02d__02d__03d__0005e04c._20_2_;
  }
  if (param_4 != 0) {
    sVar2 = strlen(param_1);
    cVar14 = DAT_00057d18;
    uVar1 = DAT_00057d14;
    *(undefined4 *)(param_1 + sVar2) = DAT_00057d10;
    *(undefined4 *)(param_1 + sVar2 + 4) = uVar1;
    param_1[sVar2 + 8] = cVar14;
  }
  sVar2 = strlen(param_1);
  cVar14 = 0xfffffffe < sVar2;
  sVar7 = sVar2 + 1;
  if ((opt_debug != '\0') &&
     (((use_syslog != '\0' || (opt_log_output != '\0')) ||
      (cVar14 = 5 < opt_log_level, 6 < (int)opt_log_level)))) {
    cVar14 = 9 < sVar2;
    puVar8 = (undefined2 *)&DAT_000609ec;
    if (10 < (int)sVar2) {
      puVar8 = &DAT_00057d48;
    }
    snprintf(acStack_828,0x800,"API: send reply: (%d) \'%.10s%s\'",sVar7,param_1,puVar8);
    _applog(7,acStack_828,0);
  }
  uVar9 = param_3 & 0x1f;
  uVar11 = param_3 + 0x1f & (int)param_3 >> 0x20;
  if (cVar14 == '\0') {
    uVar11 = param_3;
  }
  if ((int)param_3 < 1) {
    uVar9 = -(-param_3 & 0x1f);
  }
  iVar12 = 0;
  iVar13 = 0;
  sVar2 = sVar7;
  do {
    while( true ) {
      if ((int)sVar2 < 1 || 4 < iVar13) {
        return;
      }
      p_Var10 = &local_8b0.tv_usec;
      local_8b0.tv_sec = 0;
      local_8b0.tv_usec = 50000;
      do {
        p_Var10 = p_Var10 + 1;
        *p_Var10 = 0;
      } while (local_8a8.fds_bits + 0x1f != p_Var10);
      local_8a8.fds_bits[(int)uVar11 >> 5] =
           local_8a8.fds_bits[(int)uVar11 >> 5] | 1 << (uVar9 & 0xff);
      iVar3 = select(param_3 + 1,(fd_set *)0x0,&local_8a8,(fd_set *)0x0,&local_8b0);
      if (iVar3 < 1) {
        if (((use_syslog == '\0') && (opt_log_output == '\0')) && ((int)opt_log_level < 4)) {
          return;
        }
        snprintf(acStack_828,0x800,"API: send select failed (%d)",iVar3);
        _applog(4,acStack_828,0);
        return;
      }
      sVar4 = send(param_3,param_1,sVar2,0);
      iVar12 = iVar12 + 1;
      if ((int)sVar4 < 0) break;
      if (iVar12 == 1) {
        if (sVar2 != sVar4) {
          if ((opt_debug != '\0') &&
             (((use_syslog != '\0' || (opt_log_output != '\0')) || (6 < (int)opt_log_level)))) {
            snprintf(acStack_828,0x800,"API: sent %d of %d first go",sVar4,sVar2);
            _applog(7,acStack_828,0);
          }
          goto LAB_00015cb0;
        }
        if ((opt_debug == '\0') ||
           (((use_syslog == '\0' && (opt_log_output == '\0')) && ((int)opt_log_level < 7))))
        goto LAB_00015d80;
        sVar2 = sVar2 - sVar4;
        snprintf(acStack_828,0x800,"API: sent all of %d first go");
        param_1 = param_1 + sVar4;
        _applog(7,acStack_828,0);
      }
      else if (sVar2 == sVar4) {
        if ((opt_debug != '\0') &&
           (((use_syslog != '\0' || (opt_log_output != '\0')) || (6 < (int)opt_log_level)))) {
          snprintf(acStack_828,0x800,"API: sent all of remaining %d (sendc=%d)",sVar2,iVar12);
          _applog(7,acStack_828,0);
        }
LAB_00015d80:
        sVar2 = sVar2 - sVar4;
        param_1 = param_1 + sVar4;
      }
      else {
        if ((opt_debug != '\0') &&
           (((use_syslog != '\0' || (opt_log_output != '\0')) || (6 < (int)opt_log_level)))) {
          snprintf(acStack_828,0x800,"API: sent %d of remaining %d (sendc=%d)",sVar4,sVar2,iVar12);
          _applog(7,acStack_828,0);
        }
LAB_00015cb0:
        sVar2 = sVar2 - sVar4;
        param_1 = param_1 + sVar4;
        if (sVar4 == 0) goto LAB_00015cb8;
      }
    }
    piVar5 = __errno_location();
    if (*piVar5 != 0xb) {
      if (((use_syslog == '\0') && (opt_log_output == '\0')) && ((int)opt_log_level < 4)) {
        return;
      }
      pcVar6 = strerror(*piVar5);
      snprintf(acStack_828,0x800,"API: send (%d:%d) failed: %s",sVar7,sVar7 - sVar2,pcVar6);
      _applog(4,acStack_828,0);
      return;
    }
LAB_00015cb8:
    iVar13 = iVar13 + 1;
  } while( true );
}


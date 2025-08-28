
/* WARNING: Unknown calling convention */

void send_result(io_data *io_data,long c,_Bool isjson)

{
  size_t sVar1;
  int iVar2;
  size_t sVar3;
  int *piVar4;
  size_t sVar5;
  __suseconds_t *p_Var6;
  undefined4 *puVar7;
  int iVar8;
  char *buf;
  char *pcVar9;
  uint uVar10;
  int iVar11;
  timeval timeout;
  fd_set wd;
  char tmp42 [2048];
  
  pcVar9 = io_data->ptr;
  if (io_data->close != false) {
    sVar1 = strlen(pcVar9);
    (pcVar9 + sVar1)[0] = ']';
    (pcVar9 + sVar1)[1] = '\0';
  }
  if (isjson) {
    sVar1 = strlen(pcVar9);
    builtin_strncpy(pcVar9 + sVar1,",\"id\":1}",9);
  }
  sVar1 = strlen(pcVar9);
  sVar5 = sVar1 + 1;
  if ((opt_debug != false) &&
     (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
    if ((int)sVar1 < 0xb) {
      puVar7 = (undefined4 *)&DAT_00046bb8;
    }
    else {
      puVar7 = &DAT_00047330;
    }
    snprintf(tmp42,0x800,"API: send reply: (%d) \'%.10s%s\'",sVar5,pcVar9,puVar7);
    _applog(7,tmp42,false);
  }
  uVar10 = c + 0x1fU & c >> 0x20;
  if (((uint)(c >> 0x1f) >> 0x1a & 1) == 0) {
    uVar10 = c;
  }
  iVar8 = 0;
  iVar11 = 0;
  sVar1 = sVar5;
  do {
    while( true ) {
      if (4 < iVar11 || (int)sVar1 < 1) {
        return;
      }
      p_Var6 = &timeout.tv_usec;
      timeout.tv_sec = 0;
      timeout.tv_usec = (__suseconds_t)&LAB_0000c350;
      do {
        p_Var6 = p_Var6 + 1;
        *p_Var6 = 0;
      } while (p_Var6 != wd.fds_bits + 0x1f);
      ((fd_set *)&wd)->fds_bits[(int)uVar10 >> 5] =
           1 << (c % 0x20 & 0xffU) | ((fd_set *)&wd)->fds_bits[(int)uVar10 >> 5];
      iVar2 = select(c + 1,(fd_set *)0x0,(fd_set *)&wd,(fd_set *)0x0,(timeval *)&timeout);
      if (iVar2 < 1) {
        if (((use_syslog == false) && (opt_log_output == false)) && (opt_log_level < 4)) {
          return;
        }
        snprintf(tmp42,0x800,"API: send select failed (%d)",iVar2);
        _applog(4,tmp42,false);
        return;
      }
      sVar3 = send(c,pcVar9,sVar1,0);
      iVar8 = iVar8 + 1;
      if ((int)sVar3 < 0) break;
      if (iVar8 == 1) {
        if (sVar3 != sVar1) {
          if ((opt_debug != false) &&
             (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
            snprintf(tmp42,0x800,"API: sent %d of %d first go",sVar3,sVar1);
            _applog(7,tmp42,false);
          }
          goto LAB_0001874e;
        }
        if ((opt_debug == false) ||
           (((use_syslog == false && (opt_log_output == false)) && (opt_log_level < 7))))
        goto LAB_0001881e;
        snprintf(tmp42,0x800,"API: sent all of %d first go",sVar3);
        sVar1 = sVar1 - sVar3;
        _applog(7,tmp42,false);
        pcVar9 = pcVar9 + sVar3;
      }
      else if (sVar3 == sVar1) {
        if ((opt_debug != false) &&
           (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
          snprintf(tmp42,0x800,"API: sent all of remaining %d (sendc=%d)",sVar3,iVar8);
          _applog(7,tmp42,false);
        }
LAB_0001881e:
        sVar1 = sVar1 - sVar3;
        pcVar9 = pcVar9 + sVar3;
      }
      else {
        if ((opt_debug != false) &&
           (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
          snprintf(tmp42,0x800,"API: sent %d of remaining %d (sendc=%d)",sVar3,sVar1,iVar8);
          _applog(7,tmp42,false);
        }
LAB_0001874e:
        sVar1 = sVar1 - sVar3;
        pcVar9 = pcVar9 + sVar3;
        if (sVar3 == 0) goto LAB_00018756;
      }
    }
    piVar4 = __errno_location();
    if (*piVar4 != 0xb) {
      if (((use_syslog == false) && (opt_log_output == false)) && (opt_log_level < 4)) {
        return;
      }
      pcVar9 = strerror(*piVar4);
      snprintf(tmp42,0x800,"API: send (%d:%d) failed: %s",sVar5,sVar5 - sVar1,pcVar9);
      _applog(4,tmp42,false);
      return;
    }
LAB_00018756:
    iVar11 = iVar11 + 1;
  } while( true );
}


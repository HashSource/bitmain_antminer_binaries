
/* WARNING: Unknown calling convention */

void send_result(io_data *io_data,long c,_Bool isjson)

{
  char cVar1;
  size_t sVar2;
  int len;
  int iVar3;
  int res;
  size_t sVar4;
  int n;
  int *piVar5;
  undefined4 uVar6;
  size_t sVar7;
  int tosend;
  __suseconds_t *p_Var8;
  int sendc;
  char *buf;
  char *pcVar9;
  uint uVar10;
  int count;
  timeval timeout;
  fd_set wd;
  char tmp42 [2048];
  
  pcVar9 = io_data->ptr;
  if (io_data->close != false) {
    sVar2 = strlen(pcVar9);
    *(undefined2 *)(pcVar9 + sVar2) = *DAT_00018900;
  }
  if (isjson) {
    sVar2 = strlen(pcVar9);
    uVar6 = DAT_00018904[1];
    cVar1 = *(char *)(DAT_00018904 + 2);
    *(undefined4 *)(pcVar9 + sVar2) = *DAT_00018904;
    *(undefined4 *)(pcVar9 + sVar2 + 4) = uVar6;
    pcVar9[sVar2 + 8] = cVar1;
  }
  sVar2 = strlen(pcVar9);
  sVar7 = sVar2 + 1;
  if ((opt_debug != false) &&
     (((*DAT_000188d8 != '\0' || (*DAT_000188ec != '\0')) || (6 < *DAT_000188f0)))) {
    uVar6 = DAT_000188dc;
    if (10 < (int)sVar2) {
      uVar6 = DAT_000188e0;
    }
    snprintf(tmp42,0x800,DAT_000188e4,sVar7,pcVar9,uVar6);
    _applog(7,tmp42,false);
  }
  uVar10 = c + 0x1fU & c >> 0x20;
  if (((uint)(c >> 0x1f) >> 0x1a & 1) == 0) {
    uVar10 = c;
  }
  sendc = 0;
  count = 0;
  sVar2 = sVar7;
  do {
    while( true ) {
      if (4 < count || (int)sVar2 < 1) {
        return;
      }
      p_Var8 = &timeout.tv_usec;
      timeout.tv_sec = 0;
      timeout.tv_usec = (__suseconds_t)&LAB_0000c350;
      do {
        p_Var8 = p_Var8 + 1;
        *p_Var8 = 0;
      } while (p_Var8 != wd.fds_bits + 0x1f);
      ((fd_set *)&wd)->fds_bits[(int)uVar10 >> 5] =
           1 << (c % 0x20 & 0xffU) | ((fd_set *)&wd)->fds_bits[(int)uVar10 >> 5];
      iVar3 = select(c + 1,(fd_set *)0x0,(fd_set *)&wd,(fd_set *)0x0,(timeval *)&timeout);
      if (iVar3 < 1) {
        if (((*DAT_00018950 == '\0') && (*DAT_00018954 == '\0')) && (*DAT_00018958 < 4)) {
          return;
        }
        snprintf(tmp42,0x800,DAT_0001895c,iVar3);
        _applog(4,tmp42,false);
        return;
      }
      sVar4 = send(c,pcVar9,sVar2,0);
      sendc = sendc + 1;
      if ((int)sVar4 < 0) break;
      if (sendc == 1) {
        if (sVar4 != sVar2) {
          if ((opt_debug != false) &&
             (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
            snprintf(tmp42,0x800,DAT_000188f8,sVar4,sVar2);
            _applog(7,tmp42,false);
          }
          goto LAB_0001874e;
        }
        if ((opt_debug == false) ||
           (((use_syslog == false && (opt_log_output == false)) && (opt_log_level < 7))))
        goto LAB_0001881e;
        snprintf(tmp42,0x800,DAT_00018908);
        sVar2 = sVar2 - sVar4;
        _applog(7,tmp42,false);
        pcVar9 = pcVar9 + sVar4;
      }
      else if (sVar4 == sVar2) {
        if ((opt_debug != false) &&
           (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
          snprintf(tmp42,0x800,DAT_000188fc,sVar4,sendc);
          _applog(7,tmp42,false);
        }
LAB_0001881e:
        sVar2 = sVar2 - sVar4;
        pcVar9 = pcVar9 + sVar4;
      }
      else {
        if ((opt_debug != false) &&
           (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
          snprintf(tmp42,0x800,DAT_000188e8,sVar4,sVar2,sendc);
          _applog(7,tmp42,false);
        }
LAB_0001874e:
        sVar2 = sVar2 - sVar4;
        pcVar9 = pcVar9 + sVar4;
        if (sVar4 == 0) goto LAB_00018756;
      }
    }
    piVar5 = __errno_location();
    if (*piVar5 != 0xb) {
      if (((*DAT_000188d8 == '\0') && (*DAT_000188ec == '\0')) && (*DAT_000188f0 < 4)) {
        return;
      }
      pcVar9 = strerror(*piVar5);
      snprintf(tmp42,0x800,DAT_000188f4,sVar7,sVar7 - sVar2,pcVar9);
      _applog(4,tmp42,false);
      return;
    }
LAB_00018756:
    count = count + 1;
  } while( true );
}



void send_result(io_data *io_data,long c,_Bool isjson)

{
  undefined4 uVar1;
  _Bool _Var2;
  size_t sVar3;
  int iVar4;
  ssize_t sVar5;
  int *piVar6;
  char *pcVar7;
  undefined4 *puVar8;
  long lVar9;
  _Bool isjson_local;
  long c_local;
  io_data *io_data_local;
  fd_set wd;
  char tmp42 [2048];
  timeval timeout;
  int n;
  int res;
  fd_set *__arr;
  int len;
  uint __i;
  char *buf;
  int tosend;
  int sendc;
  int count;
  
  buf = io_data->ptr;
  strcpy(buf,io_data->ptr);
  if (io_data->close != false) {
    sVar3 = strlen(buf);
    *(undefined2 *)(buf + sVar3) = DAT_0006d2d4;
  }
  if (isjson) {
    sVar3 = strlen(buf);
    uVar1 = DAT_0006dd28;
    puVar8 = (undefined4 *)(buf + sVar3);
    *puVar8 = DAT_0006dd24;
    puVar8[1] = uVar1;
    *(undefined *)(puVar8 + 2) = DAT_0006dd2c;
  }
  len = strlen(buf);
  tosend = len + 1;
  if ((opt_debug != false) &&
     (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
    pcVar7 = BLANK;
    if (10 < len) {
      pcVar7 = "...";
    }
    snprintf(tmp42,0x800,"API: send reply: (%d) \'%.10s%s\'",tosend,buf,pcVar7);
    _applog(7,tmp42,false);
  }
  sendc = 0;
  count = 0;
  while( true ) {
    if (4 < count) {
      return;
    }
    if (tosend < 1) break;
    timeout.tv_sec = 0;
    timeout.tv_usec = 50000;
    for (__i = 0; __i < 0x20; __i = __i + 1) {
      wd.fds_bits[__i] = 0;
    }
    lVar9 = c;
    if (c < 0) {
      lVar9 = c + 0x1f;
    }
    wd.fds_bits[lVar9 >> 5] = wd.fds_bits[lVar9 >> 5] | 1 << (c % 0x20 & 0xffU);
    iVar4 = select(c + 1,(fd_set *)0x0,(fd_set *)&wd,(fd_set *)0x0,(timeval *)&timeout);
    if (iVar4 < 1) {
      if (((use_syslog == false) && (opt_log_output == false)) && (opt_log_level < 4)) {
        return;
      }
      snprintf(tmp42,0x800,"API: send select failed (%d)",iVar4);
      _applog(4,tmp42,false);
      return;
    }
    sVar5 = send(c,buf,tosend,0);
    sendc = sendc + 1;
    if (sVar5 < 0) {
      count = count + 1;
      _Var2 = sock_blocks();
      if (!_Var2) {
        if (((use_syslog != false) || (opt_log_output != false)) || (3 < opt_log_level)) {
          piVar6 = __errno_location();
          pcVar7 = strerror(*piVar6);
          snprintf(tmp42,0x800,"API: send (%d:%d) failed: %s",len + 1,(len + 1) - tosend,pcVar7);
          _applog(4,tmp42,false);
        }
        return;
      }
    }
    else {
      if (sendc < 2) {
        if (sVar5 == tosend) {
          if ((opt_debug != false) &&
             (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
            snprintf(tmp42,0x800,"API: sent all of %d first go",tosend);
            _applog(7,tmp42,false);
          }
        }
        else if ((opt_debug != false) &&
                (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
          snprintf(tmp42,0x800,"API: sent %d of %d first go",sVar5,tosend);
          _applog(7,tmp42,false);
        }
      }
      else if (sVar5 == tosend) {
        if ((opt_debug != false) &&
           (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
          snprintf(tmp42,0x800,"API: sent all of remaining %d (sendc=%d)",tosend,sendc);
          _applog(7,tmp42,false);
        }
      }
      else if ((opt_debug != false) &&
              (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
        snprintf(tmp42,0x800,"API: sent %d of remaining %d (sendc=%d)",sVar5,tosend,sendc);
        _applog(7,tmp42,false);
      }
      tosend = tosend - sVar5;
      buf = buf + sVar5;
      if (sVar5 == 0) {
        count = count + 1;
      }
    }
  }
  return;
}


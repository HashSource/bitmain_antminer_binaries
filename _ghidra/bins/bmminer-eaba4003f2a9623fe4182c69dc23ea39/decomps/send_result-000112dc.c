
void send_result(io_data *io_data,long c,_Bool isjson)

{
  _Bool _Var1;
  size_t sVar2;
  int iVar3;
  ssize_t sVar4;
  int *piVar5;
  char *pcVar6;
  long lVar7;
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
    sVar2 = strlen(buf);
    (buf + sVar2)[0] = ']';
    (buf + sVar2)[1] = '\0';
  }
  if (isjson) {
    sVar2 = strlen(buf);
    builtin_strncpy(buf + sVar2,",\"id\":1}",9);
  }
  sVar2 = strlen(buf);
  tosend = sVar2 + 1;
  if ((opt_debug != false) &&
     (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
    pcVar6 = BLANK;
    if (10 < (int)sVar2) {
      pcVar6 = "...";
    }
    snprintf(tmp42,0x800,"API: send reply: (%d) \'%.10s%s\'",tosend,buf,pcVar6);
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
    lVar7 = c;
    if (c < 0) {
      lVar7 = c + 0x1f;
    }
    wd.fds_bits[lVar7 >> 5] = wd.fds_bits[lVar7 >> 5] | 1 << (c % 0x20 & 0xffU);
    iVar3 = select(c + 1,(fd_set *)0x0,(fd_set *)&wd,(fd_set *)0x0,(timeval *)&timeout);
    if (iVar3 < 1) {
      if (((use_syslog == false) && (opt_log_output == false)) && (opt_log_level < 4)) {
        return;
      }
      snprintf(tmp42,0x800,"API: send select failed (%d)",iVar3);
      _applog(4,tmp42,false);
      return;
    }
    sVar4 = send(c,buf,tosend,0);
    sendc = sendc + 1;
    if (sVar4 < 0) {
      count = count + 1;
      _Var1 = sock_blocks();
      if (!_Var1) {
        if (((use_syslog != false) || (opt_log_output != false)) || (3 < opt_log_level)) {
          piVar5 = __errno_location();
          pcVar6 = strerror(*piVar5);
          snprintf(tmp42,0x800,"API: send (%d:%d) failed: %s",sVar2 + 1,(sVar2 + 1) - tosend,pcVar6)
          ;
          _applog(4,tmp42,false);
        }
        return;
      }
    }
    else {
      if (sendc < 2) {
        if (sVar4 == tosend) {
          if ((opt_debug != false) &&
             (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
            snprintf(tmp42,0x800,"API: sent all of %d first go",tosend);
            _applog(7,tmp42,false);
          }
        }
        else if ((opt_debug != false) &&
                (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
          snprintf(tmp42,0x800,"API: sent %d of %d first go",sVar4,tosend);
          _applog(7,tmp42,false);
        }
      }
      else if (sVar4 == tosend) {
        if ((opt_debug != false) &&
           (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
          snprintf(tmp42,0x800,"API: sent all of remaining %d (sendc=%d)",tosend,sendc);
          _applog(7,tmp42,false);
        }
      }
      else if ((opt_debug != false) &&
              (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
        snprintf(tmp42,0x800,"API: sent %d of remaining %d (sendc=%d)",sVar4,tosend,sendc);
        _applog(7,tmp42,false);
      }
      tosend = tosend - sVar4;
      buf = buf + sVar4;
      if (sVar4 == 0) {
        count = count + 1;
      }
    }
  }
  return;
}


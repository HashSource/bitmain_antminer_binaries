
void send_result(io_data *io_data,long c,_Bool isjson)

{
  _Bool _Var1;
  size_t sVar2;
  ssize_t sVar3;
  int *piVar4;
  char *pcVar5;
  int iVar6;
  uint uVar7;
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
    pcVar5 = BLANK;
    if (10 < (int)sVar2) {
      pcVar5 = "...";
    }
    snprintf(tmp42,0x800,"API: send reply: (%d) \'%.10s%s\'",tosend,buf,pcVar5);
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
    iVar6 = c + 0x1f;
    if (-1 < c) {
      iVar6 = c;
    }
    uVar7 = c & 0x1f;
    if (c < 1) {
      uVar7 = -(-c & 0x1fU);
    }
    wd.fds_bits[iVar6 >> 5] = wd.fds_bits[iVar6 >> 5] | 1 << (uVar7 & 0xff);
    iVar6 = select(c + 1,(fd_set *)0x0,(fd_set *)&wd,(fd_set *)0x0,(timeval *)&timeout);
    if (iVar6 < 1) {
      if (((use_syslog == false) && (opt_log_output == false)) && (opt_log_level < 4)) {
        return;
      }
      snprintf(tmp42,0x800,"API: send select failed (%d)",iVar6);
      _applog(4,tmp42,false);
      return;
    }
    sVar3 = send(c,buf,tosend,0);
    sendc = sendc + 1;
    if (sVar3 < 0) {
      count = count + 1;
      _Var1 = sock_blocks();
      if (!_Var1) {
        if (((use_syslog != false) || (opt_log_output != false)) || (3 < opt_log_level)) {
          piVar4 = __errno_location();
          pcVar5 = strerror(*piVar4);
          snprintf(tmp42,0x800,"API: send (%d:%d) failed: %s",sVar2 + 1,(sVar2 + 1) - tosend,pcVar5)
          ;
          _applog(4,tmp42,false);
        }
        return;
      }
    }
    else {
      if (sendc < 2) {
        if (sVar3 == tosend) {
          if ((opt_debug != false) &&
             (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
            snprintf(tmp42,0x800,"API: sent all of %d first go",tosend);
            _applog(7,tmp42,false);
          }
        }
        else if ((opt_debug != false) &&
                (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
          snprintf(tmp42,0x800,"API: sent %d of %d first go",sVar3,tosend);
          _applog(7,tmp42,false);
        }
      }
      else if (sVar3 == tosend) {
        if ((opt_debug != false) &&
           (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
          snprintf(tmp42,0x800,"API: sent all of remaining %d (sendc=%d)",tosend,sendc);
          _applog(7,tmp42,false);
        }
      }
      else if ((opt_debug != false) &&
              (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
        snprintf(tmp42,0x800,"API: sent %d of remaining %d (sendc=%d)",sVar3,tosend,sendc);
        _applog(7,tmp42,false);
      }
      tosend = tosend - sVar3;
      buf = buf + sVar3;
      if (sVar3 == 0) {
        count = count + 1;
      }
    }
  }
  return;
}


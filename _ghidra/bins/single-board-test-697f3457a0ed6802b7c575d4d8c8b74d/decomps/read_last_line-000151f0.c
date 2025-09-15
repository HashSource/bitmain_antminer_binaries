
int read_last_line(char *buf,size_t len,int block)

{
  ssize_t sVar1;
  int *piVar2;
  char *pcVar3;
  void *pvVar4;
  int block_local;
  size_t len_local;
  char *buf_local;
  char tmp42 [1024];
  char *start;
  ssize_t n;
  size_t pos;
  
  pos = 0;
  set_blocking_mode(0,block);
LAB_00015218:
  sVar1 = read(0,buf + pos,len - pos);
  if (sVar1 == -1) {
    piVar2 = __errno_location();
    if (*piVar2 == 4) goto LAB_00015218;
  }
  if ((sVar1 == -1) &&
     ((piVar2 = __errno_location(), *piVar2 == 0xb || (piVar2 = __errno_location(), *piVar2 == 0xb))
     )) {
    if (pos == 0) {
      return 0;
    }
    if (((use_syslog != false) || (opt_log_output != false)) || (0 < opt_log_level)) {
      piVar2 = __errno_location();
      pcVar3 = strerror(*piVar2);
      snprintf(tmp42,0x400,"strange: a partial line was read %s\n",pcVar3);
      _applog(1,tmp42,false);
    }
    set_blocking_mode(0,1);
  }
  else {
    if (sVar1 == -1) {
      if (((use_syslog != false) || (opt_log_output != false)) || (-1 < opt_log_level)) {
        piVar2 = __errno_location();
        pcVar3 = strerror(*piVar2);
        snprintf(tmp42,0x400,"read stdin: %s\n",pcVar3);
        _applog(0,tmp42,false);
      }
    }
    else if ((sVar1 == 0) &&
            (((use_syslog != false || (opt_log_output != false)) || (-1 < opt_log_level)))) {
      snprintf(tmp42,0x400,"%s EOF on stdin\n","read_last_line");
      _applog(0,tmp42,false);
    }
    pos = sVar1 + pos;
    if (buf[pos - 1] == '\n') {
      pvVar4 = memrchr(buf,10,pos - 1);
      if (pvVar4 != (void *)0x0) {
        if (((use_syslog != false) || (opt_log_output != false)) || (0 < opt_log_level)) {
          snprintf(tmp42,0x400,"%s strange: more than 1 line was read\n","read_last_line");
          _applog(1,tmp42,false);
        }
        pos = pos - ((int)pvVar4 + (1 - (int)buf));
        memmove(buf,(void *)((int)pvVar4 + 1),pos);
      }
      buf[pos - 1] = '\0';
      return 1;
    }
  }
  goto LAB_00015218;
}


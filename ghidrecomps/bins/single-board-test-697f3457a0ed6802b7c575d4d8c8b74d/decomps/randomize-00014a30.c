
void randomize(void *p,int l)

{
  int iVar1;
  int *piVar2;
  char *pcVar3;
  ssize_t sVar4;
  int l_local;
  void *p_local;
  char tmp42 [1024];
  int ret;
  int fd;
  char *fname;
  
  iVar1 = open("/dev/urandom",0);
  if (iVar1 == -1) {
    if (((use_syslog != false) || (opt_log_output != false)) || (-1 < opt_log_level)) {
      piVar2 = __errno_location();
      pcVar3 = strerror(*piVar2);
      snprintf(tmp42,0x400,"open %s: %s\n","/dev/urandom",pcVar3);
      _applog(0,tmp42,false);
    }
                    /* WARNING: Subroutine does not return */
    exit(1);
  }
  sVar4 = read(iVar1,p,l);
  if (sVar4 == -1) {
    if (((use_syslog != false) || (opt_log_output != false)) || (-1 < opt_log_level)) {
      piVar2 = __errno_location();
      pcVar3 = strerror(*piVar2);
      snprintf(tmp42,0x400,"read %s: %s\n","/dev/urandom",pcVar3);
      _applog(0,tmp42,false);
    }
                    /* WARNING: Subroutine does not return */
    exit(1);
  }
  if (sVar4 != l) {
    if (((use_syslog != false) || (opt_log_output != false)) || (-1 < opt_log_level)) {
      snprintf(tmp42,0x400,"%s: short read %d bytes out of %d\n","/dev/urandom",sVar4,l);
      _applog(0,tmp42,false);
    }
                    /* WARNING: Subroutine does not return */
    exit(1);
  }
  iVar1 = close(iVar1);
  if (iVar1 == -1) {
    if (((use_syslog != false) || (opt_log_output != false)) || (-1 < opt_log_level)) {
      piVar2 = __errno_location();
      pcVar3 = strerror(*piVar2);
      snprintf(tmp42,0x400,"close %s: %s\n","/dev/urandom",pcVar3);
      _applog(0,tmp42,false);
    }
                    /* WARNING: Subroutine does not return */
    exit(1);
  }
  return;
}


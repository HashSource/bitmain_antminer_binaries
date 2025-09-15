
void set_blocking_mode(int fd,int block)

{
  uint uVar1;
  int *piVar2;
  char *pcVar3;
  int iVar4;
  int block_local;
  int fd_local;
  char tmp42 [1024];
  int f;
  
  uVar1 = fcntl(fd,3);
  if (uVar1 == 0xffffffff) {
    if (((use_syslog != false) || (opt_log_output != false)) || (-1 < opt_log_level)) {
      piVar2 = __errno_location();
      pcVar3 = strerror(*piVar2);
      snprintf(tmp42,0x400,"fcntl F_GETFL: %s\n",pcVar3);
      _applog(0,tmp42,false);
    }
                    /* WARNING: Subroutine does not return */
    exit(1);
  }
  if (block == 0) {
    uVar1 = uVar1 | 0x800;
  }
  else {
    uVar1 = uVar1 & 0xfffff7ff;
  }
  iVar4 = fcntl(fd,4,uVar1);
  if (iVar4 == -1) {
    if (((use_syslog != false) || (opt_log_output != false)) || (-1 < opt_log_level)) {
      piVar2 = __errno_location();
      pcVar3 = strerror(*piVar2);
      snprintf(tmp42,0x400,"fcntl F_SETFL: %s\n",pcVar3);
      _applog(0,tmp42,false);
    }
                    /* WARNING: Subroutine does not return */
    exit(1);
  }
  return;
}


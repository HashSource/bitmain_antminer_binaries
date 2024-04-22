
ssize_t read_key(uchar value)

{
  ssize_t sVar1;
  ssize_t sVar2;
  uchar value_local;
  char tmp42 [1024];
  ssize_t ret_len;
  
  value_local = value;
  lseek(cgpu.key_fd,0,0);
  sVar1 = read(cgpu.key_fd,&value_local,1);
  if (sVar1 == 1) {
    sVar2 = 1;
  }
  else {
    if (((use_syslog != false) || (opt_log_output != false)) || (1 < opt_log_level)) {
      snprintf(tmp42,0x400,"%s: can\'t read out key value\n","read_key");
      _applog(2,tmp42,false);
    }
    sVar2 = -1;
  }
  return sVar2;
}


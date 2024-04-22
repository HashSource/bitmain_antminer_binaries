
undefined4 read_key(undefined param_1)

{
  undefined4 uVar1;
  undefined local_411 [5];
  char acStack_40c [1024];
  ssize_t local_c;
  
  local_c = 0;
  local_411[0] = param_1;
  lseek(cgpu._44_4_,0,0);
  local_c = read(cgpu._44_4_,local_411,1);
  if (local_c == 1) {
    uVar1 = 1;
  }
  else {
    if (((use_syslog != '\0') || (opt_log_output != '\0')) || (1 < opt_log_level)) {
      snprintf(acStack_40c,0x400,"%s: can\'t read out key value\n","read_key");
      _applog(2,acStack_40c,0);
    }
    uVar1 = 0xffffffff;
  }
  return uVar1;
}


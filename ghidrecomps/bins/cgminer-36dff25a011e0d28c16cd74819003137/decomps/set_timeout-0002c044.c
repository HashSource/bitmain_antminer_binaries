
void set_timeout(int final_freq,int percent)

{
  int iVar1;
  FILE *__stream;
  int percent_local;
  int final_freq_local;
  FILE *pFile;
  
  iVar1 = calculate_core_number(dev->corenum);
  iVar1 = __aeabi_idiv(0x1000000,iVar1);
  iVar1 = __aeabi_idiv((uint)dev->addrInterval * iVar1,final_freq);
  dev->timeout = (percent * iVar1) / 100;
  if (3 < log_level) {
    print_crt_time_to_file(log_file,3);
    __stream = fopen(log_file,"a+");
    if (__stream != (FILE *)0x0) {
      fprintf(__stream,"%s:%d:%s: freq %d final timeout=%d\n","driver-btm-soc.c",0x1756,
              "set_timeout",final_freq,dev->timeout);
    }
    fclose(__stream);
  }
  if (opt_multi_version == 0) {
    set_time_out_control(dev->timeout & 0x1ffff | 0x80000000);
  }
  else {
    set_time_out_control(opt_multi_version * dev->timeout & 0x1ffff | 0x80000000);
  }
  return;
}


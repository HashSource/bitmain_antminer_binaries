
/* WARNING: Unknown calling convention */

int check_fan_num(void)

{
  int iVar1;
  FILE *__stream;
  bool bVar2;
  FILE *pFile;
  int ret;
  int retry_times;
  
  retry_times = 3;
  do {
    set_PWM('d');
    iVar1 = check_fan();
    if (1 < iVar1) {
      return 0;
    }
    sleep(1);
    bVar2 = retry_times != 0;
    retry_times = retry_times + -1;
  } while (bVar2);
  freq_scan_error_code_set(10,0);
  if (3 < log_level) {
    print_crt_time_to_file(log_file,3);
    __stream = fopen(log_file,"a+");
    if (__stream != (FILE *)0x0) {
      fprintf(__stream,"%s:%d:%s: FETAL ERROR! %d Fan detected!\n","driver-btm-soc.c",0x18c7,
              "check_fan_num",iVar1);
    }
    fclose(__stream);
  }
  return -1;
}


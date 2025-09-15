
/* WARNING: Unknown calling convention */

int get_reopen_pwm(void)

{
  FILE *pFVar1;
  FILE *pFile_1;
  FILE *pFile_4;
  FILE *pFile_3;
  FILE *pFile_2;
  FILE *pFile;
  int pwm;
  
  if (3 < log_level) {
    print_crt_time_to_file(log_file,3);
    pFVar1 = fopen(log_file,"a+");
    if (pFVar1 != (FILE *)0x0) {
      fprintf(pFVar1,"%s:%d:%s: lowest pcb temp: %d\n","driver-btm-soc.c",0xc9f,"get_reopen_pwm",
              last_testpatten_lowest_pcb_temp);
    }
    fclose(pFVar1);
  }
  if (last_testpatten_lowest_pcb_temp < 0x1b) {
    pwm = 0;
    if (3 < log_level) {
      print_crt_time_to_file(log_file,3);
      pFVar1 = fopen(log_file,"a+");
      if (pFVar1 != (FILE *)0x0) {
        fprintf(pFVar1,"%s:%d:%s: reopen pwm = %d\n","driver-btm-soc.c",0xca3,"get_reopen_pwm",0);
      }
      fclose(pFVar1);
    }
  }
  else if ((last_testpatten_lowest_pcb_temp < 0x1b) || (0x1e < last_testpatten_lowest_pcb_temp)) {
    if ((last_testpatten_lowest_pcb_temp < 0x1f) || (0x22 < last_testpatten_lowest_pcb_temp)) {
      if (3 < log_level) {
        print_crt_time_to_file(log_file,3);
        pFVar1 = fopen(log_file,"a+");
        if (pFVar1 != (FILE *)0x0) {
          fprintf(pFVar1,"%s:%d:%s: reopen pwm = %d\n","driver-btm-soc.c",0xcb5,"get_reopen_pwm",100
                 );
        }
        fclose(pFVar1);
      }
      pwm = 100;
    }
    else {
      if (3 < log_level) {
        print_crt_time_to_file(log_file,3);
        pFVar1 = fopen(log_file,"a+");
        if (pFVar1 != (FILE *)0x0) {
          fprintf(pFVar1,"%s:%d:%s: reopen pwm = %d\n","driver-btm-soc.c",0xcaf,"get_reopen_pwm",
                  0x50);
        }
        fclose(pFVar1);
      }
      pwm = 0x50;
    }
  }
  else {
    if (3 < log_level) {
      print_crt_time_to_file(log_file,3);
      pFVar1 = fopen(log_file,"a+");
      if (pFVar1 != (FILE *)0x0) {
        fprintf(pFVar1,"%s:%d:%s: reopen pwm = %d\n","driver-btm-soc.c",0xca9,"get_reopen_pwm",0x1e)
        ;
      }
      fclose(pFVar1);
    }
    pwm = 0x1e;
  }
  return pwm;
}


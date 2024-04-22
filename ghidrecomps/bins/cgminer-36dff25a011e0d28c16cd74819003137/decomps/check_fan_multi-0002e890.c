
/* WARNING: Unknown calling convention */

void check_fan_multi(void)

{
  _Bool _Var1;
  FILE *pFVar2;
  FILE *pFile_1;
  _Bool testRet;
  FILE *pFile;
  int testCounter;
  
  if (3 < log_level) {
    print_crt_time_to_file(log_file,3);
    pFVar2 = fopen(log_file,"a+");
    if (pFVar2 != (FILE *)0x0) {
      fprintf(pFVar2,"%s:%d:%s: check fan for 20 times...\n","driver-btm-soc.c",0x1b2e,
              "check_fan_multi");
    }
    fclose(pFVar2);
  }
  testCounter = 0;
  do {
    _Var1 = check_fan();
    if (_Var1) {
      if (1 < dev->fan_num) {
        return;
      }
      if (1 < log_level) {
        print_crt_time_to_file(log_file,1);
        pFVar2 = fopen(log_file,"a+");
        if (pFVar2 != (FILE *)0x0) {
          fprintf(pFVar2,"%s:%d:%s: Error!!! Fan lost!\n","driver-btm-soc.c",0x1b39,
                  "check_fan_multi");
        }
        fclose(pFVar2);
      }
    }
    if (testCounter == 0x13) {
      stop_scan(FAN_NUM_ERR,'\0');
    }
    testCounter = testCounter + 1;
    sleep(1);
  } while( true );
}


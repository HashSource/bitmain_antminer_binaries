
void processTEST(void)

{
  int iVar1;
  FILE *pFVar2;
  undefined4 uVar3;
  
  iVar1 = readTestID();
  if (iVar1 == 1) {
    saveTestID(0);
    if (3 < log_level) {
      pFVar2 = fopen(log_file,"a+");
      if (pFVar2 != (FILE *)0x0) {
        fprintf(pFVar2,"%s:%d: get TEST ID=%d getAsicNumTest \n","main.c",0x3331,1);
      }
      fclose(pFVar2);
    }
    test_show_register = 1;
    reset_crc_count(1);
    getAsicNumTest(1);
    if (3 < log_level) {
      pFVar2 = fopen(log_file,"a+");
      if (pFVar2 != (FILE *)0x0) {
        uVar3 = get_crc_count();
        fprintf(pFVar2,"%s:%d: TEST asicnum CRC error counter=%d\n","main.c",0x3338,uVar3);
      }
      fclose(pFVar2);
    }
    test_show_register = 0;
    reset_crc_count(0);
  }
  else if (iVar1 == 2) {
    saveTestID(0);
    if (3 < log_level) {
      pFVar2 = fopen(log_file,"a+");
      if (pFVar2 != (FILE *)0x0) {
        fprintf(pFVar2,"%s:%d: get TEST ID=%d getAsicNumTest Without Reset \n","main.c",0x3341,2);
      }
      fclose(pFVar2);
    }
    test_show_register = 1;
    reset_crc_count(1);
    getAsicNumTest(0);
    if (3 < log_level) {
      pFVar2 = fopen(log_file,"a+");
      if (pFVar2 != (FILE *)0x0) {
        uVar3 = get_crc_count();
        fprintf(pFVar2,"%s:%d: TEST asicnum CRC error counter=%d\n","main.c",0x3348,uVar3);
      }
      fclose(pFVar2);
    }
    test_show_register = 0;
    reset_crc_count(0);
  }
  return;
}


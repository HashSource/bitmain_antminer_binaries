
uint slowly_downgrade_voltage(undefined4 param_1,int param_2)

{
  pthread_mutex_t *__mutex;
  int iVar1;
  FILE *pFVar2;
  uint uVar3;
  
  iVar1 = write_EEPROM_iic(1,1,0x90,param_1,0);
  iVar1 = (int)(longlong)
               (((DAT_000380e8 / ((double)(longlong)iVar1 + DAT_000380e0) + DAT_000380f0) *
                DAT_000380f8) / 4.75);
  uVar3 = iVar1 * 0x66666667;
  iVar1 = (iVar1 / 10) * 10;
  if (3 < log_level) {
    pFVar2 = fopen(log_file,(char *)&DAT_0005e760);
    if (pFVar2 != (FILE *)0x0) {
      fprintf(pFVar2,"%s:%d:%s: chain[%d] current_voltage_value = %d\n","driver-btm-c5.c",0x2ef5,
              DAT_00038100,param_1,iVar1);
    }
    uVar3 = fclose(pFVar2);
    if (3 < log_level) {
      pFVar2 = fopen(log_file,(char *)&DAT_0005e760);
      if (pFVar2 != (FILE *)0x0) {
        fprintf(pFVar2,"%s:%d:%s: chain[%d] target_voltage_value = %d\n","driver-btm-c5.c",0x2ef6,
                DAT_00038100,param_1,param_2);
      }
      uVar3 = fclose(pFVar2);
    }
  }
  __mutex = DAT_00038104;
  if (param_2 - 500U < 0x2bd) {
    while (iVar1 = iVar1 + -10, param_2 <= iVar1) {
      while( true ) {
        pthread_mutex_lock(__mutex);
        pthread_mutex_unlock(__mutex);
        if (log_level < 4) break;
        pFVar2 = fopen(log_file,(char *)&DAT_0005e760);
        if (pFVar2 != (FILE *)0x0) {
          fprintf(pFVar2,"%s:%d:%s: chain[%d] set voltage to %d\n","driver-btm-c5.c",0x2f07,
                  DAT_00038100,param_1,iVar1);
        }
        iVar1 = iVar1 + -10;
        fclose(pFVar2);
        uVar3 = sleep(3);
        if (iVar1 < param_2) goto LAB_00037fba;
      }
      uVar3 = sleep(3);
    }
LAB_00037fba:
    if (log_level < 2) {
      return uVar3;
    }
    pFVar2 = fopen(log_file,(char *)&DAT_0005e760);
    if (pFVar2 != (FILE *)0x0) {
      fprintf(pFVar2,"%s:%d:%s: chain[%d] set working voltage to %d\n","driver-btm-c5.c",0x2f11,
              DAT_00038100,param_1,param_2);
    }
  }
  else {
    if (log_level < 2) {
      return uVar3;
    }
    pFVar2 = fopen(log_file,(char *)&DAT_0005e760);
    if (pFVar2 != (FILE *)0x0) {
      fprintf(pFVar2,"%s:%d:%s: target voltage invalid\n","driver-btm-c5.c",0x2efa,DAT_00038100);
    }
  }
  uVar3 = (*(code *)PTR_fclose_0007cfe8)(pFVar2);
  return uVar3;
}


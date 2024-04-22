
undefined8 get_min_voltage(void)

{
  double dVar1;
  FILE *pFVar2;
  double dVar3;
  undefined4 local_28;
  undefined4 uStack_24;
  int local_1c;
  undefined4 local_18;
  undefined4 uStack_14;
  
  local_18 = 0;
  uStack_14 = 0x40340000;
  for (local_1c = 0; local_1c < total_exist_chain_num; local_1c = local_1c + 1) {
    pthread_mutex_lock((pthread_mutex_t *)iic_mutex);
    dVar3 = (double)dsPIC33EP16GS202_pic_get_an_voltage2
                              (*(uint *)(exist_chain + local_1c * 4) & 0xff);
    pthread_mutex_unlock((pthread_mutex_t *)iic_mutex);
    local_28 = SUB84(dVar3,0);
    uStack_24 = (undefined4)((ulonglong)dVar3 >> 0x20);
    if (3 < log_level) {
      pFVar2 = fopen(log_file,"a+");
      if (pFVar2 != (FILE *)0x0) {
        fprintf(pFVar2,"%s:%d: board[%d] voltage: %f\n","power.c",0x24c,
                *(undefined4 *)(exist_chain + local_1c * 4));
      }
      fclose(pFVar2);
    }
    dVar1 = (double)CONCAT44(uStack_14,local_18);
    if (dVar1 != dVar3 && dVar1 < dVar3 == (NAN(dVar1) || NAN(dVar3))) {
      local_18 = local_28;
      uStack_14 = uStack_24;
    }
  }
  if (3 < log_level) {
    pFVar2 = fopen(log_file,"a+");
    if (pFVar2 != (FILE *)0x0) {
      fprintf(pFVar2,"%s:%d: min voltage: %f\n","power.c",0x252,local_18,uStack_14);
    }
    fclose(pFVar2);
  }
  return CONCAT44(uStack_14,local_18);
}



undefined4 get_min_voltage(void)

{
  FILE *pFVar1;
  undefined4 uVar2;
  undefined4 extraout_s1;
  int local_1c;
  undefined4 local_18;
  undefined4 uStack_14;
  
  local_18 = 0;
  uStack_14 = 0x40340000;
  for (local_1c = 0; local_1c < total_exist_chain_num; local_1c = local_1c + 1) {
    pthread_mutex_lock((pthread_mutex_t *)iic_mutex);
    uVar2 = dsPIC33EP16GS202_pic_get_an_voltage2(*(uint *)(exist_chain + local_1c * 4) & 0xff);
    pthread_mutex_unlock((pthread_mutex_t *)iic_mutex);
    if (3 < log_level) {
      pFVar1 = fopen(log_file,"a+");
      if (pFVar1 != (FILE *)0x0) {
        fprintf(pFVar1,"%s:%d: board[%d] voltage: %f\n","power.c",0x24c,
                *(undefined4 *)(exist_chain + local_1c * 4));
      }
      fclose(pFVar1);
    }
    if ((double)CONCAT44(extraout_s1,uVar2) < (double)CONCAT44(uStack_14,local_18)) {
      local_18 = uVar2;
      uStack_14 = extraout_s1;
    }
  }
  if (3 < log_level) {
    pFVar1 = fopen(log_file,"a+");
    if (pFVar1 != (FILE *)0x0) {
      fprintf(pFVar1,"%s:%d: min voltage: %f\n","power.c",0x252,local_18,uStack_14);
    }
    fclose(pFVar1);
  }
  return local_18;
}


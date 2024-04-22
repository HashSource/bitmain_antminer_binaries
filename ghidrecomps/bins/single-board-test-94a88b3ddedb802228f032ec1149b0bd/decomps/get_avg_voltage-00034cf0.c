
double get_avg_voltage(void)

{
  FILE *pFVar1;
  double dVar2;
  undefined4 local_38;
  undefined4 uStack_34;
  int local_1c;
  double local_18;
  
  local_18 = 0.0;
  for (local_1c = 0; local_1c < total_exist_chain_num; local_1c = local_1c + 1) {
    pthread_mutex_lock((pthread_mutex_t *)iic_mutex);
    dVar2 = (double)dsPIC33EP16GS202_pic_get_an_voltage2
                              (*(uint *)(exist_chain + local_1c * 4) & 0xff);
    pthread_mutex_unlock((pthread_mutex_t *)iic_mutex);
    if (3 < log_level) {
      pFVar1 = fopen(log_file,"a+");
      if (pFVar1 != (FILE *)0x0) {
        fprintf(pFVar1,"%s:%d: board[%d] voltage: %f\n","power.c",0x236,
                *(undefined4 *)(exist_chain + local_1c * 4));
      }
      fclose(pFVar1);
    }
    local_18 = local_18 + dVar2;
  }
  local_18 = local_18 / (double)(longlong)total_exist_chain_num;
  if (3 < log_level) {
    pFVar1 = fopen(log_file,"a+");
    if (pFVar1 != (FILE *)0x0) {
      local_38 = SUB84(local_18,0);
      uStack_34 = (undefined4)((ulonglong)local_18 >> 0x20);
      fprintf(pFVar1,"%s:%d: avg voltage: %f\n","power.c",0x23c,local_38,uStack_34);
    }
    fclose(pFVar1);
  }
  return local_18;
}


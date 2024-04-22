
void power_check_protocal_type(void)

{
  byte bVar1;
  FILE *pFVar2;
  int local_c;
  
  pthread_mutex_lock((pthread_mutex_t *)iic_mutex);
  local_c = 0;
  do {
    bVar1 = znyq_set_iic(power_iic_addr,power_iic_no,1,1,0,0);
    usleep(200000);
    if (bVar1 == 0xf5) break;
    local_c = local_c + 1;
  } while (local_c < 10);
  if (bVar1 == 0xf5) {
    if (3 < log_level) {
      pFVar2 = fopen(log_file,"a+");
      if (pFVar2 != (FILE *)0x0) {
        fprintf(pFVar2,"%s:%d: power protocal %02x, using package cmd\n","power.c",0x95,0xf5);
      }
      fclose(pFVar2);
    }
    power_protocal_type = 2;
  }
  else {
    if (3 < log_level) {
      pFVar2 = fopen(log_file,"a+");
      if (pFVar2 != (FILE *)0x0) {
        fprintf(pFVar2,"%s:%d: power protocal %02x, using simple cmd\n","power.c",0x9a,(uint)bVar1);
      }
      fclose(pFVar2);
    }
    power_protocal_type = 1;
  }
  pthread_mutex_unlock((pthread_mutex_t *)iic_mutex);
  return;
}


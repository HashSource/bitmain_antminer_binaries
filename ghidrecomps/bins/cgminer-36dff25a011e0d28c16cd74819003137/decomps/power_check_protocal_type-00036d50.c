
/* WARNING: Unknown calling convention */

void power_check_protocal_type(void)

{
  byte bVar1;
  FILE *pFVar2;
  FILE *pFile_1;
  FILE *pFile;
  FILE *pFile_3;
  FILE *pFile_2;
  uint8_t ret;
  
  pthread_mutex_lock((pthread_mutex_t *)&iic_mutex);
  bVar1 = znyq_set_iic(power_iic_addr,power_iic_no,true,true,'\0','\0');
  if (bVar1 == 0xf5) {
    if (3 < log_level) {
      print_crt_time_to_file(log_file,3);
      pFVar2 = fopen(log_file,"a+");
      if (pFVar2 != (FILE *)0x0) {
        fprintf(pFVar2,"%s:%d:%s: power protocal %02x, using package cmd\n","power.c",0xb5,
                "power_check_protocal_type",0xf5);
      }
      fclose(pFVar2);
    }
    if (3 < log_level) {
      print_crt_time_to_file(log_file,3);
      pFVar2 = fopen(log_file,"a+");
      if (pFVar2 != (FILE *)0x0) {
        fprintf(pFVar2,"%s:%d:%s: power type APW9 3600W\n","power.c",0xb6,
                "power_check_protocal_type");
      }
      fclose(pFVar2);
    }
    power_protocal_type = 2;
  }
  else {
    if (3 < log_level) {
      print_crt_time_to_file(log_file,3);
      pFVar2 = fopen(log_file,"a+");
      if (pFVar2 != (FILE *)0x0) {
        fprintf(pFVar2,"%s:%d:%s: power protocal %02x, using simple cmd\n","power.c",0xbb,
                "power_check_protocal_type",(uint)bVar1);
      }
      fclose(pFVar2);
    }
    if (3 < log_level) {
      print_crt_time_to_file(log_file,3);
      pFVar2 = fopen(log_file,"a+");
      if (pFVar2 != (FILE *)0x0) {
        fprintf(pFVar2,"%s:%d:%s: power type APW8 2000W\n","power.c",0xbc,
                "power_check_protocal_type");
      }
      fclose(pFVar2);
    }
    power_protocal_type = 1;
  }
  pthread_mutex_unlock((pthread_mutex_t *)&iic_mutex);
  return;
}


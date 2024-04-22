
void stop_scan(FREQ_SCAN_ERRNO error_num,uint8_t chain)

{
  FILE *pFVar1;
  uint8_t chain_local;
  FREQ_SCAN_ERRNO error_num_local;
  FILE *pFile_5;
  FILE *pFile;
  FILE *pFile_1;
  FILE *pFile_2;
  FILE *pFile_3;
  FILE *pFile_4;
  
  switch(error_num) {
  case ASIC_NUM_ERR:
    if (3 < log_level) {
      print_crt_time_to_file(log_file,3);
      pFVar1 = fopen(log_file,"a+");
      if (pFVar1 != (FILE *)0x0) {
        fprintf(pFVar1,"%s:%d:%s: J[%d]:2 Error for chain[%d] asic number not enough\n",
                "freq_scan.c",0x36,"stop_scan",(uint)chain,(uint)chain);
      }
      fclose(pFVar1);
    }
    break;
  case HASH_RATE_ERR:
    if (3 < log_level) {
      print_crt_time_to_file(log_file,3);
      pFVar1 = fopen(log_file,"a+");
      if (pFVar1 != (FILE *)0x0) {
        fprintf(pFVar1,"%s:%d:%s: T[%d]:1 Error for chain[%d] hash rate too low\n","freq_scan.c",
                0x39,"stop_scan",(uint)chain,(uint)chain);
      }
      fclose(pFVar1);
    }
    break;
  case EEPROM_SET_ERR:
    if (3 < log_level) {
      print_crt_time_to_file(log_file,3);
      pFVar1 = fopen(log_file,"a+");
      if (pFVar1 != (FILE *)0x0) {
        fprintf(pFVar1,"%s:%d:%s: E[%d]:1 Error for chain[%d] saving freq info into eeprom\n",
                "freq_scan.c",0x3c,"stop_scan",(uint)chain,(uint)chain);
      }
      fclose(pFVar1);
    }
    break;
  case FAN_NUM_ERR:
    if (3 < log_level) {
      print_crt_time_to_file(log_file,3);
      pFVar1 = fopen(log_file,"a+");
      if (pFVar1 != (FILE *)0x0) {
        fprintf(pFVar1,"%s:%d:%s: F:1 Error for fan number not enough\n","freq_scan.c",0x3f,
                "stop_scan");
      }
      fclose(pFVar1);
    }
    break;
  case INBALANCE_NUM_ERR:
    if (3 < log_level) {
      print_crt_time_to_file(log_file,3);
      pFVar1 = fopen(log_file,"a+");
      if (pFVar1 != (FILE *)0x0) {
        fprintf(pFVar1,
                "%s:%d:%s: J[%d]:3 Error for chain[%d] inbalance asic number is more than 4\n",
                "freq_scan.c",0x42,"stop_scan",(uint)chain,(uint)chain);
      }
      fclose(pFVar1);
    }
    break;
  default:
    if (3 < log_level) {
      print_crt_time_to_file(log_file,3);
      pFVar1 = fopen(log_file,"a+");
      if (pFVar1 != (FILE *)0x0) {
        fprintf(pFVar1,"%s:%d:%s: X:X Error for unkwon error\n","freq_scan.c",0x45,"stop_scan");
      }
      fclose(pFVar1);
    }
  }
  do {
    process_TEST();
    sleep(1);
  } while( true );
}


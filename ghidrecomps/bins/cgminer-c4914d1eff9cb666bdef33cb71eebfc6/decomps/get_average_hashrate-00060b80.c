
double get_average_hashrate(uint32_t minutes)

{
  uint32_t uVar1;
  FILE *pFVar2;
  double dVar3;
  uint32_t minutes_local;
  FILE *pFile;
  FILE *pFile_8;
  FILE *pFile_7;
  FILE *pFile_6;
  FILE *pFile_5;
  FILE *pFile_4;
  FILE *pFile_3;
  FILE *pFile_2;
  FILE *pFile_1;
  double hash_rate;
  double diff_secs;
  double diff_hashrate;
  int tmp_index;
  int32_t start_index;
  int32_t end_index;
  
  if (length < 2) {
    dVar3 = DAT_00060da0;
    if (3 < log_level) {
      print_crt_time_to_file(log_file,3);
      pFVar2 = fopen(log_file,"a+");
      if (pFVar2 != (FILE *)0x0) {
        fprintf(pFVar2,"%s:%d:%s: hash rate data is not enough!\n","hash_rate.c",0x7b,
                "get_average_hashrate");
      }
      fclose(pFVar2);
      dVar3 = DAT_00060da0;
    }
  }
  else {
    minutes_local = minutes;
    if (length - 1 <= minutes) {
      if (3 < log_level) {
        print_crt_time_to_file(hash_log,3);
        pFVar2 = fopen(hash_log,"a+");
        if (pFVar2 != (FILE *)0x0) {
          fprintf(pFVar2,"%s:%d:%s: minutes = %d,max length = %d,use minute = %d instead\n",
                  "hash_rate.c",0x81,"get_average_hashrate",minutes,length,length - 1);
        }
        fclose(pFVar2);
      }
      if (4 < log_level) {
        print_crt_time_to_file(log_file,4);
        pFVar2 = fopen(log_file,"a+");
        if (pFVar2 != (FILE *)0x0) {
          fprintf(pFVar2,"%s:%d:%s: minutes = %d beyond max length = %d,use minute = %d instead\n",
                  "hash_rate.c",0x82,"get_average_hashrate",minutes,length,length - 1);
        }
        fclose(pFVar2);
      }
      minutes_local = length - 1;
    }
    uVar1 = thash_index;
    end_index = thash_index - minutes_local;
    if (end_index < 0) {
      end_index = end_index + 0x41;
    }
    if (3 < log_level) {
      print_crt_time_to_file(hash_log,3);
      pFVar2 = fopen(hash_log,"a+");
      if (pFVar2 != (FILE *)0x0) {
        fprintf(pFVar2,"%s:%d:%s: start_index = %d, end_index = %d\n","hash_rate.c",0x90,
                "get_average_hashrate",uVar1,end_index);
      }
      fclose(pFVar2);
    }
    if (4 < log_level) {
      print_crt_time_to_file(log_file,4);
      pFVar2 = fopen(log_file,"a+");
      if (pFVar2 != (FILE *)0x0) {
        fprintf(pFVar2,"%s:%d:%s: start_index = %d, end_index = %d\n","hash_rate.c",0x91,
                "get_average_hashrate",uVar1,end_index);
      }
      fclose(pFVar2);
    }
    dVar3 = (thashrate_array[uVar1] - thashrate_array[end_index]) /
            (double)(ulonglong)(minutes_local * 0x3c);
    if (3 < log_level) {
      print_crt_time_to_file(hash_log,3);
      pFVar2 = fopen(hash_log,"a+");
      if (pFVar2 != (FILE *)0x0) {
        fprintf(pFVar2,"%s:%d:%s: diff_hashrate = %.3f, diff_secs = %.0f\n","hash_rate.c",0x97,
                "get_average_hashrate");
      }
      fclose(pFVar2);
    }
    if (4 < log_level) {
      print_crt_time_to_file(log_file,4);
      pFVar2 = fopen(log_file,"a+");
      if (pFVar2 != (FILE *)0x0) {
        fprintf(pFVar2,"%s:%d:%s: diff_hashrate = %.3f, diff_secs = %.0f\n","hash_rate.c",0x98,
                "get_average_hashrate");
      }
      fclose(pFVar2);
    }
    hash_rate._0_4_ = SUB84(dVar3,0);
    hash_rate._4_4_ = (undefined4)((ulonglong)dVar3 >> 0x20);
    if (3 < log_level) {
      print_crt_time_to_file(hash_log,3);
      pFVar2 = fopen(hash_log,"a+");
      if (pFVar2 != (FILE *)0x0) {
        fprintf(pFVar2,"%s:%d:%s: [%d] minutes ave hashrate : [%.3f] THash/s\n","hash_rate.c",0x9a,
                "get_average_hashrate",minutes_local,hash_rate._0_4_,hash_rate._4_4_);
      }
      fclose(pFVar2);
    }
    if (4 < log_level) {
      print_crt_time_to_file(log_file,4);
      pFVar2 = fopen(log_file,"a+");
      if (pFVar2 != (FILE *)0x0) {
        fprintf(pFVar2,"%s:%d:%s: [%d] minutes ave hashrate : [%.3f] THash/s\n","hash_rate.c",0x9b,
                "get_average_hashrate",minutes_local,hash_rate._0_4_,hash_rate._4_4_);
      }
      fclose(pFVar2);
    }
    dVar3 = dVar3 * DAT_00060da8;
  }
  return dVar3;
}


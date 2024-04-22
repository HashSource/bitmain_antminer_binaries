
int scan_freq_get_work_of_core_one_file(int which_asic,int which_core,FILE **stream,int count)

{
  uint32_t uVar1;
  char *pcVar2;
  FILE *__stream;
  SCAN_FREQ_WORK *__ptr;
  int count_local;
  FILE **stream_local;
  int which_core_local;
  int which_asic_local;
  char str [1024];
  FILE *pFile;
  SCAN_FREQ_WORK *new_work;
  int read_pattern_count;
  uint subid;
  uint8_t *temp;
  
  memset(str,0,0x400);
  subid = 0;
  read_pattern_count = 0;
  do {
    pcVar2 = fgets(str,0x3ff,(FILE *)*stream);
    if (pcVar2 == (char *)0x0) {
      return subid;
    }
    read_pattern_count = read_pattern_count + 1;
    if (subid < (uint)count) {
      __ptr = scanfreq_info.works[which_asic] + subid + count * which_core;
      pcVar2 = strstr(str,"nonce");
      if (pcVar2 == (char *)0x0) {
err:
        free(__ptr);
        if (log_level < 4) {
          return subid;
        }
        print_crt_time_to_file(log_file,3);
        __stream = fopen(log_file,"a+");
        if (__stream != (FILE *)0x0) {
          fprintf(__stream,"%s:%d:%s: get work err\n","freq_scan.c",0x133,
                  "scan_freq_get_work_of_core_one_file");
        }
        fclose(__stream);
        return subid;
      }
      for (temp = (uint8_t *)(pcVar2 + 5); *temp == ' '; temp = temp + 1) {
      }
      s2hex((uchar *)&__ptr->nonce,temp,8);
      uVar1 = htonl(__ptr->nonce);
      __ptr->nonce = uVar1;
      pcVar2 = strstr(str,"midstate");
      if (pcVar2 == (char *)0x0) goto err;
      for (temp = (uint8_t *)(pcVar2 + 8); *temp == ' '; temp = temp + 1) {
      }
      s2hex(__ptr->midstate,temp,0x40);
      pcVar2 = strstr(str,"data");
      if (pcVar2 == (char *)0x0) goto err;
      for (temp = (uint8_t *)(pcVar2 + 4); *temp == ' '; temp = temp + 1) {
      }
      s2hex(__ptr->data,temp,0x18);
      memset(__ptr->is_nonce_return_back,0,0x40);
      __ptr->id = subid;
      subid = subid + 1;
    }
    if (7 < read_pattern_count) {
      return subid;
    }
  } while( true );
}


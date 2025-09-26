
void BTC_super_software_pattern_check_nonce(return_nonce_128bit_t *nonce_buf)

{
  byte bVar1;
  return_nonce_128bit_t *nonce_buf_local;
  char time_stamp [48];
  char tmp1 [2048];
  uint32_t nonce;
  char *sznonce;
  work_new *work;
  work_new *works;
  uint32_t which_pattern;
  uint32_t which_small_core;
  uint32_t which_big_core;
  uint32_t which_asic;
  
  which_asic = 0;
  which_big_core = 0;
  which_small_core = 0;
  which_pattern = 0;
  works = (work_new *)0x0;
  work = (work_new *)0x0;
  if ((*(byte *)nonce_buf & 0xf) == gChain) {
    bVar1 = get_asic_index_by_nonce((nonce_buf->nonce).nonce,gAddress_interval);
    which_asic = (uint32_t)bVar1;
    bVar1 = get_coreid_by_nonce((nonce_buf->nonce).nonce);
    which_big_core = (uint32_t)bVar1;
    which_small_core = *(ushort *)((int)(nonce_buf->reg).reserved_2 + 1) & 0xf;
    which_pattern = (int)(*(ushort *)((int)nonce_buf + 2) & 0x7fff) >> 7;
    if (which_asic < (Local_Config_Information->Hash_Board).Asic_Num) {
      if (which_big_core < 0x80) {
        if ((which_big_core == 0x7f) || (which_big_core == 0xf)) {
          if (0xb < which_small_core) {
            print_time_stamp(time_stamp,0x30);
            printf("%s ",time_stamp);
            printf("%s: receive nonce from Aisc: %d, big_core %d, small_core %d, but the most Asic small_core number is: %d\n"
                   ,"BTC_super_software_pattern_check_nonce",which_asic,which_big_core,
                   which_small_core,0x10);
            snprintf(tmp1,0x800,
                     "receive nonce from Aisc: %d, big_core %d, small_core %d, but the most Asic small_core number is: %d"
                     ,which_asic,which_big_core,which_small_core,0x10);
            log_to_file(tmp1,time_stamp);
            return;
          }
        }
        else if (0xf < which_small_core) {
          print_time_stamp(time_stamp,0x30);
          printf("%s ",time_stamp);
          printf("%s: receive nonce from Aisc: %d, big_core %d, small_core %d, but the most Asic small_core number is: %d\n"
                 ,"BTC_super_software_pattern_check_nonce",which_asic,which_big_core,
                 which_small_core,0x10);
          snprintf(tmp1,0x800,
                   "receive nonce from Aisc: %d, big_core %d, small_core %d, but the most Asic small_core number is: %d"
                   ,which_asic,which_big_core,which_small_core,0x10);
          log_to_file(tmp1,time_stamp);
          return;
        }
        if (which_pattern < (Local_Config_Information->Test_Info).Test_Standard.Pattern_Number) {
          nonce = (nonce_buf->nonce).nonce << 0x18 |
                  (nonce_buf->nonce).nonce >> 0x18 | ((nonce_buf->nonce).nonce & 0xff0000) >> 8 |
                  ((nonce_buf->nonce).nonce & 0xff00) << 8;
          sznonce = bin2hex((uchar *)&nonce,4);
          print_time_stamp(time_stamp,0x30);
          printf("%s ",time_stamp);
          printf("%s: asic:%d coreid:%d recv nonce: %s \n\n",
                 "BTC_super_software_pattern_check_nonce",which_asic,which_big_core,sznonce);
          snprintf(tmp1,0x800,"asic:%d coreid:%d recv nonce: %s \n",which_asic,which_big_core,
                   sznonce);
          log_to_file(tmp1,time_stamp);
          if (sznonce != (char *)0x0) {
            free(sznonce);
          }
        }
        else {
          print_time_stamp(time_stamp,0x30);
          printf("%s ",time_stamp);
          printf("%s: receive %dth pattern from Aisc: %d, big_core %d, small_core %d, but the most pattern number is: %d\n"
                 ,"BTC_super_software_pattern_check_nonce",which_pattern,which_asic,which_big_core,
                 which_small_core,(Local_Config_Information->Test_Info).Test_Standard.Pattern_Number
                );
          snprintf(tmp1,0x800,
                   "receive %dth pattern from Aisc: %d, big_core %d, small_core %d, but the most pattern number is: %d"
                   ,which_pattern,which_asic,which_big_core,which_small_core,
                   (Local_Config_Information->Test_Info).Test_Standard.Pattern_Number);
          log_to_file(tmp1,time_stamp);
        }
      }
      else {
        print_time_stamp(time_stamp,0x30);
        printf("%s ",time_stamp);
        printf("%s: receive nonce from Aisc: %d, big_core %d, but the most Asic big_core number is: %d\n"
               ,"BTC_super_software_pattern_check_nonce",which_asic,which_big_core,0x80);
        snprintf(tmp1,0x800,
                 "receive nonce from Aisc: %d, big_core %d, but the most Asic big_core number is: %d"
                 ,which_asic,which_big_core,0x80);
        log_to_file(tmp1,time_stamp);
      }
    }
    else {
      print_time_stamp(time_stamp,0x30);
      printf("%s ",time_stamp);
      printf("%s: receive nonce from Aisc: %d, but the most Asic number is: %d\n",
             "BTC_super_software_pattern_check_nonce",which_asic,
             (Local_Config_Information->Hash_Board).Asic_Num);
      snprintf(tmp1,0x800,"receive nonce from Aisc: %d, but the most Asic number is: %d",which_asic,
               (Local_Config_Information->Hash_Board).Asic_Num);
      log_to_file(tmp1,time_stamp);
    }
  }
  else {
    print_time_stamp(time_stamp,0x30);
    printf("%s ",time_stamp);
    printf("%s: receive nonce from chain: %d, but not gChain: %d\n",
           "BTC_super_software_pattern_check_nonce",*(byte *)nonce_buf & 0xf,gChain);
    snprintf(tmp1,0x800,"receive nonce from chain: %d, but not gChain: %d",*(byte *)nonce_buf & 0xf,
             gChain);
    log_to_file(tmp1,time_stamp);
  }
  return;
}


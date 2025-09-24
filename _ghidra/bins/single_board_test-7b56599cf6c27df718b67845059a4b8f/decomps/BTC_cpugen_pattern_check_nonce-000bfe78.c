
void BTC_cpugen_pattern_check_nonce(return_nonce_128bit_t *nonce_buf)

{
  byte bVar1;
  uint uVar3;
  uint uVar4;
  return_nonce_128bit_t *nonce_buf_local;
  char time_stamp [48];
  char tmp1 [256];
  work_new *work;
  work_new *works;
  uint32_t which_pattern;
  uint32_t which_small_core;
  uint32_t which_big_core;
  uint32_t which_asic;
  uint uVar2;
  
  if ((*(byte *)nonce_buf & 0xf) == gChain) {
    bVar1 = get_asic_index_by_nonce((nonce_buf->nonce).nonce,gAddress_interval);
    uVar2 = (uint)bVar1;
    bVar1 = get_coreid_by_nonce((nonce_buf->nonce).nonce);
    uVar3 = (uint)bVar1;
    uVar4 = *(ushort *)((int)nonce_buf + 2) & 0x7f;
    if (uVar2 < (Local_Config_Information->Hash_Board).Asic_Num) {
      if (uVar3 < 0x50) {
        if (uVar3 == 0x4f) {
          if (uVar4 < 4) {
            print_time_stamp(time_stamp,0x30);
            printf("%s ",time_stamp);
            printf("%s : receive nonce from Aisc: %d, big_core %d, small_core %d, but the most Asic small_core number is: %d\n"
                   ,"BTC_cpugen_pattern_check_nonce",uVar2,0x4f,uVar4,0x10);
            snprintf(tmp1,0x100,
                     "receive nonce from Aisc: %d, big_core %d, small_core %d, but the most Asic small_core number is: %d"
                     ,uVar2,0x4f,uVar4,0x10);
            log_to_file(tmp1,time_stamp);
          }
        }
        else if (0xf < uVar4) {
          print_time_stamp(time_stamp,0x30);
          printf("%s ",time_stamp);
          printf("%s : receive nonce from Aisc: %d, big_core %d, small_core %d, but the most Asic small_core number is: %d\n"
                 ,"BTC_cpugen_pattern_check_nonce",uVar2,uVar3,uVar4,0x10);
          snprintf(tmp1,0x100,
                   "receive nonce from Aisc: %d, big_core %d, small_core %d, but the most Asic small_core number is: %d"
                   ,uVar2,uVar3,uVar4,0x10);
          log_to_file(tmp1,time_stamp);
        }
      }
      else {
        print_time_stamp(time_stamp,0x30);
        printf("%s ",time_stamp);
        printf("%s : receive nonce from Aisc: %d, big_core %d, but the most Asic big_core number is: %d\n"
               ,"BTC_cpugen_pattern_check_nonce",uVar2,uVar3,0x50);
        snprintf(tmp1,0x100,
                 "receive nonce from Aisc: %d, big_core %d, but the most Asic big_core number is: %d"
                 ,uVar2,uVar3,0x50);
        log_to_file(tmp1,time_stamp);
      }
    }
    else {
      print_time_stamp(time_stamp,0x30);
      printf("%s ",time_stamp);
      printf("%s : receive nonce from Aisc: %d, but the most Asic number is: %d\n",
             "BTC_cpugen_pattern_check_nonce",uVar2,(Local_Config_Information->Hash_Board).Asic_Num)
      ;
      snprintf(tmp1,0x100,"receive nonce from Aisc: %d, but the most Asic number is: %d",uVar2,
               (Local_Config_Information->Hash_Board).Asic_Num);
      log_to_file(tmp1,time_stamp);
    }
  }
  else {
    print_time_stamp(time_stamp,0x30);
    printf("%s ",time_stamp);
    printf("%s : receive nonce from chain: %d, but not gChain: %d\n",
           "BTC_cpugen_pattern_check_nonce",*(byte *)nonce_buf & 0xf,gChain);
    snprintf(tmp1,0x100,"receive nonce from chain: %d, but not gChain: %d",*(byte *)nonce_buf & 0xf,
             gChain);
    log_to_file(tmp1,time_stamp);
  }
  return;
}


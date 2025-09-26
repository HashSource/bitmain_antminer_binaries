
void BTC_mid_auto_gen_check_nonce(return_nonce_128bit_t *nonce_buf)

{
  byte bVar1;
  char *datetime;
  int len;
  uint uVar3;
  uint uVar4;
  work *pwVar5;
  int iVar6;
  return_nonce_128bit_t *nonce_buf_local;
  char time_stamp [48];
  char tmp1 [2048];
  uint32_t match_nonce;
  work *work;
  work *works;
  uint32_t which_pattern;
  uint32_t which_small_core;
  uint32_t which_big_core;
  uint32_t which_asic;
  uint uVar2;
  
  if ((*(byte *)nonce_buf & 0xf) == gChain) {
    bVar1 = get_asic_index_by_nonce((nonce_buf->nonce).nonce,gAddress_interval);
    uVar2 = (uint)bVar1;
    bVar1 = get_coreid_by_nonce((nonce_buf->nonce).nonce);
    datetime = (char *)(uint)bVar1;
    uVar3 = *(ushort *)((int)(nonce_buf->reg).reserved_2 + 1) >> 8 & 0xf;
    uVar4 = (int)(*(ushort *)((int)nonce_buf + 2) & 0x7fff) >> 7;
    if (uVar2 < (Local_Config_Information->Hash_Board).Asic_Num) {
      if (datetime < (char *)0x80) {
        if (datetime == (char *)0x7f) {
          if (uVar3 < 4) {
            print_time_stamp(time_stamp,0x30);
            printf("%s ",time_stamp);
            printf("%s: receive nonce from Aisc: %d, big_core %d, small_core %d, but the most Asic small_core number is: %d\n"
                   ,"BTC_mid_auto_gen_check_nonce",uVar2,0x7f,uVar3,0x10);
            snprintf(tmp1,0x800,
                     "receive nonce from Aisc: %d, big_core %d, small_core %d, but the most Asic small_core number is: %d"
                     ,uVar2,0x7f,uVar3,0x10);
            log_to_file(tmp1,time_stamp);
            return;
          }
        }
        else if (0xf < uVar3) {
          print_time_stamp(datetime,len);
          printf("%s : receive nonce from Aisc: %d, big_core %d, small_core %d, but the most Asic small_core number is: %d\n"
                 ,"BTC_mid_auto_gen_check_nonce",uVar2,datetime,uVar3,0x10);
          return;
        }
        if (uVar4 < (Local_Config_Information->Test_Info).Test_Standard.Pattern_Number) {
          pwVar5 = pattern_info.works[uVar2];
          iVar6 = uVar4 + (Local_Config_Information->Test_Info).Test_Standard.Pattern_Number *
                          ((int)datetime * 0x10 + uVar3);
          if ((nonce_buf->nonce).nonce == pwVar5[iVar6].pattern.nonce) {
            if (pwVar5[iVar6].is_nonce_return_back == 0) {
              pwVar5[iVar6].is_nonce_return_back = pwVar5[iVar6].is_nonce_return_back + 1;
              gHistory_Result[gPattern_test_counter].valid_nonce_num =
                   gHistory_Result[gPattern_test_counter].valid_nonce_num + 1;
              iVar6 = (int)datetime * 0x10 + uVar3;
              gHistory_Result[gPattern_test_counter].asic_core_nonce_num[uVar2][iVar6] =
                   gHistory_Result[gPattern_test_counter].asic_core_nonce_num[uVar2][iVar6] + 1;
              gHistory_Result[gPattern_test_counter].every_asic_got_nonce_num[uVar2] =
                   gHistory_Result[gPattern_test_counter].every_asic_got_nonce_num[uVar2] + 1;
            }
            else {
              gHistory_Result[gPattern_test_counter].repeat_nonce_number =
                   gHistory_Result[gPattern_test_counter].repeat_nonce_number + 1;
              pwVar5[iVar6].is_nonce_return_back = pwVar5[iVar6].is_nonce_return_back + 1;
            }
          }
        }
        else {
          print_time_stamp(datetime,len);
          printf("%s : receive %dth pattern from Aisc: %d, big_core %d, small_core %d, but the most pattern number is: %d\n"
                 ,"BTC_mid_auto_gen_check_nonce",uVar4,uVar2,datetime,uVar3,
                 (Local_Config_Information->Test_Info).Test_Standard.Pattern_Number);
        }
      }
      else {
        print_time_stamp(time_stamp,0x30);
        printf("%s ",time_stamp);
        printf("%s: receive nonce from Aisc: %d, big_core %d, but the most Asic big_core number is: %d\n"
               ,"BTC_mid_auto_gen_check_nonce",uVar2,datetime,0x80);
        snprintf(tmp1,0x800,
                 "receive nonce from Aisc: %d, big_core %d, but the most Asic big_core number is: %d"
                 ,uVar2,datetime,0x80);
        log_to_file(tmp1,time_stamp);
      }
    }
    else {
      print_time_stamp(time_stamp,0x30);
      printf("%s ",time_stamp);
      printf("%s: receive nonce from Aisc: %d, but the most Asic number is: %d\n",
             "BTC_mid_auto_gen_check_nonce",uVar2,(Local_Config_Information->Hash_Board).Asic_Num);
      snprintf(tmp1,0x800,"receive nonce from Aisc: %d, but the most Asic number is: %d",uVar2,
               (Local_Config_Information->Hash_Board).Asic_Num);
      log_to_file(tmp1,time_stamp);
    }
  }
  else {
    print_time_stamp(time_stamp,0x30);
    printf("%s ",time_stamp);
    printf("%s: receive nonce from chain: %d, but not gChain: %d\n","BTC_mid_auto_gen_check_nonce",
           *(byte *)nonce_buf & 0xf,gChain);
    snprintf(tmp1,0x800,"receive nonce from chain: %d, but not gChain: %d",*(byte *)nonce_buf & 0xf,
             gChain);
    log_to_file(tmp1,time_stamp);
  }
  return;
}


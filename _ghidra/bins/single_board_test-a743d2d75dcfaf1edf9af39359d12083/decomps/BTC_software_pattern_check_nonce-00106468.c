
void BTC_software_pattern_check_nonce(return_nonce_128bit_t *nonce_buf)

{
  byte bVar1;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  work_new *pwVar6;
  int iVar7;
  return_nonce_128bit_t *nonce_buf_local;
  char time_stamp [48];
  char tmp1 [2048];
  uint32_t match_nonce;
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
    uVar4 = *(ushort *)((int)(nonce_buf->reg).reserved_2 + 1) & 0xf;
    uVar5 = (int)(*(ushort *)((int)nonce_buf + 2) & 0x7fff) >> 7;
    if (uVar2 < (Local_Config_Information->Hash_Board).Asic_Num) {
      if (uVar3 < 0x80) {
        if ((uVar3 == 0x7f) || (uVar3 == 0xf)) {
          if (0xb < uVar4) {
            print_time_stamp(time_stamp,0x30);
            printf("%s ",time_stamp);
            printf("%s: receive nonce from Aisc: %d, big_core %d, small_core %d, but the most Asic small_core number is: %d\n"
                   ,"BTC_software_pattern_check_nonce",uVar2,uVar3,uVar4,0x10);
            snprintf(tmp1,0x800,
                     "receive nonce from Aisc: %d, big_core %d, small_core %d, but the most Asic small_core number is: %d"
                     ,uVar2,uVar3,uVar4,0x10);
            log_to_file(tmp1,time_stamp);
            return;
          }
        }
        else if (0xf < uVar4) {
          print_time_stamp(time_stamp,0x30);
          printf("%s ",time_stamp);
          printf("%s: receive nonce from Aisc: %d, big_core %d, small_core %d, but the most Asic small_core number is: %d\n"
                 ,"BTC_software_pattern_check_nonce",uVar2,uVar3,uVar4,0x10);
          snprintf(tmp1,0x800,
                   "receive nonce from Aisc: %d, big_core %d, small_core %d, but the most Asic small_core number is: %d"
                   ,uVar2,uVar3,uVar4,0x10);
          log_to_file(tmp1,time_stamp);
          return;
        }
        if (uVar5 < (Local_Config_Information->Test_Info).Test_Standard.Pattern_Number) {
          pwVar6 = pattern_info_new.works[uVar2];
          iVar7 = uVar5 + (Local_Config_Information->Test_Info).Test_Standard.Pattern_Number *
                          (uVar3 * 0x10 + uVar4);
          if ((nonce_buf->nonce).nonce == pwVar6[iVar7].pattern.nonce) {
            if ((Local_Config_Information->Test_Info).Test_Method.Midstate_Number == 4) {
              if (pwVar6[iVar7].is_nonce_return_back == 0) {
                pwVar6[iVar7].is_nonce_return_back = pwVar6[iVar7].is_nonce_return_back + 1;
                gHistory_Result[gPattern_test_counter].valid_nonce_num =
                     gHistory_Result[gPattern_test_counter].valid_nonce_num + 1;
                iVar7 = uVar3 * 0x10 + uVar4;
                gHistory_Result[gPattern_test_counter].asic_core_nonce_num[uVar2][iVar7] =
                     gHistory_Result[gPattern_test_counter].asic_core_nonce_num[uVar2][iVar7] + 1;
                gHistory_Result[gPattern_test_counter].every_asic_got_nonce_num[uVar2] =
                     gHistory_Result[gPattern_test_counter].every_asic_got_nonce_num[uVar2] + 1;
              }
              else {
                gHistory_Result[gPattern_test_counter].repeat_nonce_number =
                     gHistory_Result[gPattern_test_counter].repeat_nonce_number + 1;
                pwVar6[iVar7].is_nonce_return_back = pwVar6[iVar7].is_nonce_return_back + 1;
              }
            }
            else if (pwVar6[iVar7].is_nonce_return_back == 0) {
              pwVar6[iVar7].is_nonce_return_back = pwVar6[iVar7].is_nonce_return_back + 1;
              gHistory_Result[gPattern_test_counter].valid_nonce_num =
                   gHistory_Result[gPattern_test_counter].valid_nonce_num + 1;
              iVar7 = uVar3 * 0x10 + uVar4;
              gHistory_Result[gPattern_test_counter].asic_core_nonce_num[uVar2][iVar7] =
                   gHistory_Result[gPattern_test_counter].asic_core_nonce_num[uVar2][iVar7] + 1;
              gHistory_Result[gPattern_test_counter].every_asic_got_nonce_num[uVar2] =
                   gHistory_Result[gPattern_test_counter].every_asic_got_nonce_num[uVar2] + 1;
            }
            else {
              gHistory_Result[gPattern_test_counter].repeat_nonce_number =
                   gHistory_Result[gPattern_test_counter].repeat_nonce_number + 1;
              pwVar6[iVar7].is_nonce_return_back = pwVar6[iVar7].is_nonce_return_back + 1;
            }
          }
        }
        else {
          print_time_stamp(time_stamp,0x30);
          printf("%s ",time_stamp);
          printf("%s: receive %dth pattern from Aisc: %d, big_core %d, small_core %d, but the most pattern number is: %d\n"
                 ,"BTC_software_pattern_check_nonce",uVar5,uVar2,uVar3,uVar4,
                 (Local_Config_Information->Test_Info).Test_Standard.Pattern_Number);
          snprintf(tmp1,0x800,
                   "receive %dth pattern from Aisc: %d, big_core %d, small_core %d, but the most pattern number is: %d"
                   ,uVar5,uVar2,uVar3,uVar4,
                   (Local_Config_Information->Test_Info).Test_Standard.Pattern_Number);
          log_to_file(tmp1,time_stamp);
        }
      }
      else {
        print_time_stamp(time_stamp,0x30);
        printf("%s ",time_stamp);
        printf("%s: receive nonce from Aisc: %d, big_core %d, but the most Asic big_core number is: %d\n"
               ,"BTC_software_pattern_check_nonce",uVar2,uVar3,0x80);
        snprintf(tmp1,0x800,
                 "receive nonce from Aisc: %d, big_core %d, but the most Asic big_core number is: %d"
                 ,uVar2,uVar3,0x80);
        log_to_file(tmp1,time_stamp);
      }
    }
    else {
      print_time_stamp(time_stamp,0x30);
      printf("%s ",time_stamp);
      printf("%s: receive nonce from Aisc: %d, but the most Asic number is: %d\n",
             "BTC_software_pattern_check_nonce",uVar2,
             (Local_Config_Information->Hash_Board).Asic_Num);
      snprintf(tmp1,0x800,"receive nonce from Aisc: %d, but the most Asic number is: %d",uVar2,
               (Local_Config_Information->Hash_Board).Asic_Num);
      log_to_file(tmp1,time_stamp);
    }
  }
  else {
    print_time_stamp(time_stamp,0x30);
    printf("%s ",time_stamp);
    printf("%s: receive nonce from chain: %d, but not gChain: %d\n",
           "BTC_software_pattern_check_nonce",*(byte *)nonce_buf & 0xf,gChain);
    snprintf(tmp1,0x800,"receive nonce from chain: %d, but not gChain: %d",*(byte *)nonce_buf & 0xf,
             gChain);
    log_to_file(tmp1,time_stamp);
  }
  return;
}


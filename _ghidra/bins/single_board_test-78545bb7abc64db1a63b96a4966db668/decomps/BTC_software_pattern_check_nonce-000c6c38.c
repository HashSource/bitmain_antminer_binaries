
void BTC_software_pattern_check_nonce(return_nonce_128bit_t *nonce_buf)

{
  byte bVar1;
  uint uVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  work_new *pwVar7;
  return_nonce_128bit_t *nonce_buf_local;
  char time_stamp [48];
  char tmp1 [256];
  uint32_t match_nonce;
  work_new *work;
  work_new *works;
  uint32_t which_pattern;
  uint32_t which_small_core;
  uint32_t which_big_core;
  uint32_t which_asic;
  uint uVar2;
  
  if (nonce_buf == (return_nonce_128bit_t *)0x0) {
    print_time_stamp(time_stamp,0x30);
    printf("%s ",time_stamp);
    printf("%s : nonce_buf is null\n","BTC_software_pattern_check_nonce");
    builtin_strncpy(tmp1,"nonce_buf is nul",0x10);
    tmp1[0x10] = 'l';
    tmp1[0x11] = '\0';
    log_to_file(tmp1,time_stamp);
  }
  else if ((*(byte *)nonce_buf & 0xf) == gChain) {
    bVar1 = get_asic_index_by_nonce((nonce_buf->nonce).nonce,gAddress_interval);
    uVar2 = (uint)bVar1;
    bVar1 = get_coreid_by_nonce((nonce_buf->nonce).nonce);
    uVar3 = (uint)bVar1;
    uVar5 = *(ushort *)((int)(nonce_buf->reg).reserved_2 + 1) & 0xf;
    uVar6 = (int)(*(ushort *)((int)nonce_buf + 2) & 0x7fff) >> 7;
    if (uVar2 < (Local_Config_Information->Hash_Board).Asic_Num) {
      if (uVar3 < 0x80) {
        if ((uVar3 == 0x4f) || (uVar3 == 0x7f)) {
          if (0xc < uVar5) {
            err_nonce_resp = err_nonce_resp + 1;
            return;
          }
        }
        else if (0xf < uVar5) {
          err_nonce_resp = err_nonce_resp + 1;
          return;
        }
        if (uVar6 < (Local_Config_Information->Test_Info).Test_Standard.Pattern_Number) {
          pwVar7 = pattern_info_new.works[uVar2] +
                   uVar6 + (Local_Config_Information->Test_Info).Test_Standard.Pattern_Number *
                           (uVar3 * 0x10 + uVar5);
          if ((nonce_buf->nonce).nonce == (pwVar7->pattern).nonce) {
            if ((Local_Config_Information->Test_Info).Test_Method.Midstate_Number == 4) {
              if (pwVar7->is_nonce_return_back == 0) {
                pwVar7->is_nonce_return_back = pwVar7->is_nonce_return_back + 1;
                gHistory_Result[gPattern_test_counter].valid_nonce_num =
                     gHistory_Result[gPattern_test_counter].valid_nonce_num + 1;
                iVar4 = uVar3 * 0x10 + uVar5;
                gHistory_Result[gPattern_test_counter].asic_core_nonce_num[uVar2][iVar4] =
                     gHistory_Result[gPattern_test_counter].asic_core_nonce_num[uVar2][iVar4] +
                     '\x01';
                gHistory_Result[gPattern_test_counter].every_asic_got_nonce_num[uVar2] =
                     gHistory_Result[gPattern_test_counter].every_asic_got_nonce_num[uVar2] + 1;
              }
              else {
                gHistory_Result[gPattern_test_counter].repeat_nonce_number =
                     gHistory_Result[gPattern_test_counter].repeat_nonce_number + 1;
                pwVar7->is_nonce_return_back = pwVar7->is_nonce_return_back + 1;
              }
            }
            else if (pwVar7->is_nonce_return_back == 0) {
              pwVar7->is_nonce_return_back = pwVar7->is_nonce_return_back + 1;
              gHistory_Result[gPattern_test_counter].valid_nonce_num =
                   gHistory_Result[gPattern_test_counter].valid_nonce_num + 1;
              iVar4 = uVar3 * 0x10 + uVar5;
              gHistory_Result[gPattern_test_counter].asic_core_nonce_num[uVar2][iVar4] =
                   gHistory_Result[gPattern_test_counter].asic_core_nonce_num[uVar2][iVar4] + '\x01'
              ;
              gHistory_Result[gPattern_test_counter].every_asic_got_nonce_num[uVar2] =
                   gHistory_Result[gPattern_test_counter].every_asic_got_nonce_num[uVar2] + 1;
            }
            else {
              gHistory_Result[gPattern_test_counter].repeat_nonce_number =
                   gHistory_Result[gPattern_test_counter].repeat_nonce_number + 1;
              pwVar7->is_nonce_return_back = pwVar7->is_nonce_return_back + 1;
            }
          }
        }
        else {
          err_nonce_resp = err_nonce_resp + 1;
        }
      }
      else {
        err_nonce_resp = err_nonce_resp + 1;
      }
    }
    else {
      err_nonce_resp = err_nonce_resp + 1;
    }
  }
  else {
    err_nonce_resp = err_nonce_resp + 1;
  }
  return;
}



void BTC_cpugen_pattern_check_nonce(return_nonce_128bit_t *nonce_buf)

{
  byte bVar1;
  byte bVar2;
  int iVar3;
  uint which_midstate;
  uint32_t work_id_00;
  return_nonce_128bit_t *nonce_buf_local;
  char time_stamp [48];
  char tmp1 [2048];
  uint8_t midstate [32];
  uint32_t work_id;
  work *work;
  work *works;
  uint32_t which_pattern;
  uint32_t which_small_core;
  uint32_t which_big_core;
  uint32_t which_asic;
  uint which_big_core_00;
  
  if ((*(byte *)nonce_buf & 0xf) == gChain) {
    bVar1 = get_asic_index_by_nonce((nonce_buf->nonce).nonce,gAddress_interval);
    bVar2 = get_coreid_by_nonce((nonce_buf->nonce).nonce);
    which_big_core_00 = (uint)bVar2;
    which_midstate = *(ushort *)((int)(nonce_buf->reg).reserved_2 + 1) & 0xf;
    work_id_00 = (int)(*(ushort *)((int)nonce_buf + 2) & 0x7fff) >> 7;
    if ((uint)bVar1 < (Local_Config_Information->Hash_Board).Asic_Num) {
      if (which_big_core_00 < 0x50) {
        g_noncemap[work_id_00].count = 2;
      }
      else {
        if ((which_big_core_00 == 0x7f) || (which_big_core_00 == 0xf)) {
          if (0xb < which_midstate) {
            g_noncemap[work_id_00].count = 2;
            return;
          }
        }
        else if (0xf < which_midstate) {
          g_noncemap[work_id_00].count = 2;
          return;
        }
        iVar3 = check_hw(g_works_for_check + work_id_00,which_midstate,(nonce_buf->nonce).nonce);
        if (iVar3 == 0) {
          save_nonce(g_works_for_check + work_id_00,work_id_00,(uint)bVar1,which_midstate,
                     which_big_core_00,(nonce_buf->nonce).nonce,
                     (*(byte *)((int)nonce_buf + 1) & 0x7f) + 0x20);
        }
      }
    }
    else {
      g_noncemap[work_id_00].count = 2;
    }
  }
  else {
    print_time_stamp(time_stamp,0x30);
    printf("%s ",time_stamp);
    printf("%s: receive nonce from chain: %d, but not gChain: %d\n","BTC_cpugen_pattern_check_nonce"
           ,*(byte *)nonce_buf & 0xf,gChain);
    snprintf(tmp1,0x800,"receive nonce from chain: %d, but not gChain: %d",*(byte *)nonce_buf & 0xf,
             gChain);
    log_to_file(tmp1,time_stamp);
  }
  return;
}


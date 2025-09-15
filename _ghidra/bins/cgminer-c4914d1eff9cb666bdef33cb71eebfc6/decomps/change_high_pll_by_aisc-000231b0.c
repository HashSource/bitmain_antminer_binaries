
void change_high_pll_by_aisc(uint32_t chain,uint32_t asic,float freq,int index)

{
  uchar chip_addr_00;
  _Bool _Var1;
  uint8_t which_chain;
  FILE *pFVar2;
  int index_00;
  uint32_t pll_00;
  float fVar3;
  int index_local;
  float freq_local;
  uint32_t asic_local;
  uint32_t chain_local;
  uint8_t divider;
  float pll_freq;
  uint32_t vil_pll_t;
  uint8_t vil_pll [4];
  FILE *pFile_2;
  FILE *pFile_1;
  FILE *pFile;
  uint32_t chip_addr;
  uint32_t pll_index;
  uint32_t pll;
  
  divider = freq_high_pll_1393[index].divider;
  pll_00 = freq_high_pll_1393[index].pll_out;
  _Var1 = is_user_mode();
  which_chain = (uint8_t)chain;
  if (_Var1) {
    fVar3 = get_max_freq();
    _Var1 = check_freq_valid_single((uint)(0.0 < freq) * (int)freq,(uint)(0.0 < fVar3) * (int)fVar3)
    ;
    if (!_Var1) {
      if (3 < log_level) {
        print_crt_time_to_file(log_file,3);
        pFVar2 = fopen(log_file,"a+");
        if (pFVar2 != (FILE *)0x0) {
          get_max_freq();
          fprintf(pFVar2,"%s:%d:%s: User Mode: chain[%d] asic[%d] freq %f over the max freq %f \n",
                  "driver-btm-soc.c",0x11cc,"change_high_pll_by_aisc",chain,asic);
        }
        fclose(pFVar2);
      }
      disable_pic_dac(which_chain);
      dev->chain_exist[chain] = 0;
      dev->chain_num = dev->chain_num + 0xff;
      return;
    }
  }
  _Var1 = is_force_mode();
  if (_Var1) {
    fVar3 = get_max_scanfreq(false);
    _Var1 = check_freq_valid_single((uint)(0.0 < freq) * (int)freq,(uint)(0.0 < fVar3) * (int)fVar3)
    ;
    if (!_Var1) {
      if (3 < log_level) {
        print_crt_time_to_file(log_file,3);
        pFVar2 = fopen(log_file,"a+");
        if (pFVar2 != (FILE *)0x0) {
          get_max_scanfreq(false);
          fprintf(pFVar2,"%s:%d:%s: Force Mode: chain[%d] asic[%d] freq %f over the max freq %f \n",
                  "driver-btm-soc.c",0x11d8,"change_high_pll_by_aisc",chain,asic);
        }
        fclose(pFVar2);
      }
      disable_pic_dac(which_chain);
      dev->chain_exist[chain] = 0;
      dev->chain_num = dev->chain_num + 0xff;
      return;
    }
  }
  if (opt_use_pll_list == false) {
    get_pllparam_divider(freq,&vil_pll_t,&divider,&pll_freq);
    vil_pll = (uint8_t  [4])__bswap_32(vil_pll_t);
  }
  else {
    if (3 < log_level) {
      print_crt_time_to_file(log_file,3);
      pFVar2 = fopen(log_file,"a+");
      if (pFVar2 != (FILE *)0x0) {
        fprintf(pFVar2,"%s:%d:%s: set freq %d, pll_out %d\n","driver-btm-soc.c",0x11e2,
                "change_high_pll_by_aisc",freq_high_pll_1393[index].freq,pll_00);
      }
      fclose(pFVar2);
    }
    index_00 = get_index_from_pll_B1393(pll_00);
    get_plldata_from_index(index_00,vil_pll);
  }
  chip_addr_00 = (uchar)(asic << 2);
  set_config_BM1393_t(which_chain,chip_addr_00,'\0','p',divider - 1 | 0xf0f0f00);
  set_config_BM1393_t(which_chain,chip_addr_00,'\0','\b',
                      ((uint)vil_pll >> 0x10 & 0xff) << 8 |
                      (int)vil_pll << 0x18 | ((uint)vil_pll >> 8 & 0xff) << 0x10 |
                      (uint)vil_pll >> 0x18);
  set_config_BM1393_t(which_chain,chip_addr_00,'\0','p',divider - 1 | 0xf0f0f00);
  set_config_BM1393_t(which_chain,chip_addr_00,'\0','\b',
                      ((uint)vil_pll >> 0x10 & 0xff) << 8 |
                      (int)vil_pll << 0x18 | ((uint)vil_pll >> 8 & 0xff) << 0x10 |
                      (uint)vil_pll >> 0x18);
  set_unused_pll();
  return;
}


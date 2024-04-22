
int change_high_pll_test(uint8_t chain,float freq,int index)

{
  _Bool _Var1;
  FILE *pFVar2;
  int index_00;
  uint32_t pll_00;
  float fVar3;
  int index_local;
  float freq_local;
  uint8_t chain_local;
  uint8_t divider;
  float pll_freq;
  uint32_t vil_pll_t;
  uint8_t vil_pll [4];
  FILE *pFile_2;
  FILE *pFile_1;
  FILE *pFile;
  uint32_t pll_index;
  uint32_t pll;
  
  divider = freq_high_pll_1393[index].divider;
  pll_00 = freq_high_pll_1393[index].pll_out;
  _Var1 = is_user_mode();
  if (_Var1) {
    fVar3 = get_max_freq();
    _Var1 = check_freq_valid_single((uint)(0.0 < freq) * (int)freq,(uint)(0.0 < fVar3) * (int)fVar3)
    ;
    if (!_Var1) {
      if (3 < log_level) {
        print_crt_time_to_file(log_file,3);
        pFVar2 = fopen(log_file,"a+");
        if (pFVar2 != (FILE *)0x0) {
          fVar3 = get_max_freq();
          fprintf(pFVar2,"%s:%d:%s: User Mode: chain[%d] base freq %f over the max freq %f \n",
                  "driver-btm-soc.c",0x1190,"change_high_pll_test",(uint)chain,(double)freq,
                  (double)fVar3);
        }
        fclose(pFVar2);
      }
      disable_pic_dac(chain);
      dev->chain_exist[chain] = 0;
      dev->chain_num = dev->chain_num + 0xff;
      return -1;
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
          fVar3 = get_max_scanfreq(false);
          fprintf(pFVar2,"%s:%d:%s: Force Mode: chain[%d] base freq %f over the max freq %f \n",
                  "driver-btm-soc.c",0x119c,"change_high_pll_test",(uint)chain,(double)freq,
                  (double)fVar3);
        }
        fclose(pFVar2);
      }
      disable_pic_dac(chain);
      dev->chain_exist[chain] = 0;
      dev->chain_num = dev->chain_num + 0xff;
      return -1;
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
        fprintf(pFVar2,"%s:%d:%s: set freq %d, pll_out %d\n","driver-btm-soc.c",0x11a6,
                "change_high_pll_test",freq_high_pll_1393[index].freq,pll_00);
      }
      fclose(pFVar2);
    }
    index_00 = get_index_from_pll_B1393(pll_00);
    get_plldata_from_index(index_00,vil_pll);
  }
  set_config_BM1393_t(chain,'\0','\x01','p',divider - 1 | 0xf0f0f00);
  set_config_BM1393_t(chain,'\0','\x01','\b',
                      ((uint)vil_pll >> 0x10 & 0xff) << 8 |
                      (int)vil_pll << 0x18 | ((uint)vil_pll >> 8 & 0xff) << 0x10 |
                      (uint)vil_pll >> 0x18);
  set_config_BM1393_t(chain,'\0','\x01','p',divider - 1 | 0xf0f0f00);
  set_config_BM1393_t(chain,'\0','\x01','\b',
                      ((uint)vil_pll >> 0x10 & 0xff) << 8 |
                      (int)vil_pll << 0x18 | ((uint)vil_pll >> 8 & 0xff) << 0x10 |
                      (uint)vil_pll >> 0x18);
  set_unused_pll();
  return 0;
}


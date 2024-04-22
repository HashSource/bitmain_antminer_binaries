
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* WARNING: Unknown calling convention */

void scan_freq_init_info(void)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  int column;
  int chain;
  
  memset(&scanfreq_info,0,0x88d7f0);
  uVar4 = s__log_minertest64_BM1393_btc_asic_00085228._12_4_;
  uVar3 = s__log_minertest64_BM1393_btc_asic_00085228._8_4_;
  uVar2 = s__log_minertest64_BM1393_btc_asic_00085228._4_4_;
  puVar1 = DAT_00031078;
  scanfreq_info.AsicNum = 0x3c;
  scanfreq_info.CoreNum = 0xd0;
  if (test_8pattern == false) {
    scanfreq_info.AsicWorkCount = 0xd0;
  }
  else {
    scanfreq_info.AsicWorkCount = 0x680;
  }
  if (check_column_nonce == false) {
    scanfreq_info.RequiredChainNonce = scanfreq_info.AsicWorkCount * 0x3c;
  }
  else {
    scanfreq_info.RequiredChainNonce = (uint)(scanfreq_info.AsicWorkCount * 0x3c) / 10;
  }
  scanfreq_info.RequiredAsicNonce = scanfreq_info.AsicWorkCount;
  scanfreq_info.PassNonceRate = 0.99;
  *DAT_00031078 = s__log_minertest64_BM1393_btc_asic_00085228._0_4_;
  puVar1[1] = uVar2;
  puVar1[2] = uVar3;
  puVar1[3] = uVar4;
  uVar4 = s__log_minertest64_BM1393_btc_asic_00085228._28_4_;
  uVar3 = s__log_minertest64_BM1393_btc_asic_00085228._24_4_;
  uVar2 = s__log_minertest64_BM1393_btc_asic_00085228._20_4_;
  puVar1[4] = s__log_minertest64_BM1393_btc_asic_00085228._16_4_;
  puVar1[5] = uVar2;
  puVar1[6] = uVar3;
  puVar1[7] = uVar4;
  *(short *)(puVar1 + 8) = (short)ram0x00085248;
  uVar3 = ram0x00085254;
  uVar2 = s__btc_core__0008524c._4_4_;
  puVar1 = DAT_0003107c;
  *DAT_0003107c = s__btc_core__0008524c._0_4_;
  puVar1[1] = uVar2;
  *(short *)(puVar1 + 2) = (short)uVar3;
  *(char *)((int)puVar1 + 10) = (char)((uint)uVar3 >> 0x10);
  scanfreq_info.freq_step = 5;
  scan_base_freq[0] = g_sweep_config_eco.sweep_max_freq;
  scan_base_freq[1] = g_sweep_config_hpf.sweep_max_freq;
  for (chain = 0; chain < 0x10; chain = chain + 1) {
    for (column = 0; column < 10; column = column + 1) {
      scanfreq_info.base_freq_index[chain] = 0;
      scanfreq_info.base_freq[chain] = scan_base_freq[scanfreq_info.base_freq_index[chain]];
      scanfreq_info.freq_index_min[chain][column] = '\0';
      scanfreq_info.freq_index_max[chain][column] = '(';
      scanfreq_info.domain_last_freq_level[chain][column] = '\0';
      scanfreq_info.current_is_pass[chain][column] = true;
    }
  }
  return;
}


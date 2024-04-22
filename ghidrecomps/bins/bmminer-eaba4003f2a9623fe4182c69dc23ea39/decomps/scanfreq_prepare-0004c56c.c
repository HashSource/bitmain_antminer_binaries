
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* WARNING: Unknown calling convention */

int scanfreq_prepare(void)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  int iVar5;
  char tmp42 [2048];
  int ret;
  
  if (((use_syslog) || (opt_log_output)) || (4 < opt_log_level)) {
    tmp42._0_4_ = s_scanfreq_prepare_00078a98._0_4_;
    tmp42._4_4_ = s_scanfreq_prepare_00078a98._4_4_;
    tmp42._8_4_ = s_scanfreq_prepare_00078a98._8_4_;
    tmp42._12_4_ = s_scanfreq_prepare_00078a98._12_4_;
    tmp42[16] = (char)(short)ram0x00078aa8;
    tmp42[17] = (char)((ushort)(short)ram0x00078aa8 >> 8);
    _applog(5,tmp42,false);
  }
  memset(&scanfreq_info,0,0x84a334);
  uVar4 = s__mnt_card_minertest64_BM1393_btc_00078aac._12_4_;
  uVar3 = s__mnt_card_minertest64_BM1393_btc_00078aac._8_4_;
  uVar2 = s__mnt_card_minertest64_BM1393_btc_00078aac._4_4_;
  puVar1 = DAT_0004c71c;
  scanfreq_info.AsicNum = 0x6c;
  scanfreq_info.CoreNum = 0xd0;
  scanfreq_info.AsicWorkCount = 0x680;
  scanfreq_info.RequiredChainNonce = 0x2be00;
  scanfreq_info.PassNonceRate = 98.0;
  scanfreq_info.RequiredAsicNonce = scanfreq_info.AsicWorkCount;
  *DAT_0004c71c = s__mnt_card_minertest64_BM1393_btc_00078aac._0_4_;
  puVar1[1] = uVar2;
  puVar1[2] = uVar3;
  puVar1[3] = uVar4;
  uVar4 = s__mnt_card_minertest64_BM1393_btc_00078aac._28_4_;
  uVar3 = s__mnt_card_minertest64_BM1393_btc_00078aac._24_4_;
  uVar2 = s__mnt_card_minertest64_BM1393_btc_00078aac._20_4_;
  puVar1[4] = s__mnt_card_minertest64_BM1393_btc_00078aac._16_4_;
  puVar1[5] = uVar2;
  puVar1[6] = uVar3;
  puVar1[7] = uVar4;
  uVar2 = ram0x00078ad0;
  puVar1[8] = s__mnt_card_minertest64_BM1393_btc_00078aac._32_4_;
  *(short *)(puVar1 + 9) = (short)uVar2;
  *(char *)((int)puVar1 + 0x26) = (char)((uint)uVar2 >> 0x10);
  uVar3 = ram0x00078adc;
  uVar2 = s__btc_core__00078ad4._4_4_;
  puVar1 = DAT_0004c720;
  *DAT_0004c720 = s__btc_core__00078ad4._0_4_;
  puVar1[1] = uVar2;
  *(short *)(puVar1 + 2) = (short)uVar3;
  *(char *)((int)puVar1 + 10) = (char)((uint)uVar3 >> 0x10);
  scanfreq_init_freq_level();
  set_nonce2_jobid_phy_addr();
  bitmain_axi_init();
  check_chain();
  iVar5 = scanfreq_get_works();
  if (iVar5 < 0) {
    if (((use_syslog != false) || (opt_log_output != false)) || (4 < opt_log_level)) {
      tmp42[0] = s_scanfreq_get_works_failed_00078ae0[0];
      tmp42[1] = s_scanfreq_get_works_failed_00078ae0[1];
      tmp42[2] = s_scanfreq_get_works_failed_00078ae0[2];
      tmp42[3] = s_scanfreq_get_works_failed_00078ae0[3];
      tmp42[4] = s_scanfreq_get_works_failed_00078ae0[4];
      tmp42[5] = s_scanfreq_get_works_failed_00078ae0[5];
      tmp42[6] = s_scanfreq_get_works_failed_00078ae0[6];
      tmp42[7] = s_scanfreq_get_works_failed_00078ae0[7];
      tmp42[8] = s_scanfreq_get_works_failed_00078ae0[8];
      tmp42[9] = s_scanfreq_get_works_failed_00078ae0[9];
      tmp42[10] = s_scanfreq_get_works_failed_00078ae0[10];
      tmp42[11] = s_scanfreq_get_works_failed_00078ae0[11];
      tmp42[12] = s_scanfreq_get_works_failed_00078ae0[12];
      tmp42[13] = s_scanfreq_get_works_failed_00078ae0[13];
      tmp42[14] = s_scanfreq_get_works_failed_00078ae0[14];
      tmp42[15] = s_scanfreq_get_works_failed_00078ae0[15];
      tmp42[16] = s_scanfreq_get_works_failed_00078ae0[16];
      tmp42[17] = s_scanfreq_get_works_failed_00078ae0[17];
      tmp42[18] = s_scanfreq_get_works_failed_00078ae0[18];
      tmp42[19] = s_scanfreq_get_works_failed_00078ae0[19];
      tmp42[20] = s_scanfreq_get_works_failed_00078ae0[20];
      tmp42[21] = s_scanfreq_get_works_failed_00078ae0[21];
      tmp42[22] = s_scanfreq_get_works_failed_00078ae0[22];
      tmp42[23] = s_scanfreq_get_works_failed_00078ae0[23];
      tmp42._24_2_ = (undefined2)ram0x00078af8;
      tmp42[26] = (char)((uint)ram0x00078af8 >> 0x10);
      _applog(5,tmp42,false);
    }
  }
  else {
    iVar5 = 0;
  }
  return iVar5;
}



undefined4 process_config(void)

{
  FILE *pFVar1;
  int iVar2;
  undefined4 uVar3;
  
  conf._40_4_ = Conf._128_4_;
  conf._116_4_ = Conf._212_4_;
  conf._112_4_ = Conf._208_4_;
  if ((Conf._128_4_ == 1) && (Conf._208_4_ == 1)) {
    if (1 < log_level) {
      pFVar1 = fopen(log_file,"a+");
      if (pFVar1 != (FILE *)0x0) {
        fprintf(pFVar1,"%s:%d: Can\'t get temperature from ASIC in FIL mode!\n","driver-bitmain.c",
                0x502);
      }
      fclose(pFVar1);
    }
    uVar3 = 0xffffffff;
  }
  else {
    if ((Conf._128_4_ == 0) && (Conf._208_4_ == 1)) {
      cgpu[2562396] = (undefined)Conf._212_4_;
      cgpu[2562397] = 1;
      cgpu[2562398] = 3;
      if (Conf._228_4_ + Conf._216_4_ + Conf._220_4_ + Conf._224_4_ == 0) {
        if (1 < log_level) {
          pFVar1 = fopen(log_file,"a+");
          if (pFVar1 != (FILE *)0x0) {
            fprintf(pFVar1,"%s:%d: Must set temperature sensor address!\n","driver-bitmain.c",0x51f)
            ;
          }
          fclose(pFVar1);
        }
        return 0xffffffff;
      }
      conf[120] = (undefined)Conf._216_4_;
      conf[121] = (undefined)Conf._220_4_;
      conf[122] = (undefined)Conf._224_4_;
      conf[123] = (undefined)Conf._228_4_;
      conf[124] = Conf[232];
      cgpu[2562399] = Conf[232];
      cgpu[2562400] = Conf[232];
      cgpu[2562401] = Conf[232];
      cgpu[2562402] = Conf[232];
      conf[152] = (undefined)Conf._260_4_;
    }
    conf._128_4_ = Conf._236_4_;
    conf._132_4_ = Conf._240_4_;
    conf._136_4_ = Conf._244_4_;
    conf._140_4_ = Conf._248_4_;
    conf._144_4_ = Conf._252_4_;
    conf._148_4_ = Conf._256_4_;
    conf._92_4_ = Conf._188_4_;
    conf._96_4_ = Conf._192_4_;
    conf._100_4_ = Conf._196_4_;
    conf._104_4_ = Conf._200_4_;
    uVar3 = calculate_core_number(0x72);
    conf._36_4_ = Conf._120_4_;
    conf._44_4_ = Conf._132_4_;
    conf._48_4_ = Conf._136_4_;
    conf._52_4_ = Conf._140_4_;
    conf._56_4_ = Conf._144_4_;
    conf._80_4_ = Conf._184_4_;
    conf._108_4_ = Conf._204_4_;
    conf._60_4_ = Conf._148_4_;
    conf._64_4_ = Conf._152_4_;
    conf._68_4_ = Conf._156_4_;
    conf._72_4_ = Conf._176_4_;
    conf._76_4_ = Conf._180_4_;
    conf._16_4_ = Conf._88_4_;
    CHIP_ADDRESS = 0;
    HASH_RATE = 8;
    PLL_PARAMETER = 0xc;
    START_NONCE_OFFSET = 0x10;
    HASH_COUNTING_NUMBER = 0x14;
    TICKET_MASK = 0x18;
    MISC_CONTROL = 0x1c;
    GENERAL_I2C_COMMAND = 0x20;
    SECURITY_I2C_COMMAND = 0x24;
    SIGNATURE_INPUT = 0x28;
    SIGNATURE_NONCE = 0x2c;
    SIGNATURE_ID = 0x30;
    SECURITY_CONTROL_AND_STATUS = 0x34;
    JOB_INFORMATION = 0x38;
    conf._156_4_ = Conf._264_4_;
    conf._160_4_ = Conf._268_4_;
    conf._164_4_ = Conf._272_4_;
    conf._168_4_ = Conf._276_4_;
    conf._172_4_ = Conf._280_4_;
    conf._176_4_ = Conf._284_4_;
    if ((int)Conf._92_4_ < 1) {
      iVar2 = __aeabi_idiv(0x1000000,uVar3);
      iVar2 = __aeabi_idiv(iVar2 << 1,Conf._88_4_);
      conf._20_4_ = (iVar2 * 0x5f) / 100;
    }
    else {
      conf._20_4_ = Conf._92_4_;
    }
    conf._24_4_ = 0x1a;
    if (((int)Conf._72_4_ < 0x1389) && (0 < (int)Conf._72_4_)) {
      conf._0_4_ = Conf._72_4_;
    }
    else if (1 < log_level) {
      pFVar1 = fopen(log_file,"a+");
      if (pFVar1 != (FILE *)0x0) {
        fprintf(pFVar1,"%s:%d: $$$$Config argument DataCount:%d err\n","driver-bitmain.c",0x58a,
                Conf._72_4_);
      }
      fclose(pFVar1);
    }
    if (((int)conf._0_4_ < (int)Conf._76_4_) || ((int)Conf._76_4_ < 0)) {
      if (1 < log_level) {
        pFVar1 = fopen(log_file,"a+");
        if (pFVar1 != (FILE *)0x0) {
          fprintf(pFVar1,"%s:%d: $$$$Config argument DataCount:%d err\n","driver-bitmain.c",0x591,
                  Conf._72_4_);
        }
        fclose(pFVar1);
      }
    }
    else {
      conf._4_4_ = Conf._76_4_;
    }
    if (((int)conf._0_4_ < (int)Conf._80_4_) || ((int)Conf._80_4_ < 0)) {
      if (1 < log_level) {
        pFVar1 = fopen(log_file,"a+");
        if (pFVar1 != (FILE *)0x0) {
          fprintf(pFVar1,"%s:%d: $$$$Config argument DataCount:%d err\n","driver-bitmain.c",0x598,
                  Conf._72_4_);
        }
        fclose(pFVar1);
      }
    }
    else {
      conf._8_4_ = Conf._80_4_;
    }
    if (((int)conf._0_4_ < (int)Conf._84_4_) || ((int)Conf._84_4_ < 0)) {
      if (1 < log_level) {
        pFVar1 = fopen(log_file,"a+");
        if (pFVar1 != (FILE *)0x0) {
          fprintf(pFVar1,"%s:%d: $$$$Config argument DataCount:%d err\n","driver-bitmain.c",0x59f,
                  Conf._72_4_);
        }
        fclose(pFVar1);
      }
    }
    else {
      conf._12_4_ = Conf._84_4_;
    }
    uVar3 = 0;
  }
  return uVar3;
}


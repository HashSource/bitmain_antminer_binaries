
/* WARNING: Type propagation algorithm not settling */

undefined4 process_config(void)

{
  undefined4 uVar1;
  undefined4 uVar2;
  int iVar3;
  char local_820 [36];
  undefined4 local_7fc;
  char acStack_7f8 [4];
  undefined2 local_7f4;
  
  conf._52_4_ = Conf._68_4_;
  conf._132_4_ = Conf._156_4_;
  conf._128_4_ = Conf._152_4_;
  if (Conf._68_4_ == 1) {
    if (Conf._152_4_ == 1) {
      if (((use_syslog != '\0') || (opt_log_output != '\0')) || (2 < opt_log_level)) {
        builtin_strncpy(local_820,"Can\'t get temperature from ASIC in F",0x24);
        local_7fc._0_1_ = 'I';
        local_7fc._1_1_ = 'L';
        local_7fc._2_1_ = ' ';
        local_7fc._3_1_ = 'm';
        builtin_strncpy(acStack_7f8,"ode!",4);
        local_7f4 = 10;
        _applog(3,local_820,0);
      }
      return 0xffffffff;
    }
  }
  else if (Conf._152_4_ == 1 && Conf._68_4_ == 0) {
    DAT_002f457c = (undefined1)Conf._156_4_;
    DAT_002f457d = 1;
    DAT_002f457e = 3;
    if (Conf._160_4_ + Conf._164_4_ + Conf._168_4_ + Conf._172_4_ == 0) {
      if (((use_syslog == '\0') && (opt_log_output == '\0')) && (opt_log_level < 3)) {
        DAT_002f457d = 1;
        DAT_002f457e = 3;
        conf._52_4_ = Conf._68_4_;
        conf._128_4_ = Conf._152_4_;
        conf._132_4_ = Conf._156_4_;
        return 0xffffffff;
      }
      builtin_strncpy(local_820,"Must set temperature sensor address!",0x24);
      local_7fc = CONCAT22(local_7fc._2_2_,10);
      _applog(3,local_820,0);
      return 0xffffffff;
    }
    DAT_002f457f = Conf[0xb0];
    conf[0x8b] = (undefined1)Conf._172_4_;
    conf[0x88] = (undefined1)Conf._160_4_;
    conf[0x89] = (undefined1)Conf._164_4_;
    conf[0x8a] = (undefined1)Conf._168_4_;
    conf[0xa8] = (undefined1)Conf._204_4_;
    conf[0xa9] = (undefined1)Conf._208_4_;
    DAT_002f4580 = DAT_002f457f;
    DAT_002f4581 = DAT_002f457f;
    DAT_002f4582 = DAT_002f457f;
    conf[0x8c] = DAT_002f457f;
  }
  conf._144_4_ = Conf._180_4_;
  conf._148_4_ = Conf._184_4_;
  conf._152_4_ = Conf._188_4_;
  conf._156_4_ = Conf._192_4_;
  conf._160_4_ = Conf._196_4_;
  conf._164_4_ = Conf._200_4_;
  conf._108_4_ = Conf._132_4_;
  conf._112_4_ = Conf._136_4_;
  conf._116_4_ = Conf._140_4_;
  conf._120_4_ = Conf._144_4_;
  conf._56_4_ = 0x56b;
  Conf._44_4_ = 3;
  conf._40_4_ = 3;
  conf._16_4_ = Conf._48_4_;
  conf._44_4_ = 0x80;
  uVar2 = calculate_core_number();
  uVar1 = Conf._24_4_;
  conf._72_4_ = Conf._88_4_;
  conf._48_4_ = Conf._60_4_;
  conf._60_4_ = Conf._76_4_;
  conf._64_4_ = Conf._80_4_;
  conf._80_4_ = Conf._96_4_;
  conf._68_4_ = Conf._84_4_;
  conf._96_4_ = Conf._128_4_;
  conf._124_4_ = Conf._148_4_;
  conf._76_4_ = Conf._92_4_;
  conf._88_4_ = Conf._120_4_;
  conf._84_4_ = Conf._100_4_;
  conf._92_4_ = Conf._124_4_;
  conf._172_4_ = Conf._212_4_;
  conf._20_4_ = Conf._24_4_;
  conf._176_4_ = Conf._216_4_;
  conf._180_4_ = Conf._220_4_;
  conf._184_4_ = Conf._224_4_;
  conf._188_4_ = Conf._228_4_;
  conf._192_4_ = Conf._232_4_;
  if ((int)Conf._28_4_ < 1) {
    iVar3 = __aeabi_idiv(0x1000000,uVar2);
    iVar3 = __aeabi_idiv(conf._40_4_ * iVar3,uVar1);
    conf._24_4_ = (iVar3 * 0x5f) / 100;
  }
  else {
    conf._24_4_ = Conf._28_4_;
  }
  conf._28_4_ = 0x1a;
  if (Conf._8_4_ - 1 < 5000) {
    conf._0_4_ = Conf._8_4_;
LAB_0002bcb2:
    if ((int)Conf._12_4_ <= (int)conf._0_4_ && -1 < (int)Conf._12_4_) goto LAB_0002bcc4;
    if ((use_syslog != '\0') || (opt_log_output != '\0')) {
LAB_0002bd7a:
      snprintf(local_820,0x800,"$$$$Config argument DataCount:%d err\n",Conf._8_4_);
      _applog(3,local_820,0);
      goto LAB_0002bcc8;
    }
LAB_0002bf6c:
    if (2 < opt_log_level) goto LAB_0002bd7a;
    if ((int)conf._0_4_ < (int)Conf._16_4_ || (int)Conf._16_4_ < 0) goto LAB_0002bf96;
LAB_0002bcda:
    conf._8_4_ = Conf._16_4_;
LAB_0002bcde:
    if ((int)Conf._20_4_ <= (int)conf._0_4_ && -1 < (int)Conf._20_4_) {
      conf._12_4_ = Conf._20_4_;
      return 0;
    }
    if ((use_syslog != '\0') || (opt_log_output != '\0')) goto LAB_0002be0a;
  }
  else {
    if (((use_syslog != '\0') || (opt_log_output != '\0')) || (2 < opt_log_level)) {
      snprintf(local_820,0x800,"$$$$Config argument DataCount:%d err\n");
      _applog(3,local_820,0);
      goto LAB_0002bcb2;
    }
    if ((int)conf._0_4_ < (int)Conf._12_4_ || (int)Conf._12_4_ < 0) goto LAB_0002bf6c;
LAB_0002bcc4:
    conf._4_4_ = Conf._12_4_;
LAB_0002bcc8:
    if ((int)Conf._16_4_ <= (int)conf._0_4_ && -1 < (int)Conf._16_4_) goto LAB_0002bcda;
    if ((use_syslog != '\0') || (opt_log_output != '\0')) {
LAB_0002bdbc:
      snprintf(local_820,0x800,"$$$$Config argument DataCount:%d err\n",Conf._8_4_);
      _applog(3,local_820,0);
      goto LAB_0002bcde;
    }
LAB_0002bf96:
    if (2 < opt_log_level) goto LAB_0002bdbc;
    if ((int)Conf._20_4_ <= (int)conf._0_4_ && -1 < (int)Conf._20_4_) {
      conf._12_4_ = Conf._20_4_;
      return 0;
    }
  }
  if (opt_log_level < 3) {
    return 0;
  }
LAB_0002be0a:
  snprintf(local_820,0x800,"$$$$Config argument DataCount:%d err\n",Conf._8_4_);
  _applog(3,local_820,0);
  return 0;
}


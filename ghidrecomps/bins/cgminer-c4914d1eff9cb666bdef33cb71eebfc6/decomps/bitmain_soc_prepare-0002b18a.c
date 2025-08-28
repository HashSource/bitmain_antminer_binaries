
_Bool bitmain_soc_prepare(thr_info *thr)

{
  uint8_t uVar1;
  uint16_t uVar2;
  uint8_t uVar6;
  uint16_t uVar7;
  int iVar5;
  FILE *__stream;
  undefined1 uVar8;
  undefined1 uVar21;
  undefined3 uVar22;
  uint8_t uVar9;
  uint8_t uVar10;
  uint8_t uVar11;
  uint16_t uVar23;
  cglock_t *lock;
  uint16_t uVar25;
  char *pcVar12;
  init_config config;
  undefined1 auVar13 [20];
  undefined1 auVar14 [12];
  undefined1 auVar15 [11];
  unkbyte10 Var16;
  unkbyte9 Var17;
  undefined4 uVar26;
  undefined5 uVar18;
  undefined1 in_stack_00000000 [16];
  undefined4 uVar19;
  undefined4 uVar20;
  thr_info *thr_local;
  init_config soc_config;
  FILE *pFile;
  int ret;
  bitmain_soc_info *info;
  cgpu_info *bitmain_soc;
  undefined2 uVar3;
  undefined4 uVar4;
  undefined4 uVar24;
  
  lock = (cglock_t *)thr->cgpu->device_data;
  lock[0xb].rwlock.__data.__cur_writer = (int)thr;
  _mutex_init((pthread_mutex_t *)((int)&lock[0xc].mutex + 4),"driver-btm-soc.c",
              "bitmain_soc_prepare",0x1cdd);
  _cglock_init(lock,"driver-btm-soc.c","bitmain_soc_prepare",0x1cde);
  _cglock_init((cglock_t *)((int)&lock[0x10].rwlock + 0x1c),"driver-btm-soc.c","bitmain_soc_prepare"
               ,0x1cdf);
  _cglock_init((cglock_t *)((int)&lock[0x31].rwlock + 0x1c),"driver-btm-soc.c","bitmain_soc_prepare"
               ,0x1ce0);
  _cglock_init((cglock_t *)((int)&lock[0x52].rwlock + 0x1c),"driver-btm-soc.c","bitmain_soc_prepare"
               ,0x1ce1);
  memset(&soc_config,0,0x20);
  soc_config.token_type = 'Q';
  soc_config.length = 0x1a;
  soc_config._4_1_ = soc_config._4_1_ & 0xfd | 1 | (opt_bitmain_fan_ctrl & 1U) << 1 | 0xfc;
  soc_config._5_4_ = soc_config._5_4_ | 7;
  soc_config.asic_num = '<';
  soc_config.fan_pwm_percent = (uint8_t)opt_bitmain_fan_pwm;
  soc_config.temperature = 'P';
  soc_config.voltage = (uint16_t)opt_bitmain_soc_voltage;
  soc_config.frequency = (uint16_t)opt_bitmain_soc_freq;
  soc_config.chain_check_time_integer = '\n';
  soc_config.chain_check_time_fractions = '\n';
  soc_config.chip_address = '\x04';
  soc_config.chain_min_freq = 400;
  soc_config.chain_max_freq = 600;
  uVar2 = CRC16(&soc_config.token_type,0x1e);
  soc_config.crc = uVar2;
  uVar6 = soc_config.version;
  uVar1 = soc_config.token_type;
  uVar3 = CONCAT11(uVar6,uVar1);
  uVar7 = soc_config.length;
  uVar4 = CONCAT22(uVar7,uVar3);
  uVar8 = soc_config._4_1_;
  uVar18 = CONCAT14(uVar8,uVar4);
  uVar21 = soc_config._5_1_;
  uVar22._1_1_ = soc_config.reserved2[0];
  uVar22._2_1_ = soc_config.reserved2[1];
  register0x00000028 = soc_config.chain_num;
  Var17 = CONCAT45(uVar26,uVar18);
  uVar9 = soc_config.asic_num;
  Var16 = CONCAT19(uVar9,Var17);
  uVar10 = soc_config.fan_pwm_percent;
  auVar15 = CONCAT110(uVar10,Var16);
  uVar11 = soc_config.temperature;
  auVar14 = CONCAT111(uVar11,auVar15);
  uVar23 = soc_config.frequency;
  register0x0000002e = soc_config.voltage;
  auVar13 = CONCAT164(in_stack_00000000,uVar24);
  config = (init_config)CONCAT2012(auVar13,auVar14);
  uVar19 = soc_config._24_4_;
  uVar20 = soc_config._28_4_;
  iVar5 = bitmain_soc_init(config);
  if (3 < log_level) {
    print_crt_time_to_file(log_file,3);
    __stream = fopen(log_file,"a+");
    if (__stream != (FILE *)0x0) {
      if (iVar5 == 0) {
        pcVar12 = "success";
      }
      else {
        pcVar12 = "failed";
      }
      fprintf(__stream,"%s:%d:%s: bitmain soc init %s.\n","driver-btm-soc.c",0x1d07,
              "bitmain_soc_prepare",pcVar12,uVar19,uVar20);
    }
    fclose(__stream);
  }
  return true;
}


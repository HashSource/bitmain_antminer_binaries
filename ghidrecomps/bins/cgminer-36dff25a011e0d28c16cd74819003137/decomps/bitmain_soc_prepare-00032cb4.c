
_Bool bitmain_soc_prepare(thr_info *thr)

{
  uint8_t uVar1;
  uint16_t uVar2;
  uint8_t uVar5;
  uint16_t uVar6;
  undefined1 uVar7;
  undefined1 uVar8;
  uint8_t uVar21;
  uint8_t uVar23;
  uint8_t uVar9;
  uint8_t uVar10;
  uint8_t uVar11;
  uint8_t uVar12;
  uint16_t uVar24;
  cglock_t *lock;
  uint16_t uVar26;
  undefined8 uVar13;
  init_config config;
  undefined1 auVar14 [20];
  undefined1 auVar15 [12];
  undefined1 auVar16 [11];
  unkbyte10 Var17;
  unkbyte9 Var18;
  undefined6 uVar19;
  undefined5 uVar20;
  undefined1 in_stack_00000000 [16];
  thr_info *thr_local;
  init_config soc_config;
  bitmain_soc_info *info;
  cgpu_info *bitmain_soc;
  undefined2 uVar3;
  undefined4 uVar4;
  uint8_t auVar22 [2];
  undefined4 uVar25;
  
  lock = (cglock_t *)thr->cgpu->device_data;
  lock[0xb].rwlock.__data.__cur_writer = (int)thr;
  _mutex_init((pthread_mutex_t *)((int)&lock[0xc].mutex + 4),"driver-btm-soc.c",
              "bitmain_soc_prepare",0x2094);
  _cglock_init(lock,"driver-btm-soc.c","bitmain_soc_prepare",0x2095);
  _cglock_init((cglock_t *)((int)&lock[0x10].rwlock + 0x1c),"driver-btm-soc.c","bitmain_soc_prepare"
               ,0x2096);
  _cglock_init((cglock_t *)((int)&lock[0x31].rwlock + 0x1c),"driver-btm-soc.c","bitmain_soc_prepare"
               ,0x2097);
  _cglock_init((cglock_t *)((int)&lock[0x52].rwlock + 0x1c),"driver-btm-soc.c","bitmain_soc_prepare"
               ,0x2098);
  memset(&soc_config,0,0x20);
  soc_config.token_type = 'Q';
  soc_config.length = 0x1a;
  soc_config._4_1_ = 0xff;
  soc_config._5_1_ = soc_config._5_1_ | 7;
  soc_config.chain_num = '\t';
  soc_config.asic_num = '6';
  soc_config.fan_pwm_percent = 'd';
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
  uVar5 = soc_config.version;
  uVar1 = soc_config.token_type;
  uVar3 = CONCAT11(uVar5,uVar1);
  uVar6 = soc_config.length;
  uVar4 = CONCAT22(uVar6,uVar3);
  uVar7 = soc_config._4_1_;
  uVar20 = CONCAT14(uVar7,uVar4);
  uVar8 = soc_config._5_1_;
  uVar19 = CONCAT15(uVar8,uVar20);
  uVar21 = soc_config.reserved2[0];
  register0x00000027 = soc_config.reserved2[1];
  uVar13 = CONCAT26(auVar22,uVar19);
  uVar9 = soc_config.chain_num;
  Var18 = CONCAT18(uVar9,uVar13);
  uVar10 = soc_config.asic_num;
  Var17 = CONCAT19(uVar10,Var18);
  uVar11 = soc_config.fan_pwm_percent;
  auVar16 = CONCAT110(uVar11,Var17);
  uVar12 = soc_config.temperature;
  auVar15 = CONCAT111(uVar12,auVar16);
  uVar24 = soc_config.frequency;
  register0x0000002e = soc_config.voltage;
  auVar14 = CONCAT164(in_stack_00000000,uVar25);
  config = (init_config)CONCAT2012(auVar14,auVar15);
  bitmain_soc_init(config);
  return true;
}


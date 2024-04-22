
/* WARNING: Variable defined which should be unmapped: thr-local */

_Bool bitmain_soc_prepare(thr_info *thr)

{
  init_config config;
  uint16_t uVar1;
  cglock_t *lock;
  undefined4 uStack_40;
  thr_info *thr_local;
  init_config soc_config;
  bitmain_soc_info *info;
  cgpu_info *bitmain_soc;
  
  lock = (cglock_t *)thr->cgpu->device_data;
  lock[0xb].rwlock.__data.__writer = (int)thr;
  _mutex_init((pthread_mutex_t *)((int)&lock[0xc].mutex + 4),"driver-btm-soc.c",
              "bitmain_soc_prepare",0x2dd3);
  _cglock_init(lock,"driver-btm-soc.c","bitmain_soc_prepare",0x2dd4);
  _cglock_init((cglock_t *)((int)&lock[0x11].mutex + 4),"driver-btm-soc.c","bitmain_soc_prepare",
               0x2dd5);
  _cglock_init((cglock_t *)((int)&lock[0x32].mutex + 0xc),"driver-btm-soc.c","bitmain_soc_prepare",
               0x2dd6);
  _cglock_init((cglock_t *)((int)&lock[0x53].mutex + 0x14),"driver-btm-soc.c","bitmain_soc_prepare",
               0x2dd7);
  soc_config.version = '\0';
  soc_config.reserved2[0] = '\0';
  soc_config.reserved2[1] = '\0';
  soc_config.reg_data = 0;
  soc_config.token_type = 'Q';
  soc_config.length = 0x1a;
  soc_config._4_1_ = (byte)((opt_bitmain_fan_ctrl & 1) << 1) | 0xfd;
  soc_config._5_1_ = 7;
  soc_config._8_3_ = CONCAT12((uchar)opt_bitmain_fan_pwm,0x3609);
  soc_config.temperature = 'P';
  soc_config._12_3_ = CONCAT12('\a',(uint16_t)opt_bitmain_soc_freq);
  soc_config.voltage[1] = '%';
  soc_config.chain_check_time_integer = '\n';
  soc_config.chain_check_time_fractions = '\n';
  soc_config.timeout_data_integer = '\0';
  soc_config.timeout_data_fractions = '\0';
  soc_config.chip_address = '\x04';
  soc_config.reg_address = '\0';
  soc_config.chain_min_freq = 400;
  soc_config.chain_max_freq = 600;
  soc_config.crc = 0;
  uVar1 = CRC16(&soc_config.token_type,0x1e);
  soc_config.crc = uVar1;
  config._4_4_ = soc_config.reg_data;
  config._0_4_ = soc_config._16_4_;
  config._8_4_ = soc_config._24_4_;
  config._12_4_ = soc_config._28_4_;
  config._16_4_ = uStack_40;
  config.reg_data = (uint)thr;
  config.chip_address = soc_config.token_type;
  config.reg_address = soc_config.version;
  config.chain_min_freq = soc_config.length;
  config.chain_max_freq._0_1_ = soc_config._4_1_;
  config.chain_max_freq._1_1_ = soc_config._5_1_;
  config.crc._0_1_ = soc_config.reserved2[0];
  config.crc._1_1_ = soc_config.reserved2[1];
  bitmain_soc_init(config);
  return true;
}


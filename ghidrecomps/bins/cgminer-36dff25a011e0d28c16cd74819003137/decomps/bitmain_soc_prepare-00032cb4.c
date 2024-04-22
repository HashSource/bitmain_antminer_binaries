
/* WARNING: Variable defined which should be unmapped: thr-local */

_Bool bitmain_soc_prepare(thr_info *thr)

{
  init_config config;
  uint16_t uVar1;
  cglock_t *lock;
  undefined4 uStack_38;
  thr_info *thr_local;
  init_config soc_config;
  bitmain_soc_info *info;
  cgpu_info *bitmain_soc;
  
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
  soc_config.frequency = (uint16_t)opt_bitmain_soc_freq;
  soc_config.voltage = (uint16_t)opt_bitmain_soc_voltage;
  soc_config.chain_check_time_integer = '\n';
  soc_config.chain_check_time_fractions = '\n';
  soc_config.chip_address = '\x04';
  soc_config.chain_min_freq = 400;
  soc_config.chain_max_freq = 600;
  uVar1 = CRC16(&soc_config.token_type,0x1e);
  soc_config.crc = uVar1;
  config._4_4_ = soc_config.reg_data;
  config._0_4_ = soc_config._16_4_;
  config._8_4_ = soc_config._24_4_;
  config.frequency = soc_config.chain_max_freq;
  config.voltage = soc_config.crc;
  config._16_4_ = uStack_38;
  config.reg_data = (uint32_t)thr;
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


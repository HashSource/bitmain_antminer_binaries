
/* WARNING: Variable defined which should be unmapped: c5_config */
/* WARNING: Unknown calling convention */

_Bool bitmain_c5_prepare(thr_info *thr)

{
  byte bVar1;
  init_config config;
  thr_info **pptVar2;
  _func_void_ptr_void_ptr *start;
  int iVar3;
  uint uVar4;
  thr_info *thr_00;
  int *piVar5;
  cgpu_info **ppcVar6;
  char *file;
  char *file_00;
  char *file_01;
  char *file_02;
  char *file_03;
  uint uVar7;
  char *in_r2;
  init_config *piVar8;
  cgpu_info *line;
  uint uVar9;
  pthread_mutex_t *__mutex;
  bitmain_c5_info *info;
  init_config c5_config;
  char tmp42 [2048];
  
  line = thr->cgpu;
  __mutex = (pthread_mutex_t *)line->device_data;
  *(thr_info **)((int)__mutex + 0x19c) = thr;
  iVar3 = pthread_mutex_init((pthread_mutex_t *)((int)__mutex + 0x1a4),(pthread_mutexattr_t *)0x0);
  if (iVar3 != 0) {
    _mutex_init((pthread_mutex_t *)0x2db1,file,in_r2,(int)line);
  }
  iVar3 = pthread_mutex_init(__mutex,(pthread_mutexattr_t *)0x0);
  if (iVar3 != 0) {
    _mutex_init((pthread_mutex_t *)0x2db2,file_00,in_r2,(int)line);
  }
  iVar3 = pthread_rwlock_init((pthread_rwlock_t *)(__mutex + 1),(pthread_rwlockattr_t *)0x0);
  if (iVar3 != 0) {
    ppcVar6 = (cgpu_info **)__errno_location();
    line = *ppcVar6;
    snprintf(tmp42,0x800,DAT_00038704,line,DAT_000386fc,DAT_00038700,0x2db2);
    in_r2 = (char *)0x1;
    _applog(3,tmp42,true);
    _quit(1);
  }
  iVar3 = pthread_mutex_init((pthread_mutex_t *)((int)__mutex + 0x2b4),(pthread_mutexattr_t *)0x0);
  if (iVar3 != 0) {
    _mutex_init((pthread_mutex_t *)0x2db3,file_01,in_r2,(int)line);
  }
  iVar3 = pthread_rwlock_init((pthread_rwlock_t *)((int)__mutex + 0x2cc),(pthread_rwlockattr_t *)0x0
                             );
  if (iVar3 != 0) {
    ppcVar6 = (cgpu_info **)__errno_location();
    line = *ppcVar6;
    snprintf(tmp42,0x800,DAT_00038704,line,DAT_000386fc,DAT_00038700,0x2db3);
    in_r2 = (char *)0x1;
    _applog(3,tmp42,true);
    _quit(1);
  }
  iVar3 = pthread_mutex_init((pthread_mutex_t *)((int)__mutex + 0x9ec),(pthread_mutexattr_t *)0x0);
  if (iVar3 != 0) {
    _mutex_init((pthread_mutex_t *)0x2db4,file_02,in_r2,(int)line);
  }
  iVar3 = pthread_rwlock_init((pthread_rwlock_t *)((int)__mutex + 0xa04),(pthread_rwlockattr_t *)0x0
                             );
  if (iVar3 != 0) {
    ppcVar6 = (cgpu_info **)__errno_location();
    line = *ppcVar6;
    snprintf(tmp42,0x800,DAT_00038704,line,DAT_000386fc,DAT_00038700,0x2db4);
    in_r2 = (char *)0x1;
    _applog(3,tmp42,true);
    _quit(1);
  }
  iVar3 = pthread_mutex_init((pthread_mutex_t *)((int)__mutex + 0x1124),(pthread_mutexattr_t *)0x0);
  if (iVar3 != 0) {
    _mutex_init((pthread_mutex_t *)0x2db5,file_03,in_r2,(int)line);
  }
  iVar3 = pthread_rwlock_init((pthread_rwlock_t *)((int)__mutex + 0x113c),
                              (pthread_rwlockattr_t *)0x0);
  if (iVar3 != 0) {
    piVar5 = __errno_location();
    snprintf(tmp42,0x800,DAT_00038704,*piVar5,DAT_000386fc,DAT_00038700,0x2db5);
    _applog(3,tmp42,true);
    _quit(1);
  }
  pptVar2 = DAT_000386dc;
  piVar8 = &c5_config;
  uVar7 = 0xff;
  c5_config._4_1_ = (byte)((*(byte *)(DAT_000386d0 + 0x981) & 1) << 1) | 0xfd;
  c5_config.reserved2[0] = '\0';
  c5_config.reserved2[1] = '\0';
  c5_config.reg_data = 0;
  uVar9 = 0x51;
  c5_config.version = '\0';
  uVar4 = 0xff;
  c5_config.fan_pwm_percent = (uchar)*(undefined4 *)(DAT_000386d0 + 0x984);
  c5_config.length = 0x1a;
  c5_config._5_1_ = 7;
  c5_config.chain_num = '\t';
  c5_config.asic_num = '6';
  c5_config.temperature = 'P';
  c5_config.frequency = (uint16_t)*(undefined4 *)(DAT_000386d4 + 0x94);
  c5_config.voltage[0] = '\a';
  c5_config.voltage[1] = '%';
  c5_config.chip_address = '\x04';
  c5_config.reg_address = '\0';
  c5_config.chain_min_freq = 400;
  c5_config.chain_max_freq = 600;
  c5_config.crc = 0;
  c5_config.token_type = 'Q';
  c5_config.chain_check_time_integer = '\n';
  c5_config.chain_check_time_fractions = '\n';
  c5_config.timeout_data_integer = '\0';
  c5_config.timeout_data_fractions = '\0';
  while( true ) {
    iVar3 = (uVar9 ^ uVar4) + DAT_000386d8;
    uVar4 = uVar7 ^ *(byte *)(iVar3 + 0x7b8);
    bVar1 = *(byte *)(iVar3 + 0x8b8);
    uVar7 = (uint)bVar1;
    if (piVar8 == (init_config *)((int)&c5_config.chain_max_freq + 1)) break;
    piVar8 = (init_config *)&piVar8->version;
    uVar9 = (uint)*(byte *)piVar8;
  }
  c5_config.crc = (ushort)uVar4 | (ushort)bVar1 << 8;
  c5_config.chain_max_freq = 600;
  config.chain_num = '\x04';
  config.asic_num = '\0';
  config.fan_pwm_percent = 0x90;
  config.temperature = '\x01';
  config.token_type = '\n';
  config.version = '\n';
  config.length = 0;
  config._4_2_ = 0;
  config.reserved2[0] = '\0';
  config.reserved2[1] = '\0';
  config._12_4_ = c5_config._28_4_;
  config.chain_check_time_integer = 0x51;
  config.chain_check_time_fractions = 0;
  config.timeout_data_integer = '\x1a';
  config.timeout_data_fractions = '\0';
  config.reg_data._0_1_ = c5_config._4_1_;
  config.reg_data._1_1_ = 7;
  config.reg_data._2_2_ = 0;
  config.chip_address = 9;
  config.reg_address = 0x36;
  config.chain_min_freq._0_1_ = c5_config.fan_pwm_percent;
  config.chain_min_freq._1_1_ = 0x50;
  config.chain_max_freq = c5_config.frequency;
  config.crc._0_1_ = 7;
  config.crc._1_1_ = 0x25;
  bitmain_c5_init(config);
  thr_00 = (thr_info *)calloc(1,0x40);
  start = DAT_000386e0;
  *pptVar2 = thr_00;
  iVar3 = thr_info_create(thr_00,(pthread_attr_t *)0x0,start,thr_00);
  if (((iVar3 != 0) && (*DAT_000386e4 != '\0')) &&
     ((*DAT_000386e8 != '\0' || ((*DAT_000386ec != '\0' || (6 < *DAT_000386f8)))))) {
    snprintf(tmp42,0x800,DAT_000386f0,DAT_000386f4);
    _applog(7,tmp42,false);
  }
  return true;
}


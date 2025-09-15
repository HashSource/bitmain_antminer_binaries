
/* WARNING: Unknown calling convention */

_Bool bitmain_c5_prepare(thr_info *thr)

{
  byte bVar1;
  uint5 uVar2;
  uchar uVar25;
  int iVar3;
  uint uVar4;
  int *piVar5;
  undefined4 uVar26;
  undefined1 uVar7;
  uchar uVar27;
  char *file;
  char *file_00;
  char *file_01;
  char *file_02;
  char *file_03;
  uint uVar6;
  uchar uVar29;
  uchar uVar8;
  uchar uVar10;
  uchar uVar11;
  char *func;
  char *func_00;
  char *func_01;
  char *func_02;
  char *func_03;
  init_config *piVar9;
  uchar uVar12;
  uint16_t uVar30;
  uchar uVar32;
  int line;
  int line_00;
  int line_01;
  int line_02;
  int line_03;
  uint uVar13;
  uchar uVar34;
  pthread_mutex_t *__mutex;
  ulonglong uVar14;
  init_config config;
  undefined1 auVar15 [20];
  undefined1 auVar16 [12];
  undefined1 auVar17 [11];
  unkbyte10 Var18;
  unkbyte9 Var19;
  uint6 uVar20;
  undefined5 uVar35;
  undefined1 in_stack_00000000 [16];
  undefined4 uVar21;
  undefined4 uVar22;
  undefined4 uVar23;
  undefined4 uVar24;
  init_config c5_config;
  char tmp42 [2048];
  uchar auVar28 [2];
  undefined4 uVar31;
  undefined2 uVar33;
  
  __mutex = (pthread_mutex_t *)thr->cgpu->device_data;
  *(thr_info **)((int)__mutex + 0x19c) = thr;
  iVar3 = pthread_mutex_init((pthread_mutex_t *)((int)__mutex + 0x1a4),(pthread_mutexattr_t *)0x0);
  if (iVar3 != 0) {
    _mutex_init((pthread_mutex_t *)0x2db1,file,func,line);
  }
  iVar3 = pthread_mutex_init(__mutex,(pthread_mutexattr_t *)0x0);
  if (iVar3 != 0) {
    _mutex_init((pthread_mutex_t *)0x2db2,file_00,func_00,line_00);
  }
  iVar3 = pthread_rwlock_init((pthread_rwlock_t *)(__mutex + 1),(pthread_rwlockattr_t *)0x0);
  if (iVar3 != 0) {
    piVar5 = __errno_location();
    snprintf(tmp42,0x800,"Failed to pthread_rwlock_init errno=%d in %s %s():%d",*piVar5,
             "driver-btm-c5.c","bitmain_c5_prepare",0x2db2);
    _applog(3,tmp42,true);
    _quit(1);
  }
  iVar3 = pthread_mutex_init((pthread_mutex_t *)((int)__mutex + 0x2b4),(pthread_mutexattr_t *)0x0);
  if (iVar3 != 0) {
    _mutex_init((pthread_mutex_t *)0x2db3,file_01,func_01,line_01);
  }
  iVar3 = pthread_rwlock_init((pthread_rwlock_t *)((int)__mutex + 0x2cc),(pthread_rwlockattr_t *)0x0
                             );
  if (iVar3 != 0) {
    piVar5 = __errno_location();
    snprintf(tmp42,0x800,"Failed to pthread_rwlock_init errno=%d in %s %s():%d",*piVar5,
             "driver-btm-c5.c","bitmain_c5_prepare",0x2db3);
    _applog(3,tmp42,true);
    _quit(1);
  }
  iVar3 = pthread_mutex_init((pthread_mutex_t *)((int)__mutex + 0x9ec),(pthread_mutexattr_t *)0x0);
  if (iVar3 != 0) {
    _mutex_init((pthread_mutex_t *)0x2db4,file_02,func_02,line_02);
  }
  iVar3 = pthread_rwlock_init((pthread_rwlock_t *)((int)__mutex + 0xa04),(pthread_rwlockattr_t *)0x0
                             );
  if (iVar3 != 0) {
    piVar5 = __errno_location();
    snprintf(tmp42,0x800,"Failed to pthread_rwlock_init errno=%d in %s %s():%d",*piVar5,
             "driver-btm-c5.c","bitmain_c5_prepare",0x2db4);
    _applog(3,tmp42,true);
    _quit(1);
  }
  iVar3 = pthread_mutex_init((pthread_mutex_t *)((int)__mutex + 0x1124),(pthread_mutexattr_t *)0x0);
  if (iVar3 != 0) {
    _mutex_init((pthread_mutex_t *)0x2db5,file_03,func_03,line_03);
  }
  iVar3 = pthread_rwlock_init((pthread_rwlock_t *)((int)__mutex + 0x113c),
                              (pthread_rwlockattr_t *)0x0);
  if (iVar3 != 0) {
    piVar5 = __errno_location();
    snprintf(tmp42,0x800,"Failed to pthread_rwlock_init errno=%d in %s %s():%d",*piVar5,
             "driver-btm-c5.c","bitmain_c5_prepare",0x2db5);
    _applog(3,tmp42,true);
    _quit(1);
  }
  piVar9 = &c5_config;
  uVar6 = 0xff;
  bVar1 = (opt_bitmain_fan_ctrl & 1U) << 1;
  c5_config.reserved2[0] = '\0';
  c5_config.reserved2[1] = '\0';
  c5_config.reg_data = 0;
  uVar13 = 0x51;
  c5_config.version = '\0';
  uVar4 = 0xff;
  c5_config._4_1_ = bVar1 | 0xfd;
  c5_config.fan_pwm_percent = (uchar)opt_bitmain_fan_pwm;
  c5_config.length = 0x1a;
  c5_config._5_1_ = 7;
  c5_config.chain_num = '\t';
  c5_config.asic_num = '6';
  c5_config.temperature = 'P';
  c5_config.voltage[0] = '\a';
  c5_config.frequency = (uint16_t)opt_bitmain_c5_freq;
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
    uVar13 = uVar13 ^ uVar4;
    uVar4 = uVar6 ^ ""[uVar13];
    uVar6 = (uint)""[uVar13];
    if (piVar9 == (init_config *)((int)&c5_config.chain_max_freq + 1)) break;
    piVar9 = (init_config *)&piVar9->version;
    uVar13 = (uint)*(byte *)piVar9;
  }
  c5_config.crc = (ushort)uVar4 | (ushort)""[uVar13] << 8;
  c5_config.chain_max_freq = 600;
  uVar22 = 0;
  uVar2 = CONCAT14(bVar1,0x1a0051) | 0xfd00000000;
  uVar7 = 7;
  uVar25 = (char)uVar2;
  uVar26._1_1_ = (char)(uVar2 >> 8);
  uVar26._2_2_ = (short)(uVar2 >> 0x10);
  register0x00000024 = (char)(uVar2 >> 0x20);
  uVar20 = CONCAT15(uVar7,uVar35);
  uVar27 = '\0';
  register0x00000027 = '\0';
  uVar14 = CONCAT26(auVar28,uVar20);
  uVar8 = 9;
  Var19 = CONCAT18(uVar8,uVar14);
  uVar10 = 0x36;
  Var18 = CONCAT19(uVar10,Var19);
  uVar11 = (uchar)opt_bitmain_fan_pwm;
  auVar17 = CONCAT110(uVar11,Var18);
  uVar12 = 0x50;
  auVar16 = CONCAT111(uVar12,auVar17);
  uVar30 = (uint16_t)opt_bitmain_c5_freq;
  register0x0000002e = '\a';
  register0x0000002f = '%';
  auVar15 = CONCAT164(in_stack_00000000,uVar31);
  config = (init_config)CONCAT2012(auVar15,auVar16);
  uVar21 = c5_config._16_4_;
  uVar23 = c5_config._24_4_;
  uVar24 = c5_config._28_4_;
  bitmain_c5_init(config);
  send_mac_thr = (thr_info *)calloc(1,0x40);
  iVar3 = thr_info_create(send_mac_thr,(pthread_attr_t *)0x0,(_func_void_ptr_void_ptr *)0x2a5c1,
                          send_mac_thr);
  if (((iVar3 != 0) && (opt_debug != false)) &&
     ((use_syslog != false || ((opt_log_output != false || (6 < opt_log_level)))))) {
    snprintf(tmp42,0x800,"%s: create thread for send mac\n","bitmain_c5_prepare",uVar21,uVar22,
             uVar23,uVar24);
    _applog(7,tmp42,false);
  }
  return true;
}


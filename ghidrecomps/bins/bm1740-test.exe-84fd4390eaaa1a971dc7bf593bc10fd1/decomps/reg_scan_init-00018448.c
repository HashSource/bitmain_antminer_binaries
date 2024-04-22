
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void reg_scan_init(void)

{
  undefined4 local_118;
  undefined4 uStack_114;
  undefined4 uStack_110;
  undefined4 uStack_10c;
  undefined4 local_108;
  undefined2 local_104;
  undefined local_102;
  int local_18;
  int local_14;
  
  memset(&reg_scan_items,0,0x4b0);
  for (local_14 = 0; local_14 < 100; local_14 = local_14 + 1) {
    *(undefined4 *)(&DAT_000312a0 + local_14 * 0xc) = 0xffffffff;
  }
  pthread_mutex_init((pthread_mutex_t *)reg_scan_mutex,(pthread_mutexattr_t *)0x0);
  local_18 = pthread_create(&p_reg_scan,(pthread_attr_t *)0x0,reg_scan_aging + 1,(void *)0x0);
  if ((local_18 != 0) && (((use_syslog != '\0' || (opt_log_output != '\0')) || (2 < opt_log_level)))
     ) {
    local_118._0_1_ = s_create_pthread_failed_0002c710[0];
    local_118._1_1_ = s_create_pthread_failed_0002c710[1];
    local_118._2_1_ = s_create_pthread_failed_0002c710[2];
    local_118._3_1_ = s_create_pthread_failed_0002c710[3];
    uStack_114._0_1_ = s_create_pthread_failed_0002c710[4];
    uStack_114._1_1_ = s_create_pthread_failed_0002c710[5];
    uStack_114._2_1_ = s_create_pthread_failed_0002c710[6];
    uStack_114._3_1_ = s_create_pthread_failed_0002c710[7];
    uStack_110._0_1_ = s_create_pthread_failed_0002c710[8];
    uStack_110._1_1_ = s_create_pthread_failed_0002c710[9];
    uStack_110._2_1_ = s_create_pthread_failed_0002c710[10];
    uStack_110._3_1_ = s_create_pthread_failed_0002c710[11];
    uStack_10c._0_1_ = s_create_pthread_failed_0002c710[12];
    uStack_10c._1_1_ = s_create_pthread_failed_0002c710[13];
    uStack_10c._2_1_ = s_create_pthread_failed_0002c710[14];
    uStack_10c._3_1_ = s_create_pthread_failed_0002c710[15];
    local_108._0_1_ = s_create_pthread_failed_0002c710[16];
    local_108._1_1_ = s_create_pthread_failed_0002c710[17];
    local_108._2_1_ = s_create_pthread_failed_0002c710[18];
    local_108._3_1_ = s_create_pthread_failed_0002c710[19];
    local_104 = (undefined2)ram0x0002c724;
    local_102 = (undefined)((uint)ram0x0002c724 >> 0x10);
    _applog(3,&local_118,0);
  }
  return;
}


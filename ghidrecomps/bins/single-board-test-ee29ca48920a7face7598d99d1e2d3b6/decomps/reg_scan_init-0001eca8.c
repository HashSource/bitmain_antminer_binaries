
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void reg_scan_init(void)

{
  int iVar1;
  undefined4 local_414;
  undefined4 uStack_410;
  undefined4 uStack_40c;
  undefined4 uStack_408;
  undefined4 local_404;
  undefined2 local_400;
  undefined local_3fe;
  int local_14;
  
  memset(&reg_scan_items,0,0x4b0);
  for (local_14 = 0; local_14 < 100; local_14 = local_14 + 1) {
    *(undefined4 *)(&DAT_00047f00 + local_14 * 0xc) = 0xffffffff;
  }
  iVar1 = pthread_create(&p_reg_scan,(pthread_attr_t *)0x0,reg_scan_aging + 1,(void *)0x0);
  if ((iVar1 != 0) && (((use_syslog != '\0' || (opt_log_output != '\0')) || (2 < opt_log_level)))) {
    local_414._0_1_ = s_create_pthread_failed_00033f68[0];
    local_414._1_1_ = s_create_pthread_failed_00033f68[1];
    local_414._2_1_ = s_create_pthread_failed_00033f68[2];
    local_414._3_1_ = s_create_pthread_failed_00033f68[3];
    uStack_410._0_1_ = s_create_pthread_failed_00033f68[4];
    uStack_410._1_1_ = s_create_pthread_failed_00033f68[5];
    uStack_410._2_1_ = s_create_pthread_failed_00033f68[6];
    uStack_410._3_1_ = s_create_pthread_failed_00033f68[7];
    uStack_40c._0_1_ = s_create_pthread_failed_00033f68[8];
    uStack_40c._1_1_ = s_create_pthread_failed_00033f68[9];
    uStack_40c._2_1_ = s_create_pthread_failed_00033f68[10];
    uStack_40c._3_1_ = s_create_pthread_failed_00033f68[11];
    uStack_408._0_1_ = s_create_pthread_failed_00033f68[12];
    uStack_408._1_1_ = s_create_pthread_failed_00033f68[13];
    uStack_408._2_1_ = s_create_pthread_failed_00033f68[14];
    uStack_408._3_1_ = s_create_pthread_failed_00033f68[15];
    local_404._0_1_ = s_create_pthread_failed_00033f68[16];
    local_404._1_1_ = s_create_pthread_failed_00033f68[17];
    local_404._2_1_ = s_create_pthread_failed_00033f68[18];
    local_404._3_1_ = s_create_pthread_failed_00033f68[19];
    local_400 = (undefined2)ram0x00033f7c;
    local_3fe = (undefined)((uint)ram0x00033f7c >> 0x10);
    _applog(3,&local_414,0);
  }
  return;
}


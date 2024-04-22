
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 bm1744_app_init(void)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 local_414;
  undefined4 uStack_410;
  undefined4 uStack_40c;
  undefined4 uStack_408;
  undefined4 local_404;
  undefined4 uStack_400;
  undefined4 local_3fc;
  undefined4 uStack_3f8;
  undefined4 local_3f4;
  undefined4 uStack_3f0;
  undefined2 local_3ec;
  undefined local_3ea;
  int local_14;
  
  local_14 = 0;
  reg_scan_init();
  start_recv = 1;
  local_14 = 0;
  while( true ) {
    if (0 < local_14) {
      iVar1 = pthread_create(&p_scanhash,(pthread_attr_t *)0x0,nonce_scanhash_loop + 1,(void *)0x0);
      if (iVar1 == 0) {
        uVar2 = 0;
      }
      else {
        if (((use_syslog != '\0') || (opt_log_output != '\0')) || (0 < opt_log_level)) {
          local_414._0_1_ = s_create_bm1744_scanhash_loop_thre_00033c74[0];
          local_414._1_1_ = s_create_bm1744_scanhash_loop_thre_00033c74[1];
          local_414._2_1_ = s_create_bm1744_scanhash_loop_thre_00033c74[2];
          local_414._3_1_ = s_create_bm1744_scanhash_loop_thre_00033c74[3];
          uStack_410._0_1_ = s_create_bm1744_scanhash_loop_thre_00033c74[4];
          uStack_410._1_1_ = s_create_bm1744_scanhash_loop_thre_00033c74[5];
          uStack_410._2_1_ = s_create_bm1744_scanhash_loop_thre_00033c74[6];
          uStack_410._3_1_ = s_create_bm1744_scanhash_loop_thre_00033c74[7];
          uStack_40c._0_1_ = s_create_bm1744_scanhash_loop_thre_00033c74[8];
          uStack_40c._1_1_ = s_create_bm1744_scanhash_loop_thre_00033c74[9];
          uStack_40c._2_1_ = s_create_bm1744_scanhash_loop_thre_00033c74[10];
          uStack_40c._3_1_ = s_create_bm1744_scanhash_loop_thre_00033c74[11];
          uStack_408._0_1_ = s_create_bm1744_scanhash_loop_thre_00033c74[12];
          uStack_408._1_1_ = s_create_bm1744_scanhash_loop_thre_00033c74[13];
          uStack_408._2_1_ = s_create_bm1744_scanhash_loop_thre_00033c74[14];
          uStack_408._3_1_ = s_create_bm1744_scanhash_loop_thre_00033c74[15];
          local_404._0_1_ = s_create_bm1744_scanhash_loop_thre_00033c74[16];
          local_404._1_1_ = s_create_bm1744_scanhash_loop_thre_00033c74[17];
          local_404._2_1_ = s_create_bm1744_scanhash_loop_thre_00033c74[18];
          local_404._3_1_ = s_create_bm1744_scanhash_loop_thre_00033c74[19];
          uStack_400._0_1_ = s_create_bm1744_scanhash_loop_thre_00033c74[20];
          uStack_400._1_1_ = s_create_bm1744_scanhash_loop_thre_00033c74[21];
          uStack_400._2_1_ = s_create_bm1744_scanhash_loop_thre_00033c74[22];
          uStack_400._3_1_ = s_create_bm1744_scanhash_loop_thre_00033c74[23];
          local_3fc._0_1_ = s_create_bm1744_scanhash_loop_thre_00033c74[24];
          local_3fc._1_1_ = s_create_bm1744_scanhash_loop_thre_00033c74[25];
          local_3fc._2_1_ = s_create_bm1744_scanhash_loop_thre_00033c74[26];
          local_3fc._3_1_ = s_create_bm1744_scanhash_loop_thre_00033c74[27];
          uStack_3f8._0_1_ = s_create_bm1744_scanhash_loop_thre_00033c74[28];
          uStack_3f8._1_1_ = s_create_bm1744_scanhash_loop_thre_00033c74[29];
          uStack_3f8._2_1_ = s_create_bm1744_scanhash_loop_thre_00033c74[30];
          uStack_3f8._3_1_ = s_create_bm1744_scanhash_loop_thre_00033c74[31];
          local_3f4._0_1_ = s_create_bm1744_scanhash_loop_thre_00033c74[32];
          local_3f4._1_1_ = s_create_bm1744_scanhash_loop_thre_00033c74[33];
          local_3f4._2_1_ = s_create_bm1744_scanhash_loop_thre_00033c74[34];
          local_3f4._3_1_ = s_create_bm1744_scanhash_loop_thre_00033c74[35];
          uStack_3f0._0_1_ = s_create_bm1744_scanhash_loop_thre_00033c74[36];
          uStack_3f0._1_1_ = s_create_bm1744_scanhash_loop_thre_00033c74[37];
          uStack_3f0._2_1_ = s_create_bm1744_scanhash_loop_thre_00033c74[38];
          uStack_3f0._3_1_ = s_create_bm1744_scanhash_loop_thre_00033c74[39];
          local_3ec = (undefined2)ram0x00033c9c;
          local_3ea = (undefined)((uint)ram0x00033c9c >> 0x10);
          _applog(1,&local_414,0);
        }
        uVar2 = 0xffffffff;
      }
      return uVar2;
    }
    iVar1 = pthread_create((pthread_t *)(g_chain + local_14 * 0x20 + 0x18),(pthread_attr_t *)0x0,
                           handle_asic_response + 1,&local_14);
    if (iVar1 != 0) break;
    local_14 = local_14 + 1;
  }
  if (((use_syslog != '\0') || (opt_log_output != '\0')) || (0 < opt_log_level)) {
    local_414._0_1_ = s_create_p_dispatch_failed_00033c58[0];
    local_414._1_1_ = s_create_p_dispatch_failed_00033c58[1];
    local_414._2_1_ = s_create_p_dispatch_failed_00033c58[2];
    local_414._3_1_ = s_create_p_dispatch_failed_00033c58[3];
    uStack_410._0_1_ = s_create_p_dispatch_failed_00033c58[4];
    uStack_410._1_1_ = s_create_p_dispatch_failed_00033c58[5];
    uStack_410._2_1_ = s_create_p_dispatch_failed_00033c58[6];
    uStack_410._3_1_ = s_create_p_dispatch_failed_00033c58[7];
    uStack_40c._0_1_ = s_create_p_dispatch_failed_00033c58[8];
    uStack_40c._1_1_ = s_create_p_dispatch_failed_00033c58[9];
    uStack_40c._2_1_ = s_create_p_dispatch_failed_00033c58[10];
    uStack_40c._3_1_ = s_create_p_dispatch_failed_00033c58[11];
    uStack_408._0_1_ = s_create_p_dispatch_failed_00033c58[12];
    uStack_408._1_1_ = s_create_p_dispatch_failed_00033c58[13];
    uStack_408._2_1_ = s_create_p_dispatch_failed_00033c58[14];
    uStack_408._3_1_ = s_create_p_dispatch_failed_00033c58[15];
    local_404._0_1_ = s_create_p_dispatch_failed_00033c58[16];
    local_404._1_1_ = s_create_p_dispatch_failed_00033c58[17];
    local_404._2_1_ = s_create_p_dispatch_failed_00033c58[18];
    local_404._3_1_ = s_create_p_dispatch_failed_00033c58[19];
    uStack_400._0_1_ = s_create_p_dispatch_failed_00033c58[20];
    uStack_400._1_1_ = s_create_p_dispatch_failed_00033c58[21];
    uStack_400._2_1_ = s_create_p_dispatch_failed_00033c58[22];
    uStack_400._3_1_ = s_create_p_dispatch_failed_00033c58[23];
    local_3fc = CONCAT22(local_3fc._2_2_,(short)ram0x00033c70);
    _applog(1,&local_414,0);
  }
  return 0xffffffff;
}


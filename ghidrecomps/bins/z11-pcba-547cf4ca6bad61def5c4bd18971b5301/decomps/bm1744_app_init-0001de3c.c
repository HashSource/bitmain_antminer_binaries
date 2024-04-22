
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
          local_414._0_1_ = s_create_bm1744_scanhash_loop_thre_000337c4[0];
          local_414._1_1_ = s_create_bm1744_scanhash_loop_thre_000337c4[1];
          local_414._2_1_ = s_create_bm1744_scanhash_loop_thre_000337c4[2];
          local_414._3_1_ = s_create_bm1744_scanhash_loop_thre_000337c4[3];
          uStack_410._0_1_ = s_create_bm1744_scanhash_loop_thre_000337c4[4];
          uStack_410._1_1_ = s_create_bm1744_scanhash_loop_thre_000337c4[5];
          uStack_410._2_1_ = s_create_bm1744_scanhash_loop_thre_000337c4[6];
          uStack_410._3_1_ = s_create_bm1744_scanhash_loop_thre_000337c4[7];
          uStack_40c._0_1_ = s_create_bm1744_scanhash_loop_thre_000337c4[8];
          uStack_40c._1_1_ = s_create_bm1744_scanhash_loop_thre_000337c4[9];
          uStack_40c._2_1_ = s_create_bm1744_scanhash_loop_thre_000337c4[10];
          uStack_40c._3_1_ = s_create_bm1744_scanhash_loop_thre_000337c4[11];
          uStack_408._0_1_ = s_create_bm1744_scanhash_loop_thre_000337c4[12];
          uStack_408._1_1_ = s_create_bm1744_scanhash_loop_thre_000337c4[13];
          uStack_408._2_1_ = s_create_bm1744_scanhash_loop_thre_000337c4[14];
          uStack_408._3_1_ = s_create_bm1744_scanhash_loop_thre_000337c4[15];
          local_404._0_1_ = s_create_bm1744_scanhash_loop_thre_000337c4[16];
          local_404._1_1_ = s_create_bm1744_scanhash_loop_thre_000337c4[17];
          local_404._2_1_ = s_create_bm1744_scanhash_loop_thre_000337c4[18];
          local_404._3_1_ = s_create_bm1744_scanhash_loop_thre_000337c4[19];
          uStack_400._0_1_ = s_create_bm1744_scanhash_loop_thre_000337c4[20];
          uStack_400._1_1_ = s_create_bm1744_scanhash_loop_thre_000337c4[21];
          uStack_400._2_1_ = s_create_bm1744_scanhash_loop_thre_000337c4[22];
          uStack_400._3_1_ = s_create_bm1744_scanhash_loop_thre_000337c4[23];
          local_3fc._0_1_ = s_create_bm1744_scanhash_loop_thre_000337c4[24];
          local_3fc._1_1_ = s_create_bm1744_scanhash_loop_thre_000337c4[25];
          local_3fc._2_1_ = s_create_bm1744_scanhash_loop_thre_000337c4[26];
          local_3fc._3_1_ = s_create_bm1744_scanhash_loop_thre_000337c4[27];
          uStack_3f8._0_1_ = s_create_bm1744_scanhash_loop_thre_000337c4[28];
          uStack_3f8._1_1_ = s_create_bm1744_scanhash_loop_thre_000337c4[29];
          uStack_3f8._2_1_ = s_create_bm1744_scanhash_loop_thre_000337c4[30];
          uStack_3f8._3_1_ = s_create_bm1744_scanhash_loop_thre_000337c4[31];
          local_3f4._0_1_ = s_create_bm1744_scanhash_loop_thre_000337c4[32];
          local_3f4._1_1_ = s_create_bm1744_scanhash_loop_thre_000337c4[33];
          local_3f4._2_1_ = s_create_bm1744_scanhash_loop_thre_000337c4[34];
          local_3f4._3_1_ = s_create_bm1744_scanhash_loop_thre_000337c4[35];
          uStack_3f0._0_1_ = s_create_bm1744_scanhash_loop_thre_000337c4[36];
          uStack_3f0._1_1_ = s_create_bm1744_scanhash_loop_thre_000337c4[37];
          uStack_3f0._2_1_ = s_create_bm1744_scanhash_loop_thre_000337c4[38];
          uStack_3f0._3_1_ = s_create_bm1744_scanhash_loop_thre_000337c4[39];
          local_3ec = (undefined2)ram0x000337ec;
          local_3ea = (undefined)((uint)ram0x000337ec >> 0x10);
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
    local_414._0_1_ = s_create_p_dispatch_failed_000337a8[0];
    local_414._1_1_ = s_create_p_dispatch_failed_000337a8[1];
    local_414._2_1_ = s_create_p_dispatch_failed_000337a8[2];
    local_414._3_1_ = s_create_p_dispatch_failed_000337a8[3];
    uStack_410._0_1_ = s_create_p_dispatch_failed_000337a8[4];
    uStack_410._1_1_ = s_create_p_dispatch_failed_000337a8[5];
    uStack_410._2_1_ = s_create_p_dispatch_failed_000337a8[6];
    uStack_410._3_1_ = s_create_p_dispatch_failed_000337a8[7];
    uStack_40c._0_1_ = s_create_p_dispatch_failed_000337a8[8];
    uStack_40c._1_1_ = s_create_p_dispatch_failed_000337a8[9];
    uStack_40c._2_1_ = s_create_p_dispatch_failed_000337a8[10];
    uStack_40c._3_1_ = s_create_p_dispatch_failed_000337a8[11];
    uStack_408._0_1_ = s_create_p_dispatch_failed_000337a8[12];
    uStack_408._1_1_ = s_create_p_dispatch_failed_000337a8[13];
    uStack_408._2_1_ = s_create_p_dispatch_failed_000337a8[14];
    uStack_408._3_1_ = s_create_p_dispatch_failed_000337a8[15];
    local_404._0_1_ = s_create_p_dispatch_failed_000337a8[16];
    local_404._1_1_ = s_create_p_dispatch_failed_000337a8[17];
    local_404._2_1_ = s_create_p_dispatch_failed_000337a8[18];
    local_404._3_1_ = s_create_p_dispatch_failed_000337a8[19];
    uStack_400._0_1_ = s_create_p_dispatch_failed_000337a8[20];
    uStack_400._1_1_ = s_create_p_dispatch_failed_000337a8[21];
    uStack_400._2_1_ = s_create_p_dispatch_failed_000337a8[22];
    uStack_400._3_1_ = s_create_p_dispatch_failed_000337a8[23];
    local_3fc = CONCAT22(local_3fc._2_2_,(short)ram0x000337c0);
    _applog(1,&local_414,0);
  }
  return 0xffffffff;
}


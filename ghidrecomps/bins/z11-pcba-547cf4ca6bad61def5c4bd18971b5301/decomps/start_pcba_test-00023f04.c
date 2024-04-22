
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 start_pcba_test(void)

{
  int iVar1;
  undefined4 local_454;
  undefined4 uStack_450;
  undefined4 uStack_44c;
  undefined4 uStack_448;
  undefined4 local_444;
  undefined4 uStack_440;
  undefined4 uStack_43c;
  undefined4 uStack_438;
  undefined4 local_434;
  undefined4 uStack_430;
  undefined4 uStack_42c;
  undefined local_428;
  char local_54 [64];
  int local_14;
  
  memset(local_54,0,0x40);
  iVar1 = cgpu_init();
  if (iVar1 < 0) {
    if (((use_syslog != '\0') || (opt_log_output != '\0')) || (1 < opt_log_level)) {
      local_454._0_1_ = s_cgpu_init_failed_00034ca8[0];
      local_454._1_1_ = s_cgpu_init_failed_00034ca8[1];
      local_454._2_1_ = s_cgpu_init_failed_00034ca8[2];
      local_454._3_1_ = s_cgpu_init_failed_00034ca8[3];
      uStack_450._0_1_ = s_cgpu_init_failed_00034ca8[4];
      uStack_450._1_1_ = s_cgpu_init_failed_00034ca8[5];
      uStack_450._2_1_ = s_cgpu_init_failed_00034ca8[6];
      uStack_450._3_1_ = s_cgpu_init_failed_00034ca8[7];
      uStack_44c._0_1_ = s_cgpu_init_failed_00034ca8[8];
      uStack_44c._1_1_ = s_cgpu_init_failed_00034ca8[9];
      uStack_44c._2_1_ = s_cgpu_init_failed_00034ca8[10];
      uStack_44c._3_1_ = s_cgpu_init_failed_00034ca8[11];
      uStack_448._0_1_ = s_cgpu_init_failed_00034ca8[12];
      uStack_448._1_1_ = s_cgpu_init_failed_00034ca8[13];
      uStack_448._2_1_ = s_cgpu_init_failed_00034ca8[14];
      uStack_448._3_1_ = s_cgpu_init_failed_00034ca8[15];
      local_444 = CONCAT22(local_444._2_2_,(short)ram0x00034cb8);
      _applog(2,&local_454,0);
    }
    return 0xffffffff;
  }
  display_arguments();
  do {
    memset(local_54,0,0x40);
    iVar1 = strcmp(DAT_00024070,"keyboard");
    if (iVar1 == 0) {
      local_14 = __isoc99_fscanf(stdin,&DAT_00034a80,local_54);
    }
    else {
      iVar1 = strcmp(DAT_00024070,"button");
      if (iVar1 != 0) {
        if (((use_syslog != '\0') || (opt_log_output != '\0')) || (1 < opt_log_level)) {
          local_454._0_1_ = s_please_assign_ctrl_type__keyboar_00034cd0[0];
          local_454._1_1_ = s_please_assign_ctrl_type__keyboar_00034cd0[1];
          local_454._2_1_ = s_please_assign_ctrl_type__keyboar_00034cd0[2];
          local_454._3_1_ = s_please_assign_ctrl_type__keyboar_00034cd0[3];
          uStack_450._0_1_ = s_please_assign_ctrl_type__keyboar_00034cd0[4];
          uStack_450._1_1_ = s_please_assign_ctrl_type__keyboar_00034cd0[5];
          uStack_450._2_1_ = s_please_assign_ctrl_type__keyboar_00034cd0[6];
          uStack_450._3_1_ = s_please_assign_ctrl_type__keyboar_00034cd0[7];
          uStack_44c._0_1_ = s_please_assign_ctrl_type__keyboar_00034cd0[8];
          uStack_44c._1_1_ = s_please_assign_ctrl_type__keyboar_00034cd0[9];
          uStack_44c._2_1_ = s_please_assign_ctrl_type__keyboar_00034cd0[10];
          uStack_44c._3_1_ = s_please_assign_ctrl_type__keyboar_00034cd0[11];
          uStack_448._0_1_ = s_please_assign_ctrl_type__keyboar_00034cd0[12];
          uStack_448._1_1_ = s_please_assign_ctrl_type__keyboar_00034cd0[13];
          uStack_448._2_1_ = s_please_assign_ctrl_type__keyboar_00034cd0[14];
          uStack_448._3_1_ = s_please_assign_ctrl_type__keyboar_00034cd0[15];
          local_444._0_1_ = s_please_assign_ctrl_type__keyboar_00034cd0[16];
          local_444._1_1_ = s_please_assign_ctrl_type__keyboar_00034cd0[17];
          local_444._2_1_ = s_please_assign_ctrl_type__keyboar_00034cd0[18];
          local_444._3_1_ = s_please_assign_ctrl_type__keyboar_00034cd0[19];
          uStack_440._0_1_ = s_please_assign_ctrl_type__keyboar_00034cd0[20];
          uStack_440._1_1_ = s_please_assign_ctrl_type__keyboar_00034cd0[21];
          uStack_440._2_1_ = s_please_assign_ctrl_type__keyboar_00034cd0[22];
          uStack_440._3_1_ = s_please_assign_ctrl_type__keyboar_00034cd0[23];
          uStack_43c._0_1_ = s_please_assign_ctrl_type__keyboar_00034cd0[24];
          uStack_43c._1_1_ = s_please_assign_ctrl_type__keyboar_00034cd0[25];
          uStack_43c._2_1_ = s_please_assign_ctrl_type__keyboar_00034cd0[26];
          uStack_43c._3_1_ = s_please_assign_ctrl_type__keyboar_00034cd0[27];
          uStack_438._0_1_ = s_please_assign_ctrl_type__keyboar_00034cd0[28];
          uStack_438._1_1_ = s_please_assign_ctrl_type__keyboar_00034cd0[29];
          uStack_438._2_1_ = s_please_assign_ctrl_type__keyboar_00034cd0[30];
          uStack_438._3_1_ = s_please_assign_ctrl_type__keyboar_00034cd0[31];
          local_434._0_1_ = s_please_assign_ctrl_type__keyboar_00034cd0[32];
          local_434._1_1_ = s_please_assign_ctrl_type__keyboar_00034cd0[33];
          local_434._2_1_ = s_please_assign_ctrl_type__keyboar_00034cd0[34];
          local_434._3_1_ = s_please_assign_ctrl_type__keyboar_00034cd0[35];
          uStack_430._0_1_ = s_please_assign_ctrl_type__keyboar_00034cd0[36];
          uStack_430._1_1_ = s_please_assign_ctrl_type__keyboar_00034cd0[37];
          uStack_430._2_1_ = s_please_assign_ctrl_type__keyboar_00034cd0[38];
          uStack_430._3_1_ = s_please_assign_ctrl_type__keyboar_00034cd0[39];
          uStack_42c._0_1_ = s_please_assign_ctrl_type__keyboar_00034cd0[40];
          uStack_42c._1_1_ = s_please_assign_ctrl_type__keyboar_00034cd0[41];
          uStack_42c._2_1_ = s_please_assign_ctrl_type__keyboar_00034cd0[42];
          uStack_42c._3_1_ = s_please_assign_ctrl_type__keyboar_00034cd0[43];
          local_428 = (undefined)ram0x00034cfc;
          _applog(2,&local_454,0);
        }
        cgpu_exit();
        return 0;
      }
      local_14 = v9_key_read(local_54,0x40);
    }
    if ((0 < local_14) && (local_54[0] == '0')) {
      singleBoardTest_V9_BM1744();
    }
    usleep(100000);
  } while( true );
}


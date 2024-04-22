
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int submit_nonce_1(int param_1,int param_2,undefined4 param_3,undefined4 *param_4)

{
  int iVar1;
  undefined4 local_810;
  undefined4 uStack_80c;
  undefined4 uStack_808;
  undefined4 uStack_804;
  undefined2 uStack_800;
  undefined local_7fe;
  
  if (param_4 != (undefined4 *)0x0) {
    *param_4 = 0;
  }
  *(undefined4 *)(param_2 + 0x4c) = param_3;
  regen_hash(param_2);
  if (*(int *)(param_2 + 0xdc) == 0) {
    update_work_stats_isra_55(param_1 + 0x24,param_2);
    iVar1 = fulltest(param_2 + 0xc0,param_2 + 0xa0);
    if (iVar1 == 0) {
      if (param_4 != (undefined4 *)0x0) {
        *param_4 = 1;
      }
      if (((use_syslog == '\0') && (opt_log_output == '\0')) && (opt_log_level < 6)) {
        iVar1 = 0;
      }
      else {
        local_810._0_1_ = s_Share_above_target_0005d61c[0];
        local_810._1_1_ = s_Share_above_target_0005d61c[1];
        local_810._2_1_ = s_Share_above_target_0005d61c[2];
        local_810._3_1_ = s_Share_above_target_0005d61c[3];
        uStack_80c._0_1_ = s_Share_above_target_0005d61c[4];
        uStack_80c._1_1_ = s_Share_above_target_0005d61c[5];
        uStack_80c._2_1_ = s_Share_above_target_0005d61c[6];
        uStack_80c._3_1_ = s_Share_above_target_0005d61c[7];
        uStack_808._0_1_ = s_Share_above_target_0005d61c[8];
        uStack_808._1_1_ = s_Share_above_target_0005d61c[9];
        uStack_808._2_1_ = s_Share_above_target_0005d61c[10];
        uStack_808._3_1_ = s_Share_above_target_0005d61c[11];
        uStack_804._0_1_ = s_Share_above_target_0005d61c[12];
        uStack_804._1_1_ = s_Share_above_target_0005d61c[13];
        uStack_804._2_1_ = s_Share_above_target_0005d61c[14];
        uStack_804._3_1_ = s_Share_above_target_0005d61c[15];
        uStack_800 = (undefined2)ram0x0005d62c;
        local_7fe = (undefined)((uint)ram0x0005d62c >> 0x10);
        _applog(6,&local_810,0);
      }
    }
    return iVar1;
  }
  inc_hw_errors(param_1);
  return 0;
}


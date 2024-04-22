
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void roll_work(int param_1)

{
  char cVar1;
  undefined4 uVar2;
  uint uVar3;
  int iVar4;
  undefined4 local_810;
  undefined4 uStack_80c;
  undefined4 uStack_808;
  undefined4 uStack_804;
  undefined4 local_800;
  undefined4 uStack_7fc;
  undefined local_7f8;
  
  cVar1 = opt_debug;
  uVar3 = *(uint *)(param_1 + 0x44);
  uVar3 = (uVar3 << 0x18 | (uVar3 >> 8 & 0xff) << 0x10 | (uVar3 >> 0x10 & 0xff) << 8 | uVar3 >> 0x18
          ) + 1;
  local_work = local_work + 1;
  *(uint *)(param_1 + 0x44) =
       uVar3 * 0x1000000 | (uVar3 >> 8 & 0xff) << 0x10 | (uVar3 >> 0x10 & 0xff) << 8 | uVar3 >> 0x18
  ;
  *(int *)(param_1 + 0xf0) = *(int *)(param_1 + 0xf0) + 1;
  *(undefined4 *)(param_1 + 0xf8) = 0;
  if ((cVar1 != '\0') && (((use_syslog != '\0' || (opt_log_output != '\0')) || (6 < opt_log_level)))
     ) {
    local_810._0_1_ = s_Successfully_rolled_work_0005cd80[0];
    local_810._1_1_ = s_Successfully_rolled_work_0005cd80[1];
    local_810._2_1_ = s_Successfully_rolled_work_0005cd80[2];
    local_810._3_1_ = s_Successfully_rolled_work_0005cd80[3];
    uStack_80c._0_1_ = s_Successfully_rolled_work_0005cd80[4];
    uStack_80c._1_1_ = s_Successfully_rolled_work_0005cd80[5];
    uStack_80c._2_1_ = s_Successfully_rolled_work_0005cd80[6];
    uStack_80c._3_1_ = s_Successfully_rolled_work_0005cd80[7];
    uStack_808._0_1_ = s_Successfully_rolled_work_0005cd80[8];
    uStack_808._1_1_ = s_Successfully_rolled_work_0005cd80[9];
    uStack_808._2_1_ = s_Successfully_rolled_work_0005cd80[10];
    uStack_808._3_1_ = s_Successfully_rolled_work_0005cd80[11];
    uStack_804._0_1_ = s_Successfully_rolled_work_0005cd80[12];
    uStack_804._1_1_ = s_Successfully_rolled_work_0005cd80[13];
    uStack_804._2_1_ = s_Successfully_rolled_work_0005cd80[14];
    uStack_804._3_1_ = s_Successfully_rolled_work_0005cd80[15];
    local_800._0_1_ = s_Successfully_rolled_work_0005cd80[16];
    local_800._1_1_ = s_Successfully_rolled_work_0005cd80[17];
    local_800._2_1_ = s_Successfully_rolled_work_0005cd80[18];
    local_800._3_1_ = s_Successfully_rolled_work_0005cd80[19];
    uStack_7fc._0_1_ = s_Successfully_rolled_work_0005cd80[20];
    uStack_7fc._1_1_ = s_Successfully_rolled_work_0005cd80[21];
    uStack_7fc._2_1_ = s_Successfully_rolled_work_0005cd80[22];
    uStack_7fc._3_1_ = s_Successfully_rolled_work_0005cd80[23];
    local_7f8 = (undefined)ram0x0005cd98;
    _applog(7,&local_810,0);
  }
  iVar4 = *(int *)(param_1 + 0x134);
  if (iVar4 != 0) {
    hex2bin(&local_810,iVar4,4);
    uVar3 = (local_810 << 0x18 | (local_810 >> 8 & 0xff) << 0x10 | (local_810 >> 0x10 & 0xff) << 8 |
            local_810 >> 0x18) + 1;
    local_810 = uVar3 * 0x1000000 | (uVar3 >> 8 & 0xff) << 0x10 | (uVar3 >> 0x10 & 0xff) << 8 |
                uVar3 >> 0x18;
    __bin2hex(iVar4,&local_810,4);
  }
  uVar2 = total_work_inc();
  *(undefined4 *)(param_1 + 0x154) = uVar2;
  return;
}


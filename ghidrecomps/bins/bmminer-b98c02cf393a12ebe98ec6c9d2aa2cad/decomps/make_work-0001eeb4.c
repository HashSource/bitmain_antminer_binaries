
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int make_work(void)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 local_810;
  undefined4 uStack_80c;
  undefined4 uStack_808;
  undefined4 uStack_804;
  undefined4 local_800;
  undefined4 uStack_7fc;
  undefined4 uStack_7f8;
  undefined4 uStack_7f4;
  undefined2 uStack_7f0;
  undefined local_7ee;
  
  iVar1 = _cgcalloc(1,0x1c0,"cgminer.c",DAT_0001ef18,0x8a6);
  if (iVar1 != 0) {
    uVar2 = total_work_inc();
    *(undefined4 *)(iVar1 + 0x154) = uVar2;
    return iVar1;
  }
  local_810._0_1_ = s_Failed_to_calloc_work_in_make_wo_0005cd9c[0];
  local_810._1_1_ = s_Failed_to_calloc_work_in_make_wo_0005cd9c[1];
  local_810._2_1_ = s_Failed_to_calloc_work_in_make_wo_0005cd9c[2];
  local_810._3_1_ = s_Failed_to_calloc_work_in_make_wo_0005cd9c[3];
  uStack_80c._0_1_ = s_Failed_to_calloc_work_in_make_wo_0005cd9c[4];
  uStack_80c._1_1_ = s_Failed_to_calloc_work_in_make_wo_0005cd9c[5];
  uStack_80c._2_1_ = s_Failed_to_calloc_work_in_make_wo_0005cd9c[6];
  uStack_80c._3_1_ = s_Failed_to_calloc_work_in_make_wo_0005cd9c[7];
  uStack_808._0_1_ = s_Failed_to_calloc_work_in_make_wo_0005cd9c[8];
  uStack_808._1_1_ = s_Failed_to_calloc_work_in_make_wo_0005cd9c[9];
  uStack_808._2_1_ = s_Failed_to_calloc_work_in_make_wo_0005cd9c[10];
  uStack_808._3_1_ = s_Failed_to_calloc_work_in_make_wo_0005cd9c[11];
  uStack_804._0_1_ = s_Failed_to_calloc_work_in_make_wo_0005cd9c[12];
  uStack_804._1_1_ = s_Failed_to_calloc_work_in_make_wo_0005cd9c[13];
  uStack_804._2_1_ = s_Failed_to_calloc_work_in_make_wo_0005cd9c[14];
  uStack_804._3_1_ = s_Failed_to_calloc_work_in_make_wo_0005cd9c[15];
  local_800._0_1_ = s_Failed_to_calloc_work_in_make_wo_0005cd9c[16];
  local_800._1_1_ = s_Failed_to_calloc_work_in_make_wo_0005cd9c[17];
  local_800._2_1_ = s_Failed_to_calloc_work_in_make_wo_0005cd9c[18];
  local_800._3_1_ = s_Failed_to_calloc_work_in_make_wo_0005cd9c[19];
  uStack_7fc._0_1_ = s_Failed_to_calloc_work_in_make_wo_0005cd9c[20];
  uStack_7fc._1_1_ = s_Failed_to_calloc_work_in_make_wo_0005cd9c[21];
  uStack_7fc._2_1_ = s_Failed_to_calloc_work_in_make_wo_0005cd9c[22];
  uStack_7fc._3_1_ = s_Failed_to_calloc_work_in_make_wo_0005cd9c[23];
  uStack_7f8._0_1_ = s_Failed_to_calloc_work_in_make_wo_0005cd9c[24];
  uStack_7f8._1_1_ = s_Failed_to_calloc_work_in_make_wo_0005cd9c[25];
  uStack_7f8._2_1_ = s_Failed_to_calloc_work_in_make_wo_0005cd9c[26];
  uStack_7f8._3_1_ = s_Failed_to_calloc_work_in_make_wo_0005cd9c[27];
  uStack_7f4._0_1_ = s_Failed_to_calloc_work_in_make_wo_0005cd9c[28];
  uStack_7f4._1_1_ = s_Failed_to_calloc_work_in_make_wo_0005cd9c[29];
  uStack_7f4._2_1_ = s_Failed_to_calloc_work_in_make_wo_0005cd9c[30];
  uStack_7f4._3_1_ = s_Failed_to_calloc_work_in_make_wo_0005cd9c[31];
  uStack_7f0 = (undefined2)ram0x0005cdbc;
  local_7ee = (undefined)((uint)ram0x0005cdbc >> 0x10);
  _applog(3,&local_810,1);
                    /* WARNING: Subroutine does not return */
  __quit(1);
}


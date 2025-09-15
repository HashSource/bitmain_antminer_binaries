
/* WARNING: Unknown calling convention */

void reset_one_hashboard(int chainIndex)

{
  int iVar1;
  undefined4 extraout_r1;
  undefined4 extraout_r2;
  undefined4 in_r3;
  undefined4 unaff_lr;
  
  set_QN_write_data_command(chainIndex << 0x10 | 0x8000000f);
  while (iVar1 = get_QN_write_data_command(), iVar1 < 0) {
    usleep(10000);
  }
  (*(code *)(undefined *)0x0)(1,extraout_r1,extraout_r2,in_r3,unaff_lr);
  return;
}


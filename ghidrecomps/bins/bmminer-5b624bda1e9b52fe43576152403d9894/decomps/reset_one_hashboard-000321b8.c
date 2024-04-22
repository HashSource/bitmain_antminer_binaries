
/* WARNING: Unknown calling convention */

void reset_one_hashboard(int chainIndex)

{
  int iVar1;
  undefined4 extraout_r1;
  undefined4 in_r2;
  undefined4 in_r3;
  
  set_QN_write_data_command(chainIndex << 0x10 | 0x8000000f);
  while (iVar1 = get_QN_write_data_command(), iVar1 < 0) {
    usleep(10000);
  }
                    /* WARNING: Could not recover jumptable at 0x0000a554. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)PTR_LAB_0005f2f8)(1,extraout_r1,in_r2,in_r3);
  return;
}


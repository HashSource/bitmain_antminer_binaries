
/* WARNING: Unknown calling convention */

void bitmain_c5_reinit_device(cgpu_info *bitmain)

{
  if (*(char *)(DAT_0002a464 + 8) == '\0') {
                    /* WARNING: Could not recover jumptable at 0x0000a128. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*(code *)PTR_LAB_0005f1a4)(DAT_0002a468);
    return;
  }
  return;
}


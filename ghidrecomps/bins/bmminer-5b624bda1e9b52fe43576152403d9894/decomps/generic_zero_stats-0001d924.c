
/* WARNING: Unknown calling convention */

void generic_zero_stats(cgpu_info *cgpu)

{
  *(undefined4 *)&cgpu->diff_rejected = 0;
  *(undefined4 *)((int)&cgpu->diff_rejected + 4) = 0;
  cgpu->hw_errors = 0;
  *(undefined4 *)&cgpu->diff_accepted = 0;
  *(undefined4 *)((int)&cgpu->diff_accepted + 4) = 0;
  return;
}


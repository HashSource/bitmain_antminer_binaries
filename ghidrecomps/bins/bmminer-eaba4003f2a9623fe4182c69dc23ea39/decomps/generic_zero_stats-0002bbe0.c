
void generic_zero_stats(cgpu_info *cgpu)

{
  undefined4 uVar1;
  cgpu_info *cgpu_local;
  
  cgpu->hw_errors = 0;
  *(undefined4 *)&cgpu->diff_rejected = 0;
  *(undefined4 *)((int)&cgpu->diff_rejected + 4) = 0;
  uVar1 = *(undefined4 *)((int)&cgpu->diff_rejected + 4);
  *(undefined4 *)&cgpu->diff_accepted = *(undefined4 *)&cgpu->diff_rejected;
  *(undefined4 *)((int)&cgpu->diff_accepted + 4) = uVar1;
  return;
}


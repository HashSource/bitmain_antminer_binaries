
undefined4 init_ems(int param_1)

{
  uint uVar1;
  
  uVar1 = **(uint **)(param_1 + 0x7c);
  if ((int)(uVar1 << 0x16) < 0) {
    **(uint **)(param_1 + 0x7c) = uVar1 & 0xfffffdff | 0x1000;
  }
  return 1;
}


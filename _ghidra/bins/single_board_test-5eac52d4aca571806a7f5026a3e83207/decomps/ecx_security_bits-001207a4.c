
undefined4 ecx_security_bits(int param_1)

{
  undefined4 uVar1;
  
  if (**(int **)(param_1 + 0xc) == 0x43f || **(int **)(param_1 + 0xc) == 0x40a) {
    uVar1 = 0x80;
  }
  else {
    uVar1 = 0xe0;
  }
  return uVar1;
}


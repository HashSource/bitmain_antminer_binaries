
undefined4 SCT_get0_signature(int param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  
  uVar1 = *(undefined4 *)(param_1 + 0x30);
  *param_2 = *(undefined4 *)(param_1 + 0x2c);
  return uVar1;
}


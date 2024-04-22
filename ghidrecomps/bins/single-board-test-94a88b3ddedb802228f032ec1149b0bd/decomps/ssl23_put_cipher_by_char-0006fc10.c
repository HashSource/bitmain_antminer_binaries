
undefined4 ssl23_put_cipher_by_char(int param_1,undefined *param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = *(int *)(param_1 + 0xc);
  if ((((iVar1 != 0x20 && iVar1 != 0x40) && (iVar1 != 0x80)) && (*(int *)(param_1 + 0x10) != 0x10))
     && (*(int *)(param_1 + 0x10) != 0x40)) {
    if (param_2 != (undefined *)0x0) {
      uVar2 = *(undefined4 *)(param_1 + 8);
      param_2[2] = (char)uVar2;
      *param_2 = (char)((uint)uVar2 >> 0x10);
      param_2[1] = (char)((uint)uVar2 >> 8);
      return 3;
    }
    return 3;
  }
  return 0;
}


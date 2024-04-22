
undefined4 ssl3_put_cipher_by_char(int param_1,undefined *param_2)

{
  uint uVar1;
  
  if (param_2 == (undefined *)0x0) {
    return 2;
  }
  uVar1 = *(uint *)(param_1 + 8);
  if ((uVar1 & 0xff000000) != 0x3000000) {
    return 0;
  }
  param_2[1] = (char)uVar1;
  *param_2 = (char)(uVar1 >> 8);
  return 2;
}



undefined4 ssl2_put_cipher_by_char(int param_1,undefined *param_2)

{
  uint uVar1;
  
  if (param_2 == (undefined *)0x0) {
    return 3;
  }
  uVar1 = *(uint *)(param_1 + 8);
  if (((uVar1 & 0xff000000) != 0x2000000) && (uVar1 != 0x3005600)) {
    return 0;
  }
  param_2[2] = (char)uVar1;
  *param_2 = (char)(uVar1 >> 0x10);
  param_2[1] = (char)(uVar1 >> 8);
  return 3;
}


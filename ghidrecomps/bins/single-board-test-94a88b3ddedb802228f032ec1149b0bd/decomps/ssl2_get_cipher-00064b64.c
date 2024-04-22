
int ssl2_get_cipher(uint param_1)

{
  int iVar1;
  
  if (param_1 < 7) {
    iVar1 = DAT_00064b7c + (6 - param_1) * 0x30;
  }
  else {
    iVar1 = 0;
  }
  return iVar1;
}


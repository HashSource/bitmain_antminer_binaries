
int ssl3_get_cipher(uint param_1)

{
  int iVar1;
  
  if (param_1 < 0x8c) {
    iVar1 = DAT_00069384 + (0x8b - param_1) * 0x30;
  }
  else {
    iVar1 = 0;
  }
  return iVar1;
}


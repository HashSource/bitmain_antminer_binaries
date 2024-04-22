
undefined4 ssl_get_handshake_digest(uint param_1,int *param_2,undefined4 *param_3)

{
  undefined4 uVar1;
  int iVar2;
  
  if (param_1 < 6) {
    iVar2 = *(int *)(DAT_000802b0 + param_1 * 4 + 0x20);
    *param_2 = iVar2;
    if (iVar2 == 0) {
      uVar1 = 1;
      *param_3 = 0;
    }
    else {
      uVar1 = 1;
      *param_3 = *(undefined4 *)(DAT_000802b4 + param_1 * 4 + 0x3c);
    }
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}


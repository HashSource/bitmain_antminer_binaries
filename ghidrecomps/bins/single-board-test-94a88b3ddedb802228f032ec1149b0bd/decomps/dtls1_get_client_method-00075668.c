
undefined4 dtls1_get_client_method(int param_1)

{
  undefined4 uVar1;
  
  if (param_1 == 0xfeff || param_1 == 0x100) {
    return DAT_00075690;
  }
  uVar1 = DAT_0007568c;
  if (param_1 != 0xfefd) {
    uVar1 = 0;
  }
  return uVar1;
}



undefined4 dtls1_get_method(int param_1)

{
  undefined4 uVar1;
  
  if (param_1 != 0xfeff) {
    uVar1 = DAT_00088ae4;
    if (param_1 != 0xfefd) {
      uVar1 = 0;
    }
    return uVar1;
  }
  return DAT_00088ae8;
}


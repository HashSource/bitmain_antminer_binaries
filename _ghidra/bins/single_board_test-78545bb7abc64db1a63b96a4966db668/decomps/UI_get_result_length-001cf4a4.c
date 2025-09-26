
undefined4 UI_get_result_length(int param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  if (param_2 < 0) {
    ERR_put_error(0x28,0x77,0x67,"crypto/ui/ui_lib.c",0x1c0);
  }
  else {
    iVar1 = OPENSSL_sk_num(*(undefined4 *)(param_1 + 4));
    if (param_2 < iVar1) {
      OPENSSL_sk_value(*(undefined4 *)(param_1 + 4),param_2);
      uVar2 = UI_get_result_string_length();
      return uVar2;
    }
    ERR_put_error(0x28,0x77,0x66,"crypto/ui/ui_lib.c",0x1c4);
  }
  return 0xffffffff;
}



char * UI_get0_result(UI *ui,int i)

{
  int iVar1;
  UI_STRING *uis;
  char *pcVar2;
  
  if (i < 0) {
    ERR_put_error(0x28,0x6b,0x67,"crypto/ui/ui_lib.c",0x1b3);
  }
  else {
    iVar1 = OPENSSL_sk_num(*(undefined4 *)(ui + 4));
    if (i < iVar1) {
      uis = (UI_STRING *)OPENSSL_sk_value(*(undefined4 *)(ui + 4),i);
      pcVar2 = UI_get0_result_string(uis);
      return pcVar2;
    }
    ERR_put_error(0x28,0x6b,0x66,"crypto/ui/ui_lib.c",0x1b7);
  }
  return (char *)0x0;
}


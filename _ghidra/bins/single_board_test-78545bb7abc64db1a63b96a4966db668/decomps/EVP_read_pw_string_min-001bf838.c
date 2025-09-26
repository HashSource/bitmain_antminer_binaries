
int EVP_read_pw_string_min(char *buf,int minlen,int maxlen,char *prompt,int verify)

{
  UI *ui;
  int iVar1;
  int iVar2;
  char acStack_2020 [8196];
  
  if ((prompt == (char *)0x0) && (prompt_string != '\0')) {
    prompt = &prompt_string;
  }
  ui = UI_new();
  if (ui == (UI *)0x0) {
    iVar2 = -1;
  }
  else {
    iVar2 = 0x1fff;
    if (maxlen < 0x2000) {
      iVar2 = maxlen;
    }
    iVar1 = UI_add_input_string(ui,prompt,0,buf,minlen,iVar2);
    if ((iVar1 < 0) ||
       ((verify != 0 &&
        (iVar2 = UI_add_verify_string(ui,prompt,0,acStack_2020,minlen,iVar2,buf), iVar2 < 0)))) {
      iVar2 = -1;
    }
    else {
      iVar2 = UI_process(ui);
      OPENSSL_cleanse(acStack_2020,0x2000);
    }
    UI_free(ui);
  }
  return iVar2;
}


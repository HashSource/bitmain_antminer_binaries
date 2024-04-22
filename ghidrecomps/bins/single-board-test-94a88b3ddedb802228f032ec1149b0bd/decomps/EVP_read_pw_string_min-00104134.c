
int EVP_read_pw_string_min(char *buf,int minlen,int maxlen,char *prompt,int verify)

{
  UI *ui;
  int iVar1;
  char acStack_2020 [8196];
  
  if ((prompt == (char *)0x0) && (*DAT_001041c0 != '\0')) {
    prompt = DAT_001041c0;
  }
  ui = UI_new();
  if (0x1ffe < maxlen) {
    maxlen = 0x1fff;
  }
  UI_add_input_string(ui,prompt,0,buf,minlen,maxlen);
  if (verify != 0) {
    UI_add_verify_string(ui,prompt,0,acStack_2020,minlen,maxlen,buf);
  }
  iVar1 = UI_process(ui);
  UI_free(ui);
  OPENSSL_cleanse(acStack_2020,0x2000);
  return iVar1;
}


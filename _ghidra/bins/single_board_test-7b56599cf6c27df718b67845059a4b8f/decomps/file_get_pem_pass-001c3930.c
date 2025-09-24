
size_t file_get_pem_pass(char *param_1,int param_2,undefined4 param_3,undefined4 *param_4)

{
  size_t sVar1;
  UI *ui;
  int iVar2;
  UI_METHOD *meth;
  char *pcVar3;
  void *user_data;
  
  meth = (UI_METHOD *)*param_4;
  pcVar3 = (char *)param_4[2];
  user_data = (void *)param_4[1];
  ui = UI_new();
  if (ui == (UI *)0x0) {
    ERR_put_error(0x2c,0x76,0x41,"crypto/store/loader_file.c",0x36);
    return 0;
  }
  if (meth != (UI_METHOD *)0x0) {
    UI_set_method(ui,meth);
  }
  UI_add_user_data(ui,user_data);
  pcVar3 = UI_construct_prompt(ui,"pass phrase",pcVar3);
  if (pcVar3 == (char *)0x0) {
    ERR_put_error(0x2c,0x76,0x41,"crypto/store/loader_file.c",0x40);
  }
  else {
    iVar2 = UI_add_input_string(ui,pcVar3,2,param_1,0,param_2 + -1);
    if (iVar2 == 0) {
      iVar2 = 0x44;
    }
    else {
      iVar2 = UI_process(ui);
      if (iVar2 == -2) {
        ERR_put_error(0x2c,0x76,0x6d,"crypto/store/loader_file.c",0x4a);
        goto LAB_001c3998;
      }
      if (iVar2 != -1) {
        CRYPTO_free(pcVar3);
        UI_free(ui);
        if (param_1 == (char *)0x0) {
          return 0;
        }
        sVar1 = strlen(param_1);
        return sVar1;
      }
      iVar2 = 0x4e;
    }
    ERR_put_error(0x2c,0x76,0x28,"crypto/store/loader_file.c",iVar2);
  }
LAB_001c3998:
  CRYPTO_free(pcVar3);
  UI_free(ui);
  return 0;
}


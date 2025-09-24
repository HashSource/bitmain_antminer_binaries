
char * file_get_pass(UI_METHOD *param_1,char *param_2,int param_3,char *param_4,void *param_5)

{
  UI *ui;
  char *prompt;
  int iVar1;
  
  ui = UI_new();
  if (ui == (UI *)0x0) {
    ERR_put_error(0x2c,0x76,0x41,"crypto/store/loader_file.c",0x36);
    param_2 = (char *)0x0;
  }
  else {
    if (param_1 != (UI_METHOD *)0x0) {
      UI_set_method(ui,param_1);
    }
    UI_add_user_data(ui,param_5);
    prompt = UI_construct_prompt(ui,"pass phrase",param_4);
    if (prompt == (char *)0x0) {
      ERR_put_error(0x2c,0x76,0x41,"crypto/store/loader_file.c",0x40);
      param_2 = (char *)0x0;
    }
    else {
      iVar1 = UI_add_input_string(ui,prompt,2,param_2,0,param_3 + -1);
      if (iVar1 == 0) {
        ERR_put_error(0x2c,0x76,0x28,"crypto/store/loader_file.c",0x44);
        param_2 = (char *)0x0;
      }
      else {
        iVar1 = UI_process(ui);
        if (iVar1 == -2) {
          param_2 = (char *)0x0;
          ERR_put_error(0x2c,0x76,0x6d,"crypto/store/loader_file.c",0x4a);
        }
        else if (iVar1 == -1) {
          param_2 = (char *)0x0;
          ERR_put_error(0x2c,0x76,0x28,"crypto/store/loader_file.c",0x4e);
        }
      }
    }
    CRYPTO_free(prompt);
    UI_free(ui);
  }
  return param_2;
}


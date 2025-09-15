
void hwcrhk_insert_card(int param_1,char *param_2,int *param_3,int param_4)

{
  UI_METHOD *pUVar1;
  UI *ui;
  uint uVar2;
  UI_METHOD *method;
  void *pvVar3;
  uint uVar4;
  void *user_data;
  char acStack_2020 [8];
  char local_2018 [8192];
  
  if (param_4 == 0) {
    method = (UI_METHOD *)0x0;
    pvVar3 = (void *)0x0;
  }
  else {
    method = *(UI_METHOD **)(param_4 + 4);
    pvVar3 = *(void **)(param_4 + 8);
  }
  user_data = pvVar3;
  if (param_3 != (int *)0x0) {
    pUVar1 = (UI_METHOD *)*param_3;
    if ((UI_METHOD *)*param_3 == (UI_METHOD *)0x0) {
      pUVar1 = method;
    }
    method = pUVar1;
    user_data = (void *)param_3[1];
    if ((void *)param_3[1] == (void *)0x0) {
      user_data = pvVar3;
    }
  }
  if (method == (UI_METHOD *)0x0) {
    if (HWCRHK_lib_error_code == 0) {
      HWCRHK_lib_error_code = ERR_get_next_error_library();
    }
    ERR_put_error(HWCRHK_lib_error_code,0x68,0x6c,"e_chil.c",0x4f0);
  }
  else {
    ui = UI_new_method(method);
    if (ui != (UI *)0x0) {
      if ((param_2 == (char *)0x0) || (*param_2 == '\0')) {
        local_2018[0] = '\0';
      }
      else {
        BIO_snprintf(local_2018,0x1fff,"Current card: \"%s\"\n",param_2);
      }
      uVar2 = UI_dup_info_string(ui,local_2018);
      uVar4 = ~uVar2 >> 0x1f;
      if (param_1 == 0) {
        uVar4 = 0;
      }
      if (uVar4 != 0) {
        BIO_snprintf(local_2018,0x1fff,"Insert card \"%s\"",param_1);
        uVar2 = UI_dup_input_boolean
                          (ui,local_2018,"\n then hit <enter> or C<enter> to cancel\n","\r\n","Cc",1
                           ,acStack_2020);
      }
      UI_add_user_data(ui,user_data);
      if (-1 < (int)uVar2) {
        UI_process(ui);
      }
      UI_free(ui);
    }
  }
  return;
}


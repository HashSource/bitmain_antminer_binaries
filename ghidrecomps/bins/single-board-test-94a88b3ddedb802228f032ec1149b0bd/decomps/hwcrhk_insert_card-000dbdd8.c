
void hwcrhk_insert_card(int param_1,char *param_2,UI_METHOD **param_3,int param_4)

{
  int iVar1;
  UI_METHOD *pUVar2;
  UI *ui;
  uint uVar3;
  int lib;
  UI_METHOD *method;
  UI_METHOD *pUVar4;
  uint uVar5;
  char acStack_2020 [8];
  char local_2018 [8192];
  
  iVar1 = DAT_000dbef8;
  if (param_4 == 0) {
    method = (UI_METHOD *)0x0;
    pUVar4 = (UI_METHOD *)0x0;
  }
  else {
    method = *(UI_METHOD **)(param_4 + 4);
    pUVar4 = *(UI_METHOD **)(param_4 + 8);
  }
  pUVar2 = pUVar4;
  if (param_3 != (UI_METHOD **)0x0) {
    pUVar2 = *param_3;
    if (*param_3 == (UI_METHOD *)0x0) {
      pUVar2 = method;
    }
    method = pUVar2;
    pUVar2 = param_3[1];
    if (param_3[1] == (UI_METHOD *)0x0) {
      pUVar2 = pUVar4;
    }
  }
  if (method == (UI_METHOD *)0x0) {
    lib = *(int *)(DAT_000dbef8 + 0x1c);
    if (lib == 0) {
      lib = ERR_get_next_error_library();
      *(int *)(iVar1 + 0x1c) = lib;
    }
    ERR_put_error(lib,0x68,0x6c,DAT_000dbefc,0x4f0);
  }
  else {
    ui = UI_new_method(method);
    if (ui != (UI *)0x0) {
      if ((param_2 == (char *)0x0) || (*param_2 == '\0')) {
        local_2018[0] = '\0';
      }
      else {
        BIO_snprintf(local_2018,0x1fff,DAT_000dbef4,param_2);
      }
      uVar3 = UI_dup_info_string(ui,local_2018);
      uVar5 = ~uVar3 >> 0x1f;
      if (param_1 == 0) {
        uVar5 = 0;
      }
      if (uVar5 != 0) {
        BIO_snprintf(local_2018,0x1fff,DAT_000dbee4,param_1);
        uVar3 = UI_dup_input_boolean
                          (ui,local_2018,DAT_000dbeec,DAT_000dbef0,DAT_000dbee8,1,acStack_2020);
      }
      UI_add_user_data(ui,pUVar2);
      if (-1 < (int)uVar3) {
        UI_process(ui);
      }
      UI_free(ui);
    }
  }
  return;
}


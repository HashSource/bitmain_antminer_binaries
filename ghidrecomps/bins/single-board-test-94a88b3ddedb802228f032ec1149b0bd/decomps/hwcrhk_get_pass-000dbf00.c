
undefined4
hwcrhk_get_pass(char *param_1,size_t *param_2,char *param_3,UI_METHOD **param_4,code **param_5)

{
  UI *ui_method;
  char *prompt;
  int iVar1;
  size_t sVar2;
  undefined4 uVar3;
  int lib;
  UI_METHOD *method;
  UI_METHOD *pUVar4;
  UI_METHOD *pUVar5;
  uint uVar6;
  code *pcVar7;
  
  iVar1 = DAT_000dc040;
  if ((param_1 != (char *)0x0) && (*param_1 == '\0')) {
    param_1 = (char *)0x0;
  }
  if (param_5 == (code **)0x0) {
    method = (UI_METHOD *)0x0;
    pcVar7 = (code *)0x0;
    pUVar4 = (UI_METHOD *)0x0;
  }
  else {
    method = (UI_METHOD *)param_5[1];
    pcVar7 = *param_5;
    pUVar4 = (UI_METHOD *)param_5[2];
  }
  pUVar5 = pUVar4;
  if (param_4 == (UI_METHOD **)0x0) {
    uVar6 = 1 - (int)pcVar7;
    if ((code *)0x1 < pcVar7) {
      uVar6 = 0;
    }
  }
  else {
    if (*param_4 == (UI_METHOD *)0x0) {
      uVar6 = 1 - (int)pcVar7;
      if ((code *)0x1 < pcVar7) {
        uVar6 = 0;
      }
    }
    else {
      uVar6 = 1;
      pcVar7 = (code *)0x0;
      method = *param_4;
    }
    pUVar5 = param_4[1];
    if (param_4[1] == (UI_METHOD *)0x0) {
      pUVar5 = pUVar4;
    }
  }
  if (method == (UI_METHOD *)0x0) {
    uVar6 = uVar6 & 1;
  }
  else {
    uVar6 = 0;
  }
  if (uVar6 == 0) {
    if (method == (UI_METHOD *)0x0) {
      sVar2 = (*pcVar7)(param_3,*param_2,0,pUVar5);
      *param_2 = sVar2;
    }
    else {
      ui_method = UI_new_method(method);
      if (ui_method != (UI *)0x0) {
        prompt = UI_construct_prompt(ui_method,DAT_000dc03c,param_1);
        iVar1 = UI_add_input_string(ui_method,prompt,2,param_3,0,*param_2 - 1);
        UI_add_user_data(ui_method,pUVar5);
        UI_ctrl(ui_method,1,1,(void *)0x0,(f *)0x0);
        if (-1 < iVar1) {
          do {
            iVar1 = UI_process(ui_method);
            if (-1 < iVar1) {
              sVar2 = strlen(param_3);
              *param_2 = sVar2;
              break;
            }
            iVar1 = UI_ctrl(ui_method,2,0,(void *)0x0,(f *)0x0);
          } while (iVar1 != 0);
        }
        UI_free(ui_method);
        CRYPTO_free(prompt);
      }
      sVar2 = *param_2;
    }
    if (sVar2 == 0) {
      uVar3 = 0xffffffff;
    }
    else {
      uVar3 = 0;
    }
  }
  else {
    lib = *(int *)(DAT_000dc040 + 0x1c);
    if (lib == 0) {
      lib = ERR_get_next_error_library();
      *(int *)(iVar1 + 0x1c) = lib;
    }
    ERR_put_error(lib,0x66,0x6c,DAT_000dc044,0x4b4);
    uVar3 = 0xffffffff;
  }
  return uVar3;
}


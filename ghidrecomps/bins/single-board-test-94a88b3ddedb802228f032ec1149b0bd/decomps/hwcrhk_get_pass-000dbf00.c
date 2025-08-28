
undefined4 hwcrhk_get_pass(char *param_1,size_t *param_2,char *param_3,uint *param_4,uint *param_5)

{
  UI *ui_method;
  char *prompt;
  int iVar1;
  size_t sVar2;
  undefined4 uVar3;
  UI_METHOD *method;
  void *pvVar4;
  void *pvVar5;
  uint uVar6;
  code *pcVar7;
  
  if ((param_1 != (char *)0x0) && (*param_1 == '\0')) {
    param_1 = (char *)0x0;
  }
  if (param_5 == (uint *)0x0) {
    method = (UI_METHOD *)0x0;
    pcVar7 = (code *)0x0;
    pvVar4 = (void *)0x0;
  }
  else {
    method = (UI_METHOD *)param_5[1];
    pcVar7 = (code *)*param_5;
    pvVar4 = (void *)param_5[2];
  }
  pvVar5 = pvVar4;
  if (param_4 == (uint *)0x0) {
    uVar6 = 1 - (int)pcVar7;
    if ((code *)0x1 < pcVar7) {
      uVar6 = 0;
    }
  }
  else {
    if ((UI_METHOD *)*param_4 == (UI_METHOD *)0x0) {
      uVar6 = 1 - (int)pcVar7;
      if ((code *)0x1 < pcVar7) {
        uVar6 = 0;
      }
    }
    else {
      uVar6 = 1;
      pcVar7 = (code *)0x0;
      method = (UI_METHOD *)*param_4;
    }
    pvVar5 = (void *)param_4[1];
    if ((void *)param_4[1] == (void *)0x0) {
      pvVar5 = pvVar4;
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
      sVar2 = (*pcVar7)(param_3,*param_2,0,pvVar5);
      *param_2 = sVar2;
    }
    else {
      ui_method = UI_new_method(method);
      if (ui_method != (UI *)0x0) {
        prompt = UI_construct_prompt(ui_method,"pass phrase",param_1);
        iVar1 = UI_add_input_string(ui_method,prompt,2,param_3,0,*param_2 - 1);
        UI_add_user_data(ui_method,pvVar5);
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
    if (HWCRHK_lib_error_code == 0) {
      HWCRHK_lib_error_code = ERR_get_next_error_library();
    }
    ERR_put_error(HWCRHK_lib_error_code,0x66,0x6c,"e_chil.c",0x4b4);
    uVar3 = 0xffffffff;
  }
  return uVar3;
}


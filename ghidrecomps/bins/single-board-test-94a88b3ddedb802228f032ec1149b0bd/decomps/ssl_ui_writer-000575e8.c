
undefined4 ssl_ui_writer(UI *param_1,UI_STRING *param_2,undefined4 param_3,undefined4 param_4)

{
  UI_string_types UVar1;
  void *pvVar2;
  int iVar3;
  UI_METHOD *pUVar4;
  code *pcVar5;
  undefined4 uVar6;
  UI_STRING *extraout_r1;
  
  UVar1 = UI_get_string_type(param_2);
  if (((UVar1 + ~UIT_NONE < 2) && (pvVar2 = UI_get0_user_data(param_1), pvVar2 != (void *)0x0)) &&
     (iVar3 = UI_get_input_flags(param_2), iVar3 << 0x1e < 0)) {
    return 1;
  }
  pUVar4 = UI_OpenSSL();
  pcVar5 = (code *)UI_method_get_writer((UI *)pUVar4,extraout_r1);
  uVar6 = (*pcVar5)(param_1,param_2,param_3,pcVar5,param_4);
  return uVar6;
}



undefined4 ssl_ui_reader(UI *param_1,UI_STRING *param_2)

{
  UI_string_types UVar1;
  char *result;
  int iVar2;
  UI_METHOD *pUVar3;
  code *pcVar4;
  undefined4 uVar5;
  UI_STRING *extraout_r1;
  
  UVar1 = UI_get_string_type(param_2);
  if (((UVar1 + ~UIT_NONE < 2) &&
      (result = (char *)UI_get0_user_data(param_1), result != (char *)0x0)) &&
     (iVar2 = UI_get_input_flags(param_2), iVar2 << 0x1e < 0)) {
    UI_set_result(param_1,param_2,result);
    return 1;
  }
  pUVar3 = UI_OpenSSL();
  pcVar4 = (code *)UI_method_get_reader((UI *)pUVar3,extraout_r1);
  uVar5 = (*pcVar4)(param_1,param_2);
  return uVar5;
}



undefined4
sasl_create_login_message(undefined4 param_1,char *param_2,int *param_3,undefined4 *param_4)

{
  size_t sVar1;
  int iVar2;
  undefined4 uVar3;
  
  sVar1 = strlen(param_2);
  if (sVar1 == 0) {
    iVar2 = (**DAT_00055314)(DAT_00055318);
    *param_3 = iVar2;
    if (iVar2 == 0) {
      *param_4 = 0;
      uVar3 = 0x1b;
    }
    else {
      *param_4 = 1;
      uVar3 = 0;
    }
  }
  else {
    uVar3 = Curl_base64_encode(param_1,param_2,sVar1,param_3,param_4);
  }
  return uVar3;
}


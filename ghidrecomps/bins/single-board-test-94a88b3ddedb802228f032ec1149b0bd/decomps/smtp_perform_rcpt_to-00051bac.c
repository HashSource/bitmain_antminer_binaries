
void smtp_perform_rcpt_to(int *param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  uVar2 = DAT_00051bd8;
  if (***(char ***)(*(int *)(*param_1 + 0x14c) + 8) != '<') {
    uVar2 = DAT_00051bdc;
  }
  iVar1 = Curl_pp_sendf(param_1 + 0xf0,uVar2);
  if (iVar1 == 0) {
    param_1[0xfe] = 9;
  }
  return;
}



void Curl_wildcard_dtor(undefined4 *param_1)

{
  code **ppcVar1;
  code *pcVar2;
  
  if (param_1 != (undefined4 *)0x0) {
    if ((code *)param_1[5] != (code *)0x0) {
      (*(code *)param_1[5])(param_1[4]);
      param_1[5] = 0;
      param_1[4] = 0;
    }
    if (param_1[3] != 0) {
      Curl_llist_destroy(param_1[3],0);
      param_1[3] = 0;
    }
    ppcVar1 = DAT_0004c4e8;
    (**DAT_0004c4e8)(param_1[1]);
    pcVar2 = *ppcVar1;
    param_1[1] = 0;
    (*pcVar2)(param_1[2]);
    param_1[2] = 0;
    param_1[6] = 0;
    *param_1 = 0;
  }
  return;
}


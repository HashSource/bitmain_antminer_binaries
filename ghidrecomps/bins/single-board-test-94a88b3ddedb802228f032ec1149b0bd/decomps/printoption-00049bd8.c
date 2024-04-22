
void printoption(int param_1,undefined4 param_2,int param_3,int param_4)

{
  int iVar1;
  undefined4 uVar2;
  
  if (*(char *)(param_1 + 0x310) == '\0') {
    return;
  }
  if (param_3 == 0xff) {
    if (param_4 - 0xecU < 0x14) {
      Curl_infof(param_1,DAT_00049c80,param_2,
                 *(undefined4 *)(DAT_00049c7c + (param_4 - 0xecU) * 4 + 0xa0));
      return;
    }
    Curl_infof(param_1,DAT_00049c98,param_2);
    return;
  }
  uVar2 = DAT_00049c90;
  if ((((param_3 != 0xfb) && (uVar2 = DAT_00049c94, param_3 != 0xfc)) &&
      (uVar2 = DAT_00049c84, param_3 != 0xfd)) && (uVar2 = DAT_00049ca0, param_3 != 0xfe)) {
    Curl_infof(param_1,DAT_00049c78,param_2,param_3,param_4);
    return;
  }
  if (param_4 < 0x28) {
    iVar1 = *(int *)(DAT_00049c7c + param_4 * 4);
    if (iVar1 == 0) {
LAB_00049c4c:
      Curl_infof(param_1,DAT_00049c8c,param_2,uVar2,param_4);
      return;
    }
  }
  else {
    iVar1 = DAT_00049c9c;
    if (param_4 != 0xff) goto LAB_00049c4c;
  }
  Curl_infof(param_1,DAT_00049c88,param_2,uVar2,iVar1);
  return;
}


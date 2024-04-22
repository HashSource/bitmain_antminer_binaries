
undefined4 Curl_meets_timecondition(int param_1,int param_2)

{
  undefined4 uVar1;
  int iVar2;
  
  if ((param_2 != 0) && (iVar2 = *(int *)(param_1 + 0x274), iVar2 != 0)) {
    if (*(int *)(param_1 + 0x270) == 2) {
      uVar1 = DAT_0004b080;
      if (iVar2 <= param_2) goto LAB_0004b06a;
    }
    else {
      uVar1 = DAT_0004b07c;
      if (param_2 <= iVar2) {
LAB_0004b06a:
        Curl_infof(param_1,uVar1);
        *(undefined *)(param_1 + 0x8704) = 1;
        return 0;
      }
    }
  }
  return 1;
}


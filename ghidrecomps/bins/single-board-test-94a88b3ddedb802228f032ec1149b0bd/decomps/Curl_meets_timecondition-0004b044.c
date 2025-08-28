
undefined4 Curl_meets_timecondition(int param_1,int param_2)

{
  char *pcVar1;
  int iVar2;
  
  if ((param_2 != 0) && (iVar2 = *(int *)(param_1 + 0x274), iVar2 != 0)) {
    if (*(int *)(param_1 + 0x270) == 2) {
      if (iVar2 <= param_2) {
        pcVar1 = "The requested document is not old enough\n";
        goto LAB_0004b06a;
      }
    }
    else if (param_2 <= iVar2) {
      pcVar1 = "The requested document is not new enough\n";
LAB_0004b06a:
      Curl_infof(param_1,pcVar1);
      *(undefined1 *)(param_1 + 0x8704) = 1;
      return 0;
    }
  }
  return 1;
}


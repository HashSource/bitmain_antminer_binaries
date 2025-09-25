
int SCT_is_complete(int *param_1)

{
  int iVar1;
  
  if (*param_1 == -1) {
    return 0;
  }
  if (*param_1 == 0) {
    if (param_1[3] != 0) {
      iVar1 = SCT_signature_is_complete();
      if (iVar1 != 0) {
        iVar1 = 1;
      }
      return iVar1;
    }
    return 0;
  }
  iVar1 = param_1[1];
  if (iVar1 != 0) {
    iVar1 = 1;
  }
  return iVar1;
}


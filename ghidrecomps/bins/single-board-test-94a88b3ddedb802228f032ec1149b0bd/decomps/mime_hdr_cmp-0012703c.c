
int mime_hdr_cmp(undefined4 *param_1,undefined4 *param_2)

{
  int iVar1;
  
  iVar1 = *(int *)*param_2;
  if ((*(int *)*param_1 != 0) && (iVar1 != 0)) {
    iVar1 = (*(code *)(undefined *)0x0)();
    return iVar1;
  }
  if (iVar1 != 0) {
    iVar1 = 1;
  }
  if (*(int *)*param_1 == 0) {
    iVar1 = -iVar1;
  }
  else {
    iVar1 = 1 - iVar1;
  }
  return iVar1;
}


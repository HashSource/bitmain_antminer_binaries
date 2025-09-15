
undefined4 Curl_formpostheader(int *param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  int *piVar2;
  int iVar3;
  
  piVar2 = (int *)*param_1;
  if (piVar2 == (int *)0x0) {
    uVar1 = 0;
  }
  else {
    iVar3 = *piVar2;
    uVar1 = piVar2[2];
    *param_2 = piVar2[3];
    *param_1 = iVar3;
  }
  return uVar1;
}



int * Curl_MD5_init(code **param_1)

{
  code **ppcVar1;
  int *piVar2;
  int iVar3;
  
  ppcVar1 = DAT_0005f5a8;
  piVar2 = (int *)(**DAT_0005f5a8)(8);
  if (piVar2 != (int *)0x0) {
    iVar3 = (**ppcVar1)(param_1[3]);
    piVar2[1] = iVar3;
    if (iVar3 == 0) {
      (**DAT_0005f5ac)(piVar2);
      piVar2 = (int *)0x0;
    }
    else {
      *piVar2 = (int)param_1;
      (**param_1)();
    }
  }
  return piVar2;
}


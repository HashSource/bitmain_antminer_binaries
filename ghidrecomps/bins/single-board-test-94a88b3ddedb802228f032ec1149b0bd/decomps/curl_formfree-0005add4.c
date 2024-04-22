
void curl_formfree(int *param_1)

{
  code **ppcVar1;
  uint uVar2;
  int *piVar3;
  
  ppcVar1 = DAT_0005ae20;
  if (param_1 != (int *)0x0) {
    do {
      piVar3 = (int *)*param_1;
      curl_formfree(param_1[9]);
      uVar2 = param_1[10];
      if (-1 < (int)(uVar2 << 0x1d)) {
        (**ppcVar1)(param_1[1]);
        uVar2 = param_1[10];
      }
      if ((uVar2 & 0x58) == 0) {
        (**ppcVar1)(param_1[3]);
      }
      (**ppcVar1)(param_1[7]);
      (**ppcVar1)(param_1[0xb]);
      (**ppcVar1)(param_1);
      param_1 = piVar3;
    } while (piVar3 != (int *)0x0);
  }
  return;
}


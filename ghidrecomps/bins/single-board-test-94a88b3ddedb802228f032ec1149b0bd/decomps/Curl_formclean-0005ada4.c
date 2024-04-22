
void Curl_formclean(int **param_1)

{
  code **ppcVar1;
  int *piVar2;
  int *piVar3;
  
  ppcVar1 = DAT_0005add0;
  piVar2 = *param_1;
  if (piVar2 != (int *)0x0) {
    do {
      piVar3 = (int *)*piVar2;
      if ((uint)piVar2[1] < 2) {
        (**ppcVar1)(piVar2[2]);
      }
      (**ppcVar1)(piVar2);
      piVar2 = piVar3;
    } while (piVar3 != (int *)0x0);
    *param_1 = (int *)0x0;
  }
  return;
}


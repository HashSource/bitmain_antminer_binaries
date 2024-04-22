
undefined4 Curl_ip2addr(int param_1,int *param_2,undefined4 param_3,undefined4 param_4)

{
  code **ppcVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  undefined4 uVar7;
  int iVar8;
  
  piVar2 = (int *)(**DAT_0004f830)(0x2c);
  if (piVar2 == (int *)0x0) {
    return 0;
  }
  iVar3 = (**DAT_0004f834)(param_3);
  if (iVar3 == 0) {
    (**DAT_0004f838)(piVar2);
    return 0;
  }
  if (param_1 == 2) {
    iVar4 = 4;
    piVar2[5] = *param_2;
  }
  else {
    if (param_1 != 10) {
      uVar7 = 0;
      goto LAB_0004f7c0;
    }
    iVar4 = 0x10;
    iVar8 = param_2[1];
    iVar5 = param_2[2];
    iVar6 = param_2[3];
    piVar2[5] = *param_2;
    piVar2[6] = iVar8;
    piVar2[7] = iVar5;
    piVar2[8] = iVar6;
  }
  piVar2[3] = iVar4;
  piVar2[2] = (int)(short)param_1;
  piVar2[4] = (int)(piVar2 + 9);
  *piVar2 = iVar3;
  piVar2[9] = (int)(piVar2 + 5);
  piVar2[1] = 0;
  piVar2[10] = 0;
  uVar7 = Curl_he2ai(piVar2,param_4);
LAB_0004f7c0:
  ppcVar1 = DAT_0004f838;
  (**DAT_0004f838)(iVar3);
  (**ppcVar1)(piVar2);
  return uVar7;
}


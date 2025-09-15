
undefined4 Curl_ip2addr(int param_1,int *param_2,undefined4 param_3,undefined4 param_4)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  undefined4 uVar6;
  int iVar7;
  
  piVar1 = (int *)(*Curl_cmalloc)(0x2c);
  if (piVar1 == (int *)0x0) {
    return 0;
  }
  iVar2 = (*Curl_cstrdup)(param_3);
  if (iVar2 == 0) {
    (*Curl_cfree)(piVar1);
    return 0;
  }
  if (param_1 == 2) {
    iVar3 = 4;
    piVar1[5] = *param_2;
  }
  else {
    if (param_1 != 10) {
      uVar6 = 0;
      goto LAB_0004f7c0;
    }
    iVar3 = 0x10;
    iVar7 = param_2[1];
    iVar4 = param_2[2];
    iVar5 = param_2[3];
    piVar1[5] = *param_2;
    piVar1[6] = iVar7;
    piVar1[7] = iVar4;
    piVar1[8] = iVar5;
  }
  piVar1[3] = iVar3;
  piVar1[2] = (int)(short)param_1;
  piVar1[4] = (int)(piVar1 + 9);
  *piVar1 = iVar2;
  piVar1[9] = (int)(piVar1 + 5);
  piVar1[1] = 0;
  piVar1[10] = 0;
  uVar6 = Curl_he2ai(piVar1,param_4);
LAB_0004f7c0:
  (*Curl_cfree)(iVar2);
  (*Curl_cfree)(piVar1);
  return uVar6;
}


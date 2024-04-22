
void Curl_persistconninfo(int *param_1)

{
  int *piVar1;
  int *piVar2;
  int *piVar3;
  int *piVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  
  piVar2 = (int *)(*param_1 + 0x8724);
  piVar3 = param_1 + 0x2e;
  do {
    piVar4 = piVar3;
    piVar1 = piVar2;
    iVar7 = piVar4[1];
    iVar6 = piVar4[2];
    iVar5 = piVar4[3];
    piVar3 = piVar4 + 4;
    *piVar1 = *piVar4;
    piVar1[1] = iVar7;
    piVar1[2] = iVar6;
    piVar1[3] = iVar5;
    piVar2 = piVar1 + 4;
  } while (piVar3 != param_1 + 0x36);
  iVar6 = piVar4[5];
  iVar5 = piVar4[6];
  piVar1[4] = *piVar3;
  piVar1[5] = iVar6;
  piVar1[6] = iVar5;
  *(undefined2 *)(piVar1 + 7) = *(undefined2 *)(piVar4 + 7);
  piVar2 = param_1 + 0x3b;
  piVar3 = (int *)(*param_1 + 0x8758);
  do {
    piVar4 = piVar3;
    piVar1 = piVar2;
    iVar7 = piVar1[1];
    iVar6 = piVar1[2];
    iVar5 = piVar1[3];
    piVar2 = piVar1 + 4;
    *piVar4 = *piVar1;
    piVar4[1] = iVar7;
    piVar4[2] = iVar6;
    piVar4[3] = iVar5;
    piVar3 = piVar4 + 4;
  } while (piVar2 != param_1 + 0x43);
  iVar6 = *piVar2;
  iVar5 = piVar1[5];
  piVar4[6] = piVar1[6];
  piVar4[4] = iVar6;
  piVar4[5] = iVar5;
  *(undefined2 *)(piVar4 + 7) = *(undefined2 *)(piVar1 + 7);
  iVar6 = *param_1;
  iVar5 = param_1[0x47];
  *(int *)(iVar6 + 0x8754) = param_1[0x3a];
  *(int *)(iVar6 + 0x8788) = iVar5;
  return;
}


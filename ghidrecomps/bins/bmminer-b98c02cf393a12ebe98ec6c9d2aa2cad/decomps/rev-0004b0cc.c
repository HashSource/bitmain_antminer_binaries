
void rev(undefined *param_1,int param_2)

{
  undefined uVar1;
  undefined *puVar2;
  uint uVar3;
  undefined *puVar4;
  undefined *puVar5;
  
  uVar3 = param_2 - 1;
  if (uVar3 != 0) {
    puVar2 = param_1 + param_2;
    puVar4 = param_1;
    do {
      uVar3 = uVar3 - 1;
      uVar1 = *puVar4;
      puVar5 = puVar4 + 1;
      *puVar4 = puVar2[-1];
      puVar2 = puVar2 + -1;
      *puVar2 = uVar1;
      puVar4 = puVar5;
    } while ((uint)((int)puVar5 - (int)param_1) < uVar3);
  }
  return;
}


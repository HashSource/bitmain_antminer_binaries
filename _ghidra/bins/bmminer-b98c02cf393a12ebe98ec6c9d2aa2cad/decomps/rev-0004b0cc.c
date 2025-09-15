
void rev(undefined1 *param_1,int param_2)

{
  undefined1 uVar1;
  undefined1 *puVar2;
  uint uVar3;
  undefined1 *puVar4;
  undefined1 *puVar5;
  
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


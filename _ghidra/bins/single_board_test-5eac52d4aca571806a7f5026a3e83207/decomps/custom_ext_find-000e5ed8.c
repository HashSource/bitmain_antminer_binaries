
ushort * custom_ext_find(undefined4 *param_1,int param_2,uint param_3,int *param_4)

{
  ushort *puVar1;
  int iVar2;
  int iVar3;
  
  puVar1 = (ushort *)*param_1;
  iVar3 = param_1[1];
  if (iVar3 != 0) {
    iVar2 = 0;
    if (param_2 == 2) {
      do {
        if (*puVar1 == param_3) {
LAB_000e5f00:
          if (param_4 != (int *)0x0) {
            *param_4 = iVar2;
            return puVar1;
          }
          return puVar1;
        }
        iVar2 = iVar2 + 1;
        puVar1 = puVar1 + 0x12;
      } while (iVar2 != iVar3);
    }
    else {
      do {
        if ((param_3 == *puVar1) && (param_2 == *(int *)(puVar1 + 2) || *(int *)(puVar1 + 2) == 2))
        goto LAB_000e5f00;
        iVar2 = iVar2 + 1;
        puVar1 = puVar1 + 0x12;
      } while (iVar3 != iVar2);
    }
  }
  return (ushort *)0x0;
}


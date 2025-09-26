
undefined4
ec_GF2m_simple_points_make_affine(int *param_1,int param_2,int param_3,undefined4 param_4)

{
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 uVar4;
  
  if (param_2 == 0) {
    return 1;
  }
  puVar3 = (undefined4 *)(param_3 + -4);
  iVar2 = 0;
  uVar4 = param_4;
  do {
    puVar3 = puVar3 + 1;
    iVar2 = iVar2 + 1;
    iVar1 = (**(code **)(*param_1 + 0x74))
                      (param_1,*puVar3,param_4,*(code **)(*param_1 + 0x74),uVar4);
    if (iVar1 == 0) {
      return 0;
    }
  } while (param_2 != iVar2);
  return 1;
}


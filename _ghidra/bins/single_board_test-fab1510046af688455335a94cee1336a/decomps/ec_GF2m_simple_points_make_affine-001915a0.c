
undefined4
ec_GF2m_simple_points_make_affine(int *param_1,int param_2,int param_3,undefined4 param_4)

{
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  
  if (param_2 != 0) {
    puVar3 = (undefined4 *)(param_3 + -4);
    iVar2 = 0;
    do {
      puVar3 = puVar3 + 1;
      iVar2 = iVar2 + 1;
      iVar1 = (**(code **)(*param_1 + 0x70))(param_1,*puVar3,param_4);
      if (iVar1 == 0) {
        return 0;
      }
    } while (iVar2 != param_2);
  }
  return 1;
}


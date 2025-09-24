
int ec_GF2m_simple_ladder_step(int *param_1,int param_2,int param_3,int param_4,undefined4 param_5)

{
  int iVar1;
  
  iVar1 = (**(code **)(*param_1 + 0x88))
                    (param_1,*(undefined4 *)(param_2 + 0xc),*(undefined4 *)(param_2 + 0x10),
                     *(undefined4 *)(param_3 + 8),param_5);
  if (((((iVar1 == 0) ||
        (iVar1 = (**(code **)(*param_1 + 0x88))
                           (param_1,*(undefined4 *)(param_3 + 8),*(undefined4 *)(param_2 + 8),
                            *(undefined4 *)(param_3 + 0x10),param_5), iVar1 == 0)) ||
       (iVar1 = (**(code **)(*param_1 + 0x8c))
                          (param_1,*(undefined4 *)(param_3 + 0xc),*(undefined4 *)(param_2 + 0x10),
                           param_5), iVar1 == 0)) ||
      (((iVar1 = (**(code **)(*param_1 + 0x8c))
                           (param_1,*(undefined4 *)(param_2 + 0x10),*(undefined4 *)(param_2 + 8),
                            param_5), iVar1 == 0 ||
        (iVar1 = BN_GF2m_add(*(undefined4 *)(param_3 + 0x10),*(undefined4 *)(param_2 + 0xc),
                             *(undefined4 *)(param_3 + 8)), iVar1 == 0)) ||
       ((iVar1 = (**(code **)(*param_1 + 0x8c))
                           (param_1,*(undefined4 *)(param_3 + 0x10),*(undefined4 *)(param_3 + 0x10),
                            param_5), iVar1 == 0 ||
        ((iVar1 = (**(code **)(*param_1 + 0x88))
                            (param_1,*(undefined4 *)(param_3 + 8),*(undefined4 *)(param_2 + 0xc),
                             *(undefined4 *)(param_3 + 8),param_5), iVar1 == 0 ||
         (iVar1 = (**(code **)(*param_1 + 0x88))
                            (param_1,*(undefined4 *)(param_2 + 0xc),*(undefined4 *)(param_3 + 0x10),
                             *(undefined4 *)(param_4 + 8),param_5), iVar1 == 0)))))))) ||
     ((iVar1 = BN_GF2m_add(*(undefined4 *)(param_3 + 8),*(undefined4 *)(param_3 + 8),
                           *(undefined4 *)(param_2 + 0xc)), iVar1 == 0 ||
      ((((iVar1 = (**(code **)(*param_1 + 0x8c))
                            (param_1,*(undefined4 *)(param_2 + 0xc),*(undefined4 *)(param_2 + 0x10),
                             param_5), iVar1 == 0 ||
         (iVar1 = (**(code **)(*param_1 + 0x88))
                            (param_1,*(undefined4 *)(param_2 + 0x10),*(undefined4 *)(param_2 + 0x10)
                             ,*(undefined4 *)(param_3 + 0xc),param_5), iVar1 == 0)) ||
        (iVar1 = (**(code **)(*param_1 + 0x8c))
                           (param_1,*(undefined4 *)(param_3 + 0xc),*(undefined4 *)(param_3 + 0xc),
                            param_5), iVar1 == 0)) ||
       (iVar1 = (**(code **)(*param_1 + 0x88))
                          (param_1,*(undefined4 *)(param_3 + 0xc),*(undefined4 *)(param_3 + 0xc),
                           param_1[0x12],param_5), iVar1 == 0)))))) {
    iVar1 = 0;
  }
  else {
    iVar1 = BN_GF2m_add(*(undefined4 *)(param_2 + 8),*(undefined4 *)(param_2 + 0xc),
                        *(undefined4 *)(param_3 + 0xc));
    if (iVar1 != 0) {
      iVar1 = 1;
    }
  }
  return iVar1;
}


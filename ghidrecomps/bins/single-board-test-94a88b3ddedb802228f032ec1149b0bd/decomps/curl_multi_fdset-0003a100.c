
undefined4 curl_multi_fdset(int *param_1,uint param_2,int param_3,undefined4 param_4,uint *param_5)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  int **ppiVar8;
  uint unaff_r11;
  uint local_3c [6];
  
  if ((param_1 == (int *)0x0) || (*param_1 != 0xbab1e)) {
    uVar1 = 1;
  }
  else {
    ppiVar8 = (int **)param_1[1];
    uVar7 = 0xffffffff;
    if (ppiVar8 != (int **)0x0) {
LAB_0003a13a:
      do {
        iVar2 = multi_getsock_constprop_6(ppiVar8,local_3c);
        iVar3 = 0;
        uVar4 = 0;
        do {
          uVar5 = 0xffffffff;
          if ((iVar2 >> (uVar4 & 0xff)) << 0x1f < 0) {
            uVar5 = *(uint *)((int)local_3c + iVar3);
            if (uVar5 < 0x400) {
              unaff_r11 = param_2;
            }
            if (uVar5 < 0x400) {
              *(uint *)(unaff_r11 + ((int)uVar5 >> 5) * 4) =
                   *(uint *)(unaff_r11 + ((int)uVar5 >> 5) * 4) | 1 << (uVar5 & 0x1f);
            }
            else {
              uVar5 = 0xffffffff;
            }
          }
          if ((iVar2 >> (uVar4 + 0x10 & 0xff) & 1U) == 0) {
LAB_0003a1d2:
            if (uVar5 == 0xffffffff) {
              ppiVar8 = (int **)*ppiVar8;
              if (ppiVar8 == (int **)0x0) goto LAB_0003a1c6;
              goto LAB_0003a13a;
            }
          }
          else {
            uVar6 = *(uint *)((int)local_3c + iVar3);
            unaff_r11 = 1 << (uVar6 & 0x1f);
            if (0x3ff < uVar6) goto LAB_0003a1d2;
            *(uint *)(param_3 + ((int)uVar6 >> 5) * 4) =
                 *(uint *)(param_3 + ((int)uVar6 >> 5) * 4) | unaff_r11;
            uVar5 = uVar6;
          }
          uVar4 = uVar4 + 1;
          if ((int)uVar7 < (int)uVar5) {
            uVar7 = uVar5;
          }
          iVar3 = iVar3 + 4;
        } while (uVar4 != 5);
        ppiVar8 = (int **)*ppiVar8;
      } while (ppiVar8 != (int **)0x0);
    }
LAB_0003a1c6:
    uVar1 = 0;
    *param_5 = uVar7;
  }
  return uVar1;
}



int o2i_SCT_LIST(int *param_1,undefined4 *param_2,int param_3)

{
  undefined1 uVar1;
  undefined1 uVar2;
  int iVar3;
  int iVar4;
  undefined1 *puVar5;
  uint uVar6;
  int iVar7;
  int iVar8;
  uint uVar9;
  
  uVar6 = param_3 - 2;
  if (uVar6 < 0xfffe) {
    puVar5 = (undefined1 *)*param_2;
    uVar1 = *puVar5;
    uVar2 = puVar5[1];
    *param_2 = puVar5 + 2;
    if (uVar6 == CONCAT11(uVar1,uVar2)) {
      if ((param_1 == (int *)0x0) || (iVar8 = *param_1, iVar8 == 0)) {
        iVar8 = OPENSSL_sk_new_null();
        if (iVar8 == 0) {
          return 0;
        }
        if (param_3 != 2) goto LAB_001107da;
LAB_00110866:
        if (param_1 == (int *)0x0) {
          return iVar8;
        }
      }
      else {
        while (iVar4 = OPENSSL_sk_pop(iVar8), iVar4 != 0) {
          SCT_free();
        }
        if (param_3 != 2) {
LAB_001107da:
          if (uVar6 < 2) {
LAB_00110874:
            iVar4 = 0x123;
          }
          else {
            puVar5 = (undefined1 *)*param_2;
            uVar9 = param_3 - 4;
            uVar1 = *puVar5;
            uVar2 = puVar5[1];
            *param_2 = puVar5 + 2;
            uVar6 = (uint)CONCAT11(uVar1,uVar2);
            if (uVar6 <= uVar9 && uVar6 != 0) {
              do {
                iVar7 = uVar9 - uVar6;
                iVar4 = o2i_SCT(0,param_2,uVar6);
                if (iVar4 == 0) goto LAB_0011084a;
                iVar3 = OPENSSL_sk_push(iVar8,iVar4);
                if (iVar3 == 0) {
                  SCT_free(iVar4);
                  goto LAB_0011084a;
                }
                uVar9 = iVar7 - 2;
                if (iVar7 == 0) goto LAB_00110866;
                if (iVar7 == 1) goto LAB_00110874;
                puVar5 = (undefined1 *)*param_2;
                uVar1 = *puVar5;
                uVar2 = puVar5[1];
                *param_2 = puVar5 + 2;
                uVar6 = (uint)CONCAT11(uVar1,uVar2);
              } while (uVar6 <= uVar9 && uVar6 != 0);
            }
            iVar4 = 0x12a;
          }
          ERR_put_error(0x32,0x6f,0x69,"crypto/ct/ct_oct.c",iVar4);
LAB_0011084a:
          if ((param_1 == (int *)0x0) || (*param_1 == 0)) {
            SCT_LIST_free(iVar8);
          }
          return 0;
        }
      }
      if (*param_1 != 0) {
        return iVar8;
      }
      *param_1 = iVar8;
      return iVar8;
    }
    iVar8 = 0x10e;
  }
  else {
    iVar8 = 0x108;
  }
  ERR_put_error(0x32,0x6f,0x69,"crypto/ct/ct_oct.c",iVar8);
  return 0;
}


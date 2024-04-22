
undefined4 surewarehk_dsa_do_sign(undefined4 param_1,undefined4 param_2,DSA *param_3)

{
  int iVar1;
  void *pvVar2;
  DSA_SIG *a;
  BIGNUM *pBVar3;
  undefined4 uVar4;
  int iVar5;
  BIGNUM *pBVar6;
  ulong *puVar7;
  ulong uVar8;
  undefined4 local_60;
  undefined4 uStack_5c;
  undefined4 uStack_58;
  undefined4 uStack_54;
  undefined2 uStack_50;
  undefined local_4e;
  undefined auStack_4d [49];
  
  iVar1 = DAT_000ddd2c;
  local_60 = *DAT_000ddd28;
  uStack_5c = DAT_000ddd28[1];
  uStack_58 = DAT_000ddd28[2];
  uStack_54 = DAT_000ddd28[3];
  uStack_50 = (undefined2)DAT_000ddd28[4];
  local_4e = (undefined)((uint)DAT_000ddd28[4] >> 0x10);
  memset(auStack_4d,0,0x2d);
  if (*(int *)(iVar1 + 0x3c) == 0) {
    iVar5 = *(int *)(iVar1 + 4);
    if (iVar5 == 0) {
      iVar5 = ERR_get_next_error_library();
      *(int *)(iVar1 + 4) = iVar5;
    }
    ERR_put_error(iVar5,0x65,0x75,DAT_000ddd34,0x404);
  }
  else {
    pvVar2 = DSA_get_ex_data(param_3,*(int *)(DAT_000ddd30 + 0xd8));
    if (pvVar2 == (void *)0x0) {
      iVar5 = *(int *)(iVar1 + 4);
      if (iVar5 == 0) {
        iVar5 = ERR_get_next_error_library();
        *(int *)(iVar1 + 4) = iVar5;
      }
      ERR_put_error(iVar5,0x65,0x69,DAT_000ddd34,0x40a);
    }
    else {
      a = DSA_SIG_new();
      if (a == (DSA_SIG *)0x0) {
        iVar5 = *(int *)(iVar1 + 4);
        if (iVar5 == 0) {
          iVar5 = ERR_get_next_error_library();
          *(int *)(iVar1 + 4) = iVar5;
        }
        ERR_put_error(iVar5,0x65,0x41,DAT_000ddd34,0x40f);
      }
      else {
        pBVar3 = BN_new();
        a->r = pBVar3;
        pBVar3 = BN_new();
        a->s = pBVar3;
        if ((a->r != (BIGNUM *)0x0) && (pBVar3 != (BIGNUM *)0x0)) {
          bn_expand2(a->r,5);
          bn_expand2(a->s,5);
          if (a->r->dmax == 5) {
            if (a->s->dmax == 5) {
              uVar4 = (**(code **)(iVar1 + 0x3c))(&local_60,param_2,param_1,a->r->d,a->s->d,pvVar2);
              surewarehk_error_handling(&local_60,0x65,uVar4);
              pBVar3 = a->r;
              puVar7 = pBVar3->d;
              pBVar3->top = 5;
              if (puVar7[4] == 0) {
                if (puVar7[3] == 0) {
                  if (puVar7[2] == 0) {
                    if (puVar7[1] == 0) {
                      uVar8 = *puVar7;
                      if (uVar8 != 0) {
                        uVar8 = 1;
                      }
                    }
                    else {
                      uVar8 = 2;
                    }
                  }
                  else {
                    uVar8 = 3;
                  }
                }
                else {
                  uVar8 = 4;
                }
              }
              else {
                uVar8 = 5;
              }
              pBVar6 = a->s;
              pBVar3->top = uVar8;
              puVar7 = pBVar6->d;
              pBVar6->top = 5;
              if (puVar7[4] == 0) {
                if (puVar7[3] == 0) {
                  if (puVar7[2] == 0) {
                    if (puVar7[1] == 0) {
                      uVar8 = *puVar7;
                      if (uVar8 != 0) {
                        uVar8 = 1;
                      }
                    }
                    else {
                      uVar8 = 2;
                    }
                  }
                  else {
                    uVar8 = 3;
                  }
                }
                else {
                  uVar8 = 4;
                }
              }
              else {
                uVar8 = 5;
              }
              pBVar6->top = uVar8;
            }
          }
        }
        DSA_SIG_free(a);
      }
    }
  }
  return 0;
}



undefined4 surewarehk_dsa_do_sign(undefined4 param_1,undefined4 param_2,DSA *param_3)

{
  void *pvVar1;
  DSA_SIG *a;
  BIGNUM *pBVar2;
  undefined4 uVar3;
  BIGNUM *pBVar4;
  ulong *puVar5;
  ulong uVar6;
  char local_60 [16];
  undefined2 uStack_50;
  undefined1 local_4e;
  undefined1 auStack_4d [49];
  
  builtin_strncpy(local_60,"ENGINE_dsa_do_si",0x10);
  uStack_50 = 0x6e67;
  local_4e = 0;
  memset(auStack_4d,0,0x2d);
  if (p_surewarehk_Dsa_Sign == (code *)0x0) {
    if (SUREWARE_lib_error_code == 0) {
      SUREWARE_lib_error_code = ERR_get_next_error_library();
    }
    ERR_put_error(SUREWARE_lib_error_code,0x65,0x75,"e_sureware.c",0x404);
  }
  else {
    pvVar1 = DSA_get_ex_data(param_3,dsaHndidx);
    if (pvVar1 == (void *)0x0) {
      if (SUREWARE_lib_error_code == 0) {
        SUREWARE_lib_error_code = ERR_get_next_error_library();
      }
      ERR_put_error(SUREWARE_lib_error_code,0x65,0x69,"e_sureware.c",0x40a);
    }
    else {
      a = DSA_SIG_new();
      if (a == (DSA_SIG *)0x0) {
        if (SUREWARE_lib_error_code == 0) {
          SUREWARE_lib_error_code = ERR_get_next_error_library();
        }
        ERR_put_error(SUREWARE_lib_error_code,0x65,0x41,"e_sureware.c",0x40f);
      }
      else {
        pBVar2 = BN_new();
        a->r = pBVar2;
        pBVar2 = BN_new();
        a->s = pBVar2;
        if ((a->r != (BIGNUM *)0x0) && (pBVar2 != (BIGNUM *)0x0)) {
          bn_expand2(a->r,5);
          bn_expand2(a->s,5);
          if (a->r->dmax == 5) {
            if (a->s->dmax == 5) {
              uVar3 = (*p_surewarehk_Dsa_Sign)(local_60,param_2,param_1,a->r->d,a->s->d,pvVar1);
              surewarehk_error_handling(local_60,0x65,uVar3);
              pBVar2 = a->r;
              puVar5 = pBVar2->d;
              pBVar2->top = 5;
              if (puVar5[4] == 0) {
                if (puVar5[3] == 0) {
                  if (puVar5[2] == 0) {
                    if (puVar5[1] == 0) {
                      uVar6 = *puVar5;
                      if (uVar6 != 0) {
                        uVar6 = 1;
                      }
                    }
                    else {
                      uVar6 = 2;
                    }
                  }
                  else {
                    uVar6 = 3;
                  }
                }
                else {
                  uVar6 = 4;
                }
              }
              else {
                uVar6 = 5;
              }
              pBVar4 = a->s;
              pBVar2->top = uVar6;
              puVar5 = pBVar4->d;
              pBVar4->top = 5;
              if (puVar5[4] == 0) {
                if (puVar5[3] == 0) {
                  if (puVar5[2] == 0) {
                    if (puVar5[1] == 0) {
                      uVar6 = *puVar5;
                      if (uVar6 != 0) {
                        uVar6 = 1;
                      }
                    }
                    else {
                      uVar6 = 2;
                    }
                  }
                  else {
                    uVar6 = 3;
                  }
                }
                else {
                  uVar6 = 4;
                }
              }
              else {
                uVar6 = 5;
              }
              pBVar4->top = uVar6;
            }
          }
        }
        DSA_SIG_free(a);
      }
    }
  }
  return 0;
}



int cswift_rsa_mod_exp(BIGNUM *param_1,BIGNUM *param_2,RSA *param_3,BN_CTX *param_4)

{
  int iVar1;
  RSA_METHOD *pRVar2;
  int iVar3;
  int iVar4;
  BIGNUM *pBVar5;
  size_t sVar6;
  int iVar7;
  int iVar8;
  BIGNUM *a;
  BIGNUM *a_00;
  BIGNUM *a_01;
  BIGNUM *a_02;
  BIGNUM *a_03;
  BIGNUM *a_04;
  undefined4 local_78;
  int local_74;
  ulong *local_70;
  size_t local_6c;
  ulong *local_68;
  char acStack_64 [16];
  undefined4 local_54;
  uint local_50;
  void *local_4c;
  uint local_48;
  void *local_44;
  uint local_40;
  void *local_3c;
  uint local_38;
  void *local_34;
  uint local_30;
  void *local_2c;
  
  iVar1 = DAT_000db57c;
  if ((((param_3->p == (BIGNUM *)0x0) || (param_3->q == (BIGNUM *)0x0)) ||
      (param_3->dmp1 == (BIGNUM *)0x0)) ||
     ((param_3->dmq1 == (BIGNUM *)0x0 || (param_3->iqmp == (BIGNUM *)0x0)))) {
    iVar3 = *(int *)(DAT_000db57c + 4);
    if (iVar3 == 0) {
      iVar3 = ERR_get_next_error_library();
      *(int *)(iVar1 + 4) = iVar3;
    }
    ERR_put_error(iVar3,0x6b,0x69,DAT_000db580,0x2e3);
    return 0;
  }
  iVar1 = BN_num_bits(param_3->p);
  if ((((0x400 < iVar1) || (iVar1 = BN_num_bits(param_3->q), 0x400 < iVar1)) ||
      ((iVar1 = BN_num_bits(param_3->dmp1), 0x400 < iVar1 ||
       ((iVar1 = BN_num_bits(param_3->dmq1), 0x400 < iVar1 ||
        (iVar1 = BN_num_bits(param_3->iqmp), 0x400 < iVar1)))))) &&
     (pRVar2 = RSA_PKCS1_SSLeay(), pRVar2 != (RSA_METHOD *)0x0)) {
    iVar1 = (*pRVar2->rsa_mod_exp)(param_1,param_2,param_3,param_4);
    return iVar1;
  }
  iVar1 = DAT_000db57c;
  local_4c = (void *)0x0;
  local_44 = (void *)0x0;
  local_3c = (void *)0x0;
  local_34 = (void *)0x0;
  local_2c = (void *)0x0;
  pBVar5 = param_3->dmq1;
  a = param_3->iqmp;
  a_02 = param_3->p;
  a_03 = param_3->q;
  a_04 = param_3->dmp1;
  iVar3 = (**(code **)(DAT_000db57c + 0xc))(&local_78);
  if (iVar3 == 0) {
    a_00 = BN_new();
    a_01 = BN_new();
    if (a_01 == (BIGNUM *)0x0 || a_00 == (BIGNUM *)0x0) {
      iVar3 = *(int *)(iVar1 + 4);
      if (iVar3 == 0) {
        iVar3 = ERR_get_next_error_library();
        *(int *)(iVar1 + 4) = iVar3;
      }
      ERR_put_error(iVar3,0x6a,0x66,DAT_000db580,0x279);
      iVar8 = 0;
      iVar3 = 1;
    }
    else {
      local_54 = 1;
      iVar4 = BN_num_bits(a_02);
      iVar3 = iVar4 + 7;
      if (iVar4 + 7 < 0) {
        iVar3 = iVar4 + 0xe;
      }
      sVar6 = 0;
      local_50 = iVar3 >> 3;
      if ((local_50 & 0x1f) == 0) {
        sVar6 = 0;
      }
      else {
        do {
          local_50 = local_50 + 1;
          sVar6 = sVar6 + 1;
        } while ((local_50 & 0x1f) != 0);
      }
      local_4c = CRYPTO_malloc(local_50,DAT_000db880,0x24d);
      iVar3 = DAT_000db88c;
      if (local_4c == (void *)0x0) {
        iVar4 = *(int *)(iVar1 + 4);
        if (iVar4 == 0) {
          iVar4 = ERR_get_next_error_library();
          *(int *)(iVar3 + 4) = iVar4;
        }
        iVar3 = 0x28a;
      }
      else {
        BN_bn2bin(a_02,(uchar *)((int)local_4c + sVar6));
        if (sVar6 != 0) {
          memset(local_4c,0,sVar6);
        }
        iVar4 = BN_num_bits(a_03);
        iVar3 = iVar4 + 7;
        if (iVar4 + 7 < 0) {
          iVar3 = iVar4 + 0xe;
        }
        local_48 = iVar3 >> 3;
        sVar6 = local_48 & 0x1f;
        if (sVar6 != 0) {
          sVar6 = 0;
          do {
            local_48 = local_48 + 1;
            sVar6 = sVar6 + 1;
          } while ((local_48 & 0x1f) != 0);
        }
        local_44 = CRYPTO_malloc(local_48,DAT_000db880,0x24d);
        iVar3 = DAT_000db88c;
        if (local_44 == (void *)0x0) {
          iVar4 = *(int *)(iVar1 + 4);
          if (iVar4 == 0) {
            iVar4 = ERR_get_next_error_library();
            *(int *)(iVar3 + 4) = iVar4;
          }
          iVar3 = 0x28e;
        }
        else {
          BN_bn2bin(a_03,(uchar *)((int)local_44 + sVar6));
          if (sVar6 != 0) {
            memset(local_44,0,sVar6);
          }
          iVar4 = BN_num_bits(a_04);
          iVar3 = iVar4 + 7;
          if (iVar4 + 7 < 0) {
            iVar3 = iVar4 + 0xe;
          }
          local_40 = iVar3 >> 3;
          sVar6 = local_40 & 0x1f;
          if (sVar6 != 0) {
            sVar6 = 0;
            do {
              local_40 = local_40 + 1;
              sVar6 = sVar6 + 1;
            } while ((local_40 & 0x1f) != 0);
          }
          local_3c = CRYPTO_malloc(local_40,DAT_000db880,0x24d);
          iVar3 = DAT_000db88c;
          if (local_3c == (void *)0x0) {
            iVar4 = *(int *)(iVar1 + 4);
            if (iVar4 == 0) {
              iVar4 = ERR_get_next_error_library();
              *(int *)(iVar3 + 4) = iVar4;
            }
            iVar3 = 0x292;
          }
          else {
            BN_bn2bin(a_04,(uchar *)((int)local_3c + sVar6));
            if (sVar6 != 0) {
              memset(local_3c,0,sVar6);
            }
            iVar4 = BN_num_bits(pBVar5);
            iVar3 = iVar4 + 7;
            if (iVar4 + 7 < 0) {
              iVar3 = iVar4 + 0xe;
            }
            local_38 = iVar3 >> 3;
            sVar6 = local_38 & 0x1f;
            if (sVar6 != 0) {
              sVar6 = 0;
              do {
                local_38 = local_38 + 1;
                sVar6 = sVar6 + 1;
              } while ((local_38 & 0x1f) != 0);
            }
            local_34 = CRYPTO_malloc(local_38,DAT_000db880,0x24d);
            iVar3 = DAT_000db950;
            if (local_34 == (void *)0x0) {
              iVar4 = *(int *)(iVar1 + 4);
              if (iVar4 == 0) {
                iVar4 = ERR_get_next_error_library();
                *(int *)(iVar3 + 4) = iVar4;
              }
              iVar3 = 0x296;
            }
            else {
              BN_bn2bin(pBVar5,(uchar *)((int)local_34 + sVar6));
              if (sVar6 != 0) {
                memset(local_34,0,sVar6);
              }
              iVar4 = BN_num_bits(a);
              iVar3 = iVar4 + 7;
              if (iVar4 + 7 < 0) {
                iVar3 = iVar4 + 0xe;
              }
              local_30 = iVar3 >> 3;
              sVar6 = local_30 & 0x1f;
              if (sVar6 != 0) {
                sVar6 = 0;
                do {
                  local_30 = local_30 + 1;
                  sVar6 = sVar6 + 1;
                } while ((local_30 & 0x1f) != 0);
              }
              local_2c = CRYPTO_malloc(local_30,DAT_000db880,0x24d);
              iVar3 = DAT_000db950;
              if (local_2c == (void *)0x0) {
                if (*(int *)(iVar1 + 4) == 0) {
                  iVar4 = ERR_get_next_error_library();
                  *(int *)(iVar3 + 4) = iVar4;
                }
                iVar3 = 0x29a;
                iVar4 = *(int *)(iVar1 + 4);
              }
              else {
                BN_bn2bin(a,(uchar *)((int)local_2c + sVar6));
                if (sVar6 != 0) {
                  memset(local_2c,0,sVar6);
                }
                if (((param_2->top <= a_00->dmax) ||
                    (pBVar5 = bn_expand2(a_00,param_2->top), pBVar5 != (BIGNUM *)0x0)) &&
                   ((iVar3 = a_02->top + a_03->top, iVar3 <= a_01->dmax ||
                    (pBVar5 = bn_expand2(a_01,iVar3), pBVar5 != (BIGNUM *)0x0)))) {
                  iVar4 = (**(code **)(iVar1 + 0x10))(local_78,&local_54);
                  iVar3 = DAT_000db88c;
                  if (iVar4 == -0x2716) {
                    if (*(int *)(DAT_000db88c + 4) == 0) {
                      iVar4 = ERR_get_next_error_library();
                      *(int *)(iVar3 + 4) = iVar4;
                    }
                    ERR_put_error(*(int *)(iVar1 + 4),0x6a,0x65,DAT_000db954,0x2a8);
                    iVar3 = 1;
                    iVar8 = 0;
                  }
                  else {
                    if (iVar4 == 0) {
                      local_74 = BN_bn2bin(param_2,(uchar *)a_00->d);
                      iVar3 = DAT_000db88c;
                      local_70 = a_00->d;
                      iVar8 = 1;
                      iVar4 = BN_num_bits(a_02);
                      iVar7 = iVar4 + 7;
                      if (iVar7 < 0) {
                        iVar7 = iVar4 + 0xe;
                      }
                      local_6c = (iVar7 >> 3) << 1;
                      memset(a_01->d,0,local_6c);
                      local_68 = a_01->d;
                      iVar4 = (**(code **)(iVar1 + 0x14))(local_78,1,&local_74,1,&local_6c,1);
                      if (iVar4 == 0) {
                        BN_bin2bn((uchar *)a_01->d,local_6c,param_1);
                        iVar3 = iVar8;
                        goto LAB_000db4f2;
                      }
                      if (*(int *)(iVar3 + 4) == 0) {
                        iVar8 = ERR_get_next_error_library();
                        *(int *)(iVar3 + 4) = iVar8;
                      }
                      ERR_put_error(*(int *)(iVar1 + 4),0x6a,0x6b,DAT_000db880,0x2bd);
                    }
                    else {
                      if (*(int *)(DAT_000db88c + 4) == 0) {
                        iVar8 = ERR_get_next_error_library();
                        *(int *)(iVar3 + 4) = iVar8;
                      }
                      ERR_put_error(*(int *)(iVar1 + 4),0x6a,0x6b,DAT_000db954,0x2ad);
                    }
                    sprintf(acStack_64,DAT_000db884,iVar4);
                    iVar8 = 0;
                    ERR_add_error_data(2,DAT_000db888,acStack_64);
                    iVar3 = 1;
                  }
                  goto LAB_000db4f2;
                }
                iVar3 = DAT_000db950;
                if (*(int *)(iVar1 + 4) == 0) {
                  iVar4 = ERR_get_next_error_library();
                  *(int *)(iVar3 + 4) = iVar4;
                }
                iVar3 = 0x29e;
                iVar4 = *(int *)(iVar1 + 4);
              }
            }
          }
        }
      }
      ERR_put_error(iVar4,0x6a,0x67,DAT_000db880,iVar3);
      iVar3 = 1;
      iVar8 = 0;
    }
  }
  else {
    iVar3 = *(int *)(iVar1 + 4);
    if (iVar3 == 0) {
      iVar3 = ERR_get_next_error_library();
      *(int *)(iVar1 + 4) = iVar3;
    }
    iVar8 = 0;
    a_00 = (BIGNUM *)0x0;
    a_01 = (BIGNUM *)0x0;
    ERR_put_error(iVar3,0x6a,0x6c,DAT_000db580,0x270);
    iVar3 = 0;
  }
LAB_000db4f2:
  if (local_4c != (void *)0x0) {
    CRYPTO_free(local_4c);
  }
  if (local_44 != (void *)0x0) {
    CRYPTO_free(local_44);
  }
  if (local_3c != (void *)0x0) {
    CRYPTO_free(local_3c);
  }
  if (local_34 != (void *)0x0) {
    CRYPTO_free(local_34);
  }
  if (local_2c != (void *)0x0) {
    CRYPTO_free(local_2c);
  }
  if (a_01 != (BIGNUM *)0x0) {
    BN_free(a_01);
  }
  if (a_00 != (BIGNUM *)0x0) {
    BN_free(a_00);
  }
  if (iVar3 != 0) {
    (**(code **)(iVar1 + 0x18))(local_78);
  }
  return iVar8;
}


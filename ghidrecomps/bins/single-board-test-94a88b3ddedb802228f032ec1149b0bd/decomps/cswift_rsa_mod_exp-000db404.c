
int cswift_rsa_mod_exp(BIGNUM *param_1,BIGNUM *param_2,RSA *param_3,BN_CTX *param_4)

{
  int iVar1;
  RSA_METHOD *pRVar2;
  BIGNUM *pBVar3;
  size_t sVar4;
  int iVar5;
  int iVar6;
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
  
  if ((((param_3->p == (BIGNUM *)0x0) || (param_3->q == (BIGNUM *)0x0)) ||
      (param_3->dmp1 == (BIGNUM *)0x0)) ||
     ((param_3->dmq1 == (BIGNUM *)0x0 || (param_3->iqmp == (BIGNUM *)0x0)))) {
    if (CSWIFT_lib_error_code == 0) {
      CSWIFT_lib_error_code = ERR_get_next_error_library();
    }
    ERR_put_error(CSWIFT_lib_error_code,0x6b,0x69,"e_cswift.c",0x2e3);
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
  local_4c = (void *)0x0;
  local_44 = (void *)0x0;
  local_3c = (void *)0x0;
  local_34 = (void *)0x0;
  local_2c = (void *)0x0;
  pBVar3 = param_3->dmq1;
  a = param_3->iqmp;
  a_02 = param_3->p;
  a_03 = param_3->q;
  a_04 = param_3->dmp1;
  iVar1 = (*p_CSwift_AcquireAccContext)(&local_78);
  if (iVar1 == 0) {
    a_00 = BN_new();
    a_01 = BN_new();
    if (a_01 == (BIGNUM *)0x0 || a_00 == (BIGNUM *)0x0) {
      if (CSWIFT_lib_error_code == 0) {
        CSWIFT_lib_error_code = ERR_get_next_error_library();
      }
      ERR_put_error(CSWIFT_lib_error_code,0x6a,0x66,"e_cswift.c",0x279);
      iVar6 = 0;
      iVar1 = 1;
    }
    else {
      local_54 = 1;
      iVar6 = BN_num_bits(a_02);
      iVar1 = iVar6 + 7;
      if (iVar6 + 7 < 0) {
        iVar1 = iVar6 + 0xe;
      }
      sVar4 = 0;
      local_50 = iVar1 >> 3;
      if ((local_50 & 0x1f) == 0) {
        sVar4 = 0;
      }
      else {
        do {
          local_50 = local_50 + 1;
          sVar4 = sVar4 + 1;
        } while ((local_50 & 0x1f) != 0);
      }
      local_4c = CRYPTO_malloc(local_50,"e_cswift.c",0x24d);
      if (local_4c == (void *)0x0) {
        if (CSWIFT_lib_error_code == 0) {
          CSWIFT_lib_error_code = ERR_get_next_error_library();
        }
        iVar1 = 0x28a;
      }
      else {
        BN_bn2bin(a_02,(uchar *)((int)local_4c + sVar4));
        if (sVar4 != 0) {
          memset(local_4c,0,sVar4);
        }
        iVar6 = BN_num_bits(a_03);
        iVar1 = iVar6 + 7;
        if (iVar6 + 7 < 0) {
          iVar1 = iVar6 + 0xe;
        }
        local_48 = iVar1 >> 3;
        sVar4 = local_48 & 0x1f;
        if (sVar4 != 0) {
          sVar4 = 0;
          do {
            local_48 = local_48 + 1;
            sVar4 = sVar4 + 1;
          } while ((local_48 & 0x1f) != 0);
        }
        local_44 = CRYPTO_malloc(local_48,"e_cswift.c",0x24d);
        if (local_44 == (void *)0x0) {
          if (CSWIFT_lib_error_code == 0) {
            CSWIFT_lib_error_code = ERR_get_next_error_library();
          }
          iVar1 = 0x28e;
        }
        else {
          BN_bn2bin(a_03,(uchar *)((int)local_44 + sVar4));
          if (sVar4 != 0) {
            memset(local_44,0,sVar4);
          }
          iVar6 = BN_num_bits(a_04);
          iVar1 = iVar6 + 7;
          if (iVar6 + 7 < 0) {
            iVar1 = iVar6 + 0xe;
          }
          local_40 = iVar1 >> 3;
          sVar4 = local_40 & 0x1f;
          if (sVar4 != 0) {
            sVar4 = 0;
            do {
              local_40 = local_40 + 1;
              sVar4 = sVar4 + 1;
            } while ((local_40 & 0x1f) != 0);
          }
          local_3c = CRYPTO_malloc(local_40,"e_cswift.c",0x24d);
          if (local_3c == (void *)0x0) {
            if (CSWIFT_lib_error_code == 0) {
              CSWIFT_lib_error_code = ERR_get_next_error_library();
            }
            iVar1 = 0x292;
          }
          else {
            BN_bn2bin(a_04,(uchar *)((int)local_3c + sVar4));
            if (sVar4 != 0) {
              memset(local_3c,0,sVar4);
            }
            iVar6 = BN_num_bits(pBVar3);
            iVar1 = iVar6 + 7;
            if (iVar6 + 7 < 0) {
              iVar1 = iVar6 + 0xe;
            }
            local_38 = iVar1 >> 3;
            sVar4 = local_38 & 0x1f;
            if (sVar4 != 0) {
              sVar4 = 0;
              do {
                local_38 = local_38 + 1;
                sVar4 = sVar4 + 1;
              } while ((local_38 & 0x1f) != 0);
            }
            local_34 = CRYPTO_malloc(local_38,"e_cswift.c",0x24d);
            if (local_34 == (void *)0x0) {
              if (CSWIFT_lib_error_code == 0) {
                CSWIFT_lib_error_code = ERR_get_next_error_library();
              }
              iVar1 = 0x296;
            }
            else {
              BN_bn2bin(pBVar3,(uchar *)((int)local_34 + sVar4));
              if (sVar4 != 0) {
                memset(local_34,0,sVar4);
              }
              iVar6 = BN_num_bits(a);
              iVar1 = iVar6 + 7;
              if (iVar6 + 7 < 0) {
                iVar1 = iVar6 + 0xe;
              }
              local_30 = iVar1 >> 3;
              sVar4 = local_30 & 0x1f;
              if (sVar4 != 0) {
                sVar4 = 0;
                do {
                  local_30 = local_30 + 1;
                  sVar4 = sVar4 + 1;
                } while ((local_30 & 0x1f) != 0);
              }
              local_2c = CRYPTO_malloc(local_30,"e_cswift.c",0x24d);
              if (local_2c == (void *)0x0) {
                if (CSWIFT_lib_error_code == 0) {
                  CSWIFT_lib_error_code = ERR_get_next_error_library();
                }
                iVar1 = 0x29a;
              }
              else {
                BN_bn2bin(a,(uchar *)((int)local_2c + sVar4));
                if (sVar4 != 0) {
                  memset(local_2c,0,sVar4);
                }
                if (((param_2->top <= a_00->dmax) ||
                    (pBVar3 = bn_expand2(a_00,param_2->top), pBVar3 != (BIGNUM *)0x0)) &&
                   ((iVar1 = a_02->top + a_03->top, iVar1 <= a_01->dmax ||
                    (pBVar3 = bn_expand2(a_01,iVar1), pBVar3 != (BIGNUM *)0x0)))) {
                  iVar1 = (*p_CSwift_AttachKeyParam)(local_78,&local_54);
                  if (iVar1 == -0x2716) {
                    if (CSWIFT_lib_error_code == 0) {
                      CSWIFT_lib_error_code = ERR_get_next_error_library();
                    }
                    ERR_put_error(CSWIFT_lib_error_code,0x6a,0x65,"e_cswift.c",0x2a8);
                    iVar1 = 1;
                    iVar6 = 0;
                  }
                  else {
                    if (iVar1 == 0) {
                      local_74 = BN_bn2bin(param_2,(uchar *)a_00->d);
                      local_70 = a_00->d;
                      iVar6 = 1;
                      iVar1 = BN_num_bits(a_02);
                      iVar5 = iVar1 + 7;
                      if (iVar5 < 0) {
                        iVar5 = iVar1 + 0xe;
                      }
                      local_6c = (iVar5 >> 3) << 1;
                      memset(a_01->d,0,local_6c);
                      local_68 = a_01->d;
                      iVar1 = (*p_CSwift_SimpleRequest)(local_78,1,&local_74,1,&local_6c,1);
                      if (iVar1 == 0) {
                        BN_bin2bn((uchar *)a_01->d,local_6c,param_1);
                        iVar1 = iVar6;
                        goto LAB_000db4f2;
                      }
                      if (CSWIFT_lib_error_code == 0) {
                        CSWIFT_lib_error_code = ERR_get_next_error_library();
                      }
                      ERR_put_error(CSWIFT_lib_error_code,0x6a,0x6b,"e_cswift.c",0x2bd);
                    }
                    else {
                      if (CSWIFT_lib_error_code == 0) {
                        CSWIFT_lib_error_code = ERR_get_next_error_library();
                      }
                      ERR_put_error(CSWIFT_lib_error_code,0x6a,0x6b,"e_cswift.c",0x2ad);
                    }
                    sprintf(acStack_64,"%ld",iVar1);
                    iVar6 = 0;
                    ERR_add_error_data(2,"CryptoSwift error number is ",acStack_64);
                    iVar1 = 1;
                  }
                  goto LAB_000db4f2;
                }
                if (CSWIFT_lib_error_code == 0) {
                  CSWIFT_lib_error_code = ERR_get_next_error_library();
                }
                iVar1 = 0x29e;
              }
            }
          }
        }
      }
      ERR_put_error(CSWIFT_lib_error_code,0x6a,0x67,"e_cswift.c",iVar1);
      iVar1 = 1;
      iVar6 = 0;
    }
  }
  else {
    if (CSWIFT_lib_error_code == 0) {
      CSWIFT_lib_error_code = ERR_get_next_error_library();
    }
    iVar6 = 0;
    a_00 = (BIGNUM *)0x0;
    a_01 = (BIGNUM *)0x0;
    ERR_put_error(CSWIFT_lib_error_code,0x6a,0x6c,"e_cswift.c",0x270);
    iVar1 = 0;
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
  if (iVar1 != 0) {
    (*p_CSwift_ReleaseAccContext)(local_78);
  }
  return iVar6;
}


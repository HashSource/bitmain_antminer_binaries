
char * SRP_VBASE_init(_STACK **param_1,void *param_2)

{
  _STACK *sk;
  BIO_METHOD *type;
  BIO *bp;
  long lVar1;
  TXT_DB *db;
  char **ppcVar2;
  int iVar3;
  char **ppcVar4;
  char *pcVar5;
  int iVar6;
  void **ppvVar7;
  char **ppcVar8;
  int iVar9;
  _STACK *p_Var10;
  int iVar11;
  char *pcVar12;
  char *local_3c;
  char *local_2c;
  
  sk = sk_new_null();
  type = BIO_s_file();
  bp = BIO_new(type);
  if ((bp == (BIO *)0x0) || (lVar1 = BIO_ctrl(bp,0x6c,3,param_2), lVar1 < 1)) {
    local_3c = (char *)0x3;
    goto LAB_000d7cbe;
  }
  db = TXT_DB_read(bp,6);
  if (db == (TXT_DB *)0x0) {
    local_3c = (char *)0x1;
    goto LAB_000d7cbe;
  }
  if (param_1[2] == (_STACK *)0x0) {
    local_2c = (char *)0x0;
  }
  else {
    ppcVar2 = (char **)SRP_get_default_gN(0);
    local_2c = *ppcVar2;
  }
  local_3c = (char *)0x4;
  for (iVar9 = 0; iVar3 = sk_num(&db->data->stack), iVar9 < iVar3; iVar9 = iVar9 + 1) {
    ppcVar2 = (char **)sk_value(&db->data->stack,iVar9);
    if (**ppcVar2 == 'I') {
      ppcVar4 = (char **)CRYPTO_malloc(0xc,DAT_000d7fd4,0x18a);
      if (ppcVar4 == (char **)0x0) goto LAB_000d7e58;
      pcVar5 = BUF_strdup(ppcVar2[3]);
      *ppcVar4 = pcVar5;
      if (pcVar5 != (char *)0x0) {
        pcVar12 = ppcVar2[1];
        p_Var10 = param_1[1];
        if (p_Var10 == (_STACK *)0x0) {
          ppcVar4[2] = (char *)0x0;
        }
        else {
          iVar3 = 0;
          do {
            iVar6 = sk_num(p_Var10);
            if (iVar6 <= iVar3) {
              ppvVar7 = (void **)SRP_gN_new_init(pcVar12);
              if (ppvVar7 == (void **)0x0) {
                pcVar5 = (char *)0x0;
              }
              else {
                iVar3 = sk_insert(p_Var10,ppvVar7,0);
                if (iVar3 < 1) {
                  CRYPTO_free(*ppvVar7);
                  BN_free((BIGNUM *)ppvVar7[1]);
                  CRYPTO_free(ppvVar7);
                  pcVar5 = (char *)0x0;
                }
                else {
                  pcVar5 = (char *)ppvVar7[1];
                }
              }
              goto LAB_000d7dac;
            }
            ppcVar8 = (char **)sk_value(p_Var10,iVar3);
            iVar6 = strcmp(*ppcVar8,pcVar12);
            iVar3 = iVar3 + 1;
          } while (iVar6 != 0);
          pcVar5 = ppcVar8[1];
LAB_000d7dac:
          ppcVar4[2] = pcVar5;
          if (pcVar5 == (char *)0x0) {
            pcVar5 = *ppcVar4;
          }
          else {
            pcVar5 = ppcVar2[2];
            p_Var10 = param_1[1];
            if (p_Var10 == (_STACK *)0x0) {
              ppcVar4[1] = (char *)0x0;
              pcVar5 = *ppcVar4;
            }
            else {
              iVar3 = 0;
              do {
                iVar6 = sk_num(p_Var10);
                if (iVar6 <= iVar3) {
                  ppvVar7 = (void **)SRP_gN_new_init(pcVar5);
                  if (ppvVar7 == (void **)0x0) {
                    pcVar5 = (char *)0x0;
                  }
                  else {
                    iVar3 = sk_insert(p_Var10,ppvVar7,0);
                    if (iVar3 < 1) {
                      CRYPTO_free(*ppvVar7);
                      BN_free((BIGNUM *)ppvVar7[1]);
                      CRYPTO_free(ppvVar7);
                      pcVar5 = (char *)0x0;
                    }
                    else {
                      pcVar5 = (char *)ppvVar7[1];
                    }
                  }
                  goto LAB_000d7e12;
                }
                ppcVar8 = (char **)sk_value(p_Var10,iVar3);
                iVar6 = strcmp(*ppcVar8,pcVar5);
                iVar3 = iVar3 + 1;
              } while (iVar6 != 0);
              pcVar5 = ppcVar8[1];
LAB_000d7e12:
              ppcVar4[1] = pcVar5;
              if (pcVar5 == (char *)0x0) {
                pcVar5 = *ppcVar4;
              }
              else {
                iVar3 = sk_insert(sk,ppcVar4,0);
                if (iVar3 != 0) {
                  if (param_1[2] != (_STACK *)0x0) {
                    local_2c = ppcVar2[3];
                  }
                  goto LAB_000d7d08;
                }
                pcVar5 = *ppcVar4;
              }
            }
          }
        }
      }
      CRYPTO_free(pcVar5);
      CRYPTO_free(ppcVar4);
      goto LAB_000d7e60;
    }
    if (**ppcVar2 == 'V') {
      pcVar5 = ppcVar2[4];
      if (sk == (_STACK *)0x0) {
LAB_000d7f48:
        ppcVar4 = (char **)SRP_get_default_gN(pcVar5);
        if (ppcVar4 == (char **)0x0) goto LAB_000d7d08;
      }
      else {
        if (pcVar5 == (char *)0x0) {
          for (iVar3 = 0; iVar6 = sk_num(sk), iVar3 < iVar6; iVar3 = iVar3 + 1) {
            ppcVar4 = (char **)sk_value(sk,iVar3);
            if (ppcVar4 != (char **)0x0) goto LAB_000d7ea8;
          }
          goto LAB_000d7f48;
        }
        iVar3 = 0;
        do {
          iVar6 = sk_num(sk);
          iVar11 = iVar3 + 1;
          if (iVar6 <= iVar3) goto LAB_000d7f48;
          ppcVar4 = (char **)sk_value(sk,iVar3);
          iVar3 = iVar11;
        } while ((ppcVar4 == (char **)0x0) || (iVar6 = strcmp(*ppcVar4,pcVar5), iVar6 != 0));
      }
LAB_000d7ea8:
      ppcVar8 = (char **)CRYPTO_malloc(0x18,DAT_000d7fd4,0xc9);
      if (ppcVar8 == (char **)0x0) {
        local_3c = (char *)0x4;
        goto LAB_000d7e58;
      }
      pcVar12 = ppcVar4[1];
      pcVar5 = ppcVar4[2];
      ppcVar8[1] = (char *)0x0;
      ppcVar8[2] = (char *)0x0;
      *ppcVar8 = (char *)0x0;
      ppcVar8[5] = (char *)0x0;
      ppcVar8[4] = pcVar5;
      ppcVar8[3] = pcVar12;
      pcVar5 = ppcVar2[5];
      if (ppcVar2[3] == (char *)0x0) {
LAB_000d7ee0:
        if (pcVar5 != (char *)0x0) {
          pcVar5 = BUF_strdup(pcVar5);
          ppcVar8[5] = pcVar5;
          if (pcVar5 == (char *)0x0) goto LAB_000d7f16;
        }
        iVar3 = SRP_user_pwd_set_sv(ppcVar8,ppcVar2[2],ppcVar2[1]);
        if (iVar3 == 0) {
          local_3c = (char *)0x2;
        }
        else {
          iVar3 = sk_insert(*param_1,ppcVar8,0);
          local_3c = (char *)0x2;
          if (iVar3 != 0) goto LAB_000d7d08;
        }
      }
      else {
        pcVar12 = BUF_strdup(ppcVar2[3]);
        *ppcVar8 = pcVar12;
        if (pcVar12 != (char *)0x0) goto LAB_000d7ee0;
LAB_000d7f16:
        local_3c = (char *)0x4;
      }
      BN_free((BIGNUM *)ppcVar8[1]);
      BN_clear_free((BIGNUM *)ppcVar8[2]);
      CRYPTO_free(*ppcVar8);
      CRYPTO_free(ppcVar8[5]);
      CRYPTO_free(ppcVar8);
      goto LAB_000d7e60;
    }
LAB_000d7d08:
  }
  local_3c = local_2c;
  if (local_2c != (char *)0x0) {
    if (sk == (_STACK *)0x0) {
LAB_000d7e3a:
      ppcVar2 = (char **)SRP_get_default_gN(local_2c);
      local_3c = (char *)0x2;
      if (ppcVar2 == (char **)0x0) goto LAB_000d7e58;
    }
    else {
      iVar9 = 0;
      do {
        iVar3 = sk_num(sk);
        iVar6 = iVar9 + 1;
        if (iVar3 <= iVar9) goto LAB_000d7e3a;
        ppcVar2 = (char **)sk_value(sk,iVar9);
        iVar9 = iVar6;
      } while ((ppcVar2 == (char **)0x0) || (iVar3 = strcmp(*ppcVar2,local_2c), iVar3 != 0));
    }
    local_3c = (char *)0x0;
    p_Var10 = (_STACK *)ppcVar2[2];
    param_1[3] = (_STACK *)ppcVar2[1];
    param_1[4] = p_Var10;
  }
LAB_000d7e58:
  if (db != (TXT_DB *)0x0) {
LAB_000d7e60:
    TXT_DB_free(db);
  }
LAB_000d7cbe:
  if (bp != (BIO *)0x0) {
    BIO_free_all(bp);
  }
  sk_free(sk);
  return local_3c;
}


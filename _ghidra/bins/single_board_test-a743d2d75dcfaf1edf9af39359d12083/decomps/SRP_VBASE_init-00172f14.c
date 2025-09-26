
char * SRP_VBASE_init(undefined4 *param_1,void *param_2)

{
  _STACK *sk;
  BIO_METHOD *type;
  BIO *bp;
  long lVar1;
  TXT_DB *db;
  undefined4 *puVar2;
  int iVar3;
  undefined4 *puVar4;
  char *pcVar5;
  int iVar6;
  undefined4 *puVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  int iVar10;
  _STACK *p_Var11;
  int iVar12;
  char *pcVar13;
  char *local_3c;
  char *local_2c;
  
  sk = sk_new_null();
  type = BIO_s_file();
  bp = BIO_new(type);
  if ((bp == (BIO *)0x0) || (lVar1 = BIO_ctrl(bp,0x6c,3,param_2), lVar1 < 1)) {
    local_3c = (char *)0x3;
    goto LAB_00172f42;
  }
  db = TXT_DB_read(bp,6);
  if (db == (TXT_DB *)0x0) {
    local_3c = (char *)0x1;
    goto LAB_00172f42;
  }
  if (param_1[2] == 0) {
    local_2c = (char *)0x0;
  }
  else {
    puVar2 = (undefined4 *)SRP_get_default_gN(0);
    local_2c = (char *)*puVar2;
  }
  local_3c = (char *)0x4;
  for (iVar10 = 0; iVar3 = sk_num(&db->data->stack), iVar10 < iVar3; iVar10 = iVar10 + 1) {
    puVar2 = (undefined4 *)sk_value(&db->data->stack,iVar10);
    if (*(char *)*puVar2 == 'I') {
      puVar4 = (undefined4 *)CRYPTO_malloc(0xc,"srp_vfy.c",0x18a);
      if (puVar4 == (undefined4 *)0x0) goto LAB_001730dc;
      pcVar5 = BUF_strdup((char *)puVar2[3]);
      *puVar4 = pcVar5;
      if (pcVar5 != (char *)0x0) {
        pcVar13 = (char *)puVar2[1];
        p_Var11 = (_STACK *)param_1[1];
        if (p_Var11 == (_STACK *)0x0) {
          puVar4[2] = 0;
        }
        else {
          iVar3 = 0;
          do {
            iVar6 = sk_num(p_Var11);
            if (iVar6 <= iVar3) {
              puVar7 = (undefined4 *)SRP_gN_new_init(pcVar13);
              if (puVar7 == (undefined4 *)0x0) {
                iVar3 = 0;
              }
              else {
                iVar3 = sk_insert(p_Var11,puVar7,0);
                if (iVar3 < 1) {
                  CRYPTO_free((void *)*puVar7);
                  BN_free((BIGNUM *)puVar7[1]);
                  CRYPTO_free(puVar7);
                  iVar3 = 0;
                }
                else {
                  iVar3 = puVar7[1];
                }
              }
              goto LAB_00173030;
            }
            puVar7 = (undefined4 *)sk_value(p_Var11,iVar3);
            iVar6 = strcmp((char *)*puVar7,pcVar13);
            iVar3 = iVar3 + 1;
          } while (iVar6 != 0);
          iVar3 = puVar7[1];
LAB_00173030:
          puVar4[2] = iVar3;
          if (iVar3 == 0) {
            pcVar5 = (char *)*puVar4;
          }
          else {
            pcVar5 = (char *)puVar2[2];
            p_Var11 = (_STACK *)param_1[1];
            if (p_Var11 == (_STACK *)0x0) {
              puVar4[1] = 0;
              pcVar5 = (char *)*puVar4;
            }
            else {
              iVar3 = 0;
              do {
                iVar6 = sk_num(p_Var11);
                if (iVar6 <= iVar3) {
                  puVar7 = (undefined4 *)SRP_gN_new_init(pcVar5);
                  if (puVar7 == (undefined4 *)0x0) {
                    iVar3 = 0;
                  }
                  else {
                    iVar3 = sk_insert(p_Var11,puVar7,0);
                    if (iVar3 < 1) {
                      CRYPTO_free((void *)*puVar7);
                      BN_free((BIGNUM *)puVar7[1]);
                      CRYPTO_free(puVar7);
                      iVar3 = 0;
                    }
                    else {
                      iVar3 = puVar7[1];
                    }
                  }
                  goto LAB_00173096;
                }
                puVar7 = (undefined4 *)sk_value(p_Var11,iVar3);
                iVar6 = strcmp((char *)*puVar7,pcVar5);
                iVar3 = iVar3 + 1;
              } while (iVar6 != 0);
              iVar3 = puVar7[1];
LAB_00173096:
              puVar4[1] = iVar3;
              if (iVar3 == 0) {
                pcVar5 = (char *)*puVar4;
              }
              else {
                iVar3 = sk_insert(sk,puVar4,0);
                if (iVar3 != 0) {
                  if (param_1[2] != 0) {
                    local_2c = (char *)puVar2[3];
                  }
                  goto LAB_00172f8c;
                }
                pcVar5 = (char *)*puVar4;
              }
            }
          }
        }
      }
      CRYPTO_free(pcVar5);
      CRYPTO_free(puVar4);
      goto LAB_001730e4;
    }
    if (*(char *)*puVar2 == 'V') {
      pcVar5 = (char *)puVar2[4];
      if (sk == (_STACK *)0x0) {
LAB_001731cc:
        puVar4 = (undefined4 *)SRP_get_default_gN(pcVar5);
        if (puVar4 == (undefined4 *)0x0) goto LAB_00172f8c;
      }
      else {
        if (pcVar5 == (char *)0x0) {
          for (iVar3 = 0; iVar6 = sk_num(sk), iVar3 < iVar6; iVar3 = iVar3 + 1) {
            puVar4 = (undefined4 *)sk_value(sk,iVar3);
            if (puVar4 != (undefined4 *)0x0) goto LAB_0017312c;
          }
          goto LAB_001731cc;
        }
        iVar3 = 0;
        do {
          iVar6 = sk_num(sk);
          iVar12 = iVar3 + 1;
          if (iVar6 <= iVar3) goto LAB_001731cc;
          puVar4 = (undefined4 *)sk_value(sk,iVar3);
          iVar3 = iVar12;
        } while ((puVar4 == (undefined4 *)0x0) ||
                (iVar6 = strcmp((char *)*puVar4,pcVar5), iVar6 != 0));
      }
LAB_0017312c:
      puVar7 = (undefined4 *)CRYPTO_malloc(0x18,"srp_vfy.c",0xc9);
      if (puVar7 == (undefined4 *)0x0) {
        local_3c = (char *)0x4;
        goto LAB_001730dc;
      }
      uVar9 = puVar4[1];
      uVar8 = puVar4[2];
      puVar7[1] = 0;
      puVar7[2] = 0;
      *puVar7 = 0;
      puVar7[5] = 0;
      puVar7[4] = uVar8;
      puVar7[3] = uVar9;
      pcVar5 = (char *)puVar2[5];
      if ((char *)puVar2[3] == (char *)0x0) {
LAB_00173164:
        if (pcVar5 != (char *)0x0) {
          pcVar5 = BUF_strdup(pcVar5);
          puVar7[5] = pcVar5;
          if (pcVar5 == (char *)0x0) goto LAB_0017319a;
        }
        iVar3 = SRP_user_pwd_set_sv(puVar7,puVar2[2],puVar2[1]);
        if (iVar3 == 0) {
          local_3c = (char *)0x2;
        }
        else {
          iVar3 = sk_insert((_STACK *)*param_1,puVar7,0);
          local_3c = (char *)0x2;
          if (iVar3 != 0) goto LAB_00172f8c;
        }
      }
      else {
        pcVar13 = BUF_strdup((char *)puVar2[3]);
        *puVar7 = pcVar13;
        if (pcVar13 != (char *)0x0) goto LAB_00173164;
LAB_0017319a:
        local_3c = (char *)0x4;
      }
      BN_free((BIGNUM *)puVar7[1]);
      BN_clear_free((BIGNUM *)puVar7[2]);
      CRYPTO_free((void *)*puVar7);
      CRYPTO_free((void *)puVar7[5]);
      CRYPTO_free(puVar7);
      goto LAB_001730e4;
    }
LAB_00172f8c:
  }
  local_3c = local_2c;
  if (local_2c != (char *)0x0) {
    if (sk == (_STACK *)0x0) {
LAB_001730be:
      puVar2 = (undefined4 *)SRP_get_default_gN(local_2c);
      local_3c = (char *)0x2;
      if (puVar2 == (undefined4 *)0x0) goto LAB_001730dc;
    }
    else {
      iVar10 = 0;
      do {
        iVar3 = sk_num(sk);
        iVar6 = iVar10 + 1;
        if (iVar3 <= iVar10) goto LAB_001730be;
        puVar2 = (undefined4 *)sk_value(sk,iVar10);
        iVar10 = iVar6;
      } while ((puVar2 == (undefined4 *)0x0) ||
              (iVar3 = strcmp((char *)*puVar2,local_2c), iVar3 != 0));
    }
    local_3c = (char *)0x0;
    uVar8 = puVar2[2];
    param_1[3] = puVar2[1];
    param_1[4] = uVar8;
  }
LAB_001730dc:
  if (db != (TXT_DB *)0x0) {
LAB_001730e4:
    TXT_DB_free(db);
  }
LAB_00172f42:
  if (bp != (BIO *)0x0) {
    BIO_free_all(bp);
  }
  sk_free(sk);
  return local_3c;
}


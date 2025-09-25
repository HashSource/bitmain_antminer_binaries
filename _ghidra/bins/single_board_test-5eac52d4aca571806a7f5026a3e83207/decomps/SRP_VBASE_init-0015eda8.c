
char * SRP_VBASE_init(undefined4 *param_1,void *param_2)

{
  int iVar1;
  BIO_METHOD *type;
  BIO *bp;
  long lVar2;
  undefined4 *puVar3;
  char *pcVar4;
  int iVar5;
  undefined4 *puVar6;
  void *ptr;
  undefined4 uVar7;
  undefined4 uVar8;
  undefined4 *puVar9;
  char *pcVar10;
  int iVar11;
  int iVar12;
  TXT_DB *db;
  char *pcVar13;
  undefined8 uVar14;
  char *local_40;
  char *local_30;
  
  iVar1 = OPENSSL_sk_new_null();
  type = BIO_s_file();
  bp = BIO_new(type);
  if ((bp == (BIO *)0x0) || (lVar2 = BIO_ctrl(bp,0x6c,3,param_2), lVar2 < 1)) {
    db = (TXT_DB *)0x0;
    puVar9 = (undefined4 *)0x0;
    local_40 = (char *)0x3;
  }
  else {
    db = TXT_DB_read(bp,6);
    if (db == (TXT_DB *)0x0) {
      local_40 = (char *)0x1;
      puVar9 = (undefined4 *)0x0;
    }
    else {
      if (param_1[2] == 0) {
        local_30 = (char *)0x0;
      }
      else {
        puVar9 = (undefined4 *)SRP_get_default_gN(0);
        local_30 = (char *)*puVar9;
      }
      iVar12 = 0;
      local_40 = &DAT_00000004;
      while( true ) {
        uVar14 = OPENSSL_sk_num(db->data);
        iVar5 = (int)((ulonglong)uVar14 >> 0x20);
        if ((int)uVar14 <= iVar12) break;
        uVar14 = OPENSSL_sk_value(db->data,iVar12);
        pcVar4 = (char *)((ulonglong)uVar14 >> 0x20);
        puVar6 = (undefined4 *)uVar14;
        if (*(char *)*puVar6 == 'I') {
          puVar3 = (undefined4 *)CRYPTO_malloc(0xc,"crypto/srp/srp_vfy.c",0x1a2);
          if (puVar3 == (undefined4 *)0x0) {
            puVar9 = (undefined4 *)0x0;
          }
          else {
            pcVar4 = CRYPTO_strdup((char *)puVar6[3],"crypto/srp/srp_vfy.c",0x1a5);
            *puVar3 = pcVar4;
            if (pcVar4 == (char *)0x0) {
              ptr = (void *)0x0;
            }
            else {
              iVar5 = SRP_gN_place_bn(param_1[1],puVar6[1]);
              puVar3[2] = iVar5;
              if (iVar5 != 0) {
                iVar5 = SRP_gN_place_bn(param_1[1],puVar6[2]);
                puVar3[1] = iVar5;
                if ((iVar5 != 0) && (iVar5 = OPENSSL_sk_insert(iVar1,puVar3,0), iVar5 != 0)) {
                  if (param_1[2] != 0) {
                    local_30 = (char *)puVar6[3];
                  }
                  goto LAB_0015ee3e;
                }
              }
              ptr = (void *)*puVar3;
            }
            puVar9 = (undefined4 *)0x0;
            CRYPTO_free(ptr);
            CRYPTO_free(puVar3);
          }
          goto LAB_0015eddc;
        }
        if (*(char *)*puVar6 == 'V') {
          pcVar13 = (char *)puVar6[4];
          if (iVar1 == 0) {
LAB_0015efa4:
            puVar3 = (undefined4 *)SRP_get_default_gN(pcVar13,pcVar4);
            if (puVar3 == (undefined4 *)0x0) goto LAB_0015ee3e;
          }
          else {
            pcVar4 = pcVar13;
            if (pcVar13 == (char *)0x0) {
              for (; iVar5 = OPENSSL_sk_num(iVar1), (int)pcVar4 < iVar5; pcVar4 = pcVar4 + 1) {
                puVar3 = (undefined4 *)OPENSSL_sk_value(iVar1,pcVar4);
                if (puVar3 != (undefined4 *)0x0) goto LAB_0015ef26;
              }
              goto LAB_0015efa4;
            }
            pcVar4 = (char *)0x0;
            do {
              iVar5 = OPENSSL_sk_num(iVar1);
              pcVar10 = pcVar4 + 1;
              if (iVar5 <= (int)pcVar4) goto LAB_0015efa4;
              puVar3 = (undefined4 *)OPENSSL_sk_value(iVar1);
              pcVar4 = pcVar10;
            } while ((puVar3 == (undefined4 *)0x0) ||
                    (iVar5 = strcmp((char *)*puVar3,pcVar13), iVar5 != 0));
          }
LAB_0015ef26:
          puVar9 = (undefined4 *)CRYPTO_malloc(0x18,"crypto/srp/srp_vfy.c",0xbf);
          if (puVar9 == (undefined4 *)0x0) {
LAB_0015ef9e:
            local_40 = &DAT_00000004;
            goto LAB_0015eddc;
          }
          uVar7 = puVar3[1];
          uVar8 = puVar3[2];
          puVar9[1] = 0;
          puVar9[3] = uVar7;
          puVar9[4] = uVar8;
          puVar9[2] = 0;
          *puVar9 = 0;
          puVar9[5] = 0;
          pcVar4 = (char *)puVar6[5];
          if ((char *)puVar6[3] != (char *)0x0) {
            pcVar13 = CRYPTO_strdup((char *)puVar6[3],"crypto/srp/srp_vfy.c",0xd6);
            *puVar9 = pcVar13;
            if (pcVar13 == (char *)0x0) goto LAB_0015ef9e;
          }
          if (pcVar4 != (char *)0x0) {
            pcVar4 = CRYPTO_strdup(pcVar4,"crypto/srp/srp_vfy.c",0xd8);
            puVar9[5] = pcVar4;
            if (pcVar4 == (char *)0x0) goto LAB_0015ef9e;
          }
          iVar5 = SRP_user_pwd_set_sv_isra_3(puVar9 + 1,puVar9 + 2,puVar6[2],puVar6[1]);
          if (iVar5 == 0) {
            local_40 = (char *)0x2;
            goto LAB_0015eddc;
          }
          iVar5 = OPENSSL_sk_insert(*param_1,puVar9,0);
          local_40 = (char *)0x2;
          if (iVar5 == 0) goto LAB_0015eddc;
        }
LAB_0015ee3e:
        iVar12 = iVar12 + 1;
      }
      local_40 = local_30;
      if (local_30 == (char *)0x0) {
        puVar9 = (undefined4 *)0x0;
      }
      else {
        if (iVar1 == 0) {
LAB_0015f030:
          puVar6 = (undefined4 *)SRP_get_default_gN(local_30,iVar5);
          if (puVar6 == (undefined4 *)0x0) {
            local_40 = (char *)0x2;
            puVar9 = (undefined4 *)0x0;
            goto LAB_0015eddc;
          }
        }
        else {
          iVar5 = 0;
          do {
            iVar12 = OPENSSL_sk_num(iVar1);
            iVar11 = iVar5 + 1;
            if (iVar12 <= iVar5) goto LAB_0015f030;
            puVar6 = (undefined4 *)OPENSSL_sk_value(iVar1);
            iVar5 = iVar11;
          } while ((puVar6 == (undefined4 *)0x0) ||
                  (iVar12 = strcmp((char *)*puVar6,local_30), iVar12 != 0));
        }
        puVar9 = (undefined4 *)0x0;
        uVar7 = puVar6[2];
        local_40 = (char *)0x0;
        param_1[3] = puVar6[1];
        param_1[4] = uVar7;
      }
    }
  }
LAB_0015eddc:
  SRP_user_pwd_free(puVar9);
  TXT_DB_free(db);
  BIO_free_all(bp);
  OPENSSL_sk_free(iVar1);
  return local_40;
}


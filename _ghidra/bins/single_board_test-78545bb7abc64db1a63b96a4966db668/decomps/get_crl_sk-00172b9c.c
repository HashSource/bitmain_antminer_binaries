
void get_crl_sk(int param_1,int *param_2,int *param_3,undefined4 *param_4,uint *param_5,
               uint *param_6,undefined4 param_7)

{
  int iVar1;
  X509_NAME *pXVar2;
  X509_NAME *pXVar3;
  int iVar4;
  ASN1_TIME *pAVar5;
  X509 *pXVar6;
  undefined4 *puVar7;
  int *piVar8;
  GENERAL_NAME *a;
  GENERAL_NAME *b;
  undefined4 uVar9;
  undefined4 uVar10;
  int iVar11;
  uint uVar12;
  X509 *a_00;
  uint uVar13;
  uint uVar14;
  time_t *ptVar15;
  int iVar16;
  int iVar17;
  int iVar18;
  int *piVar19;
  int iVar20;
  uint local_78;
  int local_74;
  uint local_70;
  X509 *local_6c;
  uint local_68;
  X509 *local_64;
  uint local_5c;
  int local_50;
  int local_30;
  int local_2c [2];
  
  iVar20 = 0;
  a_00 = *(X509 **)(param_1 + 100);
  local_6c = (X509 *)0x0;
  local_64 = (X509 *)0x0;
  local_74 = 0;
  local_68 = 0;
  local_70 = *param_5;
  iVar1 = OPENSSL_sk_num(param_7);
  if (0 < iVar1) {
LAB_00172bd6:
    iVar1 = OPENSSL_sk_value(param_7,iVar20);
    uVar13 = *(uint *)(iVar1 + 0x54);
    if (-1 < (int)(uVar13 << 0x1e)) {
      local_78 = *param_6;
      if (-1 < *(int *)(*(int *)(param_1 + 0x10) + 0xc) << 0x13) {
        if ((uVar13 & 0x60) == 0) goto LAB_00172bfe;
        goto LAB_00172ce4;
      }
      if ((int)(uVar13 << 0x19) < 0) {
        if ((*(uint *)(iVar1 + 0x58) & ~local_78) != 0) goto LAB_00172bfe;
        goto LAB_00172ce4;
      }
      if (*(int *)(iVar1 + 0x60) != 0) goto LAB_00172ce4;
LAB_00172bfe:
      pXVar2 = X509_get_issuer_name(a_00);
      pXVar3 = (X509_NAME *)X509_CRL_get_issuer(iVar1);
      iVar4 = X509_NAME_cmp(pXVar2,pXVar3);
      if (iVar4 == 0) {
        uVar13 = 0x120;
        uVar12 = 0x20;
      }
      else {
        if (-1 < *(int *)(iVar1 + 0x54) << 0x1a) goto LAB_00172ce4;
        uVar13 = 0x100;
        uVar12 = 0;
      }
      uVar14 = *(uint *)(*(int *)(param_1 + 0x10) + 0xc);
      if ((*(uint *)(iVar1 + 0x48) & 0x200) != 0) {
        uVar13 = uVar12;
      }
      if ((int)(uVar14 << 0x1e) < 0) {
        ptVar15 = (time_t *)(*(int *)(param_1 + 0x10) + 4);
LAB_00172c48:
        pAVar5 = (ASN1_TIME *)X509_CRL_get0_lastUpdate(iVar1);
        iVar4 = X509_cmp_time(pAVar5,ptVar15);
        if (iVar4 < 0) {
          iVar4 = X509_CRL_get0_nextUpdate(iVar1);
          if (iVar4 != 0) {
            pAVar5 = (ASN1_TIME *)X509_CRL_get0_nextUpdate(iVar1);
            iVar4 = X509_cmp_time(pAVar5,ptVar15);
            if ((iVar4 == 0) || ((iVar4 < 0 && (-1 < *(int *)(param_1 + 0x70) << 0x1e))))
            goto LAB_00172c5a;
          }
          goto LAB_00172fa8;
        }
      }
      else {
        ptVar15 = (time_t *)(uVar14 & 0x200000);
        if (ptVar15 == (time_t *)0x0) goto LAB_00172c48;
LAB_00172fa8:
        uVar13 = uVar13 | 0x40;
      }
LAB_00172c5a:
      pXVar2 = (X509_NAME *)X509_CRL_get_issuer(iVar1);
      iVar18 = *(int *)(param_1 + 0x5c);
      iVar4 = OPENSSL_sk_num(*(undefined4 *)(param_1 + 0x50));
      iVar4 = iVar4 + -1;
      if (iVar18 != iVar4) {
        iVar4 = iVar18 + 1;
      }
      pXVar6 = (X509 *)OPENSSL_sk_value(*(undefined4 *)(param_1 + 0x50),iVar4);
      iVar18 = X509_check_akid(pXVar6,*(AUTHORITY_KEYID **)(iVar1 + 0x4c));
      if ((iVar18 == 0) && ((uVar13 & 0x20) != 0)) {
        uVar13 = uVar13 | 0x1c;
        local_6c = pXVar6;
      }
      else {
        iVar4 = iVar4 + 1;
        do {
          iVar18 = OPENSSL_sk_num(*(undefined4 *)(param_1 + 0x50));
          iVar16 = iVar4 + 1;
          if (iVar18 <= iVar4) {
            if (-1 < *(int *)(*(int *)(param_1 + 0x10) + 0xc) << 0x13) goto LAB_00172cd8;
            iVar4 = 0;
            goto LAB_00172f2c;
          }
          pXVar6 = (X509 *)OPENSSL_sk_value(*(undefined4 *)(param_1 + 0x50),iVar4);
          pXVar3 = X509_get_subject_name(pXVar6);
          iVar18 = X509_NAME_cmp(pXVar3,pXVar2);
          iVar4 = iVar16;
        } while ((iVar18 != 0) ||
                (iVar18 = X509_check_akid(pXVar6,*(AUTHORITY_KEYID **)(iVar1 + 0x4c)), iVar18 != 0))
        ;
        uVar13 = uVar13 | 0xc;
        local_6c = pXVar6;
      }
LAB_00172cd8:
      if ((uVar13 & 4) == 0) goto LAB_00172ce4;
      goto LAB_00172e0e;
    }
    goto LAB_00172ce4;
  }
LAB_00172cf0:
  if (local_74 != 0) {
    X509_CRL_free((X509_CRL *)*param_2);
    *param_2 = local_74;
    iVar1 = 0;
    *param_4 = local_64;
    *param_5 = local_70;
    *param_6 = local_68;
    X509_CRL_up_ref(local_74);
    X509_CRL_free((X509_CRL *)*param_3);
    *param_3 = 0;
    if ((*(int *)(*(int *)(param_1 + 0x10) + 0xc) << 0x12 < 0) &&
       ((int)((*(uint *)(local_74 + 0x48) | *(uint *)(*(int *)(param_1 + 100) + 0x80)) << 0x13) < 0)
       ) {
      for (; iVar20 = OPENSSL_sk_num(param_7), iVar1 < iVar20; iVar1 = iVar1 + 1) {
        iVar20 = OPENSSL_sk_value(param_7,iVar1);
        if ((*(int *)(iVar20 + 0x60) != 0) && (*(int *)(local_74 + 0x5c) != 0)) {
          pXVar2 = (X509_NAME *)X509_CRL_get_issuer(local_74);
          pXVar3 = (X509_NAME *)X509_CRL_get_issuer(iVar20);
          iVar4 = X509_NAME_cmp(pXVar2,pXVar3);
          if ((iVar4 == 0) &&
             ((((iVar4 = crl_extension_match(iVar20,local_74,0x5a), iVar4 != 0 &&
                (iVar4 = crl_extension_match(iVar20,local_74,0x302), iVar4 != 0)) &&
               (iVar4 = ASN1_INTEGER_cmp(*(ASN1_INTEGER **)(iVar20 + 0x60),
                                         *(ASN1_INTEGER **)(local_74 + 0x5c)), iVar4 < 1)) &&
              (iVar4 = ASN1_INTEGER_cmp(*(ASN1_INTEGER **)(iVar20 + 0x5c),
                                        *(ASN1_INTEGER **)(local_74 + 0x5c)), 0 < iVar4)))) {
            iVar1 = *(int *)(*(int *)(param_1 + 0x10) + 0xc);
            if (iVar1 << 0x1e < 0) {
              ptVar15 = (time_t *)(*(int *)(param_1 + 0x10) + 4);
LAB_00172dd0:
              pAVar5 = (ASN1_TIME *)X509_CRL_get0_lastUpdate(iVar20);
              iVar1 = X509_cmp_time(pAVar5,ptVar15);
              if (-1 < iVar1) goto LAB_00172de2;
              iVar1 = X509_CRL_get0_nextUpdate(iVar20);
              if (iVar1 != 0) {
                pAVar5 = (ASN1_TIME *)X509_CRL_get0_nextUpdate(iVar20);
                iVar1 = X509_cmp_time(pAVar5,ptVar15);
                if ((iVar1 == 0) || ((iVar1 < 0 && (-1 < *(int *)(param_1 + 0x70) << 0x1e))))
                goto LAB_00172de2;
              }
            }
            else if (-1 < iVar1 << 10) {
              ptVar15 = (time_t *)0x0;
              goto LAB_00172dd0;
            }
            *param_5 = *param_5 | 2;
LAB_00172de2:
            X509_CRL_up_ref(iVar20);
            *param_3 = iVar20;
            return;
          }
        }
      }
      *param_3 = 0;
    }
  }
  return;
  while( true ) {
    pXVar6 = (X509 *)OPENSSL_sk_value(*(undefined4 *)(param_1 + 8),iVar4);
    pXVar3 = X509_get_subject_name(pXVar6);
    iVar18 = X509_NAME_cmp(pXVar3,pXVar2);
    iVar4 = iVar16;
    if ((iVar18 == 0) &&
       (iVar18 = X509_check_akid(pXVar6,*(AUTHORITY_KEYID **)(iVar1 + 0x4c)), iVar18 == 0)) break;
LAB_00172f2c:
    iVar18 = OPENSSL_sk_num(*(undefined4 *)(param_1 + 8));
    iVar16 = iVar4 + 1;
    if (iVar18 <= iVar4) goto LAB_00172cd8;
  }
  uVar13 = uVar13 | 4;
  local_6c = pXVar6;
LAB_00172e0e:
  iVar4 = *(int *)(iVar1 + 0x54);
  if (-1 < iVar4 << 0x1b) {
    if (a_00[1].references << 0x1b < 0) {
      iVar4 = iVar4 << 0x1d;
    }
    else {
      iVar4 = iVar4 << 0x1c;
    }
    if (-1 < iVar4) {
      local_5c = *(uint *)(iVar1 + 0x58);
      iVar18 = 0;
      iVar4 = OPENSSL_sk_num(a_00[1].ex_kusage);
      if (0 < iVar4) {
        do {
          puVar7 = (undefined4 *)OPENSSL_sk_value(a_00[1].ex_kusage,iVar18);
          pXVar2 = (X509_NAME *)X509_CRL_get_issuer(iVar1);
          iVar4 = puVar7[2];
          if (iVar4 == 0) {
            if ((uVar13 & 0x20) != 0) {
LAB_00172e9e:
              if (*(undefined4 **)(iVar1 + 0x50) != (undefined4 *)0x0) {
                piVar19 = (int *)**(undefined4 **)(iVar1 + 0x50);
                piVar8 = (int *)*puVar7;
                if (piVar19 != (int *)0x0 && piVar8 != (int *)0x0) {
                  if (*piVar8 == 1) {
                    pXVar2 = (X509_NAME *)piVar8[2];
                    if (pXVar2 != (X509_NAME *)0x0) {
                      if (*piVar19 != 1) {
                        iVar4 = piVar19[1];
                        goto LAB_001730aa;
                      }
                      if (((X509_NAME *)piVar19[2] != (X509_NAME *)0x0) &&
                         (iVar4 = X509_NAME_cmp(pXVar2,(X509_NAME *)piVar19[2]), iVar4 == 0))
                      goto LAB_00172fbe;
                    }
                  }
                  else if (*piVar19 == 1) {
                    pXVar2 = (X509_NAME *)piVar19[2];
                    if (pXVar2 != (X509_NAME *)0x0) {
                      iVar4 = piVar8[1];
LAB_001730aa:
                      iVar16 = 0;
                      while( true ) {
                        iVar11 = OPENSSL_sk_num(iVar4);
                        iVar17 = iVar16 + 1;
                        if (iVar11 <= iVar16) break;
                        piVar8 = (int *)OPENSSL_sk_value(iVar4,iVar16);
                        iVar16 = iVar17;
                        if ((*piVar8 == 4) &&
                           (iVar11 = X509_NAME_cmp(pXVar2,(X509_NAME *)piVar8[1]), iVar11 == 0))
                        goto LAB_00172fbe;
                      }
                    }
                  }
                  else {
                    for (local_50 = 0; iVar4 = OPENSSL_sk_num(piVar8[1]), local_50 < iVar4;
                        local_50 = local_50 + 1) {
                      a = (GENERAL_NAME *)OPENSSL_sk_value(piVar8[1],local_50);
                      iVar4 = 0;
                      while( true ) {
                        iVar16 = OPENSSL_sk_num(piVar19[1]);
                        if (iVar16 <= iVar4) break;
                        b = (GENERAL_NAME *)OPENSSL_sk_value(piVar19[1]);
                        iVar16 = GENERAL_NAME_cmp(a,b);
                        iVar4 = iVar4 + 1;
                        if (iVar16 == 0) goto LAB_00172fbe;
                      }
                    }
                  }
                  goto LAB_00173064;
                }
              }
LAB_00172fbe:
              local_5c = local_5c & puVar7[3];
              goto LAB_00172fd6;
            }
          }
          else {
            iVar16 = 0;
            while( true ) {
              iVar4 = OPENSSL_sk_num(iVar4);
              if (iVar4 <= iVar16) break;
              piVar8 = (int *)OPENSSL_sk_value(puVar7[2],iVar16);
              if ((*piVar8 == 4) &&
                 (iVar4 = X509_NAME_cmp((X509_NAME *)piVar8[1],pXVar2), iVar4 == 0))
              goto LAB_00172e9e;
              iVar4 = puVar7[2];
              iVar16 = iVar16 + 1;
            }
          }
LAB_00173064:
          iVar18 = iVar18 + 1;
          iVar4 = OPENSSL_sk_num(a_00[1].ex_kusage);
        } while (iVar18 < iVar4);
      }
      if (((*(int **)(iVar1 + 0x50) == (int *)0x0) || (**(int **)(iVar1 + 0x50) == 0)) &&
         ((uVar13 & 0x20) != 0)) {
LAB_00172fd6:
        if ((local_5c & ~local_78) == 0) goto LAB_00172ce4;
        uVar13 = uVar13 | 0x80;
        local_78 = local_78 | local_5c;
      }
    }
  }
  if ((int)local_70 <= (int)uVar13 && uVar13 != 0) {
    if (local_74 != 0 && local_70 == uVar13) {
      uVar9 = X509_CRL_get0_lastUpdate(local_74);
      uVar10 = X509_CRL_get0_lastUpdate(iVar1);
      iVar4 = ASN1_TIME_diff(&local_30,local_2c,uVar9,uVar10);
      if ((iVar4 == 0) || ((local_30 < 1 && (local_2c[0] < 1)))) goto LAB_00172ce4;
    }
    local_68 = local_78;
    local_64 = local_6c;
    local_74 = iVar1;
    local_70 = uVar13;
  }
LAB_00172ce4:
  iVar20 = iVar20 + 1;
  iVar1 = OPENSSL_sk_num(param_7);
  if (iVar1 <= iVar20) goto LAB_00172cf0;
  goto LAB_00172bd6;
}


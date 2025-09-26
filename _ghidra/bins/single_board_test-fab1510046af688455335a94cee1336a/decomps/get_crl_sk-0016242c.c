
void get_crl_sk(int param_1,undefined4 *param_2,undefined4 *param_3,undefined4 *param_4,
               uint *param_5,uint *param_6,_STACK *param_7)

{
  int iVar1;
  int *piVar2;
  X509_NAME *pXVar3;
  X509 *pXVar4;
  X509_NAME *pXVar5;
  undefined4 *puVar6;
  _STACK *p_Var7;
  GENERAL_NAME *a;
  GENERAL_NAME *b;
  X509 *a_00;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  time_t *ptVar11;
  int iVar12;
  int iVar13;
  time_t *t;
  int *piVar14;
  int iVar15;
  int *piVar16;
  int iVar17;
  bool bVar18;
  uint local_68;
  uint local_64;
  X509 *local_60;
  int *local_5c;
  uint local_58;
  X509 *local_54;
  int local_44;
  
  local_60 = (X509 *)0x0;
  local_54 = (X509 *)0x0;
  a_00 = *(X509 **)(param_1 + 0x68);
  local_64 = *param_5;
  iVar17 = 0;
  local_5c = (int *)0x0;
  local_58 = 0;
  iVar1 = sk_num(param_7);
  if (0 < iVar1) {
LAB_0016245e:
    piVar2 = (int *)sk_value(param_7,iVar17);
    uVar9 = piVar2[7];
    local_68 = *param_6;
    if (-1 < (int)(uVar9 << 0x1e)) {
      if ((*(uint *)(*(int *)(param_1 + 0x14) + 0xc) & 0x1000) == 0) {
        uVar10 = 0;
        if ((uVar9 & 0x60) == 0) goto LAB_00162490;
        goto LAB_0016255e;
      }
      if ((uVar9 & 0x40) != 0) {
        if ((piVar2[8] & ~local_68) != 0) goto LAB_00162490;
        uVar10 = 0;
        goto LAB_0016255e;
      }
      if (piVar2[10] != 0) {
        uVar10 = 0;
        goto LAB_0016255e;
      }
LAB_00162490:
      pXVar3 = X509_get_issuer_name(a_00);
      iVar1 = X509_NAME_cmp(pXVar3,*(X509_NAME **)(*piVar2 + 8));
      if (iVar1 == 0) {
        uVar9 = 0x20;
      }
      else {
        uVar10 = piVar2[7] & 0x20;
        if (uVar10 == 0) goto LAB_0016255e;
        uVar9 = 0;
      }
      if (-1 < piVar2[4] << 0x16) {
        uVar9 = uVar9 | 0x100;
      }
      ptVar11 = (time_t *)(*(uint *)(*(int *)(param_1 + 0x14) + 0xc) & 2);
      if (ptVar11 != (time_t *)0x0) {
        ptVar11 = (time_t *)(*(int *)(param_1 + 0x14) + 4);
      }
      iVar1 = X509_cmp_time(*(ASN1_TIME **)(*piVar2 + 0xc),ptVar11);
      if (iVar1 < 0) {
        iVar1 = *piVar2;
        if (*(ASN1_TIME **)(iVar1 + 0x10) != (ASN1_TIME *)0x0) {
          iVar1 = X509_cmp_time(*(ASN1_TIME **)(iVar1 + 0x10),ptVar11);
          if ((iVar1 == 0) || ((iVar1 < 0 && (-1 < *(int *)(param_1 + 0x74) << 0x1e))))
          goto LAB_001624da;
          iVar1 = *piVar2;
        }
        uVar9 = uVar9 | 0x40;
      }
      else {
LAB_001624da:
        iVar1 = *piVar2;
      }
      iVar12 = *(int *)(param_1 + 0x60);
      pXVar3 = *(X509_NAME **)(iVar1 + 8);
      iVar1 = sk_num(*(_STACK **)(param_1 + 0x54));
      if (iVar12 != iVar1 + -1) {
        iVar12 = iVar12 + 1;
      }
      pXVar4 = (X509 *)sk_value(*(_STACK **)(param_1 + 0x54),iVar12);
      iVar1 = X509_check_akid(pXVar4,(AUTHORITY_KEYID *)piVar2[5]);
      if ((iVar1 == 0) && ((uVar9 & 0x20) != 0)) {
        uVar9 = uVar9 | 0x1c;
        local_60 = pXVar4;
      }
      else {
        iVar1 = iVar12 + 1;
        do {
          iVar12 = sk_num(*(_STACK **)(param_1 + 0x54));
          iVar13 = iVar1 + 1;
          if (iVar12 <= iVar1) {
            if (-1 < *(int *)(*(int *)(param_1 + 0x14) + 0xc) << 0x13) goto LAB_00162554;
            iVar1 = 0;
            goto LAB_001627cc;
          }
          pXVar4 = (X509 *)sk_value(*(_STACK **)(param_1 + 0x54),iVar1);
          pXVar5 = X509_get_subject_name(pXVar4);
          iVar12 = X509_NAME_cmp(pXVar5,pXVar3);
          iVar1 = iVar13;
        } while ((iVar12 != 0) ||
                (iVar12 = X509_check_akid(pXVar4,(AUTHORITY_KEYID *)piVar2[5]), iVar12 != 0));
        uVar9 = uVar9 | 0xc;
        local_60 = pXVar4;
      }
LAB_00162554:
      uVar10 = uVar9 & 4;
      if (uVar10 == 0) goto LAB_0016255e;
      goto LAB_001626ba;
    }
    uVar10 = 0;
    goto LAB_0016255e;
  }
LAB_00162582:
  if (local_5c == (int *)0x0) {
    return;
  }
  if ((X509_CRL *)*param_2 != (X509_CRL *)0x0) {
    X509_CRL_free((X509_CRL *)*param_2);
  }
  *param_2 = local_5c;
  *param_4 = local_54;
  *param_5 = local_64;
  *param_6 = local_58;
  CRYPTO_add_lock(local_5c + 3,1,6,"x509_vfy.c",0x3f0);
  if ((X509_CRL *)*param_3 != (X509_CRL *)0x0) {
    X509_CRL_free((X509_CRL *)*param_3);
    *param_3 = 0;
  }
  if (-1 < *(int *)(*(int *)(param_1 + 0x14) + 0xc) << 0x12) {
    return;
  }
  if (-1 < (int)((local_5c[4] | *(uint *)(*(int *)(param_1 + 0x68) + 0x28)) << 0x13)) {
    return;
  }
  ptVar11 = (time_t *)0x0;
  do {
    iVar1 = sk_num(param_7);
    t = (time_t *)((int)ptVar11 + 1);
    if (iVar1 <= (int)ptVar11) {
      *param_3 = 0;
      return;
    }
    piVar2 = (int *)sk_value(param_7,(int)ptVar11);
    ptVar11 = t;
  } while (((((piVar2[10] == 0) || (local_5c[9] == 0)) ||
            ((iVar1 = X509_NAME_cmp(*(X509_NAME **)(*local_5c + 8),*(X509_NAME **)(*piVar2 + 8)),
             iVar1 != 0 ||
             ((iVar1 = crl_extension_match(piVar2,local_5c,0x5a), iVar1 == 0 ||
              (iVar1 = crl_extension_match(piVar2,local_5c,0x302), iVar1 == 0)))))) ||
           (iVar1 = ASN1_INTEGER_cmp((ASN1_INTEGER *)piVar2[10],(ASN1_INTEGER *)local_5c[9]),
           0 < iVar1)) ||
          (iVar1 = ASN1_INTEGER_cmp((ASN1_INTEGER *)piVar2[9],(ASN1_INTEGER *)local_5c[9]),
          iVar1 < 1));
  bVar18 = (*(uint *)(*(int *)(param_1 + 0x14) + 0xc) & 2) == 0;
  if (bVar18) {
    t = (time_t *)0x0;
  }
  if (!bVar18) {
    t = (time_t *)(*(int *)(param_1 + 0x14) + 4);
  }
  iVar1 = X509_cmp_time(*(ASN1_TIME **)(*piVar2 + 0xc),t);
  if (iVar1 < 0) {
    if (*(ASN1_TIME **)(*piVar2 + 0x10) != (ASN1_TIME *)0x0) {
      iVar1 = X509_cmp_time(*(ASN1_TIME **)(*piVar2 + 0x10),t);
      if ((iVar1 == 0) || ((iVar1 < 0 && (-1 < *(int *)(param_1 + 0x74) << 0x1e))))
      goto LAB_0016267c;
    }
    *param_5 = *param_5 | 2;
  }
LAB_0016267c:
  CRYPTO_add_lock(piVar2 + 3,1,6,"x509_vfy.c",0x454);
  *param_3 = piVar2;
  return;
  while( true ) {
    pXVar4 = (X509 *)sk_value(*(_STACK **)(param_1 + 0xc),iVar1);
    pXVar5 = X509_get_subject_name(pXVar4);
    iVar12 = X509_NAME_cmp(pXVar5,pXVar3);
    iVar1 = iVar13;
    if ((iVar12 == 0) &&
       (iVar12 = X509_check_akid(pXVar4,(AUTHORITY_KEYID *)piVar2[5]), iVar12 == 0)) break;
LAB_001627cc:
    iVar12 = sk_num(*(_STACK **)(param_1 + 0xc));
    iVar13 = iVar1 + 1;
    if (iVar12 <= iVar1) goto LAB_00162554;
  }
  uVar9 = uVar9 | 4;
  local_60 = pXVar4;
LAB_001626ba:
  iVar1 = piVar2[7];
  uVar10 = uVar9;
  if (-1 < iVar1 << 0x1b) {
    if ((int)(a_00->ex_flags << 0x1b) < 0) {
      iVar1 = iVar1 << 0x1d;
    }
    else {
      iVar1 = iVar1 << 0x1c;
    }
    if (-1 < iVar1) {
      uVar8 = piVar2[8];
      iVar12 = 0;
      iVar1 = sk_num(&a_00->crldp->stack);
      if (0 < iVar1) {
        do {
          puVar6 = (undefined4 *)sk_value(&a_00->crldp->stack,iVar12);
          p_Var7 = (_STACK *)puVar6[2];
          pXVar3 = *(X509_NAME **)(*piVar2 + 8);
          iVar1 = 0;
          if (p_Var7 == (_STACK *)0x0) {
            if ((uVar9 & 0x20) != 0) {
LAB_00162742:
              if ((undefined4 *)piVar2[6] != (undefined4 *)0x0) {
                piVar16 = *(int **)piVar2[6];
                piVar14 = (int *)*puVar6;
                if (piVar14 != (int *)0x0 && piVar16 != (int *)0x0) {
                  if (*piVar14 == 1) {
                    pXVar3 = (X509_NAME *)piVar14[2];
                    if (pXVar3 != (X509_NAME *)0x0) {
                      if (*piVar16 != 1) {
                        p_Var7 = (_STACK *)piVar16[1];
                        goto LAB_001628bc;
                      }
                      if (((X509_NAME *)piVar16[2] != (X509_NAME *)0x0) &&
                         (iVar1 = X509_NAME_cmp(pXVar3,(X509_NAME *)piVar16[2]), iVar1 == 0))
                      goto LAB_00162832;
                    }
                  }
                  else if (*piVar16 == 1) {
                    pXVar3 = (X509_NAME *)piVar16[2];
                    if (pXVar3 != (X509_NAME *)0x0) {
                      p_Var7 = (_STACK *)piVar14[1];
LAB_001628bc:
                      iVar1 = 0;
                      while( true ) {
                        iVar13 = sk_num(p_Var7);
                        iVar15 = iVar1 + 1;
                        if (iVar13 <= iVar1) break;
                        piVar14 = (int *)sk_value(p_Var7,iVar1);
                        iVar1 = iVar15;
                        if ((*piVar14 == 4) &&
                           (iVar13 = X509_NAME_cmp(pXVar3,(X509_NAME *)piVar14[1]), iVar13 == 0))
                        goto LAB_00162832;
                      }
                    }
                  }
                  else {
                    for (local_44 = 0; iVar1 = sk_num((_STACK *)piVar14[1]), local_44 < iVar1;
                        local_44 = local_44 + 1) {
                      a = (GENERAL_NAME *)sk_value((_STACK *)piVar14[1],local_44);
                      iVar1 = 0;
                      while( true ) {
                        iVar13 = sk_num((_STACK *)piVar16[1]);
                        if (iVar13 <= iVar1) break;
                        b = (GENERAL_NAME *)sk_value((_STACK *)piVar16[1],iVar1);
                        iVar13 = GENERAL_NAME_cmp(a,b);
                        iVar1 = iVar1 + 1;
                        if (iVar13 == 0) goto LAB_00162832;
                      }
                    }
                  }
                  goto LAB_00162868;
                }
              }
LAB_00162832:
              uVar8 = puVar6[3] & uVar8;
              goto LAB_00162846;
            }
          }
          else {
            while( true ) {
              iVar13 = sk_num(p_Var7);
              if (iVar13 <= iVar1) break;
              piVar14 = (int *)sk_value((_STACK *)puVar6[2],iVar1);
              if ((*piVar14 == 4) &&
                 (iVar13 = X509_NAME_cmp((X509_NAME *)piVar14[1],pXVar3), iVar13 == 0))
              goto LAB_00162742;
              p_Var7 = (_STACK *)puVar6[2];
              iVar1 = iVar1 + 1;
            }
          }
LAB_00162868:
          iVar12 = iVar12 + 1;
          iVar1 = sk_num(&a_00->crldp->stack);
        } while (iVar12 < iVar1);
      }
      if ((((int *)piVar2[6] == (int *)0x0) || (*(int *)piVar2[6] == 0)) && ((uVar9 & 0x20) != 0)) {
LAB_00162846:
        uVar10 = uVar8 & ~local_68;
        if (uVar10 != 0) {
          local_68 = local_68 | uVar8;
          uVar10 = uVar9 | 0x80;
        }
      }
    }
  }
LAB_0016255e:
  if ((int)local_64 < (int)uVar10) {
    local_58 = local_68;
    local_54 = local_60;
    local_64 = uVar10;
    local_5c = piVar2;
  }
  iVar17 = iVar17 + 1;
  iVar1 = sk_num(param_7);
  if (iVar1 <= iVar17) goto LAB_00162582;
  goto LAB_0016245e;
}


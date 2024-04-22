
void get_crl_sk(int param_1,X509_CRL **param_2,X509_CRL **param_3,X509 **param_4,uint *param_5,
               uint *param_6,_STACK *param_7)

{
  int iVar1;
  X509_CRL *pXVar2;
  X509_NAME *pXVar3;
  X509 *pXVar4;
  X509_NAME *pXVar5;
  int **ppiVar6;
  _STACK *p_Var7;
  GENERAL_NAME *a;
  GENERAL_NAME *b;
  ASN1_TIME *s;
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
  X509_CRL_INFO *pXVar16;
  DIST_POINT_NAME *pDVar17;
  int iVar18;
  bool bVar19;
  uint local_68;
  uint local_64;
  X509 *local_60;
  X509_CRL *local_5c;
  uint local_58;
  X509 *local_54;
  int local_44;
  
  local_60 = (X509 *)0x0;
  local_54 = (X509 *)0x0;
  a_00 = *(X509 **)(param_1 + 0x68);
  local_64 = *param_5;
  iVar18 = 0;
  local_5c = (X509_CRL *)0x0;
  local_58 = 0;
  iVar1 = sk_num(param_7);
  if (0 < iVar1) {
LAB_000c10de:
    pXVar2 = (X509_CRL *)sk_value(param_7,iVar18);
    uVar9 = pXVar2->idp_flags;
    local_68 = *param_6;
    if (-1 < (int)(uVar9 << 0x1e)) {
      if ((*(uint *)(*(int *)(param_1 + 0x14) + 0xc) & 0x1000) == 0) {
        uVar10 = 0;
        if ((uVar9 & 0x60) == 0) goto LAB_000c1110;
        goto LAB_000c11de;
      }
      if ((uVar9 & 0x40) != 0) {
        if ((pXVar2->idp_reasons & ~local_68) != 0) goto LAB_000c1110;
        uVar10 = 0;
        goto LAB_000c11de;
      }
      if (pXVar2->base_crl_number != (ASN1_INTEGER *)0x0) {
        uVar10 = 0;
        goto LAB_000c11de;
      }
LAB_000c1110:
      pXVar3 = X509_get_issuer_name(a_00);
      iVar1 = X509_NAME_cmp(pXVar3,pXVar2->crl->issuer);
      if (iVar1 == 0) {
        uVar9 = 0x20;
      }
      else {
        uVar10 = pXVar2->idp_flags & 0x20;
        if (uVar10 == 0) goto LAB_000c11de;
        uVar9 = 0;
      }
      if (-1 < pXVar2->flags << 0x16) {
        uVar9 = uVar9 | 0x100;
      }
      ptVar11 = (time_t *)(*(uint *)(*(int *)(param_1 + 0x14) + 0xc) & 2);
      if (ptVar11 != (time_t *)0x0) {
        ptVar11 = (time_t *)(*(int *)(param_1 + 0x14) + 4);
      }
      iVar1 = X509_cmp_time(pXVar2->crl->lastUpdate,ptVar11);
      if (iVar1 < 0) {
        pXVar16 = pXVar2->crl;
        if (pXVar16->nextUpdate != (ASN1_TIME *)0x0) {
          iVar1 = X509_cmp_time(pXVar16->nextUpdate,ptVar11);
          if ((iVar1 == 0) || ((iVar1 < 0 && (-1 < *(int *)(param_1 + 0x74) << 0x1e))))
          goto LAB_000c115a;
          pXVar16 = pXVar2->crl;
        }
        uVar9 = uVar9 | 0x40;
      }
      else {
LAB_000c115a:
        pXVar16 = pXVar2->crl;
      }
      iVar12 = *(int *)(param_1 + 0x60);
      pXVar3 = pXVar16->issuer;
      iVar1 = sk_num(*(_STACK **)(param_1 + 0x54));
      if (iVar12 != iVar1 + -1) {
        iVar12 = iVar12 + 1;
      }
      pXVar4 = (X509 *)sk_value(*(_STACK **)(param_1 + 0x54),iVar12);
      iVar1 = X509_check_akid(pXVar4,pXVar2->akid);
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
            if (-1 < *(int *)(*(int *)(param_1 + 0x14) + 0xc) << 0x13) goto LAB_000c11d4;
            iVar1 = 0;
            goto LAB_000c144c;
          }
          pXVar4 = (X509 *)sk_value(*(_STACK **)(param_1 + 0x54),iVar1);
          pXVar5 = X509_get_subject_name(pXVar4);
          iVar12 = X509_NAME_cmp(pXVar5,pXVar3);
          iVar1 = iVar13;
        } while ((iVar12 != 0) || (iVar12 = X509_check_akid(pXVar4,pXVar2->akid), iVar12 != 0));
        uVar9 = uVar9 | 0xc;
        local_60 = pXVar4;
      }
LAB_000c11d4:
      uVar10 = uVar9 & 4;
      if (uVar10 == 0) goto LAB_000c11de;
      goto LAB_000c133a;
    }
    uVar10 = 0;
    goto LAB_000c11de;
  }
LAB_000c1202:
  if (local_5c == (X509_CRL *)0x0) {
    return;
  }
  if (*param_2 != (X509_CRL *)0x0) {
    X509_CRL_free(*param_2);
  }
  *param_2 = local_5c;
  *param_4 = local_54;
  *param_5 = local_64;
  *param_6 = local_58;
  CRYPTO_add_lock(&local_5c->references,1,6,DAT_000c14dc,0x3f0);
  if (*param_3 != (X509_CRL *)0x0) {
    X509_CRL_free(*param_3);
    *param_3 = (X509_CRL *)0x0;
  }
  if (-1 < *(int *)(*(int *)(param_1 + 0x14) + 0xc) << 0x12) {
    return;
  }
  if (-1 < (int)((local_5c->flags | *(uint *)(*(int *)(param_1 + 0x68) + 0x28)) << 0x13)) {
    return;
  }
  ptVar11 = (time_t *)0x0;
  do {
    iVar1 = sk_num(param_7);
    t = (time_t *)((int)ptVar11 + 1);
    if (iVar1 <= (int)ptVar11) {
      *param_3 = (X509_CRL *)0x0;
      return;
    }
    pXVar2 = (X509_CRL *)sk_value(param_7,(int)ptVar11);
    ptVar11 = t;
  } while (((((pXVar2->base_crl_number == (ASN1_INTEGER *)0x0) ||
             (local_5c->crl_number == (ASN1_INTEGER *)0x0)) ||
            ((iVar1 = X509_NAME_cmp(local_5c->crl->issuer,pXVar2->crl->issuer), iVar1 != 0 ||
             ((iVar1 = crl_extension_match(pXVar2,local_5c,0x5a), iVar1 == 0 ||
              (iVar1 = crl_extension_match(pXVar2,local_5c,0x302), iVar1 == 0)))))) ||
           (iVar1 = ASN1_INTEGER_cmp(pXVar2->base_crl_number,local_5c->crl_number), 0 < iVar1)) ||
          (iVar1 = ASN1_INTEGER_cmp(pXVar2->crl_number,local_5c->crl_number), iVar1 < 1));
  bVar19 = (*(uint *)(*(int *)(param_1 + 0x14) + 0xc) & 2) == 0;
  if (bVar19) {
    t = (time_t *)0x0;
  }
  if (!bVar19) {
    t = (time_t *)(*(int *)(param_1 + 0x14) + 4);
  }
  iVar1 = X509_cmp_time(pXVar2->crl->lastUpdate,t);
  if (iVar1 < 0) {
    s = pXVar2->crl->nextUpdate;
    if (s != (ASN1_TIME *)0x0) {
      iVar1 = X509_cmp_time(s,t);
      if ((iVar1 == 0) || ((iVar1 < 0 && (-1 < *(int *)(param_1 + 0x74) << 0x1e))))
      goto LAB_000c12fc;
    }
    *param_5 = *param_5 | 2;
  }
LAB_000c12fc:
  CRYPTO_add_lock(&pXVar2->references,1,6,DAT_000c14dc,0x454);
  *param_3 = pXVar2;
  return;
  while( true ) {
    pXVar4 = (X509 *)sk_value(*(_STACK **)(param_1 + 0xc),iVar1);
    pXVar5 = X509_get_subject_name(pXVar4);
    iVar12 = X509_NAME_cmp(pXVar5,pXVar3);
    iVar1 = iVar13;
    if ((iVar12 == 0) && (iVar12 = X509_check_akid(pXVar4,pXVar2->akid), iVar12 == 0)) break;
LAB_000c144c:
    iVar12 = sk_num(*(_STACK **)(param_1 + 0xc));
    iVar13 = iVar1 + 1;
    if (iVar12 <= iVar1) goto LAB_000c11d4;
  }
  uVar9 = uVar9 | 4;
  local_60 = pXVar4;
LAB_000c133a:
  iVar1 = pXVar2->idp_flags;
  uVar10 = uVar9;
  if (-1 < iVar1 << 0x1b) {
    if ((int)(a_00->ex_flags << 0x1b) < 0) {
      iVar1 = iVar1 << 0x1d;
    }
    else {
      iVar1 = iVar1 << 0x1c;
    }
    if (-1 < iVar1) {
      uVar8 = pXVar2->idp_reasons;
      iVar12 = 0;
      iVar1 = sk_num(&a_00->crldp->stack);
      if (0 < iVar1) {
        do {
          ppiVar6 = (int **)sk_value(&a_00->crldp->stack,iVar12);
          p_Var7 = (_STACK *)ppiVar6[2];
          pXVar3 = pXVar2->crl->issuer;
          iVar1 = 0;
          if (p_Var7 == (_STACK *)0x0) {
            if ((uVar9 & 0x20) != 0) {
LAB_000c13c2:
              if (pXVar2->idp != (ISSUING_DIST_POINT *)0x0) {
                pDVar17 = pXVar2->idp->distpoint;
                piVar14 = *ppiVar6;
                if (piVar14 != (int *)0x0 && pDVar17 != (DIST_POINT_NAME *)0x0) {
                  if (*piVar14 == 1) {
                    pXVar3 = (X509_NAME *)piVar14[2];
                    if (pXVar3 != (X509_NAME *)0x0) {
                      if (pDVar17->type != 1) {
                        p_Var7 = &((pDVar17->name).fullname)->stack;
                        goto LAB_000c153c;
                      }
                      if ((pDVar17->dpname != (X509_NAME *)0x0) &&
                         (iVar1 = X509_NAME_cmp(pXVar3,pDVar17->dpname), iVar1 == 0))
                      goto LAB_000c14b2;
                    }
                  }
                  else if (pDVar17->type == 1) {
                    pXVar3 = pDVar17->dpname;
                    if (pXVar3 != (X509_NAME *)0x0) {
                      p_Var7 = (_STACK *)piVar14[1];
LAB_000c153c:
                      iVar1 = 0;
                      while( true ) {
                        iVar13 = sk_num(p_Var7);
                        iVar15 = iVar1 + 1;
                        if (iVar13 <= iVar1) break;
                        piVar14 = (int *)sk_value(p_Var7,iVar1);
                        iVar1 = iVar15;
                        if ((*piVar14 == 4) &&
                           (iVar13 = X509_NAME_cmp(pXVar3,(X509_NAME *)piVar14[1]), iVar13 == 0))
                        goto LAB_000c14b2;
                      }
                    }
                  }
                  else {
                    for (local_44 = 0; iVar1 = sk_num((_STACK *)piVar14[1]), local_44 < iVar1;
                        local_44 = local_44 + 1) {
                      a = (GENERAL_NAME *)sk_value((_STACK *)piVar14[1],local_44);
                      iVar1 = 0;
                      while( true ) {
                        iVar13 = sk_num(&((pDVar17->name).fullname)->stack);
                        if (iVar13 <= iVar1) break;
                        b = (GENERAL_NAME *)sk_value(&((pDVar17->name).fullname)->stack,iVar1);
                        iVar13 = GENERAL_NAME_cmp(a,b);
                        iVar1 = iVar1 + 1;
                        if (iVar13 == 0) goto LAB_000c14b2;
                      }
                    }
                  }
                  goto LAB_000c14e8;
                }
              }
LAB_000c14b2:
              uVar8 = (uint)ppiVar6[3] & uVar8;
              goto LAB_000c14c6;
            }
          }
          else {
            while( true ) {
              iVar13 = sk_num(p_Var7);
              if (iVar13 <= iVar1) break;
              piVar14 = (int *)sk_value((_STACK *)ppiVar6[2],iVar1);
              if ((*piVar14 == 4) &&
                 (iVar13 = X509_NAME_cmp((X509_NAME *)piVar14[1],pXVar3), iVar13 == 0))
              goto LAB_000c13c2;
              p_Var7 = (_STACK *)ppiVar6[2];
              iVar1 = iVar1 + 1;
            }
          }
LAB_000c14e8:
          iVar12 = iVar12 + 1;
          iVar1 = sk_num(&a_00->crldp->stack);
        } while (iVar12 < iVar1);
      }
      if (((pXVar2->idp == (ISSUING_DIST_POINT *)0x0) ||
          (pXVar2->idp->distpoint == (DIST_POINT_NAME *)0x0)) && ((uVar9 & 0x20) != 0)) {
LAB_000c14c6:
        uVar10 = uVar8 & ~local_68;
        if (uVar10 != 0) {
          local_68 = local_68 | uVar8;
          uVar10 = uVar9 | 0x80;
        }
      }
    }
  }
LAB_000c11de:
  if ((int)local_64 < (int)uVar10) {
    local_58 = local_68;
    local_54 = local_60;
    local_64 = uVar10;
    local_5c = pXVar2;
  }
  iVar18 = iVar18 + 1;
  iVar1 = sk_num(param_7);
  if (iVar1 <= iVar18) goto LAB_000c1202;
  goto LAB_000c10de;
}



void x509v3_cache_extensions_part_7(X509 *param_1)

{
  byte bVar1;
  cmp *cmp;
  EVP_MD *type;
  long lVar2;
  BASIC_CONSTRAINTS *a;
  ASN1_INTEGER *pAVar3;
  PROXY_CERT_INFO_EXTENSION *a_00;
  ASN1_BIT_STRING *pAVar4;
  _STACK *p_Var5;
  ASN1_OBJECT *pAVar6;
  ASN1_OCTET_STRING *pAVar7;
  AUTHORITY_KEYID *pAVar8;
  X509_NAME *pXVar9;
  X509_NAME *pXVar10;
  stack_st_GENERAL_NAME *psVar11;
  NAME_CONSTRAINTS *pNVar12;
  int iVar13;
  DIST_POINT_NAME **ppDVar14;
  int *piVar15;
  int iVar16;
  X509_EXTENSION *ex;
  void *pvVar17;
  byte *pbVar18;
  ulong uVar19;
  int iVar20;
  uint uVar21;
  DIST_POINT_NAME *pDVar22;
  bool bVar23;
  ulong local_20;
  int local_1c;
  
  type = EVP_sha1();
  X509_digest(param_1,type,(uchar *)&param_1->rfc3779_addr,(uint *)0x0);
  lVar2 = ASN1_INTEGER_get(param_1->cert_info->version);
  if (lVar2 == 0) {
    param_1->ex_flags = param_1->ex_flags | 0x40;
  }
  a = (BASIC_CONSTRAINTS *)X509_get_ext_d2i(param_1,0x57,(int *)0x0,(int *)0x0);
  if (a != (BASIC_CONSTRAINTS *)0x0) {
    iVar20 = a->ca;
    if (iVar20 == 0) {
      pAVar3 = a->pathlen;
      if (pAVar3 != (ASN1_INTEGER *)0x0) goto LAB_000cb510;
LAB_000cb836:
      param_1->ex_pathlen = -1;
    }
    else {
      pAVar3 = a->pathlen;
      param_1->ex_flags = param_1->ex_flags | 0x10;
      if (pAVar3 == (ASN1_INTEGER *)0x0) goto LAB_000cb836;
LAB_000cb510:
      if ((pAVar3->type == 0x102) || (iVar20 == 0)) {
        param_1->ex_pathlen = 0;
        param_1->ex_flags = param_1->ex_flags | 0x80;
      }
      else {
        lVar2 = ASN1_INTEGER_get(pAVar3);
        param_1->ex_pathlen = lVar2;
      }
    }
    BASIC_CONSTRAINTS_free(a);
    param_1->ex_flags = param_1->ex_flags | 1;
  }
  a_00 = (PROXY_CERT_INFO_EXTENSION *)X509_get_ext_d2i(param_1,0x297,(int *)0x0,(int *)0x0);
  if (a_00 != (PROXY_CERT_INFO_EXTENSION *)0x0) {
    uVar21 = param_1->ex_flags;
    if ((int)(uVar21 << 0x1b) < 0) {
LAB_000cb552:
      param_1->ex_flags = uVar21 | 0x80;
    }
    else {
      iVar20 = X509_get_ext_by_NID(param_1,0x55,-1);
      if ((-1 < iVar20) || (iVar20 = X509_get_ext_by_NID(param_1,0x56,-1), -1 < iVar20)) {
        uVar21 = param_1->ex_flags;
        goto LAB_000cb552;
      }
    }
    if (a_00->pcPathLengthConstraint == (ASN1_INTEGER *)0x0) {
      param_1->ex_pcpathlen = -1;
    }
    else {
      lVar2 = ASN1_INTEGER_get(a_00->pcPathLengthConstraint);
      param_1->ex_pcpathlen = lVar2;
    }
    PROXY_CERT_INFO_EXTENSION_free(a_00);
    param_1->ex_flags = param_1->ex_flags | 0x400;
  }
  pAVar4 = (ASN1_BIT_STRING *)X509_get_ext_d2i(param_1,0x53,(int *)0x0,(int *)0x0);
  if (pAVar4 != (ASN1_BIT_STRING *)0x0) {
    iVar20 = pAVar4->length;
    if (iVar20 < 1) {
      param_1->ex_kusage = 0;
    }
    else {
      pbVar18 = pAVar4->data;
      bVar1 = *pbVar18;
      param_1->ex_kusage = (uint)bVar1;
      if (iVar20 != 1) {
        param_1->ex_kusage = (uint)CONCAT11(pbVar18[1],bVar1);
      }
    }
    param_1->ex_flags = param_1->ex_flags | 2;
    ASN1_BIT_STRING_free(pAVar4);
  }
  param_1->ex_xkusage = 0;
  p_Var5 = (_STACK *)X509_get_ext_d2i(param_1,0x7e,(int *)0x0,(int *)0x0);
  if (p_Var5 != (_STACK *)0x0) {
    local_20 = 0;
    param_1->ex_flags = param_1->ex_flags | 4;
    while (iVar20 = sk_num(p_Var5), (int)local_20 < iVar20) {
      pAVar6 = (ASN1_OBJECT *)sk_value(p_Var5,local_20);
      iVar20 = OBJ_obj2nid(pAVar6);
      if (iVar20 == 0x85) {
        param_1->ex_xkusage = param_1->ex_xkusage | 0x40;
      }
      else if (iVar20 < 0x86) {
        if (iVar20 == 0x82) {
          param_1->ex_xkusage = param_1->ex_xkusage | 2;
        }
        else if (iVar20 < 0x83) {
          if (iVar20 == 0x81) {
            param_1->ex_xkusage = param_1->ex_xkusage | 1;
          }
        }
        else if (iVar20 == 0x83) {
          param_1->ex_xkusage = param_1->ex_xkusage | 8;
        }
        else if (iVar20 == 0x84) {
          param_1->ex_xkusage = param_1->ex_xkusage | 4;
        }
      }
      else if (iVar20 == 0xb4) {
        param_1->ex_xkusage = param_1->ex_xkusage | 0x20;
      }
      else if (iVar20 < 0xb5) {
        if ((iVar20 == 0x89) || (iVar20 == 0x8b)) {
          param_1->ex_xkusage = param_1->ex_xkusage | 0x10;
        }
      }
      else if (iVar20 == 0x129) {
        param_1->ex_xkusage = param_1->ex_xkusage | 0x80;
      }
      else if (iVar20 == 0x38e) {
        param_1->ex_xkusage = param_1->ex_xkusage | 0x100;
      }
      local_20 = local_20 + 1;
    }
    sk_pop_free(p_Var5,DAT_000cb8c4);
  }
  pAVar4 = (ASN1_BIT_STRING *)X509_get_ext_d2i(param_1,0x47,(int *)0x0,(int *)0x0);
  if (pAVar4 != (ASN1_BIT_STRING *)0x0) {
    if (pAVar4->length < 1) {
      uVar19 = 0;
    }
    else {
      uVar19 = (ulong)*pAVar4->data;
    }
    param_1->ex_nscert = uVar19;
    param_1->ex_flags = param_1->ex_flags | 8;
    ASN1_BIT_STRING_free(pAVar4);
  }
  pAVar7 = (ASN1_OCTET_STRING *)X509_get_ext_d2i(param_1,0x52,(int *)0x0,(int *)0x0);
  param_1->skid = pAVar7;
  pAVar8 = (AUTHORITY_KEYID *)X509_get_ext_d2i(param_1,0x5a,(int *)0x0,(int *)0x0);
  param_1->akid = pAVar8;
  pXVar9 = X509_get_subject_name(param_1);
  pXVar10 = X509_get_issuer_name(param_1);
  iVar20 = X509_NAME_cmp(pXVar9,pXVar10);
  if (iVar20 == 0) {
    pAVar8 = param_1->akid;
    uVar21 = param_1->ex_flags | 0x20;
    param_1->ex_flags = uVar21;
    if (pAVar8 != (AUTHORITY_KEYID *)0x0) {
      if (((pAVar8->keyid != (ASN1_STRING *)0x0) && (param_1->skid != (ASN1_STRING *)0x0)) &&
         (iVar20 = ASN1_OCTET_STRING_cmp(pAVar8->keyid,param_1->skid), iVar20 != 0))
      goto LAB_000cb6b2;
      if (pAVar8->serial != (ASN1_INTEGER *)0x0) {
        pAVar3 = X509_get_serialNumber(param_1);
        iVar20 = ASN1_INTEGER_cmp(pAVar3,pAVar8->serial);
        if (iVar20 != 0) goto LAB_000cb6b2;
      }
      p_Var5 = &pAVar8->issuer->stack;
      if (p_Var5 != (_STACK *)0x0) {
        iVar20 = 0;
        do {
          iVar13 = sk_num(p_Var5);
          if (iVar13 <= iVar20) goto LAB_000cb896;
          piVar15 = (int *)sk_value(p_Var5,iVar20);
          iVar20 = iVar20 + 1;
        } while (*piVar15 != 4);
        pXVar9 = (X509_NAME *)piVar15[1];
        if (pXVar9 != (X509_NAME *)0x0) {
          pXVar10 = X509_get_issuer_name(param_1);
          iVar20 = X509_NAME_cmp(pXVar9,pXVar10);
          if (iVar20 != 0) goto LAB_000cb6b2;
        }
      }
LAB_000cb896:
      uVar21 = param_1->ex_flags;
    }
    param_1->ex_flags = uVar21 | 0x2000;
  }
LAB_000cb6b2:
  psVar11 = (stack_st_GENERAL_NAME *)X509_get_ext_d2i(param_1,0x55,(int *)0x0,(int *)0x0);
  param_1->altname = psVar11;
  pNVar12 = (NAME_CONSTRAINTS *)X509_get_ext_d2i(param_1,0x29a,(int *)&local_20,(int *)0x0);
  param_1->nc = pNVar12;
  if (pNVar12 == (NAME_CONSTRAINTS *)0x0) {
    uVar19 = local_20 + 1;
    bVar23 = uVar19 != 0;
    if (bVar23) {
      uVar19 = param_1->ex_flags | 0x80;
    }
    if (bVar23) {
      param_1->ex_flags = uVar19;
    }
  }
  p_Var5 = (_STACK *)X509_get_ext_d2i(param_1,0x67,(int *)0x0,(int *)0x0);
  param_1->crldp = (stack_st_DIST_POINT *)p_Var5;
  for (iVar20 = 0; iVar13 = sk_num(p_Var5), cmp = DAT_000cb8c8, iVar20 < iVar13; iVar20 = iVar20 + 1
      ) {
    ppDVar14 = (DIST_POINT_NAME **)sk_value(&param_1->crldp->stack,iVar20);
    pDVar22 = ppDVar14[1];
    if (pDVar22 == (DIST_POINT_NAME *)0x0) {
      ppDVar14[3] = (DIST_POINT_NAME *)0x807f;
    }
    else {
      uVar21 = pDVar22->type;
      if ((int)uVar21 < 1) {
        pDVar22 = ppDVar14[3];
      }
      else {
        pXVar9 = pDVar22->dpname;
        bVar23 = uVar21 != 1;
        pDVar22 = (DIST_POINT_NAME *)(uint)*(byte *)&pXVar9->entries;
        ppDVar14[3] = pDVar22;
        if (bVar23) {
          uVar21 = (uint)*(byte *)((int)&pXVar9->entries + 1);
        }
        if (bVar23) {
          pDVar22 = (DIST_POINT_NAME *)((uint)pDVar22 | uVar21 << 8);
        }
      }
      ppDVar14[3] = (DIST_POINT_NAME *)((uint)pDVar22 & 0x807f);
    }
    if ((*ppDVar14 != (DIST_POINT_NAME *)0x0) && ((*ppDVar14)->type == 1)) {
      iVar13 = 0;
      do {
        iVar16 = sk_num((_STACK *)ppDVar14[2]);
        if (iVar16 <= iVar13) goto LAB_000cb758;
        piVar15 = (int *)sk_value((_STACK *)ppDVar14[2],iVar13);
        iVar13 = iVar13 + 1;
      } while (*piVar15 != 4);
      pXVar9 = (X509_NAME *)piVar15[1];
      if (pXVar9 == (X509_NAME *)0x0) {
LAB_000cb758:
        pXVar9 = X509_get_issuer_name(param_1);
      }
      DIST_POINT_set_dpname(*ppDVar14,pXVar9);
    }
    p_Var5 = &param_1->crldp->stack;
  }
  local_20 = 0;
  do {
    iVar20 = X509_get_ext_count(param_1);
    if (iVar20 <= (int)local_20) {
      uVar21 = param_1->ex_flags;
LAB_000cb7d0:
      param_1->ex_flags = uVar21 | 0x100;
      return;
    }
    uVar19 = local_20;
    ex = X509_get_ext(param_1,local_20);
    pAVar6 = X509_EXTENSION_get_object(ex);
    iVar20 = OBJ_obj2nid(pAVar6);
    if (iVar20 == 0x359) {
      uVar19 = param_1->ex_flags | 0x1000;
    }
    if (iVar20 == 0x359) {
      param_1->ex_flags = uVar19;
    }
    iVar20 = X509_EXTENSION_get_critical(ex);
    if (iVar20 != 0) {
      pAVar6 = X509_EXTENSION_get_object(ex);
      local_1c = OBJ_obj2nid(pAVar6);
      if ((local_1c == 0) ||
         (pvVar17 = OBJ_bsearch_(&local_1c,DAT_000cb8cc,0xb,4,cmp), pvVar17 == (void *)0x0)) {
        uVar21 = param_1->ex_flags | 0x200;
        goto LAB_000cb7d0;
      }
    }
    local_20 = local_20 + 1;
  } while( true );
}


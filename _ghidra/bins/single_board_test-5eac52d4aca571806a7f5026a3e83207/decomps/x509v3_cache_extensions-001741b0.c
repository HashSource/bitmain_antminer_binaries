
void x509v3_cache_extensions(X509 *param_1)

{
  byte bVar1;
  EVP_MD *type;
  int iVar2;
  BASIC_CONSTRAINTS *a;
  ASN1_INTEGER *a_00;
  ASN1_BIT_STRING *pAVar3;
  PROXY_CERT_INFO_EXTENSION *a_01;
  long lVar4;
  ASN1_STRING *pAVar5;
  void *pvVar6;
  ASN1_OBJECT *pAVar7;
  int *piVar8;
  int iVar9;
  ASN1_OCTET_STRING *pAVar10;
  AUTHORITY_KEYID *pAVar11;
  X509_EXTENSION *ex;
  X509_NAME *pXVar12;
  X509_NAME *b;
  int *piVar13;
  EVP_PKEY *pkey;
  byte *pbVar14;
  uint uVar15;
  uint extraout_r3;
  uint uVar16;
  uint *puVar17;
  bool bVar18;
  int local_2c;
  int local_28;
  int local_24 [2];
  
  DataMemoryBarrier(0x1b);
  if (*(int *)(param_1[1].sha1_hash + 4) != 0) {
    return;
  }
  CRYPTO_THREAD_write_lock(*(undefined4 *)param_1[1].sha1_hash);
  if ((param_1[1].references & 0x100U) != 0) goto LAB_0017448e;
  type = EVP_sha1();
  iVar2 = X509_digest(param_1,type,(uchar *)&param_1[1].policy_cache,(uint *)0x0);
  if (iVar2 == 0) {
    param_1[1].references = param_1[1].references | 0x100080;
  }
  iVar2 = X509_get_version(param_1);
  if (iVar2 == 0) {
    param_1[1].references = param_1[1].references | 0x40;
  }
  a = (BASIC_CONSTRAINTS *)X509_get_ext_d2i(param_1,0x57,&local_2c,(int *)0x0);
  if (a == (BASIC_CONSTRAINTS *)0x0) {
    uVar15 = local_2c + 1;
    bVar18 = uVar15 != 0;
    if (bVar18) {
      uVar15 = param_1[1].references | 0x80;
    }
    if (bVar18) {
      param_1[1].references = uVar15;
    }
  }
  else {
    if (a->ca != 0) {
      param_1[1].references = param_1[1].references | 0x10;
    }
    a_00 = a->pathlen;
    if (a_00 == (ASN1_INTEGER *)0x0) {
      param_1[1].signature = (ASN1_BIT_STRING *)0xffffffff;
    }
    else {
      if (a_00->type != 0x102) {
        pAVar3 = (ASN1_BIT_STRING *)ASN1_INTEGER_get(a_00);
        iVar2 = a->ca;
        param_1[1].signature = pAVar3;
        if (pAVar3 == (ASN1_BIT_STRING *)0x0 || iVar2 != 0) goto LAB_0017426e;
      }
      param_1[1].signature = (ASN1_BIT_STRING *)0x0;
      param_1[1].references = param_1[1].references | 0x80;
    }
LAB_0017426e:
    BASIC_CONSTRAINTS_free(a);
    param_1[1].references = param_1[1].references | 1;
  }
  a_01 = (PROXY_CERT_INFO_EXTENSION *)X509_get_ext_d2i(param_1,0x297,&local_2c,(int *)0x0);
  if (a_01 == (PROXY_CERT_INFO_EXTENSION *)0x0) {
    uVar15 = local_2c + 1;
    bVar18 = uVar15 != 0;
    if (bVar18) {
      uVar15 = param_1[1].references | 0x80;
    }
    if (bVar18) {
      param_1[1].references = uVar15;
    }
  }
  else {
    uVar15 = param_1[1].references;
    if ((int)(uVar15 << 0x1b) < 0) {
LAB_001742a0:
      param_1[1].references = uVar15 | 0x80;
    }
    else {
      iVar2 = X509_get_ext_by_NID(param_1,0x55,-1);
      if ((-1 < iVar2) || (iVar2 = X509_get_ext_by_NID(param_1,0x56,-1), -1 < iVar2)) {
        uVar15 = param_1[1].references;
        goto LAB_001742a0;
      }
    }
    if (a_01->pcPathLengthConstraint == (ASN1_INTEGER *)0x0) {
      param_1[1].valid = -1;
    }
    else {
      lVar4 = ASN1_INTEGER_get(a_01->pcPathLengthConstraint);
      param_1[1].valid = lVar4;
    }
    PROXY_CERT_INFO_EXTENSION_free(a_01);
    param_1[1].references = param_1[1].references | 0x400;
  }
  pAVar5 = (ASN1_STRING *)X509_get_ext_d2i(param_1,0x53,&local_2c,(int *)0x0);
  if (pAVar5 == (ASN1_STRING *)0x0) {
    uVar15 = local_2c + 1;
    bVar18 = uVar15 != 0;
    if (bVar18) {
      uVar15 = param_1[1].references | 0x80;
    }
    if (bVar18) {
      param_1[1].references = uVar15;
    }
  }
  else {
    iVar2 = pAVar5->length;
    if (iVar2 < 1) {
      param_1[1].name = (char *)0x0;
    }
    else {
      pbVar14 = pAVar5->data;
      bVar1 = *pbVar14;
      param_1[1].name = (char *)(uint)bVar1;
      if (iVar2 != 1) {
        param_1[1].name = (char *)(uint)CONCAT11(pbVar14[1],bVar1);
      }
    }
    param_1[1].references = param_1[1].references | 2;
    ASN1_BIT_STRING_free(pAVar5);
  }
  param_1[1].ex_data.sk = (stack_st_void *)0x0;
  pvVar6 = X509_get_ext_d2i(param_1,0x7e,&local_2c,(int *)0x0);
  if (pvVar6 == (void *)0x0) {
    uVar15 = local_2c + 1;
    bVar18 = uVar15 != 0;
    if (bVar18) {
      uVar15 = param_1[1].references | 0x80;
    }
    if (bVar18) {
      param_1[1].references = uVar15;
    }
  }
  else {
    local_2c = 0;
    param_1[1].references = param_1[1].references | 4;
    while (iVar2 = OPENSSL_sk_num(pvVar6), local_2c < iVar2) {
      pAVar7 = (ASN1_OBJECT *)OPENSSL_sk_value(pvVar6);
      iVar2 = OBJ_obj2nid(pAVar7);
      if (iVar2 == 0x85) {
        param_1[1].ex_data.sk = (stack_st_void *)((uint)param_1[1].ex_data.sk | 0x40);
      }
      else if (iVar2 < 0x86) {
        if (iVar2 == 0x82) {
          param_1[1].ex_data.sk = (stack_st_void *)((uint)param_1[1].ex_data.sk | 2);
        }
        else if (iVar2 < 0x83) {
          if (iVar2 == 0x81) {
            param_1[1].ex_data.sk = (stack_st_void *)((uint)param_1[1].ex_data.sk | 1);
          }
        }
        else if (iVar2 == 0x83) {
          param_1[1].ex_data.sk = (stack_st_void *)((uint)param_1[1].ex_data.sk | 8);
        }
        else if (iVar2 == 0x84) {
          param_1[1].ex_data.sk = (stack_st_void *)((uint)param_1[1].ex_data.sk | 4);
        }
      }
      else if (iVar2 == 0xb4) {
        param_1[1].ex_data.sk = (stack_st_void *)((uint)param_1[1].ex_data.sk | 0x20);
      }
      else if (iVar2 < 0xb5) {
        if ((iVar2 == 0x89) || (iVar2 == 0x8b)) {
          param_1[1].ex_data.sk = (stack_st_void *)((uint)param_1[1].ex_data.sk | 0x10);
        }
      }
      else if (iVar2 == 0x129) {
        param_1[1].ex_data.sk = (stack_st_void *)((uint)param_1[1].ex_data.sk | 0x80);
      }
      else if (iVar2 == 0x38e) {
        param_1[1].ex_data.sk = (stack_st_void *)((uint)param_1[1].ex_data.sk | 0x100);
      }
      local_2c = local_2c + 1;
    }
    OPENSSL_sk_pop_free(pvVar6,0x17b9f5);
  }
  pAVar5 = (ASN1_STRING *)X509_get_ext_d2i(param_1,0x47,&local_2c,(int *)0x0);
  if (pAVar5 == (ASN1_STRING *)0x0) {
    uVar15 = local_2c + 1;
    bVar18 = uVar15 != 0;
    if (bVar18) {
      uVar15 = param_1[1].references | 0x80;
    }
    if (bVar18) {
      param_1[1].references = uVar15;
    }
  }
  else {
    if (pAVar5->length < 1) {
      uVar15 = 0;
    }
    else {
      uVar15 = (uint)*pAVar5->data;
    }
    uVar16 = param_1[1].references;
    param_1[1].ex_data.dummy = uVar15;
    param_1[1].references = uVar16 | 8;
    ASN1_BIT_STRING_free(pAVar5);
  }
  pvVar6 = X509_get_ext_d2i(param_1,0x52,&local_2c,(int *)0x0);
  param_1[1].ex_pathlen = (long)pvVar6;
  if (pvVar6 == (void *)0x0) {
    uVar15 = local_2c + 1;
    bVar18 = uVar15 != 0;
    if (bVar18) {
      uVar15 = param_1[1].references | 0x80;
    }
    if (bVar18) {
      param_1[1].references = uVar15;
    }
  }
  pvVar6 = X509_get_ext_d2i(param_1,0x5a,&local_2c,(int *)0x0);
  param_1[1].ex_pcpathlen = (long)pvVar6;
  if (pvVar6 == (void *)0x0) {
    uVar15 = local_2c + 1;
    bVar18 = uVar15 != 0;
    if (bVar18) {
      uVar15 = param_1[1].references | 0x80;
    }
    if (bVar18) {
      param_1[1].references = uVar15;
    }
  }
  pXVar12 = X509_get_subject_name(param_1);
  b = X509_get_issuer_name(param_1);
  iVar2 = X509_NAME_cmp(pXVar12,b);
  if (iVar2 == 0) {
    param_1[1].references = param_1[1].references | 0x20;
    iVar2 = X509_check_akid(param_1,(AUTHORITY_KEYID *)param_1[1].ex_pcpathlen);
    if ((iVar2 == 0) && (pkey = (EVP_PKEY *)X509_get0_pubkey(param_1), pkey != (EVP_PKEY *)0x0)) {
      iVar2 = EVP_PKEY_base_id(pkey);
      iVar2 = OBJ_find_sigid_algs(iVar2,(int *)0x0,&local_28);
      if (iVar2 == 0) {
        local_28 = EVP_PKEY_base_id(pkey);
      }
      iVar2 = OBJ_obj2nid((ASN1_OBJECT *)param_1->name);
      iVar2 = OBJ_find_sigid_algs(iVar2,(int *)0x0,local_24);
      if ((iVar2 != 0) && (iVar2 = EVP_PKEY_type(local_24[0]), iVar2 == local_28)) {
        param_1[1].references = param_1[1].references | 0x2000;
      }
    }
  }
  pvVar6 = X509_get_ext_d2i(param_1,0x55,&local_2c,(int *)0x0);
  param_1[1].ex_xkusage = (ulong)pvVar6;
  if (pvVar6 == (void *)0x0) {
    uVar15 = local_2c + 1;
    bVar18 = uVar15 != 0;
    if (bVar18) {
      uVar15 = param_1[1].references | 0x80;
    }
    if (bVar18) {
      param_1[1].references = uVar15;
    }
  }
  pvVar6 = X509_get_ext_d2i(param_1,0x29a,&local_2c,(int *)0x0);
  param_1[1].ex_nscert = (ulong)pvVar6;
  if (pvVar6 == (void *)0x0) {
    uVar15 = local_2c + 1;
    bVar18 = uVar15 != 0;
    if (bVar18) {
      uVar15 = param_1[1].references | 0x80;
    }
    if (bVar18) {
      param_1[1].references = uVar15;
    }
  }
  pvVar6 = X509_get_ext_d2i(param_1,0x67,local_24,(int *)0x0);
  param_1[1].ex_kusage = (ulong)pvVar6;
  if ((pvVar6 == (void *)0x0) && (local_24[0] != -1)) {
LAB_001743d8:
    param_1[1].references = param_1[1].references | 0x80;
  }
  else {
    local_24[0] = 0;
    while (iVar2 = OPENSSL_sk_num(pvVar6), local_24[0] < iVar2) {
      piVar13 = (int *)OPENSSL_sk_value(param_1[1].ex_kusage);
      puVar17 = (uint *)piVar13[1];
      if (puVar17 == (uint *)0x0) {
        piVar13[3] = 0x807f;
      }
      else {
        uVar15 = *puVar17;
        if ((int)uVar15 < 1) {
          uVar16 = piVar13[3];
        }
        else {
          pbVar14 = (byte *)puVar17[2];
          bVar18 = uVar15 != 1;
          uVar16 = (uint)*pbVar14;
          piVar13[3] = uVar16;
          if (bVar18) {
            uVar15 = (uint)pbVar14[1];
          }
          if (bVar18) {
            uVar16 = uVar16 | uVar15 << 8;
          }
        }
        piVar13[3] = uVar16 & 0x807f;
      }
      if (((int *)*piVar13 != (int *)0x0) && (*(int *)*piVar13 == 1)) {
        iVar2 = 0;
        do {
          iVar9 = OPENSSL_sk_num(piVar13[2]);
          if (iVar9 <= iVar2) goto LAB_001743c4;
          piVar8 = (int *)OPENSSL_sk_value(piVar13[2],iVar2);
          iVar2 = iVar2 + 1;
        } while (*piVar8 != 4);
        pXVar12 = (X509_NAME *)piVar8[1];
        if (pXVar12 == (X509_NAME *)0x0) {
LAB_001743c4:
          pXVar12 = X509_get_issuer_name(param_1);
        }
        iVar2 = DIST_POINT_set_dpname((DIST_POINT_NAME *)*piVar13,pXVar12);
        if (iVar2 == 0) goto LAB_001743d8;
      }
      pvVar6 = (void *)param_1[1].ex_kusage;
      local_24[0] = local_24[0] + 1;
    }
  }
  pAVar10 = (ASN1_OCTET_STRING *)X509_get_ext_d2i(param_1,0x122,&local_2c,(int *)0x0);
  param_1[1].skid = pAVar10;
  if (pAVar10 == (ASN1_OCTET_STRING *)0x0) {
    uVar15 = local_2c + 1;
    bVar18 = uVar15 != 0;
    if (bVar18) {
      uVar15 = param_1[1].references | 0x80;
    }
    if (bVar18) {
      param_1[1].references = uVar15;
    }
  }
  pAVar11 = (AUTHORITY_KEYID *)X509_get_ext_d2i(param_1,0x123,&local_2c,(int *)0x0);
  param_1[1].akid = pAVar11;
  if (pAVar11 == (AUTHORITY_KEYID *)0x0) {
    uVar15 = local_2c + 1;
    bVar18 = uVar15 != 0;
    if (bVar18) {
      uVar15 = param_1[1].references | 0x80;
    }
    if (bVar18) {
      param_1[1].references = uVar15;
    }
  }
  local_2c = 0;
  while (iVar2 = X509_get_ext_count(param_1), local_2c < iVar2) {
    ex = X509_get_ext(param_1,local_2c);
    pAVar7 = X509_EXTENSION_get_object(ex);
    iVar2 = OBJ_obj2nid(pAVar7);
    uVar15 = extraout_r3;
    if (iVar2 == 0x359) {
      uVar15 = param_1[1].references | 0x1000;
    }
    if (iVar2 == 0x359) {
      param_1[1].references = uVar15;
    }
    iVar2 = X509_EXTENSION_get_critical(ex);
    if ((iVar2 != 0) && (iVar2 = X509_supported_extension(ex), iVar2 == 0)) {
      param_1[1].references = param_1[1].references | 0x200;
      break;
    }
    local_2c = local_2c + 1;
  }
  x509_init_sig_info(param_1);
  param_1[1].references = param_1[1].references | 0x100;
  DataMemoryBarrier(0x1b);
  param_1[1].sha1_hash[4] = '\x01';
  param_1[1].sha1_hash[5] = '\0';
  param_1[1].sha1_hash[6] = '\0';
  param_1[1].sha1_hash[7] = '\0';
LAB_0017448e:
  CRYPTO_THREAD_unlock(*(undefined4 *)param_1[1].sha1_hash);
  return;
}


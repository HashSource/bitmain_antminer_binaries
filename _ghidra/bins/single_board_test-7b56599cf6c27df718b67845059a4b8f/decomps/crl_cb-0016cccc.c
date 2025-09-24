
undefined4 crl_cb(undefined4 param_1,undefined4 *param_2)

{
  EVP_MD *type;
  int iVar1;
  X509_ALGOR *pXVar2;
  X509_NAME *iname;
  X509_CRL_INFO *pXVar3;
  void *pvVar4;
  AUTHORITY_KEYID *pAVar5;
  int iVar6;
  X509_EXTENSION *pXVar7;
  undefined4 uVar8;
  X509_REVOKED *x;
  ASN1_INTEGER *a;
  ISSUING_DIST_POINT *pIVar9;
  ASN1_ENUMERATED *a_00;
  ASN1_TIME *pAVar10;
  ASN1_TYPE *pAVar11;
  ASN1_OBJECT *pAVar12;
  ASN1_BIT_STRING *pAVar13;
  byte *pbVar14;
  ASN1_BIT_STRING *pAVar15;
  uint uVar16;
  code *pcVar17;
  int iVar18;
  X509_CRL *data;
  int unaff_r6;
  int iVar19;
  ASN1_INTEGER *pAVar20;
  bool bVar21;
  int local_30;
  int local_2c [2];
  
  data = (X509_CRL *)*param_2;
  switch(param_1) {
  default:
    return 1;
  case 3:
    if (((*(int *)(data[1].sha1_hash + 4) != 0) &&
        (pcVar17 = *(code **)(*(int *)(data[1].sha1_hash + 4) + 8), pcVar17 != (code *)0x0)) &&
       (iVar1 = (*pcVar17)(data), iVar1 == 0)) {
      return 0;
    }
    AUTHORITY_KEYID_free((AUTHORITY_KEYID *)data[1].crl);
    ISSUING_DIST_POINT_free((ISSUING_DIST_POINT *)data[1].sig_alg);
    ASN1_INTEGER_free((ASN1_STRING *)data[1].flags);
    ASN1_INTEGER_free((ASN1_STRING *)data[1].akid);
    OPENSSL_sk_pop_free(data[1].idp,(undefined *)0x1757a5);
    return 1;
  case 4:
    pcVar17 = *(code **)(*(int *)(data[1].sha1_hash + 4) + 8);
    if ((pcVar17 != (code *)0x0) && (iVar1 = (*pcVar17)(data), iVar1 == 0)) {
      return 0;
    }
    AUTHORITY_KEYID_free((AUTHORITY_KEYID *)data[1].crl);
    ISSUING_DIST_POINT_free((ISSUING_DIST_POINT *)data[1].sig_alg);
    ASN1_INTEGER_free((ASN1_STRING *)data[1].flags);
    ASN1_INTEGER_free((ASN1_STRING *)data[1].akid);
    OPENSSL_sk_pop_free(data[1].idp,(undefined *)0x1757a5);
  case 1:
    data[1].sig_alg = (X509_ALGOR *)0x0;
    data[1].crl = (X509_CRL_INFO *)0x0;
    uVar8 = default_crl_method;
    data->meth_data = (void *)0x0;
    data[1].signature = (ASN1_BIT_STRING *)0x0;
    *(undefined4 *)(data[1].sha1_hash + 4) = uVar8;
    data[1].sha1_hash[8] = '\0';
    data[1].sha1_hash[9] = '\0';
    data[1].sha1_hash[10] = '\0';
    data[1].sha1_hash[0xb] = '\0';
    data[1].idp = (ISSUING_DIST_POINT *)0x0;
    data[1].flags = 0;
    data[1].akid = (AUTHORITY_KEYID *)0x0;
    data[1].references = 0x807f;
    return 1;
  case 5:
    break;
  }
  type = EVP_sha1();
  iVar1 = X509_CRL_digest(data,type,(uchar *)&data[1].idp_flags,(uint *)0x0);
  if (iVar1 == 0) {
    data->meth_data = (void *)((uint)data->meth_data | 0x80);
  }
  pXVar2 = (X509_ALGOR *)X509_CRL_get_ext_d2i(data,0x302,&local_30,(int *)0x0);
  data[1].sig_alg = pXVar2;
  if (pXVar2 == (X509_ALGOR *)0x0) {
    if (local_30 != -1) goto LAB_0016ce0e;
  }
  else {
    pAVar11 = pXVar2->parameter;
    pAVar13 = data[1].signature;
    pAVar12 = pXVar2[1].algorithm;
    pAVar15 = (ASN1_BIT_STRING *)((uint)pAVar13 | 1);
    if (0 < (int)pAVar11) {
      unaff_r6 = 3;
    }
    data[1].signature = pAVar15;
    if (0 < (int)pAVar11) {
      pAVar15 = (ASN1_BIT_STRING *)((uint)pAVar13 | 5);
    }
    if ((int)pAVar11 < 1) {
      unaff_r6 = 2;
      iVar1 = 1;
    }
    else {
      data[1].signature = pAVar15;
      iVar1 = 2;
    }
    pAVar11 = pXVar2[2].parameter;
    if ((int)pAVar12 < 1) {
      unaff_r6 = iVar1;
      if (0 < (int)pAVar11) goto LAB_0016cdb4;
    }
    else {
      pAVar15 = (ASN1_BIT_STRING *)((uint)pAVar15 | 8);
      data[1].signature = pAVar15;
      if (0 < (int)pAVar11) {
LAB_0016cdb4:
        pAVar15 = (ASN1_BIT_STRING *)((uint)pAVar15 | 0x10);
        data[1].signature = pAVar15;
        iVar1 = unaff_r6;
      }
      if (iVar1 != 1) {
        pAVar15 = (ASN1_BIT_STRING *)((uint)pAVar15 | 2);
      }
      if (iVar1 != 1) {
        data[1].signature = pAVar15;
      }
    }
    pAVar11 = pXVar2[1].parameter;
    if (0 < (int)pXVar2[2].algorithm) {
      pAVar15 = (ASN1_BIT_STRING *)((uint)pAVar15 | 0x20);
    }
    if (0 < (int)pXVar2[2].algorithm) {
      data[1].signature = pAVar15;
    }
    if (pAVar11 != (ASN1_TYPE *)0x0) {
      iVar1 = pAVar11->type;
      data[1].signature = (ASN1_BIT_STRING *)((uint)pAVar15 | 0x40);
      if (iVar1 < 1) {
        uVar16 = data[1].references;
      }
      else {
        pbVar14 = (byte *)pAVar11[1].type;
        uVar16 = (uint)*pbVar14;
        data[1].references = uVar16;
        if (iVar1 != 1) {
          pbVar14 = (byte *)(uint)pbVar14[1];
        }
        if (iVar1 != 1) {
          uVar16 = uVar16 | (int)pbVar14 << 8;
        }
      }
      data[1].references = uVar16 & 0x807f;
    }
    pAVar12 = pXVar2->algorithm;
    iname = (X509_NAME *)X509_CRL_get_issuer(data);
    iVar1 = DIST_POINT_set_dpname((DIST_POINT_NAME *)pAVar12,iname);
    if (iVar1 == 0) {
LAB_0016ce0e:
      data->meth_data = (void *)((uint)data->meth_data | 0x80);
    }
  }
  pXVar3 = (X509_CRL_INFO *)X509_CRL_get_ext_d2i(data,0x5a,&local_30,(int *)0x0);
  data[1].crl = pXVar3;
  if (pXVar3 == (X509_CRL_INFO *)0x0) {
    pvVar4 = (void *)(local_30 + 1);
    bVar21 = pvVar4 != (void *)0x0;
    if (bVar21) {
      pvVar4 = (void *)((uint)data->meth_data | 0x80);
    }
    if (bVar21) {
      data->meth_data = pvVar4;
    }
  }
  pvVar4 = X509_CRL_get_ext_d2i(data,0x58,&local_30,(int *)0x0);
  data[1].flags = (int)pvVar4;
  if (pvVar4 == (void *)0x0) {
    pvVar4 = (void *)(local_30 + 1);
    bVar21 = pvVar4 != (void *)0x0;
    if (bVar21) {
      pvVar4 = (void *)((uint)data->meth_data | 0x80);
    }
    if (bVar21) {
      data->meth_data = pvVar4;
    }
  }
  pAVar5 = (AUTHORITY_KEYID *)X509_CRL_get_ext_d2i(data,0x8c,&local_30,(int *)0x0);
  data[1].akid = pAVar5;
  if (pAVar5 == (AUTHORITY_KEYID *)0x0) {
    if (local_30 == -1) goto LAB_0016ce5a;
  }
  else if (data[1].flags != 0) goto LAB_0016ce5a;
  data->meth_data = (void *)((uint)data->meth_data | 0x80);
LAB_0016ce5a:
  iVar19 = data->idp_flags;
  iVar1 = 0;
  do {
    while( true ) {
      iVar6 = OPENSSL_sk_num(iVar19);
      iVar18 = iVar1 + 1;
      if (iVar6 <= iVar1) goto LAB_0016ceba;
      pXVar7 = (X509_EXTENSION *)OPENSSL_sk_value(iVar19,iVar1);
      pAVar12 = X509_EXTENSION_get_object(pXVar7);
      iVar6 = OBJ_obj2nid(pAVar12);
      iVar1 = iVar18;
      if (iVar6 == 0x359) break;
      iVar18 = X509_EXTENSION_get_critical(pXVar7);
      if ((iVar18 != 0) && (iVar6 != 0x8c && (iVar6 != 0x5a && iVar6 != 0x302))) goto LAB_0016ceb2;
    }
    data->meth_data = (void *)((uint)data->meth_data | 0x1000);
    iVar6 = X509_EXTENSION_get_critical(pXVar7);
  } while (iVar6 == 0);
LAB_0016ceb2:
  data->meth_data = (void *)((uint)data->meth_data | 0x200);
LAB_0016ceba:
  pAVar20 = (ASN1_INTEGER *)0x0;
  uVar8 = X509_CRL_get_REVOKED(data);
  iVar1 = 0;
LAB_0016ced0:
  do {
    iVar19 = OPENSSL_sk_num(uVar8);
    if (iVar19 <= iVar1) {
LAB_0016d014:
      pcVar17 = *(code **)(*(int *)(data[1].sha1_hash + 4) + 4);
      if ((pcVar17 != (code *)0x0) && (iVar1 = (*pcVar17)(data), iVar1 == 0)) {
        return 0;
      }
      data->meth_data = (void *)((uint)data->meth_data | 0x100);
      return 1;
    }
    x = (X509_REVOKED *)OPENSSL_sk_value(uVar8,iVar1);
    a = (ASN1_INTEGER *)X509_REVOKED_get_ext_d2i(x,0x303,local_2c,(int *)0x0);
    if (a == (ASN1_INTEGER *)0x0) {
      if (local_2c[0] == -1) goto LAB_0016cf08;
LAB_0016d00c:
      data->meth_data = (void *)((uint)data->meth_data | 0x80);
      goto LAB_0016d014;
    }
    pIVar9 = data[1].idp;
    if (pIVar9 == (ISSUING_DIST_POINT *)0x0) {
      pIVar9 = (ISSUING_DIST_POINT *)OPENSSL_sk_new_null();
      data[1].idp = pIVar9;
      if (pIVar9 == (ISSUING_DIST_POINT *)0x0) goto LAB_0016cfea;
    }
    iVar19 = OPENSSL_sk_push(pIVar9,a);
    pAVar20 = a;
    if (iVar19 == 0) {
LAB_0016cfea:
      GENERAL_NAMES_free((GENERAL_NAMES *)a);
      return 0;
    }
LAB_0016cf08:
    x[1].serialNumber = pAVar20;
    a_00 = (ASN1_ENUMERATED *)X509_REVOKED_get_ext_d2i(x,0x8d,local_2c,(int *)0x0);
    if (a_00 == (ASN1_ENUMERATED *)0x0) {
      if (local_2c[0] != -1) goto LAB_0016d00c;
      x[1].revocationDate = (ASN1_TIME *)0xffffffff;
    }
    else {
      pAVar10 = (ASN1_TIME *)ASN1_ENUMERATED_get(a_00);
      x[1].revocationDate = pAVar10;
      ASN1_ENUMERATED_free(a_00);
    }
    iVar6 = x->sequence;
    local_2c[0] = 0;
    iVar19 = OPENSSL_sk_num(iVar6);
    if (local_2c[0] < iVar19) {
      do {
        pXVar7 = (X509_EXTENSION *)OPENSSL_sk_value(iVar6);
        iVar19 = X509_EXTENSION_get_critical(pXVar7);
        if (iVar19 != 0) {
          pAVar12 = X509_EXTENSION_get_object(pXVar7);
          iVar19 = OBJ_obj2nid(pAVar12);
          if (iVar19 != 0x303) {
            iVar1 = iVar1 + 1;
            data->meth_data = (void *)((uint)data->meth_data | 0x200);
            goto LAB_0016ced0;
          }
        }
        local_2c[0] = local_2c[0] + 1;
        iVar19 = OPENSSL_sk_num(iVar6);
      } while (local_2c[0] < iVar19);
    }
    iVar1 = iVar1 + 1;
  } while( true );
}


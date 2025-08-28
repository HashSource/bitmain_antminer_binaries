
CMS_SignerInfo *
CMS_add1_signer(CMS_ContentInfo *cms,X509 *signer,EVP_PKEY *pk,EVP_MD *md,uint flags)

{
  int iVar1;
  ASN1_VALUE *pAVar2;
  int iVar3;
  EVP_PKEY_CTX *ctx;
  _STACK *p_Var4;
  X509_ALGOR *pXVar5;
  CMS_SignerInfo *si;
  void *bytes;
  char *name;
  undefined4 uVar6;
  int *piVar7;
  undefined4 *puVar8;
  ASN1_OBJECT *pAVar9;
  int iVar10;
  code *pcVar11;
  int local_34;
  ASN1_OBJECT *local_30;
  ASN1_OBJECT *local_2c [2];
  
  iVar1 = X509_check_private_key(signer,pk);
  if (iVar1 == 0) {
    ERR_put_error(0x2e,0x66,0x88,"cms_sd.c",0x114);
    return (CMS_SignerInfo *)0x0;
  }
  if (*(int *)(cms + 4) == 0) {
    pAVar2 = ASN1_item_new((ASN1_ITEM *)CMS_SignedData_it);
    *(ASN1_VALUE **)(cms + 4) = pAVar2;
    if (pAVar2 == (ASN1_VALUE *)0x0) {
      ERR_put_error(0x2e,0x95,0x41,"cms_sd.c",0x53);
      return (CMS_SignerInfo *)0x0;
    }
    puVar8 = *(undefined4 **)(pAVar2 + 8);
    *(undefined4 *)pAVar2 = 1;
    pAVar9 = OBJ_nid2obj(0x15);
    *puVar8 = pAVar9;
    pAVar9 = *(ASN1_OBJECT **)cms;
    *(undefined4 *)(*(int *)(*(int *)(cms + 4) + 8) + 8) = 1;
    ASN1_OBJECT_free(pAVar9);
    pAVar9 = OBJ_nid2obj(0x16);
    piVar7 = *(int **)(cms + 4);
    *(ASN1_OBJECT **)cms = pAVar9;
  }
  else {
    iVar1 = OBJ_obj2nid(*(ASN1_OBJECT **)cms);
    if (iVar1 != 0x16) {
      ERR_put_error(0x2e,0x85,0x6c,"cms_sd.c",0x48);
      return (CMS_SignerInfo *)0x0;
    }
    piVar7 = *(int **)(cms + 4);
  }
  if (piVar7 == (int *)0x0) {
    return (CMS_SignerInfo *)0x0;
  }
  pAVar2 = ASN1_item_new((ASN1_ITEM *)CMS_SignerInfo_it);
  if (pAVar2 == (ASN1_VALUE *)0x0) {
    ERR_put_error(0x2e,0x66,0x41,"cms_sd.c",0x195);
    return (CMS_SignerInfo *)0x0;
  }
  X509_check_purpose(signer,-1,-1);
  CRYPTO_add_lock(&pk->references,1,10,"cms_sd.c",0x11f);
  CRYPTO_add_lock(&signer->references,1,3,"cms_sd.c",0x120);
  *(EVP_PKEY **)(pAVar2 + 0x20) = pk;
  *(X509 **)(pAVar2 + 0x1c) = signer;
  EVP_MD_CTX_init((EVP_MD_CTX *)(pAVar2 + 0x24));
  *(undefined4 *)(pAVar2 + 0x3c) = 0;
  if ((flags & 0x10000) == 0) {
    puVar8 = *(undefined4 **)(pAVar2 + 4);
    *(undefined4 *)pAVar2 = 1;
    iVar1 = cms_set1_ias(puVar8 + 1,signer);
    uVar6 = 0;
  }
  else {
    iVar1 = *piVar7;
    puVar8 = *(undefined4 **)(pAVar2 + 4);
    *(undefined4 *)pAVar2 = 3;
    if (iVar1 < 3) {
      *piVar7 = 3;
    }
    iVar1 = cms_set1_keyid(puVar8 + 1,signer);
    uVar6 = 1;
  }
  if (iVar1 == 0) goto LAB_001112fe;
  *puVar8 = uVar6;
  if (md == (EVP_MD *)0x0) {
    iVar1 = EVP_PKEY_get_default_digest_nid(pk,&local_34);
    if (iVar1 < 1) goto LAB_001112fe;
    name = OBJ_nid2sn(local_34);
    md = EVP_get_digestbyname(name);
    if (md == (EVP_MD *)0x0) {
      ERR_put_error(0x2e,0x66,0x80,"cms_sd.c",0x13a);
      goto LAB_001112fe;
    }
  }
  cms_DigestAlgorithm_set(*(undefined4 *)(pAVar2 + 8),md);
  for (iVar1 = 0; iVar3 = sk_num((_STACK *)piVar7[1]), iVar1 < iVar3; iVar1 = iVar1 + 1) {
    pXVar5 = (X509_ALGOR *)sk_value((_STACK *)piVar7[1],iVar1);
    X509_ALGOR_get0(local_2c,(int *)0x0,(void **)0x0,pXVar5);
    iVar3 = OBJ_obj2nid(local_2c[0]);
    iVar10 = EVP_MD_type(md);
    if (iVar3 == iVar10) break;
  }
  iVar3 = sk_num((_STACK *)piVar7[1]);
  if (iVar1 == iVar3) {
    pXVar5 = X509_ALGOR_new();
    if (pXVar5 != (X509_ALGOR *)0x0) {
      cms_DigestAlgorithm_set(pXVar5,md);
      iVar1 = sk_push((_STACK *)piVar7[1],pXVar5);
      if (iVar1 != 0) goto LAB_0011126c;
      X509_ALGOR_free(pXVar5);
    }
    goto LAB_001112ec;
  }
LAB_0011126c:
  if ((flags & 0x40000) == 0) {
    iVar1 = *(int *)(*(int *)(pAVar2 + 0x20) + 0xc);
    if ((iVar1 != 0) && (pcVar11 = *(code **)(iVar1 + 0x58), pcVar11 != (code *)0x0)) {
      iVar1 = (*pcVar11)(*(int *)(pAVar2 + 0x20),5,0,pAVar2);
      if (iVar1 == -2) {
        ERR_put_error(0x2e,0xaa,0x7d,"cms_sd.c",0x100);
        goto LAB_001112fe;
      }
      if (iVar1 < 1) {
        ERR_put_error(0x2e,0xaa,0x6f,"cms_sd.c",0x104);
        goto LAB_001112fe;
      }
    }
  }
  if ((flags & 0x100) == 0) {
    if (*(int *)(pAVar2 + 0xc) == 0) {
      p_Var4 = sk_new_null();
      *(_STACK **)(pAVar2 + 0xc) = p_Var4;
      if (p_Var4 == (_STACK *)0x0) goto LAB_001112ec;
    }
    pAVar9 = (ASN1_OBJECT *)(flags & 0x200);
    if (pAVar9 != (ASN1_OBJECT *)0x0) {
LAB_00111292:
      if ((int)(flags << 0x10) < 0) {
        iVar1 = OBJ_obj2nid(*(ASN1_OBJECT **)cms);
        if (iVar1 == 0x16) {
          p_Var4 = *(_STACK **)(cms + 4);
          if (p_Var4 != (_STACK *)0x0) {
            p_Var4 = (_STACK *)p_Var4[1].num;
          }
        }
        else {
          ERR_put_error(0x2e,0x85,0x6c,"cms_sd.c",0x48);
          p_Var4 = (_STACK *)0x0;
        }
        iVar1 = 0;
        do {
          iVar3 = sk_num(p_Var4);
          iVar10 = iVar1 + 1;
          if (iVar3 <= iVar1) {
            ERR_put_error(0x2e,0x6c,0x83,"cms_sd.c",0xc1);
            goto LAB_001112fe;
          }
          si = (CMS_SignerInfo *)sk_value(p_Var4,iVar1);
          iVar1 = iVar10;
        } while (((pAVar2 == (ASN1_VALUE *)si) || (iVar3 = CMS_signed_get_attr_count(si), iVar3 < 0)
                 ) || (iVar3 = OBJ_cmp((ASN1_OBJECT *)**(undefined4 **)(pAVar2 + 8),
                                       (ASN1_OBJECT *)**(undefined4 **)(si + 8)), iVar3 != 0));
        pAVar9 = OBJ_nid2obj(0x33);
        bytes = CMS_signed_get0_data_by_OBJ(si,pAVar9,-3,4);
        if (bytes == (void *)0x0) {
          ERR_put_error(0x2e,0x6c,0x72,"cms_sd.c",0xb6);
          goto LAB_001112fe;
        }
        iVar1 = CMS_signed_add1_attr_by_NID((CMS_SignerInfo *)pAVar2,0x33,4,bytes,-1);
        if ((iVar1 == 0) ||
           (((flags & 0x44000) == 0 &&
            (iVar1 = CMS_SignerInfo_sign((CMS_SignerInfo *)pAVar2), iVar1 == 0))))
        goto LAB_001112fe;
      }
      goto LAB_0011129a;
    }
    local_30 = pAVar9;
    iVar1 = CMS_add_standard_smimecap((stack_st_X509_ALGOR **)&local_30);
    if ((iVar1 == 0) ||
       (local_2c[0] = pAVar9, iVar1 = i2d_X509_ALGORS((X509_ALGORS *)local_30,(uchar **)local_2c),
       iVar1 < 1)) {
      sk_pop_free((_STACK *)local_30,X509_ALGOR_free);
    }
    else {
      iVar1 = CMS_signed_add1_attr_by_NID((CMS_SignerInfo *)pAVar2,0xa7,0x10,local_2c[0],iVar1);
      CRYPTO_free(local_2c[0]);
      sk_pop_free((_STACK *)local_30,X509_ALGOR_free);
      if (iVar1 != 0) goto LAB_00111292;
    }
  }
  else {
LAB_0011129a:
    if (((int)(flags << 0x1e) < 0) || (iVar1 = CMS_add1_cert(cms,signer), iVar1 != 0)) {
      if ((flags & 0x40000) != 0) {
        if ((flags & 0x100) == 0) {
          iVar1 = EVP_DigestSignInit((EVP_MD_CTX *)(pAVar2 + 0x24),(EVP_PKEY_CTX **)(pAVar2 + 0x3c),
                                     md,(ENGINE *)0x0,pk);
        }
        else {
          ctx = EVP_PKEY_CTX_new(*(EVP_PKEY **)(pAVar2 + 0x20),(ENGINE *)0x0);
          *(EVP_PKEY_CTX **)(pAVar2 + 0x3c) = ctx;
          if ((ctx == (EVP_PKEY_CTX *)0x0) || (iVar1 = EVP_PKEY_sign_init(ctx), iVar1 < 1))
          goto LAB_001112fe;
          iVar1 = EVP_PKEY_CTX_ctrl(*(EVP_PKEY_CTX **)(pAVar2 + 0x3c),-1,0xf8,1,0,md);
        }
        if (iVar1 < 1) goto LAB_001112fe;
      }
      p_Var4 = (_STACK *)piVar7[5];
      if (p_Var4 == (_STACK *)0x0) {
        p_Var4 = sk_new_null();
        piVar7[5] = (int)p_Var4;
        if (p_Var4 == (_STACK *)0x0) goto LAB_001112ec;
      }
      iVar1 = sk_push(p_Var4,pAVar2);
      if (iVar1 != 0) {
        return (CMS_SignerInfo *)pAVar2;
      }
    }
  }
LAB_001112ec:
  ERR_put_error(0x2e,0x66,0x41,"cms_sd.c",0x195);
LAB_001112fe:
  ASN1_item_free(pAVar2,(ASN1_ITEM *)CMS_SignerInfo_it);
  return (CMS_SignerInfo *)0x0;
}


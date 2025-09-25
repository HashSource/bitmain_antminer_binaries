
CMS_SignerInfo *
CMS_add1_signer(CMS_ContentInfo *cms,X509 *signer,EVP_PKEY *pk,EVP_MD *md,uint flags)

{
  int iVar1;
  ASN1_VALUE *pAVar2;
  int iVar3;
  EVP_PKEY_CTX *ctx;
  stack_st_CMS_SignerInfo *psVar4;
  CMS_SignerInfo *si;
  ASN1_OBJECT *pAVar5;
  void *bytes;
  X509_ALGOR *pXVar6;
  char *name;
  undefined4 uVar7;
  code *pcVar8;
  int iVar9;
  int *piVar10;
  undefined4 *puVar11;
  ASN1_OBJECT *local_2c [2];
  
  iVar1 = X509_check_private_key(signer,pk);
  if (iVar1 == 0) {
    ERR_put_error(0x2e,0x66,0x88,"crypto/cms/cms_sd.c",0xfb);
    return (CMS_SignerInfo *)0x0;
  }
  if (*(int *)(cms + 4) == 0) {
    pAVar2 = ASN1_item_new((ASN1_ITEM *)CMS_SignedData_it);
    *(ASN1_VALUE **)(cms + 4) = pAVar2;
    if (pAVar2 != (ASN1_VALUE *)0x0) {
      puVar11 = *(undefined4 **)(pAVar2 + 8);
      *(undefined4 *)pAVar2 = 1;
      pAVar5 = OBJ_nid2obj(0x15);
      *puVar11 = pAVar5;
      pAVar5 = *(ASN1_OBJECT **)cms;
      *(undefined4 *)(*(int *)(*(int *)(cms + 4) + 8) + 8) = 1;
      ASN1_OBJECT_free(pAVar5);
      pAVar5 = OBJ_nid2obj(0x16);
      piVar10 = *(int **)(cms + 4);
      *(ASN1_OBJECT **)cms = pAVar5;
      goto LAB_0018e92a;
    }
    ERR_put_error(0x2e,0x95,0x41,"crypto/cms/cms_sd.c",0x25);
  }
  else {
    iVar1 = OBJ_obj2nid(*(ASN1_OBJECT **)cms);
    if (iVar1 == 0x16) {
      piVar10 = *(int **)(cms + 4);
LAB_0018e92a:
      if (piVar10 != (int *)0x0) {
        pAVar2 = ASN1_item_new((ASN1_ITEM *)CMS_SignerInfo_it);
        if (pAVar2 == (ASN1_VALUE *)0x0) goto LAB_0018eac8;
        X509_check_purpose(signer,-1,-1);
        X509_up_ref(signer);
        EVP_PKEY_up_ref(pk);
        *(EVP_PKEY **)(pAVar2 + 0x20) = pk;
        *(X509 **)(pAVar2 + 0x1c) = signer;
        iVar1 = EVP_MD_CTX_new();
        *(int *)(pAVar2 + 0x24) = iVar1;
        *(undefined4 *)(pAVar2 + 0x28) = 0;
        if (iVar1 == 0) {
          iVar1 = 0x110;
          goto LAB_0018ead0;
        }
        if ((flags & 0x10000) == 0) {
          *(undefined4 *)pAVar2 = 1;
          uVar7 = 0;
        }
        else {
          iVar1 = *piVar10;
          *(undefined4 *)pAVar2 = 3;
          uVar7 = 1;
          if (iVar1 < 3) {
            *piVar10 = 3;
          }
        }
        iVar1 = cms_set1_SignerIdentifier(*(undefined4 *)(pAVar2 + 4),signer,uVar7);
        if (iVar1 == 0) goto LAB_0018ea78;
        if (md == (EVP_MD *)0x0) {
          iVar1 = EVP_PKEY_get_default_digest_nid(pk,(int *)local_2c);
          if (iVar1 < 1) goto LAB_0018ea78;
          name = OBJ_nid2sn((int)local_2c[0]);
          md = EVP_get_digestbyname(name);
          if (md == (EVP_MD *)0x0) {
            ERR_put_error(0x2e,0x66,0x80,"crypto/cms/cms_sd.c",0x127);
            goto LAB_0018ea78;
          }
        }
        X509_ALGOR_set_md(*(X509_ALGOR **)(pAVar2 + 8),md);
        for (iVar1 = 0; iVar3 = OPENSSL_sk_num(piVar10[1]), iVar1 < iVar3; iVar1 = iVar1 + 1) {
          pXVar6 = (X509_ALGOR *)OPENSSL_sk_value(piVar10[1],iVar1);
          X509_ALGOR_get0(local_2c,(int *)0x0,(void **)0x0,pXVar6);
          iVar3 = OBJ_obj2nid(local_2c[0]);
          iVar9 = EVP_MD_type(md);
          if (iVar3 == iVar9) break;
        }
        iVar3 = OPENSSL_sk_num(piVar10[1]);
        if (iVar1 == iVar3) {
          pXVar6 = X509_ALGOR_new();
          if (pXVar6 != (X509_ALGOR *)0x0) {
            X509_ALGOR_set_md(pXVar6,md);
            iVar1 = OPENSSL_sk_push(piVar10[1],pXVar6);
            if (iVar1 != 0) goto LAB_0018e9e4;
            X509_ALGOR_free(pXVar6);
          }
          goto LAB_0018eac8;
        }
LAB_0018e9e4:
        if ((flags & 0x40000) == 0) {
          iVar1 = *(int *)(*(int *)(pAVar2 + 0x20) + 0xc);
          if ((iVar1 != 0) && (pcVar8 = *(code **)(iVar1 + 0x5c), pcVar8 != (code *)0x0)) {
            iVar1 = (*pcVar8)(*(int *)(pAVar2 + 0x20),5,0,pAVar2);
            if (iVar1 == -2) {
              ERR_put_error(0x2e,0xaa,0x7d,"crypto/cms/cms_sd.c",0xe7);
              goto LAB_0018ea78;
            }
            if (iVar1 < 1) {
              ERR_put_error(0x2e,0xaa,0x6f,"crypto/cms/cms_sd.c",0xeb);
              goto LAB_0018ea78;
            }
          }
        }
        if ((flags & 0x100) == 0) {
          if (*(int *)(pAVar2 + 0xc) == 0) {
            iVar1 = OPENSSL_sk_new_null();
            *(int *)(pAVar2 + 0xc) = iVar1;
            if (iVar1 == 0) goto LAB_0018eac8;
          }
          if ((ASN1_OBJECT *)(flags & 0x200) != (ASN1_OBJECT *)0x0) {
LAB_0018ea0a:
            if ((int)(flags << 0x10) < 0) {
              psVar4 = CMS_get0_SignerInfos(cms);
              iVar1 = 0;
              do {
                iVar3 = OPENSSL_sk_num(psVar4);
                iVar9 = iVar1 + 1;
                if (iVar3 <= iVar1) {
                  ERR_put_error(0x2e,0x6c,0x83,"crypto/cms/cms_sd.c",0xa8);
                  goto LAB_0018ea78;
                }
                si = (CMS_SignerInfo *)OPENSSL_sk_value(psVar4,iVar1);
                iVar1 = iVar9;
              } while (((pAVar2 == (ASN1_VALUE *)si) ||
                       (iVar3 = CMS_signed_get_attr_count(si), iVar3 < 0)) ||
                      (iVar3 = OBJ_cmp((ASN1_OBJECT *)**(undefined4 **)(pAVar2 + 8),
                                       (ASN1_OBJECT *)**(undefined4 **)(si + 8)), iVar3 != 0));
              pAVar5 = OBJ_nid2obj(0x33);
              bytes = CMS_signed_get0_data_by_OBJ(si,pAVar5,-3,4);
              if (bytes == (void *)0x0) {
                ERR_put_error(0x2e,0x6c,0x72,"crypto/cms/cms_sd.c",0x9d);
                goto LAB_0018ea78;
              }
              iVar1 = CMS_signed_add1_attr_by_NID((CMS_SignerInfo *)pAVar2,0x33,4,bytes,-1);
              if (((iVar1 == 0) ||
                  (iVar1 = CMS_signed_add1_attr_by_NID
                                     ((CMS_SignerInfo *)pAVar2,0x32,6,
                                      (void *)**(undefined4 **)(*(int *)(cms + 4) + 8),-1),
                  iVar1 < 1)) ||
                 (((flags & 0x44000) == 0 &&
                  (iVar1 = CMS_SignerInfo_sign((CMS_SignerInfo *)pAVar2), iVar1 == 0))))
              goto LAB_0018ea78;
            }
            goto LAB_0018ea10;
          }
          local_2c[0] = (ASN1_OBJECT *)(flags & 0x200);
          iVar1 = CMS_add_standard_smimecap((stack_st_X509_ALGOR **)local_2c);
          if (iVar1 == 0) {
            OPENSSL_sk_pop_free(local_2c[0],(undefined *)0x106475);
          }
          else {
            iVar1 = CMS_add_smimecap((CMS_SignerInfo *)pAVar2,(stack_st_X509_ALGOR *)local_2c[0]);
            OPENSSL_sk_pop_free(local_2c[0],(undefined *)0x106475);
            if (iVar1 != 0) goto LAB_0018ea0a;
          }
        }
        else {
LAB_0018ea10:
          if (((int)(flags << 0x1e) < 0) || (iVar1 = CMS_add1_cert(cms,signer), iVar1 != 0)) {
            if ((flags & 0x40000) != 0) {
              if ((flags & 0x100) == 0) {
                iVar1 = EVP_DigestSignInit(*(EVP_MD_CTX **)(pAVar2 + 0x24),
                                           (EVP_PKEY_CTX **)(pAVar2 + 0x28),md,(ENGINE *)0x0,pk);
              }
              else {
                ctx = EVP_PKEY_CTX_new(*(EVP_PKEY **)(pAVar2 + 0x20),(ENGINE *)0x0);
                *(EVP_PKEY_CTX **)(pAVar2 + 0x28) = ctx;
                if ((ctx == (EVP_PKEY_CTX *)0x0) || (iVar1 = EVP_PKEY_sign_init(ctx), iVar1 < 1))
                goto LAB_0018ea78;
                iVar1 = EVP_PKEY_CTX_ctrl(*(EVP_PKEY_CTX **)(pAVar2 + 0x28),-1,0xf8,1,0,md);
              }
              if (iVar1 < 1) goto LAB_0018ea78;
            }
            iVar1 = piVar10[5];
            if (iVar1 == 0) {
              iVar1 = OPENSSL_sk_new_null();
              piVar10[5] = iVar1;
              if (iVar1 == 0) goto LAB_0018eac8;
            }
            iVar1 = OPENSSL_sk_push(iVar1,pAVar2);
            if (iVar1 != 0) {
              return (CMS_SignerInfo *)pAVar2;
            }
          }
        }
LAB_0018eac8:
        iVar1 = 0x184;
LAB_0018ead0:
        ERR_put_error(0x2e,0x66,0x41,"crypto/cms/cms_sd.c",iVar1);
        ASN1_item_free(pAVar2,(ASN1_ITEM *)CMS_SignerInfo_it);
        return (CMS_SignerInfo *)0x0;
      }
    }
    else {
      ERR_put_error(0x2e,0x85,0x6c,"crypto/cms/cms_sd.c",0x1a);
    }
  }
  pAVar2 = (ASN1_VALUE *)0x0;
LAB_0018ea78:
  ASN1_item_free(pAVar2,(ASN1_ITEM *)CMS_SignerInfo_it);
  return (CMS_SignerInfo *)0x0;
}


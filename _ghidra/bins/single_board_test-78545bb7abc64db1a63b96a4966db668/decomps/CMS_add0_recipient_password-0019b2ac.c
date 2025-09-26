
CMS_RecipientInfo *
CMS_add0_recipient_password
          (CMS_ContentInfo *cms,int iter,int wrap_nid,int pbe_nid,uchar *pass,ssize_t passlen,
          EVP_CIPHER *kekciph)

{
  int iVar1;
  EVP_CIPHER_CTX *a;
  EVP_CIPHER_CTX *pEVar2;
  int iVar3;
  ASN1_TYPE *pAVar4;
  EVP_CIPHER *pEVar5;
  ASN1_VALUE *ri;
  ASN1_VALUE *pAVar6;
  X509_ALGOR *pXVar7;
  ASN1_OBJECT *pAVar8;
  ASN1_STRING *pAVar9;
  undefined4 uVar10;
  int iVar11;
  uchar auStack_38 [20];
  
  iVar1 = cms_get0_enveloped(cms);
  if (iVar1 == 0) {
    return (CMS_RecipientInfo *)0x0;
  }
  if (wrap_nid < 1) {
    if ((kekciph == (EVP_CIPHER *)0x0) &&
       (kekciph = *(EVP_CIPHER **)(*(int *)(iVar1 + 0xc) + 0xc), kekciph == (EVP_CIPHER *)0x0))
    goto LAB_0019b44c;
  }
  else {
    if ((kekciph == (EVP_CIPHER *)0x0) &&
       (kekciph = *(EVP_CIPHER **)(*(int *)(iVar1 + 0xc) + 0xc), kekciph == (EVP_CIPHER *)0x0)) {
LAB_0019b44c:
      ERR_put_error(0x2e,0xa5,0x7e,"crypto/cms/cms_pwri.c",0x44);
      return (CMS_RecipientInfo *)0x0;
    }
    if (wrap_nid != 0x37d) {
      ERR_put_error(0x2e,0xa5,0xb3,"crypto/cms/cms_pwri.c",0x49);
      return (CMS_RecipientInfo *)0x0;
    }
  }
  a = (EVP_CIPHER_CTX *)X509_ALGOR_new();
  if (a == (EVP_CIPHER_CTX *)0x0) {
LAB_0019b4d0:
    ERR_put_error(0x2e,0xa5,0x41,"crypto/cms/cms_pwri.c",0xa1);
    EVP_CIPHER_CTX_free((EVP_CIPHER_CTX *)0x0);
    goto LAB_0019b47a;
  }
  pEVar2 = EVP_CIPHER_CTX_new();
  iVar3 = EVP_EncryptInit_ex(pEVar2,kekciph,(ENGINE *)0x0,(uchar *)0x0,(uchar *)0x0);
  if (iVar3 < 1) {
    iVar1 = 0x55;
LAB_0019b468:
    ERR_put_error(0x2e,0xa5,6,"crypto/cms/cms_pwri.c",iVar1);
  }
  else {
    iVar3 = EVP_CIPHER_CTX_iv_length(pEVar2);
    if (iVar3 < 1) {
LAB_0019b352:
      pEVar5 = EVP_CIPHER_CTX_cipher(pEVar2);
      iVar3 = EVP_CIPHER_type(pEVar5);
      pEVar5 = (EVP_CIPHER *)OBJ_nid2obj(iVar3);
      a->cipher = pEVar5;
      EVP_CIPHER_CTX_free(pEVar2);
      ri = ASN1_item_new((ASN1_ITEM *)CMS_RecipientInfo_it);
      if (ri == (ASN1_VALUE *)0x0) goto LAB_0019b4d0;
      pAVar6 = ASN1_item_new((ASN1_ITEM *)CMS_PasswordRecipientInfo_it);
      *(ASN1_VALUE **)(ri + 4) = pAVar6;
      if (pAVar6 == (ASN1_VALUE *)0x0) {
LAB_0019b48a:
        ERR_put_error(0x2e,0xa5,0x41,"crypto/cms/cms_pwri.c",0xa1);
        pEVar2 = (EVP_CIPHER_CTX *)0x0;
      }
      else {
        pXVar7 = *(X509_ALGOR **)(pAVar6 + 8);
        *(undefined4 *)ri = 3;
        X509_ALGOR_free(pXVar7);
        pXVar7 = X509_ALGOR_new();
        *(X509_ALGOR **)(pAVar6 + 8) = pXVar7;
        if (pXVar7 == (X509_ALGOR *)0x0) goto LAB_0019b48a;
        pAVar8 = OBJ_nid2obj(0x37d);
        pXVar7->algorithm = pAVar8;
        iVar11 = *(int *)(pAVar6 + 8);
        pAVar4 = ASN1_TYPE_new();
        iVar3 = *(int *)(pAVar6 + 8);
        *(ASN1_TYPE **)(iVar11 + 4) = pAVar4;
        if ((*(int *)(iVar3 + 4) == 0) ||
           (pAVar9 = ASN1_item_pack(a,(ASN1_ITEM *)X509_ALGOR_it,
                                    (ASN1_OCTET_STRING **)(*(int *)(iVar3 + 4) + 4)),
           pAVar9 == (ASN1_STRING *)0x0)) goto LAB_0019b48a;
        **(undefined4 **)(*(int *)(pAVar6 + 8) + 4) = 0x10;
        X509_ALGOR_free((X509_ALGOR *)a);
        pEVar2 = (EVP_CIPHER_CTX *)PKCS5_pbkdf2_set(iter,(uchar *)0x0,0,-1,-1);
        *(EVP_CIPHER_CTX **)(pAVar6 + 4) = pEVar2;
        a = pEVar2;
        if (pEVar2 != (EVP_CIPHER_CTX *)0x0) {
          CMS_RecipientInfo_set0_password((CMS_RecipientInfo *)ri,pass,passlen);
          uVar10 = *(undefined4 *)(iVar1 + 8);
          *(undefined4 *)pAVar6 = 0;
          iVar1 = OPENSSL_sk_push(uVar10,ri);
          if (iVar1 != 0) {
            return (CMS_RecipientInfo *)ri;
          }
          a = (EVP_CIPHER_CTX *)0x0;
          goto LAB_0019b48a;
        }
      }
      EVP_CIPHER_CTX_free(pEVar2);
      ASN1_item_free(ri,(ASN1_ITEM *)CMS_RecipientInfo_it);
      goto LAB_0019b47a;
    }
    iVar3 = RAND_bytes(auStack_38,iVar3);
    if (0 < iVar3) {
      iVar3 = EVP_EncryptInit_ex(pEVar2,(EVP_CIPHER *)0x0,(ENGINE *)0x0,(uchar *)0x0,auStack_38);
      if (iVar3 < 1) {
        iVar1 = 0x5f;
        goto LAB_0019b468;
      }
      pAVar4 = ASN1_TYPE_new();
      a->engine = (ENGINE *)pAVar4;
      if (pAVar4 == (ASN1_TYPE *)0x0) {
        ERR_put_error(0x2e,0xa5,0x41,"crypto/cms/cms_pwri.c",100);
      }
      else {
        iVar3 = EVP_CIPHER_param_to_asn1(pEVar2,pAVar4);
        if (0 < iVar3) goto LAB_0019b352;
        ERR_put_error(0x2e,0xa5,0x66,"crypto/cms/cms_pwri.c",0x69);
      }
    }
  }
  EVP_CIPHER_CTX_free(pEVar2);
LAB_0019b47a:
  X509_ALGOR_free((X509_ALGOR *)a);
  return (CMS_RecipientInfo *)0x0;
}


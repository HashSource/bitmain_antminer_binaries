
CMS_RecipientInfo *
CMS_add0_recipient_password
          (CMS_ContentInfo *cms,int iter,int wrap_nid,int pbe_nid,uchar *pass,ssize_t passlen,
          EVP_CIPHER *kekciph)

{
  int iVar1;
  X509_ALGOR *a;
  int iVar2;
  ASN1_TYPE *pAVar3;
  EVP_CIPHER *ctx;
  ASN1_OBJECT *pAVar4;
  int *val;
  undefined4 *puVar5;
  X509_ALGOR *pXVar6;
  ASN1_STRING *pAVar7;
  _STACK *st;
  uchar *puVar8;
  int iVar9;
  uchar auStack_bc [16];
  EVP_CIPHER_CTX EStack_ac;
  
  iVar1 = cms_get0_enveloped();
  if (iVar1 == 0) {
    return (CMS_RecipientInfo *)0x0;
  }
  if (wrap_nid < 1) {
    wrap_nid = 0x37d;
  }
  if ((kekciph == (EVP_CIPHER *)0x0) &&
     (kekciph = *(EVP_CIPHER **)(*(int *)(iVar1 + 0xc) + 0xc), kekciph == (EVP_CIPHER *)0x0)) {
    ERR_put_error(0x2e,0xa5,0x7e,DAT_000d666c,0x71);
    return (CMS_RecipientInfo *)0x0;
  }
  if (wrap_nid != 0x37d) {
    ERR_put_error(0x2e,0xa5,0xb3,DAT_000d666c,0x76);
    return (CMS_RecipientInfo *)0x0;
  }
  a = X509_ALGOR_new();
  EVP_CIPHER_CTX_init(&EStack_ac);
  iVar2 = EVP_EncryptInit_ex(&EStack_ac,kekciph,(ENGINE *)0x0,(uchar *)0x0,(uchar *)0x0);
  if (iVar2 < 1) {
    iVar1 = 0x7f;
LAB_000d65da:
    ERR_put_error(0x2e,0xa5,6,DAT_000d666c,iVar1);
    EVP_CIPHER_CTX_cleanup(&EStack_ac);
  }
  else {
    iVar2 = EVP_CIPHER_CTX_iv_length(&EStack_ac);
    if (iVar2 < 1) {
LAB_000d64be:
      ctx = EVP_CIPHER_CTX_cipher(&EStack_ac);
      iVar2 = EVP_CIPHER_type(ctx);
      pAVar4 = OBJ_nid2obj(iVar2);
      a->algorithm = pAVar4;
      EVP_CIPHER_CTX_cleanup(&EStack_ac);
      val = (int *)ASN1_item_new(DAT_000d6660);
      if (val == (int *)0x0) {
        ERR_put_error(0x2e,0xa5,0x41,DAT_000d666c,0xca);
        EVP_CIPHER_CTX_cleanup(&EStack_ac);
        goto LAB_000d65aa;
      }
      puVar5 = (undefined4 *)ASN1_item_new(DAT_000d6664);
      val[1] = (int)puVar5;
      if (puVar5 == (undefined4 *)0x0) {
LAB_000d658a:
        ERR_put_error(0x2e,0xa5,0x41,DAT_000d666c,0xca);
      }
      else {
        pXVar6 = (X509_ALGOR *)puVar5[2];
        *val = 3;
        X509_ALGOR_free(pXVar6);
        pXVar6 = X509_ALGOR_new();
        puVar5[2] = pXVar6;
        if (pXVar6 == (X509_ALGOR *)0x0) goto LAB_000d658a;
        pAVar4 = OBJ_nid2obj(0x37d);
        pXVar6->algorithm = pAVar4;
        iVar9 = puVar5[2];
        pAVar3 = ASN1_TYPE_new();
        iVar2 = puVar5[2];
        *(ASN1_TYPE **)(iVar9 + 4) = pAVar3;
        if ((*(int *)(iVar2 + 4) == 0) ||
           (pAVar7 = ASN1_item_pack(a,DAT_000d6668,(ASN1_OCTET_STRING **)(*(int *)(iVar2 + 4) + 4)),
           pAVar7 == (ASN1_STRING *)0x0)) goto LAB_000d658a;
        **(undefined4 **)(puVar5[2] + 4) = 0x10;
        X509_ALGOR_free(a);
        a = PKCS5_pbkdf2_set(iter,(uchar *)0x0,0,-1,-1);
        puVar5[1] = a;
        if (a != (X509_ALGOR *)0x0) {
          if (*val == 3) {
            iVar2 = val[1];
            *(uchar **)(iVar2 + 0x10) = pass;
            puVar8 = pass;
            if (pass != (uchar *)0x0) {
              puVar8 = (uchar *)0x1;
            }
            if (((uint)puVar8 & (uint)passlen >> 0x1f) != 0) {
              passlen = strlen((char *)pass);
            }
            *(ssize_t *)(iVar2 + 0x14) = passlen;
          }
          else {
            ERR_put_error(0x2e,0xa8,0xb1,DAT_000d666c,0x47);
          }
          st = *(_STACK **)(iVar1 + 8);
          *puVar5 = 0;
          iVar1 = sk_push(st,val);
          if (iVar1 != 0) {
            return (CMS_RecipientInfo *)val;
          }
          a = (X509_ALGOR *)0x0;
          goto LAB_000d658a;
        }
      }
      EVP_CIPHER_CTX_cleanup(&EStack_ac);
      ASN1_item_free((ASN1_VALUE *)val,DAT_000d6660);
    }
    else {
      iVar2 = RAND_pseudo_bytes(auStack_bc,iVar2);
      if (0 < iVar2) {
        iVar2 = EVP_EncryptInit_ex(&EStack_ac,(EVP_CIPHER *)0x0,(ENGINE *)0x0,(uchar *)0x0,
                                   auStack_bc);
        if (iVar2 < 1) {
          iVar1 = 0x89;
          goto LAB_000d65da;
        }
        pAVar3 = ASN1_TYPE_new();
        a->parameter = pAVar3;
        if (pAVar3 == (ASN1_TYPE *)0x0) {
          ERR_put_error(0x2e,0xa5,0x41,DAT_000d666c,0x8e);
        }
        else {
          iVar2 = EVP_CIPHER_param_to_asn1(&EStack_ac,pAVar3);
          if (0 < iVar2) goto LAB_000d64be;
          ERR_put_error(0x2e,0xa5,0x66,DAT_000d666c,0x93);
        }
      }
      EVP_CIPHER_CTX_cleanup(&EStack_ac);
    }
  }
  if (a == (X509_ALGOR *)0x0) {
    return (CMS_RecipientInfo *)0x0;
  }
LAB_000d65aa:
  X509_ALGOR_free(a);
  return (CMS_RecipientInfo *)0x0;
}


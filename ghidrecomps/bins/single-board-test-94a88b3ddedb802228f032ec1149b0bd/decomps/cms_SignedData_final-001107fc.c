
undefined4 cms_SignedData_final(ASN1_OBJECT **param_1,undefined4 param_2)

{
  bool bVar1;
  int iVar2;
  CMS_SignerInfo *si;
  uchar *puVar3;
  int iVar4;
  ASN1_OBJECT *pAVar5;
  code *pcVar6;
  void *bytes;
  EVP_PKEY_CTX *ctx;
  size_t local_88;
  size_t local_84;
  EVP_MD_CTX EStack_80;
  uchar auStack_68 [68];
  
  iVar2 = OBJ_obj2nid(*param_1);
  if (iVar2 == 0x16) {
    pAVar5 = param_1[1];
    if (pAVar5 != (ASN1_OBJECT *)0x0) {
      pAVar5 = (ASN1_OBJECT *)pAVar5->flags;
    }
  }
  else {
    ERR_put_error(0x2e,0x85,0x6c,DAT_00110a20,0x48);
    pAVar5 = (ASN1_OBJECT *)0x0;
  }
  iVar4 = 0;
  iVar2 = sk_num((_STACK *)pAVar5);
  if (0 < iVar2) {
    do {
      si = (CMS_SignerInfo *)sk_value((_STACK *)pAVar5,iVar4);
      EVP_MD_CTX_init(&EStack_80);
      if (*(int *)(si + 0x20) == 0) {
        ERR_put_error(0x2e,0x96,0x85,DAT_00110a20,0x249);
        return 0;
      }
      iVar2 = cms_DigestAlgorithm_find_ctx(&EStack_80,param_2,*(undefined4 *)(si + 8));
      if (iVar2 == 0) {
        bVar1 = false;
LAB_0011088e:
        EVP_MD_CTX_cleanup(&EStack_80);
      }
      else {
        if (*(int *)(si + 0x3c) != 0) {
          iVar2 = *(int *)(*(int *)(si + 0x20) + 0xc);
          if ((iVar2 == 0) || (pcVar6 = *(code **)(iVar2 + 0x58), pcVar6 == (code *)0x0))
          goto LAB_0011086a;
          iVar2 = (*pcVar6)(*(int *)(si + 0x20),5,0,si);
          if (iVar2 == -2) {
            ERR_put_error(0x2e,0xaa,0x7d,DAT_00110a20,0x100);
          }
          else {
            if (0 < iVar2) goto LAB_0011086a;
            ERR_put_error(0x2e,0xaa,0x6f,DAT_00110a20,0x104);
          }
LAB_0011088c:
          bVar1 = false;
          goto LAB_0011088e;
        }
LAB_0011086a:
        iVar2 = CMS_signed_get_attr_count(si);
        if (-1 < iVar2) {
          bytes = *(void **)param_1[1]->nid;
          iVar2 = EVP_DigestFinal_ex(&EStack_80,auStack_68,&local_84);
          if (((iVar2 != 0) &&
              (iVar2 = CMS_signed_add1_attr_by_NID(si,0x33,4,auStack_68,local_84), iVar2 != 0)) &&
             (iVar2 = CMS_signed_add1_attr_by_NID(si,0x32,6,bytes,-1), 0 < iVar2)) {
            bVar1 = true;
            iVar2 = CMS_SignerInfo_sign(si);
            if (iVar2 != 0) goto LAB_0011088e;
          }
          goto LAB_0011088c;
        }
        ctx = *(EVP_PKEY_CTX **)(si + 0x3c);
        if (ctx == (EVP_PKEY_CTX *)0x0) {
          iVar2 = EVP_PKEY_size(*(EVP_PKEY **)(si + 0x20));
          puVar3 = (uchar *)CRYPTO_malloc(iVar2,DAT_00110a20,0x27b);
          if (puVar3 == (uchar *)0x0) {
            ERR_put_error(0x2e,0x96,0x41,DAT_00110a20,0x27d);
          }
          else {
            iVar2 = EVP_SignFinal(&EStack_80,puVar3,&local_84,*(EVP_PKEY **)(si + 0x20));
            if (iVar2 != 0) {
              bVar1 = true;
              ASN1_STRING_set0(*(ASN1_STRING **)(si + 0x14),puVar3,local_84);
              goto LAB_0011088e;
            }
            ERR_put_error(0x2e,0x96,0x8b,DAT_00110a20,0x281);
            CRYPTO_free(puVar3);
          }
          goto LAB_0011088c;
        }
        iVar2 = EVP_DigestFinal_ex(&EStack_80,auStack_68,&local_84);
        if (iVar2 == 0) {
LAB_001108d0:
          bVar1 = false;
        }
        else {
          local_88 = EVP_PKEY_size(*(EVP_PKEY **)(si + 0x20));
          puVar3 = (uchar *)CRYPTO_malloc(local_88,DAT_00110a20,0x270);
          if (puVar3 == (uchar *)0x0) {
            ERR_put_error(0x2e,0x96,0x41,DAT_00110a20,0x272);
            goto LAB_001108d0;
          }
          iVar2 = EVP_PKEY_sign(ctx,puVar3,&local_88,auStack_68,local_84);
          if (iVar2 < 1) goto LAB_001108d0;
          bVar1 = true;
          ASN1_STRING_set0(*(ASN1_STRING **)(si + 0x14),puVar3,local_88);
        }
        EVP_MD_CTX_cleanup(&EStack_80);
        EVP_PKEY_CTX_free(ctx);
      }
      if (!bVar1) {
        return 0;
      }
      iVar4 = iVar4 + 1;
      iVar2 = sk_num((_STACK *)pAVar5);
    } while (iVar4 < iVar2);
  }
  *(undefined4 *)(param_1[1]->nid + 8) = 0;
  return 1;
}


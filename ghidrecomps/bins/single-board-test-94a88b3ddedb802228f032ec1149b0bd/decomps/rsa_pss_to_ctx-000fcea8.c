
undefined4
rsa_pss_to_ctx(EVP_MD_CTX *param_1,EVP_PKEY_CTX *param_2,ASN1_OBJECT **param_3,EVP_PKEY *param_4)

{
  int iVar1;
  RSA_PSS_PARAMS *a;
  char *pcVar2;
  EVP_MD *p2;
  EVP_MD *md;
  long lVar3;
  int iVar4;
  int iVar5;
  ASN1_OBJECT *pAVar6;
  ASN1_STRING *pAVar7;
  X509_ALGOR *pXVar8;
  undefined4 uVar9;
  X509_ALGOR *a_00;
  EVP_PKEY_CTX *local_2c;
  uchar *local_28;
  EVP_MD *local_24;
  
  local_2c = param_2;
  iVar1 = OBJ_obj2nid(*param_3);
  if (iVar1 != 0x390) {
    ERR_put_error(4,0xa2,0x9b,DAT_000fd130,0x253);
    return 0xffffffff;
  }
  pAVar6 = param_3[1];
  if ((pAVar6 == (ASN1_OBJECT *)0x0) || (pAVar6->sn != (char *)0x10)) {
LAB_000fd028:
    ERR_put_error(4,0xa2,0x95,DAT_000fd130,0x25a);
    RSA_PSS_PARAMS_free((RSA_PSS_PARAMS *)0x0);
    return 0xffffffff;
  }
  local_28 = (uchar *)pAVar6->ln[2];
  a = d2i_RSA_PSS_PARAMS((RSA_PSS_PARAMS **)0x0,&local_28,(long)*pAVar6->ln);
  if (a == (RSA_PSS_PARAMS *)0x0) goto LAB_000fd028;
  a_00 = a->maskGenAlgorithm;
  if (a_00 == (X509_ALGOR *)0x0) {
LAB_000fd06a:
    p2 = EVP_sha1();
    if (p2 != (EVP_MD *)0x0) {
LAB_000fcf58:
      if (a->hashAlgorithm == (X509_ALGOR *)0x0) {
        md = EVP_sha1();
        if (md == (EVP_MD *)0x0) goto LAB_000fcfa6;
      }
      else {
        iVar1 = OBJ_obj2nid(a->hashAlgorithm->algorithm);
        pcVar2 = OBJ_nid2sn(iVar1);
        md = EVP_get_digestbyname(pcVar2);
        if (md == (EVP_MD *)0x0) {
          ERR_put_error(4,0x9d,0xa3,DAT_000fd130,499);
          uVar9 = 0xffffffff;
          goto LAB_000fcfaa;
        }
      }
      if (a->saltLength == (ASN1_INTEGER *)0x0) {
        iVar1 = 0x14;
      }
      else {
        iVar1 = ASN1_INTEGER_get(a->saltLength);
        if (iVar1 < 0) {
          ERR_put_error(4,0xa2,0x96,DAT_000fd130,0x26c);
          uVar9 = 0xffffffff;
          goto LAB_000fcfaa;
        }
      }
      if ((a->trailerField == (ASN1_INTEGER *)0x0) ||
         (lVar3 = ASN1_INTEGER_get(a->trailerField), lVar3 == 1)) {
        if (param_4 == (EVP_PKEY *)0x0) {
          iVar4 = EVP_PKEY_CTX_ctrl(local_2c,-1,0xf8,0xd,0,&local_24);
          if (0 < iVar4) {
            iVar4 = EVP_MD_type(md);
            iVar5 = EVP_MD_type(local_24);
            if (iVar4 == iVar5) goto LAB_000fcfd6;
            ERR_put_error(4,0xa2,0xa6,DAT_000fd130,0x285);
          }
        }
        else {
          iVar4 = EVP_DigestVerifyInit(param_1,&local_2c,md,(ENGINE *)0x0,param_4);
          if (iVar4 != 0) {
LAB_000fcfd6:
            iVar4 = EVP_PKEY_CTX_ctrl(local_2c,6,-1,0x1001,6,(void *)0x0);
            if (((0 < iVar4) &&
                (iVar1 = EVP_PKEY_CTX_ctrl(local_2c,6,0x18,0x1002,iVar1,(void *)0x0), 0 < iVar1)) &&
               (iVar1 = EVP_PKEY_CTX_ctrl(local_2c,6,0x3f8,0x1005,0,p2), 0 < iVar1)) {
              uVar9 = 1;
              goto LAB_000fcfaa;
            }
          }
        }
      }
      else {
        ERR_put_error(4,0xa2,0x8b,DAT_000fd130,0x277);
      }
    }
  }
  else {
    iVar1 = OBJ_obj2nid(a_00->algorithm);
    if ((iVar1 == 0x38f) && (a_00->parameter->type == 0x10)) {
      pAVar7 = (a_00->parameter->value).asn1_string;
      local_24 = (EVP_MD *)pAVar7->data;
      a_00 = d2i_X509_ALGOR((X509_ALGOR **)0x0,(uchar **)&local_24,pAVar7->length);
      pXVar8 = a->maskGenAlgorithm;
    }
    else {
      pXVar8 = a->maskGenAlgorithm;
      a_00 = (X509_ALGOR *)0x0;
    }
    if (pXVar8 == (X509_ALGOR *)0x0) goto LAB_000fd06a;
    iVar1 = OBJ_obj2nid(pXVar8->algorithm);
    if (iVar1 == 0x38f) {
      if (a_00 == (X509_ALGOR *)0x0) {
        ERR_put_error(4,0x9f,0x9a,DAT_000fd130,0x203);
        goto LAB_000fcfa6;
      }
      iVar1 = OBJ_obj2nid(a_00->algorithm);
      pcVar2 = OBJ_nid2sn(iVar1);
      p2 = EVP_get_digestbyname(pcVar2);
      if (p2 == (EVP_MD *)0x0) {
        ERR_put_error(4,0x9f,0x97,DAT_000fd130,0x208);
        goto LAB_000fcfa6;
      }
      goto LAB_000fcf58;
    }
    ERR_put_error(4,0x9f,0x99,DAT_000fd130,0x1ff);
  }
LAB_000fcfa6:
  uVar9 = 0xffffffff;
LAB_000fcfaa:
  RSA_PSS_PARAMS_free(a);
  if (a_00 == (X509_ALGOR *)0x0) {
    return uVar9;
  }
  X509_ALGOR_free(a_00);
  return uVar9;
}


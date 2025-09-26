
X509_ALGOR *
PKCS5_pbe2_set_iv(EVP_CIPHER *cipher,int iter,uchar *salt,int saltlen,uchar *aiv,int prf_nid)

{
  int iVar1;
  PBE2PARAM *a;
  ASN1_OBJECT *pAVar2;
  ASN1_TYPE *pAVar3;
  int iVar4;
  size_t __n;
  EVP_CIPHER_CTX *ctx;
  X509_ALGOR *pXVar5;
  X509_ALGOR *pXVar6;
  uchar auStack_38 [20];
  
  iVar1 = EVP_CIPHER_type(cipher);
  if (iVar1 == 0) {
    ERR_put_error(0xd,0xa7,0x6c,"crypto/asn1/p5_pbev2.c",0x35);
    a = (PBE2PARAM *)0x0;
    ctx = (EVP_CIPHER_CTX *)0x0;
    pXVar5 = (X509_ALGOR *)0x0;
    goto LAB_001d4fe2;
  }
  a = PBE2PARAM_new();
  if (a == (PBE2PARAM *)0x0) {
LAB_001d4fca:
    pXVar5 = (X509_ALGOR *)0x0;
  }
  else {
    pXVar6 = a->encryption;
    pAVar2 = OBJ_nid2obj(iVar1);
    pXVar6->algorithm = pAVar2;
    pAVar3 = ASN1_TYPE_new();
    pXVar6->parameter = pAVar3;
    if (pAVar3 == (ASN1_TYPE *)0x0) goto LAB_001d4fca;
    iVar4 = EVP_CIPHER_iv_length(cipher);
    if (iVar4 != 0) {
      if (aiv == (uchar *)0x0) {
        iVar4 = EVP_CIPHER_iv_length(cipher);
        iVar4 = RAND_bytes(auStack_38,iVar4);
        if (iVar4 < 1) {
          ctx = (EVP_CIPHER_CTX *)0x0;
          pXVar5 = (X509_ALGOR *)0x0;
          goto LAB_001d4fe2;
        }
      }
      else {
        __n = EVP_CIPHER_iv_length(cipher);
        memcpy(auStack_38,aiv,__n);
      }
    }
    ctx = EVP_CIPHER_CTX_new();
    if (ctx == (EVP_CIPHER_CTX *)0x0) goto LAB_001d4fca;
    pXVar5 = (X509_ALGOR *)0x0;
    iVar4 = EVP_CipherInit_ex(ctx,cipher,(ENGINE *)0x0,(uchar *)0x0,auStack_38,0);
    if (iVar4 == 0) {
      pXVar5 = (X509_ALGOR *)0x0;
      goto LAB_001d4fe2;
    }
    iVar4 = EVP_CIPHER_param_to_asn1(ctx,pXVar6->parameter);
    if (iVar4 < 1) {
      ERR_put_error(0xd,0xa7,0x72,"crypto/asn1/p5_pbev2.c",0x52);
      goto LAB_001d4fe2;
    }
    if ((prf_nid == -1) && (iVar4 = EVP_CIPHER_CTX_ctrl(ctx,7,0,&prf_nid), iVar4 < 1)) {
      ERR_clear_error();
      prf_nid = 799;
    }
    EVP_CIPHER_CTX_free(ctx);
    if (iVar1 == 0x25) {
      iVar1 = EVP_CIPHER_key_length(cipher);
    }
    else {
      iVar1 = -1;
    }
    X509_ALGOR_free(a->keyfunc);
    pXVar5 = PKCS5_pbkdf2_set(iter,salt,saltlen,prf_nid,iVar1);
    a->keyfunc = pXVar5;
    if ((pXVar5 == (X509_ALGOR *)0x0) || (pXVar5 = X509_ALGOR_new(), pXVar5 == (X509_ALGOR *)0x0))
    goto LAB_001d4fca;
    pAVar2 = OBJ_nid2obj(0xa1);
    pXVar5->algorithm = pAVar2;
    iVar1 = ASN1_TYPE_pack_sequence(PBE2PARAM_it,a,&pXVar5->parameter);
    if (iVar1 != 0) {
      PBE2PARAM_free(a);
      return pXVar5;
    }
  }
  ctx = (EVP_CIPHER_CTX *)0x0;
  ERR_put_error(0xd,0xa7,0x41,"crypto/asn1/p5_pbev2.c",0x84);
LAB_001d4fe2:
  EVP_CIPHER_CTX_free(ctx);
  PBE2PARAM_free(a);
  X509_ALGOR_free(pXVar5);
  return (X509_ALGOR *)0x0;
}


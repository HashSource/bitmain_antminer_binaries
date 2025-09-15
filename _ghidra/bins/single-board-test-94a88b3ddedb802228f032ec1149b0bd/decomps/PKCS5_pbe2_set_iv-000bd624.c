
X509_ALGOR *
PKCS5_pbe2_set_iv(EVP_CIPHER *cipher,int iter,uchar *salt,int saltlen,uchar *aiv,int prf_nid)

{
  int iVar1;
  ASN1_OBJECT *pAVar2;
  ASN1_VALUE *val;
  ASN1_TYPE *pAVar3;
  int iVar4;
  size_t __n;
  ASN1_STRING *pAVar5;
  undefined4 *puVar6;
  X509_ALGOR *pXVar7;
  uchar auStack_c4 [16];
  EVP_CIPHER_CTX EStack_b4;
  
  iVar1 = EVP_CIPHER_type(cipher);
  if (iVar1 == 0) {
    ERR_put_error(0xd,0xa7,0x6c,"p5_pbev2.c",0x68);
    val = (ASN1_VALUE *)0x0;
    pXVar7 = (X509_ALGOR *)0x0;
    goto LAB_000bd722;
  }
  pAVar2 = OBJ_nid2obj(iVar1);
  val = ASN1_item_new((ASN1_ITEM *)&PBE2PARAM_it);
  if (val == (ASN1_VALUE *)0x0) {
LAB_000bd73a:
    pXVar7 = (X509_ALGOR *)0x0;
  }
  else {
    puVar6 = *(undefined4 **)(val + 4);
    *puVar6 = pAVar2;
    pAVar3 = ASN1_TYPE_new();
    puVar6[1] = pAVar3;
    if (pAVar3 == (ASN1_TYPE *)0x0) goto LAB_000bd73a;
    iVar4 = EVP_CIPHER_iv_length(cipher);
    if (iVar4 != 0) {
      if (aiv == (uchar *)0x0) {
        iVar4 = EVP_CIPHER_iv_length(cipher);
        iVar4 = RAND_pseudo_bytes(auStack_c4,iVar4);
        if (iVar4 < 0) {
          pXVar7 = (X509_ALGOR *)0x0;
          goto LAB_000bd722;
        }
      }
      else {
        __n = EVP_CIPHER_iv_length(cipher);
        memcpy(auStack_c4,aiv,__n);
      }
    }
    pXVar7 = (X509_ALGOR *)0x0;
    EVP_CIPHER_CTX_init(&EStack_b4);
    iVar4 = EVP_CipherInit_ex(&EStack_b4,cipher,(ENGINE *)0x0,(uchar *)0x0,auStack_c4,0);
    if (iVar4 == 0) {
      pXVar7 = (X509_ALGOR *)0x0;
      goto LAB_000bd722;
    }
    iVar4 = EVP_CIPHER_param_to_asn1(&EStack_b4,(ASN1_TYPE *)puVar6[1]);
    if (iVar4 < 0) {
      ERR_put_error(0xd,0xa7,0x72,"p5_pbev2.c",0x85);
      EVP_CIPHER_CTX_cleanup(&EStack_b4);
      goto LAB_000bd722;
    }
    if ((prf_nid == -1) && (iVar4 = EVP_CIPHER_CTX_ctrl(&EStack_b4,7,0,&prf_nid), iVar4 < 1)) {
      ERR_clear_error();
      prf_nid = 0xa3;
    }
    EVP_CIPHER_CTX_cleanup(&EStack_b4);
    if (iVar1 == 0x25) {
      iVar1 = EVP_CIPHER_key_length(cipher);
    }
    else {
      iVar1 = -1;
    }
    X509_ALGOR_free(*(X509_ALGOR **)val);
    pXVar7 = PKCS5_pbkdf2_set(iter,salt,saltlen,prf_nid,iVar1);
    *(X509_ALGOR **)val = pXVar7;
    if ((pXVar7 == (X509_ALGOR *)0x0) || (pXVar7 = X509_ALGOR_new(), pXVar7 == (X509_ALGOR *)0x0))
    goto LAB_000bd73a;
    pAVar3 = ASN1_TYPE_new();
    pXVar7->parameter = pAVar3;
    if (pAVar3 != (ASN1_TYPE *)0x0) {
      pAVar2 = OBJ_nid2obj(0xa1);
      pXVar7->algorithm = pAVar2;
      pAVar5 = ASN1_item_pack(val,(ASN1_ITEM *)&PBE2PARAM_it,
                              &(pXVar7->parameter->value).octet_string);
      if (pAVar5 != (ASN1_STRING *)0x0) {
        pXVar7->parameter->type = 0x10;
        ASN1_item_free(val,(ASN1_ITEM *)&PBE2PARAM_it);
        return pXVar7;
      }
    }
  }
  ERR_put_error(0xd,0xa7,0x41,"p5_pbev2.c",0xba);
LAB_000bd722:
  ASN1_item_free(val,(ASN1_ITEM *)&PBE2PARAM_it);
  X509_ALGOR_free((X509_ALGOR *)0x0);
  X509_ALGOR_free(pXVar7);
  return (X509_ALGOR *)0x0;
}


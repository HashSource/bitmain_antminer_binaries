
X509_ALGOR * PKCS5_pbkdf2_set(int iter,uchar *salt,int saltlen,int prf_nid,int keylen)

{
  PBKDF2PARAM *a;
  ASN1_OCTET_STRING *pAVar1;
  uchar *buf;
  int iVar2;
  ASN1_INTEGER *a_00;
  X509_ALGOR *pXVar3;
  ASN1_OBJECT *pAVar4;
  ASN1_TYPE *pAVar5;
  bool bVar6;
  
  a = PBKDF2PARAM_new();
  if ((a != (PBKDF2PARAM *)0x0) &&
     (pAVar1 = ASN1_OCTET_STRING_new(), pAVar1 != (ASN1_OCTET_STRING *)0x0)) {
    pAVar5 = a->salt;
    pAVar5->type = 4;
    (pAVar5->value).octet_string = pAVar1;
    if (saltlen == 0) {
      saltlen = 8;
    }
    buf = (uchar *)CRYPTO_malloc(saltlen,"crypto/asn1/p5_pbev2.c",0xa6);
    pAVar1->data = buf;
    if (buf != (uchar *)0x0) {
      pAVar1->length = saltlen;
      if (salt == (uchar *)0x0) {
        iVar2 = RAND_bytes(buf,saltlen);
        if (iVar2 < 1) goto LAB_001cb2c6;
      }
      else {
        memcpy(buf,salt,saltlen);
      }
      if (iter < 1) {
        iter = 0x800;
      }
      iVar2 = ASN1_INTEGER_set(a->iter,iter);
      if (iVar2 != 0) {
        if (0 < keylen) {
          a_00 = ASN1_INTEGER_new();
          a->keylength = a_00;
          if ((a_00 == (ASN1_INTEGER *)0x0) || (iVar2 = ASN1_INTEGER_set(a_00,keylen), iVar2 == 0))
          goto LAB_001cb2c6;
        }
        bVar6 = prf_nid == 0xa3;
        iVar2 = prf_nid + -0xa3;
        if (!bVar6) {
          iVar2 = prf_nid;
        }
        if ((!bVar6 && prf_nid != 0) && iVar2 < 0 == (bVar6 && SBORROW4(prf_nid,0xa3))) {
          pXVar3 = X509_ALGOR_new();
          a->prf = pXVar3;
          if (pXVar3 == (X509_ALGOR *)0x0) goto LAB_001cb2c6;
          pAVar4 = OBJ_nid2obj(prf_nid);
          X509_ALGOR_set0(pXVar3,pAVar4,5,(void *)0x0);
        }
        pXVar3 = X509_ALGOR_new();
        if (pXVar3 != (X509_ALGOR *)0x0) {
          pAVar4 = OBJ_nid2obj(0x45);
          pXVar3->algorithm = pAVar4;
          iVar2 = ASN1_TYPE_pack_sequence(&PBKDF2PARAM_it,a,&pXVar3->parameter);
          if (iVar2 != 0) {
            PBKDF2PARAM_free(a);
            return pXVar3;
          }
          goto LAB_001cb2c8;
        }
      }
    }
  }
LAB_001cb2c6:
  pXVar3 = (X509_ALGOR *)0x0;
LAB_001cb2c8:
  ERR_put_error(0xd,0xdb,0x41,"crypto/asn1/p5_pbev2.c",0xd9);
  PBKDF2PARAM_free(a);
  X509_ALGOR_free(pXVar3);
  return (X509_ALGOR *)0x0;
}


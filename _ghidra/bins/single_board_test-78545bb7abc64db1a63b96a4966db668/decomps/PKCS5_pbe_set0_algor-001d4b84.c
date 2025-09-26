
int PKCS5_pbe_set0_algor(X509_ALGOR *algor,int alg,int iter,uchar *salt,int saltlen)

{
  PBEPARAM *a;
  int iVar1;
  uchar *buf;
  ASN1_STRING *pAVar2;
  ASN1_OBJECT *aobj;
  ASN1_OCTET_STRING *local_2c [2];
  
  local_2c[0] = (ASN1_STRING *)0x0;
  a = PBEPARAM_new();
  if (a == (PBEPARAM *)0x0) {
    ERR_put_error(0xd,0xd7,0x41,"crypto/asn1/p5_pbe.c",0x24);
    buf = (uchar *)0x0;
  }
  else {
    if (iter < 1) {
      iter = 0x800;
    }
    iVar1 = ASN1_INTEGER_set(a->iter,iter);
    if (iVar1 == 0) {
      iVar1 = 0x2a;
      buf = (uchar *)0x0;
    }
    else {
      if (saltlen == 0) {
        saltlen = 8;
      }
      buf = (uchar *)CRYPTO_malloc(saltlen,"crypto/asn1/p5_pbe.c",0x30);
      if (buf == (uchar *)0x0) {
        iVar1 = 0x32;
      }
      else {
        if (salt == (uchar *)0x0) {
          iVar1 = RAND_bytes(buf,saltlen);
          if (iVar1 < 1) goto LAB_001d4c1e;
        }
        else {
          memcpy(buf,salt,saltlen);
        }
        ASN1_STRING_set0(a->salt,buf,saltlen);
        pAVar2 = ASN1_item_pack(a,(ASN1_ITEM *)&PBEPARAM_it,local_2c);
        if (pAVar2 != (ASN1_STRING *)0x0) {
          PBEPARAM_free(a);
          aobj = OBJ_nid2obj(alg);
          iVar1 = X509_ALGOR_set0(algor,aobj,0x10,local_2c[0]);
          if (iVar1 != 0) {
            return 1;
          }
          buf = (uchar *)0x0;
          a = (PBEPARAM *)0x0;
          goto LAB_001d4c1e;
        }
        iVar1 = 0x3e;
        buf = (uchar *)0x0;
      }
    }
    ERR_put_error(0xd,0xd7,0x41,"crypto/asn1/p5_pbe.c",iVar1);
  }
LAB_001d4c1e:
  CRYPTO_free(buf);
  PBEPARAM_free(a);
  ASN1_STRING_free(local_2c[0]);
  return 0;
}


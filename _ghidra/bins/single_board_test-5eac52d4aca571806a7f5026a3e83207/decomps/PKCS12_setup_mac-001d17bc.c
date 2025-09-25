
int PKCS12_setup_mac(PKCS12 *p12,int iter,uchar *salt,int saltlen,EVP_MD *md_type)

{
  PKCS12_MAC_DATA *pPVar1;
  ASN1_INTEGER *pAVar2;
  int iVar3;
  uchar *puVar4;
  ASN1_OBJECT *aobj;
  ASN1_OCTET_STRING *pAVar5;
  X509_ALGOR *local_24;
  
  PKCS12_MAC_DATA_free(p12->mac);
  p12->mac = (PKCS12_MAC_DATA *)0x0;
  pPVar1 = PKCS12_MAC_DATA_new();
  p12->mac = pPVar1;
  if (pPVar1 == (PKCS12_MAC_DATA *)0x0) {
    return 0;
  }
  if (1 < iter) {
    pAVar2 = ASN1_INTEGER_new();
    pPVar1->iter = pAVar2;
    if (pAVar2 == (ASN1_INTEGER *)0x0) {
      iVar3 = 0xda;
      puVar4 = (uchar *)0x0;
      goto LAB_001d1874;
    }
    iVar3 = ASN1_INTEGER_set(p12->mac->iter,iter);
    if (iVar3 == 0) {
      iVar3 = 0xde;
      puVar4 = (uchar *)0x0;
      goto LAB_001d1874;
    }
    pPVar1 = p12->mac;
  }
  if (saltlen == 0) {
    saltlen = 8;
  }
  pAVar5 = pPVar1->salt;
  puVar4 = (uchar *)CRYPTO_malloc(saltlen,"crypto/pkcs12/p12_mutl.c",0xe4);
  iVar3 = 0xe5;
  pAVar5->data = puVar4;
  if (puVar4 != (uchar *)0x0) {
    pAVar5 = p12->mac->salt;
    pAVar5->length = saltlen;
    if (salt == (uchar *)0x0) {
      iVar3 = RAND_bytes(pAVar5->data,saltlen);
      if (iVar3 < 1) {
        return 0;
      }
    }
    else {
      memcpy(pAVar5->data,salt,saltlen);
    }
    X509_SIG_getm(p12->mac->dinfo,&local_24,0);
    iVar3 = EVP_MD_type(md_type);
    aobj = OBJ_nid2obj(iVar3);
    iVar3 = X509_ALGOR_set0(local_24,aobj,5,(void *)0x0);
    if (iVar3 != 0) {
      return 1;
    }
    iVar3 = 0xf1;
    puVar4 = (uchar *)0x0;
  }
LAB_001d1874:
  ERR_put_error(0x23,0x7a,0x41,"crypto/pkcs12/p12_mutl.c",iVar3);
  return (int)puVar4;
}


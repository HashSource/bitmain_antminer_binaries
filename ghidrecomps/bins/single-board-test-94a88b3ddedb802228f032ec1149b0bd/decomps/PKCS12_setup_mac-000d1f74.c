
int PKCS12_setup_mac(PKCS12 *p12,int iter,uchar *salt,int saltlen,EVP_MD *md_type)

{
  char *file;
  PKCS12_MAC_DATA *pPVar1;
  ASN1_STRING *pAVar2;
  int iVar3;
  uchar *puVar4;
  ASN1_OBJECT *pAVar5;
  ASN1_TYPE *pAVar6;
  X509_ALGOR *pXVar7;
  ASN1_OCTET_STRING *pAVar8;
  
  pPVar1 = PKCS12_MAC_DATA_new();
  p12->mac = pPVar1;
  if (pPVar1 == (PKCS12_MAC_DATA *)0x0) {
LAB_000d2042:
    puVar4 = (uchar *)0x0;
  }
  else {
    if (iter < 2) {
LAB_000d1fb4:
      file = DAT_000d2060;
      pAVar8 = pPVar1->salt;
      if (saltlen == 0) {
        saltlen = 8;
      }
      pAVar8->length = saltlen;
      puVar4 = (uchar *)CRYPTO_malloc(saltlen,file,0xb1);
      iVar3 = 0xb2;
      pAVar8->data = puVar4;
      if (puVar4 != (uchar *)0x0) {
        if (salt == (uchar *)0x0) {
          iVar3 = RAND_pseudo_bytes(p12->mac->salt->data,saltlen);
          if (iVar3 < 0) goto LAB_000d2042;
        }
        else {
          memcpy(p12->mac->salt->data,salt,saltlen);
        }
        pXVar7 = p12->mac->dinfo->algor;
        iVar3 = EVP_MD_type(md_type);
        pAVar5 = OBJ_nid2obj(iVar3);
        pPVar1 = p12->mac;
        pXVar7->algorithm = pAVar5;
        pXVar7 = pPVar1->dinfo->algor;
        pAVar6 = ASN1_TYPE_new();
        pXVar7->parameter = pAVar6;
        if (pAVar6 != (ASN1_TYPE *)0x0) {
          p12->mac->dinfo->algor->parameter->type = 5;
          return 1;
        }
        iVar3 = 0xbc;
        puVar4 = (uchar *)0x0;
      }
    }
    else {
      pAVar2 = ASN1_STRING_type_new(2);
      pPVar1->iter = pAVar2;
      if (pAVar2 == (ASN1_STRING *)0x0) {
        ERR_put_error(0x23,0x7a,0x41,DAT_000d2060,0xa6);
        return 0;
      }
      iVar3 = ASN1_INTEGER_set(p12->mac->iter,iter);
      if (iVar3 != 0) {
        pPVar1 = p12->mac;
        goto LAB_000d1fb4;
      }
      iVar3 = 0xaa;
      puVar4 = (uchar *)0x0;
    }
    ERR_put_error(0x23,0x7a,0x41,DAT_000d2060,iVar3);
  }
  return (int)puVar4;
}


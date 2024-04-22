
int PKCS12_verify_mac(PKCS12 *p12,char *pass,int passlen)

{
  int iVar1;
  uint uVar2;
  size_t len;
  ASN1_OCTET_STRING *pAVar3;
  size_t local_5c;
  undefined auStack_58 [68];
  
  if (p12->mac == (PKCS12_MAC_DATA *)0x0) {
    ERR_put_error(0x23,0x7e,0x6c,DAT_000d1f70,0x77);
  }
  else {
    iVar1 = OBJ_obj2nid(p12->authsafes->type);
    if (iVar1 == 0x15) {
      iVar1 = PKCS12_gen_mac_part_0(p12,pass,passlen,auStack_58,&local_5c);
      if (iVar1 != 0) {
        pAVar3 = p12->mac->dinfo->digest;
        len = pAVar3->length;
        if (len != local_5c) {
          return 0;
        }
        uVar2 = CRYPTO_memcmp(auStack_58,pAVar3->data,len);
        if (uVar2 < 2) {
          return 1 - uVar2;
        }
        return 0;
      }
    }
    else {
      ERR_put_error(0x23,0x6b,0x79,DAT_000d1f70,0x4f);
    }
    ERR_put_error(0x23,0x7e,0x6d,DAT_000d1f70,0x7b);
  }
  return 0;
}



int PKCS12_set_mac(PKCS12 *p12,char *pass,int passlen,uchar *salt,int saltlen,int iter,
                  EVP_MD *md_type)

{
  int iVar1;
  int local_5c;
  undefined auStack_58 [64];
  
  if (md_type == (EVP_MD *)0x0) {
    md_type = EVP_sha1();
  }
  iVar1 = PKCS12_setup_mac(p12,iter,salt,saltlen,md_type);
  if (iVar1 == 0) {
    ERR_put_error(0x23,0x7b,0x6e,DAT_000d2120,0x90);
  }
  else {
    iVar1 = OBJ_obj2nid(p12->authsafes->type);
    if (iVar1 == 0x15) {
      iVar1 = PKCS12_gen_mac_part_0(p12,pass,passlen,auStack_58,&local_5c);
      if (iVar1 != 0) {
        iVar1 = ASN1_STRING_set(p12->mac->dinfo->digest,auStack_58,local_5c);
        if (iVar1 != 0) {
          return 1;
        }
        ERR_put_error(0x23,0x7b,0x6f,DAT_000d2120,0x98);
        return 0;
      }
    }
    else {
      ERR_put_error(0x23,0x6b,0x79,DAT_000d2120,0x4f);
    }
    ERR_put_error(0x23,0x7b,0x6d,DAT_000d2120,0x94);
  }
  return 0;
}


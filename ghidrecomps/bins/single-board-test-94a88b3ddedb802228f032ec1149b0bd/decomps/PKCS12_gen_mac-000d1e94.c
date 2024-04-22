
int PKCS12_gen_mac(PKCS12 *p12,char *pass,int passlen,uchar *mac,uint *maclen)

{
  int iVar1;
  
  iVar1 = OBJ_obj2nid(p12->authsafes->type);
  if (iVar1 == 0x15) {
    iVar1 = PKCS12_gen_mac_part_0(p12,pass,passlen,mac);
    return iVar1;
  }
  ERR_put_error(0x23,0x6b,0x79,DAT_000d1edc,0x4f);
  return 0;
}


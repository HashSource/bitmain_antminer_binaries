
EVP_PKEY_ASN1_METHOD * ENGINE_get_pkey_asn1_meth(ENGINE *e,int nid)

{
  int iVar1;
  EVP_PKEY_ASN1_METHOD *local_c;
  
  if ((*(code **)(e + 0x30) == (code *)0x0) ||
     (iVar1 = (**(code **)(e + 0x30))(e,&local_c,0,nid), iVar1 == 0)) {
    ERR_put_error(0x26,0xc1,0x65,DAT_000a811c,0x85);
    local_c = (EVP_PKEY_ASN1_METHOD *)0x0;
  }
  return local_c;
}



int ENGINE_set_default(ENGINE *e,uint flags)

{
  int iVar1;
  
  if ((((((-1 < (int)(flags << 0x19)) || (iVar1 = ENGINE_set_default_ciphers(e), iVar1 != 0)) &&
        ((-1 < (int)(flags << 0x18) || (iVar1 = ENGINE_set_default_digests(e), iVar1 != 0)))) &&
       ((-1 < (int)(flags << 0x1f) || (iVar1 = ENGINE_set_default_RSA(e), iVar1 != 0)))) &&
      ((-1 < (int)(flags << 0x1e) || (iVar1 = ENGINE_set_default_DSA(e), iVar1 != 0)))) &&
     (((((-1 < (int)(flags << 0x1d) || (iVar1 = ENGINE_set_default_DH(e), iVar1 != 0)) &&
        ((-1 < (int)(flags << 0x1b) || (iVar1 = ENGINE_set_default_ECDH(e), iVar1 != 0)))) &&
       ((-1 < (int)(flags << 0x1a) || (iVar1 = ENGINE_set_default_ECDSA(e), iVar1 != 0)))) &&
      (((-1 < (int)(flags << 0x1c) || (iVar1 = ENGINE_set_default_RAND(e), iVar1 != 0)) &&
       ((-1 < (int)(flags << 0x16) || (iVar1 = ENGINE_set_default_pkey_meths(e), iVar1 != 0))))))))
  {
    if (-1 < (int)(flags << 0x15)) {
      return 1;
    }
    iVar1 = ENGINE_set_default_pkey_asn1_meths(e);
    if (iVar1 != 0) {
      iVar1 = 1;
    }
    return iVar1;
  }
  return 0;
}


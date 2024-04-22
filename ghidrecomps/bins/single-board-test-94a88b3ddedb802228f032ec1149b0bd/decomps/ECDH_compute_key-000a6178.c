
int ECDH_compute_key(void *out,size_t outlen,EC_POINT *pub_key,EC_KEY *ecdh,KDF *KDF)

{
  int iVar1;
  
  iVar1 = ecdh_check(ecdh);
  if (iVar1 != 0) {
    iVar1 = (**(code **)(*(int *)(iVar1 + 0xc) + 4))(out,outlen,pub_key,ecdh,KDF);
  }
  return iVar1;
}


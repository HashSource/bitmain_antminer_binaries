
EVP_MD * tls12_get_hash(undefined4 param_1)

{
  EVP_MD *pEVar1;
  
  switch(param_1) {
  case 1:
    pEVar1 = EVP_md5();
    return pEVar1;
  case 2:
    pEVar1 = EVP_sha1();
    return pEVar1;
  case 3:
    pEVar1 = EVP_sha224();
    return pEVar1;
  case 4:
    pEVar1 = EVP_sha256();
    return pEVar1;
  case 5:
    pEVar1 = EVP_sha384();
    return pEVar1;
  case 6:
    pEVar1 = EVP_sha512();
    return pEVar1;
  default:
    return (EVP_MD *)0x0;
  }
}


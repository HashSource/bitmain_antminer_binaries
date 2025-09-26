
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void OpenSSL_add_all_digests(void)

{
  EVP_MD *pEVar1;
  
  pEVar1 = EVP_md4();
  EVP_add_digest(pEVar1);
  pEVar1 = EVP_md5();
  EVP_add_digest(pEVar1);
  OBJ_NAME_add("ssl2-md5",0x8001,"MD5");
  OBJ_NAME_add("ssl3-md5",0x8001,"MD5");
  pEVar1 = EVP_sha();
  EVP_add_digest(pEVar1);
  pEVar1 = EVP_dss();
  EVP_add_digest(pEVar1);
  pEVar1 = EVP_sha1();
  EVP_add_digest(pEVar1);
  OBJ_NAME_add("ssl3-sha1",0x8001,"SHA1");
  OBJ_NAME_add("RSA-SHA1-2",0x8001,"RSA-SHA1");
  pEVar1 = EVP_dss1();
  EVP_add_digest(pEVar1);
  OBJ_NAME_add("DSA-SHA1-old",0x8001,"DSA-SHA1");
  OBJ_NAME_add("DSS1",0x8001,"DSA-SHA1");
  OBJ_NAME_add("dss1",0x8001,"DSA-SHA1");
  pEVar1 = EVP_ecdsa();
  EVP_add_digest(pEVar1);
  pEVar1 = (EVP_MD *)EVP_mdc2();
  EVP_add_digest(pEVar1);
  pEVar1 = EVP_ripemd160();
  EVP_add_digest(pEVar1);
  OBJ_NAME_add("ripemd",0x8001,"RIPEMD160");
  OBJ_NAME_add("rmd160",0x8001,"RIPEMD160");
  pEVar1 = EVP_sha224();
  EVP_add_digest(pEVar1);
  pEVar1 = EVP_sha256();
  EVP_add_digest(pEVar1);
  pEVar1 = EVP_sha384();
  EVP_add_digest(pEVar1);
  pEVar1 = EVP_sha512();
  EVP_add_digest(pEVar1);
  pEVar1 = EVP_whirlpool();
  EVP_add_digest(pEVar1);
  return;
}



void ossl_init_ssl_base_ossl_(void)

{
  EVP_CIPHER *pEVar1;
  EVP_MD *pEVar2;
  int iVar3;
  
  pEVar1 = EVP_des_cbc();
  EVP_add_cipher(pEVar1);
  pEVar1 = EVP_des_ede3_cbc();
  EVP_add_cipher(pEVar1);
  pEVar1 = EVP_idea_cbc();
  EVP_add_cipher(pEVar1);
  pEVar1 = EVP_rc4();
  EVP_add_cipher(pEVar1);
  pEVar1 = EVP_rc4_hmac_md5();
  EVP_add_cipher(pEVar1);
  pEVar1 = EVP_rc2_cbc();
  EVP_add_cipher(pEVar1);
  pEVar1 = EVP_rc2_40_cbc();
  EVP_add_cipher(pEVar1);
  pEVar1 = EVP_aes_128_cbc();
  EVP_add_cipher(pEVar1);
  pEVar1 = EVP_aes_192_cbc();
  EVP_add_cipher(pEVar1);
  pEVar1 = EVP_aes_256_cbc();
  EVP_add_cipher(pEVar1);
  pEVar1 = EVP_aes_128_gcm();
  EVP_add_cipher(pEVar1);
  pEVar1 = EVP_aes_256_gcm();
  EVP_add_cipher(pEVar1);
  pEVar1 = EVP_aes_128_ccm();
  EVP_add_cipher(pEVar1);
  pEVar1 = EVP_aes_256_ccm();
  EVP_add_cipher(pEVar1);
  pEVar1 = EVP_aes_128_cbc_hmac_sha1();
  EVP_add_cipher(pEVar1);
  pEVar1 = EVP_aes_256_cbc_hmac_sha1();
  EVP_add_cipher(pEVar1);
  pEVar1 = (EVP_CIPHER *)EVP_aes_128_cbc_hmac_sha256();
  EVP_add_cipher(pEVar1);
  pEVar1 = (EVP_CIPHER *)EVP_aes_256_cbc_hmac_sha256();
  EVP_add_cipher(pEVar1);
  pEVar1 = (EVP_CIPHER *)EVP_aria_128_gcm();
  EVP_add_cipher(pEVar1);
  pEVar1 = (EVP_CIPHER *)EVP_aria_256_gcm();
  EVP_add_cipher(pEVar1);
  pEVar1 = EVP_camellia_128_cbc();
  EVP_add_cipher(pEVar1);
  pEVar1 = EVP_camellia_256_cbc();
  EVP_add_cipher(pEVar1);
  pEVar1 = (EVP_CIPHER *)EVP_chacha20_poly1305();
  EVP_add_cipher(pEVar1);
  pEVar1 = EVP_seed_cbc();
  EVP_add_cipher(pEVar1);
  pEVar2 = EVP_md5();
  EVP_add_digest(pEVar2);
  OBJ_NAME_add("ssl3-md5",0x8001,"MD5");
  pEVar2 = (EVP_MD *)EVP_md5_sha1();
  EVP_add_digest(pEVar2);
  pEVar2 = EVP_sha1();
  EVP_add_digest(pEVar2);
  OBJ_NAME_add("ssl3-sha1",0x8001,"SHA1");
  OBJ_NAME_add("RSA-SHA1-2",0x8001,"RSA-SHA1");
  pEVar2 = EVP_sha224();
  EVP_add_digest(pEVar2);
  pEVar2 = EVP_sha256();
  EVP_add_digest(pEVar2);
  pEVar2 = EVP_sha384();
  EVP_add_digest(pEVar2);
  pEVar2 = EVP_sha512();
  EVP_add_digest(pEVar2);
  SSL_COMP_get_compression_methods();
  iVar3 = ssl_load_ciphers();
  if (iVar3 != 0) {
    OPENSSL_atexit(0xe917d);
    iVar3 = 1;
    ssl_base_inited = 1;
  }
  ossl_init_ssl_base_ossl_ret_ = iVar3;
  return;
}


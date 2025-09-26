
void ssl_load_ciphers(void)

{
  EVP_PKEY_ASN1_METHOD *ameth;
  ENGINE *local_18;
  int local_14 [2];
  
  ssl_cipher_methods._0_4_ = EVP_get_cipherbyname("DES-CBC");
  ssl_cipher_methods._4_4_ = EVP_get_cipherbyname("DES-EDE3-CBC");
  ssl_cipher_methods._8_4_ = EVP_get_cipherbyname("RC4");
  ssl_cipher_methods._12_4_ = EVP_get_cipherbyname("RC2-CBC");
  ssl_cipher_methods._16_4_ = EVP_get_cipherbyname("IDEA-CBC");
  ssl_cipher_methods._24_4_ = EVP_get_cipherbyname("AES-128-CBC");
  ssl_cipher_methods._28_4_ = EVP_get_cipherbyname("AES-256-CBC");
  ssl_cipher_methods._32_4_ = EVP_get_cipherbyname("CAMELLIA-128-CBC");
  ssl_cipher_methods._36_4_ = EVP_get_cipherbyname("CAMELLIA-256-CBC");
  ssl_cipher_methods._40_4_ = EVP_get_cipherbyname("gost89-cnt");
  ssl_cipher_methods._44_4_ = EVP_get_cipherbyname("SEED-CBC");
  ssl_cipher_methods._48_4_ = EVP_get_cipherbyname("id-aes128-GCM");
  ssl_cipher_methods._52_4_ = EVP_get_cipherbyname("id-aes256-GCM");
  ssl_digest_methods._0_4_ = EVP_get_digestbyname("MD5");
  ssl_mac_secret_size._0_4_ = EVP_MD_size((EVP_MD *)ssl_digest_methods._0_4_);
  if ((int)ssl_mac_secret_size._0_4_ < 0) {
    OpenSSLDie("ssl_ciph.c",0x1b3,"ssl_mac_secret_size[SSL_MD_MD5_IDX] >= 0");
  }
  ssl_digest_methods._4_4_ = EVP_get_digestbyname("SHA1");
  ssl_mac_secret_size._4_4_ = EVP_MD_size((EVP_MD *)ssl_digest_methods._4_4_);
  if ((int)ssl_mac_secret_size._4_4_ < 0) {
    OpenSSLDie("ssl_ciph.c",0x1b7,"ssl_mac_secret_size[SSL_MD_SHA1_IDX] >= 0");
  }
  ssl_digest_methods._8_4_ = EVP_get_digestbyname("md_gost94");
  if ((EVP_MD *)ssl_digest_methods._8_4_ != (EVP_MD *)0x0) {
    ssl_mac_secret_size._8_4_ = EVP_MD_size((EVP_MD *)ssl_digest_methods._8_4_);
    if ((int)ssl_mac_secret_size._8_4_ < 0) {
      OpenSSLDie("ssl_ciph.c",0x1bd,"ssl_mac_secret_size[SSL_MD_GOST94_IDX] >= 0");
    }
  }
  ssl_digest_methods._12_4_ = EVP_get_digestbyname("gost-mac");
  local_18 = (ENGINE *)0x0;
  local_14[0] = 0;
  ameth = EVP_PKEY_asn1_find_str(&local_18,"gost-mac",-1);
  if (ameth != (EVP_PKEY_ASN1_METHOD *)0x0) {
    EVP_PKEY_asn1_get0_info(local_14,(int *)0x0,(int *)0x0,(char **)0x0,(char **)0x0,ameth);
  }
  if (local_18 != (ENGINE *)0x0) {
    ENGINE_finish(local_18);
  }
  DAT_0024d4f8 = local_14[0];
  if (local_14[0] != 0) {
    ssl_mac_secret_size._12_4_ = 0x20;
  }
  ssl_digest_methods._16_4_ = EVP_get_digestbyname("SHA256");
  ssl_mac_secret_size._16_4_ = EVP_MD_size((EVP_MD *)ssl_digest_methods._16_4_);
  ssl_digest_methods._20_4_ = EVP_get_digestbyname("SHA384");
  ssl_mac_secret_size._20_4_ = EVP_MD_size((EVP_MD *)ssl_digest_methods._20_4_);
  return;
}


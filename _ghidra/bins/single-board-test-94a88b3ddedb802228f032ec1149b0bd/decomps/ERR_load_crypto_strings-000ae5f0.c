
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void ERR_load_crypto_strings(void)

{
  ERR_load_ERR_strings();
  ERR_load_BN_strings();
  ERR_load_RSA_strings();
  ERR_load_DH_strings();
  ERR_load_EVP_strings();
  ERR_load_BUF_strings();
  ERR_load_OBJ_strings();
  ERR_load_PEM_strings();
  ERR_load_DSA_strings();
  ERR_load_X509_strings();
  ERR_load_ASN1_strings();
  ERR_load_CONF_strings();
  ERR_load_CRYPTO_strings();
  ERR_load_COMP_strings();
  ERR_load_EC_strings();
  ERR_load_ECDSA_strings();
  ERR_load_ECDH_strings();
  ERR_load_BIO_strings();
  ERR_load_PKCS7_strings();
  ERR_load_X509V3_strings();
  ERR_load_PKCS12_strings();
  ERR_load_RAND_strings();
  ERR_load_DSO_strings();
  ERR_load_TS_strings();
  ERR_load_ENGINE_strings();
  ERR_load_OCSP_strings();
  ERR_load_UI_strings();
  ERR_load_CMS_strings();
  return;
}


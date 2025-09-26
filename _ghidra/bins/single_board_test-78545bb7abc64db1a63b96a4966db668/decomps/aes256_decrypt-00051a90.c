
int aes256_decrypt(uint8_t *ciphertext,int ciphertext_len,uint8_t *key,uint8_t *iv,
                  uint8_t *plaintext)

{
  EVP_CIPHER *cipher;
  uint8_t *iv_local;
  uint8_t *key_local;
  int ciphertext_len_local;
  uint8_t *ciphertext_local;
  int len;
  int plaintext_len;
  EVP_CIPHER_CTX *ctx;
  
  ctx = (EVP_CIPHER_CTX *)EVP_CIPHER_CTX_new();
  cipher = EVP_aes_256_cbc();
  EVP_DecryptInit_ex((EVP_CIPHER_CTX *)ctx,cipher,(ENGINE *)0x0,key,iv);
  EVP_CIPHER_CTX_set_padding((EVP_CIPHER_CTX *)ctx,0);
  EVP_DecryptUpdate((EVP_CIPHER_CTX *)ctx,plaintext,&len,ciphertext,ciphertext_len);
  plaintext_len = len;
  EVP_DecryptFinal_ex((EVP_CIPHER_CTX *)ctx,plaintext + len,&len);
  plaintext_len = len + plaintext_len;
  EVP_CIPHER_CTX_free((EVP_CIPHER_CTX *)ctx);
  return plaintext_len;
}


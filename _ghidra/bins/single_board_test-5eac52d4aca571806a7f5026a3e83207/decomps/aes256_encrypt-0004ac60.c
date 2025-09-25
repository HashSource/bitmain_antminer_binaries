
int aes256_encrypt(uint8_t *plaintext,int plaintext_len,uint8_t *key,uint8_t *iv,uint8_t *ciphertext
                  )

{
  EVP_CIPHER *cipher;
  uint8_t *iv_local;
  uint8_t *key_local;
  int plaintext_len_local;
  uint8_t *plaintext_local;
  int len;
  int ciphertext_len;
  EVP_CIPHER_CTX *ctx;
  
  ctx = (EVP_CIPHER_CTX *)EVP_CIPHER_CTX_new();
  cipher = EVP_aes_256_cbc();
  EVP_EncryptInit_ex((EVP_CIPHER_CTX *)ctx,cipher,(ENGINE *)0x0,key,iv);
  EVP_CIPHER_CTX_set_padding((EVP_CIPHER_CTX *)ctx,0);
  EVP_EncryptUpdate((EVP_CIPHER_CTX *)ctx,ciphertext,&len,plaintext,plaintext_len);
  ciphertext_len = len;
  EVP_EncryptFinal_ex((EVP_CIPHER_CTX *)ctx,ciphertext + len,&len);
  ciphertext_len = len + ciphertext_len;
  EVP_CIPHER_CTX_free((EVP_CIPHER_CTX *)ctx);
  return ciphertext_len;
}


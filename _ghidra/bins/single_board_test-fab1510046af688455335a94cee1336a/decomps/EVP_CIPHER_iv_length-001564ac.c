
int EVP_CIPHER_iv_length(EVP_CIPHER *cipher)

{
  return cipher->iv_len;
}


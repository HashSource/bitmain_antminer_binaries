
int EVP_CIPHER_key_length(EVP_CIPHER *cipher)

{
  return cipher->key_len;
}


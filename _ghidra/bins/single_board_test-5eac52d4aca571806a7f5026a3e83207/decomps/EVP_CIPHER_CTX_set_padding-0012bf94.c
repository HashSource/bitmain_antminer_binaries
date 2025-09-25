
int EVP_CIPHER_CTX_set_padding(EVP_CIPHER_CTX *c,int pad)

{
  if (pad == 0) {
    c->flags = c->flags | 0x100;
    return 1;
  }
  c->flags = c->flags & 0xfffffeff;
  return 1;
}



void asn1_string_embed_free(void *param_1,int param_2)

{
  if (param_1 == (void *)0x0) {
    return;
  }
  if (-1 < *(int *)((int)param_1 + 0xc) << 0x1b) {
    CRYPTO_free(*(void **)((int)param_1 + 8));
  }
  if (param_2 == 0) {
    CRYPTO_free(param_1);
    return;
  }
  return;
}


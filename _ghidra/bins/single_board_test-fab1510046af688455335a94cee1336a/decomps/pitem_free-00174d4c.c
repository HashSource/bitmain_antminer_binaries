
void pitem_free(pitem *item)

{
  if (item != (pitem *)0x0) {
    CRYPTO_free(item);
    return;
  }
  return;
}


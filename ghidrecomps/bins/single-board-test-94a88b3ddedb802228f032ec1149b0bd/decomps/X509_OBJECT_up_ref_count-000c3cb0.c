
void X509_OBJECT_up_ref_count(X509_OBJECT *a)

{
  if (a->type == 1) {
    CRYPTO_add_lock(&((a->data).x509)->references,1,3,DAT_000c3cec,0x197);
  }
  else if (a->type == 2) {
    CRYPTO_add_lock(&((a->data).x509)->valid,1,6,DAT_000c3cec,0x19a);
  }
  return;
}



void PKCS7_RECIP_INFO_get0_alg(PKCS7_RECIP_INFO *ri,X509_ALGOR **penc)

{
  if (penc != (X509_ALGOR **)0x0) {
    *penc = ri->key_enc_algor;
  }
  return;
}


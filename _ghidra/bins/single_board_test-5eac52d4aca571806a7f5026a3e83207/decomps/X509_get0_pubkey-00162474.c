
void X509_get0_pubkey(int param_1)

{
  if (param_1 != 0) {
    X509_PUBKEY_get0(*(undefined4 *)(param_1 + 0x2c));
    return;
  }
  return;
}


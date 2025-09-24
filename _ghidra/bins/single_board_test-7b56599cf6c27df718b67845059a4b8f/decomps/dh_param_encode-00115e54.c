
void dh_param_encode(int param_1,uchar **param_2)

{
  if (*(undefined1 **)(param_1 + 0xc) != &dhx_asn1_meth) {
    i2d_DHparams(*(DH **)(param_1 + 0x18),param_2);
    return;
  }
  i2d_DHxparams();
  return;
}


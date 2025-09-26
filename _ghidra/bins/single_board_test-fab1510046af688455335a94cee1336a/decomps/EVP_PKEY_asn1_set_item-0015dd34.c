
void EVP_PKEY_asn1_set_item(int param_1,undefined4 param_2,undefined4 param_3)

{
  *(undefined4 *)(param_1 + 0x68) = param_3;
  *(undefined4 *)(param_1 + 100) = param_2;
  return;
}


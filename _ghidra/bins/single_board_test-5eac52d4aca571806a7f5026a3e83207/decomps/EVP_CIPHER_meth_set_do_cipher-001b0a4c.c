
undefined4 EVP_CIPHER_meth_set_do_cipher(int param_1,undefined4 param_2)

{
  *(undefined4 *)(param_1 + 0x18) = param_2;
  return 1;
}


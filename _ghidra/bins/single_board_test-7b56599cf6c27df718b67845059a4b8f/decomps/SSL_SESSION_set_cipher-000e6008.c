
undefined4 SSL_SESSION_set_cipher(int param_1,undefined4 param_2)

{
  *(undefined4 *)(param_1 + 0x1b8) = param_2;
  return 1;
}


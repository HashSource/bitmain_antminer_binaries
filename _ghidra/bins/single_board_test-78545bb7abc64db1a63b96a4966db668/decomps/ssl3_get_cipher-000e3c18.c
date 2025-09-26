
undefined1 * ssl3_get_cipher(uint param_1)

{
  if (param_1 < 0xa4) {
    return ssl3_ciphers + (0xa3 - param_1) * 0x40;
  }
  return (undefined1 *)0x0;
}


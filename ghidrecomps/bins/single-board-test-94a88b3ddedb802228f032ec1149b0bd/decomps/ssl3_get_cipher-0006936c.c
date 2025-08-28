
undefined1 * ssl3_get_cipher(uint param_1)

{
  undefined1 *puVar1;
  
  if (param_1 < 0x8c) {
    puVar1 = &ssl3_ciphers + (0x8b - param_1) * 0x30;
  }
  else {
    puVar1 = (undefined1 *)0x0;
  }
  return puVar1;
}


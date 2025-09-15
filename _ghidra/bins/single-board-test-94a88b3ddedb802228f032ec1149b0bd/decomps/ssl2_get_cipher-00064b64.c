
undefined1 * ssl2_get_cipher(uint param_1)

{
  undefined1 *puVar1;
  
  if (param_1 < 7) {
    puVar1 = &ssl2_ciphers + (6 - param_1) * 0x30;
  }
  else {
    puVar1 = (undefined1 *)0x0;
  }
  return puVar1;
}


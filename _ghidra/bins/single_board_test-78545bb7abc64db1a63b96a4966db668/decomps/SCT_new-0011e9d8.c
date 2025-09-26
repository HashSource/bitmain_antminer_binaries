
undefined4 * SCT_new(void)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)CRYPTO_zalloc(0x40,"crypto/ct/ct_sct.c",0x18);
  if (puVar1 == (undefined4 *)0x0) {
    ERR_put_error(0x32,100,0x41,"crypto/ct/ct_sct.c",0x1b);
  }
  else {
    puVar1[0xd] = 0xffffffff;
    *puVar1 = 0xffffffff;
  }
  return puVar1;
}


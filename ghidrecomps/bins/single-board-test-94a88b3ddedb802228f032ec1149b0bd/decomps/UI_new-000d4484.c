
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

UI * UI_new(void)

{
  UI_METHOD **ppUVar1;
  UI_METHOD **obj;
  UI_METHOD *pUVar2;
  
  obj = (UI_METHOD **)CRYPTO_malloc(0x18,DAT_000d44d4,0x51);
  ppUVar1 = DAT_000d44d8;
  if (obj == (UI_METHOD **)0x0) {
    ERR_put_error(0x28,0x68,0x41,DAT_000d44d4,0x53);
  }
  else {
    pUVar2 = *DAT_000d44d8;
    if (pUVar2 == (UI_METHOD *)0x0) {
      pUVar2 = UI_OpenSSL();
      *ppUVar1 = pUVar2;
    }
    *obj = pUVar2;
    obj[1] = (UI_METHOD *)0x0;
    obj[2] = (UI_METHOD *)0x0;
    obj[5] = (UI_METHOD *)0x0;
    CRYPTO_new_ex_data(0xb,obj,(CRYPTO_EX_DATA *)(obj + 3));
  }
  return (UI *)obj;
}


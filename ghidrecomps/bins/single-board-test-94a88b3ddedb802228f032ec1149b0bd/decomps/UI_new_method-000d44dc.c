
UI * UI_new_method(UI_METHOD *method)

{
  UI_METHOD **ppUVar1;
  UI_METHOD **obj;
  UI_METHOD *pUVar2;
  
  obj = (UI_METHOD **)CRYPTO_malloc(0x18,DAT_000d4534,0x51);
  ppUVar1 = DAT_000d4538;
  if (obj == (UI_METHOD **)0x0) {
    ERR_put_error(0x28,0x68,0x41,DAT_000d4534,0x53);
  }
  else {
    if (method == (UI_METHOD *)0x0) {
      pUVar2 = *DAT_000d4538;
      if (pUVar2 == (UI_METHOD *)0x0) {
        pUVar2 = UI_OpenSSL();
        *ppUVar1 = pUVar2;
      }
      *obj = pUVar2;
    }
    else {
      *obj = method;
    }
    obj[1] = (UI_METHOD *)0x0;
    obj[2] = (UI_METHOD *)0x0;
    obj[5] = (UI_METHOD *)0x0;
    CRYPTO_new_ex_data(0xb,obj,(CRYPTO_EX_DATA *)(obj + 3));
  }
  return (UI *)obj;
}


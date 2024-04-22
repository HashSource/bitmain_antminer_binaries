
PKCS8_PRIV_KEY_INFO * PKCS8_set_broken(PKCS8_PRIV_KEY_INFO *p8,int broken)

{
  if (broken == 0) {
    p8->broken = 0;
  }
  else if (broken == 1) {
    p8->broken = 1;
    p8->pkey->type = 0x10;
  }
  else {
    ERR_put_error(6,0x70,0x75,DAT_001051a4,0xa4);
    p8 = (PKCS8_PRIV_KEY_INFO *)0x0;
  }
  return p8;
}


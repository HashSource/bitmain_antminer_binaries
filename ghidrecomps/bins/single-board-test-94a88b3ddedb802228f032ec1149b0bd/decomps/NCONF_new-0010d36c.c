
CONF * NCONF_new(CONF_METHOD *meth)

{
  CONF *pCVar1;
  
  if (meth == (CONF_METHOD *)0x0) {
    meth = NCONF_default();
  }
  pCVar1 = (*meth->create)(meth);
  if (pCVar1 == (CONF *)0x0) {
    ERR_put_error(0xe,0x6f,0x41,DAT_0010d398,0xed);
  }
  return pCVar1;
}


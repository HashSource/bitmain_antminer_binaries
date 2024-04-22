
CONF_VALUE * _CONF_new_section(CONF *conf,char *section)

{
  _STACK *p_Var1;
  _STACK *ptr;
  size_t sVar2;
  void *pvVar3;
  _LHASH *lh;
  
  p_Var1 = sk_new_null();
  ptr = p_Var1;
  if (p_Var1 != (_STACK *)0x0) {
    ptr = (_STACK *)CRYPTO_malloc(0xc,DAT_0010d97c,0x119);
    if (ptr != (_STACK *)0x0) {
      sVar2 = strlen(section);
      pvVar3 = CRYPTO_malloc(sVar2 + 1,DAT_0010d97c,0x11c);
      ptr->num = (int)pvVar3;
      if (pvVar3 != (void *)0x0) {
        memcpy(pvVar3,section,sVar2 + 1);
        lh = (_LHASH *)conf->data;
        ptr->sorted = (int)p_Var1;
        ptr->data = (char **)0x0;
        pvVar3 = lh_insert(lh,ptr);
        if (pvVar3 == (void *)0x0) {
          return (CONF_VALUE *)ptr;
        }
        OpenSSLDie(DAT_0010d97c,0x124,DAT_0010d980);
        return (CONF_VALUE *)ptr;
      }
    }
    sk_free(p_Var1);
    if (ptr != (_STACK *)0x0) {
      CRYPTO_free(ptr);
      return (CONF_VALUE *)0x0;
    }
  }
  return (CONF_VALUE *)ptr;
}


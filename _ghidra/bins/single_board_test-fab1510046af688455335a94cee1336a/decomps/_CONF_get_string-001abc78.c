
char * _CONF_get_string(CONF *conf,char *section,char *name)

{
  void *pvVar1;
  char *pcVar2;
  char *local_24;
  char *local_20;
  
  if (name == (char *)0x0) {
LAB_001abcd8:
    pcVar2 = (char *)0x0;
  }
  else {
    if (conf == (CONF *)0x0) {
      pcVar2 = getenv(name);
      return pcVar2;
    }
    if (section == (char *)0x0) {
LAB_001abcc6:
      local_24 = "default";
      local_20 = name;
      pvVar1 = lh_retrieve((_LHASH *)conf->data,&local_24);
      if (pvVar1 == (void *)0x0) goto LAB_001abcd8;
    }
    else {
      local_24 = section;
      local_20 = name;
      pvVar1 = lh_retrieve((_LHASH *)conf->data,&local_24);
      if (pvVar1 == (void *)0x0) {
        if ((((*section == 'E') && (section[1] == 'N')) && (section[2] == 'V')) &&
           ((section[3] == '\0' && (pcVar2 = getenv(name), pcVar2 != (char *)0x0)))) {
          return pcVar2;
        }
        goto LAB_001abcc6;
      }
    }
    pcVar2 = *(char **)((int)pvVar1 + 8);
  }
  return pcVar2;
}


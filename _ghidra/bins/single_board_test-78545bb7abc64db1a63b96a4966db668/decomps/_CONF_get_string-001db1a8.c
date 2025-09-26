
char * _CONF_get_string(CONF *conf,char *section,char *name)

{
  int iVar1;
  char *pcVar2;
  char *local_24;
  char *local_20;
  
  if (name == (char *)0x0) {
    return (char *)0x0;
  }
  if (conf == (CONF *)0x0) {
    pcVar2 = (char *)ossl_safe_getenv(name);
    return pcVar2;
  }
  if (section != (char *)0x0) {
    local_24 = section;
    local_20 = name;
    iVar1 = OPENSSL_LH_retrieve(conf->data,&local_24);
    if (iVar1 != 0) goto LAB_001db1cc;
    if ((((*section == 'E') && (section[1] == 'N')) && (section[2] == 'V')) &&
       ((section[3] == '\0' && (pcVar2 = (char *)ossl_safe_getenv(name), pcVar2 != (char *)0x0)))) {
      return pcVar2;
    }
  }
  local_24 = "default";
  local_20 = name;
  iVar1 = OPENSSL_LH_retrieve(conf->data,&local_24);
  if (iVar1 == 0) {
    return (char *)0x0;
  }
LAB_001db1cc:
  return *(char **)(iVar1 + 8);
}


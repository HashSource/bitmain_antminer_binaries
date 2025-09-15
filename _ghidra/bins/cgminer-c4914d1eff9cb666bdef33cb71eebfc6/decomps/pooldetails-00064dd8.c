
_Bool pooldetails(char *param,char **url,char **user,char **pass)

{
  size_t sVar1;
  char **pass_local;
  char **user_local;
  char **url_local;
  char *param_local;
  char *buf;
  char *ptr;
  
  param_local = param;
  sVar1 = strlen(param);
  buf = (char *)_cgmalloc(sVar1 + 1,"api-btm.c","pooldetails",0xb77);
  *url = buf;
  ptr = buf;
  copyadvanceafter(',',&param_local,&buf);
  if (*param_local != '\0') {
    *user = buf;
    copyadvanceafter(',',&param_local,&buf);
    if (*param_local != '\0') {
      *pass = buf;
      copyadvanceafter(',',&param_local,&buf);
      return true;
    }
  }
  free(ptr);
  return false;
}


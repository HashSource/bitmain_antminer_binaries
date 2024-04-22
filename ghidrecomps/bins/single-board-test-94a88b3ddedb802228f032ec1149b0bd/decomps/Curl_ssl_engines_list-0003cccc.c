
int Curl_ssl_engines_list(void)

{
  ENGINE *e;
  char *pcVar1;
  int iVar2;
  int iVar3;
  
  e = ENGINE_get_first();
  if (e == (ENGINE *)0x0) {
    return 0;
  }
  iVar3 = 0;
  do {
    pcVar1 = ENGINE_get_id(e);
    iVar2 = curl_slist_append(iVar3,pcVar1);
    if (iVar2 == 0) {
      curl_slist_free_all(iVar3);
      return 0;
    }
    e = ENGINE_get_next(e);
    iVar3 = iVar2;
  } while (e != (ENGINE *)0x0);
  return iVar2;
}


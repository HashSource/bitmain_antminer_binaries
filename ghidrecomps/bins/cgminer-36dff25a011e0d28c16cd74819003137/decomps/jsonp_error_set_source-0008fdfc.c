
void jsonp_error_set_source(json_error_t *error,char *source)

{
  char cVar1;
  size_t sVar2;
  char *source_local;
  json_error_t *error_local;
  size_t extra;
  size_t length;
  
  if ((error != (json_error_t *)0x0) && (source != (char *)0x0)) {
    sVar2 = strlen(source);
    cVar1 = DAT_000af1be;
    if (sVar2 < 0x50) {
      strncpy(error->source,source,sVar2 + 1);
    }
    else {
      *(undefined2 *)error->source = DAT_000af1bc;
      error->source[2] = cVar1;
      strncpy(error->source + 3,source + (sVar2 - 0x4c),(sVar2 - (sVar2 - 0x4c)) + 1);
    }
  }
  return;
}


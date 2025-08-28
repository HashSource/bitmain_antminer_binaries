
void jsonp_error_set_source(json_error_t *error,char *source)

{
  size_t sVar1;
  char *source_local;
  json_error_t *error_local;
  size_t extra;
  size_t length;
  
  if ((error != (json_error_t *)0x0) && (source != (char *)0x0)) {
    sVar1 = strlen(source);
    if (sVar1 < 0x50) {
      strncpy(error->source,source,sVar1 + 1);
    }
    else {
      error->source[0] = '.';
      error->source[1] = '.';
      error->source[2] = '.';
      strncpy(error->source + 3,source + (sVar1 - 0x4c),(sVar1 - (sVar1 - 0x4c)) + 1);
    }
  }
  return;
}


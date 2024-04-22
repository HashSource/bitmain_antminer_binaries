
/* WARNING: Unknown calling convention */

json_t * json_load_file(char *path,size_t flags,json_error_t *error)

{
  FILE *input;
  FILE *fp;
  json_t *pjVar1;
  json_t *result;
  int *piVar2;
  char *pcVar3;
  
  jsonp_error_init(error,path);
  if (path == (char *)0x0) {
    error_set(error,(lex_t *)0x0,DAT_0003d598);
    pjVar1 = (json_t *)0x0;
  }
  else {
    input = fopen(path,DAT_0003d594);
    if (input == (FILE *)0x0) {
      piVar2 = __errno_location();
      pcVar3 = strerror(*piVar2);
      error_set(error,(lex_t *)0x0,DAT_0003d59c,path,pcVar3);
      pjVar1 = (json_t *)0x0;
    }
    else {
      pjVar1 = json_loadf((FILE *)input,flags,error);
      fclose(input);
    }
  }
  return pjVar1;
}


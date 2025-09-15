
json_t * json_load_file(char *path,size_t flags,json_error_t *error)

{
  FILE *input;
  int *piVar1;
  char *pcVar2;
  json_t *pjVar3;
  json_error_t *error_local;
  size_t flags_local;
  char *path_local;
  json_t *result;
  FILE *fp;
  
  jsonp_error_init(error,path);
  if (path == (char *)0x0) {
    error_set(error,(lex_t *)0x0,"wrong arguments");
    pjVar3 = (json_t *)0x0;
  }
  else {
    input = fopen(path,"rb");
    if (input == (FILE *)0x0) {
      piVar1 = __errno_location();
      pcVar2 = strerror(*piVar1);
      error_set(error,(lex_t *)0x0,"unable to open %s: %s",path,pcVar2);
      pjVar3 = (json_t *)0x0;
    }
    else {
      pjVar3 = json_loadf((FILE *)input,flags,error);
      fclose(input);
    }
  }
  return pjVar3;
}


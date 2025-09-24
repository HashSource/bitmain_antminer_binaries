
/* WARNING: Unknown calling convention */

json_t * json_load_file(char *path,size_t flags,json_error_t *error)

{
  FILE *input;
  json_t *pjVar1;
  int *piVar2;
  char *pcVar3;
  
  jsonp_error_init(error,path);
  if (path == (char *)0x0) {
    error_set(error,(lex_t *)0x0,json_error_invalid_argument,"wrong arguments");
    pjVar1 = (json_t *)0x0;
  }
  else {
    input = fopen(path,"rb");
    if (input == (FILE *)0x0) {
      piVar2 = __errno_location();
      pcVar3 = strerror(*piVar2);
      error_set(error,(lex_t *)0x0,json_error_cannot_open_file,"unable to open %s: %s",path,pcVar3);
      pjVar1 = (json_t *)0x0;
    }
    else {
      pjVar1 = json_loadf((FILE *)input,flags,error);
      fclose(input);
    }
  }
  return pjVar1;
}


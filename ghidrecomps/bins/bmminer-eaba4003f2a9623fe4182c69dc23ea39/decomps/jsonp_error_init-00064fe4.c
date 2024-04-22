
void jsonp_error_init(json_error_t *error,char *source)

{
  char *source_local;
  json_error_t *error_local;
  
  if (error != (json_error_t *)0x0) {
    error->text[0] = '\0';
    error->line = -1;
    error->column = -1;
    error->position = 0;
    if (source == (char *)0x0) {
      error->source[0] = '\0';
    }
    else {
      jsonp_error_set_source(error,source);
    }
  }
  return;
}


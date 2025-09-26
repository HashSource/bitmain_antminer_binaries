
/* WARNING: Unknown calling convention */

void jsonp_error_init(json_error_t *error,char *source)

{
  if (error != (json_error_t *)0x0) {
    error->text[0] = '\0';
    error->position = 0;
    error->line = -1;
    error->column = -1;
    if (source != (char *)0x0) {
      jsonp_error_set_source(error,source);
      return;
    }
    error->source[0] = '\0';
  }
  return;
}


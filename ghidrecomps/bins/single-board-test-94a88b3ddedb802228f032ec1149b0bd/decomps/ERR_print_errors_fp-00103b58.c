
void ERR_print_errors_fp(FILE *fp)

{
  ERR_print_errors_cb(print_fp + 1,fp);
  return;
}


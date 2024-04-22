
/* WARNING: Unknown calling convention */

void btm_init_open_again_file(void)

{
  fd_open = (FILE *)fopen("/tmp/open_again.txt","w");
  if (fd_open != (FILE *)0x0) {
    fclose((FILE *)fd_open);
  }
  return;
}


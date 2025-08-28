
undefined4 close_console(void)

{
  if (tty_in != stdin) {
    fclose(tty_in);
  }
  if (tty_out != stderr) {
    fclose(tty_out);
  }
  CRYPTO_lock(10,0x1f,"ui_openssl.c",0x249);
  return 1;
}


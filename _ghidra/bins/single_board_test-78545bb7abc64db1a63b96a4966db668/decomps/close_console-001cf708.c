
undefined4 close_console(int param_1)

{
  if (tty_in != stdin) {
    fclose(tty_in);
  }
  if (tty_out != stderr) {
    fclose(tty_out);
  }
  CRYPTO_THREAD_unlock(*(undefined4 *)(param_1 + 0x14));
  return 1;
}


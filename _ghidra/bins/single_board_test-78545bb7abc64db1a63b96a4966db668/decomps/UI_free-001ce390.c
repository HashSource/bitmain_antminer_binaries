
void UI_free(UI *ui)

{
  if (ui != (UI *)0x0) {
    if (*(int *)(ui + 0x10) << 0x1e < 0) {
      (**(code **)(*(int *)ui + 0x1c))(ui,*(undefined4 *)(ui + 8));
    }
    OPENSSL_sk_pop_free(*(undefined4 *)(ui + 4),0x1ce0a1);
    CRYPTO_free_ex_data(0xb,ui,(CRYPTO_EX_DATA *)(ui + 0xc));
    CRYPTO_THREAD_lock_free(*(undefined4 *)(ui + 0x14));
    CRYPTO_free(ui);
    return;
  }
  return;
}


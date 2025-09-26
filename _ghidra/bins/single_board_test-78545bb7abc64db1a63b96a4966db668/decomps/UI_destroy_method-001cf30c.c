
void UI_destroy_method(UI_METHOD *ui_method)

{
  if (ui_method != (UI_METHOD *)0x0) {
    CRYPTO_free_ex_data(0xe,ui_method,(CRYPTO_EX_DATA *)(ui_method + 0x24));
    CRYPTO_free(*(void **)ui_method);
    *(undefined4 *)ui_method = 0;
    CRYPTO_free(ui_method);
    return;
  }
  return;
}


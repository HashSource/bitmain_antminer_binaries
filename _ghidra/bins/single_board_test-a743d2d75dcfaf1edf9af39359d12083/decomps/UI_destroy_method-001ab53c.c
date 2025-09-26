
void UI_destroy_method(UI_METHOD *ui_method)

{
  CRYPTO_free(*(void **)ui_method);
  *(undefined4 *)ui_method = 0;
  CRYPTO_free(ui_method);
  return;
}


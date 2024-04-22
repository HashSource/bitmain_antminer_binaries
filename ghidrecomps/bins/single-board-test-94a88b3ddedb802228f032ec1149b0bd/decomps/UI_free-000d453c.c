
void UI_free(UI *ui)

{
  if (ui != (UI *)0x0) {
    sk_pop_free(*(_STACK **)(ui + 4),DAT_000d4564);
    CRYPTO_free_ex_data(0xb,ui,(CRYPTO_EX_DATA *)(ui + 0xc));
    CRYPTO_free(ui);
    return;
  }
  return;
}


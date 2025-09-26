
void * UI_get0_user_data(UI *ui)

{
  return *(void **)(ui + 8);
}


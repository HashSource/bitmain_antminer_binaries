
void * UI_add_user_data(UI *ui,void *user_data)

{
  void *pvVar1;
  
  pvVar1 = *(void **)(ui + 8);
  *(void **)(ui + 8) = user_data;
  return pvVar1;
}


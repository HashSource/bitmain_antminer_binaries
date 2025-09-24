
void * UI_add_user_data(UI *ui,void *user_data)

{
  void *pvVar1;
  uint uVar2;
  
  uVar2 = *(uint *)(ui + 0x10);
  pvVar1 = *(void **)(ui + 8);
  if ((int)(uVar2 << 0x1e) < 0) {
    (**(code **)(*(int *)ui + 0x1c))();
    uVar2 = *(uint *)(ui + 0x10);
    pvVar1 = (void *)0x0;
  }
  *(void **)(ui + 8) = user_data;
  *(uint *)(ui + 0x10) = uVar2 & 0xfffffffd;
  return pvVar1;
}


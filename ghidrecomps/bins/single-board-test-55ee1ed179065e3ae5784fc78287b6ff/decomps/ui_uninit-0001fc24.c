
void ui_uninit(void)

{
  undefined4 uVar1;
  
  if (ui_inited != 0) {
    ui_pull_thread = 0;
    pthread_join(ui_thread,(void **)0x0);
    delete_c_map(ui_flicker_map);
    pthread_mutex_destroy((pthread_mutex_t *)&ui_api_mutex);
    uVar1 = convert_ui_type_to_port(0x100);
    gpio_unreg_callback(uVar1,0x1fa51);
    uVar1 = convert_ui_type_to_port(0x101);
    gpio_unreg_callback(uVar1,0x1fa51);
    uVar1 = convert_ui_type_to_port(1);
    gpio_unexport(uVar1);
    uVar1 = convert_ui_type_to_port(2);
    gpio_unexport(uVar1);
    uVar1 = convert_ui_type_to_port(0x100);
    gpio_unexport(uVar1);
    uVar1 = convert_ui_type_to_port(0x101);
    gpio_unexport(uVar1);
    gpio_uninit();
    ui_inited = 0;
  }
  return;
}



void app_config_init_registers(void)

{
  g_ticket_mask = app_conf._360_4_;
  g_core_timeout = app_conf._364_4_;
  g_misc_control = app_conf._368_4_;
  return;
}



void app_config_exit(app_config_t *conf)

{
  app_config_t *conf_local;
  
  fclose((FILE *)conf->dbg_fp);
  free(conf->comport);
  free(conf->sensor_pos);
  free(conf->bringup_autojh_freq);
  free(conf->bringup_autojh_volt);
  free(conf->slt_bin_rate);
  free(conf->pcba_level_rate);
  free(conf);
  return;
}


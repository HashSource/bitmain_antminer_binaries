
app_config_t * app_config_init(char *config_filename)

{
  app_config_t *m_conf;
  int iVar1;
  FILE *pFVar2;
  char *config_filename_local;
  char tmp42 [1024];
  char dbg_fname [32];
  app_config_t *app_conf;
  
  m_conf = (app_config_t *)calloc(0x128,1);
  iVar1 = app_config_handle(m_conf,config_filename);
  if (iVar1 < 0) {
    m_conf = (app_config_t *)0x0;
  }
  else {
    memset(dbg_fname,0,0x20);
    sprintf(dbg_fname,"%s.log",m_conf->name);
    pFVar2 = fopen(dbg_fname,"w+");
    m_conf->dbg_fp = (FILE *)pFVar2;
    if (m_conf->dbg_fp == (FILE *)0x0) {
      if (((use_syslog != false) || (opt_log_output != false)) || (1 < opt_log_level)) {
        snprintf(tmp42,0x400,"open %s file error\n",dbg_fname);
        _applog(2,tmp42,false);
      }
      m_conf = (app_config_t *)0x0;
    }
  }
  return m_conf;
}


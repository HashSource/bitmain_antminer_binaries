
void restore_syslog_file(LOG_FILE_BACKUP *backlog)

{
  LOG_FILE_BACKUP *backlog_local;
  
  use_syslog = backlog->use_syslog;
  g_logfile_enable = backlog->logfile_enable;
  g_log_file = (FILE *)0x0;
  strcpy(g_logfile_path,backlog->logfile_path);
  strcpy(g_logfile_openflag,backlog->logfile_openflag);
  return;
}



void backup_syslog_file(LOG_FILE_BACKUP *backlog)

{
  LOG_FILE_BACKUP *backlog_local;
  
  backlog->use_syslog = use_syslog;
  backlog->logfile_enable = g_logfile_enable;
  strcpy(backlog->logfile_path,g_logfile_path);
  strcpy(backlog->logfile_openflag,g_logfile_openflag);
  return;
}



void set_privite_log_file(char *logfile_name,LOG_FILE_BACKUP *backlog)

{
  LOG_FILE_BACKUP *backlog_local;
  char *logfile_name_local;
  
  backup_syslog_file(backlog);
  if (g_log_file != (FILE *)0x0) {
    fclose((FILE *)g_log_file);
    g_log_file = (FILE *)0x0;
  }
  use_syslog = false;
  g_logfile_enable = true;
  strcpy(g_logfile_path,logfile_name);
  g_logfile_openflag[0] = (char)DAT_00081b34;
  g_logfile_openflag[1] = DAT_00081b34._1_1_;
  return;
}


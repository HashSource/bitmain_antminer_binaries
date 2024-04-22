
/* WARNING: Unknown calling convention */

void writeLogFile(char *logstr)

{
  if (*DAT_00015f78 == '\0') {
    return;
  }
  writeInitLogFile(logstr);
  return;
}


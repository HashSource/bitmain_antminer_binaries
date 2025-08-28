
/* WARNING: Unknown calling convention */

void writeLogFile(char *logstr)

{
  if (!showLogToKernelLog) {
    return;
  }
  writeInitLogFile(logstr);
  return;
}

